
//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the CTransportLayerBase implementation
*/
#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000


#ifndef __PYLONTRANSPORTLAYERPRIVATEIMPL_H__
#define __PYLONTRANSPORTLAYERPRIVATEIMPL_H__

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <set>
#include <sstream>
#include <algorithm>

#include <pylon/Platform.h>
#include <pylon/internal/TransportLayerPrivate.h>
#include <pylon/TlFactory.h>
#include <pylon/internal/ConfigFileRegistry.h>
#include <pylon/XmlFileProvider.h>
#include <pylon/internal/BCLog.h>
#include <pylon/internal/Utilities.h> //for textFileToString
#include <pylon/internal/gtl.h>
#include <pylon/internal/InfoPrivate.h>
#include <pylon/internal/DeviceSecurity.h>
#include <pylon/internal/PylonBasePrivate.h>
#include "PylonDevicePrivate.h"
#include <pylon/internal/Utilities.h> // for CreateDefaultTransportLayerParamsNodeMap
#include <pylon/internal/EmbeddedNodeMapFactory.h> // for DestroyNodeMap
#include <pylon/internal/DefaultInterface.h>
#include <pylon/stdinclude.h> // String_t
#include <pylon/internal/UnixMappings.h>
#include <pylon/DeviceClass.h>

#pragma warning(push)
#pragma warning(disable:4275) // non dll-interface class used

namespace Pylon
{
    namespace detail_base_tl
    {
        BCLOG_IMPLEMENT_GET_CATID_FUNCTION( GetPylonBaseTLCatID, "pylon.base.TL" );
    }

    // name for default interface
    static const String_t DefaultInterfaceName = "DefaultInterface";

    inline void ResolveString( std::string& rValue )
    {
        for (size_t i = 0; i < rValue.size(); i++)
        {
            rValue[i] = ~rValue[i];
        }
    }

    inline void GetNoLoadXMLKey( std::string& rString )
    {
        rString.resize( 4 );

        //obfuscated and bitwise inverted string "_nlx"
        rString[3] = ~'x';
        rString[1] = ~'n';
        rString[0] = ~'_';
        rString[2] = ~'l';

        ResolveString( rString );
    }

    inline void GetSetAvailablePowerKey( std::string& rString )
    {
        rString.resize( 4 );

        //obfuscated and bitwise inverted string "_sap"
        rString[2] = ~'a';
        rString[1] = ~'s';
        rString[3] = ~'p';
        rString[0] = ~'_';

        ResolveString( rString );
    }

    inline void ClearString( std::string& rValue )
    {
        for (size_t i = 0; i < rValue.size(); i++)
        {
            rValue[i] = 0;
        }
    }

    /**
        \internal
        Private interface used by the factory for
        device creation
        */

    ///////////////////////////////////////////////////////////////////////////
    // This class is used by the TL implementations to store pointers to created objects
    // by factory methods (CreateDevice, CreateInterface),
    // so they can be deleted when the parent object is deleted.
    //
    // Since this is a template class derived from a template class
    // you'll need to add this-> to baseclass members to make the two-phase
    // name lookup.
    template<typename TlCreatedItemT, typename TlCreatedItemPrivateT>
    class TlCreatedItemMap : private std::set < TlCreatedItemT* >
    {
    public:
        //////////////////////////////////////////////////////////////////////
        TlCreatedItemMap( ITransportLayer* pTL )
            : m_pTL( pTL )
        {
            PYLON_ASSERT2( m_pTL != nullptr, "TL pointer must not be NULL" );
        }


        //////////////////////////////////////////////////////////////////////
        ~TlCreatedItemMap( void )
        {
            DestroyAll();
        }


        //////////////////////////////////////////////////////////////////////
        void DestroyAll( void )
        {
            AutoLock lock( m_lock );
            // call DestroyItem on each item in the set.
            // since we're deletiong items from the container,
            // we must call begin()/end() on each iteration and can't use
            // iterators
            while (this->begin() != this->end())
            {
                // increment will be done indirectly by the erase call in DestroyItem
                // this will also invaluida all iterators
                DestroyItem( *(this->begin()) );
            }

            // remove all items from set
            this->clear();
        }


        //////////////////////////////////////////////////////////////////////
        void DestroyItem( TlCreatedItemT* pDevice )
        {
            bool releaseRef = false;
            {
                AutoLock lock( m_lock );
                typename std::set<TlCreatedItemT*>::iterator pos = this->find( pDevice );
                if (pos != this->end())
                {
                    this->erase( pos );
                    TlCreatedItemPrivateT* pPrivate = dynamic_cast<TlCreatedItemPrivateT*>(pDevice);
                    PYLON_ASSERT2( pPrivate != nullptr, "All pylon devices MUST implement the TlCreatedItemT interface!" );
                    if (pPrivate)
                    {
                        pPrivate->Delete();
                        releaseRef = true;
                    }
                }
                else
                {
                    PYLON_ASSERT2( false, "DestroyItem called for a non-existing item." );
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvWarning, "DestroyItem called for non-existing item." );
                }
            }

            //WARNING: Must not release reference inside lock, can produce deadlock otherwise
            if (releaseRef)
            {
                // each item increments the refcount for the TL,
                // after we destroyed on item we need to decrement the refcount
                ITransportLayerPrivate* pTLpriv = dynamic_cast<ITransportLayerPrivate*>(m_pTL);
                PYLON_ASSERT2( pTLpriv != nullptr, "TL must support ITransportLayerPrivate interface!" );
                pTLpriv->ReleaseInternal();
            }
        }


        //////////////////////////////////////////////////////////////////////
        void AddItem( TlCreatedItemT* pDevice )
        {
            AutoLock lock( m_lock );
            this->insert( pDevice );

            // we store a item, so increment the refcount for the TL
            ITransportLayerPrivate* pTLpriv = dynamic_cast<ITransportLayerPrivate*>(m_pTL);
            PYLON_ASSERT2( pTLpriv != nullptr, "TL must support ITransportLayerPrivate interface!" );
            pTLpriv->AddRefInternal();
        }


        //////////////////////////////////////////////////////////////////////
        bool Contains( TlCreatedItemT* pItem )
        {
            AutoLock lock( m_lock );
            bool res = this->find( pItem ) != this->end();
            return res;
        }


        //////////////////////////////////////////////////////////////////////
        bool IsEmpty( void ) const
        {
            AutoLock lock( m_lock );
            return this->empty();
        }

        mutable CLock m_lock;
        Pylon::ITransportLayer* m_pTL;
    };


    ///////////////////////////////////////////////////////////////////////////
    // This class is added to allow a forward reference
    class DeviceMap : public TlCreatedItemMap<IPylonDevice, IPylonDevicePrivate>
    {
    public:
        DeviceMap( ITransportLayer* pTL )
            : TlCreatedItemMap<IPylonDevice, IPylonDevicePrivate>( pTL )
        {
        }
    };


    ///////////////////////////////////////////////////////////////////////////
    // This class is added to allow a forward reference
    class InterfaceMap : public TlCreatedItemMap<IInterface, IInterfacePrivate>
    {
    public:
        InterfaceMap( ITransportLayer* pTL )
            : TlCreatedItemMap<IInterface, IInterfacePrivate>( pTL )
        {
        }
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    CTransportLayerBase<T>::CTransportLayerBase( void )
        : m_pAvailableDevices( NULL ) // initialized in function body
        , m_pAvailableInterfaces( NULL ) // initialized in function body
        , m_pDefaultParams( CreateDefaultTransportLayerParamsNodeMap() )
        , m_pDeviceCreationObserver( NULL )
        , m_isEnabled( false )
        , m_nRefCountExternal( 0 )
        , m_nRefCountInternal( 0 )
    {
        m_pAvailableDevices = new DeviceMap( this ); // initialize here to avoid "used this in initializer list" warning
        m_pAvailableInterfaces = new InterfaceMap( this ); // initialize here to avoid "used this in initializer list" warning
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    CTransportLayerBase<T>::~CTransportLayerBase( void )
    {
        //PYLON_ASSERT2(m_nRefCountInternal == 0, "RefCount must be 0 when object it destroyed"); <-triggered by tests
        if (m_nRefCountInternal != 0)
        {
            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvWarning, "~CTransportLayerBase(): Internal reference count must be 0 when object is destroyed" );
        }
        //PYLON_ASSERT2(m_nRefCountExternal == 0, "RefCount must be 0 when object it destroyed"); <-triggered by tests
        if (m_nRefCountExternal != 0)
        {
            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvWarning, "~CTransportLayerBase(): External reference count must be 0 when object is destroyed" );
        }

        if (m_pAvailableDevices != NULL)
        {
            delete m_pAvailableDevices;  // this destroys all remaining devices and releases their references to the TL
            m_pAvailableDevices = NULL;
        }

        if (m_pAvailableInterfaces != NULL)
        {
            delete m_pAvailableInterfaces;  // this destroys all remaining Interfaces and releases their references to the TL
            m_pAvailableInterfaces = NULL;
        }

        DestroyNodeMap( m_pDefaultParams );
    }
    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    bool CTransportLayerBase<T>::InternalMatchDeviceClass( const String_t& deviceClass ) const
    {
        // default is exact match
        return deviceClass == InternalGetDeviceClass();
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    bool CTransportLayerBase<T>::InternalNeedsTlSpecificDeviceDiscovery( const CDeviceInfo& ) const
    {
        return false;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    CDeviceInfo CTransportLayerBase<T>::InternalDoTlSpecificDeviceDiscovery( const CDeviceInfo& )
    {
        PYLON_ASSERT( false );
        throw ("Internal error. No device specific device discovery available.");
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    int CTransportLayerBase<T>::InternalApplyFilter( const DeviceInfoList_t& unfiltered, const DeviceInfoList_t& filter, DeviceInfoList_t& result )
    {
        // Apply Filter
        int count = 0;
        for (DeviceInfoList_t::const_iterator it = unfiltered.begin(); it != unfiltered.end(); ++it)
        {
            for (DeviceInfoList_t::const_iterator subsetIt = filter.begin(); subsetIt != filter.end(); ++subsetIt)
            {
                if (InternalIsSubset( *it, *subsetIt ))
                {
                    // Device meets filter requirements add to output list and continue with other possible devices
                    ++count;
                    result.push_back( *it );
                    break;
                }
            }
        }
        if (!unfiltered.empty())
        {
            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Filter applied to device list, count of devices before filter step = %d, after filter step = %d.", unfiltered.size(), count );
        }
        return count;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    int CTransportLayerBase<T>::EnumerateDevices( DeviceInfoList_t& dil, bool addToList )
    {
        int res = EnumerateDevices( dil, DeviceInfoList_t(), addToList );
        return res;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    int CTransportLayerBase<T>::EnumerateDevices( DeviceInfoList_t& dil, const DeviceInfoList_t& filter, bool addToList )
    {
        if (!addToList)
        {
            dil.clear();
        }

        // Check, if TL is disabled by PYLON_DEVICE_FILTER
        if (!IsTLEnabled())
        {
            return 0;
        }

        size_t dilInitialSize = dil.size();
        DeviceInfoList_t* pGlobalFilter = GetGlobalDeviceFilterInstance();
        DeviceInfoList_t unfiltered; // results from InternalEnumerateDevies
        int cntReturned = 0;

        // Filter applied?
        if (!filter.empty())
        {
            // Check, can create any of the devices
            {
                DeviceInfoList_t::const_iterator it = filter.begin();
                for (; it != filter.end(); ++it)
                {
                    if (
                        !it->IsDeviceClassAvailable() // Device class not provided, search using this TL
                        || InternalMatchDeviceClass( it->GetDeviceClass() )  // Matches TL, search using this TL
                        )
                    {
                        break;
                    }
                }
                if (it == filter.end())
                {
                    // No device can be created with this TL
                    return 0;
                }
            }

            // Enumerate into new list
            InternalEnumerateDevices( unfiltered );

            // Filter and Return number of found devices
            if (pGlobalFilter == NULL)
            {
                // apply filter passed in param
                cntReturned = InternalApplyFilter( unfiltered, filter, dil );
            }
            else
            {
                // apply global filter first
                DeviceInfoList_t globalFiltered;
                InternalApplyFilter( unfiltered, *pGlobalFilter, globalFiltered );
                // apply filter passed in param
                cntReturned = InternalApplyFilter( globalFiltered, filter, dil );
            }
        }
        else
        {
            if (pGlobalFilter == NULL)
            {
                cntReturned = InternalEnumerateDevices( dil );
            }
            else
            {
                InternalEnumerateDevices( unfiltered );
                // apply global filter first
                cntReturned = InternalApplyFilter( unfiltered, *pGlobalFilter, dil );
            }
        }

        // sort newly discovered devices
        PYLON_ASSERT( dil.size() >= dilInitialSize );
        std::sort( dil.begin() + dilInitialSize, dil.end() );

        return cntReturned;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    CDeviceInfo CTransportLayerBase<T>::CreateDeviceInfo( void )
    {
        return InternalCreateDeviceInfo();
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    unsigned long CTransportLayerBase<T>::AddRefExternal( void )
    {
        AutoLock lock( m_lock );
        m_nRefCountExternal++;

        return m_nRefCountExternal;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    unsigned long CTransportLayerBase<T>::ReleaseExternal( void )
    {
        AutoLock lock( m_lock );
        if (m_nRefCountExternal == 0)
        {
            // PYLON_ASSERT(false); //something is wrong with reference counting <- triggered by test code
            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "ReleaseTL called too often." );
        }
        else
        {
            m_nRefCountExternal--;
        }

        const unsigned long resultingCount = m_nRefCountExternal +
            (m_nRefCountInternal ? 1 : 0); //any internal ref count blocks destruction

        return resultingCount;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    unsigned long CTransportLayerBase<T>::AddRefInternal( void )
    {
        AutoLock lock( m_lock );
        m_nRefCountInternal++;

        return m_nRefCountInternal;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    unsigned long CTransportLayerBase<T>::ReleaseInternal( void )
    {
        bool triggerCleanup = false;
        {
            AutoLock lock( m_lock );
            if (m_nRefCountInternal == 0)
            {
                PYLON_ASSERT2( m_nRefCountInternal != 0, "ref count cannot be 0 when calling this. Check your AddRefInternal/ReleaseInternal calls" );
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "ReleaseInternal called too often." );
            }
            else
            {
                m_nRefCountInternal--;
            }
            if (m_nRefCountInternal == 0 && m_nRefCountExternal == 0)
            {
                //User has buggy CreateTl/ReleaseTL impl
                //INFO: We need to call the CTLFactory for cleanup
                //Increase external ref artificially to be able to make the call without triggering logging and asserts
                m_nRefCountExternal++;
                triggerCleanup = true;
            }
        }
        volatile int retval = m_nRefCountInternal;
        if (triggerCleanup)
        {
            //WARNING: Must not be called inside lock, can produce deadlock otherwise
            CTlFactory::GetInstance().ReleaseTl( this );
        }
        return retval;
    }


    ///////////////////////////////////////////////////////////////////////////
    // This default implementation assumes that the device factory itself is the provider
    // for device description files.
    template<class T>
    IXmlFileProviderPrivate* CTransportLayerBase<T>::GetXmlFileProvider( void )
    {
        return dynamic_cast<IXmlFileProviderPrivate*>(this);
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    bool CTransportLayerBase<T>::IsTLEnabled()
    {
        return m_isEnabled;
    }


    ///////////////////////////////////////////////////////////////////////////
    //DEPRECATED use CreateDevice(const CDeviceInfo& di) instead
    template<class T>
    IPylonDevice* CTransportLayerBase<T>::CreateDevice( const String_t& uniqueName )
    {
        // Check, if Environment PYLON_USE_TL exist,
        // if yes create only Device, if TL is the same!
        if (!IsTLEnabled())
        {
            return NULL;
        }

        DeviceInfoList_t dil;
        if (0 == EnumerateDevices( dil ))
        {
            return NULL; // no device found
        }

        DeviceInfoList_t::iterator it;
        for (it = dil.begin(); it != dil.end(); ++it)
        {
            if (it->GetFullName() == uniqueName)
                break;
        }
        if (it != dil.end())
            return CreateDevice( *it );
        else
            return NULL; // specific device not present
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IPylonDevice* CTransportLayerBase<T>::CreateDevice( const CDeviceInfo& di )
    {
        //nothing to inject call create device with empty list
        return CreateDevice( di, StringList_t() );
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IPylonDevice* CTransportLayerBase<T>::CreateFirstDevice( const CDeviceInfo& di )
    {
        //nothing to inject call create device with empty list
        return CreateFirstDevice( di, StringList_t() );
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IPylonDevice* CTransportLayerBase<T>::CreateDevice( const CDeviceInfo& di, const StringList_t& InjectedXmlStrings )
    {
        if (!di.IsUserProvided())
        {
            return CreateDeviceImpl( di, InjectedXmlStrings );
        }
        else
        {
            CDeviceInfo deviceFound;
            FindDevice( di, deviceFound, false );
            return CreateDeviceImpl( deviceFound, InjectedXmlStrings );
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IPylonDevice* CTransportLayerBase<T>::CreateFirstDevice( const CDeviceInfo& di, const StringList_t& InjectedXmlStrings )
    {
        if (!di.IsUserProvided())
        {
            return CreateDeviceImpl( di, InjectedXmlStrings );
        }
        else
        {
            CDeviceInfo deviceFound;
            FindDevice( di, deviceFound, true );
            return CreateDeviceImpl( deviceFound, InjectedXmlStrings );
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    void CTransportLayerBase<T>::FindDevice( const CDeviceInfo& userProvidedInfo, CDeviceInfo& outDeviceFound, bool allowAnyFirstFound )
    {
        // Check, if Environment PYLON_USE_TL exist,
        // if yes create only Device, if TL is the same!
        if (!IsTLEnabled())
        {
            throw RUNTIME_EXCEPTION( "Device not accessible. Transport layer is restricted by the environment" );
        }

        if (InternalNeedsTlSpecificDeviceDiscovery( userProvidedInfo ))
        {
            outDeviceFound = InternalDoTlSpecificDeviceDiscovery( userProvidedInfo );

            if (!InternalIsSubset( outDeviceFound, userProvidedInfo ))
            {
                throw RUNTIME_EXCEPTION( "The found device does not contain all the provided device info properties." );
            }
        }
        else
        {
            // Check, can create device
            if (userProvidedInfo.IsDeviceClassAvailable()
                 && !InternalMatchDeviceClass( userProvidedInfo.GetDeviceClass() ))
            {
                String_t msg( String_t( "The device class " ) + userProvidedInfo.GetDeviceClass() + " is not supported by this transport layer. This transport layer supports " + InternalGetDeviceClass() + "." );
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, msg.c_str() );
                throw RUNTIME_EXCEPTION( msg );
            }

            DeviceInfoList_t filter;
            DeviceInfoList_t result;
            filter.push_back( userProvidedInfo );

            // Enumerate possible devices
            int found = EnumerateDevices( result, filter, false );
            if (0 == found)
            {
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "No device is available or no device contains the provided device info properties" );
                throw RUNTIME_EXCEPTION( "No device is available or no device contains the provided device info properties" );
            }
            else if (found == 1 || allowAnyFirstFound) // Success, exactly one device matches or first found
            {
                outDeviceFound = result[0];
            }
            else //The properties match for multiple camera devices
            {
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "Too many devices (%d) match the provided device info properties, don't know which device to use.", int( result.size() ) );
                throw RUNTIME_EXCEPTION( "Too many devices (%d) match the provided device info properties, don't know which device to use.", int( result.size() ) );
            }

            if (userProvidedInfo.GetPropertyAvailable( Pylon::Key::UnlockString ))
            {
                //if userProvidedInfo contains unlock info, copy unlock info
                String_t unlockInfo;
                userProvidedInfo.GetPropertyValue( Pylon::Key::UnlockString, unlockInfo );
                outDeviceFound.SetPropertyValue( Pylon::Key::UnlockString, unlockInfo );
            }
            std::string strKey;
            GetSetAvailablePowerKey( strKey );
            if (userProvidedInfo.GetPropertyAvailable( strKey.c_str() ))
            {
                //if userProvidedInfo contains set available power info, copy available power info
                String_t setAvailablePowerValue;
                userProvidedInfo.GetPropertyValue( strKey.c_str(), setAvailablePowerValue );
                outDeviceFound.SetPropertyValue( strKey.c_str(), setAvailablePowerValue );
            }
            ClearString( strKey );
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IPylonDevice* CTransportLayerBase<T>::CreateDeviceImpl( const CDeviceInfo& diIn, const StringList_t& injectedXmlStringsIn )
    {
        PYLON_ASSERT( !diIn.IsUserProvided() );

        // Check, if Environment PYLON_USE_TL exist,
        // if yes create only Device, if TL is the same!
        if (!IsTLEnabled())
        {
            throw RUNTIME_EXCEPTION( "Device creation failed. Transport layer is restricted by the environment" );
        }

        //copy information of parameters for later extension by creation observer (plug-in) or by config file registry
        CDeviceInfo di( diIn );
        StringList_t injectedXmlStrings;

        StringList_t loadedFilesOrComments;
        String_t strXMLSource;

        //get information from the config file registry
        CConfigFileRegistry::CBinding binding = CConfigFileRegistry::GetInstance().GetXmlFileBinding( di );
        String_t localFileName;
        StringList_t additionalFileNames;
        const bool loadFromFile = binding.XmlFileLocation( localFileName );
        bool loadFromDevice = binding.DownloadFromDevice();
        const bool loadAdditionalFile = binding.AdditionalXmlFileLocations( additionalFileNames );

        // Task #41855 : suppress camera loading when _nlx is available
        String_t surrogateDeviceXMLData; //surrogate with this data (to be searched in all loaded xml injections inside the code below)
        bool surrogateIsFile = false;
        bool suppressDeviceXML = false;
        std::string strKey;
        GetNoLoadXMLKey( strKey );
        if (di.GetPropertyAvailable( strKey.c_str() ))
        {
            suppressDeviceXML = true;
        }
        ClearString( strKey );


        //additional files must be loaded first
        //load additional files if needed (ConfigFileRegistry)
        if (loadAdditionalFile)
        {

            for (StringList_t::iterator it = additionalFileNames.begin(); it != additionalFileNames.end(); it++)
            {
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "About to merge file '%s' into xml.", (*it).c_str() );
                injectedXmlStrings.push_back( String_t( "file://" ) + (*it) );
                loadedFilesOrComments.push_back( *it );
            }
        }


        //parse :
        // 1. collect all file name and file-comment occurrences for generating XMLExtensionSource_*
        // 2. eventually, replace the camera.xml download with one of these files (_nlx is set)
        for (StringList_t::const_iterator it = injectedXmlStringsIn.begin(), it_end = injectedXmlStringsIn.end(); it != it_end; ++it)
        {
            if (_strnicmp( it->c_str(), "file://", 7 ) == 0) // Task #41853 : inject files via URL, check for file:// (at pos 0 only,  80/20 )
            {
                if (suppressDeviceXML && it == injectedXmlStringsIn.begin()) //Task #41855 : _nlx is set, do not load camera xml, use this one instead
                {
                    //suppress device download and load this file instead
                    surrogateDeviceXMLData = *it;
                    surrogateIsFile = true;
                    loadFromDevice = false;
                }
                else
                {
                    // Remember filename
                    const char* pFilename = &(it->c_str())[7];
                    loadedFilesOrComments.push_back( pFilename ); // Task #41812 cache filename

                    // Add to list of injected files
                    injectedXmlStrings.push_back( *it );
                }
            }
            else
            {
                if (suppressDeviceXML && it == injectedXmlStringsIn.begin()) //Task #41855 : _nlx is set, do not load camera xml, use this one instead
                {
                    // Suppress device download and load this xml fragment instead
                    surrogateDeviceXMLData = *it;
                    surrogateIsFile = false;
                    loadFromDevice = false;

                    // Get the file name from comment if any
                    strXMLSource = "user provided";// mark to indicate _nlx switch is used (replaced by filename if comment is available)
                    if (_strnicmp( it->c_str(), "<!--file://", 11 ) == 0) // Task #41812 cache comment
                    {
                        size_t nPosCommentEnd = it->find( "-->" );
                        if (nPosCommentEnd > 11)
                        {
                            String_t s( &(it->c_str())[11], nPosCommentEnd - 11 );
                            // xml loaded from filesystem
                            strXMLSource = s;
                        }
                    }
                }
                else
                {
                    // Get the file name from comment if any
                    if (_strnicmp( it->c_str(), "<!--file://", 11 ) == 0) // Task #41812 cache comment
                    {
                        size_t nPosCommentEnd = it->find( "-->" );
                        if (nPosCommentEnd > 11)
                        {
                            String_t s( &(it->c_str())[11], nPosCommentEnd - 11 );
                            loadedFilesOrComments.push_back( s );
                            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "About to merge file '%s' into xml.", s.c_str() );
                        }
                    }

                    injectedXmlStrings.push_back( it->c_str() );
                }
            }
        }

        //notify the device creation observer that a device is about to be created
        if (m_pDeviceCreationObserver)
        {
            m_pDeviceCreationObserver->OnCreateDevice( di, injectedXmlStrings );
        }

        //check for modified device information
        if (static_cast<CInfoPrivateT<CDeviceInfo>&>(di).IsModified())
        {
            // modified device infos are rejected by pylon to prevent misuse
            // deliberately be not to specific about the cause
            throw RUNTIME_EXCEPTION( "Device creation failed." );
        }

        //create the device
        IPylonDevice* pDevice = InternalCreateDevice( di );
        if (!pDevice)
        {
            PYLON_ASSERT( false ); //no TL returns NULL
            throw RUNTIME_EXCEPTION( "Internal error. Device creation failed. Created device is NULL." );
        }

        //get the private interface
        IPylonDevicePrivate* pDevicePrivate = dynamic_cast<IPylonDevicePrivate*>(pDevice);
        if (!pDevicePrivate)
        {
            PYLON_ASSERT( false ); //all devices implement IPylonDevicePrivate
            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "Device creation failed. Device doesn't implement IPylonDevicePrivate interface" );
            throw RUNTIME_EXCEPTION( "Internal error. Device creation failed. Device doesn't implement IPylonDevicePrivate interface" );
        }

        try
        {
            // retrieve the xml file from the device
            bool hasLoadedFromDevice( false );

            // Check if xml was loaded from device
            if (loadFromDevice) // Always false in Task #41855 when _nlx is set
            {
                try
                {
                    // Get the xml provider
                    std::vector<uint8_t> XmlData;
                    IXmlFileProviderPrivate* pXmlProvider = GetXmlFileProvider();

                    //if the provider can deliver the xml file, get it
                    if (pXmlProvider && pXmlProvider->CanProvideXmlFile( pDevice->GetDeviceInfo() ))
                    {
                        //get the xml file
                        pXmlProvider->ProvideXmlFileRaw( pDevice->GetDeviceInfo(), XmlData ); //use di; device info from device does not have key any more
                        hasLoadedFromDevice = true;
                        bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Downloaded XML from device '%s' length %d", pDevice->GetDeviceInfo().GetFullName().c_str(), XmlData.size() );

                        // Create the node map
                        if (hasLoadedFromDevice)
                        {
                            pDevicePrivate->CreateNodemapFromXmlData( XmlData, injectedXmlStrings, gtl::GetValue( *this, "ChunkNodeMapSupportEnable", false ) );
                        }

                        // Mark as loaded from device.
                        strXMLSource = "Device";
                    }
                }
                catch (const GenericException& e)
                {
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Error downloading XML from device '%s': %s", pDevice->GetDeviceInfo().GetFullName().c_str(), e.what() );
                    throw;
                }
                catch (const std::exception& e)
                {
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Error downloading XML from device '%s': %s", pDevice->GetDeviceInfo().GetFullName().c_str(), e.what() );
                    throw;
                }
                catch (...)
                {
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Error downloading XML from device '%s'", pDevice->GetDeviceInfo().GetFullName().c_str() );
                    throw;
                }
            }
            else if (suppressDeviceXML) //Task #41855 : Load surrogate instead of download camera xml
            {
                // Generate correct log message
                if (surrogateIsFile)
                {
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Using XML from path '%s' for device '%s'", surrogateDeviceXMLData.c_str(), pDevice->GetDeviceInfo().GetFullName().c_str() );
                }
                else
                {
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Using XML (%s) for device '%s'", strXMLSource.c_str(), pDevice->GetDeviceInfo().GetFullName().c_str() );
                }

                // Convert surrogateDeviceXMLData to XmlData buffer
                std::vector<uint8_t> XmlData( surrogateDeviceXMLData.c_str(), surrogateDeviceXMLData.c_str() + surrogateDeviceXMLData.size() );

                // Create the node map
                pDevicePrivate->CreateNodemapFromXmlData( XmlData, injectedXmlStrings, gtl::GetValue( *this, "ChunkNodeMapSupportEnable", false ) );

                // security: limit _nlx to FW update of broken cameras by allowing a only limited number of nodes, actually only a port is needed
                if (pDevice && pDevice->GetNodeMap() && pDevice->GetNodeMap()->GetNumNodes() > 3)
                {
                    pDevice->GetNodeMap()->Connect( NULL );
                }
            }

            // load the node map from a local file
            if (!hasLoadedFromDevice && !suppressDeviceXML)
            {
                //check if loading from file is allowed
                if (!loadFromFile)
                {
                    // binding doesn't allow loading from a local file
                    bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "Device creation failed. Don't know what XML configuration file to use for the device %s", pDevice->GetDeviceInfo().GetFullName().c_str() );
                    throw RUNTIME_EXCEPTION( "Device creation failed. Don't know what XML configuration file to use for the device %s", pDevice->GetDeviceInfo().GetFullName().c_str() );
                }
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvInfo, "Using XML from path '%s' for device '%s'", localFileName.c_str(), pDevice->GetDeviceInfo().GetFullName().c_str() );

                // Convert localFileName to XmlData buffer
                String_t localFileNameWithPrefix( String_t( "file://" ) + localFileName );
                std::vector<uint8_t> XmlData( localFileNameWithPrefix.c_str(), localFileNameWithPrefix.c_str() + localFileNameWithPrefix.size() );

                // Create the node map
                pDevicePrivate->CreateNodemapFromXmlData( XmlData, injectedXmlStrings, gtl::GetValue( *this, "ChunkNodeMapSupportEnable", false ) );

                // xml loaded from filesystem
                strXMLSource = localFileName;
            }

            // store the location where the xml file is read from in the device info
            // We must use the cameras device info instance here.
            // do not use the DIin parameter here since it will be discarded.
            CDeviceInfo& device_DI = const_cast<CDeviceInfo&>(pDevice->GetDeviceInfo());
            device_DI.SetPropertyValue( Key::XMLSourceKey, strXMLSource );

            // Enumerate comments and filenames to show them late e.g. in pylon viewer #41812
            int nPropertyNr = 0;
            for (StringList_t::const_iterator it = loadedFilesOrComments.begin(), it_end = loadedFilesOrComments.end(); it != it_end; ++it)
            {
                char buffer[100];
                nPropertyNr++;
                sprintf( buffer, "XMLExtensionSource_%d", nPropertyNr );
                device_DI.SetPropertyValue( buffer, *it );
            }

            //If you reuse a device info from an IPylonDevice repeatedly, like the pylon viewer does, XMLSourceKey and XMLExtensionSource_ is overwritten
            //and causes the device info to set the isModified flag. On next creation device info will be rejected, because it has been tampered with.
            //TODO: XMLExtensionSource_ can be wrong when reusing a device info from a pylon device.
            //      To be clarified in PSTPS project, where a lot of changes in this area are expected.
            static_cast<CInfoPrivateT<CDeviceInfo>&>(device_DI).ClearAccessFlags();

            // Add device to the list of created devices
            // This will add a reference to the TL for each device we store
            m_pAvailableDevices->AddItem( pDevice );

        }
        catch (...) // Destroy the created device on error
        {
            // Do not leak the device
            pDevicePrivate->Delete();
            throw;
        }


        return pDevice;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    void CTransportLayerBase<T>::DestroyDevice( Pylon::IPylonDevice* pDevice )
    {
        // Note: The following code contains a race condition but multi-threaded destruction
        // of the an object is a use case that never makes sense.
        // If this happens it will be handled safely and a message is logged.
        if (m_pAvailableDevices->Contains( pDevice ))
        {
            // this will release one reference to the TL
            m_pAvailableDevices->DestroyItem( pDevice );
        }
        else
        {
            throw LOGICAL_ERROR_EXCEPTION( "Trying to destroy device which hasn't been created by me" );
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // used by derived TL classes to allow controlled destruction of all devices in it's d'tor
    template<class T>
    void CTransportLayerBase<T>::DestroyAllDevices( void )
    {
        if (m_pAvailableDevices != NULL)
        {
            // this will release one reference to the TL for each device destroyed
            m_pAvailableDevices->DestroyAll();
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // used by derived TL classes to allow controlled destruction of all Interfaces in it's d'tor
    template<class T>
    void CTransportLayerBase<T>::DestroyAllInterfaces()
    {
        if (m_pAvailableInterfaces != NULL)
        {
            // this will release one reference to the TL for each Interface destroyed
            m_pAvailableInterfaces->DestroyAll();
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    GENAPI_NAMESPACE::INodeMap* CTransportLayerBase<T>::GetNodeMap( void )
    {
        GENAPI_NAMESPACE::INodeMap* internalNodeMap = InternalGetNodeMap();

        return internalNodeMap ? internalNodeMap : m_pDefaultParams;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    int CTransportLayerBase<T>::EnumerateInterfaces( InterfaceInfoList_t& list, bool addToList/* = false*/ )
    {
        if (!addToList)
        {
            list.clear();
        }

        size_t initialSize = list.size();
        int addedInterfaces = InternalEnumerateInterfaces( list );

        // sort newly discovered interfaces
        PYLON_ASSERT( list.size() >= initialSize );
        std::sort( list.begin() + initialSize, list.end() );

        return addedInterfaces;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IInterface* CTransportLayerBase<T>::CreateInterface( const CInterfaceInfo& interfaceInfo )
    {
        // Check, can create interface at all
        if (interfaceInfo.IsDeviceClassAvailable()
             && interfaceInfo.GetDeviceClass() != InternalGetDeviceClass())
        {
            String_t msg( String_t( "The device class " ) + interfaceInfo.GetDeviceClass() + " is not supported by this transport layer. This transport layer supports " + InternalGetDeviceClass() + "." );
            bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, msg.c_str() );
            throw RUNTIME_EXCEPTION( msg );
        }

        //is user provided?
        if (interfaceInfo.IsUserProvided())
        {
            InterfaceInfoList_t list;
            // Enumerate possible interface
            int numInterfaces = EnumerateInterfaces( list, false /*addToList*/ );
            int numFound = 0;
            int firstFound = 0;

            //loop over the found interface
            for (int interfaceIndex = 0; interfaceIndex < numInterfaces; ++interfaceIndex)
            {
                //do the user provided values match?
                if (list[interfaceIndex].IsSubset( interfaceInfo ))
                {
                    if (0 == numFound)
                    {
                        firstFound = interfaceIndex;
                    }
                    ++numFound;
                }
            }

            if (0 == numFound)
            {
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "No interface is available or no interface contains the provided interface info properties" );
                throw RUNTIME_EXCEPTION( "No interface is available or no interface contains the provided interface info properties" );
            }
            else if (1 == numFound) // Success, exactly one interface matches
            {
                //Create an interface
                IInterface* pInterface = InternalCreateInterface( list[firstFound] );
                PYLON_ASSERT2( pInterface, "Created Interface must not be NULL" );
                // Add it to the internal book keeping; the interface keeps the TL alive via reference counting
                m_pAvailableInterfaces->AddItem( pInterface );
                return pInterface;
            }
            else //The properties match for multiple camera devices
            {
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, "Too many interfaces (%d) match the provided interface info properties, don't know which interface to use.", numFound );
                throw RUNTIME_EXCEPTION( "Too many interfaces (%d) match the provided interface info properties, don't know which interface to use.", numFound );
            }
        }
        else //not user provided and device class matches
        {
            //Create an interface
            IInterface* pInterface = InternalCreateInterface( interfaceInfo );
            PYLON_ASSERT2( pInterface, "Created Interface must not be NULL" );
            // Add it to the internal book keeping; the interface keeps the TL alive via reference counting
            m_pAvailableInterfaces->AddItem( pInterface );
            return pInterface;
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    void CTransportLayerBase<T>::DestroyInterface( IInterface* pInterface )
    {
        // Note: The following code contains a race condition but multi-threaded destruction
        // of the an object is a use case that never makes sense.
        // If this happens it will be handled safely and a message is logged.
        if (m_pAvailableInterfaces->Contains( pInterface ))
        {
            // this will release one reference to the TL
            m_pAvailableInterfaces->DestroyItem( pInterface );
        }
        else
        {
            throw LOGICAL_ERROR_EXCEPTION( "Trying to destroy interface which hasn't been created by me" );
        }
    }

    // ----------------------------------------------------------------------------------------------------------------------
    // default implementation
    // ----------------------------------------------------------------------------------------------------------------------


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    GENAPI_NAMESPACE::INodeMap* CTransportLayerBase<T>::InternalGetNodeMap( void )
    {
        return NULL;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    int CTransportLayerBase<T>::InternalEnumerateInterfaces( InterfaceInfoList_t& list )
    {
        // This is the default implementation of an Interface.
        // This method will be called when not overridden by the specific TL.
        CInfoPrivateT<CInterfaceInfo> info;
        info.SetDeviceClass( this->GetTlInfo().GetDeviceClass() );
        info.SetVendorName( this->GetTlInfo().GetVendorName() );
        info.SetInterfaceID( DefaultInterfaceName );
        info.SetTLType( this->GetTlInfo().GetTLType() );
        info.ClearUserProvidedFlag();
        info.ClearAccessFlags();
        list.push_back( info );

        return 1; //one InterfaceInfo added
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IInterface* CTransportLayerBase<T>::InternalCreateInterface( const CInterfaceInfo& interfaceInfo )
    {
        // Note: CreateInterafce will create an individual DefaultInterfaces inctances on each call.
        // These can be all opend/closed individually. Real interface implementaiosn can be created multiple times,
        // but will fail to open as the underyling hardware will prevent it. (PR3550)
        IInterface* pInterface = new CDefaultInterface( this, interfaceInfo );
        return pInterface;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    IDeviceCreationObserver* CTransportLayerBase<T>::SetDeviceCreationObserver( IDeviceCreationObserver* pDeviceCreationObserver )
    {
        //save old observer
        IDeviceCreationObserver* m_oldObserver( m_pDeviceCreationObserver );

        //set new observer
        m_pDeviceCreationObserver = pDeviceCreationObserver;

        return m_oldObserver;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    bool CTransportLayerBase<T>::IsDeviceAccessible( const CDeviceInfo& deviceInfo, AccessModeSet mode, EDeviceAccessiblityInfo* pAccessibilityInfo /*= NULL*/ )
    {
        if (deviceInfo.IsUserProvided())
        {
            // Check, can check device
            if (deviceInfo.IsDeviceClassAvailable()
                 && deviceInfo.GetDeviceClass() != InternalGetDeviceClass())
            {
                String_t msg( String_t( "The device class " ) + deviceInfo.GetDeviceClass() + " is not supported by this transport layer. This transport layer supports " + InternalGetDeviceClass() + "." );
                bclog::LogTrace( detail_base_tl::GetPylonBaseTLCatID(), bclog::lvError, msg.c_str() );
                throw RUNTIME_EXCEPTION( msg );
            }

            CDeviceInfo deviceFound;
            FindDevice( deviceInfo, deviceFound, false );
            return InternalIsDeviceAccessible( deviceFound, mode, pAccessibilityInfo );
        }
        else
        {
            // modified device infos are rejected by pylon to prevent misuse
            if (static_cast<CInfoPrivateT<CDeviceInfo>&>(const_cast<CDeviceInfo&>(deviceInfo)).IsModified())
            {
                if (pAccessibilityInfo)
                {
                    *pAccessibilityInfo = Accessibility_Unknown;
                }
                return false;
            }

            return InternalIsDeviceAccessible( deviceInfo, mode, pAccessibilityInfo );
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    void CTransportLayerBase<T>::SetProperty( int propertyId, const void* pData, size_t size )
    {
        switch (Pylon::safe_cast<Permission::PropertyId>(propertyId))
        {
            case Permission::Prop_TestProperty:
            {
                if (NULL == pData)
                {
                    throw INVALID_ARGUMENT_EXCEPTION( "No data passed." );
                }
                if (size <= 0)
                {
                    throw INVALID_ARGUMENT_EXCEPTION( "Invalid size passed." );
                }

                // test property won't save anything. Just return if the params are ok
            }
            break;

            case Permission::Prop_UpdateLicense:
            {
                if ((NULL != pData)
                     && (size > 0))
                {
                    std::vector<uint8_t> v( (uint8_t*) pData, (uint8_t*) pData + size );

                    m_licenseHolder.swap( v );
                }
                else
                {
                    m_licenseHolder.clear();
                }

                return;
            }
            break;

            case Permission::Prop_EnablingState:
            {
                if (pData && size >= sizeof m_isEnabled)
                {
                    m_isEnabled = *reinterpret_cast<const bool*>(pData);
                }
            }
            break;

            default:
                throw INVALID_ARGUMENT_EXCEPTION( "Unsupported property ID passed." );
                break;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    template<class T>
    void CTransportLayerBase<T>::GetProperty( int propertyId, void* pData, size_t* pSize ) const
    {
        switch (safe_cast<Permission::PropertyId>(propertyId))
        {
            // test property used for unit tests
            case Permission::Prop_TestProperty:
            {
                if (NULL == pSize)
                {
                    throw INVALID_ARGUMENT_EXCEPTION( "No size passed." );
                }

                if (NULL != pData)
                {
                    if (*pSize >= sizeof( uint64_t ))
                    {
                        // just return a testpattern
                        memset( pData, 0xcd, sizeof( uint64_t ) );
                        *pSize = sizeof( uint64_t );
                    }
                    else
                    {
                        *pSize = sizeof( uint64_t );
                        throw INVALID_ARGUMENT_EXCEPTION( "Insufficient amount of data passed." );
                    }
                }
                else
                {
                    *pSize = sizeof( uint64_t );
                }
            }
            break;

            case Permission::Prop_NumberLicenses:
            {
                if (NULL == pSize)
                {
                    throw INVALID_ARGUMENT_EXCEPTION( "No size passed." );
                }

                if (NULL != pData)
                {
                    if (*pSize >= sizeof( size_t ))
                    {
                        const size_t n = m_licenseHolder.empty() ? 0 : 1;
                        *reinterpret_cast<size_t*>(pData) = n;
                        *pSize = sizeof( size_t );
                    }
                    else
                    {
                        *pSize = sizeof( size_t );
                        throw INVALID_ARGUMENT_EXCEPTION( "Insufficient amount of data passed." );
                    }
                }
                else
                {
                    *pSize = sizeof( size_t );
                }
            }
            break;

            case Permission::Prop_EnablingState:
            {
                if (pSize && *pSize >= sizeof m_isEnabled && pData)
                {
                    *reinterpret_cast<bool*>(pData) = m_isEnabled;
                    *pSize = sizeof m_isEnabled;
                }
            }
            break;

            default:
                throw INVALID_ARGUMENT_EXCEPTION( "Unsupported property ID passed." );
                break;
        }
    }

} // namespace Pylon

#pragma warning (pop)

#endif
