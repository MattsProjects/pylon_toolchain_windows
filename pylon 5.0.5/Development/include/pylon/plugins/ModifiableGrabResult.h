//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2016 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief  Contains a class that extends the the pylon grab result by setter functions.
*/

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
        CModifiableGrabResult()
        {
        }

        CModifiableGrabResult( const GrabResult& rhs)
            : GrabResult(rhs)
        {
        }

        void SetPayloadType( EPayloadType payloadtype )
        {
            m_PayloadType = payloadtype;
        }

        void SetPixelType( EPixelType pixeltype )
        {
            m_PixelType = pixeltype;
        }

        void SetSizeX( int32_t sizex )
        {
            m_SizeX = sizex;
        }

        void SetSizeY( int32_t sizey )
        {
            m_SizeY = sizey;
        }

        void SetOffestX( int32_t offsetx )
        {
            m_OffsetX = offsetx;
        }

        void SetOffsetY( int32_t offsety )
        {
            m_OffsetY = offsety;
        }

        void SetPaddingX( int32_t paddingx )
        {
            m_PaddingX = paddingx;
        }

        void SetPaddingY( int32_t paddingy )
        {
            m_PaddingY = paddingy;
        }

        void SetError( uint32_t errorCode, String_t errorDescription)
        {
            m_Status = Failed;
            m_ErrorCode = errorCode;
            m_ErrorDescription = errorDescription;
        }

        void SetPayloadSize( uint64_t payloadSize)
        {
            m_PayloadSize = payloadSize;
        }
    };
}

#endif /* INCLUDED_MODIFIABLEGRABRESULT_H_2503735 */
