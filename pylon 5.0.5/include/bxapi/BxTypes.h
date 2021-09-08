//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief BXAPI specific type definitions and macros
 * \ingroup public
 */
#pragma once


// on MSVC stdint.h is available since MSVC2010
#if !defined(_MSC_VER) || _MSC_VER >= 1600
#   include <stdint.h>
#else

/// portable definition of signed integer (8 bit)
typedef signed char        int8_t;
/// portable definition of signed integer (16 bit)
typedef short              int16_t;
/// portable definition of signed integer (32 bit)
typedef int                int32_t;
/// portable definition of signed integer (64 bit)
typedef long long          int64_t;
/// portable definition of unsigned integer (8 bit)
typedef unsigned char      uint8_t;
/// portable definition of unsigned integer (16 bit)
typedef unsigned short     uint16_t;
/// portable definition of unsigned integer (32 bit)
typedef unsigned int       uint32_t;
/// portable definition of unsigned integer (64 bit)
typedef unsigned long long uint64_t;

/**
\typedef uintptr_t
\brief type holding an unsigned integer or a pointer value.
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


//! makes char 8 portable across different platforms
typedef char char8_t;
//! makes char 8 portable across different platforms
typedef unsigned char uchar8_t;


/**
 * \brief BX Status. Data type representing status and error codes. (see BxStatus.h)
 */
// if you change this make sure to adapt BX_SUCESS / BX_FAILURE accordingly
typedef uint32_t BXSTATUS;

struct BxapiDeviceTagData_tag;
/// Opaque Pointer BxapiDeviceHandle. A handle value of null is considered invalid.
typedef BxapiDeviceTagData_tag* BxapiDeviceHandle;

struct BxapiStreamTagData_tag;
/// Opaque Pointer BxapiStreamHandle. A handle value of null is considered invalid.
typedef BxapiStreamTagData_tag* BxapiStreamHandle;



/// Maximum string length of a string in BxapiDeviceDiscoveryInfo.
#define BXAPI_DEVINFOMAXSTRINGLENGTH 255

#define BX_PACKING 8

// mark unused parameter to prevent warnings
#define BX_UNUSED(s_) ((void)s_)


#if defined (__cplusplus)
#   if !defined(EXTERN_C)
#       define EXTERN_C extern "C"
#   endif
#   if !defined(EXTERN_C_BEGIN)
#       define EXTERN_C_BEGIN extern "C" {
#   endif
#   if !defined(EXTERN_C_END)
#       define EXTERN_C_END }
#   endif
#else
#   if !defined(EXTERN_C_BEGIN)
#       define EXTERN_C_BEGIN
#   endif
#   if !defined(EXTERN_C_END)
#       define EXTERN_C_END
#   endif
#endif
