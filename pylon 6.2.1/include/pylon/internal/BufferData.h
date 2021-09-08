//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief Contains a data class holding all buffer relevant data
*/

#ifndef INCLUDED_BUFFERDATA_H_04040164
#define INCLUDED_BUFFERDATA_H_04040164

#include <new>
#include <boost/shared_ptr.hpp>
#include <Base/GCException.h>
#include <pylon/StreamGrabber.h>

namespace Pylon
{
    ///data class holding all buffer relevant data
    class CBufferData
    {
    public:
        //create buffer
        CBufferData()
            : bufferSize( 0 )
            , buffer( NULL )
            , factoryContext( 0 )
            , externalBufferUsed( false )
            , streamBufferHandle( 0 )
            , grabSessionId( 0 )
        {
        }

        //function for creating buffer data
        static CBufferData* New( size_t bufferSize, void* externalBuffer = NULL, intptr_t theFactoryContext = 0 )
        {
            CBufferData* pBufferData = NULL;
            try
            {
                pBufferData = new CBufferData();

                pBufferData->factoryContext = theFactoryContext;
                pBufferData->buffer = externalBuffer != NULL ? externalBuffer : new char[bufferSize];
                pBufferData->externalBufferUsed = externalBuffer != NULL;
                pBufferData->bufferSize = bufferSize;
            }
            catch (const std::bad_alloc& e)
            {
                throw BAD_ALLOC_EXCEPTION( "Out of memory. %s", e.what() );
            }
            catch (...)
            {
                delete pBufferData;
                throw;
            }
            return pBufferData;
        }


        //destroy
        ~CBufferData()
        {
            if (!externalBufferUsed)
            {
                char* p = reinterpret_cast<char*>(buffer);
                buffer = 0;
                delete[] p;
            }
        }

        //buffer props
        size_t bufferSize; ///<size of the allocated buffer
        void* buffer; ///<holds the pointer to the allocated buffer
        intptr_t factoryContext; ///<context information from the factory of the buffer data
        bool externalBufferUsed; ///<indicates the usage of an external buffer, this buffer is not deleted

        //used by grab engine
        StreamBufferHandle streamBufferHandle; ///<handle when registered at streamgrabber
        size_t grabSessionId; ///<used for checking that the handle belongs to the current grab session
        boost::shared_ptr<CBufferData> m_selfReference; ///<needed for queueing into stream grabber, set when put into queue, is released when retrieving result

    private:
        ///The buffer object is not copyable
        CBufferData( const CBufferData& );
        ///The buffer object is not copyable
        void operator = ( const CBufferData& );
    };
}

#endif /* INCLUDED_BUFFERDATA_H_04040164 */
