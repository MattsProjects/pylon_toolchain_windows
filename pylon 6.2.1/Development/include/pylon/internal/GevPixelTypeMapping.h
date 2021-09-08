//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Internally used mapping GigE Vision pixel format to pylon PixelType enumeration member
*/

#ifndef __GEVPIXELTYPEMAPPING_H__
#define __GEVPIXELTYPEMAPPING_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/PixelType.h>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-narrowing"
#endif

namespace Pylon
{

    ///holds GigE Vision pixel formats used by previous cameras
    namespace PreviousCustomGevPixelFormat
    {
        ///previous custom pixel formats that are now part of the GigE Vision standard
        enum PixelFormat
        {
            PixelType_YUV422_YUYV_Packed = 0x82100005,

            PixelType_BayerGB12Packed = 0x810c0003,
            PixelType_BayerGR12Packed = 0x810c0001,
            PixelType_BayerRG12Packed = 0x810c0002,
            PixelType_BayerBG12Packed = 0x810c0004,

            PixelType_BayerGR16 = 0x81100006,
            PixelType_BayerRG16 = 0x81100007,
            PixelType_BayerGB16 = 0x81100008,
            PixelType_BayerBG16 = 0x81100009,

            PixelType_RGB12V1packed = 0x80000000 | PIXEL_COLOR | PIXEL_BIT_COUNT( 36 ) | 0x000a
        };
    }

    ///holds PFNC standard compliant pixel formats
    namespace PFNCPixelFormat
    {
        enum PixelFormat
        {
            PixelType_YCbCr422_8 = 0x0210003B,
        };
    }

    ///Maps the GigE Vision pixel format to pylon PixelType enumeration member
    EPixelType MapGevPixelFormatToPylonPixelType( int gevPixelFormat )
    {
        //start with a simple cast as pylon PixelType and GigE Vision pixel format use the same enum values
        EPixelType mappedPixelType = static_cast<EPixelType>(gevPixelFormat);

        //if is custom pixel format of previous cameras
        if ((gevPixelFormat & 0x80000000) != 0)
        {
            //try to map the format
            switch (gevPixelFormat)
            {
                case PreviousCustomGevPixelFormat::PixelType_YUV422_YUYV_Packed:
                {
                    mappedPixelType = PixelType_YUV422_YUYV_Packed;   break;
                }

                case PreviousCustomGevPixelFormat::PixelType_BayerGB12Packed:
                {
                    mappedPixelType = PixelType_BayerGB12Packed;      break;
                }
                case PreviousCustomGevPixelFormat::PixelType_BayerGR12Packed:
                {
                    mappedPixelType = PixelType_BayerGR12Packed;      break;
                }
                case PreviousCustomGevPixelFormat::PixelType_BayerRG12Packed:
                {
                    mappedPixelType = PixelType_BayerRG12Packed;      break;
                }
                case PreviousCustomGevPixelFormat::PixelType_BayerBG12Packed:
                {
                    mappedPixelType = PixelType_BayerBG12Packed;      break;
                }

                case PreviousCustomGevPixelFormat::PixelType_BayerGR16:
                {
                    mappedPixelType = PixelType_BayerGR16;            break;
                }
                case PreviousCustomGevPixelFormat::PixelType_BayerRG16:
                {
                    mappedPixelType = PixelType_BayerRG16;            break;
                }
                case PreviousCustomGevPixelFormat::PixelType_BayerGB16:
                {
                    mappedPixelType = PixelType_BayerGB16;            break;
                }
                case PreviousCustomGevPixelFormat::PixelType_BayerBG16:
                {
                    mappedPixelType = PixelType_BayerBG16;            break;
                }

                case PreviousCustomGevPixelFormat::PixelType_RGB12V1packed:
                {
                    mappedPixelType = PixelType_RGB12V1packed;        break;
                }
            }
        }
        else
        {
            //try to map the format
            switch (gevPixelFormat)
            {
                case PFNCPixelFormat::PixelType_YCbCr422_8:
                {
                    mappedPixelType = PixelType_YUV422_YUYV_Packed;   break;
                }
            }
        }

        return  mappedPixelType;
    }

} // namespace

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif
