#ifndef PYLON_DEVICE_SECURITY_H_INCLUDED__
#define PYLON_DEVICE_SECURITY_H_INCLUDED__

#if _MSC_VER > 1000
#pragma once
#endif

#include <stdint.h>
#include <pylon/Platform.h>
#include <pylon/PylonLinkage.h>

#ifndef PYLON_NO_AUTO_IMPLIB
#   pragma comment(lib, PYLON_LIB_NAME( "ImplHelpers" ))
#endif

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */


namespace Pylon
{
    namespace Key
    {
        //string to unlock the device in format: "Role=5;Key=00112233445566778899aabbcceeff"
        const char* const UnlockString = "_BornFree";
    }

#if defined(PYLON_WIN_BUILD)
    // return true if the arch is big endian
    bool IsHostArchBigEndian();
    // get the role/key from the device info
    size_t GetKeyFromDeviceInfo( const Pylon::CDeviceInfo& di, int32_t* pRole, uint8_t* pKey, size_t cbKey );
    // unlock a port
    bool UnlockPort( GENAPI_NAMESPACE::IPort* pPort, bool doByteSwap, int32_t role, const uint8_t* pKey, size_t cbKey );
    // unlock a device
    bool UnlockDevice( Pylon::IPylonDevice* pDevice, int32_t role, const uint8_t* pKey, size_t cbKey );
    // unlock a device use info from deviceinfo
    bool UnlockDeviceFromDeviceInfo( Pylon::IPylonDevice* pDevice );
#endif

} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif

