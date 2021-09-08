//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2017 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Declaration of the CUxEventStream class
 */
#pragma once

#include "UxDll.h"
#include "UxStatus.h"

#ifdef _MSC_VER
#   pragma pack(push, UX_PACKING)
#endif /* _MSC_VER */

namespace uxapi
{
    class CUxDevice;
    class CUxEventStreamImpl;

    /// Used for grabbing camera events.
    class UX_API CUxEventStream
    {
    public:

        /**
        \brief Opens the event stream.
        \return The status of the operation.

        \pre
        <ul>
        <li> The event stream is closed.
        <li> The device supports events.
        </ul>

        \post
        <ul>
        <li> The stream is open.
        <li> Data structures needed for grabbing are allocated.
        <li> The thread for grabbing event buffers is started.
        </ul>
        */
        UXSTATUS Open();


        /**
        \brief Closes the event stream.
        \return The status of the operation.

        \pre
        The stream is open.

        \post
        <ul>
        <li> Event processing is stopped.
        <li> The thread for grabbing event buffers is stopped.
        <li> The event stream is closed.
        <li> Data structures needed for grabbing are freed.
        </ul>
        */
        UXSTATUS Close();


        /**
        \brief Wait for an event to appear in the internal output queue.
        \param[in] timeout Timeout for waiting.
        \return Returns UX_E_TIMEOUT on timeout, UX_OK if a buffer is available, or an error status.
        */
        UXSTATUS WaitForEvent( uint32_t timeout );


        /**
        \brief Retrieve an event.
        \param[in]  pBuffer The buffer that receives the event data.
        \param[in,out]  pBufferSize The size of the event data buffer. In: size of the buffer, Out: Received number of Bytes
        \param[out] pEventId Returns the ID of the event.
        \param[out] pTimestamp Returns the timestamp of the event.
        \param[out] pnBuffersLeft Optional output parameter. Returns the count of buffers available in the output queue.

        \return The status of the operation. See detailed description for more info.

        Return values:
        <ul>
        <li> UX_E_NO_BUFFER_AVAILABLE; Status of RetrieveEvent. No event in the output queue.
        <li> UX_E_INVALID_PARAMETER; Status of RetrieveEvent. A NULL pointer has been passed.
        <li> UX_E_INSUFFICIENT_BUFFER; Status of RetrieveEvent. The passed buffer is too small for the received event data. The event is removed from the output queue anyway.
        <li> Any other value; Status of the received event command.
        </ul>

        \pre
        <ul>
        <li> The pointer pBuffer, pBufferSize, pEventId, and pTimeStamp must not be NULL.
        <li> The passed buffer must be large enough to hold the event data. Use GetProperty with MaximumTransferLengthValue to get the maximum required length after the event stream is opened.
        </ul>
        */
        UXSTATUS RetrieveEvent( void* pBuffer, size_t* pBufferSize, uint16_t* pEventId, uint64_t* pTimestamp, size_t *pnBuffersLeft );

        /**
        \brief Retrieve an event including GenCP command header.
        \param[in]  pBuffer The buffer that receives the event data including GenCP command header.
        \param[in,out]  pBufferSize The size of the event data buffer. In: size of the buffer, Out: Received number of Bytes
        \param[out] pnBuffersLeft Optional output parameter. Returns the count of buffers available in the output queue.

        \return The status of the operation. See detailed description for more info.

        Return values:
        <ul>
        <li> UX_E_NO_BUFFER_AVAILABLE; Status of RetrieveEvent. No event in the output queue.
        <li> UX_E_INVALID_PARAMETER; Status of RetrieveEvent. A NULL pointer has been passed.
        <li> UX_E_INSUFFICIENT_BUFFER; Status of RetrieveEvent. The passed buffer is too small for the received event data. The event is removed from the output queue anyway.
        <li> Any other value; Status of the received event command.
        </ul>

        \pre
        <ul>
        <li> The pointer pBuffer and pBufferSize must not be NULL.
        <li> The passed buffer must be large enough to hold the event data. Use GetProperty with MaximumTransferLengthValue to get the maximum required length after the event stream is opened.
        </ul>
        */
        UXSTATUS RetrieveEvent( void* pBuffer, size_t* pBufferSize, size_t *pnBuffersLeft );

        /**
        \brief Register a wait object. Optional.

        Register a different event used for waiting for buffers in the output queue.
        On windows, this must be an event created using CreateEvent().
        You can safely cast the HANDLE returned from CreateEvent() to WaitObject_t

        The handle of the event is duplicated. The new event replaces the existing event.
        The signal state of the previous event is transferred to the new event.
        */
        UXSTATUS RegisterWaitObject( WaitObjectHandle waitObject);

        /// Checks if the event stream is open.
        bool IsOpen() const;


        /// List of all available properties
        enum EPropertyValue
        {
            //<> [INCLUDE]["PropertyEnum.tpl.h"]
                                                                                //$
            /**                                                                 //$
                \brief Value of NumBuffer. The type is uint32_t.                //$
                Number of buffers to be used.                                   //$
            */                                                                  //$
            NumBufferValue = 0x200,                                             //$
                                                                                //$
            /**                                                                 //$
                \brief Value of NumMaxQueuedUrbs. The type is uint32_t.         //$
                The maximum number of requests to be enqueued to the driver.    //$
            */                                                                  //$
            NumMaxQueuedUrbsValue = 0x300,                                      //$
                                                                                //$
            /**                                                                 //$
                \brief Value of MaximumTransferLength. The type is uint32_t.    //$
                The maximum transfer length used for events.                    //$
            */                                                                  //$
            MaximumTransferLengthValue = 0x400,                                 //$
                                                                                //$
            /**                                                                 //$
                \brief Value of TotalEventCount. The type is int64_t.           //$
                The total count of processed events.                            //$
            */                                                                  //$
            TotalEventCountValue = 0x500,                                       //$
                                                                                //$
            /**                                                                 //$
                \brief Value of FailedEventCount. The type is int64_t.          //$
                The count of processed events with an error status.             //$
            */                                                                  //$
            FailedEventCountValue = 0x600,                                      //$
                                                                                //$
            /**                                                                 //$
                \brief Value of LastFailedEventBufferStatus. The type is UXSTATUS.//$
                The status code of the last failed event buffer.                //$
            */                                                                  //$
            LastFailedEventBufferStatusValue = 0x700,                           //$
                                                                                //$
            /**                                                                 //$
                \brief Value of TransferLoopThreadPriority. The type is int32_t.//$
                The priority of the thread that handles  the USB requests of the stream interface.//$
            */                                                                  //$
            TransferLoopThreadPriorityValue = 0x800,                            //$
            /** \brief Maximum value of TransferLoopThreadPriority */           //$
            TransferLoopThreadPriorityMax = 0x808,                              //$
            /** \brief Minimum value of TransferLoopThreadPriority */           //$
            TransferLoopThreadPriorityMin = 0x810,                              //$
                                                                                //$
            /**                                                                 //$
                \brief Value of GenerateNumTestEvents. The type is uint8_t.     //$
                Generates a number of test events.                              //$
            */                                                                  //$
            GenerateNumTestEventsValue = 0x900,                                 //$
                                                                                //$
        };

        /// Gets a property value. See EPropertyValue.
        UXSTATUS GetProperty( EPropertyValue propertyId, void *pValue, size_t valueSize) const;

        /// Sets a property value. EPropertyValue.
        UXSTATUS SetProperty( EPropertyValue propertyId, const void *pValue, size_t valueSize);

        /// Constructor. Internal use only.
        CUxEventStream(CUxEventStreamImpl * pImpl);

        /// Destructor. Internal use only.
        ~CUxEventStream();
    private:
        CUxEventStream( const CUxEventStream& );
        CUxEventStream& operator=(const CUxEventStream& );

        friend class CUxDevice;   ///< CUxDevice is a friend of CUxStream.

        CUxEventStreamImpl * m_pImpl;
    };
}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */
