//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Declaration of the CBxStreamWrapper class
 * \ingroup public
 */
#pragma once

#include <stddef.h>

#include <bxapi/BxTypes.h>
#include <bxapi/BxStatus.h>
#include <bxapi/BxStream.h>


#ifdef _MSC_VER
#   pragma pack(push, BX_PACKING)
#endif /* _MSC_VER */

namespace bxapi
{
    class CBxDeviceWrapper;
    class CBxStreamWrapper;

    /// Used for grabbing images. Wraps BxapiStreamHandle
    class CBxStreamWrapper
    {
    public:
        typedef void (BX_CALL *CBxStreamWrapperCallback)(CBxStreamWrapper *hStream, size_t imageReadyCount, void *userContext);

        /// default c'tor
        /// \param[in] hDevice Given by the corresponding device
        CBxStreamWrapper(BxapiDeviceHandle hDevice)
            : m_streamingSupported(true)
            , m_hStream(NULL)
            , m_hMyDevice(hDevice)
            , userCallbackFunction(NULL)
            , userContextData(NULL)
        {
        }

        /// default d'tor
        ~CBxStreamWrapper()
        {
            DestroyBxStream();
        }

        /** \brief See BxapiStreamOpen()
            \return The status of the operation.
        */
        BXSTATUS Open()
        {
            return BxapiStreamOpen(m_hStream);
        }

        /** \brief See BxapiStreamClose()
             \return The status of the operation.
        */
        BXSTATUS Close()
        {
            return BxapiStreamClose(m_hStream);
        }

        /** \brief See BxapiStreamPrepareGrab()
            \param [in] nMaxBuffer
            \param [in] MaxBufferSize
            \return The status of the operation.
            */
        BXSTATUS PrepareGrab(size_t nMaxBuffer, size_t MaxBufferSize)
        {
            return BxapiStreamPrepareGrab(m_hStream, nMaxBuffer, MaxBufferSize);
        }

        /** \brief See BxapiStreamRegisterBuffer()
            \param [in] pBuffer
            \param [in] BufferSize
            \param [out] phBuffer
            \return The status of the operation.
        */
        BXSTATUS RegisterBuffer(void* pBuffer, size_t BufferSize, BxapiBufferHandle *phBuffer)
        {
            //TODO: rename ::BufferHandle to more specific name
            return BxapiStreamRegisterBuffer(m_hStream, pBuffer, BufferSize, phBuffer);
        }

        /** \brief See BxapiStreamCancelGrab()
            \return The status of the operation.
        */
        BXSTATUS CancelGrab()
        {
            return BxapiStreamCancelGrab(m_hStream);
        }

        /** \brief See BxapiStreamStartStreaming()
            \return The status of the operation.
        */
        BXSTATUS StartStreaming()
        {
            return BxapiStreamStartStreaming(m_hStream);
        }

        /** \brief See BxapiStreamStopStreaming()
            \return The status of the operation.
        */
       BXSTATUS StopStreaming()
        {
            return BxapiStreamStopStreaming(m_hStream);
        }

        /** \brief See BxapiStreamQueueBuffer()
            \param [in] hBuffer
            \param [in] userContext
            \return The status of the operation.
        */
        BXSTATUS QueueBuffer(BxapiBufferHandle hBuffer, const void* userContext)
        {
            return BxapiStreamQueueBuffer( m_hStream, hBuffer, userContext);
        }

        /** \brief See BxapiStreamWaitForBuffer()
            \param [in] timeout
            \return The status of the operation.
        */
        BXSTATUS WaitForBuffer(uint32_t timeout)
        {
            return BxapiStreamWaitForBuffer(m_hStream, timeout);
        }

        /** \brief See BxapiStreamRetrieveBuffer()
            \param [out] pGrabResult
            \param [out] pBuffersRemaining
            \return The status of the operation.
        */
        BXSTATUS RetrieveBuffer(BxapiGrabResult* pGrabResult, size_t *pBuffersRemaining)
        {
            return BxapiStreamRetrieveBuffer(m_hStream, pGrabResult, pBuffersRemaining);
        }

        /** \brief See BxapiStreamDeregisterBuffer()
            \param [in] hBuffer
            \param [out] ppBuffer
            \return The status of the operation.
        */
        BXSTATUS DeregisterBuffer(BxapiBufferHandle hBuffer, void** ppBuffer)
        {
            return BxapiStreamDeregisterBuffer(m_hStream, hBuffer, ppBuffer);
        }

        /** \brief See BxapiStreamFinishGrab()
            \return The status of the operation.
        */
        BXSTATUS FinishGrab()
        {
            return BxapiStreamFinishGrab(m_hStream);
        }

        /** \brief See BxapiStreamRegisterCallback()
            \param [in]  callback
            \param [in]  userContext
            \return The status of the operation.
        */
        BXSTATUS RegisterCallback(CBxStreamWrapperCallback callback, void* userContext)
        {
            userCallbackFunction = callback;
            userContextData = userContext;

            if (callback != NULL)
            {
                return BxapiStreamRegisterCallback(m_hStream, bxapi::CBxStreamWrapper::BxStreamWrapperCallback, this);
            }
            else
            {
                return BxapiStreamRegisterCallback(m_hStream, NULL, NULL);
            }
        }

        /** \brief See BxapiStreamGetState()
            \return Current state of the stream.
        */
        BxapiStreamState GetState() const
        {
            return BxapiStreamGetState(m_hStream);
        }

        /** \brief See BxapiDeviceGetProperty()
            \param [in] propertyId
            \param [out] pPropertyData
            \param [in] propertyDataSize
            \return The status of the operation.
        */
        BXSTATUS GetProperty(uint64_t propertyId, void *pPropertyData, size_t propertyDataSize) const
        {
            return BxapiStreamGetProperty(m_hStream, propertyId, pPropertyData, propertyDataSize);
        }

        /** \brief See BxapiDeviceSetProperty()
            \param [in] propertyId
            \param [in] pPropertyData
            \param [in] propertyDataSize
            \return The status of the operation.
        */
        BXSTATUS SetProperty(uint64_t propertyId, const void *pPropertyData, size_t propertyDataSize)
        {
            return BxapiStreamSetProperty(m_hStream, propertyId, pPropertyData, propertyDataSize);
        }

        /** \brief Returns true if Open() has been called successfully.
            \return Returns true if Open() has been called successfully.
        */
        bool IsOpen() const
        {
            BxapiStreamState state = GetState();

            return  (state == BxapiStreamState_Opened) ||
                    (state == BxapiStreamState_Prepared) ||
                    (state == BxapiStreamState_Streaming);
        }

        /** \brief Returns true if PrepareGrab() has been called successfully.
            \return Returns true if PrepareGrab() has been called successfully.
        */
        bool IsPrepared() const
        {
            BxapiStreamState state = GetState();

            return  (state == BxapiStreamState_Prepared) ||
                    (state == BxapiStreamState_Streaming);
        }

        
        /** \brief Returns true if StartStreaming() has been called successfully.
            \return Returns true if StartStreaming() has been called successfully.
        */
        bool IsStreaming() const
        {
            return (GetState() == BxapiStreamState_Streaming);
        }

        // Callback for Bxapi
        static void BX_CALL BxStreamWrapperCallback(BxapiStreamHandle hStream, size_t imageReadyCount, void *userContext)
        {
            BX_UNUSED(hStream);

            CBxStreamWrapper *helper = static_cast<CBxStreamWrapper*>(userContext);

            if (helper != NULL)
            {
                if (helper->userCallbackFunction != NULL)
                {
                    helper->userCallbackFunction(helper, imageReadyCount, helper->userContextData);
                }
            }
        }

        /** \brief See BxapiStreamCreate()
        \return Status code from BxapiStreamCreate()
        */
        BXSTATUS LazyCreateBxStream()
        {
            BXSTATUS status = BX_OK;
            if (m_streamingSupported)
            {
                if (m_hStream == NULL)
                {
                    status = BxapiStreamCreate(m_hMyDevice, &m_hStream);
                    if (status == BX_E_BCON_ADAPTER_FUNCTION_IS_MISSING)
                    {
                        m_hStream = NULL;
                        m_streamingSupported = false;
                    }
                }
            }
            return status;
        }
        
        /** \brief See BxapiStreamDestroy()
        */
        void DestroyBxStream()
        {
            // Call BCON adapter API
            if (m_hStream != NULL)
            {
                BxapiStreamDestroy(m_hStream);
                m_hStream = NULL;
            }
        }
        
        /** \brief Tries to create the BX stream if not already done and checks whether streaming is supported.
        \return Returns true if the BCON Adapter Library supports streaming.
        */
        bool IsStreamingSupported()
        {
            LazyCreateBxStream();
            return m_streamingSupported;
        }
    private:
        CBxStreamWrapper( const CBxStreamWrapper& );
        CBxStreamWrapper& operator=(const CBxStreamWrapper& );

        bool m_streamingSupported;
        BxapiStreamHandle m_hStream;
        BxapiDeviceHandle m_hMyDevice;

        CBxStreamWrapperCallback userCallbackFunction;
        void* userContextData;
    };
}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */
