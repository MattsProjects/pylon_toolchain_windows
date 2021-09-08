//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2008-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  JS
//-----------------------------------------------------------------------------
/*!
\file Includes used by IPCam camera classes
*/

#ifndef PYLON_IPCAM_INCLUDED_INCLUDED__
#define PYLON_IPCAM_INCLUDED_INCLUDED__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

namespace Pylon
{
    const char* const IpCamTransportLayer( "IPCam" );

    // just use forwards to make generated header PylonIPCamIncludes compilable
    class CPylonIPCamDeviceInfo;
    class CPylonIpCamDevice;
    class CPylonIpCamStreamGrabber;

    typedef void CPylonIpCamEventGrabber;
}

#endif // PYLON_IPCAM_INCLUDED_INCLUDED__
