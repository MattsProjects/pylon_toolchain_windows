//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief   Converts nodemap chunk data to GrabResult data
*/

#ifndef INCLUDED_CHUNKTOGRABRESULTDATACONVERTER_H_1063151
#define INCLUDED_CHUNKTOGRABRESULTDATACONVERTER_H_1063151

#include <pylon/internal/ResultPrivate.h>
#include <pylon/PixelTypeMapper.h>
#include <GenApi/INodeMap.h>
namespace Pylon
{
    /*!
    \class  CChunkToGrabResultDataConverter
    \brief  Converts nodemap chunk data to GrabResult data
    */
    class CChunkToGrabResultDataConverter
    {
    public:
        CChunkToGrabResultDataConverter()
            : m_attached( false )
        {
        }

        ~CChunkToGrabResultDataConverter()
        {
        }

        void AttachToNodeMap( GENAPI_NAMESPACE::INodeMap* nodemap )
        {
            //attach to pointers
            m_psChunkStride = nodemap->GetNode( "ChunkStride" );
            m_psChunkOffsetX = nodemap->GetNode( "ChunkOffsetX" );
            m_psChunkOffsetY = nodemap->GetNode( "ChunkOffsetY" );
            m_psChunkWidth = nodemap->GetNode( "ChunkWidth" );
            m_psChunkHeight = nodemap->GetNode( "ChunkHeight" );
            m_psChunkPixelFormat = nodemap->GetNode( "ChunkPixelFormat" );
            m_pPixelTypeMapper.SetPixelFormatEnumNode( m_psChunkPixelFormat.IsValid() ? &*m_psChunkPixelFormat : NULL );
            m_attached = true;
        }

        void DetachFromNodeMap()
        {
            //detach from pointers
            m_psChunkStride = NULL;
            m_psChunkOffsetX = NULL;
            m_psChunkOffsetY = NULL;
            m_psChunkWidth = NULL;
            m_psChunkHeight = NULL;
            m_psChunkPixelFormat = NULL;
            m_attached = false;
        }

        template<typename U, typename GrabResultT>
        void SetResultData( GrabResultT& result ) const
        {
            if (m_attached)
            {
                if (m_psChunkOffsetX.IsValid() && IsReadable( m_psChunkOffsetX->GetAccessMode() ))
                {
                    result.SetOffestX( static_cast<U>(m_psChunkOffsetX->GetValue()) );
                }
                if (m_psChunkOffsetY.IsValid() && IsReadable( m_psChunkOffsetY->GetAccessMode() ))
                {
                    result.SetOffsetY( static_cast<U>(m_psChunkOffsetY->GetValue()) );
                }
                if (m_psChunkWidth.IsValid() && IsReadable( m_psChunkWidth->GetAccessMode() ))
                {
                    result.SetSizeX( static_cast<U>(m_psChunkWidth->GetValue()) );
                }
                if (m_psChunkHeight.IsValid() && IsReadable( m_psChunkHeight->GetAccessMode() ))
                {
                    result.SetSizeY( static_cast<U>(m_psChunkHeight->GetValue()) );
                }

                if (m_psChunkPixelFormat.IsValid() && IsReadable( m_psChunkPixelFormat->GetAccessMode() ))
                {
                    EPixelType pixelType = m_pPixelTypeMapper.GetPylonPixelTypeFromNodeValue( m_psChunkPixelFormat->GetIntValue() );
                    result.SetPixelType( pixelType );
                }

                if (m_psChunkStride.IsValid() && IsReadable( m_psChunkStride->GetAccessMode() ))
                {
                    size_t chunkStride = static_cast<U>(m_psChunkStride->GetValue());

                    if (chunkStride != 0) //some older camera devices may deliver 0
                    {
                        size_t lineStride = 0;
                        if (Pylon::ComputeStride( lineStride, result.GetPixelType(), result.GetSizeX(), 1 ))
                        {
                            --lineStride; //stride with padding can be computed in most cases
                            if (chunkStride >= lineStride)
                            {
                                result.SetPaddingX( static_cast<U>(chunkStride - lineStride) );
                            }
                        }
                    }
                }
            }
        }

        bool IsAttached() const
        {
            return m_attached;
        }

    private:

        GENAPI_NAMESPACE::CIntegerPtr m_psChunkStride; ///< a node that is carrying information that is not in GrabResult when ChunkMode is on
        GENAPI_NAMESPACE::CIntegerPtr m_psChunkOffsetX; ///< a node that is carrying information that is not in GrabResult when ChunkMode is on
        GENAPI_NAMESPACE::CIntegerPtr m_psChunkOffsetY; ///< a node that is carrying information that is not in GrabResult when ChunkMode is on
        GENAPI_NAMESPACE::CIntegerPtr m_psChunkWidth; ///< a node that is carrying information that is not in GrabResult when ChunkMode is on
        GENAPI_NAMESPACE::CIntegerPtr m_psChunkHeight; ///< a node that is carrying information that is not in GrabResult when ChunkMode is on
        GENAPI_NAMESPACE::CEnumerationPtr m_psChunkPixelFormat; ///< a node that is carrying information that is not in GrabResult when ChunkMode is on
        CPixelTypeMapper m_pPixelTypeMapper; ///<converts chunk type enum to pylon type enum
        bool m_attached; ///<indicates nothing attached, processing can be skipped, optimization
    };
}

#endif /* INCLUDED_CHUNKTOGRABRESULTDATACONVERTER_H_1063151 */
