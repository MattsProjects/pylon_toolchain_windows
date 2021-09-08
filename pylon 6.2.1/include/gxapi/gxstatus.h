//----------------------------------------------------------------------------
// GX macro definitions
//----------------------------------------------------------------------------

/**
 * GX Status.
 * Data type for representing status and error codes.
 */
typedef uint32_t GXSTATUS;



/**
 * GX Severity.
 * Macro extracting the severity from a given GXSTATUS value.
 */
#define GX_SEVERITY(_s_)     (((_s_) >> 30) & 0x3)



/**
 * GX Facility.
 * Macro extracting the facility from a given GXSTATUS value.
 */
#define GX_FACILITY(_s_)     (((_s_) >> 16) & 0xfff)



/**
 * GX Error Code.
 * Macro extracting the intrinsic error code from a given GXSTATUS value.
 */
#define GX_ERRORCODE(_s_)    ((uint16_t)((_s_) & 0xffff))



/**
 * GX Success.
 * Checks whether the GX Status code represents a successful operation.
 * \todo Allow status codes with severity 'Information' to be success?
 */
#define GX_SUCCESS(_s_) ((GXSTATUS)(_s_) == GX_OK)



/**
 * GX Information.
 * Checks whether the GX Status code represents informational success status.
 */
#define GX_INFORMATION(_s_) (GX_SEVERITY(_s_) == GX_STATUS_SEVERITY_INFORMATIONAL)



/**
 * GX Warning.
 * Checks whether the GX Status code represents a warning.
 */
#define GX_WARNING(_s_) (GX_SEVERITY(_s_) == GX_STATUS_SEVERITY_WARNING)



/**
 * GX Error.
 * Checks whether the GX Status code represents an error.
 */
#define GX_ERROR(_s_) (GX_SEVERITY(_s_) == GX_STATUS_SEVERITY_ERROR)



#define GX_OK (GXSTATUS)0



//----------------------------------------------------------------------------
// GX_STATUS_FACILITY_GX
//----------------------------------------------------------------------------
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define GX_STATUS_FACILITY_GX            0x100
#define GX_STATUS_FACILITY_GEV           0x101
#define GX_STATUS_FACILITY_ERRNO         0x102
#define GX_STATUS_FACILITY_GVSP          0x108


//
// Define the severity codes
//
#define GX_STATUS_SEVERITY_SUCCESS       0x0
#define GX_STATUS_SEVERITY_INFORMATIONAL 0x1
#define GX_STATUS_SEVERITY_WARNING       0x2
#define GX_STATUS_SEVERITY_ERROR         0x3


//
// MessageId: GX_E_FALSE
//
// MessageText:
//
// False.%0
//
#define GX_E_FALSE                       ((GXSTATUS)0x21000001L)

//
// MessageId: GX_E_OUT_OF_MEMORY
//
// MessageText:
//
// Response header not completely supplied.%0
//
#define GX_E_OUT_OF_MEMORY               ((GXSTATUS)0xE1000002L)

//
// MessageId: GX_E_OPERATION_ABORTED
//
// MessageText:
//
// The operation was aborted.%0
//
#define GX_E_OPERATION_ABORTED           ((GXSTATUS)0xE1000003L)

//
// MessageId: GX_E_NOT_IMPLEMENTED
//
// MessageText:
//
// Function not implemented.%0
//
#define GX_E_NOT_IMPLEMENTED             ((GXSTATUS)0xE1000004L)

//
// MessageId: GX_E_INVALID_PORT
//
// MessageText:
//
// Invalid Port.%0
//
#define GX_E_INVALID_PORT                ((GXSTATUS)0xE1000005L)

//
// MessageId: GX_E_INVALID_PARAMETER
//
// MessageText:
//
// Invalid Parameter.%0
//
#define GX_E_INVALID_PARAMETER           ((GXSTATUS)0xE1000006L)

//
// MessageId: GX_E_TIMEOUT
//
// MessageText:
//
// The requested operation timed out.%0
//
#define GX_E_TIMEOUT                     ((GXSTATUS)0xE1000007L)

//
// MessageId: GX_E_IO_COMPLETION
//
// MessageText:
//
// The wait was ended by one or more asynchronous callbacks.%0
//
#define GX_E_IO_COMPLETION               ((GXSTATUS)0xE1000008L)

//
// MessageId: GX_E_ONLY_IPV4_SUPPORTED
//
// MessageText:
//
// Currently only IPv4 addressing is supported.%0
//
#define GX_E_ONLY_IPV4_SUPPORTED         ((GXSTATUS)0xE1000009L)

//
// MessageId: GX_E_INSUFFICIENT_RESPONSE_SIZE
//
// MessageText:
//
// Response header not completely supplied.%0
//
#define GX_E_INSUFFICIENT_RESPONSE_SIZE  ((GXSTATUS)0xE100000AL)

//
// MessageId: GX_E_UNEXPECTED_RESPONSE
//
// MessageText:
//
// An unexpected response was encountered for the initiated transaction.%0
//
#define GX_E_UNEXPECTED_RESPONSE         ((GXSTATUS)0xE100000BL)

//
// MessageId: GX_E_UNEXPECTED_RESPONSE_SIZE
//
// MessageText:
//
// Requested data not completely supplied.%0
//
#define GX_E_UNEXPECTED_RESPONSE_SIZE    ((GXSTATUS)0xE100000CL)

//
// MessageId: GX_E_INSUFFICIENT_BUFFER
//
// MessageText:
//
// Requested data not completely supplied.%0
//
#define GX_E_INSUFFICIENT_BUFFER         ((GXSTATUS)0xE100000DL)

//
// MessageId: GX_E_STREAM_EXHAUSTED
//
// MessageText:
//
// The maximum number of streams implemented by the server is already open.%0
//
#define GX_E_STREAM_EXHAUSTED            ((GXSTATUS)0xE100000EL)

//
// MessageId: GX_E_STREAM_NOT_OPEN
//
// MessageText:
//
// The stream wasn't opened previously.%0
//
#define GX_E_STREAM_NOT_OPEN             ((GXSTATUS)0xE100000FL)

//
// MessageId: GX_E_SERVER_NO_CONNECTION
//
// MessageText:
//
// Connection cannot be established.%0
//
#define GX_E_SERVER_NO_CONNECTION        ((GXSTATUS)0xE1000010L)

//
// MessageId: GX_E_SERVER_STREAM_NOT_CONNECTED
//
// MessageText:
//
// The supplied stream is not connected.%0
//
#define GX_E_SERVER_STREAM_NOT_CONNECTED ((GXSTATUS)0xE1000011L)

//
// MessageId: GX_E_REGISTER_BAD_ALIGNMENT
//
// MessageText:
//
// An attempt was made to access registers with bad address or size alignment.%0
//
#define GX_E_REGISTER_BAD_ALIGNMENT      ((GXSTATUS)0xE1000012L)

//
// MessageId: GX_E_FATAL
//
// MessageText:
//
// A fatal internal error occurred.%0
//
#define GX_E_FATAL                       ((GXSTATUS)0xE1000013L)

//
// MessageId: GX_E_BUFFER_INCOMPLETE
//
// MessageText:
//
// The buffer was incompletely grabbed. This can be caused by performance problems of the network hardware used, i.e. network adapter, switch, or ethernet cable. To fix this, try increasing the camera's Inter-Packet Delay in the Transport Layer category to reduce the required bandwidth, and adjust the camera's Packet Size setting to the highest supported frame size.%0
//
#define GX_E_BUFFER_INCOMPLETE           ((GXSTATUS)0xE1000014L)

//
// MessageId: GX_E_BUFFER_OVERFLOW
//
// MessageText:
//
// Internal buffer overflow.%0
//
#define GX_E_BUFFER_OVERFLOW             ((GXSTATUS)0xE1000015L)

//
// MessageId: GX_E_CONTROL_CHANNEL_DISCONNECTED
//
// MessageText:
//
// The control channel is already disconnected.%0
//
#define GX_E_CONTROL_CHANNEL_DISCONNECTED ((GXSTATUS)0xE1000016L)

//
// MessageId: GX_E_BUFFER_CANCELLED
//
// MessageText:
//
// The buffer was cancelled.%0
//
#define GX_E_BUFFER_CANCELLED            ((GXSTATUS)0xE1000017L)

//
// MessageId: GX_E_HEARTBEAT_TIMEOUT_TOO_SMALL
//
// MessageText:
//
// An attempt was made to set a too small heartbeat timeout.%0
//
#define GX_E_HEARTBEAT_TIMEOUT_TOO_SMALL ((GXSTATUS)0xE1000018L)

//
// MessageId: GX_E_NO_SUITABLE_STREAM_GRABBER_FOUND
//
// MessageText:
//
// No suitable stream grabber found.%0
//
#define GX_E_NO_SUITABLE_STREAM_GRABBER_FOUND ((GXSTATUS)0xE1000019L)

//
// MessageId: GX_E_DEVICE_SUPPORTS_NO_MESSAGE_CHANNEL
//
// MessageText:
//
// Device supports no message channel.%0
//
#define GX_E_DEVICE_SUPPORTS_NO_MESSAGE_CHANNEL ((GXSTATUS)0xE100001AL)

//
// MessageId: GX_E_BUFFER_NO_LENGTHS
//
// MessageText:
//
// Failed to deduce the buffer segment lengths from leader and trailer information because of insufficient buffer sizes.%0
//
#define GX_E_BUFFER_NO_LENGTHS           ((GXSTATUS)0xE100001BL)

//
// MessageId: GX_E_BUFFER_UNKNOWN_FORMAT
//
// MessageText:
//
// Failed to deduce the buffer segment lengths from leader and trailer information because of an unknown data format.%0
//
#define GX_E_BUFFER_UNKNOWN_FORMAT       ((GXSTATUS)0xE100001CL)

//
// MessageId: GX_E_INSUFFICIENT_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the API.%0
//
#define GX_E_INSUFFICIENT_RESOURCES      ((GXSTATUS)0xE100001DL)

//
// MessageId: GX_E_UNINTIALIZED
//
// MessageText:
//
// Uninitialized status%0
//
#define GX_E_UNINTIALIZED                ((GXSTATUS)0xE100001EL)

//----------------------------------------------------------------------------
// GX_STATUS_FACILITY_GEV
//----------------------------------------------------------------------------
//
// MessageId: GX_E_STATUS_GV_NOT_IMPLEMENTED
//
// MessageText:
//
// The command isn't implemented by the device.%0
//
#define GX_E_STATUS_GV_NOT_IMPLEMENTED   ((GXSTATUS)0xE1018001L)

//
// MessageId: GX_E_GV_STATUS_INVALID_PARAMETER
//
// MessageText:
//
// An invalid parameter is reported by the device.%0
//
#define GX_E_GV_STATUS_INVALID_PARAMETER ((GXSTATUS)0xE1018002L)

//
// MessageId: GX_E_GV_STATUS_INVALID_ADDRESS
//
// MessageText:
//
// An attempt was made to access a nonexistent address space location.%0
//
#define GX_E_GV_STATUS_INVALID_ADDRESS   ((GXSTATUS)0xE1018003L)

//
// MessageId: GX_E_GV_STATUS_WRITE_PROTECT
//
// MessageText:
//
// The addressed register cannot be written to.%0
//
#define GX_E_GV_STATUS_WRITE_PROTECT     ((GXSTATUS)0xE1018004L)

//
// MessageId: GX_E_GV_STATUS_BAD_ALIGNMENT
//
// MessageText:
//
// A badly aligned address offset or data size was specified.%0
//
#define GX_E_GV_STATUS_BAD_ALIGNMENT     ((GXSTATUS)0xE1018005L)

//
// MessageId: GX_E_GV_STATUS_ACCESS_DENIED
//
// MessageText:
//
// An attempt was made to access an address location which is currently/momentary not accessible.%0
//
#define GX_E_GV_STATUS_ACCESS_DENIED     ((GXSTATUS)0xE1018006L)

//
// MessageId: GX_E_GV_STATUS_BUSY
//
// MessageText:
//
// A required resource to service the request is currently not available. The request may be retried.%0
//
#define GX_E_GV_STATUS_BUSY              ((GXSTATUS)0xE1018007L)

//
// MessageId: GX_E_GV_STATUS_LOCAL_PROBLEM
//
// MessageText:
//
// An internal problem in the device implementation occurred while processing the request.%0
//
#define GX_E_GV_STATUS_LOCAL_PROBLEM     ((GXSTATUS)0xE1018008L)

//
// MessageId: GX_E_GV_STATUS_MSG_MISMATCH
//
// MessageText:
//
// Message mismatch (request and acknowledge don't match).%0
//
#define GX_E_GV_STATUS_MSG_MISMATCH      ((GXSTATUS)0xE1018009L)

//
// MessageId: GX_E_GV_STATUS_INVALID_PROTOCOL
//
// MessageText:
//
// This version of the GVCP protocol is not supported.%0
//
#define GX_E_GV_STATUS_INVALID_PROTOCOL  ((GXSTATUS)0xE101800AL)

//
// MessageId: GX_E_GV_STATUS_NO_MSG
//
// MessageText:
//
// Timeout, no message received.%0
//
#define GX_E_GV_STATUS_NO_MSG            ((GXSTATUS)0xE101800BL)

//
// MessageId: GX_E_GV_STATUS_PACKET_UNAVAILABLE
//
// MessageText:
//
// The request packet is not available anymore.%0
//
#define GX_E_GV_STATUS_PACKET_UNAVAILABLE ((GXSTATUS)0xE101800CL)

//
// MessageId: GX_E_GV_STATUS_DATA_OVERRUN
//
// MessageText:
//
// Internal memory of device overrun (typically for image acquisition).%0
//
#define GX_E_GV_STATUS_DATA_OVERRUN      ((GXSTATUS)0xE101800DL)

//
// MessageId: GX_E_GV_STATUS_INVALID_HEADER
//
// MessageText:
//
// The message header is not valid. Some of its fields do not match the specification.%0
//
#define GX_E_GV_STATUS_INVALID_HEADER    ((GXSTATUS)0xE101800EL)

//
// MessageId: GX_E_GV_STATUS_NO_REF_TIME
//
// MessageText:
//
// The device is not synchronized to a master clock to be used as time reference.%0
//
#define GX_E_GV_STATUS_NO_REF_TIME       ((GXSTATUS)0xE1018013L)

//
// MessageId: GX_E_GV_STATUS_OVERFLOW
//
// MessageText:
//
// A device queue or packet data has overflowed.%0
//
#define GX_E_GV_STATUS_OVERFLOW          ((GXSTATUS)0xE1018015L)

//
// MessageId: GX_E_GV_STATUS_ACTION_LATE
//
// MessageText:
//
// The requested scheduled action command was requested at a time that is already past. Action is executed anyway.%0
//
#define GX_E_GV_STATUS_ACTION_LATE       ((GXSTATUS)0xE1018016L)

//
// MessageId: GX_E_GV_STATUS_ERROR
//
// MessageText:
//
// Generic GigE Vision error.%0
//
#define GX_E_GV_STATUS_ERROR             ((GXSTATUS)0xE1018FFFL)

