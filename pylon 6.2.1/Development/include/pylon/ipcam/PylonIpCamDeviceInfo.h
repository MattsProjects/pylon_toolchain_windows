//-----------------------------------------------------------------------------
//  Copyright (c) 2007-2021 Basler AG
//  Section: Basler Components
//  Project: PYLON
//  Author:  JS
//  $Header:  $
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of CPylonPylonIpCamDeviceInfo
*/

#pragma once

#ifndef PYLONIPCAMDEVICEINFO_H__
#define PYLONIPCAMDEVICEINFO_H__

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
        // Internal use only. Therefore not part of CDeviceInfo.

        ///Identifies the uniform resource identifier of the device.
        const char* const URIKey = "URI";
        ///Identifies the default timeout.
        const char* const DefaultTimeoutKey = "DefaultTimeout";
    }

    /*!
    \brief PylonIpCam specific Device Info object.
    */
    class PYLONBASE_API CPylonIpCamDeviceInfo : public Pylon::CDeviceInfo
    {
    public:
        CPylonIpCamDeviceInfo();
        CPylonIpCamDeviceInfo( const CDeviceInfo& di );

        /* The underlying implementation does not need to support all the listed properties.
        The properties that are not supported always have the value "N/A" which is the value of CInfoBase::PropertyNotAvailable */

        ///Retrieves the uniform resource identifier of the device.
        ///This property is identified by Key::URIKey.
        String_t GetURI() const;
        ///Sets the above property.
        CPylonIpCamDeviceInfo& SetURI( const String_t& URIValue );
        ///Returns true if the above property is available.
        bool IsURIAvailable() const;

        ///Retrieves the default timeout.
        ///This property is identified by Key::DefaultTimeoutKey.
        String_t GetDefaultTimeout() const;
        ///Sets the above property.
        CPylonIpCamDeviceInfo& SetDefaultTimeout( const String_t& DefaultTimeoutValue );
        ///Returns true if the above property is available.
        bool IsDefaultTimeoutAvailable() const;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // PYLONIPCAMDEVICEINFO_H__
