//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Low Level API: Generic pylon BCON camera interface
*/

#ifndef BASLER_BCON_CAMERA_H
#define BASLER_BCON_CAMERA_H

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000
#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */


#include "PylonBconCamera.h"

#include "_BaslerBconCameraParams.h"


namespace Pylon
{
    //**************************************************************************************************
    //! Low Level API: The camera class for Basler BCON camera devices
    /**
    Class for Basler BCON cameras providing access to camera parameters.
    \see \ref configuringcameras

    \ingroup Pylon_LowLevelApi

    \deprecated This class is deprecated in pylon 6.0. Please consider using CBaslerUniversalInstantCamera instead.
    */
    //**************************************************************************************************
    PYLON_DEFINE_CAMERA( CBaslerBconCamera, Pylon::CPylonBconCameraT<Basler_BconCameraParams::CBconCameraParams_Params> );

} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // BASLER_BCON_CAMERA_H
