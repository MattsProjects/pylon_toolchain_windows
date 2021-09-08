//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2017 Basler
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief UXAPI specific type definitions
 */
#pragma once

#if defined(_MSC_VER) && defined(_WIN32)
#    if (_MSC_VER < 1600)

//! makes int 8 portable across different platforms
typedef char int8_t;
//! makes unsigned char portable across different platforms
typedef unsigned char uint8_t;

//! makes short portable across different platforms
typedef short int16_t;
//! makes unsigned short portable across different platforms
typedef unsigned short uint16_t;

//! makes __int32 portable across different platforms
typedef __int32 int32_t;
//! makes unsigned int32 portable across different platforms
typedef unsigned __int32 uint32_t;

//! makes int64 portable across different platforms
typedef __int64 int64_t;
//! makes unsigned int64 portable across different platforms
typedef unsigned __int64 uint64_t;

//! use a universal platform dependent int
typedef __int64 int_t;
//! use a universal platform dependent unsigned int
typedef unsigned __int64 uint_t;

#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
//! use a universal platform dependent unsigned int
typedef unsigned __int64 size_t;
#else
//! use a universal platform dependent unsigned int
typedef unsigned int size_t;
#endif
#define _SIZE_T_DEFINED
#endif

#ifndef _INTPTR_T_DEFINED
#ifdef  _WIN64
//! use a universal platform dependent int
typedef __int64 intptr_t;
#else
//! use a universal platform dependent int
typedef int intptr_t;
#endif
#define _INTPTR_T_DEFINED
#endif

#endif //_MSC_VER < 1600

#   include <stdint.h>

#else
//all non-MS compilers
#    define __STDC_LIMIT_MACROS
#   include <stddef.h>
#   include <stdint.h>

#    define _ASSERT assert

// INFINITE is defined at WIN32 platforms only
#ifndef INFINITE
#    define INFINITE (-1)
#endif

#endif

//! makes char 8 portable across different platforms
typedef char char8_t;
//! makes char 8 portable across different platforms
typedef unsigned char uchar8_t;

namespace uxapi {
    typedef void* WaitObjectHandle;
}


/**
 * \brief UX Status. Data type for representing status and error codes.
 */
typedef uint32_t UXSTATUS;


