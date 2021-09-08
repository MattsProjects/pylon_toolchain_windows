//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2016 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief BCON specific instant camera array class.
*/
#ifndef INCLUDED_BCON_INSTANTCAMERAARRAY_H
#define INCLUDED_BCON_INSTANTCAMERAARRAY_H

#include <pylon/bcon/BaslerBconInstantCamera.h>
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiBcon
     * @{
     */

    /*!
    \class  CBaslerBconInstantCameraArray
    \brief  BCON specific instant camera array

    \threading
        The CBaslerBconInstantCameraArray class is not thread-safe.
    */
    class CBaslerBconInstantCameraArray : public CDeviceSpecificInstantCameraArrayT<CBaslerBconInstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        CBaslerBconInstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        CBaslerBconInstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBaslerBconInstantCamera>(numberOfCameras) {}

    };

    /**
     * @}
     */
}

#endif /* INCLUDED_BCON_INSTANTCAMERAARRAY_H */
