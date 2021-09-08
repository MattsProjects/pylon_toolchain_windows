//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Instant camera array class for blaze cameras.
*/

#pragma once

#include "BlazeInstantCamera.h"
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /*!
    \class  BlazeInstantCameraArray
    \brief  Blaze based instant camera array.

    \threading
        The BlazeInstantCameraArray class is not thread-safe.
    */
    class BlazeInstantCameraArray: public CDeviceSpecificInstantCameraArrayT<CBlazeInstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        BlazeInstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        BlazeInstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBlazeInstantCamera>(numberOfCameras) {}

    };

} // namespace Pylon

