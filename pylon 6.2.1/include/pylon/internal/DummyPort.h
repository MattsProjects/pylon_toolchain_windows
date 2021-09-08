#pragma once

#include <pylon/stdinclude.h>
#include <GenApi/PortImpl.h>
#include <boost/noncopyable.hpp>


namespace Pylon
{
    class CDummyPort : public GenApi::CPortImpl
        , private boost::noncopyable
    {
    public:
        CDummyPort()
        {
            ;
        }
        ~CDummyPort()
        {
            ;
        }

    public:
        //! Get the access mode of the node
        virtual GenApi::EAccessMode GetAccessMode() const
        {
            return GenApi::RW;
        }

        //! Reads a chunk of bytes from the port
        virtual void Read( void* pBuffer, int64_t Address, int64_t Length )
        {
            PYLON_UNUSED( pBuffer );
            PYLON_UNUSED( Address );
            PYLON_UNUSED( Length );
        }

        //! Writes a chunk of bytes to the port
        virtual void Write( const void* pBuffer, int64_t Address, int64_t Length )
        {
            PYLON_UNUSED( pBuffer );
            PYLON_UNUSED( Address );
            PYLON_UNUSED( Length );
        }
    };
}
