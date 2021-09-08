//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Low Level API: Basler CamEmu camera interface
*/

#ifndef BASLER_CAMEMU_CAMERA_H
#define BASLER_CAMEMU_CAMERA_H

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */


#include <pylon/PylonDeviceProxy.h>

#include "_BaslerCamEmuParams.h"
#include "PylonCamEmuCamera.h"

namespace Pylon
{
    //**************************************************************************************************
    //! Low Level API: The camera class for Basler CamEmu camera devices
    /**
    Class for Basler CamEmu cameras providing access to camera parameters.
    \see \ref configuringcameras

    \ingroup PYLON_CAMEMU

    \deprecated This class is deprecated in pylon 6.0. Please consider using CBaslerUniversalInstantCamera instead.
    */
    //**************************************************************************************************
    PYLON_DEFINE_CAMERA( CBaslerCamEmuCamera, Pylon::CPylonCamEmuCameraT<Basler_BaslerCamEmu::CBaslerCamEmu_Params> );

} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // BASLER_CAMEMU_CAMERA_H
