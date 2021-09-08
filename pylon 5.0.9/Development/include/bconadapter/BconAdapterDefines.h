//-----------------------------------------------------------------------------
//  Copyright (C) 2016-2017 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief BCON adapter interface constants.
* \ingroup public
*/
#pragma once

#if defined(_MSC_VER)

#   define BCON_ADAPTER_CDECL __cdecl

#   if defined (BCON_ADAPTER_IMPORT)
#       define BCON_ADAPTER_API // Functions will be imported using GetProcAddress/dlsym and not via import lib
#   else
/// Default: mark functions as exported from the DLL
#       define BCON_ADAPTER_API __declspec(dllexport)
#   endif

#elif defined(__GNUC__) && (defined(__linux__))
#   if defined(__i386) || defined(__i386__) || defined(_M_IX86)
// cdecl is only needed on 32 bit intel platforms, causes attribute ignored warning when used on 64 bit or non-intel builds
#       define BCON_ADAPTER_CDECL __attribute__((__cdecl__))
#   else
#       define BCON_ADAPTER_CDECL
#   endif



#   if defined (BCON_ADAPTER_IMPORT)
#       define BCON_ADAPTER_API
#   else
#       define BCON_ADAPTER_API __attribute__((visibility("default")))
#   endif


#else

#   error "Unsupported platform"

#endif

/// Alignment of structures
#define BCON_PACKING 8

// Calling Convention
#define BCON_ADAPTER_CALL BCON_ADAPTER_CDECL 

/** 
* \def BCON_ADAPTER_API
* \brief Marks a BCON ADAPTER API function
*/

#if ! defined (BCON_UNUSED)
/// Explicitly state that variable v is not used
#define BCON_UNUSED( v ) ((void) (v))
#endif
/**
* \def EXTERN_C_BEGIN
* \brief Begin of code region with C linkage
*
* \def EXTERN_C_END
* \brief End of code region with C linkage
*/
#if defined (__cplusplus)
#   if !defined(EXTERN_C_BEGIN)
#       define EXTERN_C_BEGIN extern "C" {
#   endif
#   if !defined(EXTERN_C_END)
#       define EXTERN_C_END }
#   endif
#   if !defined(EXTERN_C)
#       define EXTERN_C extern "C"
#   endif
#else
#   if !defined(EXTERN_C_BEGIN)
#       define EXTERN_C_BEGIN
#   endif
#   if !defined(EXTERN_C_END)
#       define EXTERN_C_END
#   endif
#   if !defined(EXTERN_C)
#       define EXTERN_C
#   endif
#endif

//----------------------------------------------------------------------------
// BCON status code layout
//----------------------------------------------------------------------------
//
//  Values are 32-bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev = severity level code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C = customer code flag
//
//      R = reserved bit
//
//      Facility = facility code
//
//      Code = status code
//
//
// Facility code definition
//
#define BCON_STATUS_FACILITY_BCON        0x220


//
// Severity level code definitions
//
#define BCON_STATUS_SEVERITY_WARNING       0x2
#define BCON_STATUS_SEVERITY_SUCCESS       0x0
#define BCON_STATUS_SEVERITY_INFORMATIONAL 0x1
#define BCON_STATUS_SEVERITY_ERROR         0x3


/**
* BCON Severity.
* Extracts the severity level code from a given BCONSTATUS value.
*/
#define BCON_SEVERITY(_s_)     (((_s_) >> 30) & 0x3)



/**
* BCON Facility.
* Extracts the facility code from a given BCONSTATUS value.
*/
#define BCON_FACILITY(_s_)     (((_s_) >> 16) & 0xfff)



/**
* BCON Error Code.
* Extracts the facility status code from a given BCONSTATUS value.
*/
#define BCON_ERRORCODE(_s_)    ((uint16_t)((_s_) & 0xffff))



/**
* BCON Success.
* Checks whether the BCON status indicates a successful operation.
* \todo Allow status codes with severity 'Information' to be success?
*/
#define BCON_SUCCESS(_s_) (BCON_SEVERITY(_s_) == BCON_STATUS_SEVERITY_SUCCESS || BCON_SEVERITY(_s_)==BCON_STATUS_SEVERITY_INFORMATIONAL)



/**
* BCON Information.
* Checks whether the BCON status indicates a successful operation with severity level 'Informational'.
*/
#define BCON_INFORMATION(_s_) (BCON_SEVERITY(_s_) == BCON_STATUS_SEVERITY_INFORMATIONAL)



/**
* BCON Warning.
* Checks whether the BCON status indicates a warning.
*/
#define BCON_WARNING(_s_) (BCON_SEVERITY(_s_) == BCON_STATUS_SEVERITY_WARNING)



/**
* BCON Error.
* Checks whether the BCON status indicates an error.
*/
#define BCON_ERROR(_s_) (BCON_SEVERITY(_s_) == BCON_STATUS_SEVERITY_ERROR)



/// Operation was successful.
#define BCON_OK (BCONSTATUS)0


// -----------------------------------------------------------------------------------------
// BCON status codes
// -----------------------------------------------------------------------------------------
//
// MessageId: BCON_E_NOT_FOUND
//
// MessageText:
//
/// The specified item does not exist.
//
#define BCON_E_NOT_FOUND                   ((BCONSTATUS)0xE2200001L)

//
// MessageId: BCON_S_ALREADY_CREATED
//
// MessageText:
//
/// The specified item has already been created.
//
#define BCON_S_ALREADY_CREATED             ((BCONSTATUS)0x62200002L)

//
// MessageId: BCON_E_UNKNOWN
//
// MessageText:
//
/// Unknown error.
//
#define BCON_E_UNKNOWN                     ((BCONSTATUS)0xE2200003L)

//
// MessageId: BCON_E_OPERATION_ABORTED
//
// MessageText:
//
/// The operation was aborted.
//
#define BCON_E_OPERATION_ABORTED           ((BCONSTATUS)0xE2200004L)

//
// MessageId: BCON_E_OPERATION_FAILED
//
// MessageText:
//
/// The operation failed.
//
#define BCON_E_OPERATION_FAILED            ((BCONSTATUS)0xE2200005L)

//
// MessageId: BCON_E_NOT_IMPLEMENTED
//
// MessageText:
//
/// Function not implemented.
//
#define BCON_E_NOT_IMPLEMENTED             ((BCONSTATUS)0xE2200006L)

//
// MessageId: BCON_E_TIMEOUT
//
// MessageText:
//
/// The requested operation timed out.
//
#define BCON_E_TIMEOUT                     ((BCONSTATUS)0xE2200007L)

//
// MessageId: BCON_E_INVALID_PARAMETER
//
// MessageText:
//
/// An invalid parameter has been passed.
//
#define BCON_E_INVALID_PARAMETER           ((BCONSTATUS)0xE2200008L)

//
// MessageId: BCON_E_INSUFFICIENT_BUFFER
//
// MessageText:
//
/// The provided buffer is too small.
//
#define BCON_E_INSUFFICIENT_BUFFER         ((BCONSTATUS)0xE2200009L)

//
// MessageId: BCON_E_INVALID_HANDLE
//
// MessageText:
//
/// The handle is invalid.
//
#define BCON_E_INVALID_HANDLE              ((BCONSTATUS)0xE220000AL)

//
// MessageId: BCON_E_WRITE_FAILED
//
// MessageText:
//
/// Write operation failed.
//
#define BCON_E_WRITE_FAILED                ((BCONSTATUS)0xE220000BL)

//
// MessageId: BCON_E_READ_FAILED
//
// MessageText:
//
/// Read operation failed.
//
#define BCON_E_READ_FAILED                 ((BCONSTATUS)0xE220000CL)

//
// MessageId: BCON_E_NOT_INITIALIZED
//
// MessageText:
//
/// Library or object is not initialized. Call the appropriate initialization function first.
//
#define BCON_E_NOT_INITIALIZED             ((BCONSTATUS)0xE220000DL)

//
// MessageId: BCON_E_UNEXPECTED_EXCEPTION
//
// MessageText:
//
/// An unexpected exception has been caught.
//
#define BCON_E_UNEXPECTED_EXCEPTION        ((BCONSTATUS)0xE220000EL)


// -----------------------------------------------------------------------------------------
// Stream related status codes
// -----------------------------------------------------------------------------------------
//
// MessageId: BCON_E_INVALID_STREAM_STATE
//
// MessageText:
//
/// Invalid state.
//
#define BCON_E_INVALID_STREAM_STATE        ((BCONSTATUS)0xE2200200L)

//
// MessageId: BCON_E_BUFFER_ALREADY_REGISTERED
//
// MessageText:
//
/// The buffer is already registered.
//
#define BCON_E_BUFFER_ALREADY_REGISTERED   ((BCONSTATUS)0xE2200201L)

//
// MessageId: BCON_E_INVALID_BUFFER_HANDLE
//
// MessageText:
//
/// Invalid buffer handle.
//
#define BCON_E_INVALID_BUFFER_HANDLE       ((BCONSTATUS)0xE2200202L)

//
// MessageId: BCON_E_NO_BUFFER_AVAILABLE
//
// MessageText:
//
/// No buffer available.
//
#define BCON_E_NO_BUFFER_AVAILABLE         ((BCONSTATUS)0xE2200203L)

//
// MessageId: BCON_E_BUFFER_STILL_QUEUED
//
// MessageText:
//
/// Buffer is still queued.
//
#define BCON_E_BUFFER_STILL_QUEUED         ((BCONSTATUS)0xE2200204L)

//
// MessageId: BCON_E_BUFFER_ALREADY_QUEUED
//
// MessageText:
//
/// Buffer is already queued.
//
#define BCON_E_BUFFER_ALREADY_QUEUED       ((BCONSTATUS)0xE2200205L)

//
// MessageId: BCON_E_BUFFER_INCOMPLETE
//
// MessageText:
//
/// The buffer was incompletely grabbed.
//
#define BCON_E_BUFFER_INCOMPLETE           ((BCONSTATUS)0xE2200206L)

//
// MessageId: BCON_E_BUFFER_CANCELLED
//
// MessageText:
//
/// The buffer was canceled.
//
#define BCON_E_BUFFER_CANCELLED            ((BCONSTATUS)0xE2200207L)

//
// MessageId: BCON_E_STREAMING_NOT_SUPPORTED
//
// MessageText:
//
/// The device does not support streaming.
//
#define BCON_E_STREAMING_NOT_SUPPORTED     ((BCONSTATUS)0xE2200208L)


// -----------------------------------------------------------------------------------------
// Custom status codes
// -----------------------------------------------------------------------------------------

/// Custom status codes can use the 16-bit "Code" field in a range from 0x8000 to 0xFFFF,
/// combined with the appropriate severity level code.
#define BCON_E_CUSTOM                    ((BCONSTATUS)0xE2208000L)
#define BCON_I_CUSTOM                    ((BCONSTATUS)0x62208000L)
#define BCON_W_CUSTOM                    ((BCONSTATUS)0xA2208000L)
#define BCON_S_CUSTOM                    ((BCONSTATUS)0x22208000L)



