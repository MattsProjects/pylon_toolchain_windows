//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Low Level API: Generic pylon CamEmu camera interface
*/

#ifndef PYLON_CAMEMU_CAMERA_H
#define PYLON_CAMEMU_CAMERA_H

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */


#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <pylon/StreamGrabberProxy.h>
#include <pylon/EventGrabberProxy.h>

#include "BaslerCamEmuDeviceInfo.h"
#include <pylon/PylonDeviceProxy.h>


namespace Pylon
{
    //**************************************************************************************************
    //! Low Level API: Class for pylon CamEmu cameras providing access to transport layer related parameters.
    /**
    \see \ref configuringcameras
    \ingroup PYLON_CAMEMU
    */
    //**************************************************************************************************
    //PYLON_DEFINE_NODEMAP(CPylonCamEmuTLParams, CNodeMapProxyT<>);
    typedef void CPylonCamEmuTLParams;

    //**************************************************************************************************
    //! Low Level API: Class for pylon CamEmu cameras providing access to stream grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup PYLON_CAMEMU
    */
    //**************************************************************************************************
    //PYLON_DEFINE_STREAMGRABBER(CPylonCamEmuStreamGrabber, CStreamGrabberProxyT<>);
    typedef void CPylonCamEmuStreamGrabber;


    //**************************************************************************************************
    //! Low Level API: Class for pylon CamEmu cameras providing access to event grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup PYLON_CAMEMU
    */
    //**************************************************************************************************
    //PYLON_DEFINE_EVENTGRABBER(CPylonCamEmuEventGrabber, CEventGrabberProxyT<>);
    typedef void CPylonCamEmuEventGrabber;


    //**************************************************************************************************
    //! Low Level API: The camera class for pylon CamEmu camera devices
    /**
    This is the base class for pylon CamEmu cameras providing access to camera parameters.
    \see \ref configuringcameras

    \tparam TCameraParams  The camera specific parameter class (auto generated from camera xml file)
    \ingroup PYLON_CAMEMU

    \deprecated This class is deprecated in pylon 6.0. Please consider using CBaslerUniversalInstantCamera instead.
    */
    //**************************************************************************************************
    template<class TCameraParams>
    class CPylonCamEmuCameraT : public CPylonDeviceProxyT<TCameraParams>
    {
    public:
        typedef Pylon::CBaslerCamEmuDeviceInfo   DeviceInfo_t;    //!< \copybrief Pylon::CBaslerCamEmuDeviceInfo
        typedef Pylon::CPylonCamEmuTLParams      TlParams_t;      //!< \copybrief Pylon::CPylonCamEmuTLParams
        typedef Pylon::CPylonCamEmuStreamGrabber StreamGrabber_t; //!< \copybrief Pylon::CPylonCamEmuStreamGrabber
        typedef Pylon::CPylonCamEmuEventGrabber  EventGrabber_t;  //!< \copybrief Pylon::CPylonCamEmuEventGrabber

        //! The name of this device class, use this for enumeration
        static String_t DeviceClass()
        {
            return BaslerCamEmuDeviceClass;
        }

    public:
        //! \name Construction
        // \{

        /** \brief \copybrief Pylon::CPylonDeviceProxyT<TCameraParams>::CPylonDeviceProxyT()

        \copydetails Pylon::CPylonDeviceProxyT<TCameraParams>::CPylonDeviceProxyT()
        */
        CPylonCamEmuCameraT()
        {
        };

              /** \brief \copybrief Pylon::CPylonDeviceProxyT<TCameraParams>::CPylonDeviceProxyT(IPylonDevice*,bool)

              \copydetails Pylon::CPylonDeviceProxyT<TCameraParams>::CPylonDeviceProxyT(IPylonDevice*,bool)
              */
        CPylonCamEmuCameraT( IPylonDevice* pDevice, bool takeOwnership = true )
            : CPylonDeviceProxyT<TCameraParams>( pDevice, takeOwnership )
        {
        }

        //\}
    };


} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // PYLON_CAMEMU_CAMERA_H
