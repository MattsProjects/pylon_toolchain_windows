//AG: Temporary File, needs to be removed somewhen
#pragma once

#include <pylon/WaitObject.h>

#if defined(PYLON_WIN_BUILD)
namespace Pylon
{
    // ----------------------------------------------------------------------
    /*
    This class is deprecated. Please use Pylon::WaitObjectEx instead.
    */
    // ----------------------------------------------------------------------
    class PYLONBASE_API
        // PYLON_DEPRECATED("This class is deprecated. Please use Pylon::WaitObjectEx instead.")
        AlertableWaitObject : public WaitObjectEx
    {
    public:
        AlertableWaitObject( bool manualReset = false, bool initiallySignalled = false );
        AlertableWaitObject( HANDLE h, bool duplicate = true );
    };
}
#endif

