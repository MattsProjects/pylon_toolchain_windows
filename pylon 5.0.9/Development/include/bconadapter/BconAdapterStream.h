//-----------------------------------------------------------------------------
//  Copyright (C) 2016-2017 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief BCON adapter stream interface.
* \ingroup public
*/
#pragma once

#include <stddef.h> // size_t
#include "BconAdapterDefines.h"
#include "BconAdapterTypes.h"


EXTERN_C_BEGIN

//-----------------------------------------------------------------------------
// types
//

#pragma pack(push, BCON_PACKING)

/// To store data required for operation of the adapter layer, this struct can be specified and
/// used by the adapter. The prototype here ensures that just the pointer type is known.
struct BconAdapterStream_tag;

/** 
\typedef BconAdapterStreamHandle 
\brief Opaque handle representing a stream
A handle value of null is considered invalid. 
*/
typedef struct BconAdapterStream_tag* BconAdapterStreamHandle;

/// To store data required for operation of the adapter layer, this struct can be specified and
/// used by the adapter. The prototype here ensures that just the pointer type is known.
struct BconAdapterBuffer_tag;
/**
\typedef BconAdapterBufferHandle
\brief Opaque handle representing a buffer
A handle value of NULL is considered invalid.
*/
typedef struct BconAdapterBuffer_tag *BconAdapterBufferHandle;


//* Grab result */
typedef struct BconGrabResult_tag
{
    int                     sizeOfGrabResult;   ///< Size in bytes. Provided by the caller of BconAdapterStreamRetrieveResult.
    int                     grabResultTypeID;   ///< Special marker for different GrabResults. Provided by the caller of BconAdapterStreamRetrieveResult.
    BconAdapterBufferHandle hBuffer;            ///< Handle to the buffer.
    void*                   pBuffer;            ///< Pointer to the buffer.
    const void*             userContext;        ///< User context.
    BCONSTATUS              errorCode;          ///< Error code.

    uint16_t                payloadType;        ///< Type of payload.
    uint64_t                blockId;            ///< Block identifier.
    uint64_t                timeStamp;          ///< Timestamp.
    uint32_t                pixelFormat;        ///< Pixel format.
    uint32_t                sizeX;              ///< Size in x-direction.
    uint32_t                sizeY;              ///< Size in y-direction.
    uint32_t                offsetX;            ///< Offset in x-direction.
    uint32_t                offsetY;            ///< Offset in y-direction.
    uint16_t                paddingX;           ///< Padding in x-direction.
    uint16_t                paddingY;           ///< Padding in y-direction.
    uint64_t                payloadSize;        ///< Payload size.
} BconGrabResult;


/**
\brief Stream callback function. 
Call this function when the number of images ready changes.
\param[in] hStream          Stream handle.
\param[in] imageReadyCount  Number of images ready. If the grabber implementation cannot tell how many 
                            images are ready, it is sufficient to pass 0 to indicate that no buffers are available
                            or 1 to indicate that one or more buffers are available.
\param[in] context          The context contains the value passed when the callback has been
                            registered using BconAdapterStreamRegisterCallback().

\attention This callback must only be used to signal to other threads that they can progress further. Do not
           acquire any locks or call further functions of the BCON Adapter API from the callback.
*/
typedef void (BCON_ADAPTER_CALL *BconAdapterStreamBufferReadyCallback)(
    BconAdapterStreamHandle hStream,
    size_t imageReadyCount,
    void* context);

//-----------------------------------------------------------------------------
// functions
//

/**
\brief Creates the stream.
Allocates memory and/or other resources as required.
Assigns a unique handle representing the stream.
\param[in] deviceID Device identifier received during enumeration.
\param[out] phStream Handle representing the stream created.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_S_ALREADY_CREATED Stream has already been created.
\retval Any Other BCON adapter error code.
\post   Stream is idle on success.
\threading
This function must be thread-safe. It is assumed that a known fixed amount of cameras is attached
to a BCON system, so that required data structures can be allocated when BconAdapterInit() is called.
Therefore, thread-safety can be assured without using additional locking.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamCreate(
    const char deviceID[],
    BconAdapterStreamHandle *phStream);


/**
\brief Destroys the stream.
Frees memory and/or other resources.
\param[in] hStream    Stream handle.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is idle. BconAdapterStreamCreate() or BconAdapterStreamClose() has been called before.
\post   hStream is invalid.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamDestroy(
    BconAdapterStreamHandle hStream);


/**
\brief Opens the stream.
\param[in] hStream   Stream handle.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is idle. BconAdapterStreamCreate() or BconAdapterStreamClose() has been called before.
\post   Stream is open on success.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamOpen(
    BconAdapterStreamHandle hStream);


/**
\brief Closes the stream.
\param[in] hStream   Stream handle
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is open. BconAdapterStreamOpen() or BconAdapterStreamFinishGrab() has been called before.
\post   Stream is idle on success.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamClose(
    BconAdapterStreamHandle hStream);


/**
\brief Gets a property value. The property value is written to the buffer given in pValue.
\param[in] hStream      Stream handle.
\param[in] propertyId   ID of the property to be read.
\param[in] pValue       Pointer to allocated and writable memory.
\param[in] valueSize    Size of the allocated memory in bytes.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INSUFFICIENT_BUFFER pValue was NULL or valueSize was too small to hold the data.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is created.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function can be implemented. If the BCON adapter library is used with pylon, this method can be accessed via the "StreamGrabberPort" port of the pylon stream grabber node map.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamGetProperty(
    BconAdapterStreamHandle hStream,
    uint64_t propertyId,
    void *pValue,
    size_t valueSize);


/**
\brief Sets a property value. The property value is read from the buffer given in pValue.
\param[in] hStream      Stream handle.
\param[in] propertyId   ID of the property to be written.
\param[in] pValue       Pointer to memory where the property value should be read from.
\param[in] valueSize    Size of memory in bytes.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is created.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function can be implemented. If the BCON adapter library is used with pylon, this method can be accessed via the "StreamGrabberPort" port of the pylon stream grabber node map.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamSetProperty(
    BconAdapterStreamHandle hStream,
    uint64_t propertyId,
    const void *pValue,
    size_t valueSize);


/**
\brief Configures the main streaming parameters.
\param[in] hStream              Stream handle.
\param[in] width                Image width to be set for the camera.
\param[in] height               Image height to be set for the camera.
\param[in] pixelFormatPfncValue Pixel Format Naming Convention value (see www.emva.org) to be set for the camera.
\param[in] clockFrequency       Clock frequency value in Hz to be set for the camera.
\param[in] pixelsPerClockCycle  Pixels per clock cycle to be set for the camera (1 = 'One', 2 = 'Two').
\param[out] payloadSizeOut      Required buffer size for grabbing an image with the above properties and the frame grabber used by the BCON adapter.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is open.
\threading
This function must be thread-safe. 
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamConfigureStreamingParameters(
    BconAdapterStreamHandle hStream,
    uint32_t width,
    uint32_t height,
    uint32_t pixelFormatPfncValue,
    uint32_t clockFrequency,
    uint32_t pixelsPerClockCycle,
    size_t* payloadSizeOut);


/**
\brief Prepares a stream for grabbing.
\param[in] hStream          Stream handle.
\param[in] maxNumBuffer     Maximum number of buffers registered at any time during streaming.
\param[in] maxBufferSize    Maximum buffer size used for streaming.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is open. BconAdapterStreamOpen() or BconAdapterStreamFinishGrab() has been called before.
\post   Stream is prepared on success.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamPrepareGrab(
    BconAdapterStreamHandle hStream,
    size_t maxNumBuffer,
    size_t maxBufferSize);


/**
\brief Registers a buffer for grabbing.
\param[in] hStream      Stream handle.
\param[in] pBuffer      Buffer.
\param[in] bufferSize   Buffer size in bytes.
\param[out] phBuffer    Unique handle for the buffer.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_BUFFER_ALREADY_REGISTERED Buffer is already registered.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\post   Buffer is ready to be used by the stream.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamRegisterBuffer(
    BconAdapterStreamHandle hStream,
    void *pBuffer,
    size_t bufferSize,
    BconAdapterBufferHandle *phBuffer);


/**
\brief Deregisters a buffer.
\param[in] hStream      Stream handle.
\param[in] hBuffer      Buffer handle.
\param[out] ppBuffer    Optional. Pointer to the buffer.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval BCON_E_INVALID_BUFFER_HANDLE Buffer has already been deregistered or buffer handle is invalid.
\retval BCON_E_BUFFER_STILL_QUEUED Buffer is still queued for grabbing.
\retval Any Other BCON adapter error code.
\post   The buffer will no longer be accessed by the stream. The buffer handle is invalid.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamDeregisterBuffer(
    BconAdapterStreamHandle hStream,
    BconAdapterBufferHandle hBuffer,
    void **ppBuffer);


/**
\brief Aborts all pending transfers. Transfers canceled buffers to the output queue.
\param[in] hStream   Stream handle.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is prepared.
\post   All buffers are marked as canceled and are placed in the output queue.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamFlushBuffers(
    BconAdapterStreamHandle hStream);


/**
\brief Starts the streaming thread.
\param[in] hStream Stream handle.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is prepared. BconAdapterStreamPrepareGrab() or BconAdapterStreamStopStreaming() has been called before.
\post   Stream is streaming.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamStartStreaming(
    BconAdapterStreamHandle hStream);


/**
\brief Stops the streaming thread. Cancels all buffers by calling FlushBuffers().
\param[in] hStream Stream handle.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is streaming. BconAdapterStreamStartStreaming() has been called before.
\post   Stream is prepared on success.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamStopStreaming(
    BconAdapterStreamHandle hStream);


/**
\brief Queues a registered buffer for grabbing.
\param[in] hStream  Stream handle.
\param[in] hBuffer  Handle of a registered buffer.
\param[in] context  Additional data for this buffer. This is returned when buffer is retrieved.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval BCON_E_INVALID_BUFFER_HANDLE Buffer handle is invalid.
\retval BCON_E_BUFFER_ALREADY_QUEUED Buffer is already queued.
\retval Any Other BCON adapter error code.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamQueueBuffer(
    BconAdapterStreamHandle hStream,
    BconAdapterBufferHandle hBuffer,
    const void* context);


/**
\brief Retrieves a grab result.
\param[in] hStream          Stream handle.
\param[out] pGrabResult     Pointer to a grab result structure.
\param[out] pNumBuffersLeft Optional. Returns the number of buffers available in the output queue. Can be NULL.
\return Status of the operation.
\retval BCON_OK Grab result has been retrieved.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval BCON_E_NO_BUFFER_AVAILABLE No result is available.
\retval Any Other BCON adapter error code.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamRetrieveResult(
    BconAdapterStreamHandle hStream,
    BconGrabResult *pGrabResult,
    size_t *pNumBuffersLeft);


/**
\brief Finishes a grab session.
\param[in] hStream   Stream handle.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\retval Any Other BCON adapter error code.
\pre    Stream is prepared. BconAdapterStreamPrepareGrab() or BconAdapterStreamStopStreaming() has been called before.
\post   Stream is idle on success. All buffers are placed in the output queue.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamFinishGrab(
    BconAdapterStreamHandle hStream);

/**
\brief Registers a callback. Call this function when the number of grabbed images changes.
The callback replaces previously registered callbacks. Passing NULL deregisters the callback.
\param[in] hStream       Stream handle.
\param[in] pCallback     Optional. Callback function.
\param[in] context       Optional. User context, will be given to callback.
\return Status of the operation.
\retval BCON_OK Success.
\retval BCON_E_INVALID_HANDLE Stream handle is invalid.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread at a time can access a stream.
\note This function must be implemented if the BCON adapter library is supposed to support streaming.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamRegisterCallback(
    BconAdapterStreamHandle hStream,
    BconAdapterStreamBufferReadyCallback pCallback,
    void* context);


#pragma pack(pop)

EXTERN_C_END
