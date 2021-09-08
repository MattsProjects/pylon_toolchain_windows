//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2016 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief BCON Specific Instant Camera class for Basler BCON devices.
*/

#ifndef INCLUDED_BCON_INSTANTCAMERA_H
#define INCLUDED_BCON_INSTANTCAMERA_H

#include <pylon/bcon/_BaslerBconCameraParams.h>
#include <pylon/bcon/BaslerBconDeviceInfo.h>
#include <pylon/bcon/BaslerBconConfigurationEventHandler.h>
#include <pylon/bcon/BaslerBconImageEventHandler.h>
#include <pylon/bcon/BaslerBconCameraEventHandler.h>
#include <pylon/bcon/BaslerBconGrabResultPtr.h>
#include <pylon/private/DeviceSpecificInstantCamera.h>
#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <pylon/bcon/_BconStreamParams.h>
#include <pylon/bcon/_BconTLParams.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiBcon
     * @{
     */

    // This dummy implementation is used by the Device Specific Instant Camera for BCON
    // because the BCON Transport Layer does not support some features.
    class CBconDummyEventParams_Params
    {
    public:
        void _Initialize(GenApi::INodeMap*)
        {
        }
    };

    class CBaslerBconInstantCamera;

    /// Lists all the types used by the Device Specific Instant Camera class for BCON.
    struct CBaslerBconInstantCameraTraits
    {
        /// The type of the final camera class.
        typedef CBaslerBconInstantCamera InstantCamera_t;
        /// \copybrief Basler_BconCameraParams::CBconCameraParams_Params
        typedef Basler_BconCameraParams::CBconCameraParams_Params CameraParams_t;
        /// \copybrief Pylon::IPylonDevice
        typedef IPylonDevice IPylonDevice_t;
        /// \copybrief Pylon::CBaslerBconDeviceInfo
        typedef Pylon::CBaslerBconDeviceInfo DeviceInfo_t;
        /// The parameters of the BCON transport layer.
        typedef CNodeMapProxyT<Basler_BconTLParams::CBconTLParams_Params> TlParams_t;
        /// The parameters of the BCON stream grabber.
        typedef CNodeMapProxyT<Basler_BconStreamParams::CBconStreamParams_Params> StreamGrabberParams_t;
        /// Not supported by BCON transport layer.
        typedef CNodeMapProxyT<CBconDummyEventParams_Params> EventGrabberParams_t;
        /// The BCON specific configuration event handler class.
        typedef CBaslerBconConfigurationEventHandler ConfigurationEventHandler_t;
        /// The BCON specific image event handler class.
        typedef CBaslerBconImageEventHandler ImageEventHandler_t;
        /// The BCON specific camera event handler class.
        typedef CBaslerBconCameraEventHandler CameraEventHandler_t;
        /// The BCON specific grab result data.
        typedef CBaslerBconGrabResultData GrabResultData_t;
        /// The BCON specific grab result smart pointer.
        typedef CBaslerBconGrabResultPtr GrabResultPtr_t;

        //! The name of this device class. Use this one for enumeration.
        static String_t DeviceClass() { return BaslerBconDeviceClass; }
    };


    /*!
    \class  CBaslerBconInstantCamera
    \brief  Extends the CInstantCamera by BCON specific parameter interface classes.
    */
    PYLON_DEFINE_INSTANT_CAMERA( CBaslerBconInstantCamera, CDeviceSpecificInstantCameraT<CBaslerBconInstantCameraTraits>)

    /**
     * @}
     */
} // namespace Pylon

#endif /* INCLUDED_BCON_INSTANTCAMERA_H */
