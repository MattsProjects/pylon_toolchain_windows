//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2019-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  MP
//-----------------------------------------------------------------------------
/**
* \file
* \brief Declaration of the Exception class
*/
#pragma once

#include <compression/Compression.h>

#define DECLARE_COMPRESSION_EXCEPTION( name ) \
            class COMPRESSION_API name : public Exception \
            { \
            public: \
                name( const name& exception ); \
                name( const Exception& exception ); \
                name( const char* pDescription ); \
            }

namespace Compression
{

    /*!
    \class Exception
    \brief Provides an exception base class for different kinds of C++ exceptions.

           This exception base class cannot be instantiated directly. Use one of
           the derived classes below.
    */
    class COMPRESSION_API Exception
    {
    protected:
        /*!
        \brief Creates an exception by copying from another exception.
        \error Does not throw C++ exceptions.
        */
        Exception( const Exception& exception );
        /*!
        \brief Creates an exception with the given description.
        \param[in] pDescription Pointer to the description for this exception.
        \error Does not throw C++ exceptions.
        */
        Exception( const char* pDescription );

    public:
        /*!
        \brief Destroys the exception instance.
        \error Does not throw C++ exceptions.
        \threading The destructor is thread-safe.
        */
        ~Exception();

        /*!
        \brief Gets the description of this message.
        \return Returns the desciption of this message.
        \error Does not throw C++ exceptions.
        \threading This method is thread-safe.
        */
        virtual const char* GetDescription() const;

        /*!
        \brief Copies the exception.
        \param[in] exception The source exception.
        \return Returns a reference to the destination exception.
        \error Does not throw C++ exceptions.
        \threading This method is thread-safe.
        */
        Exception& operator = ( const Exception& exception );

    private:
        struct Impl_t;

        Impl_t* m_pImpl;
    };

    DECLARE_COMPRESSION_EXCEPTION( BadAllocException );
    DECLARE_COMPRESSION_EXCEPTION( InvalidArgumentException );
    DECLARE_COMPRESSION_EXCEPTION( RuntimeException );

} //namespace Compression