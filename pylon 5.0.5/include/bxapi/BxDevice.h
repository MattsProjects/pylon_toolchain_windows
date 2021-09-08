//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Declaration of Device part for BXAPI
* \ingroup public
*/
#pragma once
#include <stddef.h>
#include "BxTypes.h"
#include "BxStatus.h"
#include "BxDll.h"
#include "BxEnumerator.h"

#pragma pack(push, BX_PACKING)

EXTERN_C_BEGIN

/** State of the device. Use BxapiDeviceGetSate() to retrieve the current state. */
enum BxapiDeviceState
{
      DeviceState_Invalid = 0   ///< Device not found or has been disconnected or the handle passed to BxapiDeviceGetState() is invalid
    , DeviceState_Closed = 1    ///< Device is closed
    , DeviceState_Opened = 2    ///< Device is opened
};

/**
\brief Creates a device.
This function creates a bxapi device and on success returns the device handle in phDev.
For each successfull created device you must call BxapiDeviceDestroy().
\param [in] pDeviceInfo Pointer to a device info returned by a previous device discovery.
\param [out] phDev On success this pointer is used to store the device handle of the newly created device.
\return The status of the operation.
\pre - A successful device discovery has been performed.
\post - A device has been created.
\post - The device is closed.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiDeviceCreate(BxapiDeviceDiscoveryInfo *pDeviceInfo, BxapiDeviceHandle *phDev);


/**
\brief Destroys a device created by BxapiDeviceCreate().
This function frees all data associated with the device passed in hDev.
\param [in] hDev Device handle to be destroyed.
\return The status of the operation.
\pre - The device in hDev has been successfully created.
\post All the resources associated with the device have been released.
\threading
This function is thread-safe. Calling this function while other threads access the device or it's stream will result in undefined behavior.
*/
BX_API BXSTATUS BxapiDeviceDestroy(BxapiDeviceHandle hDev);


/**
\brief Opens the camera device.
Opens the specified device.
After a sucessful call to BxapiDeviceOpen() you can can start reading and writing to the device by using the BxapiDeviceRead() and BxapiDeviceWrite() functions.
\param [in] hDev Device handle.
\return The status of the operation.
\pre - The device has been created.
\pre - The device is closed.
\post - The device is opened.
\post - The stream is closed.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiDeviceOpen(BxapiDeviceHandle hDev);


/**
\brief Closes the camera device.
Closes the camera prviously opened by a call to BxapiDeviceOpen().
\param [in] hDev Device handle.
\return The status of the operation.
\pre - The device has been opened by a call to BxapiDeviceOpen().
\post - Streaming is stopped.
\post - The device is closed.
\post - The device state is closed.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiDeviceClose(BxapiDeviceHandle hDev);


/**
\brief Returns the current state of the device.
Returns the current state of the device. 
\param [in] hDev Device handle.
\return Returns one of the states specified in the BxapiDeviceState enumeration.
\pre - The device has been created by a call to BxapiDeviceCreate().
\threading
This function is thread-safe.
*/
BX_API BxapiDeviceState BxapiDeviceGetState(BxapiDeviceHandle hDev);


/** 
\brief Returns a device specific meta data property specified by propertyId.
Returns a device specific meta data property specified by propertyId. The size and type of property data is determined by the property id. 
See property id defines for more information, e.g. \link BXAPI_PROPERTYID_LASTERRORSTATUS_VALUE \endlink.
\param [in] hDev Device handle.
\param [in] propertyId Specifies which property to return.
\param [out] pPropertyData Destination buffer to copy the property data to.
\param [in] propertyDataSize Size of destination buffer passed in pPropertyData.
                             The data type of each property is defined in the documentation of the property.
                             The passed data buffer must be large enough to hold the property data.
\return The status of the operation. If the buffer is not large enough to hold data, BX_E_INSUFFICIENT_BUFFER is returned and the required size is returned in pRequiredDataSize.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiDeviceGetProperty(BxapiDeviceHandle hDev, uint64_t propertyId, void *pPropertyData, size_t propertyDataSize);

/**
\brief Sets a device specific meta data property specified by propertyId.
Sets a device specific meta data property specified by propertyId. The size and type of property data is determined by the property id.
See property id defines for more information, e.g. \link BXAPI_PROPERTYID_LASTERRORSTATUS_VALUE \endlink.
\param [in] hDev Device handle.
\param [in] propertyId Specifies which property to return.
\param [in] pPropertyData Source buffer to copy the property data from.
\param [in] propertyDataSize Size of source buffer passed in pPropertyData.
\return The status of the operation.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiDeviceSetProperty(BxapiDeviceHandle hDev, uint64_t propertyId, const void *pPropertyData, size_t propertyDataSize);


/**
\brief Reads data from the device.
\param [in] hDev Device handle.
\param [in] address Address on the device to read data from.
\param [out] pBuffer Points to the destination buffer to copy the data to.
\param [in] sizeInByte Specifies the size of the buffer in bytes pBuffer points to and the number of bytes to read.
\return The status of the operation.
\pre - The device has been opened by a call to BxapiDeviceOpen().
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BxapiDeviceRead(BxapiDeviceHandle hDev, uint64_t address, void *pBuffer, size_t sizeInByte);


/**
\brief Writes data to the the device.
\param [in] hDev Device handle.
\param [in] address Address on the device to write data to.
\param [out] pBuffer Points to buffer to read the data from.
\param [in] sizeInBytes Specifies the number of bytes to read from pBuffer.
\return The status of the operation.
\pre - The device has been opened by a call to BxapiDeviceOpen().
*/
BX_API BXSTATUS BxapiDeviceWrite(BxapiDeviceHandle hDev, uint64_t address, const void *pBuffer, size_t sizeInBytes);


/**
\brief Reads the camera description file (xml/zip) from the device.
Reads the camera description file (xml/zip) from the device. If the device provides multiple file, only the first file is returned.
\param [in] hDev Device handle.
\param [out] pBuffer Data buffer.
\param [in] sizeInBytes The size of the buffer passed in pBuffer.
\param [out] pRequiredSize Optional parameter returns the number of bytes needed to store the description file.
\return The status of the operation. If the buffer is not large enough to hold data, BX_E_INSUFFICIENT_BUFFER is returned and the required size is returned in pRequiredDataSize.
\pre - The device has been opened by a call to BxapiDeviceOpen().
*/
BX_API BXSTATUS BxapiDeviceProvideCameraDescriptionFile(BxapiDeviceHandle hDev, void *pBuffer, size_t sizeInBytes, size_t* pRequiredSize);


//<> [INCLUDE]["PropertyDefines.tpl.h"]
 /** \brief Value of ReadOperationsFailedCount; The type is int64_t; The total count of failed read operations. (read only) */                        //$
#define BXAPI_PROPERTYID_READOPERATIONSFAILEDCOUNT_VALUE 0xD0100                                                                                      //$
/** \brief Value of WriteOperationsFailedCount; The type is int64_t; The total count of failed write operations. (read only) */                       //$
#define BXAPI_PROPERTYID_WRITEOPERATIONSFAILEDCOUNT_VALUE 0xD0200                                                                                     //$
/** \brief Value of LastErrorStatus; The type is BXSTATUS; The last error status for a read or write operation. (read only) */                        //$
#define BXAPI_PROPERTYID_LASTERRORSTATUS_VALUE 0xD0300                                                                                                //$
                                                                                                                                                      //$
/** \brief The message text of the status code of the last read write failed operation. The maximum size is 1KB. */
#define BXAPI_PROPERTYID_LASTERRORSTATUSTEXT_VALUE 0xDF000

EXTERN_C_END

#pragma pack(pop)
