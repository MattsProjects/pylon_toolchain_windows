//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief todo
*/

#ifndef INCLUDED_GRABRESULTDATAIMPL_H_5902935
#define INCLUDED_GRABRESULTDATAIMPL_H_5902935

#include <boost/shared_ptr.hpp>
#include <pylon/GrabResultData.h>
#include <pylon/stdinclude.h>
#include <pylon/internal/BufferData.h>
#include <pylon/internal/ResultPrivate.h>
#include <pylon/ChunkParser.h>
#include <pylon/internal/ChunkToGrabResultDataConverter.h>
#include <pylon/internal/Utilities.h>   // for DestroyNodeMap()
#include <GenApi/NodeMapFactory.h>
#include <pylon/PylonDataComponent.h>
#include <pylon/PylonDataContainer.h>

#ifdef __GNUC__
#   undef GCC_VERSION
#   define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#   undef GCC_DIAGNOSTIC_AWARE
#   define GCC_DIAGNOSTIC_AWARE          (GCC_VERSION >= 40200)
#   undef GCC_DIAGNOSTIC_PUSH_POP_AWARE
#   define GCC_DIAGNOSTIC_PUSH_POP_AWARE (GCC_VERSION >= 40600)
#else
#   undef GCC_DIAGNOSTIC_AWARE
#   define GCC_DIAGNOSTIC_AWARE 0
#endif

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic push
#   endif
#   pragma GCC diagnostic ignored "-Wpragmas"   // gcc 4.3.6 doesn't know the following pragma
#endif

namespace Pylon
{

    /// The grab result properties
    class CGrabResultProperties
    {
        ///////////////////////////////////////////////////////////////////////
        //
        inline uint32_t ClipNegativeValues( int32_t value )
        {
            return static_cast<uint32_t>(value < 0 ? 0 : value);
        }


        ///////////////////////////////////////////////////////////////////////
        //
        inline uint64_t ClipNegativeValues( int64_t value )
        {
            return static_cast<uint64_t>(value < 0 ? 0 : value);
        }

    public:
        ///////////////////////////////////////////////////////////////////////
        //
        CGrabResultProperties()
            : m_Result()
            , m_pBuffer( nullptr )
            , m_bufferSize( 0 )
            , m_grabSucceeded( false )
            , m_payloadType( PayloadType_Undefined )
            , m_pixelType( PixelType_Undefined )
            , m_timeStamp( 0 )

            , m_width( 0 )
            , m_height( 0 )
            , m_offsetX( 0 )
            , m_offsetY( 0 )
            , m_paddingX( 0 )
            , m_paddingY( 0 )

            , m_payloadSize( 0 )
            , m_errorCode( 0 )
            , m_errorDescription( "" )
            , m_blockId( 0 )
        {
        }


        ///////////////////////////////////////////////////////////////////////
        //
        ~CGrabResultProperties()
        {
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void Clear()
        {
            m_pBuffer = nullptr;
            m_bufferSize = 0;
            m_grabSucceeded = false;
            m_blockId = 0;
            m_payloadType = PayloadType_Undefined;
            m_pixelType = PixelType_Undefined;
            m_timeStamp = 0;

            m_width = 0;
            m_height = 0;
            m_offsetX = 0;
            m_offsetY = 0;
            m_paddingX = 0;
            m_paddingY = 0;

            m_payloadSize = 0;
            m_errorCode = 0;
            m_errorDescription = "";
        }


        ///////////////////////////////////////////////////////////////////////
        //
        CGrabResultProperties( const GrabResult& r )
        {
            m_Result = r;
            m_pBuffer = r.Buffer();
            m_bufferSize = r.GetBufferSize();
            m_grabSucceeded = r.Succeeded();
            m_payloadType = r.GetPayloadType();
            m_pixelType = r.GetPixelType();
            m_timeStamp = r.GetTimeStamp();

            m_width = ClipNegativeValues( r.GetSizeX() );
            m_height = ClipNegativeValues( r.GetSizeY() );
            m_offsetX = ClipNegativeValues( r.GetOffsetX() );
            m_offsetY = ClipNegativeValues( r.GetOffsetY() );
            m_paddingX = ClipNegativeValues( r.GetPaddingX() );
            m_paddingY = ClipNegativeValues( r.GetPaddingY() );

            m_payloadSize = ClipNegativeValues( r.GetPayloadSize() );
            m_errorCode = r.GetErrorCode();
            m_errorDescription = r.GetErrorDescription();

            m_blockId = r.GetBlockID();

            PYLON_ASSERT2( "Inconsistent payload size.", GetPayloadSize() <= GetBufferSize() );
        }


        ///////////////////////////////////////////////////////////////////////
        //
        uint32_t GetSizeX() const
        {
            return m_width;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        EPixelType GetPixelType() const
        {
            return m_pixelType;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        const void* GetBuffer() const
        {
            return m_pBuffer;
        }


        size_t GetBufferSize() const
        {
            return m_bufferSize;
        }

        ///////////////////////////////////////////////////////////////////////
        //
        EPayloadType GetPayloadType()
        {
            return m_payloadType;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        size_t GetPayloadSize() const
        {
#if SIZE_MAX >= UINT64_MAX
            size_t payloadSize = static_cast<size_t>(m_payloadSize);
#else
            if (m_payloadSize > SIZE_MAX)
            {
                throw OUT_OF_RANGE_EXCEPTION( "PayloadSize too big." );
            }
            size_t payloadSize = static_cast<size_t>(m_payloadSize & SIZE_MAX);
#endif
            PYLON_ASSERT2( "Inconsistent payload size.", payloadSize <= GetBufferSize() );

            return payloadSize;

        }


        ///////////////////////////////////////////////////////////////////////
        //
        bool GrabSucceeded() const
        {
            return m_grabSucceeded;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPixelType( EPixelType pixeltype )
        {
            m_pixelType = pixeltype;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetSizeX( uint32_t sizex )
        {
            m_width = sizex;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetSizeY( uint32_t sizey )
        {
            m_height = sizey;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetOffestX( uint32_t offsetx )
        {
            m_offsetX = offsetx;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetOffsetY( uint32_t offsety )
        {
            m_offsetY = offsety;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPaddingX( uint32_t paddingx )
        {
            m_paddingX = paddingx;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        void SetPaddingY( uint32_t paddingy )
        {
            m_paddingY = paddingy;
        }


        ///////////////////////////////////////////////////////////////////////
        //
        CPylonDataContainer GetDataContainer() const
        {
            return CPylonDataContainer( m_Result );
        }


        ///////////////////////////////////////////////////////////////////////
        //
        size_t GetDataComponentCount() const
        {
            CPylonDataContainer container = CPylonDataContainer( m_Result );
            return container.GetDataComponentCount();
        }


        ///////////////////////////////////////////////////////////////////////
        //
        CPylonDataComponent GetDataComponent( size_t index )
        {
            CPylonDataContainer container = CPylonDataContainer( m_Result );
            if (index < container.GetDataComponentCount())
            {
                return container.GetDataComponent( index );
            }
            else
            {
                throw RUNTIME_EXCEPTION( "Parameter 'index' out of range." );
            }
        }

    protected:
        GrabResult m_Result;
        const void* m_pBuffer;
        size_t m_bufferSize;
        bool m_grabSucceeded;
        EPayloadType m_payloadType;
        EPixelType m_pixelType;
        uint64_t m_timeStamp;

        uint32_t m_width;
        uint32_t m_height;
        uint32_t m_offsetX;
        uint32_t m_offsetY;
        uint32_t m_paddingX;
        uint32_t m_paddingY;

        uint64_t m_payloadSize;
        uint32_t m_errorCode;
        String_t m_errorDescription;

        friend class CGrabResultData;

        uint64_t m_blockId;
    };


    ///hold the grab result data
    class CGrabResultData::CGrabResultDataImpl
    {
    public:
        //init
        CGrabResultDataImpl()
            : cameraContext( 0 )
            , serialNumber( 0 )
            , imageNumber( 0 )
            , skippedImageCount( 0 )
            , m_pEmptyNodeMap( nullptr )
            , grabResultProperties()

            , bufferData()

            , pSelfReliantChunkParser()
            , chunkToGrabResultDataConverter()

            , m_bufferContext( 0 )
        {
        }

        ///destroy
        ~CGrabResultDataImpl()
        {
            if (m_pEmptyNodeMap != nullptr)
            {
                DestroyNodeMap( m_pEmptyNodeMap );
            }
        }

        ///set defined state, called when grab result data returns for reuse
        void Clear()
        {
            cameraContext = 0;
            serialNumber = 0;
            imageNumber = 0;
            skippedImageCount = 0;

            grabResultProperties.Clear();

            //detach from buffer
            if (pSelfReliantChunkParser)
            {
                pSelfReliantChunkParser->DetachBuffer();
            }

            bufferData.reset();

            m_bufferContext = 0;
        }

        ///parse the chunk data
        void ProcessChunks()
        {
            if (pSelfReliantChunkParser && grabResultProperties.GrabSucceeded() && grabResultProperties.GetPayloadType() == PayloadType_ChunkData)
            {
                pSelfReliantChunkParser->AttachBuffer( grabResultProperties.GetBuffer(), grabResultProperties.GetPayloadSize() );
                chunkToGrabResultDataConverter.SetResultData<uint32_t>( grabResultProperties );
            }
        }

        ///return the correct node map
        GENAPI_NAMESPACE::INodeMap& GetChunkDataNodeMap()
        {
            if (pSelfReliantChunkParser)
            {
                return *pSelfReliantChunkParser->GetChunkDataNodeMap();
            }

            // lazy creation of the empty nodemap
            if (m_pEmptyNodeMap == nullptr)
            {
                m_pEmptyNodeMap = GENAPI_NAMESPACE::CNodeMapFactory::CreateEmptyNodeMap();
            }

            return *m_pEmptyNodeMap;
        }

        ///forward crc getter method result
        bool GetHasCRC() const
        {
            if (pSelfReliantChunkParser)
            {
                return pSelfReliantChunkParser->HasCRC();
            }
            return false;
        }

        ///forward crc getter method result
        bool CheckCRC() const
        {
            if (pSelfReliantChunkParser)
            {
                return pSelfReliantChunkParser->CheckCRC();
            }
            return false;
        }

        ///set the per result chunk parser
        void SetChunkParser( boost::shared_ptr<ISelfReliantChunkParser> pSelfReliantChunkParserNew )
        {
            //if a parser has been used detach it
            if (pSelfReliantChunkParser)
            {
                chunkToGrabResultDataConverter.DetachFromNodeMap();
            }
            //set the new parser if any
            pSelfReliantChunkParser = pSelfReliantChunkParserNew;
            //if new parser attach it the chunkToGrabResultDataConverter
            if (pSelfReliantChunkParserNew)
            {
                chunkToGrabResultDataConverter.AttachToNodeMap( pSelfReliantChunkParserNew->GetChunkDataNodeMap() );
            }
        }

        ///returns true if the result can update its properties from the chunk data itself
        bool CanAutoUpdateResultData() const
        {
            return chunkToGrabResultDataConverter.IsAttached();
        }

        bool GetChunkParsingActive() const
        {
            return pSelfReliantChunkParser != nullptr;
        }

        CPylonDataContainer GetDataContainer() const
        {
            return grabResultProperties.GetDataContainer();
        }

        size_t GetDataComponentCount() const
        {
            return grabResultProperties.GetDataComponentCount();
        }
      
        CPylonDataComponent GetDataComponent( size_t index )
        {
            return grabResultProperties.GetDataComponent( index );
        }

    public:
        intptr_t cameraContext; ///<the camera context, can be used for identifying the camera from which the result originated
        int64_t serialNumber; ///<the serial number of the image grabbed
        int64_t imageNumber; ///<the number of grabbed image according to the grab strategy
        int64_t skippedImageCount; ///<the number of images skipped before this image
        GENAPI_NAMESPACE::INodeMap* m_pEmptyNodeMap; ///<empty nodemap used when no self-reliant chunk parser is available
        CGrabResultProperties grabResultProperties; ///<the grab result properties

        boost::shared_ptr<CBufferData> bufferData; ///<see CBufferData.h
    protected:
        boost::shared_ptr<ISelfReliantChunkParser> pSelfReliantChunkParser; ///<handles the parsing of result specific chunk data
        CChunkToGrabResultDataConverter chunkToGrabResultDataConverter; ///<used for updating the grab result data structure when chunks active

    public:
        intptr_t m_bufferContext;
    };

}

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#       pragma GCC diagnostic warning "-Wpragmas"   // gcc 4.3.6 doesn't know the pragma
#   endif
#endif

#endif /* INCLUDED_GRABRESULTDATAIMPL_H_5902935 */
