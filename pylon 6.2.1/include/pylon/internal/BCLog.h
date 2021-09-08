//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2008-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file  BCLog.h
\brief Simple logging with categories and levels.
*/

#if _MSC_VER > 1000
#pragma once
#endif

#include <stdarg.h>
#include <cstddef>
#include "../Platform.h"

#ifndef BC_LOG_H_INCLUDED__
#define BC_LOG_H_INCLUDED__

#ifdef _LIB
    // static link library
#   define BCLOG_API
#else
    // dynamic link library
#   ifdef BCLOG_EXPORTS
#       define BCLOG_API APIEXPORT
#   else
#       define BCLOG_API APIIMPORT
#   endif
#endif

/// implements a simple inline function to retrive a CatID for a given MessageType
/// this is the preferred way of obtaining CatIDs since it won't call LogGetCatID on every trace call
#define BCLOG_IMPLEMENT_GET_CATID_FUNCTION(funcName, catName)         \
inline bclog::LogCatID funcName(void)                                 \
{                                                                     \
    static const bclog::LogCatID catID = bclog::LogGetCatID(catName); \
    return catID;                                                     \
}

namespace bclog
{

    // category ID
    typedef size_t LogCatID;

    /// log levels
    enum LogLevel
    {
        /// Output only for developers. May not be readable/understandable by non developers
        lvDebug = 0x0010,

        /// informational message such as 'Setting paramater value'. These outputs may occur quite often so it is likely to be configured away.
        lvInfo = 0x0020,

        /// informational message but occurences are more rare than tlInfo like 'initializing camera'
        lvNotice = 0x0040,

        /// warning message use if something happens which actually shouldn't but can be handled correctly
        /// or doesn't lead to unpredicted results such as 'parameter out of range using default value'
        lvWarning = 0x0080,

        /// This message describes an error. Something which shouldn't happen such as 'Could not talk to camera' or 'file not found'
        lvError = 0x0100,

        /// A catastrophic failure such as 'camera about to explode, run for your life!'
        lvCritical = 0x0200
    };

    /// get a catID for a LogCategoryName (you should use the BCLOG_IMPLEMENT_GET_CATID_FUNCTION macro instead of calling this function directly)
    BCLOG_API LogCatID CDECL LogGetCatID( const char* pszLogCatName ) throw();

    /// printf like logging with va list
    BCLOG_API bool CDECL LogTraceVA( LogCatID logCatID, LogLevel logLevel, const char* pszFormat, va_list va ) throw();
    /// printf like logging. CatID can be retrieved by the LogGetCatID function
    BCLOG_API bool CDECL LogTrace( LogCatID logCatID, LogLevel logLevel, const char* pszFormat, ... ) throw();

    /// disable logging. This can be useful if you deinitialize the underlying logging library
    BCLOG_API bool CDECL LogEnable( bool enableLogging ) throw();

} // namespace bclog

#endif // BC_LOG_H_INCLUDED__
