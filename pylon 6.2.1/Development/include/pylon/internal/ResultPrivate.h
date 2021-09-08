//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  Lutz Koschorreck
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the setter function for the GrabResult and the EventResult
objects
*/

#pragma once

#ifndef RESULTPRIVATE_H_INCLUDED_
#define RESULTPRIVATE_H_INCLUDED_

#include <limits.h>
#include <pylon/Platform.h>
#include <pylon/Result.h>

namespace Pylon
{
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    // class GrabResultPrivate
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class GrabResultPrivate : public GrabResult
    {
    public:
        ///////////////////////////////////////////////////////////////////////
        //
        GrabResultPrivate()
        {
        }


        ///////////////////////////////////////////////////////////////////////
        //
        GrabResultPrivate( const GrabResult& rhs )
            : GrabResult( rhs )
        {
        }


        ///////////////////////////////////////////////////////////////////////
        // assignment operator taking GrabResult as rhs
        GrabResultPrivate& operator = ( const GrabResult& rhs )
        {
            // we must cast here since GrabResult doesn't have an assignment operator
            const GrabResultPrivate& rhsPrivate = static_cast<const GrabResultPrivate&>(rhs);

            m_pContext = rhsPrivate.m_pContext;
            m_hBuffer = rhsPrivate.m_hBuffer;
            m_pBuffer = rhsPrivate.m_pBuffer;
            m_Status = rhsPrivate.m_Status;
            m_PayloadType = rhsPrivate.m_PayloadType;
            m_PixelType = rhsPrivate.m_PixelType;
            m_TimeStamp = rhsPrivate.m_TimeStamp;
            m_SizeX = rhsPrivate.m_SizeX;
            m_SizeY = rhsPrivate.m_SizeY;
            m_OffsetX = rhsPrivate.m_OffsetX;
            m_OffsetY = rhsPrivate.m_OffsetY;
            m_PaddingX = rhsPrivate.m_PaddingX;
            m_PaddingY = rhsPrivate.m_PaddingY;
            m_PayloadSize = rhsPrivate.m_PayloadSize;
            m_ErrorCode = rhsPrivate.m_ErrorCode;
            m_ErrorDescription = rhsPrivate.m_ErrorDescription;
            m_BlockID = rhsPrivate.m_BlockID;
            m_BufferSize = rhsPrivate.m_BufferSize;

            return *this;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetResult( StreamBufferHandle hBuffer, const void* pBuffer, const void* context, EGrabStatus grabStatus = GrabStatus_Grabbed )
        {
            m_hBuffer = hBuffer;
            m_pBuffer = pBuffer;
            m_pContext = context;
            m_Status = grabStatus;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetStatus( EGrabStatus grabStatus )
        {
            m_Status = grabStatus;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetBuffer( const void* pBuffer )
        {
            m_pBuffer = pBuffer;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetContext( const void* context )
        {
            m_pContext = context;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPayloadType( EPayloadType payloadType )
        {
            m_PayloadType = payloadType;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPixelType( EPixelType pixelType )
        {
            m_PixelType = pixelType;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetTimeStamp( uint64_t timeStamp )
        {
            m_TimeStamp = timeStamp;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetSizeX( int32_t sizeX )
        {
            m_SizeX = sizeX;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetSizeY( int32_t sizeY )
        {
            m_SizeY = sizeY;
        }


        ///////////////////////////////////////////////////////////////////////
        // TODO: Remove after all references have been renamed to SetOffsetX
        void SetOffestX( int32_t offsetX )
        {
            m_OffsetX = offsetX;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetOffsetX( int32_t offsetX )
        {
            m_OffsetX = offsetX;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetOffsetY( int32_t offsetY )
        {
            m_OffsetY = offsetY;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPaddingX( int32_t paddingX )
        {
            m_PaddingX = paddingX;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPaddingY( int32_t paddingY )
        {
            m_PaddingY = paddingY;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPayloadSize( uint64_t payloadSize )
        {
#if defined(PYLON_32_BUILD)
            if (payloadSize > SIZE_MAX)
            {
                throw OUT_OF_RANGE_EXCEPTION( "PayloadSize too big" );
            }
#endif
            m_PayloadSize = payloadSize;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetErrorDescription( const String_t& errorDescription )
        {
            m_ErrorDescription = errorDescription;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetErrorCode( uint32_t errorCode )
        {
            m_ErrorCode = errorCode;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void Init( void )
        {
            // remember the current values, so we can restore them later
            const void* pContext = m_pContext;
            StreamBufferHandle hBuffer = m_hBuffer;
            const void* pBuffer = m_pBuffer;
            size_t BufferSize = m_BufferSize;

            // delegate initialization to GrabResult to get correct default values
            // this will overwrite the complete GrabResult
            *this = GrabResult();

            // Restore the old values. Some TLs rely on these not being changed
            m_pContext = pContext;
            m_hBuffer = hBuffer;
            m_pBuffer = pBuffer;
            m_BufferSize = BufferSize;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetBlockID( uint64_t blockId )
        {
            m_BlockID = blockId;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetBufferSize( size_t sizeInBytes )
        {
            m_BufferSize = sizeInBytes;
        }

    };

    static_assert(sizeof( GrabResult ) == sizeof( GrabResultPrivate ), "GrabResultPrivate can only add member functions! You can't add additional variables.");


    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    // class EventResultSetter
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class EventResultSetter : public EventResult
    {
    public:
        ///////////////////////////////////////////////////////////////////////
        //
        void SetResultCode( uint32_t resultCode )
        {
            m_ReturnCode = resultCode;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetResultString( const String_t& strResult )
        {
            m_Message = strResult;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void ClearError()
        {
            m_Message = String_t();
            m_ReturnCode = 0;
        }
    };

    static_assert(sizeof( EventResultSetter ) == sizeof( EventResult ), "EventResultSetter can only add member functions! You can't add additional variables.");

} // namespace Pylon
#endif // __RESULTPRIVATE_H__

