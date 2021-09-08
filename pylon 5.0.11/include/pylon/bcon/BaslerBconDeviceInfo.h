//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2011-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the CBaslerBconDeviceInfo class
*/

#ifndef INCLUDED_BCON_DEVICEINFO_H
#define INCLUDED_BCON_DEVICEINFO_H

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/PylonBase.h>
#include <pylon/DeviceInfo.h>


namespace Pylon
{
    namespace Key
    {
        ///Identifies the name of BCON adapter library including extension without path information.
        const char* const BconAdapterLibraryNameKey("BconAdapterLibraryName");
        ///Identifies the version of the externally provided BCON adapter library. The format is:v{major}.{minor}
        const char* const BconAdapterLibraryVersionKey("BconAdapterLibraryVersion");
        ///Identifies the version of the BCON Adapter API the BCON adapter library has been implemented for. The format is:v{major}.{minor}
        const char* const BconAdapterLibraryApiVersionKey("BconAdapterLibraryApiVersion");
        ///Identifies the version of the BCON Adapter API currently supported by pylon. The format is:v{major}.{minor}
        const char* const SupportedBconAdapterApiVersionKey("SupportedBconAdapterApiVersion");
    }

    /*!
    \ingroup Pylon_TransportLayer
    \class CBaslerBconDeviceInfo
    \brief PylonBcon specific Device Info object.
    */
    class PYLONBASE_API CBaslerBconDeviceInfo : public Pylon::CDeviceInfo
    {
    public:
        CBaslerBconDeviceInfo();
        CBaslerBconDeviceInfo(const CDeviceInfo& di);
        virtual ~CBaslerBconDeviceInfo();

        ///Retrieves the name of BCON adapter library including extension without path information.
        ///This property is identified by Key::BconAdapterLibraryNameKey.
        String_t GetBconAdapterLibraryName() const;
        ///Sets the above property.
        CBaslerBconDeviceInfo& SetBconAdapterLibraryName(const String_t& BconAdapterLibraryNameValue);
        ///Returns true if the above property is available.
        bool IsBconAdapterLibraryNameAvailable() const;

        ///Retrieves the version of the externally provided BCON adapter library. The format is:v{major}.{minor}
        ///This property is identified by Key::BconAdapterLibraryVersionKey.
        String_t GetBconAdapterLibraryVersion() const;
        ///Sets the above property.
        CBaslerBconDeviceInfo& SetBconAdapterLibraryVersion(const String_t& BconAdapterLibraryVersionValue);
        ///Returns true if the above property is available.
        bool IsBconAdapterLibraryVersionAvailable() const;

        ///Retrieves the version of the BCON Adapter API the BCON adapter library has been implemented for. The format is:v{major}.{minor}
        ///This property is identified by Key::BconAdapterLibraryApiVersionKey.
        String_t GetBconAdapterLibraryApiVersion() const;
        ///Sets the above property.
        CBaslerBconDeviceInfo& SetBconAdapterLibraryApiVersion(const String_t& BconAdapterLibraryApiVersionValue);
        ///Returns true if the above property is available.
        bool IsBconAdapterLibraryApiVersionAvailable() const;

        ///Retrieves the version of the BCON Adapter API currently supported by pylon. The format is:v{major}.{minor}
        ///This property is identified by Key::SupportedBconAdapterApiVersionKey.
        String_t GetSupportedBconAdapterApiVersion() const;
        ///Sets the above property.
        CBaslerBconDeviceInfo& SetSupportedBconAdapterApiVersion(const String_t& SupportedBconAdapterApiVersionValue);
        ///Returns true if the above property is available.
        bool IsSupportedBconAdapterApiVersionAvailable() const;

        ///Retrieves the manufacturer info.
        ///This property is identified by Key::ManufacturerInfo.
        String_t GetManufacturerInfo() const;
        ///Returns true if the above property is available.
        bool IsManufacturerInfoAvailable() const;

        ///Retrieves the device index. For internal use only.
        ///This property is identified by Key::DeviceIdx.
        String_t GetDeviceIdx() const;
        ///Returns true if the above property is available.
        bool IsDeviceIdxAvailable() const;

 
    protected:
        CBaslerBconDeviceInfo& SetManufacturerInfo( const String_t& );
        CBaslerBconDeviceInfo& SetDeviceIdx( const String_t& );
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_BCON_DEVICEINFO_H */
