//-----------------------------------------------------------------------------
//  Copyright (c) 2012-2021 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Declaration of the CUxStream class
 */
#pragma once

#include "UxDll.h"
#include "UxStatus.h"

#ifdef _MSC_VER
#   pragma pack(push, UX_PACKING)
#endif /* _MSC_VER */


/**
\brief This callback will be called when the number of images ready changes. There are several limitations, see below for further information.
\param[in] resultReadyCount Contains the number of images ready for processing or zero if no images are available anymore.
                            This value should only be used to check whether any images are available.
                            The count of images is passed for debugging purposes only.
\param[in] userContext User context, that has been provided when registering the callback.

\threading This callback is called from multiple threads inside the lock of the uxapi device or uxapi stream

\attention Use this callback only to signal other threads for further processing.
           You MUST NOT call any uxapi Methods from this callback. Doing so will result in undefined behavior and may crash the program.
           Furthermore it is not allowed to perform any time consuming operations in this callback, otherwise the device streaming the images
           will loose image data.
*/

typedef void (UX_CALL* UxapiStreamBufferReadyCallback)(size_t resultReadyCount, void* userContext);

namespace uxapi
{
    class CUxDevice;
    class CUxStreamImplBase;

    /// Payload types.
    enum PayloadTypes
    {
        PayloadType_Chunk = 0x4000,              //!< Generic chunk mode where the first chunk is not derived from any payload type. Used to transmit any combination of chunks.
        PayloadType_Image = 0x0001,              //!< Uncompressed image data.
        PayloadType_ImageExtendedChunk = 0x4001  //!< Support for Image extended chunk data. In this case, the Image must be the first chunk in the payload data.
    };

    /// Used for grabbing images
    class UX_API CUxStream
    {
    public:
        struct BufferHandle_s;  ///< Forward declaration.
        typedef BufferHandle_s* BufferHandle;   ///< Pointer to buffer handle.

        /// Grab result
        struct GrabResult
        {
            uint64_t     blockId;       ///< Block identifier.
            uint16_t     payloadType;   ///< Type of payload.
            uint64_t     timeStamp;     ///< Time stamp.
            uint32_t     pixelFormat;   ///< Pixel format.
            uint32_t     sizeX;         ///< Size in x-direction.
            uint32_t     sizeY;         ///< Size in y-direction.
            uint32_t     offsetX;       ///< Offset in x-direction.
            uint32_t     offsetY;       ///< Offset in y-direction.
            uint16_t     paddingX;      ///< Padding in x-direction.
            uint16_t     paddingY;      ///< Padding in y-direction.
            uint64_t     payloadSize;   ///< Payload size.
            uint64_t     streamResetCount;   ///< Counts how many time the stream has been reset. BlockId restarts with zero for every stream reset.

            BufferHandle hBuffer;       ///< Handle to buffer.
            void* pBuffer;       ///< Pointer to buffer.
            size_t       bufferSize;    ///< size of buffer in bytes.
            const void* pUserContext;  ///< User context.
            UXSTATUS     errorCode;     ///< Error code.
        };

    /**
    \brief Opens the stream.
    \return The status of the operation.

    \pre
    <ul>
    <li> The stream is closed.
    <li> The device supports streaming.
    </ul>

    \post
    <ul>
    <li> The stream is open.
    <li> The streaming endpoint is reset.
    </ul>
    */
        UXSTATUS Open();


        /**
        \brief Closes the stream.
        \return The status of the operation.

        \pre
        The stream is open.

        \post
        <ul>
        <li> Streaming is stopped.
        <li> All buffers are unqueued and deregistered. The old buffers cannot be retrieved anymore.
        <li> Data structures allocated for streaming are freed.
        <li> The stream is closed.
        </ul>
        */
        UXSTATUS Close();


        /**
        \brief Prepares the stream for grabbing.
        \param[in] nMaxBuffer The maximum number of buffers registered at any time during streaming.
        \param[in] MaxBufferSize The maximum buffer size used for streaming.
        \return The status of the operation.

        \pre
        The stream is open.

        \post
        <ul>
        <li> All old buffers are unqueued and deregistered. The old buffers cannot be retrieved anymore.
        <li> Old data structures allocated for streaming are freed.
        <li> New data structures are allocated for streaming.
        <li> The stream is prepared for streaming.
        <li> The stream of the device is enabled.
        </ul>
        */
        UXSTATUS PrepareGrab( size_t nMaxBuffer, size_t MaxBufferSize );


        /**
        \brief Registers a buffer for grabbing.
        \param[in] pBuffer The buffer.
        \param[in] BufferSize The buffer size in byte.
        \param[out] phBuffer Returns the handle of the buffer.
        \return The status of the operation.

        \pre
        <ul>
        <li> The stream is prepared.
        <li> The buffer is not registered.
        </ul>

        \post
        The buffer is registered.
        */
        UXSTATUS RegisterBuffer( void* pBuffer, size_t BufferSize, BufferHandle* phBuffer );


        /**
        \brief All pending transfers are aborted. All buffers are transfered to the output queue.
        \return The status of the operation.

        Currently this stops the device stream (Stream Enable=0). This may change.

        \pre
        The stream is prepared.

        \post
        <ul>
        <li> All buffers are in the output queue.
        <li> BlockId is reset to 0. (This may change)
        </ul>
        */
        UXSTATUS CancelGrab();


        /**
        \brief Starts the streaming thread.
        \return The status of the operation.

        \pre
        The stream is prepared.

        \post
        <ul>
        <li> The thread for transferring the buffers is running.
        <li> Available buffers (transfers) are queued at the streaming endpoint.
        </ul>
        */
        UXSTATUS StartStreaming();


        /**
        \brief Stops the streaming thread. All buffers are canceled by calling CancelGrab().
        \return The status of the operation.

        \pre
        The thread for transferring the buffers is running.

        \post
        <ul>
        <li> The thread for transferring the buffers is stopped.
        <li> All buffers are in the output queue.
        </ul>
        */
        UXSTATUS StopStreaming();


        /**
        \brief Queues a registered buffer for grabbing.
        \return The status of the operation.

        \pre
        <ul>
        <li> The stream is prepared.
        <li> The buffer is registered.
        <li> The buffer is not queued already.
        </ul>

        \post
        The buffer is queued.
        */
        UXSTATUS QueueBuffer( BufferHandle hBuffer, const void* pContext );

        /**
        \brief Wait for a buffer to appear in the output queue.
        \param[in] timeout Timeout for waiting.
        \return Returns UX_E_TIMEOUT on timeout, UX_OK if a buffer is available, or an error status.
        */
        UXSTATUS WaitForBuffer( uint32_t timeout );

        /**
        \brief Retrieve a grab result.
        \param[out] pGrabResult A pointer to a grab result structure.
        \param[out] pnBuffersLeft Optional output parameter. Returns the count of buffers available in the output queue.
        \return The status of the operation. Returns UX_OK if a grab result has been retrieved. Return UX_E_NO_BUFFER_AVAILABLE if no result is available.

        The memory of the GrabResult struct pointed to by pGrabResult is set to zero first.

        \pre
        <ul>
        <li> The pointer pGrabResult must not be NULL.
        <li> The stream is open.
        </ul>

        \post
        If a grab result has been returned, the buffer of the grab result is unqueued.
        */
        UXSTATUS RetrieveBuffer( GrabResult* pGrabResult, size_t* pnBuffersLeft );

        /**
        \brief Deregisters a buffer.
        \param[out] hBuffer The buffer handle.
        \param[out] ppBuffer Optional. Returns the pointer to the buffer.
        \return The status of the operation.

        \pre
        <ul>
        <li> The stream is open.
        <li> The buffer is not queued.
        </ul>

        \post
        <ul>
        <li> The buffer is deregistered.
        <li> If grab is finished and all buffers are deregistered, data structures allocated for streaming are freed.
        </ul>
        */
        UXSTATUS DeregisterBuffer( BufferHandle hBuffer, void** ppBuffer );

        /**
        \brief Finish grab session.

        \pre
        <ul>
        <li> The stream is prepared or streaming.
        </ul>

        \post
        <ul>
        <li> The streaming is stopped.
        <li> All buffers are in the output queue.
        <li> The stream of the device is disabled.
        </ul>
        */
        UXSTATUS FinishGrab();

        /**
        \brief Register a wait object. Optional.

        Register a different event used for waiting for buffers in the output queue.
        On windows, this must be an event created using CreateEvent().
        You can safely cast the HANDLE returned from CreateEvent() to WaitObjectHandle

        The handle of the event is duplicated. The new event replaces the existing event.
        The signal state of the previous event is transferred to the new event.
        */
        UXSTATUS RegisterWaitObject( WaitObjectHandle waitObject );

        /**
        \brief Register a buffer ready callback. This callback will be called when the availability of buffers to retrieve with RetrieveResult() changes.
        \param[in] callback Callback function, you can pass NULL to unregister a callback.
        \param[in] userContext The User context, e.g. a this pointer of the class using the stream. The user context will passed every time the callback is called.
        \return The status of the operation.

        Only one buffer ready callback can be registered. Any subsequent call will remove the previously registered callback.
        */
        UXSTATUS RegisterBufferReadyCallback( UxapiStreamBufferReadyCallback callback, void* userContext );

        /// Checks if the stream is open.
        bool IsOpen() const;

        /// Checks if the stream is prepared for grabbing.
        bool IsPrepared() const;

        /// Checks if Streaming has been started.
        bool IsStreaming() const;

        /// List of all available properties
        enum EPropertyValue
        {
            //<> [INCLUDE]["PropertyEnum.tpl.h"]
                                                                                //$
            /**                                                                 //$
                \brief Value of NumMaxQueuedUrbs. The type is uint32_t.         //$
                Maximum number of USB request blocks (URBs) to be enqueued simultaneously. Increasing this value may improve stability and reduce jitter, but requires more resources on the host computer.//$
            */                                                                  //$
            NumMaxQueuedUrbsValue = 0x200,                                      //$
                                                                                //$
            /**                                                                 //$
                \brief Value of MaxTransferSize. The type is uint32_t.          //$
                Maximum USB data transfer size in bytes. The default value is appropriate for most applications. Decreasing the value may increase the CPU load. USB host adapter drivers may require decreasing the value if the application fails to receive the image stream. The maximum value also depends on the operating system.//$
            */                                                                  //$
            MaxTransferSizeValue = 0x300,                                       //$
            /** \brief Maximum value of MaxTransferSize */                      //$
            MaxTransferSizeMax = 0x308,                                         //$
            /** \brief Minimum value of MaxTransferSize */                      //$
            MaxTransferSizeMin = 0x310,                                         //$
            /** \brief Increment value of MaxTransferSize */                    //$
            MaxTransferSizeInc = 0x318,                                         //$
                                                                                //$
            /**                                                                 //$
                \brief Value of TotalBufferCount. The type is int64_t.          //$
                GigE cameras: Number of frames received. Other cameras: Number of buffers processed.//$
            */                                                                  //$
            TotalBufferCountValue = 0x400,                                      //$
                                                                                //$
            /**                                                                 //$
                \brief Value of FailedBufferCount. The type is int64_t.         //$
                GigE cameras: Number of buffers with at least one failed packet. A packet is considered failed if its status is not 'success'. Other cameras: Number of buffers that returned an error. //$
            */                                                                  //$
            FailedBufferCountValue = 0x500,                                     //$
                                                                                //$
            /**                                                                 //$
                \brief Value of MissedFrameCount. The type is int64_t.          //$
                Number of corrupt or lost frames between successfully grabbed images.//$
            */                                                                  //$
            MissedFrameCountValue = 0x600,                                      //$
                                                                                //$
            /**                                                                 //$
                \brief Value of ResynchronizationCount. The type is int64_t.    //$
                Number of stream resynchronizations.                            //$
            */                                                                  //$
            ResynchronizationCountValue = 0x700,                                //$
                                                                                //$
            /**                                                                 //$
                \brief Value of OutOfMemoryErrorCount. The type is int64_t.     //$
                Number of out-of-memory errors.                                 //$
            */                                                                  //$
            OutOfMemoryErrorCountValue = 0x800,                                 //$
                                                                                //$
            /**                                                                 //$
                \brief Value of LastBlockId. The type is int64_t.               //$
                Last grabbed block ID.                                          //$
            */                                                                  //$
            LastBlockIdValue = 0x900,                                           //$
                                                                                //$
            /**                                                                 //$
                \brief Value of LastFailedBufferStatus. The type is UXSTATUS.   //$
                Status code of the last failed buffer.                          //$
            */                                                                  //$
            LastFailedBufferStatusValue = 0xA00,                                //$
                                                                                //$
            /**                                                                 //$
                \brief Value of TransferLoopThreadPriority. The type is int32_t.//$
                Priority of the thread that handles USB requests from the stream interface.//$
            */                                                                  //$
            TransferLoopThreadPriorityValue = 0xB00,                            //$
            /** \brief Maximum value of TransferLoopThreadPriority */           //$
            TransferLoopThreadPriorityMax = 0xB08,                              //$
            /** \brief Minimum value of TransferLoopThreadPriority */           //$
            TransferLoopThreadPriorityMin = 0xB10,                              //$
                                                                                //$
            /**                                                                 //$
                \brief Value of TransferTimeout. The type is uint32_t.          //$
                Timeout for payload and trailer transfers in milliseconds.      //$
            */                                                                  //$
            TransferTimeoutValue = 0xC00,                                       //$
            /** \brief Maximum value of TransferTimeout */                      //$
            TransferTimeoutMax = 0xC08,                                         //$
            /** \brief Minimum value of TransferTimeout */                      //$
            TransferTimeoutMin = 0xC10,                                         //$
                                                                                //$

            /** \brief PayloadSize from camera device */
            PayloadSize = 0xA0000,

            /** \brief Address of CompressionRegisterMap or 0 if not supported */
            CompressionRegisterMapAddress = 0xC0B00,

            /** \brief The complete compression register map */
            CompressionRegisterMap = 0xC0D00,

            /** \brief PayloadSizeDecompressed */
            PayloadSizeDecompressed = 0xDEC00,

            /// The message text of the status code of the last failed buffer.  The maximum size is 1KB.
            LastFailedBufferStatusText = 0x000F0000,

            BadModeValue = 0xF4000400
        };

        /// Gets a property value. See EPropertyValue.
        UXSTATUS GetProperty( EPropertyValue propertyId, void* pValue, size_t valueSize ) const;

        /// Sets a property value. EPropertyValue.
        UXSTATUS SetProperty( EPropertyValue propertyId, const void* pValue, size_t valueSize );

        /// Constructor. Internal use only.
        CUxStream( CUxStreamImplBase* );

        /// Destructor. Internal use only.
        ~CUxStream();
    private:
        CUxStream( const CUxStream& );
        CUxStream& operator=( const CUxStream& );

        CUxStreamImplBase* m_pImpl;
        friend class CUxDevice;   ///< CUxDevice is a friend of CUxStream.
    };
}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */
