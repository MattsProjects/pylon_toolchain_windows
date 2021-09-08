#pragma once

#if defined(PYLON_WIN_BUILD)

#include <vector>
#include <string>

#include <pylon/PylonUtility.h>
#include <pylon/PixelType.h>

namespace Pylon
{

#pragma warning(push)
#pragma warning(disable: 4251) // Pylon::CPylonPNGImage::m_messages' : class 'std::vector<_Ty>' needs to have dll-interface to be used by clients of class 'Pylon::CPNGImage'

    class PYLONUTILITY_API CPylonPNGImage
    {
    public:
        enum ErrorCodes
        {
            ecOK = 0
            , ecInvalidParams
            , ecInvalidPNGData
            , ecCouldNotCreatePNGStruct
            , ecCouldNotCreateInfoStruct
            , ecCouldNotReadIHDR
            , ecRawBufferTooSmall
            , ecRawBufferInvalid
            , ecDecodeError
            , ecFileNotFound
            , ecCouldNotOpenFile
            , ecOutOfMem
            // add new entries here

            , ecLastDoNotUse
        };

        enum ColorTypes
        {
            ctUnknown = 0
            , ctGray
            , ctPalette
            , ctRGB
        };

    public:
        CPylonPNGImage( void );
        CPylonPNGImage( void* pPixelData, size_t pixelDataSize );

        virtual ~CPylonPNGImage( void );

        ErrorCodes LoadImageFromMemory( const void* pDataIn, size_t sizeDataIn );
        ErrorCodes LoadImageFromFile( const char* pszFilename );

    public:
        //////////////////////////////////////////////////////////////////////////
        int GetHeight() const;

        //////////////////////////////////////////////////////////////////////////
        int GetWidth() const;

        //////////////////////////////////////////////////////////////////////////
        size_t GetBytesPerRow() const;

        //////////////////////////////////////////////////////////////////////////
        ColorTypes GetColorType() const;

        //////////////////////////////////////////////////////////////////////////
        int GetBitDepth() const;

        //////////////////////////////////////////////////////////////////////////
        int GetChannels() const;

        //////////////////////////////////////////////////////////////////////////
        const void* GetPixels() const;

        //////////////////////////////////////////////////////////////////////////
        PixelType GetPixelType() const;

        //////////////////////////////////////////////////////////////////////////
        static const char* GetErrorCodeText( ErrorCodes ec );

    protected:
        unsigned char* InternalGetRowBuffer( const size_t sizeNeeded );

    protected:
        int                         m_width;
        int                         m_height;
        size_t                      m_bytesPerRow;
        int                         m_bitDepth;
        ColorTypes                  m_colorType;
        int                         m_channels;

        std::vector<std::string>    m_messages;

        std::vector<unsigned char>  m_pixels;
        void* m_pCallerSuppliedBuffer;
        size_t                      m_callerSuppliedBufferSize;
    };

#pragma warning (pop)

} // namespace

#endif // PYLON_WIN_BUILD
