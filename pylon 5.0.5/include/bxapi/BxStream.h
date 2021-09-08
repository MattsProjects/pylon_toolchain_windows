//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Declaration of the Stream part of BXAPI
 * \ingroup public
 */
#pragma once

#if _POSIX_C_SOURCE
#include <inttypes.h>
#include <stdbool.h>
#endif

#include <stddef.h>

#include <bxapi/BxDll.h>
#include <bxapi/BxTypes.h>
#include <bxapi/BxStatus.h>

#pragma pack(push, BX_PACKING)

EXTERN_C_BEGIN

struct BufferHandle_s;  ///< Forward declaration.
typedef BufferHandle_s *BxapiBufferHandle;   ///< Pointer to buffer handle. A handle value of null is considered invalid.


/// States of a bxapi stream
enum BxapiStreamState
{
      BxapiStreamState_Invalid = 0   ///< Stream not found or device has been disconnected or the handle passed to BxapiStreamGetState() is invalid
    , BxapiStreamState_Closed = 1    ///< Stream is closed
    , BxapiStreamState_Opened = 2    ///< Stream is opened
    , BxapiStreamState_Prepared = 3  ///< Stream has been prepared for grab
    , BxapiStreamState_Streaming = 4 ///< Stream is receiving image data
};

/// Payload types.
/** Describes the contents a the stream payload. Currently only image data is supported. */
enum BxapiPayloadType
{
    BxapiPayloadType_Image = 0x0001    ///< Uncompressed image data.

    // no chunk support
};


//* Grab result */
typedef struct BxapiGrabResult_tag
{
    int          sizeOfGrabResult;  ///< Size in bytes.
    int          grabResultTypeID;  ///< Special marker for different GrabResults.
    BxapiBufferHandle hBuffer;       ///< Handle to buffer.
    void*        pBuffer;       ///< Pointer to buffer.
    void*        userContext;   ///< User context.
    BXSTATUS     errorCode;     ///< Error code.

    uint16_t     payloadType;   ///< Type of payload.
    uint64_t     blockId;       ///< Block identifier.
    uint64_t     timeStamp;     ///< Time stamp.
    uint32_t     pixelFormat;   ///< Pixel format.
    uint32_t     sizeX;         ///< Size in x-direction.
    uint32_t     sizeY;         ///< Size in y-direction.
    uint32_t     offsetX;       ///< Offset in x-direction.
    uint32_t     offsetY;       ///< Offset in y-direction.
    uint16_t     paddingX;      ///< Padding in x-direction.
    uint16_t     paddingY;      ///< Padding in y-direction.
    uint64_t     payloadSize;   ///< Payload size.
} BxapiGrabResult;






/**
\brief Creates a stream handle which can used to retrieve image data from the device.
Returns a stream handle which can be used with BxapiStream functions to retrieve image data.
Each sucessfully created stream must be destroyed using BxapiStreamDestroy() before closing the device.
\param [in] hDev Device handle.
\param [out] phStream On successful return this points to the stream handle.
\return The status of the operation.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamCreate(BxapiDeviceHandle hDev, BxapiStreamHandle *phStream);


/**
\brief Destroys a stream created by BxapiStreamCreate().
This function releases all data associated with the stream passed in hStream.
\param [in] hStream Stream handle to be destroyed.
\return The status of the operation.
\pre - The stream in hStream has been successfully created.
\post - All the resources associated with the stream have been released.
\threading
This function is thread-safe. Calling this function while other threads access the stream will result in undefined behavior.
*/
BX_API BXSTATUS BxapiStreamDestroy(BxapiStreamHandle hStream);


/**
\brief Open the stream.
Opens the specified stream.
After a sucessful call to BxapiStreamOpen() you can can prepare grabbing and start aquiring images.
\param [in] hStream Device handle.
\return The status of the operation.
\pre - The stream has been created.
\post - The stream is closed.
\post - The stream is opened.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamOpen(BxapiStreamHandle hStream);


/**
\brief Close the stream
Closes the stream previously opened by a call to BxapiStreamOpen().
\param [in] hStream Stream handle.
\return The status of the operation.
\pre - The stream has been opened by a call to BxapiStreamOpen().
\post - Streaming is stopped.
\post - The stream is closed.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamClose(BxapiStreamHandle hStream);


/**
\brief Returns the current state of the stream.
Returns the current state of the stream.
\param [in] hStream stream handle.
\return Returns one of the states specified in the BxapiStreamState enumeration.
\pre - The stream has been created by a call to BxapiStreamCreate().
\threading
This function is thread-safe.
*/
BX_API BxapiStreamState BxapiStreamGetState(BxapiStreamHandle hStream);


/**
\brief Get a property value.
Returns a stream specific meta data property specified by propertyId. The size and type of property data is determined by the property id.
See property id defines for more information, e.g. \link BXAPI_PROPERTYID_WIDTH_VALUE \endlink.
\param [in] hStream Stream handle.
\param [in] propertyId Specifies which property to return.
\param [out] pPropertyData Destination buffer to copy the property data to.
\param [in] propertyDataSize Size of destination buffer passed in pPropertyData.
                             The data type of each property is defined in the documentation of the property.
                             The passed data buffer must be large enough to hold the property data.
\return The status of the operation. If the buffer is not large enough to hold data, BX_E_INSUFFICIENT_BUFFER is returned and the required size is returned in pRequiredDataSize.
\pre - The stream has been created by a call to BxapiStreamCreate().
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamGetProperty(BxapiStreamHandle hStream, uint64_t propertyId, void *pPropertyData, size_t propertyDataSize);

/**
\brief Set a property value.
Sets a stream specific meta data property specified by propertyId. The size and type of property data is determined by the property id.
See property id defines for more information, e.g. \link BXAPI_PROPERTYID_WIDTH_VALUE \endlink.
\param [in] hStream Stream handle.
\param [in] propertyId Specifies which property to set.
\param [in] pPropertyData Source buffer to copy the property data from.
\param [in] propertyDataSize Size of source buffer passed in pPropertyData in bytes.
\return The status of the operation.
\pre - The stream has been created by a call to BxapiStreamCreate().
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamSetProperty(BxapiStreamHandle hStream, uint64_t propertyId, const void *pPropertyData, size_t propertyDataSize);


/**
\brief Prepares the stream for grabbing.
This function sets the stream in the prepared state.
After the stream is prepared you can register and queue buffers.
Streaming is not started until you call BxapiStreamStartGrab().
You must call BxapiStreamFinishGrab() if you've sucessfully called BxapiStreamPrepareGrab().
\param [in] hStream Stream handle.
\param [in] nMaxBuffer The maximum number of buffers registered at any time during streaming.
\param [in] MaxBufferSize The maximum buffer size used for streaming.
\return The status of the operation.
\pre - The stream has been opened by a call to BxapiStreamOpen().
\post - The stream is prepared
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamPrepareGrab(BxapiStreamHandle hStream, size_t nMaxBuffer, size_t MaxBufferSize);


/**
\brief Finishes an active grab session.
If you've successfully called BxapiStreamPrepareGrab() you must call this function after you've finished the grab and unregistered all buffers.
\param [in] hStream Stream handle.
\return The status of the operation.
\pre - The stream is prepared
\post - All buffers are deregistered
\post - The stream is opened.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamFinishGrab(BxapiStreamHandle hStream);


/**
\brief Registers a buffer for grabbing.
Before a buffer can be used by bxapi it must be registered. After it has been successfully registered a buffer handle will be returned.
You can use this handle on subsequent calls to BxapiStreamQueueBuffer(), BxapiStreamWaitForBuffer() and BxapiStreamDeregisterBuffer().
Each buffer successfully registered must be deregistered by calling BxapiStreamDeregisterBuffer() before the stream is closed.
\param [in] hStream Stream handle.
\param [in] pBuffer The buffer.
\param [in] bufferSize The buffer size in byte.
\param [out] phBuffer Returns the handle of the buffer.
\return The status of the operation. If the buffer has been registered before BX_E_ALREADY_REGISTERED will be returned.
\pre - The stream has been prepared by call to BxapiStreamPrepareGrab().
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamRegisterBuffer(BxapiStreamHandle hStream, void* pBuffer, size_t bufferSize, BxapiBufferHandle *phBuffer);


/**
\brief Deregisters a buffer.
Before closing the stream you must deregister all previously registered buffers.
After a buffer has been deregistered the buffer handle becomes invalid and you cannot queue the buffer anymore.
\param [in] hStream Stream handle.
\param [out] hBuffer A handle to buffer returned from BxapiStreamRegisterBuffer().
\param [out] ppBuffer Optional. Returns the pointer to the buffer.
\return The status of the operation.
\pre - The stream is prepared.
\post - The stream is prepared.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamDeregisterBuffer(BxapiStreamHandle hStream, BxapiBufferHandle hBuffer, void** ppBuffer);


/**
\brief Marks all buffers as canceled and moves them to the output queue.
Marks all buffers currently in the input queue waiting to be filled as canceled and moves them to the output queue.
Currently this stops the device stream.
\param [in] hStream Stream handle.
\return The status of the operation.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamCancelGrab(BxapiStreamHandle hStream);


/**
\brief Starts streaming.
Puts the stream into the streaming state. The bxapi library wait for image data sent from the device in the background and store it in the next free buffer.
If a buffer is completely filled it will be moved to the output queue and the callback will be called.
You can call BxapiStreamRetrieveBuffer() to access that buffer.
If the device needs to issued a custom command before it starts sending stream data you must send it separately.
\param [in] hStream Stream handle.
\return The status of the operation.
\pre - The stream is prepared
\post - The stream is streaming
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamStartStreaming(BxapiStreamHandle hStream);


/**
\brief Stops streaming.
Puts the stream back into the prepared state. If there are any buffers in the input queue,
they will be cancelled and moved to the output queue by an implicit call to BxapiStreamCancelGrab().
\param [in] hStream Stream handle.
\return The status of the operation.
\pre - The stream is streaming
\post - The stream is prepared
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamStopStreaming(BxapiStreamHandle hStream);


/**
\brief Queues a registered buffer for grabbing.
Queues a buffer into the stream's input queue, so it will be filled with image data when received.
\param [in] hStream Stream handle.
\param [in] hBuffer Handle to the buffer being queued
\param [in] userContext Holds the user defined context.
\return The status of the operation.
\pre - The stream is prepared.
\pre - The buffer has been registered by calling BxapiStreamRegisterBuffer()
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamQueueBuffer(BxapiStreamHandle hStream, BxapiBufferHandle hBuffer, const void* userContext);


/**
\brief Wait for a buffer to appear in the output queue.
\param [in] hStream Stream handle.
\param [in] timeout Number of milliseconds to wait for the arrival of a buffer in the output queue.
\return Returns BX_E_TIMEOUT on timeout, BX_OK if a buffer is available, or an error status.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamWaitForBuffer(BxapiStreamHandle hStream, uint32_t timeout);


/**
\brief Retrieve a filled grab result (buffer).
This function retrieves the next available buffer from the output queue. The buffer is returned in grab result structure containing meta data about a filled buffer.
You should check BxapiGrabResult.errorCode member whether the grab results contains valid data.
You can access the buffer by using the BxapiGrabResult.pBuffer pointer.
This function processes buffers using a first in, first out strategy.
\param [in] hStream Stream handle.
\param [out] pGrabResult A pointer to a BxapiGrabResult structure filled on successful return.
\param [out] pBuffersRemaining Optional parameter. On successful return it will hold the number of remaining buffers in the output queue. If 0 is returned it indicates there are currently no more buffers to retrieve.
\return The status of the operation. Returns BX_OK if a grab result has been retrieved. Returns BX_E_NO_BUFFER_AVAILABLE if no result is available.
\pre - Stream is prepared or streaming or open.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamRetrieveBuffer(BxapiStreamHandle hStream, BxapiGrabResult* pGrabResult, size_t *pBuffersRemaining);


/**
\brief \brief Call this function when the number of images ready changed.
\param[in] hStream          Stream handle.
\param[in] imageReadyCount  Number of images available. The used BCON Adapter library may only pass
                            pass 0 to indicate that no buffers are available
                            and 1 to indicate that one or more buffers are available.
                            Please see the documentation of the used BCON Adapter library for further information.
\param[in] context          The userContext contains the value passed when the callback has been registered using BxapiStreamRegisterCallback().

\attention This callback must only be used to signal other threads for further processing. It is not allowed
to acquire any locks or call further functions of the BCON Adapter API from the callback.
*/
typedef void (BX_CALL *BxapiStreamCallback)(BxapiStreamHandle hStream, size_t imageReadyCount, void *userContext);


/**
\brief Register a callback. The callback will be called when a finished buffer has been added to the output queue.
\param [in] hStream Stream handle.
\param [in] callback Pointer to the callback function. To disable the callback set this parameter to NULL
\param [in] userContext User defined value passed to the callback function.
\return The status of the operation.
\pre - Stream has been created
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiStreamRegisterCallback(BxapiStreamHandle hStream, BxapiStreamCallback callback, void *userContext);


//<> [INCLUDE]["PropertyDefines.tpl.h"]
 /** \brief Value of Width; The type is uint32_t; The width of the ROI configured on the hardware grabber. (read and write) */                        //$
#define BXAPI_PROPERTYID_WIDTH_VALUE 0x50100                                                                                                          //$
/** \brief Value of Height; The type is uint32_t; The height of the ROI configured on the hardware grabber. (read and write) */                       //$
#define BXAPI_PROPERTYID_HEIGHT_VALUE 0x50200                                                                                                         //$
/** \brief Value of PixelFormatValue; The type is uint32_t; The pixel format value according to GenICam Pixel Format Naming Convention (PFNC). (read and write) */ //$
#define BXAPI_PROPERTYID_PIXELFORMATVALUE_VALUE 0x50300                                                                                               //$
/** \brief Value of PixelPerClockCycle; The type is uint32_t; Pixel per clock cycle configured on the hardware grabber. (read and write) */           //$
#define BXAPI_PROPERTYID_PIXELPERCLOCKCYCLE_VALUE 0x50400                                                                                             //$
/** \brief Value of PayloadSize; The type is uint32_t; Size of the payload in bytes produced by the hardware grabber (read only) */                   //$
#define BXAPI_PROPERTYID_PAYLOADSIZE_VALUE 0x50500                                                                                                    //$
/** \brief Value of TotalBufferCount; The type is int64_t; The total count of processed buffers. (read only) */                                       //$
#define BXAPI_PROPERTYID_TOTALBUFFERCOUNT_VALUE 0x50600                                                                                               //$
/** \brief Value of FailedBufferCount; The type is int64_t; The count of buffers that returned with an error status. (read only) */                   //$
#define BXAPI_PROPERTYID_FAILEDBUFFERCOUNT_VALUE 0x50700                                                                                              //$
/** \brief Value of LastFailedBufferStatus; The type is BXSTATUS; The status code of the last failed buffer. (read only) */                           //$
#define BXAPI_PROPERTYID_LASTFAILEDBUFFERSTATUS_VALUE 0x50900                                                                                         //$
                                                                                                                                                      //$
/** \brief The message text of the status code of the last failed buffer. The maximum size is 1KB.. */
#define BXAPI_PROPERTYID_LASTFAILEDBUFFERSTATUSTEXT_VALUE 0x5F000

EXTERN_C_END


#pragma pack(pop)
