//-----------------------------------------------------------------------------
// Copyright (c) 2018-2021 Basler AG
// Internal Header. Do NOT include in public headers.
//-----------------------------------------------------------------------------

#ifndef PYLONPRIVATE_STRINGS_H__
#define PYLONPRIVATE_STRINGS_H__

#include <string>

//////////////////////////////////////////////
//ATTENTION: THIS CODE IS INLINE ON PURPOSE //
//////////////////////////////////////////////

namespace
{
// ============================================================
//For obfuscated strings
// ============================================================
    inline std::string MakeAString( const uint8_t* dataA, const uint8_t* dataB )
    {
        std::string result;
        char c = 0;
        do
        {
            c = (*dataA ^ *dataB) - 17;
            result += c;
            ++dataA;
            ++dataB;
        } while (c);

        return result;
    }

    // ============================================================
    //For obfuscated strings
    // ============================================================
    inline void MakeAString( const uint8_t* dataA, const uint8_t* dataB, char* dataC )
    {
        char c = 0;
        do
        {
            c = (*dataA ^ *dataB) - 17;
            *dataC = c;
            ++dataC;
            ++dataA;
            ++dataB;
        } while (c);
    }


    inline std::string GetBslUSBSpeedModeString()
    {
        std::string result;
        uint8_t data[] = { 0xd1, 0x6c, 0xe7, 0xa2, 0xd1, 0x57, 0x3b, 0xe6, 0x41, 0xf6, 0x59, 0xdd, 0x1a, 0x05, 0x26, 0x6a, };
        uint8_t mask[] = { 0x82, 0xe8, 0x9a, 0xc4, 0xb5, 0x04, 0x5f, 0x67, 0x37, 0x80, 0x2c, 0x83, 0x9a, 0x70, 0x50, 0x7b, };

        result = MakeAString( data, mask );
        return result;
    }


    inline std::string GetServiceBoardIdSelectorString()
    {
        std::string result;
        uint8_t data[] = { 0xe6, 0x9e, 0x19, 0x43, 0xcf, 0x70, 0x29, 0x34, 0xb7, 0xf2, 0xaf, 0xf6, 0xc0, 0x05, 0x34, 0x0d, 0xbb, 0x9b, 0x64, 0x4a, 0xcb, 0x9a, 0x8d, };
        uint8_t mask[] = { 0x82, 0xe8, 0x9a, 0xc4, 0xb5, 0x04, 0x5f, 0x67, 0x37, 0x80, 0x2c, 0x83, 0x9a, 0x70, 0x50, 0x7b, 0xc6, 0xed, 0x10, 0xcf, 0x4b, 0x19, 0x9c, };

        result = MakeAString( data, mask );
        return result;
    }


    inline std::string GetFakeVendorString()
    {
        std::string result;
        uint8_t data[] = { 0xd5, 0x9a, 0xe6, 0xb2, 0xd2, 0x72, 0x20, 0x12, 0xb7, 0x03, 0x3d, };
        uint8_t mask[] = { 0x82, 0xe8, 0x9a, 0xc4, 0xb5, 0x04, 0x5f, 0x67, 0x37, 0x80, 0x2c, };

        result = MakeAString( data, mask );
        return result;
    }


    inline std::string GetFakeModelNameString()
    {
        std::string result;
        uint8_t data[] = { 0xd5, 0x9a, 0xe6, 0xb2, 0xeb, 0x84, 0x2a, 0x11, 0x4a, 0xdf, 0x5e, 0xfd, 0xec, 0x61, };
        uint8_t mask[] = { 0x82, 0xe8, 0x9a, 0xc4, 0xb5, 0x04, 0x5f, 0x67, 0x37, 0x80, 0x2c, 0x83, 0x9a, 0x70, };

        result = MakeAString( data, mask );
        return result;
    }


    inline std::string Get123456String()
    {
        std::string result;
        uint8_t data[] = { 0xc0, 0xab, 0xde, 0x81, 0xf3, 0x43, 0x4e, };
        uint8_t mask[] = { 0x82, 0xe8, 0x9a, 0xc4, 0xb5, 0x04, 0x5f, };

        result = MakeAString( data, mask );
        return result;
    }


    inline std::string GetFakeCamString()
    {
        std::string result;
        uint8_t data[] = { 0xd5, 0x9a, 0xe6, 0xb2, 0xe1, 0x76, 0x21, 0x76, };
        uint8_t mask[] = { 0x82, 0xe8, 0x9a, 0xc4, 0xb5, 0x04, 0x5f, 0x67, };

        result = MakeAString( data, mask );
        return result;
    }

}

#endif // PYLONPRIVATE_STRINGS_H__