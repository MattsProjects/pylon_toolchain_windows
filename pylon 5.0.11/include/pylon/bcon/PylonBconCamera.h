//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2017 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief BCON API: Generic pylon BCON camera interface
*/

#ifndef PYLON_BCON_CAMERA_H
#define PYLON_BCON_CAMERA_H

#if _MSC_VER > 1000
#   pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include "../DeviceClass.h"
#include "../NodeMapProxy.h"
#include "../StreamGrabberProxy.h"

#include "BaslerBconDeviceInfo.h"
#include "../PylonDeviceProxy.h"

#include "_BconStreamParams.h"
#include "_BconTLParams.h"


namespace Pylon
{
    //**************************************************************************************************
    //! BCON API: Class for pylon BCON cameras providing access to transport layer related parameters.
    /**
    \see \ref configuringcameras
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    PYLON_DEFINE_NODEMAP(CPylonBconTLParams, CNodeMapProxyT<Basler_BconTLParams::CBconTLParams_Params>);


    //**************************************************************************************************
    //! BCON API: Class for pylon BCON cameras providing access to stream grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    PYLON_DEFINE_STREAMGRABBER(CPylonBconStreamGrabber, CStreamGrabberProxyT<Basler_BconStreamParams::CBconStreamParams_Params>);


    //**************************************************************************************************
    //! BCON API: Class for pylon BCON cameras doesn't support event grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    typedef void CPylonBconEventGrabber;

    //**************************************************************************************************
    //! BCON API: The camera class for pylon BCON camera devices
    /**
    This is the base class for pylon BCON cameras providing access to camera parameters.
    \see \ref configuringcameras

    \tparam TCameraParams  The camera specific parameter class (auto generated from camera xml file)
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    template<class TCameraParams>
    class CPylonBconCameraT : public CPylonDeviceProxyT<TCameraParams>
    {
    public:
        typedef Pylon::CBaslerBconDeviceInfo   DeviceInfo_t;    //!< \copybrief Pylon::CBaslerBconDeviceInfo
        typedef Pylon::CPylonBconTLParams      TlParams_t;      //!< \copybrief Pylon::CPylonBconTLParams
        typedef Pylon::CPylonBconStreamGrabber StreamGrabber_t; //!< \copybrief Pylon::CPylonBconStreamGrabber
        typedef Pylon::CPylonBconEventGrabber  EventGrabber_t;  //!< \copybrief Pylon::CPylonBconEventGrabber

        /// The name of this device class, use this for enumeration
        static String_t DeviceClass() { return BaslerBconDeviceClass; }

    public:
        //! \name Construction
        // \{

        /** \brief \copybrief Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT()

        \copydetails Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT()
        */
        CPylonBconCameraT() {};

        /** \brief \copybrief Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT(IPylonDevice*,bool)

        \copydetails Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT(IPylonDevice*,bool)
        */
        CPylonBconCameraT(IPylonDevice* pDevice, bool takeOwnership = true)
            : CPylonDeviceProxyT<TCameraParams>(pDevice, takeOwnership)
        {
        }

        //\}
    };


} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // PYLON_BCON_CAMERA_H
