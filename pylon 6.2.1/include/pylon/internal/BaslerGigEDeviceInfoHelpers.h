#pragma once

namespace Pylon
{
    // this is an enum to so we don't have to parse the non portable bitfield using the GEV_IP_CONFIG from the GEV headers
    enum PortableIpConfig
    {
        IpConfig_Invalid = 0,
        IpConfig_PersistentIP = 256, // values are used as flags and must be OR'able
        IpConfig_DHCP = 512,
        IpConfig_LLA = 1024
    };

    ///This namespace contains keys for accessing the properties of pylon info objects
    namespace Key
    {
        ///Identifies the persistent IP configuration options.
        const char* const PortableIpConfigOptionsKey = "_PortableIpConfigOptions";
        ///Identifies the current IP configuration of the device.
        const char* const PortableIpConfigCurrentKey = "_PortableIpConfigCurrent";
    }

}
