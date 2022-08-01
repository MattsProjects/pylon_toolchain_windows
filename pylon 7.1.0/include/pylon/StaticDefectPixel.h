//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2022 Basler AG
//  http://www.baslerweb.com
//  Author:  DV
//-----------------------------------------------------------------------------

#pragma once

#include <pylon/Platform.h>
#include <pylon/stdinclude.h>



namespace Pylon
{
    /// Type of defect pixel. \note This is currently not used.
    enum EStaticDefectPixelType
    {
        StaticDefectPixelType_Reserved = 0          //!< Not used.
    };

    /// A single defect pixel.
    struct StaticDefectPixel
    {
        uint16_t X;           //!< X coordinate.
        uint16_t Y;           //!< Y coordinate.
        EStaticDefectPixelType Type;     //!< Type of defect pixel.
    };
}
