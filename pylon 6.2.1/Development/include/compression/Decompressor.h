//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2019-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  MP
//-----------------------------------------------------------------------------
/**
* \file
* \brief Declaration of the CDecompressor class
*/
#pragma once

#include <compression/Compression.h>
#include <cstddef>
#include <cstdint>

namespace Compression
{

#ifdef _MSC_VER
#   pragma pack(push, COMPRESSION_API_PACKING)
#endif /* _MSC_VER */

    /*!
    \enum ECompressionStatus
    \brief Status of a grab buffer with compressed data.

           It is possible that images could not be compressed properly by the camera (if the amount of data required for
           compressing an image exceeds the desired compression ratio). If an image was compressed successfully, it will
           have the compression status CompressionStatus_Ok.
    */
    enum ECompressionStatus
    {
        CompressionStatus_Ok,                           //!< Buffer was compressed properly.
        CompressionStatus_BufferOverflow,               //!< Size of compressed image exceeded desired compression ratio.
        CompressionStatus_Error                         //!< Generic error.
    };

    /*!
    \enum EEndianness
    \brief Endianness for parsing the grab buffer as defined for the camera technology used.

           If not known, Endianness_Auto can be used to detect the endianness automatically. However, this may take longer.
    */
    enum EEndianness
    {
        Endianness_Little,                              //!< Little endian (e.g., as used in USB3 Vision).
        Endianness_Big,                                 //!< Big endian (e.g., as used in GigE Vision).
        Endianness_Auto                                 //!< Try to detect endianness automatically.
    };

    /*!
    \struct CompressionInfo_t
    \brief The struct containing information about a grab buffer.

           You can find more information about the usage of this struct in the description of
           the CDecompressor class.
    */
    struct COMPRESSION_API CompressionInfo_t
    {
        bool                hasCompressedImage;         ///< True if grab buffer provided contains a compressed image (otherwise false if buffer is already decompressed).
        ECompressionStatus  compressionStatus;          ///< Status of compression (see ECompressionStatus).
        bool                lossy;                      ///< True if image was compressed lossily (otherwise false if it was compressed losslessly).
        uint32_t            pixelFormat;                ///< Pixel format of compressed image (PFNC32 value see https://www.emva.org/wp-content/uploads/PFNC.h)
        size_t              width;                      ///< Width (in pixels) of compressed image.
        size_t              height;                     ///< Height (in pixels) of compressed image.
        size_t              offsetX;                    ///< X offset (in pixels) of compressed image.
        size_t              offsetY;                    ///< Y offset (in pixels) of compressed image.
        size_t              paddingX;                   ///< X padding (line padding; in bytes) of compressed image.
        size_t              paddingY;                   ///< Y padding (image padding; in bytes) of compressed image.
        size_t              decompressedImageSize;      ///< Size (in bytes) required for decompressed image (only valid if hasCompressedImage is true).
        size_t              decompressedPayloadSize;    ///< Size (in bytes; including chunk data) required for decompressed payload (only valid if hasCompressedImage is true).

        /*!
        \brief Creates and initializes a compression info struct.
        \error
        Does not throw C++ exceptions.
        */
        CompressionInfo_t();
    };

    /*!
    \class CDecompressor
    \brief Provides convenient support for image decompression.

           A decompressor requires a compression descriptor in order to be able to decompress images. You can set
           a compression descriptor via the constructor or the SetCompressionDescriptor method (in both cases,
           either using the node map or manually).

           A compression descriptor can be identified via a hash. This hash can be used to identify the matching
           compression descriptor for a particular compressed image. It can be computed using the
           ComputeCompressionDescriptorHash method or retrieved from the camera, decompressor, or a grab buffer
           using one of the GetCompressionDescriptorHash methods.

           Grab buffers may contain different kinds of data. You can use the
           decompressor's GetCompressionInfo method to distinguish between them. For that to work, a
           grab buffer must have been received successfully and it must contain the
           payload type chunk.

           If compression info for the grab buffer provided is available,
           GetCompressionInfo returns true and you will receive the compression info
           via the CompressionInfo_t struct.
           If the field hasCompressedImage in the struct is true, the grab buffer
           contains a compressed image. In this case, you should check the compressionStatus
           field in the struct to check whether the camera was able to compress
           the image properly. The camera can't compress an image if the amount of
           data required for compressing the image exceeds the desired compression ratio.
           The image can be decompressed if compressionStatus is CompressionStatus_Ok.
           If the field hasCompressedImage in the struct is false, the grab buffer
           contains an already decompressed image. In this case, the decompressedImageSize
           and decompressedPayloadSize fields will not be used. All other fields contain
           information about the decompressed data.
    */
    class COMPRESSION_API CDecompressor
    {
    public:
        /*!
        \brief Creates an empty decompressor without compression descriptor.

               This constructor does not initialize the decompressor with a compression descriptor. You will have to
               initialize the decompressor first by using the SetCompressionDescriptor method in order to be able to
               decompress images. You will get an exception if you access methods that require the decompressor
               to be initialized (see method descriptions for which methods are affected by that precondition).
        \error
        Throws an exception if no memory can be allocated.
        */
        CDecompressor();

        /*!
        \brief Creates a decompressor by copying from another decompressor.
        \param[in] decompressor Decompressor to copy from during initialization.
        \error
        Throws an exception if no memory can be allocated.
        */
        explicit CDecompressor( const CDecompressor& decompressor );

        /*!
        \brief Creates a decompressor and initializes it with the compression descriptor provided.
        \param[in] pCompressionDescriptor Pointer to the compression descriptor. This parameter must not be NULL.
        \param[in] sizeCompressionDescriptor Size of the data (in bytes) of the compression descriptor.
        \error
        Throws an exception if no memory can be allocated or the compression descriptor provided is invalid (e.g., because it is corrupt)
        or incompatible (e.g., because a compression descriptor of a newer compression implementation is passed).
        */
        CDecompressor( const void* pCompressionDescriptor, size_t sizeCompressionDescriptor );

        /*!
        \brief Destroys the decompressor instance.
        \error
        Does not throw C++ exceptions.
        \threading
        This method is thread-safe.
        */
        ~CDecompressor();

        /*!
        \brief Determines whether the decompressor already has a compression descriptor.
        \return Returns true if the decompressor is already initialized with a compression descriptor or false otherwise.
        \error
        Does not throw C++ exceptions.
        \threading
        This method is thread-safe.
        */
        bool HasCompressionDescriptor() const;

        /*!
        \brief Resets the compression descriptor in the decompressor.
        \note After calling this method, no images can be decompressed by the decompressor because it is
              back in uninitialized state.
        \error
        Does not throw C++ exceptions.
        \threading
        This method is thread-safe.
        */
        void ResetCompressionDescriptor();

        /*!
        \brief Initializes a decompressor with the compression descriptor provided.
        \param[in] pCompressionDescriptor Pointer to the compression descriptor. This parameter must not be NULL.
        \param[in] sizeCompressionDescriptor Size of the data (in bytes) of the compression descriptor.
        \error
        Throws an exception if no memory can be allocated or the compression descriptor provided is invalid (e.g., because it is corrupt)
        or incompatible (e.g., because a compression descriptor of a newer compression implementation is passed).
        \threading
        This method is thread-safe.
        */
        void SetCompressionDescriptor( const void* pCompressionDescriptor, size_t sizeCompressionDescriptor );

        /*!
        \brief Gets the currently set compression descriptor.

               This method requires that a compression descriptor has been set previously via the constructor or
               the SetCompressionDescriptor method. You can determine this via the HasCompressionDescriptor method.
        \param[out] pCompressionDescriptor Pointer to the buffer that will receive the compression descriptor or
                    NULL if you only want to get the size of the buffer for buffer allocation.
        \param[in,out] pSizeCompressionDescriptor On input, the variable specifies the size of the buffer (in bytes)
                       for the compression descriptor (if pCompressionDescriptor is not NULL).
                       On output, the variable will receive the actual buffer size required for the current
                       compression descriptor.
                       This parameter must not be NULL.
        \error
        Throws an exception if the decompressor has no compression descriptor set or the input parameters are
        invalid (e.g., if the size provided is not sufficient to hold the compression descriptor).
        \threading
        This method is thread-safe.
        */
        void GetCompressionDescriptor( void* pCompressionDescriptor, size_t* pSizeCompressionDescriptor ) const;

        /*!
        \brief Gets compression information about a particular grab buffer.
        \param[out] compressionInfo Reference to the struct that will receive the compression information if the grab buffer contains such information.
        \param[in] pGrabBuffer Pointer to the grab buffer that holds the compressed data. This parameter must not be NULL.
        \param[in] payloadSize Payload size (in bytes) of the data received (must be less or equal to the size of the grab buffer).
        \param[in] endianness Endianness of the grab buffer's content. If not known, auto detection can be used.
        \return Returns true if compression information could be extracted from the the grab buffer or false otherwise.
        \error
        Throws an exception if the input parameters are invalid.
        \threading
        This method is thread-safe.
        */
        static bool GetCompressionInfo( CompressionInfo_t& compressionInfo, const void* pGrabBuffer, size_t payloadSize, EEndianness endianness = Endianness_Auto );

        /*!
        \brief Computes the hash for a given compression descriptor.
        \param[out] pHash Pointer to the buffer that will receive the compression descriptor hash or
                    NULL if you only want to get the size of the buffer for buffer allocation.
        \param[in,out] pSizeHash On input, the variable specifies the size of the buffer (in bytes)
                       for the compression descriptor hash (if pHash is not NULL).
                       On output, the variable will receive the actual buffer size required for the current
                       compression descriptor hash.
                       This parameter must not be NULL.
        \param[in] pCompressionDescriptor Pointer to the compression descriptor. This parameter must not be NULL.
        \param[in] sizeCompressionDescriptor Size of the data (in bytes) of the compression descriptor.
        \error
        Throws an exception if the input parameters are invalid (e.g., if the size provided is not sufficient to hold
        the compression descriptor hash).
        \threading
        This method is thread-safe.
        */
        static void ComputeCompressionDescriptorHash( void* pHash, size_t* pSizeHash, const void* pCompressionDescriptor, size_t sizeCompressionDescriptor );

        /*!
        \brief Gets the hash of the currently set compression descriptor.

               This method requires that a compression descriptor has been set previously via the constructor or
               the SetCompressionDescriptor method. You can determine this via the HasCompressionDescriptor method.
        \param[out] pHash Pointer to the buffer that will receive the compression descriptor hash or
                    NULL if you only want to get the size of the buffer for buffer allocation.
        \param[in,out] pSizeHash On input, the variable specifies the size of the buffer (in bytes)
                       for the compression descriptor hash (if pHash is not NULL).
                       On output, the variable will receive the actual buffer size required for the current
                       compression descriptor hash.
                       This parameter must not be NULL.
        \error
        Throws an exception if the decompressor has no compression descriptor set or the input parameters are
        invalid (e.g., if the size provided is not sufficient to hold the compression descriptor hash).
        \threading
        This method is thread-safe.
        */
        void GetCompressionDescriptorHash( void* pHash, size_t* pSizeHash ) const;

        /*!
        \brief Gets the hash of the compression descriptor that is required for decompressing the grab buffer provided.
        \param[out] pHash Pointer to the buffer that will receive the compression descriptor hash or
                    NULL if you only want to get the size of the buffer for buffer allocation.
        \param[in,out] pSizeHash On input, the variable specifies the size of the buffer (in bytes)
                       for the compression descriptor hash (if pHash is not NULL).
                       On output, the variable will receive the actual buffer size required for the current
                       compression descriptor hash.
                       This parameter must not be NULL.
        \param[in] pGrabBuffer Pointer to the grab buffer that holds the compressed data. This parameter must not be NULL.
        \param[in] payloadSize Payload size (in bytes) of the data received (must be less or equal to the size of the grab buffer).
        \param[in] endianness Endianness of the grab buffer's content. If not known, auto detection can be used.
        \error
        Throws an exception if the grab buffer does not contain compressed data, the data is corrupt, or the input
        parameters are invalid (e.g., if the size provided is not sufficient to hold the compression descriptor hash).
        \threading
        This method is thread-safe.
        */
        static void GetCompressionDescriptorHash( void* pHash, size_t* pSizeHash, const void* pGrabBuffer, size_t payloadSize, EEndianness endianness = Endianness_Auto );

        /*!
        \brief Gets size (in bytes) required for allocating buffers for decompressing the payloads during streaming.

               You can get the values for decompressedImageSize and extraChunkDataSize from features of the camera's
               node map.
        \param[in] decompressedImageSize Corresponds to the value that can be retrieved from the
                   BslImageCompressionBCBDecompressedImageSize feature in the camera node map.
        \param[in] extraChunkDataSize Corresponds to the value that can be retrieved from the
                   BslImageCompressionBCBExtraChunkDataSize feature in the camera node map.
        \return Returns the buffer size (in bytes) required for payload decompression.
        \error
        Does not throw C++ exceptions.
        \threading
        This method is thread-safe.
        */
        static size_t GetPayloadSizeForDecompression( size_t decompressedImageSize, size_t extraChunkDataSize );

        /*!
        \brief Decompresses the image of the grab buffer provided.

               In contrast to the DecompressPayload method, the output buffer will only receive the bare decompressed
               image without any chunk information.

               This method requires that a compression descriptor has been set previously via the constructor or
               the SetCompressionDescriptor method. You can determine this via the HasCompressionDescriptor method.

               The grab buffer provided must contain a compressed image that has been received without errors.
        \param[out] pOutputBuffer Pointer to the buffer that will receive the decompressed image. This parameter must
                    not be NULL.
        \param[in,out] pSizeOutputBuffer On input, the variable specifies the size of the buffer (in bytes)
                       for the decompressed image (must be larger or equal to the value in the decompressedImageSize
                       field in the CompressionInfo_t struct received via the GetCompressionInfo method;
                       alternatively, the value from the BslImageCompressionBCBDecompressedImageSize feature of the
                       camera's node map can be used to get the image size required for decompression).
                       On output, the variable will receive the actual buffer size required for the decompressed image.
                       This parameter must not be NULL.
        \param[in] pGrabBuffer Pointer to the grab buffer that holds the compressed data. This parameter must not be NULL.
        \param[in] payloadSize Payload size (in bytes) of the data received (must be less or equal to the size of the grab buffer).
        \return Returns the struct with the compression information of the compressed image.
        \error
        Throws an exception if the grab buffer does not contain compressed data, the data is corrupt, the image cannot
        be decompressed, or the input parameters are invalid (e.g., if the size provided is not sufficient to hold the
        decompressed image).
        \threading
        This method is thread-safe.
        */
        CompressionInfo_t DecompressImage( void* pOutputBuffer, size_t* pSizeOutputBuffer, const void* pGrabBuffer, size_t payloadSize ) const;

        /*!
        \brief Decompresses the entire payload (including chunks and padding) of the grab buffer provided.

               In contrast to the DecompressImage method, the output buffer will receive the decompressed image
               and copy the chunk information (including the compression information) from the grab buffer. Therefore,
               the result is a fully valid payload buffer with the decompressed image in its first chunk.

               This method requires that a compression descriptor has been set previously via the constructor or
               the SetCompressionDescriptor method. You can determine this via the HasCompressionDescriptor method.

               The grab buffer provided must contain a compressed image that has been received without errors.
        \param[out] pOutputBuffer Pointer to the buffer that will receive the decompressed payload. This parameter must
                    not be NULL.
        \param[in,out] pSizeOutputBuffer On input, the variable specifies the size of the buffer (in bytes)
                       for the decompressed payload (must be larger or equal to the value in the decompressedPayloadSize
                       field in the CompressionInfo_t struct received via the GetCompressionInfo method;
                       alternatively, the GetPayloadSizeForDecompression method can be used to get the payload
                       size required for decompression).
                       On output, the variable will receive the actual buffer size required for the decompressed payload.
                       This parameter must not be NULL.
        \param[in] pGrabBuffer Pointer to the grab buffer that holds the compressed data. This parameter must not be NULL.
        \param[in] payloadSize Payload size (in bytes) of the data received (must be less or equal to the size of the grab buffer).
        \return Returns the struct with the compression information about the compressed payload.
        \error
        Throws an exception if the grab buffer does not contain compressed data, the data is corrupt, the payload cannot
        be decompressed, or the input parameters are invalid (e.g., if the size provided is not sufficient to hold the
        decompressed payload).
        \threading
        This method is thread-safe.
        */
        CompressionInfo_t DecompressPayload( void* pOutputBuffer, size_t* pSizeOutputBuffer, const void* pGrabBuffer, size_t payloadSize ) const;

        /*!
        \brief Copies the decompressor.
        \param[in] decompressor The source decompressor.
        \return Returns a reference to the destination decompressor.
        \error
        Does not throw C++ exceptions.
        \threading
        This method is thread-safe.
        */
        CDecompressor& operator = ( const CDecompressor& decompressor );

        /*!
        \brief Compares this instance with another decompressor.
        \param[in] decompressor The decompressor on the right-hand side of the comparison.
        \return True if both decompressors are equal or false otherwise.
        \error
        Does not throw C++ exceptions.
        \threading
        This method is thread-safe.
        */
        bool operator == ( const CDecompressor& decompressor );

    private:
        struct Impl_t;

        Impl_t* m_pImpl;
    };

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

} //namespace Compression