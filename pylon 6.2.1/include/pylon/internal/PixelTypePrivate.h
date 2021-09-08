//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
    \file
    \brief  Contains internal pixel type related functions.
*/

#ifndef INCLUDED_PIXELTYPEPRIVATE_H_08721125
#define INCLUDED_PIXELTYPEPRIVATE_H_08721125

#include <limits> // for numeric_limits

#include <Base/GCBase.h> //for INVALID_ARGUMENT_EXCEPTION

#include <pylon/Platform.h>
#include <pylon/PylonBase.h>
#include <pylon/PixelType.h>

#pragma pack(push, PYLON_PACKING)

namespace Pylon
{
    // compute stride in bit, works for all pixel types
    inline size_t ComputeStrideBits( EPixelType pixelType, uint32_t width )
    {
        if (width > static_cast<uint32_t>(std::numeric_limits<int32_t>::max()))
        {
            throw INVALID_ARGUMENT_EXCEPTION( "The unsigned width parameter value exceeds the maximum allowed value. Probably a negative value has been passed." );
        }

        uint32_t const bitPerPixel = BitPerPixel( pixelType );
        uint32_t const planeCount = PlaneCount( pixelType );

        switch (pixelType)
        {
            case PixelType_YUV422planar:
            case PixelType_YUV420planar:
            case PixelType_YCbCr422_8_YY_CbCr_Semiplanar:
            case PixelType_YCbCr420_8_YY_CbCr_Semiplanar:
                throw INVALID_ARGUMENT_EXCEPTION( "Cannot compute stride. The image planes are of different sizes." );

            default:
                break;
        }

        if (bitPerPixel % planeCount)
        {
            //should never happen
            throw INVALID_ARGUMENT_EXCEPTION( "The value of bit per pixel is not divisible by the number of planes." );
        }

        uint32_t bitPerPixelPlane = bitPerPixel / planeCount;

        uint64_t value = static_cast<uint64_t>(bitPerPixelPlane) * static_cast<uint64_t>(width);

        //check out of bounds
        if (value > std::numeric_limits<size_t>::max())
        {
            throw INVALID_ARGUMENT_EXCEPTION( "Cannot compute stride. The return value exceeds SIZE_MAX." );
        }

        return static_cast<size_t>(value);
    }
}

#pragma pack(pop)

#endif /* INCLUDED_PIXELTYPEPRIVATE_H_08721125 */
