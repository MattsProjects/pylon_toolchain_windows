//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Declaration of the CBxDeviceWrapper class
* \ingroup public
*/
#pragma once

#include <stddef.h>
#include <vector>

#include <bxapi/BxTypes.h>
#include <bxapi/BxStatus.h>
#include <bxapi/BxDevice.h>
#include <bxapi/BxStreamWrapper.h>


#ifdef _MSC_VER
#   pragma pack(push, BX_PACKING)
#endif /* _MSC_VER */


namespace bxapi
{

    // --------------------------------------------------------------------------
    // forward declarations
    class CBxStreamWrapper;


    /// Wraps BxapiDeviceHandle
    class CBxDeviceWrapper
    {
        /** \brief default c'tor
        */
        CBxDeviceWrapper(BxapiDeviceHandle hDevice)
            : m_stream(hDevice)
            , m_hDevice(hDevice)
        {
        }

        /** \brief default d'tor
        */
        ~CBxDeviceWrapper(void)
        {
            if (m_hDevice)
            {
                m_stream.DestroyBxStream();
                BxapiDeviceDestroy(m_hDevice);
                m_hDevice = NULL;
            }
        }

    public:
        /** \brief See BxapiDeviceCreate()
            \param [in] discoveryInfo
            \return The status of the operation.
        */
        static CBxDeviceWrapper* CreateDevice(const BxapiDeviceDiscoveryInfo& discoveryInfo)
        {
            CBxDeviceWrapper* pNewDeviceWrapper = NULL;
            BxapiDeviceHandle hDevice = NULL;

            BXSTATUS status = BxapiDeviceCreate(const_cast<BxapiDeviceDiscoveryInfo *>(&discoveryInfo), &hDevice);
            if (BX_SUCCESS(status))
            {
                try
                {
                    pNewDeviceWrapper = new CBxDeviceWrapper(hDevice);
                }
                catch (...)
                {
                    status = BxapiDeviceDestroy(hDevice);
                    //bad alloc
                }
            }

            return pNewDeviceWrapper;
        }


        /** \brief See BxapiDeviceDestroy()
            \param [in] pBxDeviceWrapper
            \return The status of the operation.
        */
        static void DestroyDevice(CBxDeviceWrapper* pBxDeviceWrapper)
        {
            // Try to destroy stream first
            CBxStreamWrapper* pStream;
            pBxDeviceWrapper->GetStream(pStream);
            if (pStream != NULL)
            {
                pStream->DestroyBxStream();
            }

            // Destroy device
            BxapiDeviceDestroy(pBxDeviceWrapper->m_hDevice);
            pBxDeviceWrapper->m_hDevice = NULL;
            delete pBxDeviceWrapper;
        }

        /** \brief See BxapiDeviceOpen()
            \return The status of the operation.
        */
        BXSTATUS Open()
        {
            return BxapiDeviceOpen(m_hDevice);
        }

        /** \brief BxapiDeviceClose()
            \return The status of the operation.
        */
        BXSTATUS Close()
        {
            return BxapiDeviceClose(m_hDevice);
        }

        /** \brief Returns true when the device is open
            \return Returns true when the device is open
        */
        bool IsOpen() const
        {
            return BxapiDeviceGetState(m_hDevice) >= DeviceState_Opened;
        }

        /** \brief See BxapiDeviceProvideCameraDescriptionFile()
            \param [in] descriptionData
            \return The status of the operation.
        */
        BXSTATUS ProvideCameraDescriptionFile(std::vector<uint8_t>& descriptionData) const
        {

            // Double calling: First, get size of pBuffer
            size_t sizeInBytes = 0;
            BXSTATUS status = BxapiDeviceProvideCameraDescriptionFile(m_hDevice, NULL, 0, &sizeInBytes);
            
            if ( !( BX_SUCCESS(status) && (0<sizeInBytes) ) )
            {
                return status;
            }
            
            // get memory needed to hold the data
            descriptionData.clear();
            descriptionData.resize(sizeInBytes);

            status = BxapiDeviceProvideCameraDescriptionFile(m_hDevice, &descriptionData[0], sizeInBytes, NULL);

            if ( !(BX_SUCCESS(status)) )
            {
                descriptionData.clear();
            }

            return status;
        }

        /** \brief See BxapiDeviceRead()
            \param [in] address
            \param [out] pBuffer
            \param [in] sizeInBytes
            \return The status of the operation.
        */
        BXSTATUS Read(uint64_t address, void* pBuffer, size_t sizeInBytes)
        {
            return BxapiDeviceRead(m_hDevice, address, pBuffer, sizeInBytes);
        }

        /** \brief See BxapiDeviceWrite()
            \param [in] address
            \param [in] pBuffer
            \param [in] sizeInBytes
            \return The status of the operation.
        */
        BXSTATUS Write(uint64_t address, const void* pBuffer, size_t sizeInBytes)
        {
            return BxapiDeviceWrite(m_hDevice, address, pBuffer, sizeInBytes);
        }

        /** 
        */
        BXSTATUS GetStream(CBxStreamWrapper*& pStream)
        {
            BXSTATUS status = m_stream.LazyCreateBxStream();
            pStream = &m_stream;
            return status;
        }

        /** \brief See BxapiDeviceGetProperty()
            \param [in] propertyId
            \param [out] pPropertyData
            \param [in] propertyDataSize
            \return The status of the operation.
        */
        BXSTATUS GetProperty(uint64_t propertyId, void *pPropertyData, size_t propertyDataSize) const
        {
            return BxapiDeviceGetProperty(m_hDevice, propertyId, pPropertyData, propertyDataSize);
        }

        /** \brief See BxapiDeviceSetProperty()
            \param [in] propertyId
            \param [in] pPropertyData
            \param [in] propertyDataSize
            \return The status of the operation.
        */
        BXSTATUS SetProperty(uint64_t propertyId, const void *pPropertyData, size_t propertyDataSize)
        {
            return BxapiDeviceSetProperty(m_hDevice, propertyId, pPropertyData, propertyDataSize);
        }

    private:
        CBxStreamWrapper m_stream;
        BxapiDeviceHandle m_hDevice;
    };

}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */
