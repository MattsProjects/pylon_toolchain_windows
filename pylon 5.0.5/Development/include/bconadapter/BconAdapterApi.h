//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
* \file
* \brief Definition of the BCON adapter interface.
* \ingroup public
*/
#pragma once

#include <stddef.h>
#include "BconAdapterDefines.h"
#include "BconAdapterTypes.h"


EXTERN_C_BEGIN


/** \brief Current major version of the BCON adapter API. A change to the major version number indicates a breaking change. The BCON adapter will not be loaded if the version is different from the supported version.*/
#define BCON_ADAPTER_API_MAJORVERSION     1u

/** \brief  Current minor version of the BCON adapter API. If only the minor version number differs, the API differences will be handled correctly by the caller. */
#define BCON_ADAPTER_API_MINORVERSION     0u


/**
\brief Initializes/opens the BCON adapter layer.
This function is called when the library is loaded.
Re-initialization is possible after calling BconAdapterExit().
\param[in] pTraceFunc Optional. Pointer to a function. If this parameter is not NULL, you can call this to write to the host application.
\return Initialization status.
\retval BCON_OK on success.
\retval Any other BCON adapter error code otherwise.
\post Library is ready to use.
\threading
This function is only called once before BconAdapterExit() is called.
This function does not need to be thread-safe.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterInit(BconTraceFunc pTraceFunc);


/**
\brief Closes the BCON adapter layer.
This function is called before the library is unloaded. It should free all resources.
\return Status of the library. 
\retval BCON_OK if resources were freed.
\retval Any other BCON adapter error code otherwise.
\pre Library was successfully initialized.
\post Library resources are freed and can be unloaded.
\threading
This function does not need to be thread-safe.
All created objects are destroyed before BconAdapterExit() is called.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterExit(void);


/**
\brief Returns the version of the library.
This function is called to check the API version implemented by the library.
Two different sets of major/minor version numbers are returned:
<ul>
<li> Version of the BCON adapter API implemented by the library.
<li> Version of the adapter library. Only used for display.
</ul>
\param[out] apiMajorVersion     Major version of the BCON adapter API (\ref BCON_ADAPTER_API_MAJORVERSION ).
\param[out] apiMinorVersion     Minor version of the BCON adapter API (\ref BCON_ADAPTER_API_MINORVERSION ).
\param[out] adapterMajorVersion Major version of the adapter library.
\param[out] adapterMinorVersion Minor version of the adapter library.
\return Status of the retrieval.
\retval BCON_OK on success.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
\note This function must be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGetVersion(
    unsigned int *apiMajorVersion,
    unsigned int *apiMinorVersion,
    unsigned int *adapterMajorVersion,
    unsigned int *adapterMinorVersion);


/**
\brief Retrieves the message text of a status code.
This function is called to decode a user-defined status code into a readable string.
\param[in] statusToDecode       Status to decode into string.
\param[in] pBuffer              Optional. The buffer for the returned string. This parameter can be NULL to retrieve the required buffer size.
\param[in] bufferSize           Size in number of characters. This parameter can be 0 to retrieve the required buffer size.
\param[in,out] pRequiredSize    Optional. Required size of the buffer including terminating 0.
If the buffer is not large enough to hold the full string and is at least of one byte size, an empty string is returned.
\return Status of the retrieval.
\retval BCON_OK on success.
\retval BCON_E_INSUFFICIENT_BUFFER if the buffer provided is too small.
\retval BCON_E_NOT_FOUND if the status code was not found.
\retval Any other BCON adapter error code otherwise.
\threading
This function must be thread-safe.
\note This function can be implemented.
*/
BCON_ADAPTER_API BCONSTATUS BCON_ADAPTER_CALL BconAdapterGetStatusMessage(
    BCONSTATUS statusToDecode,
    char *pBuffer,
    size_t bufferSize,
    size_t *pRequiredSize);


EXTERN_C_END
