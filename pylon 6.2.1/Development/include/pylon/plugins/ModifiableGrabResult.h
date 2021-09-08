//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief  Contains a class that extends the the pylon grab result by setter functions.
*/

#pragma once

#ifndef INCLUDED_MODIFIABLEGRABRESULT_H_2503735
#define INCLUDED_MODIFIABLEGRABRESULT_H_2503735

#include <pylon/Result.h>

namespace Pylon
{

    /*!
    \interface  CModifiableGrabResult
    \brief  Usable to modify grab result data.
    */
    class CModifiableGrabResult : public GrabResult
    {
    public:
        ///////////////////////////////////////////////////////////////////////
        //
        CModifiableGrabResult()
        {
        }


        ///////////////////////////////////////////////////////////////////////
        //
        CModifiableGrabResult( const GrabResult& rhs )
            : GrabResult( rhs )
        {
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
        //
        void SetOffestX( int32_t offsetX )
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
        void SetError( uint32_t errorCode, const String_t& errorDescription )
        {
            m_Status = GrabStatus_Failed;
            m_ErrorCode = errorCode;
            m_ErrorDescription = errorDescription;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPayloadSize( uint64_t payloadSize )
        {
            m_PayloadSize = payloadSize;
        }


        // m_BufferSize, m_Context, m_pContainer, m_hBuffer, m_Status left out intentionally
    };
}

#endif /* INCLUDED_MODIFIABLEGRABRESULT_H_2503735 */
