//-----------------------------------------------------------------------------
//  Basler pylon
//  Copyright (c) 2016-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  BR
//-----------------------------------------------------------------------------
/*!
\file
\internal
\brief Implementation of the IXmlFileProviderPrivate interface
*/

#ifndef INCLUDED_PYLONXMLFILEPROVIDERPRIVATEIMPL_H
#define INCLUDED_PYLONXMLFILEPROVIDERPRIVATEIMPL_H

#pragma once
#include <pylon/Platform.h>
#include <vector>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/stdinclude.h>
#include <pylon/internal/XmlFileProviderPrivate.h>
#include <PlatformHelper/GenApi_WithoutWarnings.h>


// Defines for Windows and Linux portability
#if defined(_MSC_VER)
#   define xfp_strnicmp    _strnicmp
#elif defined (__GNUC__)
#   define xfp_strnicmp    strncasecmp
#else
#   error unsupported platform!
#endif

namespace Pylon
{
    class CDeviceInfo;

    /**
    \ Internal
    */
    struct XmlFileProviderPrivateImpl : IXmlFileProviderPrivate
    {
        //! \name Partly implementation of the IXmlFileProviderPrivate interface for old style access GeniCam access
        // \{
        void ProvideXmlFile( const CDeviceInfo& di, String_t& RecommendedFileName, String_t& XmlString )
        {
            // Download Raw XML from Device
            std::vector<uint8_t> fileBuffer;
            ProvideXmlFileRaw( di, fileBuffer );

            // Clear output parameters
            RecommendedFileName = "";
            XmlString = "";

            // Check for minimum size for ZIP header check
            if (fileBuffer.size() > 4)
            {
                // Detect if content has Zip format
                if (xfp_strnicmp( reinterpret_cast<const char*>(&fileBuffer[0]), "PK\x03\x04", 4 ) == 0)
                {
                    // Create NodeMap with NodeMapFactory
                    GENAPI_NAMESPACE::CNodeMapFactory factory( GENAPI_NAMESPACE::ContentType_ZippedXml, &fileBuffer[0], fileBuffer.size(), GENAPI_NAMESPACE::CacheUsage_Automatic, false /* suppress strings */ );

                    // Preprocess data and get unzipped XML
                    factory.Preprocess();
                    XmlString = factory.ToXml();
                }
                else
                {
                    // Store downloaded xml into XmlString
                    XmlString.assign( reinterpret_cast<const char*>(&fileBuffer[0]), fileBuffer.size() );
                }
            }
            else
            {
                // Throw runtime exception that no xml data was passed.
                throw RUNTIME_EXCEPTION( "Failed to get XML from Device" );
            }
        }
        // \}
    };
}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_PYLONXMLFILEPROVIDERPRIVATEIMPL_H */
