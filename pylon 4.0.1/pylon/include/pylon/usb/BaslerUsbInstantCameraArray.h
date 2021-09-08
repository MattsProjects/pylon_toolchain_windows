//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2012-2013 Basler
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief USB specific instant camera array class.
*/
#ifndef INCLUDED_BASLERUSBINSTANTCAMERAARRAY_H_5817072
#define INCLUDED_BASLERUSBINSTANTCAMERAARRAY_H_5817072

#include <pylon/usb/BaslerUsbInstantCamera.h>
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiUsb
     * @{
     */

    /*!
    \class  CBaslerUsbInstantCameraArray
    \brief  USB specific instant camera array

    \threading
        The CBaslerUsbInstantCameraArray class is not thread-safe.
    */
    class CBaslerUsbInstantCameraArray : public CDeviceSpecificInstantCameraArrayT<CBaslerUsbInstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        CBaslerUsbInstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t) 
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        CBaslerUsbInstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBaslerUsbInstantCamera>(numberOfCameras) {}

    };

    /** 
     * @}
     */
}

#endif /* INCLUDED_BASLERUSBINSTANTCAMERAARRAY_H_5817072 */
