#pragma once

// simple portable critical section/mutex implementation so we don't have to add dependencies to other libraries
// just include and go!

#include <pylon/Platform.h>

#if defined(PYLON_WIN_BUILD)
#   include <windows.h>
#elif defined(PYLON_UNIX_BUILD)
#   include <pthread.h>
#else
#   error Invalid platform
#endif

namespace Pylon
{

#if defined(PYLON_WIN_BUILD)
    // simple portable mutex implementation so we don't have to add dependencies to other libraries
    class CSimpleMutex
    {
    public:
        CSimpleMutex()
        {
            // we even use spins in the default case
            ::InitializeCriticalSectionAndSpinCount( &m_cs, 4000 );
        }

        CSimpleMutex( unsigned int spinCount )
        {
            ::InitializeCriticalSectionAndSpinCount( &m_cs, spinCount );
        }

        ~CSimpleMutex()
        {
            ::DeleteCriticalSection( &m_cs );
        }

    public:
        void Lock()
        {
            ::EnterCriticalSection( &m_cs );
        }

        void Unlock()
        {
            ::LeaveCriticalSection( &m_cs );
        }
    protected:
        CRITICAL_SECTION m_cs;
    };
#elif defined(PYLON_UNIX_BUILD)
    class CSimpleMutex
    {
    public:
        CSimpleMutex()
        {
            // create a recursive mutex
            ::pthread_mutexattr_t attr;
            ::pthread_mutexattr_init( &attr );
            ::pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE );

            ::pthread_mutex_init( &m_mutex, &attr );

            ::pthread_mutexattr_destroy( &attr );
        }

        CSimpleMutex( unsigned int spinCount )
        {
            // create a recursive mutex (spin count is not supported on pthreads
            ::pthread_mutexattr_t attr;
            ::pthread_mutexattr_init( &attr );
            ::pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE );

            ::pthread_mutex_init( &m_mutex, &attr );

            ::pthread_mutexattr_destroy( &attr );
        }

        ~CSimpleMutex()
        {
            ::pthread_mutex_destroy( &m_mutex );
        }

    public:
        void Lock()
        {
            ::pthread_mutex_lock( &m_mutex );
        }

        void Unlock()
        {
            ::pthread_mutex_unlock( &m_mutex );
        }
    protected:
        pthread_mutex_t m_mutex;
    };
#else
#   error Invalid platform
#endif

    // simple auto lock class for CSimpleMutex
    class CScopedSimpleLock
    {
    public:
        CScopedSimpleLock( CSimpleMutex& m )
            :m_mutex( m )
        {
            m_mutex.Lock();
        }

        ~CScopedSimpleLock()
        {
            m_mutex.Unlock();
        }
    private:
        // noncopyable
        CScopedSimpleLock( const CScopedSimpleLock& );
        CScopedSimpleLock& operator=( const CScopedSimpleLock& );

    private:
        CSimpleMutex& m_mutex;
    };

} // namespace
