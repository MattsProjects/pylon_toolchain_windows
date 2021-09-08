//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Low Level API: Basler generic CamEmu camera interface

\ingroup PYLON_INTERNAL
*/

#ifndef BASLER_CAMEMU_CAMERA_H
#define BASLER_CAMEMU_CAMERA_H

#include "../DeviceClass.h"
#include "../NodeMapProxy.h"
#include "../StreamGrabberProxy.h"
#include "../EventGrabberProxy.h"

#include "BaslerCamEmuDeviceInfo.h"
#include "../PylonDeviceProxy.h"

#include "_BaslerCamEmuParams.h"
namespace Basler_CameraEmuParams = Basler_BaslerCamEmu; /// Pylon 2.0 compatibility \deprecated


namespace Pylon
{
    //**************************************************************************************************
    /// Low Level API: The camera class for pylon CamEmu camera devices
    /**
    This is the base class for pylon CamEmu cameras providing access to camera parameters.
    \see \ref configuringcameras

    \tparam TCameraParams  The camera specific parameter class (auto generated from camera xml file)
    \ingroup PYLON_INTERNAL
    */
    //**************************************************************************************************
    template<class TCameraParams>
    class CBaslerCameraEmuT : public CPylonDeviceProxyT<TCameraParams>
    {
    public:
        typedef CBaslerCamEmuDeviceInfo DeviceInfo_t;

        typedef void TlParams_t;
        typedef void StreamGrabber_t;
        typedef void EventGrabber_t;

        /// The name of this device class, use this for enumeration
        static String_t DeviceClass()
        {
            return BaslerCamEmuDeviceClass;
        }

    public:
        //! \name Construction
        // \{

        CBaslerCameraEmuT()
        {
        };

        CBaslerCameraEmuT( IPylonDevice* pDevice, bool takeOwnership = true )
            : CPylonDeviceProxyT<TCameraParams>( pDevice, takeOwnership )
        {
        }

        //\}
    };


    typedef CBaslerCameraEmuT<Basler_BaslerCamEmu::CBaslerCamEmu_Params> CBaslerCameraEmu;


} // namespace Pylon

#endif // BASLER_CAMEMU_CAMERA_H
