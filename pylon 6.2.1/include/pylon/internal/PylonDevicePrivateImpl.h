//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief Handles general XML loading and node map creation tasks for devices.
*/

#ifndef INCLUDED_PYLONDEVICEPRIVATEIMPL_H_6746942
#define INCLUDED_PYLONDEVICEPRIVATEIMPL_H_6746942

#include <pylon/internal/Utilities.h> //for textFileToString
#include <pylon/internal/Strings.h>
#include <Base/GCException.h>
#include <GenApi/NodeMapRef.h>
#include <pylon/internal/PylonDevicePrivate.h>
#include <pylon/internal/UnixMappings.h>
#include <boost/shared_ptr.hpp>

#include <StringHelper/Stringhelper.h>
#include <StringHelper/CharStore.h>

namespace Pylon
{
    typedef boost::shared_ptr<GENAPI_NAMESPACE::CNodeMapRef> ChunkNodeMapPtrT;

    template <typename IPylonDeviceT>
    class CPylonDevicePrivateImpl
        : public IPylonDevicePrivate
        , public IPylonDeviceT
    {
    protected:

        //This is only for using the correct assignment operator.
        template<typename T>
        void SetNodeMap( GENAPI_NAMESPACE::CNodeMapRefT<T>& nodeMapRef, GENAPI_NAMESPACE::INodeMap* pNodeMap )
        {
            nodeMapRef = pNodeMap;
        }


        GENAPI_NAMESPACE::CNodeMapFactory CreateNodeMapFactoryForFile(
            const String_t& XmlFileName,
            bool noCache,
            bool suppressStrings
            )
        {
            //check is zip file
            bool isZipFile = false;
            if (XmlFileName.size() > 4)
            {
                const char* pFilenameExt = &(XmlFileName.c_str())[XmlFileName.size() - 4];
                if (_strnicmp( pFilenameExt, ".zip", 4 ) == 0)
                {
                    isZipFile = true;
                }
            }

            //create the node map factory
            GENAPI_NAMESPACE::CNodeMapFactory factory(
            (isZipFile ? GENAPI_NAMESPACE::ContentType_ZippedXml : GENAPI_NAMESPACE::ContentType_Xml),
                XmlFileName,
                (noCache ? GENAPI_NAMESPACE::CacheUsage_Ignore : GENAPI_NAMESPACE::CacheUsage_Automatic),
                suppressStrings );

            return factory;
        }


        GENAPI_NAMESPACE::CNodeMapFactory CreateNodeMapFactoryForString(
            const String_t& XmlStringData, /*<- must not be freed or changed while being attached to factory*/
            bool noCache,
            bool suppressStrings
            )
        {
            // Task #41853 load file by URL, simple check (80/20) for file:// at first position in string
            if (XmlStringData.size() >= 7 && _strnicmp( XmlStringData.c_str(), "file://", 7 ) == 0)
            {
                String_t filename( XmlStringData.substr( 7 ) );
                return CreateNodeMapFactoryForFile( filename, noCache, suppressStrings );
            }
            else
            {
                GENAPI_NAMESPACE::CNodeMapFactory factory(
                    GENAPI_NAMESPACE::ContentType_Xml,
                    XmlStringData.c_str(),
                    XmlStringData.size(),
                    (noCache ? GENAPI_NAMESPACE::CacheUsage_Ignore : GENAPI_NAMESPACE::CacheUsage_Automatic),
                    suppressStrings );

                return factory;
            }
        }


        bool IsInjectionAllowed( const String_t& XmlStringData /*<- must not be freed or changed while being attached to factory*/ )
        {
            //security: These nodes are used for detecting Basler devices, therefor it is not allowed to inject them
            //usually injection files are quite small, so that this should be fast enough
            GENAPI_NAMESPACE::CNodeMapFactory factory = CreateNodeMapFactoryForString( XmlStringData, true /*noCache, no traces*/, true/*suppress doc strings*/ );
            GENAPI_NAMESPACE::CNodeMapRef ptrNodeMap = factory.CreateNodeMap();
            GENAPI_NAMESPACE::INode* pServiceBoardIdSelector = ptrNodeMap._GetNode( GetServiceBoardIdSelectorString().c_str() );
            GENAPI_NAMESPACE::INode* pBslUSBSpeedMode = ptrNodeMap._GetNode( GetBslUSBSpeedModeString().c_str() );
            bool isAllowed = pServiceBoardIdSelector == NULL && pBslUSBSpeedMode == NULL;
            return isAllowed;
        }


        //currently only used for master xml file
        GENAPI_NAMESPACE::CNodeMapFactory CreateNodeMapFactoryForVector( const std::vector<uint8_t>& xmlDataTextNotNullTerminated )
        {
            // Task #41853 load file by URL, simple check (80/20) for file:// at first position in vector
            if (xmlDataTextNotNullTerminated.size() >= 7 && _strnicmp( (const char*) &xmlDataTextNotNullTerminated[0], "file://", 7 ) == 0)
            {
                String_t filename( (const char*) &xmlDataTextNotNullTerminated[7], xmlDataTextNotNullTerminated.size() - 7 );
                return CreateNodeMapFactoryForFile( filename, false /*cache auto*/, false /*no suppress strings*/ );
            }
            else
            {
                GENAPI_NAMESPACE::CNodeMapFactory factory( GENAPI_NAMESPACE::ContentType_Xml, &xmlDataTextNotNullTerminated[0], xmlDataTextNotNullTerminated.size(), GENAPI_NAMESPACE::CacheUsage_Automatic, false /*suppress strings*/ );
                return factory;
            }
        }


        template <typename NodeMapRefT>
        void CreateNodemapImpl(
            NodeMapRefT& nodeMapRef,
            GENAPI_NAMESPACE::CNodeMapFactory& nodeMapFactory,
            const StringList_t& InjectedXmlStrings,
            bool extractChunks
            )
        {
            // add injection strings
            for (StringList_t::const_iterator it = InjectedXmlStrings.begin(), it_end = InjectedXmlStrings.end(); it != it_end; ++it)
            {
                // Security: Injection of secret nodes are not allowed
                if (IsInjectionAllowed( *it ))
                {
                    GENAPI_NAMESPACE::CNodeMapFactory injectedCameraDescriptionFile = CreateNodeMapFactoryForString( *it, false /*cache auto*/, false /*no suppress strings*/ );
                    nodeMapFactory.AddInjectionData( injectedCameraDescriptionFile );
                }
            }

            // create the camera node map
            GENAPI_NAMESPACE::INodeMap* pNodeMap = nodeMapFactory.CreateNodeMap( "Device", false /* do not release source data*/ );
            SetNodeMap( nodeMapRef, pNodeMap );

            if (extractChunks)
            {
                const String_t chunkRootNode( "ChunkData" );
                //if it has a chunk data node
                if (pNodeMap->GetNode( chunkRootNode ))
                {
                    m_chunkDataNodeMapFactory = nodeMapFactory.ExtractSubtree( chunkRootNode, true );
                }
            }
        }


        template <typename NodeMapRefT>
        void CreateNodemapFromXmlDataImpl( NodeMapRefT& nodeMapRef, const std::vector<uint8_t>& xmlData, const StringList_t& injectedXmlStrings, bool extractChunks )
        {
            // Check for minimum size for ZIP header check
            if (xmlData.size() > 4)
            {
                // Check if xml data contains zipped data (Check for ZIP magic)
                if (_strnicmp( reinterpret_cast<const char*>(&xmlData[0]), "PK\x03\x04", 4 ) == 0)
                {
                    // Here we have zip data
                    GENAPI_NAMESPACE::CNodeMapFactory factory( GENAPI_NAMESPACE::ContentType_ZippedXml, &xmlData[0], xmlData.size(), GENAPI_NAMESPACE::CacheUsage_Automatic, false /*suppress strings*/ );
                    CreateNodemapImpl( nodeMapRef, factory, injectedXmlStrings, extractChunks && GetChunkDataNodeMapSupported() );
                }
                else
                {
                    // Here we need to check for file url. Data comes from camera or url must extracted.
                    GENAPI_NAMESPACE::CNodeMapFactory factory = CreateNodeMapFactoryForVector( xmlData );
                    CreateNodemapImpl( nodeMapRef, factory, injectedXmlStrings, extractChunks && GetChunkDataNodeMapSupported() );
                }
            }
            else
            {
                // Throw runtime exception that no xml data was passed.
                throw RUNTIME_EXCEPTION( "Create Nodemap from XML data failed." );
            }
        }


        virtual bool GetChunkDataNodeMapSupported()
        {
            return false; //default is false -> not supported; overridden by tl specific device implementation
        }


        virtual bool ChunkDataXmlDescriptionAvailable()
        {
            bool res = GetChunkDataNodeMapSupported() && m_chunkDataNodeMapFactory.IsPreprocessed();
            return res;
        }


        virtual ChunkNodeMapPtrT CreateChunkNodeMap()
        {
            if (ChunkDataXmlDescriptionAvailable())
            {
                ChunkNodeMapPtrT ptr( new ChunkNodeMapPtrT::element_type );
                *ptr = m_chunkDataNodeMapFactory.CreateNodeMap();
                return ptr;
            }
            return ChunkNodeMapPtrT();
        }


    private:
        GENAPI_NAMESPACE::CNodeMapFactory m_chunkDataNodeMapFactory;
    };
}

#endif /* INCLUDED_PYLONDEVICEPRIVATEIMPL_H_6746942 */
