//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2015 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Declaration of the CEnumerator class used for discovering U3V devices.
 */
#pragma once

#include "UxDll.h"
#include "UxStatus.h"

#ifdef _MSC_VER
#   pragma pack(push, UX_PACKING)
#endif /* _MSC_VER */

namespace uxapi
{
    /// The type of device.
    enum EDeviceType
    {
        DeviceType_WinUsb,      ///< A WinUSB device.
        DeviceType_BaslerUsb,   ///< A Basler USB device.
        DeviceType_Libusb       ///< A LibUsb device
    };

    const size_t cDevInfoMaxStringLength = 255; ///< Maximum string length of a devive info.

    /// Device information block
    struct DeviceDiscoveryInfo
    {
        uint8_t     DeviceIdx;  ///< Result of enumeration.
        uint16_t    VendorID;   ///< Result of idVendor (Device Descriptor).
        uint16_t    ProductID;  ///< Result of idProduct (Device Descriptor).

        char     SerialNumberOfDeviceDescriptor[cDevInfoMaxStringLength + 1];    ///< Result of iSerialNumber (Device Descriptor) and String Descriptor if device is not an USB3 Vision camera OR iSerialNumber (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.
        char     Product[cDevInfoMaxStringLength + 1];                           ///< Result of iProduct (Device Descriptor) and String Descriptor
        char     Manufacturer[cDevInfoMaxStringLength + 1];                      ///< Result of iManufacturer (Device Descriptor) and String Descriptor

        char     SerialNumberOfCameraInfoDescriptor[cDevInfoMaxStringLength + 1];    ///< Result of iSerialNumber (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.
        char     ManufacturerInfo[cDevInfoMaxStringLength + 1];                      ///< Result of iManufacturerInfo (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.
        char     UserDefinedName[cDevInfoMaxStringLength + 1];                       ///< Result of iUserDefinedName (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.
        char     DeviceGUID[cDevInfoMaxStringLength + 1];                            ///< Result of iDeviceGUID (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.
        char     VendorName[cDevInfoMaxStringLength + 1];                            ///< Result of iVendorName (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.
        char     ModelName[cDevInfoMaxStringLength + 1];                             ///< Result of iModelName (Camera Info Descriptor) and String Descriptor if device is an USB3 Vision camera.

        char        DevPath[cDevInfoMaxStringLength + 1];                               ///< The device path.

        EDeviceType DeviceType;                 ///< The device type.

        uint16_t    BcdUsb;                     ///< USB version in BCD format (e.g. if USB 3.0 is supported, BcdUsb = 0x0300)
        uint8_t     SpeedSupport;               ///< 0-th bit (lsb) is set: FullSpeed is supported; 1-th bit is set: HighSpeed is supported; 2-th bit is set: SuperSpeed is supported;
        bool        IsBufferedTransferDevice;   ///< Indicates that device uses buffered transfer mode instead of direct transfer mode
    };

    /// USB camera device enumerator
    class CEnumerator
    {

    public:
        /// Callback interface to be provided for device enumeration.
        class UX_API Callee
        {
        public:
            /// Called when a device is found
            virtual UXSTATUS EnumCallback(
                /// Discovery Information.
                const DeviceDiscoveryInfo *pDiscoveryInfo
            ) = 0;
        };

    public:
        /**
            \brief Discover USB camera devices.

            Runs the discovery process.

            \param pCallee Pointer to the callback interface.

            \return Status of discovery.
        */
        static UX_API UXSTATUS Discover( Callee *pCallee );

        /**
            \brief Retrieve device information for a given device path.

            \param[in] pDevicePath The device path.
            \param[out] deviceInfo The returned device information. DeviceInfo is set to zero if the information retrieval fails.

            \return Status of the operation.
        */
        static UX_API UXSTATUS DeviceInfoFromPath( const wchar_t* pDevicePath, DeviceDiscoveryInfo& deviceInfo );

        /**
            \copybrief UXSTATUS DeviceInfoFromPath( const wchar_t* pDevicePath, DeviceDiscoveryInfo& deviceInfo )
            \copydoc UXSTATUS DeviceInfoFromPath( const wchar_t* pDevicePath, DeviceDiscoveryInfo& deviceInfo )
        */
        static UX_API UXSTATUS DeviceInfoFromPath( const char* pDevicePath, DeviceDiscoveryInfo& deviceInfo );

    };

}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */


