//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2008-2014 Basler AG
//  http://www.baslerweb.com
//  Author:  JS
//-----------------------------------------------------------------------------
/*!
\file
\brief includes specific for the Camera Link transport layer
*/

#ifndef PYLON_CAMERALINK_INCLUDED_INCLUDED__
#define PYLON_CAMERALINK_INCLUDED_INCLUDED__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>
#include <pylon/StreamGrabberProxy.h>
#include <pylon/DeviceClass.h>
#include <pylon/cameralink/PylonCLSerDeviceInfo.h>

namespace Pylon
{
    const char* const CLSerTransportLayer("Camera Link");

    // just use forwards to make generated header PylonCLSerIncludes compilable
    class CPylonCLSerDeviceInfo;
    class CPylonCLSerDevice;

    typedef void CPylonCLSerEventGrabber;
    
    // aliases until classes are renamed properly
    typedef CPylonCLSerDeviceInfo CBaslerCameraLinkDeviceInfo; // *JS*
}

#endif // PYLON_CAMERALINK_INCLUDED_INCLUDED__
