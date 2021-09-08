//-----------------------------------------------------------------------------
//  Copyright (C) 2015-2017 Basler
//-----------------------------------------------------------------------------
 /**
 * \file
 * \brief BXAPI error codes
 * \ingroup public
 */
#pragma once
#include "BxTypes.h"

//----------------------------------------------------------------------------
// BXAPI error macro definitions
//----------------------------------------------------------------------------



/**
 * BX Severity.
 * Macro extracting the severity from a given BXSTATUS value.
 */
#define BX_SEVERITY(_s_)     (((_s_) >> 30) & 0x3)



/**
 * BX Facility.
 * Macro extracting the facility from a given BXSTATUS value.
 */
#define BX_FACILITY(_s_)     (((_s_) >> 16) & 0xfff)



/**
 * BX Error Code.
 * Macro extracting the intrinsic error code from a given BXSTATUS value.
 */
#define BX_ERRORCODE(_s_)    ((uint16_t)((_s_) & 0xffff))



/**
 * BX Success.
 * Checks whether the BXSTATUS represents a successful operation.
 * By definition negative values are errors, 0 and positive values indicate sucessess
 */
#define BX_SUCCESS(_s_) ((int32_t)(_s_) >= 0)



/**
 * BX Failure.
 * Checks whether the BX status code represents an error.
 */
#define BX_FAILURE(_s_) (!BX_SUCCESS(_s_))

/**
 * BX Error.
 * Checks whether the BX Status code represents an error.
 */
#define BX_ERROR(_s_) (BX_SEVERITY(_s_) == BX_STATUS_SEVERITY_ERROR)



#define BX_OK ((BXSTATUS)0)



//----------------------------------------------------------------------------
// BX_STATUS_FACILITY_BX
//----------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------
// Error codes shared with the BCON Adapter
// -----------------------------------------------------------------------------------------
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
#define BX_STATUS_FACILITY_BX            0x220


//
// Define the severity codes
//
#define BX_STATUS_SEVERITY_WARNING       0x2
#define BX_STATUS_SEVERITY_SUCCESS       0x0
#define BX_STATUS_SEVERITY_INFORMATIONAL 0x1
#define BX_STATUS_SEVERITY_ERROR         0x3


//
// MessageId: BX_E_NOT_FOUND
//
// MessageText:
//
// The specified item does not exist.%0
//
#define BX_E_NOT_FOUND                   ((BXSTATUS)0xE2200001L)

//
// MessageId: BX_S_ALREADY_CREATED
//
// MessageText:
//
// The specified item has already been created.%0
//
#define BX_S_ALREADY_CREATED             ((BXSTATUS)0x62200002L)

//
// MessageId: BX_E_UNKNOWN
//
// MessageText:
//
// Unknown error.%0
//
#define BX_E_UNKNOWN                     ((BXSTATUS)0xE2200003L)

//
// MessageId: BX_E_OPERATION_ABORTED
//
// MessageText:
//
// The operation was aborted.%0
//
#define BX_E_OPERATION_ABORTED           ((BXSTATUS)0xE2200004L)

//
// MessageId: BX_E_OPERATION_FAILED
//
// MessageText:
//
// The operation failed.%0
//
#define BX_E_OPERATION_FAILED            ((BXSTATUS)0xE2200005L)

//
// MessageId: BX_E_NOT_IMPLEMENTED
//
// MessageText:
//
// Function not implemented.%0
//
#define BX_E_NOT_IMPLEMENTED             ((BXSTATUS)0xE2200006L)

//
// MessageId: BX_E_TIMEOUT
//
// MessageText:
//
// The requested operation timed out.%0
//
#define BX_E_TIMEOUT                     ((BXSTATUS)0xE2200007L)

//
// MessageId: BX_E_INVALID_PARAMETER
//
// MessageText:
//
// An invalid parameter has been passed.%0
//
#define BX_E_INVALID_PARAMETER           ((BXSTATUS)0xE2200008L)

//
// MessageId: BX_E_INSUFFICIENT_BUFFER
//
// MessageText:
//
// The provided buffer is too small.%0
//
#define BX_E_INSUFFICIENT_BUFFER         ((BXSTATUS)0xE2200009L)

//
// MessageId: BX_E_INVALID_HANDLE
//
// MessageText:
//
// The handle is invalid.%0
//
#define BX_E_INVALID_HANDLE              ((BXSTATUS)0xE220000AL)

//
// MessageId: BX_E_WRITE_FAILED
//
// MessageText:
//
// Write operation failed.%0
//
#define BX_E_WRITE_FAILED                ((BXSTATUS)0xE220000BL)

//
// MessageId: BX_E_READ_FAILED
//
// MessageText:
//
// Read operation failed.%0
//
#define BX_E_READ_FAILED                 ((BXSTATUS)0xE220000CL)

//
// MessageId: BX_E_NOT_INITIALIZED
//
// MessageText:
//
// Library or object is not initialized. Call the appropriate initialization function first.%0
//
#define BX_E_NOT_INITIALIZED             ((BXSTATUS)0xE220000DL)

//
// MessageId: BX_E_UNEXPECTED_EXCEPTION
//
// MessageText:
//
// An unexpected exception has been caught.%0
//
#define BX_E_UNEXPECTED_EXCEPTION        ((BXSTATUS)0xE220000EL)

// -----------------------------------------------------------------------------------------
// Error codes used by bxapi only
// -----------------------------------------------------------------------------------------
//
// MessageId: BX_E_DEVICE_NOT_OPEN
//
// MessageText:
//
// Device not open.%0
//
#define BX_E_DEVICE_NOT_OPEN             ((BXSTATUS)0xE2200100L)

//
// MessageId: BX_E_CRC_ERROR
//
// MessageText:
//
// The CRC values do not match.%0
//
#define BX_E_CRC_ERROR                   ((BXSTATUS)0xE2200101L)

//
// MessageId: BX_E_DEVICE_ALREADY_OPEN
//
// MessageText:
//
// Device is already open.%0
//
#define BX_E_DEVICE_ALREADY_OPEN         ((BXSTATUS)0xE2200102L)

//
// MessageId: BX_E_READ_CAPABILITY_FAILED
//
// MessageText:
//
// Failed to read the device capability register.%0
//
#define BX_E_READ_CAPABILITY_FAILED      ((BXSTATUS)0xE2200103L)

//
// MessageId: BX_E_READ_MAXIMUM_DEVICE_RESPONSE_TIME_FAILED
//
// MessageText:
//
// Failed to read the first register (maximum device response time). This can be caused by problems with the I2C-bus used.%0
//
#define BX_E_READ_MAXIMUM_DEVICE_RESPONSE_TIME_FAILED ((BXSTATUS)0xE2200104L)

//
// MessageId: BX_E_DEVICE_HAS_BEEN_REMOVED
//
// MessageText:
//
// Device has been removed from the PC.%0
//
#define BX_E_DEVICE_HAS_BEEN_REMOVED     ((BXSTATUS)0xE2200105L)

//
// MessageId: BX_E_DEVICE_IN_USE
//
// MessageText:
//
// Device is exclusively opened by another client.%0
//
#define BX_E_DEVICE_IN_USE               ((BXSTATUS)0xE2200106L)

//
// MessageId: BX_E_BCON_ADAPTER_LIBRARY_IS_MISSING
//
// MessageText:
//
// The BCON adapter library cannot be found.%0
//
#define BX_E_BCON_ADAPTER_LIBRARY_IS_MISSING ((BXSTATUS)0xE2200107L)

//
// MessageId: BX_E_BCON_ADAPTER_FUNCTION_IS_MISSING
//
// MessageText:
//
// A BCON adapter library function is missing or not implemented.%0
//
#define BX_E_BCON_ADAPTER_FUNCTION_IS_MISSING ((BXSTATUS)0xE2200108L)

//
// MessageId: BX_E_BCON_ADAPTER_LIBRARY_API_MAJOR_VERSION_MISMATCH
//
// MessageText:
//
// Mismatch of major versions of the BCON adapter library and the implemented API.%0
//
#define BX_E_BCON_ADAPTER_LIBRARY_API_MAJOR_VERSION_MISMATCH ((BXSTATUS)0xE2200109L)

// -----------------------------------------------------------------------------------------
// stream related errors, shared with the BCON adapter
// -----------------------------------------------------------------------------------------
//
// MessageId: BX_E_INVALID_STREAM_STATE
//
// MessageText:
//
// Invalid state.%0
//
#define BX_E_INVALID_STREAM_STATE        ((BXSTATUS)0xE2200200L)

//
// MessageId: BX_E_BUFFER_ALREADY_REGISTERED
//
// MessageText:
//
// The buffer is already registered.%0
//
#define BX_E_BUFFER_ALREADY_REGISTERED   ((BXSTATUS)0xE2200201L)

//
// MessageId: BX_E_INVALID_BUFFER_HANDLE
//
// MessageText:
//
// Invalid buffer handle.%0
//
#define BX_E_INVALID_BUFFER_HANDLE       ((BXSTATUS)0xE2200202L)

//
// MessageId: BX_E_NO_BUFFER_AVAILABLE
//
// MessageText:
//
// No buffer available.%0
//
#define BX_E_NO_BUFFER_AVAILABLE         ((BXSTATUS)0xE2200203L)

//
// MessageId: BX_E_BUFFER_STILL_QUEUED
//
// MessageText:
//
// Buffer is still queued.%0
//
#define BX_E_BUFFER_STILL_QUEUED         ((BXSTATUS)0xE2200204L)

//
// MessageId: BX_E_BUFFER_ALREADY_QUEUED
//
// MessageText:
//
// Buffer is already queued.%0
//
#define BX_E_BUFFER_ALREADY_QUEUED       ((BXSTATUS)0xE2200205L)

//
// MessageId: BX_E_BUFFER_INCOMPLETE
//
// MessageText:
//
// The buffer was incompletely grabbed.%0
//
#define BX_E_BUFFER_INCOMPLETE           ((BXSTATUS)0xE2200206L)

//
// MessageId: BX_E_BUFFER_CANCELLED
//
// MessageText:
//
// The buffer was canceled.%0
//
#define BX_E_BUFFER_CANCELLED            ((BXSTATUS)0xE2200207L)

//
// MessageId: BX_E_STREAMING_NOT_SUPPORTED
//
// MessageText:
//
// The device does not support streaming.%0
//
#define BX_E_STREAMING_NOT_SUPPORTED     ((BXSTATUS)0xE2200208L)

//-----------------------------------------------------------------------------
//  Copyright (C) 2015-2017 Basler AG
//-----------------------------------------------------------------------------
/*
 * GenCP error codes
 */

#if defined(_MSC_VER) && (_MSC_VER < 1600)
//! makes unsigned int32 portable across different platforms
typedef unsigned __int32 uint32_t;
#else
#   include <stdint.h>
#endif

/**
 * \brief UX Status. Data type for representing status and error codes.
 */
typedef uint32_t GCPSTATUS;

//----------------------------------------------------------------------------
// GenCP error macro definitions
//----------------------------------------------------------------------------



/**
 * GenCP Severity.
 * Macro extracting the severity from a given GCPSTATUS value.
 */
#define GENCP_SEVERITY(_s_)     (((_s_) >> 30) & 0x3)



/**
 * GenCP Facility.
 * Macro extracting the facility from a given GCPSTATUS value.
 */
#define GENCP_FACILITY(_s_)     (((_s_) >> 16) & 0xfff)



/**
 * GenCP Error Code.
 * Macro extracting the intrinsic error code from a given GCPSTATUS value.
 */
#define GENCP_ERRORCODE(_s_)    ((uint16_t)((_s_) & 0xffff))



/**
 * GenCP Success.
 * Checks whether the GenCP Status code represents a successful operation.
 * \todo Allow status codes with severity 'Information' to be success?
 */
#define GENCP_SUCCESS(_s_) ((GCPSTATUS)(_s_) == MAP_GCPSTATUS(OK))



/**
 * GenCP Information.
 * Checks whether the GenCP Status code represents informational success status.
 */
#define GENCP_INFORMATION(_s_) (GENCP_SEVERITY(_s_) == GENCP_STATUS_SEVERITY_INFORMATIONAL)



/**
 * GenCP Warning.
 * Checks whether the GenCP Status code represents a warning.
 */
#define GENCP_WARNING(_s_) (GENCP_SEVERITY(_s_) == GENCP_STATUS_SEVERITY_WARNING)



/**
 * GenCP Error.
 * Checks whether the GenCP Status code represents an error.
 */
#define GENCP_ERROR(_s_) (GENCP_SEVERITY(_s_) == GENCP_STATUS_SEVERITY_ERROR)



// -----------------------------------------------------------------------------------------
// Control protocol related errors
// -----------------------------------------------------------------------------------------
//
// MessageId: GENCP_E_NACK
//
// MessageText:
//
// Command not accepted.%0
//
#define GENCP_E_NACK                     ((GCPSTATUS)0xE2300200L)

//
// MessageId: GENCP_E_WRITE_INCOMPLETE
//
// MessageText:
//
// Wrote less data than requested.%0
//
#define GENCP_E_WRITE_INCOMPLETE         ((GCPSTATUS)0xE2300201L)

//
// MessageId: GENCP_E_INVALID_ADDRESS
//
// MessageText:
//
// Attempt to access a not existing register address.%0
//
#define GENCP_E_INVALID_ADDRESS          ((GCPSTATUS)0xE2300202L)

//
// MessageId: GENCP_E_WRITE_PROTECT
//
// MessageText:
//
// Attempt to write to a read only register.%0
//
#define GENCP_E_WRITE_PROTECT            ((GCPSTATUS)0xE2300203L)

//
// MessageId: GENCP_E_BAD_ALIGNMENT
//
// MessageText:
//
// Attempt to access registers with an address which is not aligned according to the underlying technology.%0
//
#define GENCP_E_BAD_ALIGNMENT            ((GCPSTATUS)0xE2300204L)

//
// MessageId: GENCP_E_ACCESS_DENIED
//
// MessageText:
//
// Attempt to access a currently not supported register space.%0
//
#define GENCP_E_ACCESS_DENIED            ((GCPSTATUS)0xE2300205L)

//
// MessageId: GENCP_E_BUSY
//
// MessageText:
//
// The command receiver is currently busy.%0
//
#define GENCP_E_BUSY                     ((GCPSTATUS)0xE2300206L)

//
// MessageId: GENCP_E_MSG_TIMEOUT
//
// MessageText:
//
// Timeout waiting for an acknowledgement.%0
//
#define GENCP_E_MSG_TIMEOUT              ((GCPSTATUS)0xE2300207L)

//
// MessageId: GENCP_E_INVALID_HEADER
//
// MessageText:
//
// The header of the received command is invalid.%0
//
#define GENCP_E_INVALID_HEADER           ((GCPSTATUS)0xE2300208L)

//
// MessageId: GENCP_E_WRONG_CONFIG
//
// MessageText:
//
// The current receiver information does not allow the execution of the sent command.%0
//
#define GENCP_E_WRONG_CONFIG             ((GCPSTATUS)0xE2300209L)

//
// MessageId: GENCP_E_ERROR
//
// MessageText:
//
// A fatal internal error occurred.%0
//
#define GENCP_E_ERROR                    ((GCPSTATUS)0xE23002FFL)

