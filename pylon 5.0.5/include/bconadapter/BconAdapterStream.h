//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Defines stream interface of BCON adapter (INTERNAL USE ONLY)
* \attention Internal use only. Subject to change without notice.
* \ingroup internal
*/
#pragma once
///////////////////////////////////////////////////////////////////////////////
//                                  WARNING                                  //
//          Internal use only. Subject to change without notice.             //
///////////////////////////////////////////////////////////////////////////////

#include <stddef.h> // size_t
#include "BconAdapterDefines.h"
#include "BconAdapterTypes.h"


EXTERN_C_BEGIN

//-----------------------------------------------------------------------------
// defines
//

// -----------------------------------------------------------------------------------------
// stream related error codes
// -----------------------------------------------------------------------------------------
//
// MessageId: BCON_E_INVALID_STREAM_STATE
//
// MessageText:
//
// Invalid state.%0
//
#define BCON_E_INVALID_STREAM_STATE        ((BCONSTATUS)0xE2200200L)

//
// MessageId: BCON_E_BUFFER_ALREADY_REGISTERED
//
// MessageText:
//
// The buffer is already registered.%0
//
#define BCON_E_BUFFER_ALREADY_REGISTERED   ((BCONSTATUS)0xE2200201L)

//
// MessageId: BCON_E_INVALID_BUFFER_HANDLE
//
// MessageText:
//
// Invalid buffer handle.%0
//
#define BCON_E_INVALID_BUFFER_HANDLE       ((BCONSTATUS)0xE2200202L)

//
// MessageId: BCON_E_NO_BUFFER_AVAILABLE
//
// MessageText:
//
// No buffer available.%0
//
#define BCON_E_NO_BUFFER_AVAILABLE         ((BCONSTATUS)0xE2200203L)

//
// MessageId: BCON_E_BUFFER_STILL_QUEUED
//
// MessageText:
//
// Buffer is still queued.%0
//
#define BCON_E_BUFFER_STILL_QUEUED         ((BCONSTATUS)0xE2200204L)

//
// MessageId: BCON_E_BUFFER_ALREADY_QUEUED
//
// MessageText:
//
// Buffer is already queued.%0
//
#define BCON_E_BUFFER_ALREADY_QUEUED       ((BCONSTATUS)0xE2200205L)

//
// MessageId: BCON_E_BUFFER_INCOMPLETE
//
// MessageText:
//
// The buffer was incompletely grabbed.%0
//
#define BCON_E_BUFFER_INCOMPLETE           ((BCONSTATUS)0xE2200206L)

//
// MessageId: BCON_E_BUFFER_CANCELLED
//
// MessageText:
//
// The buffer was canceled.%0
//
#define BCON_E_BUFFER_CANCELLED            ((BCONSTATUS)0xE2200207L)

//
// MessageId: BCON_E_STREAMING_NOT_SUPPORTED
//
// MessageText:
//
// The device does not support streaming.%0
//
#define BCON_E_STREAMING_NOT_SUPPORTED     ((BCONSTATUS)0xE2200208L)

//-----------------------------------------------------------------------------
// types
//

/**
\brief Stream states
*/
enum BconAdapterStreamState_tag
{
    BconAdapterStreamState_Invalid = 0,      /// invalid state
    BconAdapterStreamState_Closed = 1,       ///< Stream is idle 
    BconAdapterStreamState_Open = 2,         ///< Stream is open
    BconAdapterStreamState_Prepared = 3,     ///< Stream is prepared for streaming
    BconAdapterStreamState_Streaming = 4,    ///< Stream is streaming
    BconAdapterStreamState_NumStates         ///< Number of possible states.
};

#pragma pack(push, BCON_PACKING)

typedef BconAdapterStreamState_tag BconAdapterStreamState;

/// To store data required for operation of the adapter layer, this struct can be specified and
/// used by the adapter. A prototype here ensures that just the pointer type is known.
struct BconAdapterStream_tag;

/** 
\typedef BconAdapterStreamHandle 
\brief Opaque handle representing a stream
A handle value of null is considered invalid. 
*/
typedef struct BconAdapterStream_tag* BconAdapterStreamHandle;
/// Opaque handle representing a buffer
/// A handle value of null is considered invalid.
typedef void* BconAdapterBufferHandle;


//* Grab result */
typedef struct BconGrabResult_tag
{
    int                     sizeOfGrabResult;   ///< Size in bytes. Provided by the caller of BconAdapterStreamRetrieveResult.
    int                     grabResultTypeID;   ///< Special marker for different GrabResults. Provided by the caller of BconAdapterStreamRetrieveResult.
    BconAdapterBufferHandle hBuffer;            ///< Handle to the buffer.
    void*                   pBuffer;            ///< Pointer to the buffer.
    void*                   userContext;        ///< User context.
    BCONSTATUS              errorCode;          ///< Error code.

    uint16_t                payloadType;        ///< Type of payload.
    uint64_t                blockId;            ///< Block identifier.
    uint64_t                timeStamp;          ///< Time stamp.
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
Call this function when the number of images ready changed.
\param[in] hStream          Stream handle.
\param[in] imageReadyCount  Number of images ready. If the grabber implementation cannot tell how many 
                            images are ready, it is sufficient to pass 0 to indicate that no buffers are available
                            or 1 to indicate that one or more buffers are available.
\param[in] context          The userContext contains the value passed when the callback has been
                            registered using BconAdapterStreamRegisterCallback().

\attention This callback must only be used to signal other threads that they can process further. Do not
           acquire any locks or call further functions of the BCON Adapter API from the callback.
*/
typedef void (BCON_ADAPTER_CALL *BconAdapterStreamCallback)(
    BconAdapterStreamHandle hStream,
    size_t imageReadyCount,
    void* context);

//-----------------------------------------------------------------------------
// functions
//

/**
\brief Creates the stream.
Allocate memory and/or other resources as required (see _BconAdapterStream_s).
Assign a unique handle representing the stream.
\param[in] deviceID Device identifier received during enumeration.
\param[out] phStream Handle representing the stream created.
\post Stream is idle.
\return The status of the operation.
\retval BCON_OK on success.
\retval BX_S_ALREADY_CREATED if the stream has already been created.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe. It is assumed that a known fixed amount of cameras is attached
to a BCON system, so that required data structures can be allocated when BconAdapterInit() is called.
Therefore, thread-safety can be assured without using additional locking.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamCreate(
    const char deviceID[],
    BconAdapterStreamHandle *phStream);


/**
\brief Destroys the stream.
Free memory and/or other resources (see _BconAdapterStream_s).
\param[in] hStream    Stream handle.
\post hStream is invalid.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamDestroy(
    BconAdapterStreamHandle hStream);


/**
\brief Opens the stream.
\param[in] hStream   Stream handle.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre Stream is idle.
\post Stream is open.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamOpen(
    BconAdapterStreamHandle hStream);


/**
\brief Closes the stream.
\param[in] hStream   Stream handle
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\post Stream is idle.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamClose(
    BconAdapterStreamHandle hStream);


/**
\brief Gets a property value. The property value is written to the buffer given in pValue.
\param[in] hStream      Stream handle.
\param[in] propertyId   ID of the property to be read.
\param[in] pValue       Pointer to allocated and writable memory.
\param[in] valueSize    Size of the allocated memory in bytes.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INSUFFICIENT_BUFFER if pValue was NULL or if valueSize was too small to hold the data.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre  Stream is created.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function can be implemented. If the BCON adapter library is used with pylon this method can be accessed via the port "StreamGrabberPort" of the pylon stream grabber node map.
\attention Internal use only. Subject to change without notice.
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
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre  Stream is created.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function can be implemented. If the BCON adapter library is used with pylon, this method can be accessed via the "StreamGrabberPort" port of the pylon stream grabber node map.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamSetProperty(
    BconAdapterStreamHandle hStream,
    uint64_t propertyId,
    const void *pValue,
    size_t valueSize);


/**
\brief Configures the main streaming parameters.
\param[in] hStream              Stream handle.
\param[in] width                The image width to be set for the camera.
\param[in] height               The image height to be set for the camera.
\param[in] pixelFormatPfncValue The Pixel Format Naming Convention value (see www.emva.org) to be set for the camera.
\param[in] pixelsPerClockCycle  Pixels per clock cycle to be set for the camera (1 = 'One', 2 = 'Two').
\param[out] payloadSizeOut      The required buffer size for grabbing an image with the above properties and the frame grabber used by the BCON adapter.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre  Stream is open.
\threading
This function must be thread-safe. 
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamConfigureStreamingParameters(
    BconAdapterStreamHandle hStream,
    uint32_t width,
    uint32_t height,
    uint32_t pixelFormatPfncValue,
    uint32_t pixelsPerClockCycle,
    size_t* payloadSizeOut);


/**
\brief Prepares a stream for grabbing.
\param[in] hStream           Stream handle.
\param[in] maxNumBuffer     The maximum number of buffers registered at any time during streaming.
\param[in] maxBufferSize    The maximum buffer size used for streaming.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre    Stream is open.
\post   Stream is prepared.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamPrepareGrab(
    BconAdapterStreamHandle hStream,
    size_t maxNumBuffer,
    size_t maxBufferSize);


/**
\brief Registers a buffer for grabbing.
\param[in] hStream      Stream handle.
\param[in] pBuffer      The buffer.
\param[in] bufferSize   The buffer size in bytes.
\param[out] phBuffer    A unique handle for the buffer.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_BUFFER_ALREADY_REGISTERED if the buffer is already registered.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\post Buffer is ready to be used by the stream.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamRegisterBuffer(
    BconAdapterStreamHandle hStream,
    void *pBuffer,
    size_t bufferSize,
    BconAdapterBufferHandle *phBuffer);


/**
\brief Deregisters a buffer.
\param[in] hStream      Stream handle.
\param[in] hBuffer      The buffer handle.
\param[out] ppBuffer    Optional. Pointer to the buffer.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval BCON_INVALID_BUFFER_HANDLE if the buffer has already been deregistered or if the buffer handle is invalid.
\retval BCON_BUFFER_STILL_QUEUED if the buffer is still queued for grabbing.
\retval Any other BCON adapter error code otherwise.
\post The buffer will no longer be accessed by the stream. The buffer handle is invalid.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamDeregisterBuffer(
    BconAdapterStreamHandle hStream,
    BconAdapterBufferHandle hBuffer,
    void **ppBuffer);


/**
\brief Aborts all pending transfers. Transfers canceled buffers to the output queue.
\param[in] hStream   Stream handle.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre   Stream is prepared.
\post  All buffers are marked as canceled and are placed in the output queue.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamFlushBuffers(
    BconAdapterStreamHandle hStream);


/**
\brief Starts the streaming thread.
\param[in] hStream Stream handle.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre   Stream is prepared.
\post  Stream is streaming.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamStartStreaming(
    BconAdapterStreamHandle hStream);


/**
\brief Stops the streaming thread. Cancel all buffers by calling FlushBuffers().
\param[in] hStream Stream handle.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\pre  Stream is streaming.
\post Stream is prepared.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamStopStreaming(
    BconAdapterStreamHandle hStream);


/**
\brief Queues a registered buffer for grabbing.
\param[in] hStream  Stream handle.
\param[in] hBuffer  Handle of a registered buffer.
\param[in] context  Additional data for this buffer. This is returned when Buffer is retrieved.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval BCON_INVALID_BUFFER_HANDLE if the buffer handle is invalid.
\retval BCON_BUFFER_ALREADY_QUEUED if the buffer is already queued.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamQueueBuffer(
    BconAdapterStreamHandle hStream,
    BconAdapterBufferHandle hBuffer,
    uintptr_t context);


/**
\brief Waits for a buffer to appear in the output queue.
\param[in] hStream       Stream handle.
\param[in] timeout_ms   Timeout in milliseconds.
\return The status of the operation.
\retval BCON_OK if a buffer is available.
\retval BCON_E_TIMEOUT on timeout.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamWaitForBuffer(
    BconAdapterStreamHandle hStream,
    uint32_t timeout_ms);


/**
\brief Retrieves a grab result.
\param[in] hStream           Stream handle.
\param[out] pGrabResult     Pointer to a grab result structure.
\param[out] pNumBuffersLeft Optional. Returns the number of buffers available in the output queue. Can be NULL.
\return The status of the operation.
\retval Returns BCON_OK if a grab result has been retrieved. 
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval BCON_NO_BUFFER_AVAILABLE if no result is available.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamRetrieveResult(
    BconAdapterStreamHandle hStream,
    BconGrabResult *pGrabResult,
    size_t *pNumBuffersLeft);


/**
\brief Finishes a grab session.
\param[in] hStream   Stream handle.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\post Stream is idle.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamFinishGrab(
    BconAdapterStreamHandle hStream);


/**
\brief Registers a callback. Call this function when the number of grabbed images increases.
The callback replaces previously registered callbacks. Passing NULL unregisters the callback.
\param[in] hStream       Stream handle.
\param[in] pCallback     Optional. Callback function.
\param[in] context       Optional. User context, will be given to callback.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamRegisterCallback(
    BconAdapterStreamHandle hStream,
    BconAdapterStreamCallback pCallback,
    uintptr_t context);


/**
\brief Gets the state of the stream.
\param[in] hStream   Stream handle.
\param[out] pState  Pointer to a buffer holding the state.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_OPERATION_FAILED if pState is NULL.
\retval BCON_E_INVALID_HANDLE if the stream handle is invalid.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
Multiple threads, one for each stream of different cameras, can access this function at the same time. However, only one thread accesses a single stream at the same time.
\note This function must be implemented if the BCON adapter library should support streaming.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStreamGetState(
    BconAdapterStreamHandle hStream, 
    BconAdapterStreamState* pState);

#pragma pack(pop)

EXTERN_C_END
