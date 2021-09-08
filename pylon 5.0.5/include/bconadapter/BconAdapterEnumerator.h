//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Defines the enumeration interface of the BCON adapter.
* \ingroup public
*/
#pragma once

#include "BconAdapterDefines.h"
#include "BconAdapterTypes.h"

EXTERN_C_BEGIN


//-----------------------------------------------------------------------------
// Types

/**
\brief Discovery callback function.
Call this function for each device present. The callee opens the connection 
to the camera device to retrieve further information if needed.
\param[in] deviceId    A string that identifies the device just found.
                        The string is UTF-8 encoded, zero-terminated, contains 
                        less than 255 characters, and only printable characters.
\param[in] userContext  User context handed to the call of BconAdapterStartDiscovery().
\return Status of processing the passed device ID.
*/
typedef BCONSTATUS (BCON_ADAPTER_CALL *PFUNC_BCON_ADAPTER_DISCOVERY_CALLBACK)(const char deviceId[], uintptr_t userContext);


//-----------------------------------------------------------------------------
// Functions
/**
\brief Discovers camera devices.
This function should implement a complete device enumeration 
or provide static information, e.g. read from a config file.
\param[in] pCallback     Pointer to the callback interface.
\param[in] userContext   User defined type returned in callback.
\return Status of device discovery.
\retval BCON_OK on success.
\retval BCON_E_NOT_FOUND if no information is available.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterStartDiscovery(
    PFUNC_BCON_ADAPTER_DISCOVERY_CALLBACK pCallback,
    uintptr_t userContext);


EXTERN_C_END

