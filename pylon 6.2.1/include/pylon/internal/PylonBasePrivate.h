//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
*/

#ifndef __PYLONBASEPRIVATE_H__
#define __PYLONBASEPRIVATE_H__

#if _MSC_VER > 1000
#pragma once
#endif
// pylon/PylonBase includes pylon/Platform.h so we should include PlatformPrivate.h
#include <pylon/internal/PlatformPrivate.h>

#include <pylon/PylonBase.h>

// pylon internal flags used with AddInternalFlags & ClearInternalFlags
#define PYLON_INTERNAL_FLAG_PYLON_INITAILIZED       0x1l    // PylonInitialize has been called.

#define PYLON_INTERNAL_FLAG_NO_LOGGING_INIT         0x2l    // Don't initialize GeniCam logging in case it already has been initialized.

#define PYLON_INTERNAL_FLAG_PYLON_GUI_INITIALIZED   0x4l    // PylonGui will set this to tell PylonTerminate to call PyGTerminate

namespace Pylon
{
    PYLONBASE_API void AddInternalFlags( long flags );
    PYLONBASE_API void ClearInternalFlags( long flags );

    // forward
    class DeviceInfoList;
    typedef DeviceInfoList DeviceInfoList_t;

    // returns the global device filter instance from the environment
    PYLONBASE_API DeviceInfoList_t* GetGlobalDeviceFilterInstance();

    // Pylon::Set/GetProperty property IDs
    enum EPropertyValue
    {
        // Set the license (do not change this value, as it have been given to customers to set a license at runtime)
        EPropertyValue_License = 0x8472,
        // return enumerated devices for license generation
        EPropertyValue_EnumInfo = 0x1701
    };

}

#endif
