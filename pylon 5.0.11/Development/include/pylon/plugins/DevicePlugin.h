//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief  Contains the plug-in interface for pylon devices.
*/

#ifndef INCLUDED_DEVICEPLUGIN_H_3378565
#define INCLUDED_DEVICEPLUGIN_H_3378565

#include <pylon/Device.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

namespace Pylon
{
    interface IStreamGrabberPlugin;

    /*!
    \interface  IDevicePlugin
    \brief  Usable to extend the capabilities of a pylon device.
    */
    interface IDevicePlugin
    {
        /*!
        \brief Initialize the pylon device plug-in.

        This method is called after a %Pylon Device has been created.

        \attention Special care must be taken when making calls to the passed %Pylon Device
                   to not put it into an unexpected or bad state.

        \param[in]  pDevice The pointer to the %Pylon Device.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void Initialize( IPylonDevice* pDevice) = 0;


        /*!
        \brief Create a pylon stream grabber plug-in.

        If no plug-in is needed, NULL can be returned.
        This method is called after a stream grabber has been retrieved.

        \param[in]  index The index of the stream grabber that is extended by the plug-in.
        \return The pointer to the created pylon stream grabber plug-in or NULL if no plug-in for the stream grabber is required.

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual IStreamGrabberPlugin* CreateStreamGrabberPlugin( uint32_t index) = 0;


        /*!
        \brief Destroy a pylon stream grabber plug-in.

        \param[in]  pStreamGrabberPlugin The pointer to the previously created pylon stream grabber plug-in.
                                         The value of \c pStreamGrabberPlugin can be NULL.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void DestroyStreamGrabberPlugin( IStreamGrabberPlugin* pStreamGrabberPlugin) = 0;


        /*!
        \brief This method is called before the %Pylon Device is opened.

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnDeviceOpen() = 0;


        /*!
        \brief This method is called after the %Pylon Device is opened.

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnDeviceOpened() = 0;


        /*!
        \brief This method is called before the %Pylon Device is closed.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnDeviceClose() = 0;


        /*!
        \brief This method is called after the %Pylon Device is closed.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnDeviceClosed() = 0;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */


#endif /* INCLUDED_DEVICEPLUGIN_H_3378565 */
