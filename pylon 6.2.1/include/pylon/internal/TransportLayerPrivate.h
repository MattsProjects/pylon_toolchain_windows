//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the ITransportLayerPrivate interface and CTransportLayerBase
*/

#ifndef INCLUDED_PYLONTRANSPORTLAYERPRIVATE_H
#define INCLUDED_PYLONTRANSPORTLAYERPRIVATE_H

#pragma once
#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/stdinclude.h>
#include <pylon/Device.h>
#include <pylon/internal/XmlFileProviderPrivate.h>
#include "pylon/TransportLayer.h"

#pragma warning (push)
#pragma warning(disable:4275) // non dll-interface class used

namespace Pylon
{

    /**
        \internal
        Needed for pylon transport layer plug-in adapter
    */
    interface PUBLIC_INTERFACE IDeviceCreationObserver
    {
        virtual void OnCreateDevice( CDeviceInfo& deviceInfo, StringList_t& injectedXmlStrings ) = 0;
    };

    /**
        \internal
        Private interface used by the factory for
        device creation

    */
    interface PUBLIC_INTERFACE ITransportLayerPrivate
    {
        //External reference counting triggered by using CTlFactory::ReleaseTL and CTlFactory::CreateTL:
        virtual unsigned long AddRefExternal() = 0;
        virtual unsigned long ReleaseExternal() = 0; //may be called indirectly by ReleaseInternal for destruction of TL due to current design

        //Internal reference counting, e.g. for open devices:
        virtual unsigned long AddRefInternal() = 0;
        //WARNING: due to current design ReleaseInternal must call CTlFactory::ReleaseTL and therefore indirectly ReleaseExternal for destruction of TL
        virtual unsigned long ReleaseInternal() = 0;

        // Set Observer; can pass NULL; return already installed observer
        virtual IDeviceCreationObserver* SetDeviceCreationObserver( IDeviceCreationObserver* pDeviceCreationObserver ) = 0;

        /** \brief Set the value of a property.
        \param propertyId Identifies the property.
        \param pData A pointer to the buffer containing the data.
        \param size Size of the buffer in bytes.
        */
        virtual void SetProperty( int propertyId, const void* pData, size_t size ) = 0;

        /** \brief Retrieve the value of a property.
        \param propertyId Identifies the property
        \param pData Pointer to the buffer for the data.
        \param pSize Size of the buffer in bytes when calling. Holds the resulting size on return.
        */
        virtual void GetProperty( int propertyId, void* pData, size_t* pSize ) const = 0;
    };


    class DeviceMap;
    class InterfaceMap;
    interface IXmlFileProvider;

    namespace Permission
    {
        enum PropertyId
        {
            Prop_TestProperty = 0x7357, // Test property (has a size of 8)
            Prop_UpdateLicense = 0x10001,
            Prop_EnumInfo = 0xE4F1, // Query information for license generation
            Prop_NumberLicenses,
            Prop_EnablingState = 0x32f1a5// TL enabling state (has size of bool)
        };
    }

    /**
      \brief Base class for transport layer classes
    */
    template <class T = ITransportLayer>
    class CTransportLayerBase
        : public T
        , public ITransportLayerPrivate
    {
    public:
        CTransportLayerBase( void );
        virtual ~CTransportLayerBase( void );

        /// \name ITransportLayer implementation
        // \{
        virtual int EnumerateDevices( DeviceInfoList_t& list, bool addToList = false );
        virtual int EnumerateDevices( DeviceInfoList_t& list, const DeviceInfoList_t& filter, bool addToList = false );
        virtual IPylonDevice* CreateDevice( const CDeviceInfo& di );
        virtual IPylonDevice* CreateFirstDevice( const CDeviceInfo& di = CDeviceInfo() );
        virtual IPylonDevice* CreateDevice( const CDeviceInfo& di, const StringList_t& InjectedXmlStrings );
        virtual IPylonDevice* CreateFirstDevice( const CDeviceInfo& di, const StringList_t& InjectedXmlStrings );
        virtual IPylonDevice* CreateDevice( const String_t& );
        virtual void DestroyDevice( IPylonDevice* );
        virtual CDeviceInfo CreateDeviceInfo( void );
        virtual GENAPI_NAMESPACE::INodeMap* GetNodeMap( void );
        virtual int EnumerateInterfaces( InterfaceInfoList_t& list, bool addToList = false );
        virtual IInterface* CreateInterface( const CInterfaceInfo& interfaceInfo );
        virtual void DestroyInterface( IInterface* pInterface );
        virtual bool IsDeviceAccessible( const CDeviceInfo& deviceInfo, AccessModeSet mode = Control, EDeviceAccessiblityInfo* pAccessibilityInfo = NULL );
        virtual void SetProperty( int propertyId, const void* pData, size_t size );
        virtual void GetProperty( int propertyId, void* pData, size_t* pSize ) const;
        // \}

        /// \name ITransportLayerPrivate implementation
        // \{
        virtual unsigned long AddRefExternal( void );
        virtual unsigned long ReleaseExternal( void );
        // \}

    protected:
        virtual unsigned long AddRefInternal( void );
        virtual unsigned long ReleaseInternal( void );

        // Override this, when the device factory is not the XmlFileProvider
        virtual IXmlFileProviderPrivate* GetXmlFileProvider( void );

        // check, if transport layer is allowed and not disabled by environment variable
        virtual bool IsTLEnabled();


        virtual IPylonDevice* CreateDeviceImpl( const CDeviceInfo& di, const StringList_t& InjectedXmlStrings );
        int InternalApplyFilter( const DeviceInfoList_t& list, const DeviceInfoList_t& filter, DeviceInfoList_t& result );
        void FindDevice( const CDeviceInfo& userProvidedInfo, CDeviceInfo& outDeviceFound, bool allowAnyFirstFound );
        virtual IDeviceCreationObserver* SetDeviceCreationObserver( IDeviceCreationObserver* pDeviceCreationObserver );
        virtual void DestroyAllDevices( void );
        virtual void DestroyAllInterfaces( void );

        virtual int InternalEnumerateDevices( DeviceInfoList_t& ) = 0;
        virtual IPylonDevice* InternalCreateDevice( const CDeviceInfo& di ) = 0;
        virtual CDeviceInfo InternalCreateDeviceInfo( void ) = 0;
        virtual bool InternalIsSubset( const CDeviceInfo& info, const CDeviceInfo& subset )  const = 0;
        virtual String_t InternalGetDeviceClass() const = 0;
        virtual bool InternalMatchDeviceClass( const String_t& deviceClass ) const;
        virtual bool InternalNeedsTlSpecificDeviceDiscovery( const CDeviceInfo& info ) const;
        virtual CDeviceInfo InternalDoTlSpecificDeviceDiscovery( const CDeviceInfo& info );
        virtual GENAPI_NAMESPACE::INodeMap* InternalGetNodeMap( void );
        virtual int InternalEnumerateInterfaces( InterfaceInfoList_t& );
        virtual IInterface* InternalCreateInterface( const CInterfaceInfo& interfaceInfo ); //destruction is TL agnostic, performed via IInterfacePrivate::Delete
        virtual bool InternalIsDeviceAccessible( const CDeviceInfo& deviceInfo, AccessModeSet mode, EDeviceAccessiblityInfo* pAccessibilityInfo ) = 0;

    private:
        DeviceMap* m_pAvailableDevices;
        InterfaceMap* m_pAvailableInterfaces;
        GENAPI_NAMESPACE::INodeMap* m_pDefaultParams;
        IDeviceCreationObserver* m_pDeviceCreationObserver;
        bool m_isEnabled;
    protected:
        std::vector< uint8_t > m_licenseHolder; // hold a binary blob
        CLock m_lock; //lock used for device map and reference counting, can be used by TL impl
    private:
        int m_nRefCountExternal; //pylon user ref count
        int m_nRefCountInternal; //internal ref count
    };

} // namespace Pylon


#pragma warning (pop)

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_PYLONTRANSPORTLAYERPRIVATE_H */
