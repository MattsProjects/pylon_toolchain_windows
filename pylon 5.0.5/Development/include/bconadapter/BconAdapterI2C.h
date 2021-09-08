//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Defines the I2C interface of the BCON adapter.
* \ingroup public
*/

#pragma once

#include "BconAdapterDefines.h"
#include "BconAdapterTypes.h"
#include <stddef.h>

EXTERN_C_BEGIN


//-----------------------------------------------------------------------------
// Types
struct BconAdapterI2cBusHandle_tag;
/**
\typedef BconAdapterI2cBusHandle
\brief Handle representing an I2C bus instance.
A handle value of null is considered invalid.
*/
typedef struct BconAdapterI2cBusHandle_tag* BconAdapterI2cBusHandle;


//-----------------------------------------------------------------------------
// Functions


/**
\brief Opens the I2C bus connection to a camera device.
This call can be used to initialize I2C bus hardware or allocate resources needed.
\note The device address of the camera is also returned. This information is handed down to the read and write functions.
\param[in] deviceId         Device identifier received during discovery.
\param[out] phBus      I2C bus handle created. If multiple cameras share an I2C bus, the returned handles must be equal.
\param[out] pDeviceAddress  The device address (I2C) of the device. It will be used in BconAdapterI2cRead and BconAdapterI2cWrite operations.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_NOT_FOUND   if device is not available.
\retval Any other BCON adapter error code otherwise.
\post I2C bus is in use and the device is open.
\threading
This function must be thread-safe. It is assumed that a known fixed amount of cameras is attached
to a BCON system, so that required data structures can be allocated when BconAdapterInit() is called.
Therefore, thread-safety can be assured without using additional locking.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterI2cOpenConnection(
    const char deviceId[],
    BconAdapterI2cBusHandle *phBus,
    uint32_t *pDeviceAddress);


/**
\brief Closes the I2C bus connection to a camera device.
Memory and resources allocated during BconAdapterI2cOpenConnection() can be freed.
\param[in] hBus        Bus handle.
\param[in] deviceAddress    The device address (I2C) of the device.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_NOT_FOUND if device is not open.
\retval Any other BCON adapter error code otherwise.
\pre I2C bus is in connected state and the device is open.
\post The device is closed.
\threading
This function must be thread-safe.
Only one thread accesses the I2C functions at the same time per device address.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterI2cCloseConnection(
    BconAdapterI2cBusHandle hBus,
    uint32_t deviceAddress
    );


/**
\brief Reads a block of data from I2C bus.
\param[in] hBus        Bus handle.
\param[in] deviceAddress    Device address space (I2C).
\param[out] pData           Pointer to the data buffer.
\param[in] sizeInBytes      Size of the data buffer.
\param[out] pBytesRead      Number of bytes read.
\param[in] timeout_ms       Timeout in milliseconds.
\return The status of the operation.
\retval BCON_OK on success.
\retval BCON_E_TIMEOUT if the operation timed out.
\retval Any other BCON adapter error code otherwise.
\pre The connection with this device has been started.
\threading
This function must be thread-safe.
Only one thread accesses the I2C functions at the same time per device address.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterI2cRead(
    BconAdapterI2cBusHandle hBus,
    uint32_t deviceAddress,
    void *pData,
    size_t sizeInBytes,
    size_t *pBytesRead,
    uint32_t timeout_ms);


/**
\brief Writes a block of data on the I2C bus.
\param[in] hBus        Bus handle.
\param[in] deviceAddress    Device address space (I2C).
\param[in] pData            Pointer to the data buffer.
\param[in] sizeInBytes      Size of data buffer in bytes.
\param[in] timeout_ms       Timeout in milliseconds.
\return The status of the operation.
\retval BCON_OK on success
\retval BCON_E_TIMEOUT if the operation timed out.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
Only one thread accesses the I2C functions at the same time per device address.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterI2cWrite(
    BconAdapterI2cBusHandle hBus,
    uint32_t deviceAddress,
    const void *pData,
    size_t sizeInBytes,
    uint32_t timeout_ms);


EXTERN_C_END
