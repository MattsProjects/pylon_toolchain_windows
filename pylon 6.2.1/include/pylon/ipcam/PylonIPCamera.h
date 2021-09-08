//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Generic pylon IP camera interface
*/
#pragma once

#ifndef PYLON_IP_CAMERA_H
#define PYLON_IP_CAMERA_H


#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <pylon/StreamGrabberProxy.h>
#include <pylon/EventGrabberProxy.h>
#include <pylon/PylonDeviceProxy.h>

#include <pylon/ipcam/PylonIpCamDeviceInfo.h>


namespace Pylon
{
    //**************************************************************************************************
    //! Class for pylon IP cameras providing access to transport layer related parameters.
    /**
    \see \ref configuringcameras
    \ingroup PYLON_IP
    */
    //**************************************************************************************************
    //PYLON_DEFINE_NODEMAP(CPylonIPTLParams, CNodeMapProxyT<>);
    typedef void CPylonIPTLParams;

    //**************************************************************************************************
    //! Class for pylon IP cameras providing access to stream grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup PYLON_IP
    */
    //**************************************************************************************************
    //PYLON_DEFINE_STREAMGRABBER(CPylonIPStreamGrabber, CStreamGrabberProxyT<>);
    typedef void CPylonIPStreamGrabber;


    //**************************************************************************************************
    //! Class for pylon IP cameras providing access to event grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup PYLON_IP
    */
    //**************************************************************************************************
    //PYLON_DEFINE_EVENTGRABBER(CPylonIPEventGrabber, CEventGrabberProxyT<>);
    typedef void CPylonIPEventGrabber;


    //**************************************************************************************************
    //! The camera class for pylon IP camera devices
    /**
    This is the base class for pylon IP cameras providing access to camera parameters.
    \see \ref configuringcameras

    \tparam TCameraParams  The camera specific parameter class (auto generated from camera xml file)
    \ingroup PYLON_IP

    \deprecated This class is deprecated in pylon 6.0. Please consider using CBaslerUniversalInstantCamera instead.
    */
    //**************************************************************************************************
    template<class TCameraParams>
    class CPylonIPCameraT : public CPylonDeviceProxyT<TCameraParams>
    {
    public:
        typedef Pylon::CPylonIpCamDeviceInfo DeviceInfo_t;    //!< \copybrief Pylon::CPylonIpCamDeviceInfo
        typedef Pylon::CPylonIPTLParams      TlParams_t;      //!< \copybrief Pylon::CPylonIPTLParams
        typedef Pylon::CPylonIPStreamGrabber StreamGrabber_t; //!< \copybrief Pylon::CPylonIPStreamGrabber
        typedef Pylon::CPylonIPEventGrabber  EventGrabber_t;  //!< \copybrief Pylon::CPylonIPEventGrabber

        //! The name of this device class, use this for enumeration
        static String_t DeviceClass()
        {
            return BaslerIpCamDeviceClass;
        }

    public:
        //! \name Construction
        // \{

        /** \brief \copybrief Pylon::CPylonIPCameraT<TCameraParams>::CPylonIPCameraT()

        \copydetails Pylon::CPylonIPCameraT<TCameraParams>::CPylonIPCameraT()
        */
        CPylonIPCameraT()
        {
        };

              /** \brief \copybrief Pylon::CPylonIPCameraT<TCameraParams>::CPylonIPCameraT(IPylonDevice*,bool)

              \copydetails Pylon::CPylonIPCameraT<TCameraParams>::CPylonIPCameraT(IPylonDevice*,bool)
              */
        CPylonIPCameraT( IPylonDevice* pDevice, bool takeOwnership = true )
            : CPylonDeviceProxyT<TCameraParams>( pDevice, takeOwnership )
        {
        }

        //\}
    };


} // namespace Pylon

#endif // PYLON_IP_CAMERA_H
