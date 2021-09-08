//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2015 Basler
//-----------------------------------------------------------------------------
/*
 * UXAPI error codes
 */

#include "UxTypes.h"
#ifdef _WIN32
    #include <uxdrv/uxdrvstatus.h>
#endif

//----------------------------------------------------------------------------
// UXAPI error macro definitions
//----------------------------------------------------------------------------



/**
 * UX Severity.
 * Macro extracting the severity from a given UXSTATUS value.
 */
#define UX_SEVERITY(_s_)     (((_s_) >> 30) & 0x3)



/**
 * UX Facility.
 * Macro extracting the facility from a given UXSTATUS value.
 */
#define UX_FACILITY(_s_)     (((_s_) >> 16) & 0xfff)



/**
 * UX Error Code.
 * Macro extracting the intrinsic error code from a given UXSTATUS value.
 */
#define UX_ERRORCODE(_s_)    ((uint16_t)((_s_) & 0xffff))



/**
 * UX Success.
 * Checks whether the UX Status code represents a successful operation.
 * \todo Allow status codes with severity 'Information' to be success?
 */
#define UX_SUCCESS(_s_) ((UXSTATUS)(_s_) == UX_OK)



/**
 * UX Information.
 * Checks whether the UX Status code represents informational success status.
 */
#define UX_INFORMATION(_s_) (UX_SEVERITY(_s_) == UX_STATUS_SEVERITY_INFORMATIONAL)



/**
 * UX Warning.
 * Checks whether the UX Status code represents a warning.
 */
#define UX_WARNING(_s_) (UX_SEVERITY(_s_) == UX_STATUS_SEVERITY_WARNING)



/**
 * UX Error.
 * Checks whether the UX Status code represents an error.
 */
#define UX_ERROR(_s_) (UX_SEVERITY(_s_) == UX_STATUS_SEVERITY_ERROR)



#define UX_OK (UXSTATUS)0



//----------------------------------------------------------------------------
// UX_STATUS_FACILITY_UX
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
#define UX_STATUS_FACILITY_UX            0x200
#define UX_STATUS_FACILITY_LIBUSB        0x210


//
// Define the severity codes
//
#define UX_STATUS_SEVERITY_WARNING       0x2
#define UX_STATUS_SEVERITY_SUCCESS       0x0
#define UX_STATUS_SEVERITY_INFORMATIONAL 0x1
#define UX_STATUS_SEVERITY_ERROR         0x3


//
// MessageId: UX_E_FATAL
//
// MessageText:
//
// A fatal internal error occurred.%0
//
#define UX_E_FATAL                       ((UXSTATUS)0xE2000001L)

//
// MessageId: UX_E_NOT_FOUND
//
// MessageText:
//
// The specified item does not exist.%0
//
#define UX_E_NOT_FOUND                   ((UXSTATUS)0xE2000002L)

//
// MessageId: UX_E_UNKNOWN
//
// MessageText:
//
// Unknown error.%0
//
#define UX_E_UNKNOWN                     ((UXSTATUS)0xE2000003L)

//
// MessageId: UX_E_OUT_OF_MEMORY
//
// MessageText:
//
// Response header not completely supplied.%0
//
#define UX_E_OUT_OF_MEMORY               ((UXSTATUS)0xE2000004L)

//
// MessageId: UX_E_OPERATION_ABORTED
//
// MessageText:
//
// The operation was aborted.%0
//
#define UX_E_OPERATION_ABORTED           ((UXSTATUS)0xE2000005L)

//
// MessageId: UX_E_OPERATION_FAILED
//
// MessageText:
//
// The operation failed.%0
//
#define UX_E_OPERATION_FAILED            ((UXSTATUS)0xE2000006L)

//
// MessageId: UX_E_NOT_IMPLEMENTED
//
// MessageText:
//
// Function not implemented.%0
//
#define UX_E_NOT_IMPLEMENTED             ((UXSTATUS)0xE2000007L)

//
// MessageId: UX_E_INVALID_PARAMETER
//
// MessageText:
//
// An invalid parameter has been passed.%0
//
#define UX_E_INVALID_PARAMETER           ((UXSTATUS)0xE2000008L)

//
// MessageId: UX_E_TIMEOUT
//
// MessageText:
//
// The requested operation timed out.%0
//
#define UX_E_TIMEOUT                     ((UXSTATUS)0xE2000009L)

//
// MessageId: UX_E_INSUFFICIENT_RESPONSE_SIZE
//
// MessageText:
//
// Response header not completely supplied.%0
//
#define UX_E_INSUFFICIENT_RESPONSE_SIZE  ((UXSTATUS)0xE200000AL)

//
// MessageId: UX_E_INSUFFICIENT_BUFFER
//
// MessageText:
//
// The provided buffer is too small.%0
//
#define UX_E_INSUFFICIENT_BUFFER         ((UXSTATUS)0xE200000BL)

//
// MessageId: UX_E_DEVICE_NOT_FOUND
//
// MessageText:
//
// Device not found.%0
//
#define UX_E_DEVICE_NOT_FOUND            ((UXSTATUS)0xE200000CL)

//
// MessageId: UX_E_DEVICE_NOT_OPEN
//
// MessageText:
//
// Device not open.%0
//
#define UX_E_DEVICE_NOT_OPEN             ((UXSTATUS)0xE200000DL)

//
// MessageId: UX_E_DEVICE_ALREADY_OPEN
//
// MessageText:
//
// Device is already open.%0
//
#define UX_E_DEVICE_ALREADY_OPEN         ((UXSTATUS)0xE200000EL)

//
// MessageId: UX_E_DEVICE_HAS_BEEN_REMOVED
//
// MessageText:
//
// Device has been removed from the PC.%0
//
#define UX_E_DEVICE_HAS_BEEN_REMOVED     ((UXSTATUS)0xE200000FL)

//
// MessageId: UX_E_WRITE_FAILED
//
// MessageText:
//
// Write operation failed.%0
//
#define UX_E_WRITE_FAILED                ((UXSTATUS)0xE2000010L)

//
// MessageId: UX_E_READ_FAILED
//
// MessageText:
//
// Read operation failed.%0
//
#define UX_E_READ_FAILED                 ((UXSTATUS)0xE2000011L)

//
// MessageId: UX_E_BUFFER_OVERFLOW
//
// MessageText:
//
// Internal buffer overflow.%0
//
#define UX_E_BUFFER_OVERFLOW             ((UXSTATUS)0xE2000012L)

//
// MessageId: UX_E_INSUFFICIENT_RESOURCES
//
// MessageText:
//
// Insufficient system resources exist to complete the API.%0
//
#define UX_E_INSUFFICIENT_RESOURCES      ((UXSTATUS)0xE2000013L)

//
// MessageId: UX_E_OBJECT_NOT_FOUND
//
// MessageText:
//
// The requested object was not available.%0
//
#define UX_E_OBJECT_NOT_FOUND            ((UXSTATUS)0xE2000014L)

//
// MessageId: UX_E_READ_CAPABILITY_FAILED
//
// MessageText:
//
// Failed to read the device capability register.%0
//
#define UX_E_READ_CAPABILITY_FAILED      ((UXSTATUS)0xE2000015L)

//
// MessageId: UX_E_READ_MAXIMUM_DEVICE_RESPONSE_TIME_FAILED
//
// MessageText:
//
// Failed to read the maximum device response time register.%0
//
#define UX_E_READ_MAXIMUM_DEVICE_RESPONSE_TIME_FAILED ((UXSTATUS)0xE2000016L)

//
// MessageId: UX_E_NOT_INITIALIZED
//
// MessageText:
//
// Library or object not initialized. Call the appropriate initialization function first.%0
//
#define UX_E_NOT_INITIALIZED             ((UXSTATUS)0xE2000017L)

//
// MessageId: UX_E_CALLBACK_ALREADY_REGISTERED
//
// MessageText:
//
// An attempt to register a callback failed, because there is currently a callback registered.%0
//
#define UX_E_CALLBACK_ALREADY_REGISTERED ((UXSTATUS)0xE2000018L)

//
// MessageId: UX_E_DEVICE_IN_USE
//
// MessageText:
//
// Device is exclusively opened by another client.%0
//
#define UX_E_DEVICE_IN_USE               ((UXSTATUS)0xE2000019L)

// -----------------------------------------------------------------------------------------
// stream related errors
// -----------------------------------------------------------------------------------------
//
// MessageId: UX_E_STREAM_ALREADY_CREATED
//
// MessageText:
//
// There is already a stream. %0
//
#define UX_E_STREAM_ALREADY_CREATED      ((UXSTATUS)0xE2000100L)

//
// MessageId: UX_E_INVALID_STREAM_STATE
//
// MessageText:
//
// Invalid state.%0
//
#define UX_E_INVALID_STREAM_STATE        ((UXSTATUS)0xE2000101L)

//
// MessageId: UX_E_BUFFER_CANCELLED
//
// MessageText:
//
// The buffer was cancelled.%0
//
#define UX_E_BUFFER_CANCELLED            ((UXSTATUS)0xE2000102L)

//
// MessageId: UX_E_UNEXPECTED_CANCEL
//
// MessageText:
//
// The buffer was cancelled unexpectedly.%0
//
#define UX_E_UNEXPECTED_CANCEL           ((UXSTATUS)0xE2000103L)

//
// MessageId: UX_E_BUFFER_ALREADY_REGISTERED
//
// MessageText:
//
// The buffer is already registered.%0
//
#define UX_E_BUFFER_ALREADY_REGISTERED   ((UXSTATUS)0xE2000104L)

//
// MessageId: UX_E_INVALID_BUFFER_HANDLE
//
// MessageText:
//
// Invalid buffer handle.%0
//
#define UX_E_INVALID_BUFFER_HANDLE       ((UXSTATUS)0xE2000105L)

//
// MessageId: UX_E_NO_BUFFER_AVAILABLE
//
// MessageText:
//
// No buffer available.%0
//
#define UX_E_NO_BUFFER_AVAILABLE         ((UXSTATUS)0xE2000106L)

//
// MessageId: UX_E_BUFFER_STILL_QUEUED
//
// MessageText:
//
// Buffer is still queued.%0
//
#define UX_E_BUFFER_STILL_QUEUED         ((UXSTATUS)0xE2000107L)

//
// MessageId: UX_E_BUFFER_ALREADY_QUEUED
//
// MessageText:
//
// Buffer is already queued.%0
//
#define UX_E_BUFFER_ALREADY_QUEUED       ((UXSTATUS)0xE2000108L)

//
// MessageId: UX_E_NO_IMAGE_DATA_ENDPOINT
//
// MessageText:
//
// The device doesn't provide an endpoint for image data.%0
//
#define UX_E_NO_IMAGE_DATA_ENDPOINT      ((UXSTATUS)0xE2000109L)

//
// MessageId: UX_E_BUFFER_INCOMPLETE
//
// MessageText:
//
// The buffer was incompletely grabbed.%0
//
#define UX_E_BUFFER_INCOMPLETE           ((UXSTATUS)0xE200010AL)

//
// MessageId: UX_E_IMAGE_STREAM_OUT_OF_SYNC
//
// MessageText:
//
// The image stream is out of sync.%0
//
#define UX_E_IMAGE_STREAM_OUT_OF_SYNC    ((UXSTATUS)0xE200010BL)

//
// MessageId: UX_E_INVALID_BUFFER_STATE
//
// MessageText:
//
// Invalid buffer state.%0
//
#define UX_E_INVALID_BUFFER_STATE        ((UXSTATUS)0xE200010CL)

//
// MessageId: UX_E_INTERNAL_STREAM_ERROR
//
// MessageText:
//
// Invalid buffer state.%0
//
#define UX_E_INTERNAL_STREAM_ERROR       ((UXSTATUS)0xE200010DL)

//
// MessageId: UX_E_STREAMING_NOT_SUPPORTED
//
// MessageText:
//
// The device does not support streaming.%0
//
#define UX_E_STREAMING_NOT_SUPPORTED     ((UXSTATUS)0xE200010EL)

//
// MessageId: UX_E_EVENTS_NOT_SUPPORTED
//
// MessageText:
//
// The device does not support events.%0
//
#define UX_E_EVENTS_NOT_SUPPORTED        ((UXSTATUS)0xE200010FL)

//
// MessageId: UX_E_LEADER_TRAILER_BLOCKID_MISMATCH
//
// MessageText:
//
// The block IDs in leader and trailer are not equal.%0
//
#define UX_E_LEADER_TRAILER_BLOCKID_MISMATCH ((UXSTATUS)0xE2000110L)

//
// MessageId: UX_E_BLOCKID_TOO_SMALL
//
// MessageText:
//
// The current block ID must be larger than the previous block ID.%0
//
#define UX_E_BLOCKID_TOO_SMALL           ((UXSTATUS)0xE2000111L)

//
// MessageId: UX_E_PAYLOAD_TOO_SMALL
//
// MessageText:
//
// The count of received payload bytes is smaller than the payload size reported in trailer.%0
//
#define UX_E_PAYLOAD_TOO_SMALL           ((UXSTATUS)0xE2000112L)

//
// MessageId: UX_E_BLOCK_WITH_UNKNOWN_STATUS
//
// MessageText:
//
// The status field in trailer contains an unknown value.%0
//
#define UX_E_BLOCK_WITH_UNKNOWN_STATUS   ((UXSTATUS)0xE2000113L)

//
// MessageId: UX_E_NO_U3V_DEVICE
//
// MessageText:
//
// Device is not an U3V device.%0
//
#define UX_E_NO_U3V_DEVICE               ((UXSTATUS)0xE2000114L)

//
// MessageId: UX_E_NO_USB2_SUPPORT
//
// MessageText:
//
// The device cannot be operated on an USB 2.0 port. The device requires an USB 3.0 compatible port.%0
//
#define UX_E_NO_USB2_SUPPORT             ((UXSTATUS)0xE2000115L)

//
// MessageId: UX_E_PAYLOAD_OR_TRAILER_TIMEOUT
//
// MessageText:
//
// A payload or trailer transfer timed out.%0
//
#define UX_E_PAYLOAD_OR_TRAILER_TIMEOUT  ((UXSTATUS)0xE2000116L)

// -----------------------------------------------------------------------------------------
// control protocol related errors
// -----------------------------------------------------------------------------------------
//
// MessageId: UX_E_GENCP_GENERIC
//
// MessageText:
//
// Generic error occurred.%0
//
#define UX_E_GENCP_GENERIC               ((UXSTATUS)0xE2000200L)

//
// MessageId: UX_E_GENCP_XACT_ABORT
//
// MessageText:
//
// Transaction aborted.%0
//
#define UX_E_GENCP_XACT_ABORT            ((UXSTATUS)0xE2000201L)

//
// MessageId: UX_E_GENCP_NACK
//
// MessageText:
//
// Command not accepted.%0
//
#define UX_E_GENCP_NACK                  ((UXSTATUS)0xE2000202L)

//
// MessageId: UX_E_GENCP_WRITE_INCOMPLETE
//
// MessageText:
//
// Wrote less data than requested.%0
//
#define UX_E_GENCP_WRITE_INCOMPLETE      ((UXSTATUS)0xE2000203L)

//
// MessageId: UX_E_GENCP_NOT_IMPLEMENTED
//
// MessageText:
//
// Command not implemented in the device.%0
//
#define UX_E_GENCP_NOT_IMPLEMENTED       ((UXSTATUS)0xE2000204L)

//
// MessageId: UX_E_GENCP_INVALID_PARAMETER
//
// MessageText:
//
// At least one command parameter is invalid or out of range.%0
//
#define UX_E_GENCP_INVALID_PARAMETER     ((UXSTATUS)0xE2000205L)

//
// MessageId: UX_E_GENCP_INVALID_ADDRESS
//
// MessageText:
//
// Attempt to access a not existing register address.%0
//
#define UX_E_GENCP_INVALID_ADDRESS       ((UXSTATUS)0xE2000206L)

//
// MessageId: UX_E_GENCP_WRITE_PROTECT
//
// MessageText:
//
// Attempt to write to a read only register.%0
//
#define UX_E_GENCP_WRITE_PROTECT         ((UXSTATUS)0xE2000207L)

//
// MessageId: UX_E_GENCP_BAD_ALIGNMENT
//
// MessageText:
//
// Attempt to access registers with an address which is not aligned according to the underlying technology.%0
//
#define UX_E_GENCP_BAD_ALIGNMENT         ((UXSTATUS)0xE2000208L)

//
// MessageId: UX_E_GENCP_ACCESS_DENIED
//
// MessageText:
//
// Attempt to access a currently not supported register space.%0
//
#define UX_E_GENCP_ACCESS_DENIED         ((UXSTATUS)0xE2000209L)

//
// MessageId: UX_E_GENCP_BUSY
//
// MessageText:
//
// The command receiver is currently busy.%0
//
#define UX_E_GENCP_BUSY                  ((UXSTATUS)0xE200020AL)

//
// MessageId: UX_E_GENCP_MSG_TIMEOUT
//
// MessageText:
//
// Timeout waiting for an acknowledgement.%0
//
#define UX_E_GENCP_MSG_TIMEOUT           ((UXSTATUS)0xE200020BL)

//
// MessageId: UX_E_GENCP_INVALID_HEADER
//
// MessageText:
//
// The header of the received command is invalid.%0
//
#define UX_E_GENCP_INVALID_HEADER        ((UXSTATUS)0xE200020CL)

//
// MessageId: UX_E_GENCP_WRONG_CONFIG
//
// MessageText:
//
// The current receiver information does not allow the execution of the sent command.%0
//
#define UX_E_GENCP_WRONG_CONFIG          ((UXSTATUS)0xE200020DL)

//
// MessageId: UX_E_U3V_RESEND_NOT_SUPPORTED
//
// MessageText:
//
// The U3V protocol does not support resends.%0
//
#define UX_E_U3V_RESEND_NOT_SUPPORTED    ((UXSTATUS)0xE200020EL)

//
// MessageId: UX_E_U3V_DSI_ENDPOINT_HALTED
//
// MessageText:
//
// The endpoint of the Device Streaming Interface is halted.%0
//
#define UX_E_U3V_DSI_ENDPOINT_HALTED     ((UXSTATUS)0xE200020FL)

//
// MessageId: UX_E_U3V_SI_PAYLOAD_SIZE_NOT_ALIGNED
//
// MessageText:
//
// The value written to the SI streaming size registers is not aligned according to the Payload Size Alignment value of the SI Info register.%0
//
#define UX_E_U3V_SI_PAYLOAD_SIZE_NOT_ALIGNED ((UXSTATUS)0xE2000210L)

//
// MessageId: UX_E_U3V_SI_REGISTERS_INCONSISTENT
//
// MessageText:
//
// Values within the stream interface registers are not consistent or valid.%0
//
#define UX_E_U3V_SI_REGISTERS_INCONSISTENT ((UXSTATUS)0xE2000211L)

//
// MessageId: UX_E_U3V_DATA_DISCARDED
//
// MessageText:
//
// Payload data has been discarded. Payload data can be discarded by the camera device if the available bandwidth is insufficient.%0
//
#define UX_E_U3V_DATA_DISCARDED          ((UXSTATUS)0xE2000212L)

//
// MessageId: UX_E_GENCP_ERROR
//
// MessageText:
//
// Generic error.%0
//
#define UX_E_GENCP_ERROR                 ((UXSTATUS)0xE2000213L)

//
// MessageId: UX_E_GENCP_FATAL
//
// MessageText:
//
// Fatal error.%0
//
#define UX_E_GENCP_FATAL                 ((UXSTATUS)0xE20002FFL)

// -----------------------------------------------------------------------------------------
// other errors
// -----------------------------------------------------------------------------------------
//
// MessageId: UX_W_DEVICEPATH_NOT_VALID
//
// MessageText:
//
// Device instance path is not valid.%0
//
#define UX_W_DEVICEPATH_NOT_VALID        ((UXSTATUS)0xA2000300L)

//
// MessageId: UX_W_SUITABLE_USB_DRIVER_NOT_PRESENT
//
// MessageText:
//
// Suitable USB driver is not present.%0
//
#define UX_W_SUITABLE_USB_DRIVER_NOT_PRESENT ((UXSTATUS)0xA2000301L)

//
// MessageId: UX_E_ROOTHUBNAME_NOT_VALID
//
// MessageText:
//
// The root hub name is not valid. The device or driver is not working properly.%0
//
#define UX_E_ROOTHUBNAME_NOT_VALID       ((UXSTATUS)0xE2000302L)

//
// MessageId: UX_W_DEVICE_INSTANCE_ID_NOT_VALID
//
// MessageText:
//
// Device path identifier is not valid.%0
//
#define UX_W_DEVICE_INSTANCE_ID_NOT_VALID ((UXSTATUS)0xA2000303L)

//
// MessageId: UX_W_DEVICE_REGISTRY_PROPERTIES_NOT_VALID
//
// MessageText:
//
// Device registry properties not valid.%0
//
#define UX_W_DEVICE_REGISTRY_PROPERTIES_NOT_VALID ((UXSTATUS)0xA2000304L)

//
// MessageId: UX_W_USB_CONTROLLER_INFO_NOT_VALID
//
// MessageText:
//
// USB controller info not valid.%0
//
#define UX_W_USB_CONTROLLER_INFO_NOT_VALID ((UXSTATUS)0xA2000305L)

//
// MessageId: UX_W_DRIVER_VERSION_NOT_VALID
//
// MessageText:
//
// Driver version not valid.%0
//
#define UX_W_DRIVER_VERSION_NOT_VALID    ((UXSTATUS)0xA2000306L)

//
// MessageId: UX_W_DRIVER_DATE_NOT_VALID
//
// MessageText:
//
// Driver date not valid.%0
//
#define UX_W_DRIVER_DATE_NOT_VALID       ((UXSTATUS)0xA2000307L)

//
// MessageId: UX_W_USB_NODE_INFORMATION_NOT_VALID
//
// MessageText:
//
// USB node information not valid.%0
//
#define UX_W_USB_NODE_INFORMATION_NOT_VALID ((UXSTATUS)0xA2000308L)

//
// MessageId: UX_W_USB_U3VDEVICE_EXISTS_AND_IS_NOT_USB3
//
// MessageText:
//
// An U3V device is connected and will operate with limited speed.%0
//
#define UX_W_USB_U3VDEVICE_EXISTS_AND_IS_NOT_USB3 ((UXSTATUS)0xA2000309L)

//
// MessageId: UX_W_USB_VERSION_IS_NOT_USB3_AND_HENCE_NOT_SUPERSPEED
//
// MessageText:
//
// The device is not connected to an USB 3.0 port and will operate with limited speed.%0
//
#define UX_W_USB_VERSION_IS_NOT_USB3_AND_HENCE_NOT_SUPERSPEED ((UXSTATUS)0xA200030AL)

//
// MessageId: UX_E_HIGHSPEED_NOT_SUPPORTED
//
// MessageText:
//
// The device does not support USB 2.0 High-Speed, it cannot be operated when connected to an USB 2.0 port.%0
//
#define UX_E_HIGHSPEED_NOT_SUPPORTED     ((UXSTATUS)0xE200030BL)

//
// MessageId: UX_E_USB_NO_DEVICE_CONNECTED
//
// MessageText:
//
// No device connected.%0
//
#define UX_E_USB_NO_DEVICE_CONNECTED     ((UXSTATUS)0xE200030CL)

//
// MessageId: UX_E_USB_DEVICE_FAILED_ENUMERATION
//
// MessageText:
//
// The enumeration of the device failed.%0
//
#define UX_E_USB_DEVICE_FAILED_ENUMERATION ((UXSTATUS)0xE200030DL)

//
// MessageId: UX_E_USB_DEVICE_GENERAL_FAILURE
//
// MessageText:
//
// The connection failed for unspecified reasons.%0
//
#define UX_E_USB_DEVICE_GENERAL_FAILURE  ((UXSTATUS)0xE200030EL)

//
// MessageId: UX_E_USB_DEVICE_CAUSED_OVERCURRENT
//
// MessageText:
//
// The attempt to connect failed because of an overcurrent condition.%0
//
#define UX_E_USB_DEVICE_CAUSED_OVERCURRENT ((UXSTATUS)0xE200030FL)

//
// MessageId: UX_E_USB_DEVICE_NOT_ENOUGH_POWER
//
// MessageText:
//
// There was not enough power to drive the device, and the connection failed.%0
//
#define UX_E_USB_DEVICE_NOT_ENOUGH_POWER ((UXSTATUS)0xE2000310L)

//
// MessageId: UX_E_USB_DEVICE_NOT_ENOUGH_BANDWIDTH
//
// MessageText:
//
// There was not enough bandwidth available for the device to function properly, and the connection failed.%0
//
#define UX_E_USB_DEVICE_NOT_ENOUGH_BANDWIDTH ((UXSTATUS)0xE2000311L)

//
// MessageId: UX_E_USB_DEVICE_HUB_NESTED_TOO_DEEPLY
//
// MessageText:
//
// The nesting of USB hubs was too deep, so the connection failed.%0
//
#define UX_E_USB_DEVICE_HUB_NESTED_TOO_DEEPLY ((UXSTATUS)0xE2000312L)

//
// MessageId: UX_E_USB_DEVICE_INLEGACY_HUB
//
// MessageText:
//
// An attempt was made to connect a device to the port of an unsupported legacy hub, and the connection failed.%0
//
#define UX_E_USB_DEVICE_INLEGACY_HUB     ((UXSTATUS)0xE2000313L)

//
// MessageId: UX_E_USB_DEVICE_ENUMERATING
//
// MessageText:
//
// A device connected to the port is currently being enumerated.%0
//
#define UX_E_USB_DEVICE_ENUMERATING      ((UXSTATUS)0xE2000314L)

//
// MessageId: UX_E_USB_DEVICE_RESET
//
// MessageText:
//
// The device connected to the port is currently being reset.%0
//
#define UX_E_USB_DEVICE_RESET            ((UXSTATUS)0xE2000315L)

//
// MessageId: UX_W_DRIVER_SHOULD_BE_UPDATED
//
// MessageText:
//
// The driver should be updated.%0
//
#define UX_W_DRIVER_SHOULD_BE_UPDATED    ((UXSTATUS)0xA2000316L)

//
// MessageId: UX_E_FAILED_TO_GET_DRIVER_KEY_NAME
//
// MessageText:
//
// A driver is not installed or is not working correctly. (Failed to get driver key name)%0
//
#define UX_E_FAILED_TO_GET_DRIVER_KEY_NAME ((UXSTATUS)0xE2000317L)

//
// MessageId: UX_E_FAILED_TO_GET_SERVICE
//
// MessageText:
//
// A driver is not installed or is not working correctly. (Failed to get information about the service)%0
//
#define UX_E_FAILED_TO_GET_SERVICE       ((UXSTATUS)0xE2000318L)

//
// MessageId: UX_W_USB_INSTALL_STATE_NEEDS_REINSTALL
//
// MessageText:
//
// The driver needs to be reinstalled.%0
//
#define UX_W_USB_INSTALL_STATE_NEEDS_REINSTALL ((UXSTATUS)0xA2000319L)

//
// MessageId: UX_E_USB_DEVICE_HAS_PROBLEM
//
// MessageText:
//
// The device or driver has a problem.%0
//
#define UX_E_USB_DEVICE_HAS_PROBLEM      ((UXSTATUS)0xE200031AL)

//
// MessageId: UX_W_USB_INSTALL_STATE_FAILED_INSTALL
//
// MessageText:
//
// Failed to install the driver.%0
//
#define UX_W_USB_INSTALL_STATE_FAILED_INSTALL ((UXSTATUS)0xA200031BL)

//
// MessageId: UX_W_USB_INSTALL_STATE_FINISH_INSTALL
//
// MessageText:
//
// The device or driver is in finish install state.%0
//
#define UX_W_USB_INSTALL_STATE_FINISH_INSTALL ((UXSTATUS)0xA200031CL)

//
// MessageId: UX_E_DESCRIPTOR_NOT_FOUND
//
// MessageText:
//
// USB descriptor not found.%0
//
#define UX_E_DESCRIPTOR_NOT_FOUND        ((UXSTATUS)0xE200031DL)

//
// MessageId: UX_W_ONLY_ONE_CAMERA_RECOMMENDED
//
// MessageText:
//
// Only one camera of the current USB 3.0 camera model and no further device should be connected to the host controller.%0
//
#define UX_W_ONLY_ONE_CAMERA_RECOMMENDED ((UXSTATUS)0xA200031EL)

//
// MessageId: UX_W_U3V_BANDWIDTH_MIGHT_BE_EXCEEDED
//
// MessageText:
//
// The host controller might not provide sufficient bandwidth for the connected camera devices.%0
//
#define UX_W_U3V_BANDWIDTH_MIGHT_BE_EXCEEDED ((UXSTATUS)0xA200031FL)

//
// MessageId: UX_E_U3V_DATA_OVERRUN
//
// MessageText:
//
// The transfer size configured by the host is not big enough to hold all data sent by the camera device.%0
//
#define UX_E_U3V_DATA_OVERRUN            ((UXSTATUS)0xA2000320L)

//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2015 Basler
//-----------------------------------------------------------------------------
/*
 * UXDRV error codes
 */

//Declare UXSTATUS
#ifdef _WIN32
   typedef unsigned __int32 uint32_t;
   typedef uint32_t UXSTATUS;
#endif

//----------------------------------------------------------------------------
// UXDRV error macro definitions
//----------------------------------------------------------------------------



/**
 * UX Severity.
 * Macro extracting the severity from a given UXSTATUS value.
 */
#define UX_SEVERITY(_s_)     (((_s_) >> 30) & 0x3)



/**
 * UX Facility.
 * Macro extracting the facility from a given UXSTATUS value.
 */
#define UX_FACILITY(_s_)     (((_s_) >> 16) & 0xfff)



/**
 * UX Error Code.
 * Macro extracting the intrinsic error code from a given UXSTATUS value.
 */
#define UX_ERRORCODE(_s_)    ((uint16_t)((_s_) & 0xffff))



/**
 * UX Success.
 * Checks whether the UX Status code represents a successful operation.
 * \todo Allow status codes with severity 'Information' to be success?
 */
#define UX_SUCCESS(_s_) ((UXSTATUS)(_s_) == UX_OK)



/**
 * UX Information.
 * Checks whether the UX Status code represents informational success status.
 */
#define UX_INFORMATION(_s_) (UX_SEVERITY(_s_) == UX_STATUS_SEVERITY_INFORMATIONAL)



/**
 * UX Warning.
 * Checks whether the UX Status code represents a warning.
 */
#define UX_WARNING(_s_) (UX_SEVERITY(_s_) == UX_STATUS_SEVERITY_WARNING)



/**
 * UX Error.
 * Checks whether the UX Status code represents an error.
 */
#define UX_ERROR(_s_) (UX_SEVERITY(_s_) == UX_STATUS_SEVERITY_ERROR)



#define UX_OK (UXSTATUS)0



// ------------------------------------------------------------------------------------------
// driver related errors
// ------------------------------------------------------------------------------------------
//
// MessageId: UX_E_DRV_FALSE
//
// MessageText:
//
// No%0
//
#define UX_E_DRV_FALSE                   ((UXSTATUS)0xE201012CL)

//
// MessageId: UX_E_DRV_NOT_IMPLEMENTED
//
// MessageText:
//
// Function is not implemented.%0
//
#define UX_E_DRV_NOT_IMPLEMENTED         ((UXSTATUS)0xE201012DL)

//
// MessageId: UX_E_DRV_INVALID_PIPE
//
// MessageText:
//
// Invalid Pipe.%0
//
#define UX_E_DRV_INVALID_PIPE            ((UXSTATUS)0xE201012EL)

//
// MessageId: UX_E_DRV_INVALID_INTERFACE
//
// MessageText:
//
// Invalid Interface.%0
//
#define UX_E_DRV_INVALID_INTERFACE       ((UXSTATUS)0xE201012FL)

//
// MessageId: UX_E_DRV_LOCK_BUFFER
//
// MessageText:
//
// Failed to probe and lock buffer.%0
//
#define UX_E_DRV_LOCK_BUFFER             ((UXSTATUS)0xE2010130L)

//
// MessageId: UX_E_DRV_INPUT_BUFFER
//
// MessageText:
//
// Invalid input buffer.%0
//
#define UX_E_DRV_INPUT_BUFFER            ((UXSTATUS)0xE2010131L)

//
// MessageId: UX_E_DRV_OUTPUT_BUFFER
//
// MessageText:
//
// Invalid out	put buffer.%0
//
#define UX_E_DRV_OUTPUT_BUFFER           ((UXSTATUS)0xE2010132L)

//
// MessageId: UX_E_DRV_FORWARD_REQUEST
//
// MessageText:
//
// Unable to forward request.%0
//
#define UX_E_DRV_FORWARD_REQUEST         ((UXSTATUS)0xE2010133L)

//
// MessageId: UX_E_DRV_REQUEXT_CONTEXT
//
// MessageText:
//
// Failed to create request context.%0
//
#define UX_E_DRV_REQUEXT_CONTEXT         ((UXSTATUS)0xE2010134L)

//
// MessageId: UX_E_DRV_WRITE_TRANSMISSION
//
// MessageText:
//
// Write transmission failed.%0
//
#define UX_E_DRV_WRITE_TRANSMISSION      ((UXSTATUS)0xE2010135L)

//
// MessageId: UX_E_DRV_READ_TRANSMISSION
//
// MessageText:
//
// Read transmission failed.%0
//
#define UX_E_DRV_READ_TRANSMISSION       ((UXSTATUS)0xE2010136L)

//
// MessageId: UX_E_DRV_INVALID_STRING_INDEX
//
// MessageText:
//
// Invalid string index.%0
//
#define UX_E_DRV_INVALID_STRING_INDEX    ((UXSTATUS)0xE2010137L)

//
// MessageId: UX_E_DRV_QUERY_STRING
//
// MessageText:
//
// Failed to query string from device.%0
//
#define UX_E_DRV_QUERY_STRING            ((UXSTATUS)0xE2010138L)

//
// MessageId: UX_E_DRV_INVALID_LANGUAGE_ID
//
// MessageText:
//
// Invalid language parameter.%0
//
#define UX_E_DRV_INVALID_LANGUAGE_ID     ((UXSTATUS)0xE2010139L)

//
// MessageId: UX_E_DRV_QUERY_LANGUAGE_ID
//
// MessageText:
//
// Failed to query string languages from device.%0
//
#define UX_E_DRV_QUERY_LANGUAGE_ID       ((UXSTATUS)0xE201013AL)

//
// MessageId: UX_E_DRV_STALL_PIPE
//
// MessageText:
//
// Failed to stall pipe.%0
//
#define UX_E_DRV_STALL_PIPE              ((UXSTATUS)0xE201013BL)

//
// MessageId: UX_E_DRV_RESET_PIPE
//
// MessageText:
//
// Failed to reset pipe.%0
//
#define UX_E_DRV_RESET_PIPE              ((UXSTATUS)0xE201013CL)

//
// MessageId: UX_E_DRV_ABORT_PIPE
//
// MessageText:
//
// Failed to abort pipe.%0
//
#define UX_E_DRV_ABORT_PIPE              ((UXSTATUS)0xE201013DL)

//
// MessageId: UX_E_DRV_CONFIGURATION
//
// MessageText:
//
// Failed to select configuration.%0
//
#define UX_E_DRV_CONFIGURATION           ((UXSTATUS)0xE201013EL)

//
// MessageId: UX_E_DRV_DEVICE_IN_USE
//
// MessageText:
//
// Device is exclusively opened by another client.%0
//
#define UX_E_DRV_DEVICE_IN_USE           ((UXSTATUS)0xE201013FL)

//
// MessageId: UX_E_DRV_STREAM
//
// MessageText:
//
// Unable to create stream.%0
//
#define UX_E_DRV_STREAM                  ((UXSTATUS)0xE2010140L)

//
// MessageId: UX_W_DRV_STREAM_CONFIGURATION
//
// MessageText:
//
// Unable to complete stream configuration.%0
//
#define UX_W_DRV_STREAM_CONFIGURATION    ((UXSTATUS)0xA2010141L)

//
// MessageId: UX_E_DRV_INVALID_BUFFER_SIZE
//
// MessageText:
//
// Invalid buffer size.%0
//
#define UX_E_DRV_INVALID_BUFFER_SIZE     ((UXSTATUS)0xE2010142L)

//
// MessageId: UX_E_DRV_FORMAT_REQUEST
//
// MessageText:
//
// Unable to format USB request.%0
//
#define UX_E_DRV_FORMAT_REQUEST          ((UXSTATUS)0xE2010143L)

//
// MessageId: UX_E_DRV_FATAL
//
// MessageText:
//
// Fatal Error.%0
//
#define UX_E_DRV_FATAL                   ((UXSTATUS)0xE2010002L)

