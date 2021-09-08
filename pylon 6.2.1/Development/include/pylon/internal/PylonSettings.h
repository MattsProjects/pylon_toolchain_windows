//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
#ifndef INCLUDED_PYLONSETTINGS_H_9610865
#define INCLUDED_PYLONSETTINGS_H_9610865

#include <pylon/PylonBase.h>
#include <pylon/Platform.h>
#include <StringHelper/CharStore.h>



namespace Pylon
{
    ///////////////////////////////////////////////////////////////////////////
    //
    inline const char* GetTransportLayerPluginSettingName()
    {
#if defined(PYLON_WIN_BUILD)
#  if defined(PYLON_64_BUILD)
        return "TransportLayerPluginX64";
#  else
        return "TransportLayerPluginWin32";
#  endif
#elif defined(PYLON_UNIX_BUILD)
        return "TransportLayerPlugin";
#else
#  error Unsupported plattform;
#endif
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    inline const char* GetLicenseSettingName()
    {
        // Use a static object so we can return the c_str()
        static CSelfDestructingString str = BS( "License" );
        return str.c_str();
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    inline const char* GetSettingsDirectorySettingName()
    {
        return "SettingsDirectory";
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    class PYLONBASE_API CPylonSettings
    {
    public:
        static void UpdateSettings();
        static void ClearSettings();
        static bool GetSetting( const char* pName, String_t& value );
        static bool SetSetting( const char* pName, const String_t& value );
    };
}

#endif /* INCLUDED_PYLONSETTINGS_H_9610865 */
