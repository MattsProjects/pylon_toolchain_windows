//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
*/


#ifndef __PYLON_REFCOUNTED_H__
#define __PYLON_REFCOUNTED_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/stdinclude.h>

#if defined(_MSC_VER)
#   define INTERLOCKED_INCREMENT(x) InterlockedIncrement(reinterpret_cast<long *>(&x))
#   define INTERLOCKED_DECREMENT(x) InterlockedDecrement(reinterpret_cast<long *>(&x))
#elif defined(HAVE_CONFIG_H)
#   include <autoconf.h> // needed for __sync_fetch_and_add replacement macros
#   define INTERLOCKED_INCREMENT(x) (__sync_fetch_and_add (reinterpret_cast<long *>(&x), 1) + 1)
#   define INTERLOCKED_DECREMENT(x) (__sync_fetch_and_sub (reinterpret_cast<long *>(&x), 1) - 1)
#else
#   error Unsupported build tool chain
#endif

#include <assert.h>

namespace Pylon
{
    /**
    Very simple base class for refcounted classes.
    Currently no copying or assignment is supported!
    */
    class CRefCounted
    {
    public:

        unsigned long AddRef( void )
        {
            return INTERLOCKED_INCREMENT( m_nRefCount );
        }

        unsigned long Release( void )
        {
            assert( 0 < m_nRefCount );

            const unsigned long nRefCount( INTERLOCKED_DECREMENT( m_nRefCount ) );
            if (!nRefCount)
                Delete();

            return nRefCount;
        }

        unsigned long GetRefCount( void ) const
        {
            return m_nRefCount;
        }

        CRefCounted()
            : m_nRefCount( 0 )
        {
        }

        virtual ~CRefCounted( void )
        {
            assert( m_nRefCount == 0 );
        }

    protected:

        virtual void Delete( void )
        {
            delete this;
        }

    private:

        // assignment and copy construction currently not supported!!!
        CRefCounted( const CRefCounted& );
        CRefCounted& operator=( const CRefCounted& );

        unsigned long m_nRefCount;
    };

    template <class T>
    class CAutoReferenceT
    {
    public:
        CAutoReferenceT( T& t )
            : m_T( t )
        {
            m_T.AddRef();
        }

        ~CAutoReferenceT()
        {
            m_T.Release();
        }
    private:
        T& m_T;

        CAutoReferenceT( const CAutoReferenceT& );
        CAutoReferenceT& operator=( const CAutoReferenceT& );
    };

    typedef CAutoReferenceT<CRefCounted> CAutoReference;
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif
