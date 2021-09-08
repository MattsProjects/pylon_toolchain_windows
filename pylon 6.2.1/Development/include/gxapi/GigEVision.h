/**
 * \file
 * \brief GigE Vision public structure definitions.
 *
 * Definition of the
 * - GigE Vision (GEV) Bootstrap Register layout,
 * - the GigE Vision Control Protocol (GVCP) message structures,
 * - the GigE Vision Streaming Protocol (GVSP) message structures,
 * - predefined GigE Vision status code values,
 * - further GEV constants, macros and default parameters
 *
 * \Copyright (c) 2005-2021 Basler AG
 *
 * \author Volker Moebius
 *
 */

#ifdef _MSC_VER
#    pragma once
#endif

#ifndef GIGEVISION_H__INCLUDED
#define GIGEVISION_H__INCLUDED



#define GIGEVISION_LITTLE_ENDIAN 1234
#define GIGEVISION_BIG_ENDIAN 4321


#if defined(__GNUC__)
#    if __BYTE_ORDER == __LITTLE_ENDIAN
#        define GIGEVISION_ENDIANESS GIGEVISION_LITTLE_ENDIAN
#    elif __BYTE_ORDER == __BIG_ENDIAN
#        define GIGEVISION_ENDIANESS GIGEVISION_BIG_ENDIAN
#    else
#        error unknown endianess
#    endif
#elif defined( _MSC_VER )
#    if defined( _M_IX86 ) || defined( _M_AMD64 )
#        define GIGEVISION_ENDIANESS GIGEVISION_LITTLE_ENDIAN
#    else
#        error unknown architecture
#    endif
#else
#    error unknown compiler
#endif



#ifndef GIGEVISION_ENDIANESS
#    error Undefined endianess
#endif


#ifdef __GNUC__
#    define GEV_PACKED    __attribute__((packed))
#    define GEV_DEPRECATED __attribute__ ((deprecated))
#else
#    define GEV_PACKED
#    define GEV_DEPRECATED __declspec(deprecated)
#endif


#ifdef _MSC_VER
#    pragma warning( push )
#    pragma warning( disable : 4200 ) /* nonstandard extension used : zero-sized array in struct/union */
#    pragma warning( disable : 4201 ) /* nonstandard extension used : nameless struct/union */
#    pragma warning( disable : 4214 ) /* nonstandard extension used : bit field types other than int */
#endif



#ifdef __cplusplus
extern "C" {
#endif



#pragma pack(push,1)


    typedef int BOOL;


    typedef union _GEV_SPECVERSION
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint16_t Minor;
            uint16_t Major;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN

            uint16_t Major;
            uint16_t Minor;

#    else

#        error unknown endianess


#    endif
        } GEV_PACKED;

        uint32_t uint32[1];
    }
    GEV_PACKED GEV_SPECVERSION;



    typedef union _GEV_DEVICE_MODE
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint32_t CharacterSetIndex : 8;
            uint32_t Reserved : 23;
            uint32_t Endianess : 1;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN

        /**
         * Endianess.
         * Represents the endianess of bootstrap registers.
         * - 0 : Little-endian device
         * - 1 : Big-endian device
         */
            uint32_t Endianess : 1;

            /**
             * Reserved.
             * Bit [1..23]
             * Always 0.
             */
            uint32_t Reserved : 23;

            /**
             * Character Set Index.
             * Bit [24..31]
             * This field represents the character set. It must take one of
             * the following values:
             * - 0 : reserved
             * - 1 : UTF-8
             * - other : reserved
             *
             * \see GEV_CHARACTER_SET_INDEX
             */
            uint32_t CharacterSetIndex : 8;

#    else

#        error unknown endianess

#    endif
        } GEV_PACKED;

        uint32_t uint32;
    }
    GEV_PACKED GEV_DEVICE_MODE;



    typedef enum _GEV_CHARACTER_SET_INDEX
    {
        GV_CSI_UTF8 = 1
    }
    GEV_CHARACTER_SET_INDEX;



    typedef struct _GEV_IN_ADDR
    {
        uint32_t U32;
    }
    GEV_PACKED GEV_IN_ADDR;



    typedef struct _GEV_IN6_ADDR
    {
        uint8_t Reserved[16];
    }
    GEV_PACKED GEV_IN6_ADDR;



/**
 * GigE Vision IP Address.
 * IP address register layout used by GigE Vision
 * Bootstrap Registers.
 */
    typedef union _GEV_IP_ADDRESS
    {
        struct
        {
            uint8_t Reserved[sizeof( GEV_IN6_ADDR ) - sizeof( GEV_IN_ADDR )];
            GEV_IN_ADDR Address;
        }
        GEV_PACKED V4;

        struct
        {
            GEV_IN6_ADDR Address;
        }
        GEV_PACKED V6;
    }
    GEV_PACKED GEV_IP_ADDRESS;


    typedef struct _GV_DEVICE_DESCRIPTION
    {
        char ManufacturerName[32];
        char ModelName[32];
        char DeviceVersion[32];
        char ManufacturerInformation[48];
        char SerialNumber[16];
        char UserDefinedName[16];
    }
    GEV_PACKED GV_DEVICE_DESCRIPTION;



    typedef union _GEV_MAC_ADDRESS
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint16_t High;
            uint16_t Reserved;
            uint32_t Low;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN

            uint16_t Reserved;
            uint16_t High;
            uint32_t Low;

#    else

#        error unknown endianess

#    endif
        } GEV_PACKED;

        uint32_t uint32[2];
    }
    GEV_PACKED GEV_MAC_ADDRESS;



/**
 * IP Configuration.
 */
    typedef union _GEV_IP_CONFIG
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint32_t PersistentIP : 1;
            uint32_t DHCP : 1;
            uint32_t LLA : 1;
            uint32_t Reserved : 29;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN

        /**
         * Reserved.
         */
            uint32_t Reserved : 29;

            /**
             * Link-local address.
             */
            uint32_t LLA : 1;

            /**
             * DHCP is activated.
             */
            uint32_t DHCP : 1;

            /**
             * Persistent IP is activated.
             */
            uint32_t PersistentIP : 1;

#    endif
        } GEV_PACKED;

        uint32_t uint32;
    }
    GEV_PACKED GEV_IP_CONFIG;



    typedef struct _GEV_DISCOVERY_INFO
    {
        GEV_SPECVERSION SpecVersion;
        GEV_DEVICE_MODE DeviceMode;
        GEV_MAC_ADDRESS DeviceMacAddress;
        GEV_IP_CONFIG IPConfigOptions;
        GEV_IP_CONFIG IPConfigCurrent;
        GEV_IP_ADDRESS CurrentIP;
        GEV_IP_ADDRESS CurrentSubnetMask;
        GEV_IP_ADDRESS DefaultGateway;
        GV_DEVICE_DESCRIPTION Description;
    }
    GEV_PACKED GEV_DISCOVERY_INFO;


    GEV_DEPRECATED
        typedef GEV_DISCOVERY_INFO GV_DISCOVERY_INFO;



        /**
         * GigE Vision Control Access Priviledges.
         * Written to the CCP Bootstrap Register to gain control of the device.
         */
    typedef enum _GEV_CONTROL_ACCESS_PRIVILEDGES
    {
        GEV_EXCLUSIVE_CONTROL_ACCESS = 1,
        GEV_CONTROL_ACCESS = 2
    }
    GEV_CONTROL_ACCESS_PRIVILEDGES;



    typedef struct _GV_NETWORK_INTERFACE_REGISTERS
    {
        struct
        {
            uint16_t Reserved;
            uint16_t High;
            uint32_t Low;
        }
        MacAddress;
        uint32_t SupportedIpConfig;
        uint32_t CurrentIpConfig;
        GEV_IP_ADDRESS CurrentIpAddress;
        GEV_IP_ADDRESS CurrentSubnetMask;
        GEV_IP_ADDRESS CurrentDefaultGateway;
        GEV_IP_ADDRESS PersistentIpAddress;
        GEV_IP_ADDRESS PersistentSubnetMask;
        GEV_IP_ADDRESS PersistentDefaultGateway;
        uint8_t  Reserved[0x0100 - 0x00f0];
    }
    GV_NETWORK_INTERFACE_REGISTERS;



    typedef union _GVCP_CAPABILITIES
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

        /**
         * Concatenation.
         * Bit [31].
         * Multiple operations in a single message are supported.
         */
            uint32_t Concatenation : 1;

            /**
             * Write Mem.
             * Bit [30].
             * WRITEMEM_CMD and WRITEMEM_ACK are supported.
             */
            uint32_t WriteMem : 1;

            /**
             * Packet Resend.
             * Bit [29].
             * PACKETRESEND_CMD and PACKETRESEND_ACK are supported.
             */
            uint32_t PacketResend : 1;

            /**
             * Event.
             * Bit [28]
             * EVENT_CMD and EVENT_ACK are supported.
             */
            uint32_t Event : 1;

            /**
             * Event Data.
             * Bit [27].
             * EVENTDATA_CMD and EVENTDATA_ACK are supported.
             */
            uint32_t EventData : 1;

            /**
            * Pending Acknowledge
            * Bit [26].
            * PENDING_ACK is supported.
            */
            uint32_t PendingAck : 1;

            /**
            * Action
            * Bit[25].
            * ACTION_CMD and ACTION_ACK are supported.
            */
            uint32_t Action : 1;

            /**
             * Reserved.
             * Bit [15..24]
             * Always 0.
             */
            uint32_t ReservedB : 10;

            /**
            * Scheduled Action Command
            * Bit [14].
            * Scheduled Action Commands are supported.
            */
            uint32_t ScheduledActionCmd : 1;

            /**
            * Extended Status Code 2.0
            * Bit [13]
            * Generation of extended status codes introduced in specification 2.0
            */
            uint32_t ExtendedStatusCode_2_0 : 1;

            /**
            * IEEE1588 PTP support
            * Bit [12]
            * IEEE 1588 PTP is supported.
            */
            uint32_t Ieee1588Ptp : 1;

            /**
            * Unconditional Action
            * Bit [11]
            * Unconditional ACTION_CMD is supported.
            */
            uint32_t UnconditionalAction : 1;

            /**
            * Primary Application Switchover
            * Bit [10]
            * Primary application switchover capability is supported.
            */
            uint32_t PrimaryAppSwitchover : 1;

            /**
            * Extended Status Code 1.1
            * Bit [9]
            * Generation of extended status codes introduced in specification 1.1
            */
            uint32_t ExtendedStatusCode_1_1 : 1;

            /**
            * Writable Discovery Acknowledge Delay
            * Bit [8]
            * Writable Discovery ACK Delay register is supported.
            */
            uint32_t WritableDiscoveryAckDelay : 1;

            /**
            * Discovery Acknowledge Delay
            * Bit [7]
            * Discovery ACK Delay register is supported.
            */
            uint32_t DiscoveryAckDelay : 1;

            /**
             * TestData.
             * Bit [6].
             * Test packet is filled with data from the LFSR generator.
             */
            uint32_t TestData : 1;

            /**
                * ManifestTable.
                * Bit [5].
                * Manifest Table is supported.
                */
            uint32_t ManifestTable : 1;

            /**
                * ReservedB.
                * Bit [2..4]
                * Always 0.
                */
            uint32_t ReservedA : 3;

            /**
             * SerialNumber.
             * Bit [1].
             * Serial number register is supported.
             */
            uint32_t SerialNumber : 1;

            /**
             * User Defined Name.
             * Bit [0].
             * User-defined name register is supported.
             */
            uint32_t UserDefinedName : 1;

#    else

            uint32_t UserDefinedName : 1;
            uint32_t SerialNumber : 1;
            uint32_t HeartbeatDisable : 1;
            uint32_t LinkSpeed : 1;
            uint32_t CcpApplicationPort : 1;
            uint32_t ManifestTable : 1;
            uint32_t TestData : 1;
            uint32_t DiscoveryAckDelay : 1;
            uint32_t WritableDiscoveryAckDelay : 1;
            uint32_t ExtendedStatusCode_1_1 : 1;
            uint32_t PrimaryAppSwitchover : 1;
            uint32_t UnconditionalAction : 1;
            uint32_t Ieee1588Ptp : 1;
            uint32_t ExtendedStatusCode_2_0 : 1;
            uint32_t ScheduledActionCmd : 1;
            uint32_t ReservedB : 10;
            uint32_t Action : 1;
            uint32_t PendingAck : 1;
            uint32_t EventData : 1;
            uint32_t Event : 1;
            uint32_t PacketResend : 1;
            uint32_t WriteMem : 1;
            uint32_t Concatenation : 1;

#    endif
        };

        uint32_t uint32;
    }
    GVCP_CAPABILITIES;

    typedef union _GVSP_CAPABILITIES
    {
        struct
        {
            uint32_t Reserved : 30;
            uint32_t LegacyBlockId : 1;
            uint32_t ScspRegistersSupport : 1;
        };
        uint32_t uint32;
    }
    GEV_PACKED GVSP_CAPABILITIES;

    typedef union _GVSP_CONFIGURATION
    {
        struct
        {
            uint32_t Reserved : 30;
            uint32_t BlockId64BitEnable : 1;
        };
        uint32_t uint32;
    }
    GEV_PACKED GVSP_CONFIGURATION;

    typedef union _GEV_STREAM_CHANNEL_PACKET_SIZE_REGISTER
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN
            uint32_t Size : 16;
            uint32_t Reserved : 13;
            uint32_t PixelEndianess : 1;
            uint32_t DoNotFragment : 1;
            uint32_t FireTestPacket : 1;
#    else
            uint32_t FireTestPacket : 1;
            uint32_t DoNotFragment : 1;
            uint32_t PixelEndianess : 1;
            uint32_t Reserved : 13;
            uint32_t Size : 16;
#    endif
        };

        uint32_t uint32;
    }
    GEV_PACKED GEV_STREAM_CHANNEL_PACKET_SIZE_REGISTER;



    typedef union _GEV_STREAM_CHANNEL_PORT_REGISTER
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint32_t PortNumber : 16;
            uint32_t InterfaceIndex : 4;
            uint32_t Reserved : 12;

#    else

        /**
         * Reserved.
         * Must be held to zero.
         * Bit [0..11].
         */
            uint32_t Reserved : 12;

            /**
             * Network Interface Index.
             * Index of network interface to use (from 0 to 3). Specific streams
             * might be hard-coded to a specific network interfaces. Therefore
             * this field might not be programmable on certain devices. It is
             * read-only for this case.
             * Bit [12..15].
             */
            uint32_t InterfaceIndex : 4;

            /**
             * Port.
             * Destination Port Number. Setting this value to 0 closes the stream channel.
             * Bit [16..31].
             */
            uint32_t PortNumber : 16;

#    endif
        };

        uint32_t uint32;
    }
    GEV_PACKED GEV_STREAM_CHANNEL_PORT_REGISTER;



    typedef struct _GEV_STREAMING_CHANNEL_REGISTERS
    {
        GEV_STREAM_CHANNEL_PORT_REGISTER Port;
        GEV_STREAM_CHANNEL_PACKET_SIZE_REGISTER PacketSize;
        uint32_t PacketDelay;
        GEV_IP_ADDRESS Ip;
        uint8_t Reserved[0x0040 - sizeof( GEV_IP_ADDRESS ) - 3 * sizeof( uint32_t )];
    }
    GEV_PACKED GEV_STREAMING_CHANNEL_REGISTERS;



/**
 * Timestamp.
 */
    typedef struct _GEV_TIMESTAMP
    {
        /**
         * High 32 bits.
         */
        uint32_t High;

        /**
         * Low 32 bits.
         */
        uint32_t Low;
    }
    GEV_PACKED GEV_TIMESTAMP;

/**
* Dicovery Delay
*/
    typedef union _GEV_DISCOVERY_ACK_DELAY
    {
        struct
        {
            uint32_t Delay : 16;
            uint32_t Reserved : 16;
        };
        uint32_t uint32;
    }
    GEV_PACKED GEV_DISCOVERY_ACK_DELAY;

/**
* GVCP Configuration
*/
    typedef union _GVCP_CONFIGRATION
    {
        struct
        {
            uint32_t ReservedA : 12;
            uint32_t Ieee1588Ptp : 1;
            uint32_t ExtStatusCode_2_0 : 1;
            uint32_t ReservedB : 14;
            uint32_t UnconditionalAction : 1;
            uint32_t ExtStatusCode_1_1 : 1;
            uint32_t PendingAck : 1;
            uint32_t HeartbeatDisable : 1;
        };
        uint32_t uint32;
    }
    GEV_PACKED GVCP_CONFIGURATION;
/**
* Action Group Key Registers
*/
    typedef  struct _GVCP_ACTION_GROUP
    {
        uint32_t ActionGroupKey;
        uint32_t ActionGroupMask;
        uint8_t  Reserved[0x10 - 0x8];
    } GEV_PACKED GVCP_ACTION_GROUP;

    typedef struct _GEV_BOOTSTRAP_REGISTERS
    {
        GEV_DISCOVERY_INFO di;
        uint8_t Reserved0[0x0200 - sizeof( GEV_DISCOVERY_INFO )];
        char Url0[512];
        char Url1[512];
        uint32_t NumberOfNetworkInterfaces;
        uint8_t  Reserved1[0x0640 - 0x0604];
        GEV_IP_ADDRESS PersistentIp;
        GEV_IP_ADDRESS PersistentSubnetMask;
        GEV_IP_ADDRESS PersistentDefaultGateway;
        uint8_t  Reserved2[0x0680 - 0x0670];
        GV_NETWORK_INTERFACE_REGISTERS NetworkInterfaces[3];
        uint8_t  Reserved3[0x0900 - 0x0800];
        uint32_t NumberOfMessagingChannels;
        uint32_t NumberOfStreamingChannels;
        uint32_t NumberOfActionSignals;                    // {n | 0 <= n <=128}
        uint32_t ActionDeviceKey;
        uint32_t NumberActiveLinks;
        uint8_t  Reserved4[0x0930 - 0x0914];
        GVSP_CAPABILITIES GvspCapabilities;
        GVCP_CAPABILITIES GvcpCapabilities;
        uint32_t HeartbeatTimeout_ms;
        GEV_TIMESTAMP TimestampTickFrequency;
        uint32_t TimestampControl;
        GEV_TIMESTAMP TimestampValue;
        GEV_DISCOVERY_ACK_DELAY DiscoverAckDelay;
        GVCP_CONFIGURATION GvcpConfiguration;
        uint32_t PendingTimeout;
        uint32_t ControlSwitchoverKey;
        GVSP_CONFIGURATION GvspConfiguration;
        uint8_t  Reserved5[0x0a00 - 0x0964];
        uint32_t CCP;
        uint8_t  Reserved6[0x0b00 - 0x0a04];
        struct
        {
            uint32_t Port;
            GEV_IP_ADDRESS Ip;
            uint32_t TransmissionTimeout;
            uint32_t RetryCount;
        }
        MessageChannel;
        uint8_t Reserved7[0x0d00 - 0x0b1c];
        GEV_STREAMING_CHANNEL_REGISTERS StreamingChannels[1];
        uint8_t Reserved8[0x9800 - 0xd00 - sizeof( GEV_STREAMING_CHANNEL_REGISTERS )];
        GVCP_ACTION_GROUP GvcpActionGroup[128];
    }
    GEV_BOOTSTRAP_REGISTERS;


    GEV_DEPRECATED
        typedef GEV_BOOTSTRAP_REGISTERS GV_BOOTSTRAP_REGISTERS;







        /**
         * Default Heartbeat Timeout [ms].
         * The default GVCP Heartbeat Timeout in milliseconds.
         */
#define GEV_DEFAULT_HEARTBEATTIMEOUT_MS 3000



/**
 * Minimum Heartbeat Timeout [ms].
 * The minimal GVCP Heartbeat Timeout in milliseconds.
 */
#define GEV_MINIMUM_HEARTBEATTIMEOUT_MS 500



    typedef enum _GEV_COMMAND_FLAGS
    {
        GEV_COMMAND_FLAG_ANSWER = 1 << 0,
    }
    GEV_COMMAND_FLAGS;


#define FORTY_TWO 0x42


    typedef enum _GEV_MESSAGE_TAGS
    {
        TAG_DISCOVERY_CMD = 0x02,
        TAG_DISCOVERY_ACK = 0x03,

        TAG_FORCEIP_CMD = 0x04,
        TAG_FORCEIP_ACK = 0x05,

        TAG_PACKETRESEND_CMD = 0x40,

        TAG_READREG_CMD = 0x80,
        TAG_READREG_ACK = 0x81,

        TAG_WRITEREG_CMD = 0x82,
        TAG_WRITEREG_ACK = 0x83,

        TAG_READMEM_CMD = 0x84,
        TAG_READMEM_ACK = 0x85,

        TAG_WRITEMEM_CMD = 0x86,
        TAG_WRITEMEM_ACK = 0x87,

        TAG_EVENT_CMD = 0xc0,
        TAG_EVENT_ACK = 0xc1,

        TAG_EVENTDATA_CMD = 0xc2,
        TAG_EVENTDATA_ACK = 0xc3,

        TAG_ACTION_CMD = 0x100,
        TAG_ACTION_ACK = 0x101,

        TAG_SETIPCONFIG_CMD = 0x8004,
        TAG_SETIPCONFIG_ACK = 0x8005,


        /**
         * Shutdown Request Tag.
         * This is a GX specific message extension.
         */
         TAG_SHUTDOWN_CMD = 0xfe,

         /**
          * Shutdown Response Tag
          * This is a GX specific message extension.
          */
          TAG_SHUTDOWN_ACK = 0xff
    }
    GEV_MESSAGE_TAGS;



    typedef struct _GVCP_REQUEST_HEADER
    {
        /**
         * Magic Tag.
         * Defined to be 0x42 always. Simple mean to validate the message.
         */
        uint8_t FortyTwo;

        uint8_t Flags;
        uint16_t Command;

        /**
         * Length.
         * Number of data bytes following the GVCP_REQUEST_HEADER.
         */
        uint16_t Length;

        uint16_t ReqId;
    }
    GEV_PACKED GVCP_REQUEST_HEADER;



/**
 * GigE Vision Status.
 * GEV status uses 16 bit.
 */
    typedef uint16_t GEV_STATUS;



    /**
     * GVCP Response Header.
     * Common header of all GVCP response messages.
     */
    typedef struct GVCP_RESPONSE_HEADER
    {
        GEV_STATUS Status;
        uint16_t Acknowledge;
        uint16_t Length;
        uint16_t AckId;
    }
    GEV_PACKED GVCP_RESPONSE_HEADER;



/**
 * Discovery Command Flags.
 * Request header flags specific to the discovery command.
 */
    typedef enum _GEV_DISCOVERY_COMMAND_FLAGS
    {
        /**
         * Broadcast Acknowledge.
         * Bit 3 - Allows broadcast of acknowledge.
         * \todo Make bitfield?
         */
        GEV_DISCOVERY_COMMAND_FLAG_BROADCAST_ACK = 1 << 4
    }
    GEV_DISCOVERY_COMMAND_FLAGS;



    typedef struct GV_DISCOVERY_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
    }
    GEV_PACKED GV_DISCOVERY_REQUEST;



    typedef struct GV_DISCOVERY_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
        GEV_DISCOVERY_INFO DiscoveryInfo;
    }
    GEV_PACKED GV_DISCOVERY_RESPONSE;



/**
 * FORCEIP Request Message.
 */
    typedef struct _GVCP_FORCEIP_REQUEST
    {
        GVCP_REQUEST_HEADER Header;

        /**
         * MAC Address.
         * MAC address of the device to access.
         */
        GEV_MAC_ADDRESS MacAddress;

        /**
         * Static IP.
         * Static IP address to force into the device.
         */
        GEV_IP_ADDRESS StaticIp;

        /**
         * Static Subnet Mask.
         * Subnet mask to use with the Static IP address.
         */
        GEV_IP_ADDRESS StaticSubnetMask;

        /**
         * Static Default Gateway.
         * Default gateway to use with the Static IP address.
         */
        GEV_IP_ADDRESS StaticDefaultGateway;
    }
    GEV_PACKED GVCP_FORCEIP_REQUEST;



/**
 * FORCEIP Response Message.
 * The FORCEIP_ACK is sent back by the device after the forced static IP
 * address has been assigned. The status field is used to signal any
 * problem.
 */
    typedef struct _GVCP_FORCEIP_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
    }
    GEV_PACKED GVCP_FORCEIP_RESPONSE;



/**
 * GigE Vision Register Address Type.
 */
    typedef uint32_t GEV_ADDRESS;



    typedef struct GVCP_READREG_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GEV_ADDRESS Addresses[1];
    }
    GEV_PACKED GVCP_READREG_REQUEST;



    typedef struct GVCP_READREG_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
        uint32_t Data[1];
    }
    GEV_PACKED GVCP_READREG_RESPONSE;



/**
 * READREG Maximum Number of Registers.
 * The maximum number of registers that can be read by a single READREG
 * command.
 */
#define GVCP_READREG_MAX_NR_REGS 135



    typedef    struct GVCP_WRITEREG_ITEM
    {
        GEV_ADDRESS Address;
        uint32_t Data;
    }
    GEV_PACKED GVCP_WRITEREG_ITEM;



    typedef struct GVCP_WRITEREG_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GVCP_WRITEREG_ITEM Items[1];
    }
    GEV_PACKED GVCP_WRITEREG_REQUEST;



    typedef struct _GVCP_WRITEREG_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
        uint16_t Reserved;
        uint16_t Index;
    }
    GEV_PACKED GVCP_WRITEREG_RESPONSE;



/**
 * WRITEREG Maximum Number of Registers.
 * The maximum number of registers that can be written by a single WRITEREG
 * command.
 */
#define GVCP_WRITEREG_MAX_NR_REGS 67



    typedef struct GVCP_READMEM_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GEV_ADDRESS Address;
        uint16_t Reserved;
        uint16_t Count;
    }
    GEV_PACKED GVCP_READMEM_REQUEST;



    typedef struct GVCP_READMEM_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
        GEV_ADDRESS Address;
        uint8_t Data[1];
    }
    GEV_PACKED GVCP_READMEM_RESPONSE;



/**
 * READMEM Maximum Number Bytes.
 * The maximum number of bytes that can be read by a single READMEM
 * command.
 */
#define GVCP_READMEM_MAX_NR_BYTES 536



    typedef struct GVCP_WRITEMEM_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GEV_ADDRESS Address;
        uint8_t Data[1];
    }
    GEV_PACKED GVCP_WRITEMEM_REQUEST;



    typedef struct GVCP_WRITEMEM_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
        uint16_t Reserved;
        uint16_t Index;
    }
    GEV_PACKED GVCP_WRITEMEM_RESPONSE;



/**
 * WRITEMEM Maximum Number Bytes.
 * The maximum number of bytes that can be written by a single WRITEMEM
 * command.
 */
#define GVCP_WRITEMEM_MAX_NR_BYTES 536

// ==============================================================================
    typedef struct _GVCP_ACTION_CMD
    {
        GVCP_REQUEST_HEADER Header;
        uint32_t DeviceKey;
        uint32_t GroupKey;
        uint32_t GroupMask;
        int64_t ActionTime;
    }
    GEV_PACKED GVCP_ACTION_CMD;
    typedef struct _GVCP_ACTION_ACK
    {
        GVCP_RESPONSE_HEADER Header;
    }
    GEV_PACKED GVCP_ACTION_ACK;

    typedef enum _GEV_ACTION_COMMAND_FLAGS
    {
        GEV_ACTION_COMMAND_SCHEDULED_FLAG = 0x1 << 7     // bit 0
    }
    GEV_ACTION_COMMAND_FLAGS;
// ==============================================================================

    typedef    union _GVCP_EVENT_ITEM
    {
        struct
        {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint16_t Identifier;
            uint16_t Reserved;
            uint16_t BlockId;
            uint16_t StreamChannelIndex;
            GEV_TIMESTAMP TimeStamp;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN


            uint16_t Reserved;
            uint16_t Identifier;
            uint16_t StreamChannelIndex;
            uint16_t BlockId;
            GEV_TIMESTAMP TimeStamp;

#    else

#        error unknown endianess

#    endif

        } GEV_PACKED;

        uint32_t uint32[4];
    }
    GEV_PACKED GVCP_EVENT_ITEM;



    typedef struct _GVCP_EVENT_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GVCP_EVENT_ITEM Items[1];
    }
    GEV_PACKED GVCP_EVENT_REQUEST;



    typedef struct _GVCP_EVENT_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
    }
    GEV_PACKED GVCP_EVENT_RESPONSE;



    typedef struct _GVCP_EVENTDATA_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GVCP_EVENT_ITEM Item;
        uint32_t Data[];
    }
    GEV_PACKED GVCP_EVENTDATA_REQUEST;



    typedef struct _GVCP_EVENTDATA_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
    }
    GEV_PACKED GVCP_EVENTDATA_RESPONSE;


    typedef struct _GV_IPCONFIG
    {
        GEV_IP_CONFIG IPConfiguration;
        GEV_IP_ADDRESS PersistantIP;
        GEV_IP_ADDRESS PersistantSubNetMask;
        GEV_IP_ADDRESS PersistantDefaultGateway;
        char UserDefinedName[16];
    }
    GEV_PACKED GV_IPCONFIG;

    typedef struct _GVCP_SETIPCONFIG_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
        GEV_MAC_ADDRESS MacAddress;
        GV_IPCONFIG Configuration;
    }
    GEV_PACKED GVCP_SETIPCONFIG_REQUEST;


    typedef struct GVCP_SETIPCONFIG_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
    }
    GEV_PACKED GVCP_SETIPCONFIG_RESPONSE;



#define GVCP_MAX_NR_EVENT_ITEMS 33



#define GVCP_MAX_EVENT_DATA_QUADLETS 131



    typedef struct GX_SHUTDOWN_REQUEST
    {
        GVCP_REQUEST_HEADER Header;
    }
    GEV_PACKED GX_SHUTDOWN_REQUEST;



    typedef struct GX_SHUTDOWN_RESPONSE
    {
        GVCP_RESPONSE_HEADER Header;
    }
    GEV_PACKED GX_SHUTDOWN_RESPONSE;



/**
 * Packet Format.
 */
    typedef enum _GVSP_PACKETFORMAT
    {
        /** The packet contains a data leader. */
        GVSP_PACKETFORMAT_LEADER = 1,

        /** The packet contains a data trailer. */
        GVSP_PACKETFORMAT_TRAILER = 2,

        /** The packet contains a part of the data payload. */
        GVSP_PACKETFORMAT_PAYLOAD = 3

    } GVSP_PACKETFORMAT;



    typedef union _GVSP_PACKETHEADER_PACKETINFO
    {
        struct
        {
#        if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

        /**
        * ID of packet in the block. The packet_id is reset to 0 at
        * the start of each data block. Packet_id 0 is thus the data
        * leader for the current block_id.
        */
            uint32_t PacketId : 24;

            /**
            * \see GVSP_PACKETFORMAT.
            */
            uint32_t PacketFormat : 7;

            /* See packet header below. */
            uint32_t ExtendedId : 1;

#        else
        //AG: ??? TODO
#error("Extended ID extension needs to be mapped.")

            uint32_t Reserved : 8;

            uint32_t PacketFormat : 24;

#        endif
        };

        uint32_t uint32;
    }
    GVSP_PACKETHEADER_PACKETINFO;


    typedef union _GVSP_PACKETHEADER_PACKETINFO_EXTENDED_ID
    {
        struct
        {
#        if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

        /**
        * ID of packet in the block. The packet_id is reset to 0 at
        * the start of each data block. Packet_id 0 is thus the data
        * leader for the current block_id.
        */
            uint32_t Reserved1 : 24;

            /**
            * \see GVSP_PACKETFORMAT.
            */
            uint32_t PacketFormat : 4;
            uint32_t Reserved2 : 3;
            uint32_t ExtendedId : 1;
            /*
            When EI (ExtendedId) flag = 0 -> block_id
                ID of the data block. Sequential and incrementing starting at 1. A block_id of 0 is
                reserved for the test packet. block_id wraps-around to 1 when it reaches its
                maximum value. For a GVSP transmitter, the block_id is reset to 1 when the
                stream channel is opened.
            When EI(ExtendedId) flag = 1 -> flag
                Provide GVSP stream status flag information. Upper 8 bits (msb, bit 0 to bit 7)
                are device - specific.Lower 8 bits(lsb, bit 8 to bit 15) are specified by GigE
                Vision.All unused bits must be set to 0 on transmission and ignored on
                reception.
                bit 0 to 7: device - specific
                bit 8 to 12 : Reserved.See Table 24 - 1.
                bit 13 : GEV_FLAG_RESEND_RANGE_ERROR.See Table 24 - 1.
                bit 14 : GEV_FLAG_PREVIOUS_BLOCK_DROPPED.See Table 24 - 1.
                bit 15 : GEV_FLAG_PACKET_RESEND.See Table 24 - 1.
            Extended ID (EI) flag indicating if block IDs are 64 bits and packet IDs are 32 bits.
                This is necessary to correctly decode this packet and determine if the block ID is put in
                the block_id or in the block_id64 field, and if the packet ID is put in the packet_id or in
                the packet_id32 field. It is also used to indicate how block_id / flag field is used.
                0: Standard ID - 16-bit block ID using the block_id field and 24-bit packet ID in
                the packet_id field. block_id64 and packet_id32 fields are not present.
                1: Extended ID - 64-bit block ID using the block_id64 field and 32-bit packet ID
                using the packet_id32 field.The flag field is available.
            */
#        else
        //AG: ??? TODO
#error("Extended ID extension needs to be mapped.")

            uint32_t Reserved : 8;

            uint32_t PacketFormat : 24;

#        endif
        };

        uint32_t uint32;
    }
    GEV_PACKED GVSP_PACKETHEADER_PACKETINFO_EXTENDED_ID;


    /**
    * GVSP Packet Header flags.
    */
    typedef struct _GVSP_PACKETHEADER_FLAG
    {
        uint16_t DeviceSpecific : 8;
        uint16_t Reserved : 5;
        uint16_t GEV_FLAG_RESEND_RANGE_ERROR : 1;
        uint16_t GEV_FLAG_PREVIOUS_BLOCK_DROPPED : 1;
        uint16_t GEV_FLAG_PACKET_RESEND : 1;
    }
    GEV_PACKED GVSP_PACKETHEADER_FLAG;

/**
* GVSP Packet Header. (8 bytes)
*/
    typedef struct GVSP_PACKETHEADER
    {
        /**
        * Status of the streaming operation.
        */
        uint16_t Status;

        /**
        * ID of the data block. Sequential and incrementing starting at 1.
        * A block_id of 0 is reserved for the test packet. Block_id wraps-around
        * to 1 when it reaches the limit of the 16-bit.
        */
        uint16_t BlockId;

        /**
        * 32 bit containing Packet Format and Packet Id.
        */
        GVSP_PACKETHEADER_PACKETINFO PacketInfo;
    }
    GEV_PACKED GVSP_PACKETHEADER;


    /**
    * GVSP Packet Header Extended Id. (20 bytes)
    */
    typedef struct _GVSP_PACKETHEADER_EXTENDED_ID
    {
        /**
        * Status of the streaming operation.
        */
        uint16_t Status;

        /**
        * GVSP Packet Header flags.
        */
        GVSP_PACKETHEADER_FLAG Flag;

        /**
        * 32 bit containing Packet Format and Packet Id.
        */
        GVSP_PACKETHEADER_PACKETINFO_EXTENDED_ID PacketInfo;
        uint64_t BlockId64;
        uint32_t PacketId32;
    }
    GEV_PACKED GVSP_PACKETHEADER_EXTENDED_ID;



    /**
     * GVSP Data Leader Info.
     * Generic Data Leader message body following the
     * GVSP_PACKETHEADER. Common to all content specific Data Leaders.
     * The data is swapped by the driver 32bit wise.
     */
    typedef struct _GVSP_DATALEADER_INFO
    {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

        uint16_t PayloadType;

        uint16_t Reserved;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN

        uint16_t Reserved;

        /**
         * Payload Type.
         * \see GVSP_PAYLOADTYPE.
         */
        uint16_t PayloadType;

#    else

#        error unknown endianess

#    endif

    /**
     * Timestamp.
     */
        GEV_TIMESTAMP Timestamp;

    }
    GEV_PACKED GVSP_DATALEADER_INFO;


/**
* GVSP Data Leader.
* Generic Data Leader format. Common to all content specific Data Leaders.
*/
    typedef struct GVSP_DATALEADER
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATALEADER_INFO Info;
    }
    GEV_PACKED GVSP_DATALEADER;


    /**
     * Maximum Data Leader Packet Size.
     * Maximum Ethernet payload size of GVSP Data Leader packets. This size
     * includes the IP header, UDP header, generic GVSP packet header,
     * additional fields of generic GVSP Data Leader packet header and all
     * the special fields of the various derivatives of the GVSP Data Leader
     * as well as additional appended custom data.
     */
#define GVSP_DATALEADER_MAXPACKETSIZE 576



/**
 * Payload Type.
 */
    typedef enum _GVSP_PAYLOADTYPE
    {
        /**
         * Payload Type Image.
         * The block contains an image.
         */
        GVSP_PAYLOADTYPE_IMAGE = 0x0001,

        /**
         * Payload Type Raw Data.
         * The block contains raw data.
         */
         GVSP_PAYLOADTYPE_RAWDATA = 0x0002,

         /**
          * Payload Type File.
          * The block contains a file.
          */
          GVSP_PAYLOADTYPE_FILE = 0x0003,

          /**
           * Payload Type Chunk Data.
           * The block contains chunked data.
           */
           GVSP_PAYLOADTYPE_CHUNKDATA = 0x0004,

           /**
            * Payload Type Device Specific.
            * The block contains device specific data.
            */
            GVSP_PAYLOADTYPE_DEVICESPECIFIC = 0x8000,

            /**
             * Payload Type Device Specific.
             * The block contains image and chunked data.
             */
             GVSP_PAYLOADTYPE_IMAGE_EXTENDED_CHUNK = 0x4001
    }
    GVSP_PAYLOADTYPE;



/**
 * GVSP Image Data Leader Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATALEADER_IMAGE_INFO
    {
        GVSP_DATALEADER_INFO Generic;

        /**
         * This field gives the pixel format of payload data.
         * Refer to pixel type format.
         */
        uint32_t PixelType;

        struct
        {
            /**
             * Width in pixels. The actual width received can be lower than the
             * maximum supported by the device when a ROI is set. When no ROI is
             * defined, this field must be set to the maximum number of pixels
             * supported by the device.
             */
            uint32_t X;

            /**
             * Height in lines. The actual number of lines received can be lower
             * than the maximum supported by the device when a ROI is set. When
             * no ROI is defined, this field must be set to the maximum number of
             * lines supported by the device.
             */
            uint32_t Y;
        }
        GEV_PACKED Size;


        struct
        {
            /**
             * Offset in pixels from image origin. Used for ROI support. When no
             * ROI is defined this field must be set to 0.
             */
            uint32_t X;

            /**
             * Offset in lines from image origin. Used for ROI support. When no ROI
             * is defined this field must be set to 0.
             */
            uint32_t Y;
        }
        GEV_PACKED Offset;


        struct
        {
#        if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

            uint16_t Y;

            uint16_t X;

#        else

            /**
             * Horizontal padding expressed in bytes. Number of extra bytes
             * transmitted at the end of each line to facilitate image alignment
             * in buffers. This can typically used to have 32-bit aligned image
             * lines. This is similar to the horizontal invalid (or horizontal
             * blanking) in analog cameras. Set to 0 when no horizontal padding
             * is used.
             */
            uint16_t X;

            /**
             * Vertical padding expressed in bytes. Number of extra bytes
             * transmitted at the end of the image to facilitate image alignment
             * in buffers. This could be used to align buffers to certain block
             * size (for instance 4 KB). This is similar to the vertical invalid
             * (or vertical blanking) in analog cameras. Set to 0 when no
             * vertical padding is used.
             */
            uint16_t Y;

#        endif

        }
        GEV_PACKED Padding;
    }
    GEV_PACKED GVSP_DATALEADER_IMAGE_INFO;



/**
 * GVSP Image Data Leader.
 */
    typedef struct _GVSP_DATALEADER_IMAGE
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATALEADER_IMAGE_INFO Info;
    }
    GEV_PACKED GVSP_DATALEADER_IMAGE;



/**
 * GVSP Raw Data Leader Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATALEADER_RAWDATA_INFO
    {
        GVSP_DATALEADER_INFO Generic;

        struct
        {
            uint32_t High;
            uint32_t Low;
        }
        GEV_PACKED DataSize;
    }
    GEV_PACKED GVSP_DATALEADER_RAWDATA_INFO;



/**
 * GVSP Raw Data Leader.
 */
    typedef struct _GVSP_DATALEADER_RAWDATA
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATALEADER_RAWDATA_INFO Info;
    }
    GEV_PACKED GVSP_DATALEADER_RAWDATA;



/**
 * GVSP File Data Leader Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATALEADER_FILE_INFO
    {
        GVSP_DATALEADER_INFO Generic;

        struct
        {
            uint32_t High;
            uint32_t Low;
        }
        GEV_PACKED DataSize;

        char FileName[1];
    }
    GEV_PACKED GVSP_DATALEADER_FILE_INFO;



/**
 * GVSP File Data Leader.
 */
    typedef struct GVSP_DATALEADER_FILE
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATALEADER_FILE_INFO Info;
    }
    GEV_PACKED GVSP_DATALEADER_FILE;



/**
 * GVSP Chunk Data Leader Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATALEADER_CHUNKDATA_INFO
    {
        GVSP_DATALEADER_INFO Generic;
    }
    GEV_PACKED GVSP_DATALEADER_CHUNKDATA_INFO;



/**
 * GVSP Chunk Data Leader.
 */
    typedef struct _GVSP_DATALEADER_CHUNKDATA
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATALEADER_CHUNKDATA_INFO Info;
    }
    GEV_PACKED GVSP_DATALEADER_CHUNKDATA;



/**
 * GVSP Device Specific Data Leader Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATALEADER_DEVICESPECIFIC_INFO
    {
        GVSP_DATALEADER_INFO Generic;

        /**
         * Data.
         * Device specific data.
         */
        uint8_t Data[];
    }
    GEV_PACKED GVSP_DATALEADER_DEVICESPECIFIC_INFO;



/**
 * GVSP Chunk Data Leader.
 */
    typedef struct _GVSP_DATALEADER_DEVICESPECIFIC
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATALEADER_DEVICESPECIFIC_INFO Info;
    }
    GEV_PACKED GVSP_DATALEADER_DEVICESPECIFIC;



    typedef struct _GVSP_DATAPACKET
    {
        GVSP_PACKETHEADER Header;

        /**
         * Payload.
         */
        uint8_t Payload[1];
    }
    GEV_PACKED GVSP_DATAPACKET;



/**
 * GVSP Data Trailer Info.
 * Generic Data Trailer message body following the
 * GVSP_PACKETHEADER. Common to all content specific Data Trailers.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATATRAILER_INFO
    {
#    if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN

        uint16_t PayloadType;

        uint16_t Reserved;

#    elif GIGEVISION_ENDIANESS == GIGEVISION_BIG_ENDIAN

        uint16_t Reserved;

        /**
         * Payload Type.
         * \see GVSP_PAYLOADTYPE.
         */
        uint16_t PayloadType;

#    endif
    }
    GEV_PACKED GVSP_DATATRAILER_INFO;



/**
 * GVSP Data Trailer.
 * Generic Data Trailer format. Common to all content specific Data Trailers.
 */
    typedef struct GVSP_DATATRAILER
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATATRAILER_INFO Info;
    }
    GEV_PACKED GVSP_DATATRAILER;



/**
 * Maximum Data Trailer Packet Size.
 * Maximum Ethernet payload size of GVSP Data Trailer packets. This size
 * includes the IP header, UDP header, generic GVSP packet header,
 * additional fields of generic GVSP Data Trailer packet header and all
 * the special fields of the various derivatives of the GVSP Data Trailer
 * as well as additional appended custom data.
 */
#define GVSP_DATATRAILER_MAXPACKETSIZE 576



/**
 * GVSP Image Data Trailer Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATATRAILER_IMAGE_INFO
    {
        GVSP_DATATRAILER_INFO Generic;

        uint32_t SizeY;
    }
    GEV_PACKED GVSP_DATATRAILER_IMAGE_INFO;



/**
 * GVSP Image Data Trailer.
 */
    typedef struct _GVSP_DATATRAILER_IMAGE
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATATRAILER_IMAGE_INFO Info;
    }
    GEV_PACKED GVSP_DATATRAILER_IMAGE;



/**
 * GVSP Raw Data Trailer Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATATRAILER_RAWDATA_INFO
    {
        GVSP_DATATRAILER_INFO Generic;
    }
    GEV_PACKED GVSP_DATATRAILER_RAWDATA_INFO;



/**
 * GVSP Raw Data Trailer.
 */
    typedef struct GVSP_DATATRAILER_RAWDATA
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATATRAILER_INFO Info;
    }
    GEV_PACKED GVSP_DATATRAILER_RAWDATA;



/**
 * GVSP File Data Trailer Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATATRAILER_FILE_INFO
    {
        GVSP_DATATRAILER_INFO Generic;
    }
    GEV_PACKED GVSP_DATATRAILER_FILE_INFO;



/**
 * GVSP File Data Trailer.
 */
    typedef struct GVSP_DATATRAILER_FILE
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATATRAILER_FILE_INFO Info;
    }
    GEV_PACKED GVSP_DATATRAILER_FILE;



/**
 * GVSP Chunk Data Trailer Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATATRAILER_CHUNKDATA_INFO
    {
        GVSP_DATATRAILER_INFO Generic;

        uint32_t Length;
    }
    GEV_PACKED GVSP_DATATRAILER_CHUNKDATA_INFO;



/**
 * GVSP Image Data Trailer.
 */
    typedef struct _GVSP_DATATRAILER_CHUNKDATA
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATATRAILER_CHUNKDATA_INFO Info;
    }
    GEV_PACKED GVSP_DATATRAILER_CHUNKDATA;



/**
 * GVSP Device Specific Data Trailer Info.
 * The data is swapped by the driver 32bit wise.
 */
    typedef struct _GVSP_DATATRAILER_DEVICESPECIFIC_INFO
    {
        GVSP_DATATRAILER_INFO Generic;

        uint8_t Data[];
    }
    GEV_PACKED GVSP_DATATRAILER_DEVICESPECIFIC_INFO;



/**
 * GVSP Device Specific Data Trailer.
 */
    typedef struct _GVSP_DATATRAILER_DEVICESPECIFIC
    {
        GVSP_PACKETHEADER Header;
        GVSP_DATATRAILER_DEVICESPECIFIC_INFO Info;
    }
    GEV_PACKED GVSP_DATATRAILER_DEVICESPECIFIC;



/**
 * GVSP Request Header.
 * The GVSP request messages use the same header as the GVCP ones.
 *
 * \Note Currently the PACKETRESEND_CMD ist the only defined GVSP request.
 */
    typedef GVCP_REQUEST_HEADER GVSP_REQUEST_HEADER;



    typedef union _GVSP_PACKETRESEND_PACKETID
    {
        struct
        {
#        if GIGEVISION_ENDIANESS == GIGEVISION_LITTLE_ENDIAN
            uint32_t PacketId : 24;
            uint32_t Reserved : 8;
#        else
            uint32_t Reserved : 8;
            uint32_t PacketId : 24;
#        endif
        } GEV_PACKED;

        uint32_t uint32;
    }
    GEV_PACKED GVSP_PACKETRESEND_PACKETID;

/**
 * Packet Resend Command Flags.
 * Request header flags specific to the packet resend command.
 */
    typedef enum _GEV_PACKETRESEND_COMMAND_FLAGS
    {
        /**
         *  bit 3 – Extended ID flag Set to indicate a 64-bit block_id64 and 32-bit packet_id32,
         *  Clear for a 16-bit block_id and 24-bit packet_id.
         */
        GEV_PACKETRESEND_COMMAND_FLAG_EXTENDED_ID = 1 << 4
    }
    GEV_PACKETRESEND_COMMAND_FLAGS;


    typedef struct _GVSP_PACKETRESEND_REQUEST
    {
        GVSP_REQUEST_HEADER Header;

        /**
         * Stream Channel Index.
         * Index of stream channel the request belongs to.
         */
        uint16_t StreamChannelIndex;

        /**
         * Block ID.
         * ID number of the data block.
         */
        uint16_t BlockId;

        /**
         * ID of first packet to be resent.
         */
        GVSP_PACKETRESEND_PACKETID First;

        /**
         * ID of last packet to be resent.
         */
        GVSP_PACKETRESEND_PACKETID Last;
    }
    GEV_PACKED GVSP_PACKETRESEND_REQUEST;


    typedef struct _GVSP_PACKETRESEND_REQUEST_EXTENDED_ID
    {
        GVSP_REQUEST_HEADER Header;

        /**
        * Stream Channel Index.
        * Index of stream channel the request belongs to.
        */
        uint16_t StreamChannelIndex;

        /**
        * Former Block ID.
        */
        uint16_t Reserved;

        /**
        * ID of first packet to be resent.
        */
        uint32_t FirstPacketId;

        /**
        * ID of last packet to be resent.
        */
        uint32_t LastPacketId;

        /**
        * Block ID 64 Bit.
        * ID number of the data block.
        */
        uint64_t BlockId64;
    }
    GEV_PACKED GVSP_PACKETRESEND_REQUEST_EXTENDED_ID;


#define GVSP_PIXEL_MONO  0x01000000
#define GVSP_PIXEL_COLOR 0x02000000

#define _GVSP_PIXEL_ENCODE_BIT_COUNT( n ) (((n) & 0xff) << 16)


/**
 * Pixel Formats.
 */
    typedef enum _GVSP_PIXEL_FORMAT
    {
        GVSP_PIX_MONO8 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 8 ) | 0x0001,
        GVSP_PIX_MONO8_SIGNED = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 8 ) | 0x0002,
        GVSP_PIX_MONO10 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0003,
        GVSP_PIX_MONO10_PACKED = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 12 ) | 0x0004,
        GVSP_PIX_MONO12 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0005,
        GVSP_PIX_MONO12_PACKED = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 12 ) | 0x0006,
        GVSP_PIX_MONO16 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0007,

        GVSP_PIX_BAYGR8 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 8 ) | 0x0008,
        GVSP_PIX_BAYRG8 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 8 ) | 0x0009,
        GVSP_PIX_BAYGB8 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 8 ) | 0x000a,
        GVSP_PIX_BAYBG8 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 8 ) | 0x000b,

        GVSP_PIX_BAYGR10 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x000c,
        GVSP_PIX_BAYRG10 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x000d,
        GVSP_PIX_BAYGB10 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x000e,
        GVSP_PIX_BAYBG10 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x000f,

        GVSP_PIX_BAYGR12 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0010,
        GVSP_PIX_BAYRG12 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0011,
        GVSP_PIX_BAYGB12 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0012,
        GVSP_PIX_BAYBG12 = GVSP_PIXEL_MONO | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x0013,

        GVSP_PIX_RGB8_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 24 ) | 0x0014,
        GVSP_PIX_BGR8_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 24 ) | 0x0015,

        GVSP_PIX_RGBA8_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 32 ) | 0x0016,
        GVSP_PIX_BGRA8_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 32 ) | 0x0017,

        GVSP_PIX_RGB10_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x0018,
        GVSP_PIX_BGR10_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x0019,

        GVSP_PIX_RGB12_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x001a,
        GVSP_PIX_BGR12_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x001b,

        GVSP_PIX_BGR10V1_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 32 ) | 0x001c,
        GVSP_PIX_BGR10V2_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 32 ) | 0x001d,

        GVSP_PIX_YUV411_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 12 ) | 0x001e,
        GVSP_PIX_YUV422_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 16 ) | 0x001f,
        GVSP_PIX_YUV444_PACKED = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 24 ) | 0x0020,

        GVSP_PIX_RGB8_PLANAR = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 24 ) | 0x0021,
        GVSP_PIX_RGB10_PLANAR = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x0022,
        GVSP_PIX_RGB12_PLANAR = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x0023,
        GVSP_PIX_RGB16_PLANAR = GVSP_PIXEL_COLOR | _GVSP_PIXEL_ENCODE_BIT_COUNT( 48 ) | 0x0024
    }
    GVSP_PIXEL_FORMAT;



#define GVSP_PIXEL_FORMAT_GET_BIT_COUNT( format ) (((format) >> 16) & 0xff)



#define GEV_SOCKET_TYPE SOCK_DGRAM



/**
 * \name GigE Vision Status Codes.
 * Enumeration of GigE Vision Standard Status Codes.
 */
/*@{*/


/**
 * Success.
 * Command executed successfully.
 */
#define GEV_STATUS_SUCCESS ((GEV_STATUS)0x0000U)


/**
 * Not Implemented.
 * Command is not supported by the device.
 */
#define GEV_STATUS_NOT_IMPLEMENTED ((GEV_STATUS)0x8001U)


/**
 * Invalid Parameter.
 * At least one parameter provided in the command is invalid
 * (or out of range) for the device.
 */
#define GEV_STATUS_INVALID_PARAMETER ((GEV_STATUS)0x8002U)


/**
 * Invalid Address.
 * An attempt was made to access a non existent address space location.
 */
#define GEV_STATUS_INVALID_ADDRESS ((GEV_STATUS)0x8003U)


/**
 * Write Protected.
 * The addressed register cannot be written to.
 */
#define GEV_STATUS_WRITE_PROTECT ((GEV_STATUS)0x8004U)


/**
 * Bad Alignment.
 * A badly aligned address offset or data size was specified.
 */
#define GEV_STATUS_BAD_ALIGNMENT ((GEV_STATUS)0x8005U)


/**
 * Access denied.
 * An attempt was made to access an address location which is
 * currently/momentary not accessible. This depends on the current
 * state of the device node, in particular the current privilege of
 * the application.
 */
#define GEV_STATUS_ACCESS_DENIED ((GEV_STATUS)0x8006U)


/**
 * Busy.
 * A required resource to service the request isnâ€™t currently
 * available. The request may be retried.
 */
#define GEV_STATUS_BUSY ((GEV_STATUS)0x8007U)


/**
 * Local Problem.
 * An internal problem in the device implementation occurred while
 * processing the request. Optionally the device provides a mechanism
 * for looking up a detailed description of the problem. (Log files,
 * Event log, â€˜Get last errorâ€™ mechanics). This error is intended to
 * report problems from underlying services (operating system, 3rd
 * party library) in the camera to the client side without translating
 * every possible error code into a GigE Vision equivalent.
 */
#define GEV_STATUS_LOCAL_PROBLEM ((GEV_STATUS)0x8008U)


/**
 * Message Mismatch.
 * Message mismatch (request and acknowledge don't match).
 */
#define GEV_STATUS_MSG_MISMATCH ((GEV_STATUS)0x8009U)


/**
 * Invalid Protocol.
 * This version of the GVCP protocol is not supported.
 */
#define GEV_STATUS_INVALID_PROTOCOL ((GEV_STATUS)0x800a)


/**
 * No Message.
 * Timeout, no message received.
 */
#define GEV_STATUS_NO_MSG ((GEV_STATUS)0x800b)


/**
 * Packet Unavailable.
 * The request packet is not available anymore.
 */
#define GEV_STATUS_PACKET_UNAVAILABLE ((GEV_STATUS)0x800c)


/**
 * Data Overrun.
 * Internal memory of device overrun (typically for image acquisition).
 */
#define GEV_STATUS_DATA_OVERRUN ((GEV_STATUS)0x800d)


/**
 * Invalid header.
 * The message header is not valid. Some of its fields do not match
 * the specificiation.
 */
#define GEV_STATUS_INVALID_HEADER ((GEV_STATUS)0x800e)


/**
 * Error.
 * Generic error. Try to avoid and use a more descriptive status code
 * from list above.
 */
#define GEV_STATUS_ERROR ((GEV_STATUS)0x8fff)


#define GEV_SUCCESS( __s__ ) (0 == (__s__))
#define GEV_FAILED( __s__ ) (0 != ((__s__) & 0x8000))


/*@}*/

#pragma pack(pop)

#ifdef __cplusplus
}
#endif



#ifdef _MSC_VER
#    pragma warning( pop )
#endif



#define GEV_DEFAULT_PORT 3956



#endif    // ndef GIGEVISION_H__INCLUDED
