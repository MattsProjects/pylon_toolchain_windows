/**
 * \file
 * \brief Header of the GX - GigE Vision Transactions - library.
 *
 * \Copyright (c) 2004-2021 Basler AG
 *
 * \author Volker Moebius
 *
 */

#ifdef _MSC_VER
#    pragma once
#endif

#ifndef GXAPI_H_INCLUDED
#define GXAPI_H_INCLUDED


struct sockaddr;
#include <stddef.h>     // for size_t,...


#if defined(__GNUC__) && (defined(__unix__) || defined(__APPLE__))
#  include <stdint.h>     // for int8_t,uint8_t,...
#  include <gxstatus.h>
#elif defined(_MSC_VER) && defined(_WIN32)
#  if (_MSC_VER < 1600)
#pragma message( "Including substitute/stdint.h")
#    include <substitute/stdint.h>
#  endif
#  include <gxstatus.h>
#else
#   error No platform-specific type definitions
#endif

#include "GigEVision.h"


#ifdef WIN32
#    ifdef GX_EXPORTS
#        define GX_API __declspec(dllexport)
#    else
#        define GX_API __declspec(dllimport)
#    endif
#    define GX_CALL __cdecl
#else
#   ifdef GX_EXPORTS
#        define GX_API __attribute__((visibility("default")))
#   else
#        define GX_API
#   endif
#   define GX_CALL //__attribute__((cdecl))
#endif


#define GX_TIMEOUT_INFINITE (-1)


/**
 * GX Address.
 * Data type for representing (register) address values.
 *
 * \note Addresses are defined to be 32bit values by the underlying
 *       GigE Vision Standard.
 */
typedef GEV_ADDRESS GXADDRESS;



typedef char GXCHAR;



/**
 * \name Client Side Interface.
 */
 /*@{*/
namespace Gx
{

    // List of all available properties
    enum EPropertyValue
    {
        EPropertyValue_License = 0xAEF1,
        EPropertyValue_EnumInfo = 0x93D1
    };

    // The receive buffer size for sockets used for receiving broadcast answers
    extern size_t g_cBroadcastSocketRecvBufSize;

    /// Version information.
    /// Returns the library version in Major.Minor format.
    GX_API GXSTATUS GX_CALL GetVersion( uint32_t *pMajor, uint32_t *pMinor );

    /// Init.
    /// Static initializer function. Must be called once before any subsequent
    /// usage of the GX library.
    GX_API GXSTATUS GX_CALL Init();


    /// Set properties
    /// Set the value of a property.
    GX_API GXSTATUS GX_CALL SetProperty( int propertyId, const void *pData, size_t size );

    /// Get properties
    /// Retrieve the value of a property.
    GX_API GXSTATUS GX_CALL GetProperty( int propertyId, void *pData, size_t *pSize );

    /// GX Exit.
    /// Static cleanup function. Must be called once before the process exits.
    GX_API GXSTATUS GX_CALL Exit();

    typedef void* WaitObject_t;

    class Enumerator
    {
    public:

        /// Callback interface to be provided for device enumeration.
        class Callee
        {
        public:

            virtual GXSTATUS EnumCallback(

                /// Device Address.
                /// The current network address of the device.
                /// \note The pointer must not be stored for subsequent use. Instead
                ///       interesting information have to be copied from the struct.
                const sockaddr *pDeviceAddr,

                /// Discovery Information.
                /// \note The pointer must not be stored for subsequent use. Instead
                ///       interesting information have to be copied from the struct.
                const GEV_DISCOVERY_INFO *pDiscoveryInfo,

                /// Interface Address.
                /// The local network address at which the response did arrive.
                /// \note The pointer must not be stored for subsequent use. Instead
                ///       interesting information have to be copied from the struct.
                const sockaddr *pInterfaceAddr
            ) = 0;
        };


        enum Flags
        {
            /// Default.
            /// Must not be combined with other flags.
            FlagDefault = 0,

            /// Broadcast Acknowledge.
            FlagBroadcastAcknowledge
        };


        /// Discover.
        /// Starts the discovery process.
        static GX_API GXSTATUS GX_CALL Discover(

            Callee *pCallee,

            // Timeout in milliseconds to be applied during discovery. */
            uint32_t Timeout_ms,

            /// Flags.
            /// Combination of enum Flags members.
            uint32_t Flags = FlagDefault,

            /// Destination.
            /// If a destination address is provided a directed unicast
            /// discovery request is issued. (Broadcast by default.) Currently
            /// only IPv4 addressing is supported, i.e. pDestination must refer
            /// to a valid sockaddr_in structure. The sockaddr_in.sin_port
            /// may be used to override the default GigE Vision port number.
            const sockaddr *pDestination = NULL
        );
    };



    class ControlChannel
    {
    public:

        virtual GXSTATUS Destroy() = 0;

        virtual GXSTATUS GetProperty( uint32_t Property, void *pValue, size_t Size, size_t *pLength ) /* const */ = 0;
        virtual GXSTATUS SetProperty( uint32_t Property, const void *pValue, size_t Size ) = 0;

        /// Surprise Removal Callback.
        class SurpriseRemovalCallback
        {
        public:

            /// On Surprise Removal.
            /// Invoked on surprisingly removal of the camera.
            virtual void OnSurpriseRemoval() = 0;
        };

        virtual GXSTATUS ReadReg( const GXADDRESS Addresses[], uint32_t Data[], size_t Count ) = 0;
        virtual GXSTATUS WriteReg( const GXADDRESS Addresses[], const uint32_t Data[], size_t Count ) = 0;

        virtual GXSTATUS ReadMem( GXADDRESS Address, void *Data, size_t Count ) = 0;
        virtual GXSTATUS WriteMem( GXADDRESS Address, const void *Data, size_t Count ) = 0;



        /// Open Stream.
        /// Opens the stream channel at the camera site.
        /// \note The 'Do Not Fragment' bit is always set by the current
        ///       implementation while writing down the packet size to the
        ///       according camera register.
        virtual GXSTATUS OpenStream(

            /// Stream Index.
            /// Index of stream to open.
            uint32_t StreamIndex,

            /// Destination Address.
            /// Destination IP address and UDP port number of the stream. The
            /// IP address is written to the cameras SCDAx register. The port
            /// number is written to the cameras SCPx register.
            /// \note Currently only IPv4 addressing is supported.
            const sockaddr *pDest ) = 0;



        /// Close Stream.
        virtual GXSTATUS CloseStream( uint32_t StreamIndex ) = 0;


        /// Set Heartbeat Timeout.
        /// Adjusts the heartbeat timeout at the camera as well as at the
        /// internal heartbeat timer. An application must not modify the
        /// heartbeat timeout bootstrap register of the camera by WriteReg
        /// or WriteMem directly. Instead the SetHeartbeatTimeout method
        /// must be used to keep the timeout period of the camera and the
        /// heartbeat frequency consistent.
        /// \return GX status according the success of the operation. The
        ///         implementation returns an error status on attempt to set
        ///         an heartbeat timeout of less than GEV_MINIMUM_HEARTBEATTIMEOUT_MS,
        ///         i.e. 500 ms.
        virtual GXSTATUS SetHeartbeatTimeout(

            /// Timeout Duration [ms].
            /// Duration of the heartbeat timeout in units of milliseconds.
            /// Must not be less than GEV_MINIMUM_HEARTBEATTIMEOUT_MS, i.e. 500ms.
            uint32_t TimeoutDuration_ms

        ) = 0;


        /// Enable Command Duplication.
        /// This is a workaround for a problem with Intel network adapters
        /// that sporadically fail to generate an interrupt for the acknowledge packet.
        /// Sending a command twice will result in two acknowledge packets
        /// send back by the camera. Tests show that this ensures that
        /// the interrupt is triggered.
        /// For enabling the sending of two commands
        /// with the same request id for each request.
        /// \return GX status according the success of the operation.
        virtual GXSTATUS EnableCommandDuplication(

            /// True for enabling the sending of two commands
            /// with the same request id for each request.
            bool enable

        ) = 0;


        /// Register Callback.
        /// Registers callback notifications.
        /// Only one callback can be registered at a given time. Registering
        /// a callback deregisters the previous one implicitely. Registering
        /// NULL deregisters the callback at all.
        /// \note RegisterSurpriseRemovalCallback is synchronized with the
        ///       delivering of a callback, i.e. invocation of
        ///       SurpriseRemovalCallback::OnSurpriseRemoval. However it may
        ///       be called from within a callback itself.
        virtual GXSTATUS RegisterSurpriseRemovalCallback(

            /// Callback.
            /// Pointer to the callback handler to be registered.
            SurpriseRemovalCallback *pCallback

        ) = 0;


        /// Properties.
        /// Enumeration of the properties the ControlChannel knows and
        /// understands.
        enum Properties
        {
            /// Read Register Timeout [ms].
            ReadRegTimeout,

            /// Write Register Timeout [ms].
            WriteRegTimeout,

            /// Read Memory Timeout [ms].
            ReadMemTimeout,

            /// Write Memory Timeout [ms].
            WriteMemTimeout,

            /// Read Retry Count
            MaxRetryCountRead,

            /// Write Retry Count
            MaxRetryCountWrite,

            /// Statistic Retry Count
            StatisticReadWriteTimeoutCount,

            /// !!!!! INSERT NEW PROPERTIES HERE !!!!!!

            /// Address of CompressionRegisterMap or 0 if not supported
            CompressionRegisterMapAddress = 0xC0B00,

            /// The complete compression register map (Baselibs::CCompressionRegisterMap)
            CompressionRegisterMap = 0xC0D00,

            /// Return the payload size of the decompressed image or 0 if not supported (uint64_t)
            PayloadSizeDecompressed = 0xDEC00,

            /// Security: Value of m_isBadMode in CControlChannel. The type is bool and only settable to true. for 
            BadModeValue = 0xF12AB648,

            /// Security: Value of m_NextRequestID in CChannel. The type is uint16_t and only readable.
            RequestIdValue = 0xF1676AB1,
        };


        /// \todo sort interface methods on DLL renaming

        /// Open Message Channel.
        virtual GXSTATUS OpenMessageChannel(

            /// Destination Address.
            /// The destination IP address of the message channel.
            /// \note Only IPv4 addressing is supported currently.
            const sockaddr *pDestAddr,

            /// Timeout [ms].
            /// Timeout value in milliseconds. If an acknowledge was requested
            /// and the timeout expires before the acknowledge arrives at the
            /// device the message is resent.
            uint32_t Timeout_ms,

            /// Retry Count.
            /// Specifies how many times a message is resent if the requested
            /// acknowledge doesn't arrive at the device within the specified
            /// Timeout_ms. If RetryCount is set to zero, no acknowledges are
            /// requested by the device at all, i.e. the acknowledge bit in
            /// the command header is not set.
            uint16_t RetryCount ) = 0;

        /// Close Message Channel.
        /// Closes the message channel at the device.
        virtual GXSTATUS CloseMessageChannel() = 0;

        /// Open.
        /// Establishes a control connection to the specified device.
        static GX_API GXSTATUS GX_CALL Create(

            /// Device Address.
            /// Pointer to a device address structure. Currently only IPv4
            /// addresses are allowed.
            const sockaddr *pDeviceAddr,

            /// Access Flags.
            /// One of the GEV_CONTROL_ACCESS_PRIVILEDGES.
            uint32_t AccessFlags,

            /// Control Channel.
            /// Address of a Control Channel Pointer.
            Gx::ControlChannel **ppControlChannel
        );

        /// Establishes a control connection to the specified device and specify a heartbeat timeout.
        static GX_API GXSTATUS GX_CALL Create(

            /// Device Address.
            /// Pointer to a device address structure. Currently only IPv4
            /// addresses are allowed.
            const sockaddr *pDeviceAddr,

            /// Access Flags.
            /// One of the GEV_CONTROL_ACCESS_PRIVILEDGES.
            uint32_t AccessFlags,

            /// Heartbeat timeout in for the local thread in ms
            /// this can be overwritten using SetHeartbeatTimeout
            uint32_t HeartbeatTimeout_ms,

            /// Control Channel.
            /// Address of a Control Channel Pointer.
            Gx::ControlChannel **ppControlChannel
        );
    };



    class MessageListener
    {
    public:

        /// Destroy.
        virtual GXSTATUS Destroy() = 0;

        /// Get Address.
        /// Retrieves the underlying socket address of the MessageChannel.
        virtual GXSTATUS GetAddress( sockaddr *pSockAddr ) = 0;



        /// Allocate Resources.
        virtual GXSTATUS
            AllocResources(

                /// Number of Buffers.
                /// Number of internal buffers to queue received messages.
                uint32_t NrBuffers

            ) = 0;



        /// Free Resources.
        virtual GXSTATUS FreeResources() = 0;



        /// Get Message.
        virtual GXSTATUS GetNextMessage(

            void *pBuffer,

            size_t BufSize,

            size_t *pLength ) = 0;

        /// Register Wait Object.
        virtual GXSTATUS RegisterWaitObject( WaitObject_t WaitObject ) = 0;

        /// Create.
        static GX_API GXSTATUS GX_CALL Create(

            /// Camera address.
            const sockaddr *pCameraAddr,

            /// Interface Address.
            /// Specifies the local interface the newly created MessageListener
            /// is bound to. If NULL the MessageListener is not bound to a
            /// specific interface.
            const sockaddr *pInterfaceAddr,

            /// Message Listener.
            /// Output parameter. Pointer to a MessageListener pointer.
            Gx::MessageListener **ppMessageListener );
    };



    /// Interface Stream Grabber.
    class StreamGrabber
    {
    public:

        virtual GXSTATUS Destroy() = 0;

        virtual GXSTATUS SetProperty( uint32_t Property, const void *pValue, size_t Size ) = 0;
        virtual GXSTATUS GetProperty( uint32_t Property, void *pValue, size_t Size, size_t *pLength ) const = 0;

        /// Get Address.
        /// Retrieves the underlying socket address of the stream grabber.
        virtual GXSTATUS GetAddress( sockaddr *pSockAddr ) = 0;

        enum Types
        {
            /// NDIS IM Filter Driver.
            NdisImAccelerator,

            /// Intel 8254x Miniport Adapter Driver.
            /// (Aka Basler GigE Vision Adapter.)
            Intel8254xAccelerator,

            /// UserMode socket driver
            Socket
        };

        /// Get Type.
        virtual GXSTATUS GetType( Types *pType ) const = 0;

        /// Allocate Resources.
        virtual GXSTATUS
            AllocResources(

                /// Maximum Number of Buffers.
                /// Maximum number of frame buffers to be queued simultaneously
                /// at the stream.
                unsigned MaxNrBuffers,

                /// Maximum Data Size.
                /// Size in bytes of the largest data buffer to be attached at
                /// the stream.
                size_t MaxDataSize,

                /// Packet Size.
                /// Size of streaming packets to use including the sizes of the
                /// IP header, UDP header and GEV Stream packet header.
                uint16_t PacketSize,

                /// Receive Window Size.
                /// Size of the sliding receive window in number of frames.
                /// If Null is specified the ReceiveWindowSize is set internally.
                uint32_t ReceiveWindowSize,

                /// Stream uses extened IDs, 64 Bit for block IDs and 32 Bit for packet IDs
                /// Extended ID mode is set in GVSP Configuration register
                bool ExtendedId

            ) = 0;



        /// Free Resources.
        virtual GXSTATUS FreeResources() = 0;


        /// Attached Buffer.
        class AttachedBuffer
        {
        public:
            virtual GXSTATUS Queue() = 0;
            virtual GXSTATUS Detach() = 0;
        };


        enum
        {
            MaxLeaderSize = 576 - 2 * sizeof( uint32_t )
        };
        enum
        {
            MaxTrailerSize = 576 - 2 * sizeof( uint32_t )
        };

        typedef void *Context_t;


        virtual GXSTATUS AttachBuffer(
            void *pLeader,
            size_t LeaderSize,
            void *pData,
            size_t DataSize,
            void *pTrailer,
            size_t TrailerSize,
            Context_t Context,
            AttachedBuffer **ppAttachedBuffer ) = 0;

        struct AcquisitionResult
        {
            /// Block ID.
            /// GVSP Block Id of the acquired data frame.
            uint64_t BlockId;

            /// Completion Status
            /// The completion status of the acquired frame.
            GXSTATUS CompletionStatus;

            /// Leader Length.
            /// Actual length of the acquired data leader.
            size_t LeaderLength;

            /// Data Length.
            /// Actual length of the acquired data payload.
            size_t DataLength;

            /// Trailer Length.
            /// Actual length of the acquired data trailer.
            size_t TrailerLength;
        };

        virtual GXSTATUS RetrieveBuffer(
            Context_t *pContext,
            AcquisitionResult *pAcquisitionResult ) = 0;

        /// Register Wait Object.
        virtual GXSTATUS RegisterWaitObject( WaitObject_t WaitObject ) = 0;

        virtual GXSTATUS Flush() = 0;


        /// IsTypeAvailable.
        static GX_API GXSTATUS GX_CALL IsTypeAvailable(

            /// Type.
            /// The type of Stream Grabber to check. Member of enum
            /// Types. \see Types
            Types Type,

            /// Camera address.
            const sockaddr *pCameraAddr,

            /// Interface address.
            const sockaddr *pInterfaceAddr
        );

        /// Create.
        static GX_API GXSTATUS GX_CALL Create(

            /// Type.
            /// The type of Stream Grabber to instantiate. Member of enum
            /// Types. \see Types
            Types Type,

            /// The GigE Vision stream channel number
            uint16_t StreamChannelIndex,

            /// Camera address.
            const sockaddr *pCameraAddr,

            /// Interface address.
            const sockaddr *pInterfaceAddr,

            /// Multicast or broadcast address.
            const sockaddr *pMulticastAddr,

            Gx::StreamGrabber **ppStreamGrabber );
    };

    /// Interface stream param helper.
    class StreamParamHelper
    {
    public:
        /// Destroy.
        virtual GXSTATUS Destroy() = 0;

        ///////////////////////////////////////////////////////////////////////////
        // Enums are used as index. Change with care!
        enum EStreamPropertyItem
        {
            /* Statistics */

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticTotalBufferCount,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticFailedBufferCount,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticBufferUnderrunCount,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticTotalPacketCount,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticFailedPacketCount,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticResendRequestCount,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONGLONG.
            * Type for socket: ULONG.
            */
            StreamProperty_StatisticResendPacketCount,

            /* Common */

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONG.
            * Type for socket: ULONG.
            */
            StreamProperty_EnableResend,

            /**
            * Type for filter: ULONG.
            * Type for performance: not available.
            * Type for socket: ULONG.
            */
            StreamProperty_FrameRetentionMs,

            /**
            * Type for filter: ULONG.
            * Type for performance: ULONG.
            * Type for socket: ULONG.
            */
            StreamProperty_PacketTimeoutMs,

            /* Performance Driver */

            /**
            * Type for filter: not available.
            * Type for performance: ULONG.
            * Type for socket: not available.
            */
            StreamProperty_ResendThresholdAsPercentageOfHardwareWindow,

            /**
            * Type for filter: not available.
            * Type for performance: ULONG.
            * Type for socket: not available.
            */
            StreamProperty_AdditionalResendBatchingForThresholdResendsAspercentageOfThreshold,

            /**
            * Type for filter: not available.
            * Type for performance: ULONG.
            * Type for socket: not available.
            */
            StreamProperty_MissingPacketResendTimeoutInMilliseconds,

            /**
            * Type for filter: not available.
            * Type for performance: ULONG.
            * Type for socket: not available.
            */
            StreamProperty_ResendResponseTimeoutInMilliseconds,

            /**
            * Type for filter: not available.
            * Type for performance: ULONG.
            * Type for socket: not available.
            */
            StreamProperty_MaximumNumberResendRequestsPerPacket,

            /* Socket Driver */

            /**
            * Type for filter: not available.
            * Type for performance: not available.
            * Type for socket: UINT32.
            */
            StreamProperty_SocketBufferSize,

            /* Number of property elements */
            NumberOfStreamProperties
        };

        virtual GXSTATUS GetStreamProperty( EStreamPropertyItem streamProperty, uint32_t *uiValue ) = 0;
        virtual GXSTATUS GetStreamProperty( EStreamPropertyItem streamProperty, uint64_t *uiValue64 ) = 0;
        virtual GXSTATUS SetStreamProperty( EStreamPropertyItem streamProperty, uint32_t uiValue ) = 0;

        virtual void SetStream( Gx::StreamGrabber *pStreamGrabber ) = 0;

        // Create stream param helper
        static GX_API GXSTATUS GX_CALL Create(

            // The pointer to stream grabber for attach
            Gx::StreamGrabber *pStreamGrabber,

            /// Param Helper.
            /// Output parameter. Pointer to a ParamHelper pointer.
            Gx::StreamParamHelper **ppStreamParamHelper );
    };


    /// Force IP.
    /// Performs a Force IP request.
    GX_API GXSTATUS GX_CALL ForceIp(

        /// MAC Address.
        /// MAC address of the device to access.
        const uint8_t MacAddress[6],

        /// Static IP.
        /// Static IP address to force into the device.
        /// Only IPv4 addressing is supported currently. That means
        /// pStaticIp must reference a sockaddr_in and pStaticIp->sa_family
        /// must be equal AF_INET. Only the address component is evaluated.
        const sockaddr *pStaticIp,

        /// Static Subnet Mask.
        /// Subnet mask to use with the Static IP address.
        /// Only IPv4 addressing is supported currently. That means
        /// pStaticSubnetMask must reference a sockaddr_in and pStaticSubnetMask->sa_family
        /// must be equal AF_INET. Only the address component is evaluated.
        const sockaddr *pStaticSubnetMask,

        /// Static Default Gateway.
        /// Default gateway to use with the Static IP address.
        /// Only IPv4 addressing is supported currently. That means
        /// pStaticDefaultGateway must reference a sockaddr_in and pStaticDefaultGateway->sa_family
        /// must be equal AF_INET. Only the address component is evaluated.
        const sockaddr *pStaticDefaultGateway,

        /// Port.
        /// Port number to be used to issue the request. The GigE Vision
        /// standard port is used by default.
        uint16_t PortNr = 0
    );



    /// Test Packet.
    /// \return GX_OK - the test packet passed through,
    ///         GX_FALSE - the test packet wasn't received (completely)
    ///         other status code in case of errors.
    GX_API GXSTATUS GX_CALL TestPacket(

        /// Control Channel.
        /// Control Channel opened with control access privileges to the
        /// device to be tested.
        Gx::ControlChannel *pControlChannel,

        /// Stream Index.
        /// Index number of the stream to be tested
        uint32_t StreamIndex,

        /// Packet Size.
        /// GVSP packet size to be tested. This corresponds to the Ethernet payload size.
        uint16_t PacketSize,

        /// Adapter Address.
        /// Address of the adapter to be used during the test. Mainly this is
        /// the destination IP address of the  test packet. Currently only
        /// IPv4 addressing is supported. That means pAdapterAddr must reference
        /// a sockaddr_in and pAdapterAddr->sa_family must be equal AF_INET.
        /// Only the address part is evaluated currently . The port number
        /// must be held to 0.
        const sockaddr *pAdapterAddr
    );

    /// Probe a working packet size.
    /// post: a value for the packet size is set determined by probing or the default value is set
    /// \return GX_OK - a packets size has been probed and set,
    ///         GX_FALSE - no test packet was received (completely)
    ///         other status code in case of errors.
    GX_API GXSTATUS GX_CALL ProbeAWorkingPacketSize(

        /// Control Channel.
        /// Control Channel opened with control access privileges to the
        /// device to be tested.
        Gx::ControlChannel *pControlChannel,

        /// Timeout when waiting for test packets.
        uint32_t Timeout_ms,

        /// Stream Index.
        /// Index number of the stream to be tested.
        uint32_t StreamIndex,

        /// The count of test packets used for probing.
        uint32_t countOfTestPacketsSizes,

        /// The list of test packets used for probing. Sorted ascending. First value is default packet size.
        const uint16_t* pTestPacketSizes,

        /// Adapter Address.
        /// Address of the adapter to be used during the test. Mainly this is
        /// the destination IP address of the test packet. Currently only
        /// IPv4 addressing is supported. That means pAdapterAddr must reference
        /// a sockaddr_in and pAdapterAddr->sa_family must be equal AF_INET.
        /// Only the address part is evaluated currently . The port number
        /// must be held to 0.
        const sockaddr *pAdapterAddr,

        /// The last packet size for which a test packet has been successfully received.
        uint16_t* pLastSuccessfulPacketSize
    );


    /// Get Status Message.
    /// Retrieves a status message according a specific status value.
    ///
    /// \return
    ///     - GX_OK in case of success
    ///     - GX_E_INSUFFICIENT_BUFFER in case no or a too small buffer is supplied. Use
    ///                                this to query the required buffer size.
    ///     - other GX status code in case of serious errors.
    ///
    GX_API GXSTATUS GX_CALL
        GetStatusMessage(

            /// Status code to be translated into a message string
            GXSTATUS Status,

            /// Destination buffer of the message to be returned. If a NULL pointer is
            /// supplied, the size required for the entire message is returned by
            /// pnSizeRequired_chars.
            GXCHAR *Buffer,

            /// Size of message buffer (Buffer) in number of characters. If a
            /// size of zero is supplied, the size required for the entire
            /// message is returned by pSizeRequired_chars.
            size_t BufSize_chars,

            /// Size of returned message in number of characters. Or size of the
            /// entire message if no buffer or a buffer with zero size is supplied.
            size_t *pSizeRequired_chars
        );

    /// Set IP Configuration.
    /// Performs a Force IP request.
    GX_API GXSTATUS GX_CALL SetIpConfiguration(

        /// MAC Address.
        /// MAC address of the device to access.
        const uint8_t MacAddress[6],

        /// IP Configuration
        GEV_IP_CONFIG IpConfiguration,

        /// Static IP.
        /// Static IP address to force into the device.
        /// Only IPv4 addressing is supported currently. That means
        /// pStaticIp must reference a sockaddr_in and pStaticIp->sa_family
        /// must be equal AF_INET. Only the address component is evaluated.
        const sockaddr *pStaticIp,

        /// Static Subnet Mask.
        /// Subnet mask to use with the Static IP address.
        /// Only IPv4 addressing is supported currently. That means
        /// pStaticSubnetMask must reference a sockaddr_in and pStaticSubnetMask->sa_family
        /// must be equal AF_INET. Only the address component is evaluated.
        const sockaddr *pStaticSubnetMask,

        /// Static Default Gateway.
        /// Default gateway to use with the Static IP address.
        /// Only IPv4 addressing is supported currently. That means
        /// pStaticDefaultGateway must reference a sockaddr_in and pStaticDefaultGateway->sa_family
        /// must be equal AF_INET. Only the address component is evaluated.
        const sockaddr *pStaticDefaultGateway,

        /// User Defined Name
        const uint8_t UserDefinedName[16],

        bool Broadcast,
        uint32_t Timeout_ms

    );




    typedef uint32_t ACTIONGROUPKEY;
    typedef uint32_t DEVICEKEY;
    typedef uint32_t ACTIONGROUPMASK;

    typedef struct _ACTION_PARAMETER
    {
        uint32_t Length;                    // structure length in bytes
        DEVICEKEY DeviceKey;                // First required match. The Device key is a security feature. The device key is only known to the application. The Device Key cannot be read from the device.
        ACTIONGROUPKEY ActionGroupKey;      // Must match a group key stored in the device.
        ACTIONGROUPMASK ActionGroupMask;    // The logical And of ActionGroupMask and ActionGroupMask stored in the device must be larger that zero.
    } ACTION_PARAMETER, *PACTION_PARAMETER;

    typedef struct _SCHEDULED_ACTION_PARAMETER
    {
        uint32_t Length;                    // structure length in bytes
        DEVICEKEY DeviceKey;                // first required match; see also _ACTION_PARAMETER description
        ACTIONGROUPKEY ActionGroupKey;      // second required match; see also _ACTION_PARAMETER description
        ACTIONGROUPMASK ActionGroupMask;    // third required match; see also _ACTION_PARAMETER description
        uint64_t ExectuionTime;             // execution time in ns
    } SCHEDULED_ACTION_PARAMETER, *PSCHEDULED_ACTION_PARAMETER;


    typedef struct _GX_ACTION_RESULT
    {
        sockaddr_in DeviceAddr;
        GXSTATUS ActionStatus;
    } GX_ACTION_RESULT, *PGX_ACTION_RESULT;

    typedef enum _GX_ACTION_FLAG
    {
        GX_ACTION_FLAG_ACK = 1 << 0,
        GX_ACTION_FLAG_TIME = 1 << 7
    } GX_ACTION_FLAG;



    // Send a Scheduled Action command
    // Call returns after timeout ms or when pNumberExpectedReactions have been received by the host.
    // Returns gx status of the operation
    GX_API GXSTATUS GX_CALL SendScheduledActionCommand
    (

        /// Destination Address.
        /// [in] The destination IP address of the device.
        /// \note Only IPv4 addressing is supported currently.
        const sockaddr *pDestinationAddress,

        /// [in] Action specific parameter
        PSCHEDULED_ACTION_PARAMETER pParameter,

        /// [in] Time span in milliseconds before the operation is stopped and clean-up begins.
        uint32_t Timeout_ms,

        /// [in,out, opt] Number of expected reactions and number of elements provided
        /// in the array of elements.
        /// On success, the actual number of received reactions is returned.
        /// If no reactions are expected, because the acknowledge flag is cleared
        /// NULL may be passed.
        uint32_t* pNumberExpectedReactions,

        /// [out, opt] User provided array of reactions structures with at least pNumberExectedReactions elements.
        /// The first pNumberExpectedReactions elements are filled with data.
        /// Reactions of devices that do not support  ACTION_COMMANDs and send
        /// GEV_STATUS_NOT_IMPLEMENTED These replies are filtered out.
        /// Valid status values are:
        ///   GX_OK                      if the call could be issued successfully
        ///   GX_E_GV_STATUS_OVERFLOW    if scheduled action command and the action queue is full, command has been discarded
        ///   GX_E_GV_STATUS_NO_REF_TIME if scheduled action command and device is not synchronized, command has been ignored
        ///   GX_E_GV_STATUS_ACTION_LATE if scheduled action command and the time tag is in the past, command has been executed immediately
        GX_ACTION_RESULT Reactions[]

    );

    // Send an Action command
    // see SendScheduledActionCommand for more info
    GX_API GXSTATUS GX_CALL SendActionCommand(
        const sockaddr *pDestinationAddress,
        const PACTION_PARAMETER  pParameter,
        uint32_t Timeout_ms,
        uint32_t* pNumberExpectedReactions,
        GX_ACTION_RESULT Reactions[]
    );

    // \}

}

/*@}*/


#endif /* ifdef GXAPI_H_INCLUDED */
