//-----------------------------------------------------------------------------
//  Copyright (C) 2016-2017 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief DLL specific settings.
 * \ingroup public
 */
#pragma once

#if defined (_MSC_VER) && defined (_WIN32)

#   ifdef BXAPI_EXPORTS
#       define BX_API __declspec(dllexport)    ///< export functions, data, and objects
#   else
#       define BX_API __declspec(dllimport)    ///< import functions, data, and objects
#   endif

#   define BX_CDECL __cdecl

#   define USE_WPP_EVENT_TRACING 1 ///< WPP event tracing

#elif defined(__GNUC__) && defined(__linux__)

#   ifdef BXAPI_EXPORTS
#        define BX_API __attribute__((visibility("default")))
#   else
#        define BX_API
#   endif

#   if defined(__i386) || defined(__i386__) || defined(_M_IX86)
// cdecl is only needed on 32 bit intel platforms, causes attribute ignored warning when used on 64 bit or non-intel builds
#       define BX_CDECL __attribute__((__cdecl__))
#   else
#       define BX_CDECL
#   endif

#   define __stdcall

#   define BX_PACKING 8    ///< packing
#else

#error "Unsupported platform"

#endif

#define BX_CALL BX_CDECL

#define BX_COUNTOF(array_) (sizeof(array_) / sizeof(array_[0]))

