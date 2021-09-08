//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2016 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief  Contains the plug-in interface for pylon transport layers.
*/

#ifndef INCLUDED_TRANSPORTLAYERPLUGIN_H_7297589
#define INCLUDED_TRANSPORTLAYERPLUGIN_H_7297589

#include <pylon/stdinclude.h>
#include <pylon/DeviceInfo.h>
#include <pylon/Container.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

namespace Pylon
{
    interface IDevicePlugin;

    /*!
    \interface  ITransportLayerPlugin
    \brief  Usable to extend the capabilities of a pylon transport layer.
    */
    interface ITransportLayerPlugin
    {
        /*!
        \brief Create a pylon device plug-in.

        The passed device information ca be used to decide what type of device plug-in is used.
        If no plug-in is needed, NULL can be returned.
        This method is called after a %Pylon Device has been created.

        \param[in]  deviceInfo The information of the camera device.
        \return The pointer to the created pylon device plug-in or NULL if no plug-in for the device is required.

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual IDevicePlugin* CreateDevicePlugin( const CDeviceInfo& deviceInfo) = 0;


        /*!
        \brief Destroy a pylon device plug-in.

        This method is called before the %Pylon Device is destroyed.

        \param[in]  pDevicePlugin The pointer to the previously created pylon device plug-in.
                                  The value of \c pDevicePlugin can be NULL.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void DestroyDevicePlugin( IDevicePlugin* pDevicePlugin) = 0;


        /*!
        \brief Provides information about a device that is about to be created.

        This method is called before a %Pylon Device is created.

        \param[in]  deviceInfo         The properties of the camera device.
        \param[in]  injectedXmlStrings Additional strings that are injected.
                                       Currently only one injected xml string is supported.

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnTransportLayerCreateDevice( CDeviceInfo& deviceInfo, StringList_t& injectedXmlStrings) = 0;


        /*!
        \brief Provides information about the result of the enumeration.

        This method is called when the enumeration has finished.
        Unwanted devices can be removed from the enumeration result.

        \param[in]  enumeratedDevices  The list of enumerated devices.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnEnumerationFinished( DeviceInfoList_t& enumeratedDevices) = 0;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */


#endif /* INCLUDED_TRANSPORTLAYERPLUGIN_H_7297589 */
