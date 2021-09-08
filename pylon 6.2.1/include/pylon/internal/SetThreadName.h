#pragma once

#ifndef PYLON_SET_THREAD_NAME_H_INCLUDED__
#define PYLON_SET_THREAD_NAME_H_INCLUDED__

#include <pylon/PylonLinkage.h>

#ifndef PYLON_NO_AUTO_IMPLIB
#   pragma comment(lib, PYLON_LIB_NAME( "ImplHelpers" ))
#endif

namespace Pylon
{
    ///////////////////////////////////////////////////////////////////////////
    // Sets the name for a specific thread or -1 to set the current therad. Parameter pszThreadname must be an ANSI string.
    void SetThreadName( unsigned long dwThreadID, const char* pszThreadName );

    ///////////////////////////////////////////////////////////////////////////
    // Sets the name for the calling thread. Parameter pszThreadname must be an ANSI string
    void SetCurrentThreadName( const char* pszThreadName )
    {
#if defined(_MSC_VER)
        SetThreadName( static_cast<unsigned long>(-1), pszThreadName );
#else // any other platform
        // unused
        pszThreadName;
#endif
    }
}

#endif
