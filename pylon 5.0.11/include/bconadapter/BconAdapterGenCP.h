// -------------------------------------------------------------------------- -
//  Copyright (C) 2016-2017 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Defines the GenCP interface of the BCON adapter (INTERNAL USE ONLY)
* \attention Internal use only. Subject to change without notice.
* \ingroup public
*/
///////////////////////////////////////////////////////////////////////////////
//                                  WARNING                                  //
//          Internal use only. Subject to change without notice.             //
///////////////////////////////////////////////////////////////////////////////

// ----------------------------------------------------------------------------
#pragma once

#include "BconAdapterDefines.h"
#include "BconAdapterTypes.h"


EXTERN_C_BEGIN


//-----------------------------------------------------------------------------
// Types

// Opaque pointer BconAdapterGencpHandle
struct _BconAdapterGenCpHandle_tag;
/**
\typedef BconAdapterGencpHandle
\brief Handle representing a GenCP connection
A handle value of null is considered invalid.
*/
typedef struct _BconAdapterGenCpHandle_tag* BconAdapterGencpHandle;

//-----------------------------------------------------------------------------
// Functions


/**
\brief Opens the GenCP connection to a camera device.
\param[in]  deviceId        Device identifier received during enumeration.
\param[out] phGenCp         Device handle created. Memory needs to be allocated.
\return The status of the operation.
\threading
This function must be thread-safe. It is assumed that a known fixed amount of cameras is attached
to a BCON system, so that required data structures can be allocated when BconAdapterInit() is called.
Therefore, thread-safety can be assured without using additional locking.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGencpOpen(
    const char deviceId[],
    BconAdapterGencpHandle *phGenCp);


/**
\brief Closes the GenCP connection to a camera device. All memory and resources allocated during BconAdapterGencpOpen() should be freed.
\param[in] hGenCp   Device handle.
\return The status of the operation.
\threading
This function must be thread-safe.
Only one thread accesses the GenCP functions at the same time per BconAdapterGencpHandle handle.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGencpClose(
    BconAdapterGencpHandle hGenCp);


/**
\brief Reads from the GenCP connection.
\param[in] hGenCp           Device handle.
\param[out] pData           Pointer to the buffer to fill.
\param[in]  sizeInBytes     Buffer size in bytes.
\param[out] pBytesRead      Number of bytes read.
\param[in] timeout_ms      Timeout in milliseconds.
\return The status of the operation.
\threading
This function must be thread-safe.
Only one thread accesses the GenCP functions at the same time per BconAdapterGencpHandle handle.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGencpRead(
    BconAdapterGencpHandle hGenCp,
    void *pData,
    size_t sizeInBytes,
    size_t *pBytesRead,
    uint32_t timeout_ms);


/**
\brief Writes to the GenCP connection.
\param[in] hGenCp           Device handle.
\param[out] pData           Pointer to the data buffer.
\param[out] sizeInBytes     Buffer size in bytes.
\param[in] timeout_ms       Timeout value in milliseconds.
\return The status of the operation.
\threading
This function must be thread-safe.
Only one thread accesses the GenCP functions at the same time per BconAdapterGencpHandle handle.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGencpWrite(
    BconAdapterGencpHandle hGenCp,
    const void *pData,
    size_t sizeInBytes,
    uint32_t timeout_ms);


/**
\brief Tries to recover the GenCP connection. This function is called after an error or timeout was detected.
\param[in] handle   Device handle.
\return The status of the operation.
\threading
This function must be thread-safe.
Only one thread accesses the GenCP functions at the same time per BconAdapterGencpHandle handle.
\attention Internal use only. Subject to change without notice.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGencpRecover(
    BconAdapterGencpHandle handle);


EXTERN_C_END
