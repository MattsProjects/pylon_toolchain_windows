//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2016 Basler
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief DLL specific settings.
 */
#pragma once

#ifdef _WIN32

#ifdef UXAPI_EXPORTS
#define UX_API __declspec(dllexport)    ///< export functions, data, and objects
#else
#define UX_API __declspec(dllimport)    ///< import functions, data, and objects
#endif

#define UX_CALL __cdecl ///< calling convention

#define UX_PACKING 8    ///< packing

#define USE_WPP_EVENT_TRACING 1 ///< WPP event tracing

#else

#   ifdef UXAPI_EXPORTS
#        define UX_API __attribute__((visibility("default")))
#   else
#        define UX_API
#   endif
#   define UX_CALL //__attribute__((cdecl))

#   define __stdcall

#    define UX_PACKING 8    ///< packing

#endif


