//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Internally used mapping USB pixel format to pylon PixelType enumeration member
*/

#ifndef __USBPIXELTYPEMAPPING_H__
#define __USBPIXELTYPEMAPPING_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/PixelType.h>

namespace Pylon
{

    ///Maps the USB pixel format to pylon PixelType enumeration member
    EPixelType MapUsbPixelFormatToPylonPixelType( uint32_t usbPixelFormat )
    {
        EPixelType pyPixelType = PixelType_Undefined;

        switch (usbPixelFormat)
        {
            // name=Mono1p; id=0x01010037; realign=8; padding_bits=0*
            // Combine 8 monochrome pixels in one byte
            case 0x01010037:
                pyPixelType = PixelType_Mono1packed; //Mono1p
                break;
                // name=Mono2p; id=0x01020038; realign=4; padding_bits=0*
                // Combine 4 monochrome pixels in one byte
            case 0x01020038:
                pyPixelType = PixelType_Mono2packed; //Mono2p
                break;
                // name=Mono4p; id=0x01040039; realign=2; padding_bits=0*
                // Combine 2 monochrome pixels in one byte
            case 0x01040039:
                pyPixelType = PixelType_Mono4packed; //Mono4p
                break;
                // name=Mono8; id=0x01080001; realign=1; padding_bits=0
                // 8-bit pixel in one byte
            case 0x01080001:
                pyPixelType = PixelType_Mono8; //Mono8
                break;
                // name=Mono8s; id=0x01080002;
            case 0x01080002:
                pyPixelType = PixelType_Mono8signed; //Mono8s
                break;
                // name=Mono10; id=0x01100003; realign=1; padding_bits=6
                // 10-bit pixel padded to 16 bits
            case 0x01100003:
                pyPixelType = PixelType_Mono10; //Mono10
                break;
                // name=Mono10p; id=0x010a0046; realign=4; padding_bits=0*
                // It takes 4 pixels (packed over 5 bytes) to re-align on byte boundary
            case 0x010a0046:
                pyPixelType = PixelType_Mono10p; //Mono10p
                break;
                // It takes 4 pixels (packed over 5 bytes) to re-align on byte boundary
            case 0x010a0052:
                pyPixelType = PixelType_BayerBG10p;
                break;
                // It takes 4 pixels (packed over 5 bytes) to re-align on byte boundary
            case 0x010a0054:
                pyPixelType = PixelType_BayerGB10p;
                break;
                // It takes 4 pixels (packed over 5 bytes) to re-align on byte boundary
            case 0x010a0056:
                pyPixelType = PixelType_BayerGR10p;
                break;
                // It takes 4 pixels (packed over 5 bytes) to re-align on byte boundary
            case 0x010a0058:
                pyPixelType = PixelType_BayerRG10p;
                break;
                //name=Mono12; id=0x01100005; realign=1; padding_bits=4*
                //12-bit pixel padded to 16 bits
            case 0x01100005:
                pyPixelType = PixelType_Mono12; //Mono12
                break;
                // name=Mono12p; id=0x010c0047; realign=2; padding_bits=0
                // It takes 2 pixels (packed over 3 bytes) to re-align on byte boundary
            case 0x010c0047:
                pyPixelType = PixelType_Mono12p; //Mono12p
                break;
                // name=Mono16; id=0x01100007; realign=1; padding_bits=0
                // 16-bit pixel in two bytes
            case 0x01100007:
                pyPixelType = PixelType_Mono16; //Mono16
                break;
                // name=BayerGR8; id=0x01080008; realign=1; padding_bits=0
                // 8-bit pixel in one byte
            case 0x01080008:
                pyPixelType = PixelType_BayerGR8; //BayerGR8
                break;
                // name=BayerGR10; id=0x0110000C; realign=1; padding_bits=6
                // 10-bit pixel padded to 16 bits
            case 0x0110000C:
                pyPixelType = PixelType_BayerGR10; //BayerGR10
                break;
                // name=BayerGR12; id=0x01100010; realign=1; padding_bits=4
                // 12-bit pixel padded to 16 bits
            case 0x01100010:
                pyPixelType = PixelType_BayerGR12; //BayerGR12
                break;
                // name=BayerGR12p; id=0x010C0057; realign=2; padding_bits=0
                // It takes 2 pixels (packed over 3 bytes) to re-align on byte boundary
            case 0x010C0057:
                pyPixelType = PixelType_BayerGR12p; //BayerGR12p
                break;
                // name=BayerGR16; id=0x0110002E; realign=1; padding_bits=0
                // 16-bit pixel in two bytes
            case 0x0110002E:
                pyPixelType = PixelType_BayerGR16; //BayerGR16
                break;
                // name=BayerRG8; id=0x01080009; realign=1; padding_bits=0
                // 8-bit pixel in one byte
            case 0x01080009:
                pyPixelType = PixelType_BayerRG8; //BayerRG8
                break;
                // name=BayerRG10; id=0x0110000D; realign=1; padding_bits=6
                // 10-bit pixel padded to 16 bits
            case 0x0110000D:
                pyPixelType = PixelType_BayerRG10; //BayerRG10
                break;
                // name=BayerRG12; id=0x01100011; realign=1; padding_bits=4
                // 12-bit pixel padded to 16 bits
            case 0x01100011:
                pyPixelType = PixelType_BayerRG12; //BayerRG12
                break;
                // name=BayerRG12p; id=0x010C0059; realign=2; padding_bits=0
                // It takes 2 pixels (packed over 3 bytes) to re-align on byte boundary
            case 0x010C0059:
                pyPixelType = PixelType_BayerRG12p; //BayerRG12p
                break;
                // name=BayerRG16; id=0x0110002F; realign=1; padding_bits=0
                // 16-bit pixel in two bytes
            case 0x0110002F:
                pyPixelType = PixelType_BayerRG16; //BayerRG16
                break;
                // name=BayerGB8; id=0x0108000A; realign=1; padding_bits=0
                // 8-bit pixel in one byte
            case 0x0108000A:
                pyPixelType = PixelType_BayerGB8; //BayerGB8
                break;
                // name=BayerGB10; id=0x0110000E; realign=1; padding_bits=6
                // 10-bit pixel padded to 16 bits
            case 0x0110000E:
                pyPixelType = PixelType_BayerGB10; //BayerGB10
                break;
                // name=BayerGB12; id=0x01100012; realign=1; padding_bits=4
                // 12-bit pixel padded to 16 bits
            case 0x01100012:
                pyPixelType = PixelType_BayerGB12; //BayerGB12
                break;
                // name=BayerGB12p; id=0x010C0055; realign=2; padding_bits=0
                // It takes 2 pixels (packed over 3 bytes) to re-align on byte boundary
            case 0x010C0055:
                pyPixelType = PixelType_BayerGB12p; //BayerGB12p
                break;
                // name=BayerGB16; id=0x01100030; realign=1; padding_bits=0
                // 16-bit pixel in two bytes
            case 0x01100030:
                pyPixelType = PixelType_BayerGB16; //BayerGB16
                break;
                // name=BayerBG8; id=0x0108000B; realign=1; padding_bits=0
                // 8-bit pixel in one byte
            case 0x0108000B:
                pyPixelType = PixelType_BayerBG8; //BayerBG8
                break;
                // name=BayerBG10; id=0x0110000F; realign=1; padding_bits=6
                // 10-bit pixel padded to 16 bits
            case 0x0110000F:
                pyPixelType = PixelType_BayerBG10; //BayerBG10
                break;
                // name=BayerBG12; id=0x01100013; realign=1; padding_bits=4
                // 12-bit pixel padded to 16 bits
            case 0x01100013:
                pyPixelType = PixelType_BayerBG12; //BayerBG12
                break;
                // name=BayerBG12p; id=0x010C0053; realign=2; padding_bits=0
                // It takes 2 pixels (packed over 3 bytes) to re-align on byte boundary
            case 0x010C0053:
                pyPixelType = PixelType_BayerBG12p; //BayerBG12p
                break;
                // name=BayerBG16; id=0x01100031; realign=1; padding_bits=0
                // 16-bit pixel in two bytes
            case 0x01100031:
                pyPixelType = PixelType_BayerBG16; //BayerBG16
                break;
                // name=BGR8; id=0x02180015; realign=1; padding_bits=0
                // 8-bit color component in one byte
            case 0x02180015:
                pyPixelType = PixelType_BGR8packed; //BGR8
                break;
                // name=BGR10; id=0x02300019; realign=1; padding_bits=6
                // 10-bit color component padded to 16 bits
            case 0x02300019:
                pyPixelType = PixelType_BGR10packed; //BGR10
                break;
                // name=BGR12; id=0x0230001B; realign=1; padding_bits=4
                // 12-bit color component padded to 16 bits
            case 0x0230001B:
                pyPixelType = PixelType_BGR12packed; //BGR12
                break;
                // name=BGRa8; id=0x02200017; realign=1; padding_bits=0
                // 8-bit color component in one byte
            case 0x02200017:
                pyPixelType = PixelType_BGRA8packed; //BGRa8
                break;
                // name=RGB8; id=0x02180014;
            case 0x02180014:
                pyPixelType = PixelType_RGB8packed; //RGB8
                break;
                // name=RGB10; id=0x02300018;
            case 0x02300018:
                pyPixelType = PixelType_RGB10packed; //RGB10
                break;
                // name=RGB12; id=0x0230001A;
            case 0x0230001A:
                pyPixelType = PixelType_RGB12packed; //RGB12
                break;
                // name=RGBa8; id=0x02200016;
            case 0x02200016:
                pyPixelType = PixelType_RGBA8packed; //RGBa8
                break;
                // name=RGB16; id=0x02300033;
            case 0x02300033:
                pyPixelType = PixelType_RGB16packed; //RGB16
                break;
                // name=YCbCr411_8; id=0x020C005A;
            case 0x020C005A:
                pyPixelType = PixelType_YUV411packed; //YCbCr411_8
                break;
                // name=YCbCr8; id=0x0218005B;
            case 0x0218005B:
                pyPixelType = PixelType_YUV444packed; //YCbCr8
                break;
                // name=YCbCr422_8; id=0x0210003B; realign=1; padding_bits=0
                // 8-bit color component in one byte, YCbYCr component sequence
            case 0x0210003B:
                pyPixelType = PixelType_YUV422_YUYV_Packed; //YCbCr422_8
                break;
                // name=RGB8_Planar; id=0x02180021;
            case 0x02180021:
                pyPixelType = PixelType_RGB8planar; //RGB8_Planar
                break;
                // name=RGB10_Planar; id=0x02300022;
            case 0x02300022:
                pyPixelType = PixelType_RGB10planar; //RGB10_Planar
                break;
                // name=RGB12_Planar; id=0x02300023;
            case 0x02300023:
                pyPixelType = PixelType_RGB12planar; //RGB12_Planar
                break;
                // name=RGB16_Planar; id=0x02300024;
            case 0x02300024:
                pyPixelType = PixelType_RGB16planar; //RGB16_Planar
                break;
            default:
                break;
        }

        return pyPixelType;
    }

} // namespace

#endif
