//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2017 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Declaration of the CUxDevice class
*/
#pragma once

#include "UxDll.h"
#include "UxStatus.h"
#include "UxNotification.h"
#include "Enumerator.h"

#ifdef _MSC_VER
#   pragma pack(push, UX_PACKING)
#endif /* _MSC_VER */


namespace GenCP_1_0
{
    class CChannel;
    struct ManifestTableEntryVersionInfo_t;
}

namespace uxapi
{

    // --------------------------------------------------------------------------
    // forward declarations
    class CUxStream;
    class CUxEventStream;
    class CUxStreamImplBase;
    class CUxDeviceNotifier;
    class CUxPipe;
    class CUxInterface;
    class CUxDevice;
    class CCustomRequestData;
    class CUxLowLevelDevice;
    struct UxCallbackData;
    struct CRecursiveLock;


    // --------------------------------------------------------------------------
    /// Stores an XML file.
    class UX_API CXmlFile
    {
    public:
        /// Constructor.
        CXmlFile();
        /// Destructor.
        ~CXmlFile();
        /// Gets the buffer.
        const uint8_t* GetBuffer() const;
        /// Gets the buffer size.
        size_t GetBufferSize() const;

    private:
        CXmlFile(const CXmlFile&);
        const CXmlFile& operator=(const CXmlFile&);
        void Init(const uint8_t* pBuffer, size_t bufferSize);

        uint8_t* m_pBuffer; ///< The buffer
        size_t m_BuferSize; ///< The buffer size.

        friend class CUxDevice;   ///< CUxDevice is a friend of CXmlFile.
    };


    // --------------------------------------------------------------------------
    /**
    \class CUxDevice
    \brief Represents a USB camera device

    \threading
    The CUxDevice class methods are thread-safe.
    */
    class UX_API CUxDevice
    {
    public:
        /**
        \brief Creates a USB camera device object.
        \error  No-Fail.
        */
        CUxDevice(void);

        /**
        \brief Create a USB camera device
        \param[in] deviceType the type of the device to create
        \return The created device is returned or NULL a device could not be created.
        */
        static CUxDevice* CreateDevice( EDeviceType deviceType);

        /**
        \brief Destroys a USB camera device
        If the stream is open it is closed before destruction.
        If the device is open it is closed before destruction.
        \post
        The object pointed to is freed and may not be used anymore.
        \error No fail.
        */
        static void DestroyDevice( CUxDevice* );

        /**
        \brief Open the specified USB camera device.
        \param[in] pDeviceInfo Pointer to a device info object, received by the enumeration.
        \return The status of the operation.
        \pre
        The device is closed.
        \post
        <ul>
        <li> The device is open.
        <li> The device is observing device removal events.
        <li> The stream is closed.
        </ul>
        */
        UXSTATUS Open( const DeviceDiscoveryInfo* pDeviceInfo );

        /**
        \brief Close the USB camera device
        \return The status of the operation.
        \post
        <ul>
        <li> Streaming is stopped.
        <li> The device is closed.
        <li> The stream stays open even though the device is closed. This allows the user to retrieve all buffers.
        <li> The device is not observing device removal events.
        </ul>
        */
        UXSTATUS Close();

        /// Returns true if the USB camera device is open.
        bool IsOpen() const;

        /**
        \brief Reads the xml file from the device.
        Always the first processable XML file is provided.
        \param XmlFile Container for the XML file.
        \pre
        The USB camera device must be open.
        \return Returns UX_OK in case of success.
        */
        UXSTATUS ProvideXmlFile( CXmlFile& XmlFile);

        /**
        \brief  Read memory of the USB camera device
        \param[in]  buf Pointer to the buffer receiving the data
        \param[in]  address Location of the memory in the USB device
        \param[in,out]  pCount Pointer to a variable containing the number of bytes to read, resp. been read
        \return The status of the operation.
        \retval UX_E_DEVICE_NOT_OPEN if not yet opened
        \pre
        The USB camera device must be open.
        */
        UXSTATUS ReadMem( void* buf, uint64_t address,  size_t *pCount );
        /**
        \brief  Write memory to the USB camera device
        \param[in]  buf Pointer to the buffer containing the data
        \param[in]  address Location of the memory in the USB device
        \param[in]  count The number of bytes to write.
        \return The status of the operation.
        \retval UX_E_DEVICE_NOT_OPEN if not yet opened
        \pre
        The USB camera device must be open.
        */
        UXSTATUS WriteMem( const void* buf, uint64_t address, size_t count );

#ifdef WIN32
        /**
        \brief Returns the file handle of the underlying driver.
        \param[out] h The file handle.
        \return The status of the operation.
        \retval UX_OK on Success.
        \pre
        The USB camera device must be open.
        */
        virtual UXSTATUS GetFileHandle(HANDLE& h) = 0;  // for PnP handling
#endif

        /**
        \brief Gets the stream.
        The stream is created when the device is created.
        The stream is destroyed when the device is destroyed and must not be used
        after destruction of the device.
        \return The status of the operation is returned.
        */
        UXSTATUS GetStream( CUxStream**);

        /**
        \brief Gets the event stream.
        The event stream is created when the device is created.
        The event stream is destroyed when the device is destroyed and must not be used
        after destruction of the device.
        \return The status of the operation is returned.
        */
        UXSTATUS GetEventStream( CUxEventStream**);

        /// List of all available properties
        enum EPropertyValue
        {
            //<> [INCLUDE]["PropertyEnum.tpl.h"]
                                                                                //$
            /**                                                                 //$
                \brief Value of ReadPipeResetCount. The type is int64_t.        //$
                The total count of read pipe resets.                            //$
            */                                                                  //$
            ReadPipeResetCountValue = 0x200,                                    //$
                                                                                //$
            /**                                                                 //$
                \brief Value of WritePipeResetCount. The type is int64_t.       //$
                The total count of write pipe resets.                           //$
            */                                                                  //$
            WritePipeResetCountValue = 0x300,                                   //$
                                                                                //$
            /**                                                                 //$
                \brief Value of ReadOperationsFailedCount. The type is int64_t. //$
                The total count of failed read operations.                      //$
            */                                                                  //$
            ReadOperationsFailedCountValue = 0x400,                             //$
                                                                                //$
            /**                                                                 //$
                \brief Value of WriteOperationsFailedCount. The type is int64_t.//$
                The total count of failed write operations.                     //$
            */                                                                  //$
            WriteOperationsFailedCountValue = 0x500,                            //$
                                                                                //$
            /**                                                                 //$
                \brief Value of LastErrorStatus. The type is UXSTATUS.          //$
                The last error status for a read or write operation.            //$
            */                                                                  //$
            LastErrorStatusValue = 0x600,                                       //$
                                                                                //$
            /**                                                                 //$
                \brief Value of CustomRequestId. The type is uint8_t.           //$
                Part of a custom request to the USB device. Maps to bRequest.   //$
            */                                                                  //$
            CustomRequestIdValue = 0xAFFE0000,                                  //$
                                                                                //$
            /**                                                                 //$
                \brief Value of CustomRequestValue. The type is uint16_t.       //$
                Part of a custom request to the USB device. Maps to wValue.     //$
            */                                                                  //$
            CustomRequestValueValue = 0xAFFE0100,                               //$
                                                                                //$
            /**                                                                 //$
                \brief Value of CustomRequestIndex. The type is uint16_t.       //$
                Part of a custom request to the USB device. Maps to wIndex.     //$
            */                                                                  //$
            CustomRequestIndexValue = 0xAFFE0200,                               //$
                                                                                //$
            /**                                                                 //$
                \brief Value of CustomRequestDataLength. The type is uint16_t.  //$
                Part of a custom request to the USB device. Maps to wLength.    //$
            */                                                                  //$
            CustomRequestDataLengthValue = 0xAFFE0300,                          //$
                                                                                //$
            /**                                                                 //$
                \brief Value of CustomRequestExecuteRead. The type is uint8_t.  //$
                Execute custom request read. Custom request fields need to be set first.//$
            */                                                                  //$
            CustomRequestExecuteReadValue = 0xAFFE0400,                         //$
                                                                                //$
            /**                                                                 //$
                \brief Value of CustomRequestExecuteWrite. The type is uint8_t. //$
                Execute custom request write. Custom request fields and data need to be set first.//$
            */                                                                  //$
            CustomRequestExecuteWriteValue = 0xAFFE0500,                        //$
                                                                                //$

            /// The custom request data buffer address space. The maximum size is 64KB.
            CustomRequestDataBuffer = 0xAFFF0000,
            /// The message text of the status code of the last failed operation.  The maximum size is 1KB.
            LastErrorStatusText = 0x000F0000
        };

        /// Gets a property value. See CUxDevice::EPropertyValue.
        UXSTATUS GetProperty( EPropertyValue propertyId, void *pValue, size_t valueSize) const;

        /// Sets a property value. See CUxDevice::EPropertyValue.
        UXSTATUS SetProperty( EPropertyValue propertyId, const void *pValue, size_t valueSize);

        /// Cycle port operation is similar to the device being unplugged and then plugged back in,
        /// except that the device is not electrically disconnected.
        /// Used for debugging purposes only.
        virtual UXSTATUS CyclePort();

        /// Resets a Basler camera device. Used for debugging purposes only.
        virtual UXSTATUS ResetDevice();

        // -------------------------------------------------------------------
        // -------------------------------------------------------------------
        // -------------------------------------------------------------------
    protected:  // Driver specific virtual methods. Internal use only.
        friend class CUxBulkStreamImpl;

        /**
        \brief Opens a device. Internal use only.
        \param info The device info retrieve by device discovery.
        */
        virtual UXSTATUS OpenDevice( const DeviceDiscoveryInfo& info) = 0;

        /// Close device. Internal use only.
        virtual UXSTATUS CloseDevice() = 0;

        /**
        \brief Gets the device info. Internal use only.
        \param info The device info retrieve by device discovery.
        */
        virtual UXSTATUS GetDeviceInfo( DeviceDiscoveryInfo& info) const = 0;

        /**
        \brief Gets the number of interfaces. Internal use only.
        \param num The number of interface.
        */
        virtual UXSTATUS GetNumInterfaces( size_t& num );

        /**
        \brief Gets the interfaces related to certain index. Internal use only.
        \param idx The index of the interface.
        \param pInterface Pointer to interface with index idx.
        \return Returns UX_OK in case of success.
        */
        virtual UXSTATUS GetInterface( uint8_t idx, CUxInterface*& pInterface ) =0;

#ifdef WIN32
        /// Returns GUID of device interface.
        virtual GUID GetDeviceInterfaceGuid() const = 0;
#endif

        /// Connect to stream.  Internal use only.
        virtual UXSTATUS ConnectToStream();

        /// Disconnect from stream.  Internal use only.
        virtual UXSTATUS DisconnectFromStream();

        /// Connect to event stream.  Internal use only.
        virtual UXSTATUS ConnectToEventStream();

        /// Disconnect from event stream.  Internal use only.
        virtual UXSTATUS DisconnectFromEventStream();

        /// Called when the device has been removed.
        static void __stdcall OnSurpriseRemovalCallbackHandler(const uxapi::UxCallbackData* pData);

        /// Returns the mutex. Internal use only.
        CRecursiveLock* GetLock() { return m_pLock; }

        /// SetProperty and GetProperty can be used to issue custom requests. Internal use only.
        virtual bool AreCustomRequestsSupported() const;

        /// SetProperty and GetProperty can be used to issue custom requests. Internal use only.
        virtual UXSTATUS CustomReadRequest( CCustomRequestData* pCustomRequestData);

        /// SetProperty and GetProperty can be used to issue custom requests. Internal use only.
        virtual UXSTATUS CustomWriteRequest( CCustomRequestData* pCustomRequestData);

        /// Returns the device index. Internal use only;
        virtual long GetDeviceIdx() const;
        /**
        \brief Destroys the USB camera device. Internal use only.
        If the device is open it is closed before destruction.
        */
        virtual ~CUxDevice(void);

        /// Internal helper for opening libusb
        UXSTATUS OpenInternal(const DeviceDiscoveryInfo* pDeviceInfo);

    private:
        // The device can't be copied.
        CUxDevice( const CUxDevice& );
        CUxDevice& operator=( const CUxDevice& );

        bool                                m_isOpen;   ///< Is true, if the device is open, false otherwise.
        GenCP_1_0::CChannel*                m_pChannel; ///< Channel
        CUxStream*                          m_pStream;  ///< Stream
        CUxEventStream*                     m_pEventStream;  ///< Event Stream
        mutable CRecursiveLock*                m_pLock;    ///< Mutex to lock device
        CUxInterface*                       m_pStreamInterface;     ///< The stream interface.
        CUxInterface*                       m_pEventStreamInterface;     ///< The event stream interface.
        bool                                m_deviceHasBeenRemoved; ///< Is true if device has been removed, false otherwise.
        UxCallbackHandle                    m_hRemovalCallback; ///< The removal callback is used to close the device handle on removal.
        UxCallbackHandle                    m_hSuspendCallback; ///< Suspend is treated in the same way as device removal.
        CCustomRequestData*                 m_pCustomRequestData; ///< Holds custom request data.
        long                                m_DeviceIdx; ///< Each device instance gets a unique index. Used for ETW traces (as InstanceId)
        bool                                m_USB2deviceHasBeenLimited; ///< Is true if device is USB2 and already has limited the MaximumTransferSize.

        friend UX_API UXSTATUS UX_CALL Exit();
        friend class CUxLowLevelDevice;
        friend class CUxDeviceNotifier;
    };

}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */
