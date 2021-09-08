//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Defines the BCON adapter specific types.
* \ingroup public
*/
#pragma once

#include <bconadapter/BconAdapterDefines.h>
#include <stdarg.h>
// on MSVC stdint.h is available since MSVC2010
#if !defined(_MSC_VER) || _MSC_VER >= 1600
#   include <stdint.h>
#else

/// Portable definition of signed integer (8 bit)
typedef signed char        int8_t;
/// Portable definition of signed integer (16 bit)
typedef short              int16_t;
/// Portable definition of signed integer (32 bit)
typedef int                int32_t;
/// Portable definition of signed integer (64 bit)
typedef long long          int64_t;
/// Portable definition of unsigned integer (8 bit)
typedef unsigned char      uint8_t;
/// Portable definition of unsigned integer (16 bit)
typedef unsigned short     uint16_t;
/// Portable definition of unsigned integer (32 bit)
typedef unsigned int       uint32_t;
/// Portable definition of unsigned integer (64 bit)
typedef unsigned long long uint64_t;

/** 
\typedef uintptr_t 
\brief Type holding an unsigned integer or a pointer value.
*/
#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned long long uintptr_t;
#else /* _WIN64 */
typedef  unsigned int  uintptr_t;
#endif /* _WIN64 */
#endif /* _UINTPTR_T_DEFINED */

#endif // !defined(_MSC_VER) || _MSC_VER >= 1600


/** \brief Makes char 8 portable across different platforms */
typedef char char8_t;
/** \brief Makes char 8 portable across different platforms */
typedef unsigned char uchar8_t;

/** \brief Data type for representing status and error codes. */
typedef uint32_t BCONSTATUS;

/// Severity level of the messages to be traced
typedef enum EBconAdapterTraceLevel
{
      BconAdapterTraceLevel_Critical = 10        ///< Critical, unrecoverable errors are traced.
    , BconAdapterTraceLevel_Error = 20           ///< Error messages are traced.
    , BconAdapterTraceLevel_Warning = 30         ///< Warning messages are traced. 
    , BconAdapterTraceLevel_Information = 40     ///< Informational messages are traced.
    , BconAdapterTraceLevel_Verbose = 50         ///< More verbose messages are traced.
    , BconAdapterTraceLevel_Debug = 60           ///< Very verbose messages are traced, e.g. function entries and exits. Usually for debugging purposes.
} BconAdapterTraceLevel;

/**
\brief Writes trace messages to the trace output of the host application.
If the host application passes a pointer to a function, you can use this function to write to the trace output of the host application.
The level parameter specifies the severity level of the messages to be traced. It allows you to filter the output.
The pFormat parameter specifies the format string (see printf). Do not add line breaks to the format string.
The argList parameter points to the variable argument list.
*/
typedef void (BCON_ADAPTER_CDECL *BconTraceFunc)(BconAdapterTraceLevel level, const char* pFormat, va_list argList);

