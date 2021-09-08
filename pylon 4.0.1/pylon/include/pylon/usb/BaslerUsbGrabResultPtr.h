//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2012-2013 Basler
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Contains the USB specific grab result ptr class.
*/

#ifndef INCLUDED_BASLERUSBGRABRESULTPTR_H_03519839
#define INCLUDED_BASLERUSBGRABRESULTPTR_H_03519839

#include <pylon/usb/BaslerUsbGrabResultData.h>
#include <pylon/private/DeviceSpecificGrabResultPtr.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiUsb
     * @{
     */

    /// The USB specific grab result smart pointer.
    PYLON_DEFINE_DEVICE_SPECIFIC_GRAB_RESULT_PTR( CBaslerUsbGrabResultPtr, CBaslerUsbGrabResultData)

     /** 
     * @}
     */
}

#endif /* INCLUDED_BASLERUSBGRABRESULTPTR_H_03519839 */
