//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Low Level API: Pylon IP camera interface for Basler IP cameras
*/

#ifndef BASLER_IP_CAMERA_H
#define BASLER_IP_CAMERA_H


#include "PylonIPCamera.h"

#include "_BaslerIPCameraParams.h"
namespace Basler_IpCameraParams = Basler_BaslerIPCamera; // Pylon 2.0 compatibility


namespace Pylon
{
    //**************************************************************************************************
    //! Low Level API: The camera class for Basler IP camera devices
    /**
    Class for Basler IP cameras providing access to camera parameters.
    \see \ref configuringcameras

    \ingroup PYLON_IP

    \deprecated This class is deprecated in pylon 6.0. Please consider using CBaslerUniversalInstantCamera instead.
    */
    //**************************************************************************************************
    PYLON_DEFINE_CAMERA( CBaslerIPCamera, Pylon::CPylonIPCameraT<Basler_IpCameraParams::CBaslerIPCamera_Params> );

} // namespace Pylon

#endif // BASLER_IP_CAMERA_H
