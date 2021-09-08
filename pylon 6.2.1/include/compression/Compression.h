//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2019-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  MP
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief DLL specific settings.
 */
#pragma once

#ifdef _WIN32

#   ifndef COMPRESSION_API_STATIC
#       ifdef COMPRESSION_API_EXPORTS
#          define COMPRESSION_API __declspec(dllexport)    ///< export functions, data, and objects
#       else
#           define COMPRESSION_API __declspec(dllimport)    ///< import functions, data, and objects
#      endif
#   else
#       define COMPRESSION_API
#   endif

#   define COMPRESSION_API_CALL __cdecl ///< calling convention

#   define COMPRESSION_API_PACKING 8    ///< packing

#else

#   ifndef COMPRESSION_API_STATIC
#      ifdef COMPRESSION_API_EXPORTS
#           define COMPRESSION_API __attribute__((visibility("default")))
#      else
#           define COMPRESSION_API
#      endif
#   else
#       define COMPRESSION_API
#   endif

#   define COMPRESSION_API_CALL //__attribute__((cdecl))

#   define __stdcall

#   define COMPRESSION_API_PACKING 8    ///< packing

#endif
