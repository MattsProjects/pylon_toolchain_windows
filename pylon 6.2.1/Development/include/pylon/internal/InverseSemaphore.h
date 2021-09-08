//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  Hartmut Nebelung
//-----------------------------------------------------------------------------
/*!
\file
*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __INVERSESEMAPHORE_H__
#define __INVERSESEMAPHORE_H__

#include <pylon/stdinclude.h>    // Do not remove as GenApi::LockableObject needs it
#include <pylon/internal/AlertableWaitObject.h>

#pragma warning( push )
#pragma warning( disable: 4251 ) // class xxx needs to have dll-interface

namespace Pylon
{

    class PYLONBASE_API CInverseSemaphore
    {
    public:
        explicit CInverseSemaphore( unsigned max = 10 );
        unsigned Increment();
        unsigned Decrement();
        unsigned UseCount() const;
        void ReInitialize( unsigned max );
        bool WaitForClearance( unsigned timeout = INFINITE );
    private:
        CInverseSemaphore( const CInverseSemaphore& );
        CInverseSemaphore& operator=( const CInverseSemaphore& );
    private:
        unsigned m_UseCount;
        unsigned m_MaxUseCount;
        AlertableWaitObject m_Guard;
        mutable CLock m_lock;
    };
}

#pragma warning( pop )

#endif
