//-----------------------------------------------------------------------------
//  Copyright (C) 2016 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Master header of the BXAPI library.
 * \ingroup public
 */
#pragma once

#include <malloc.h>
#include <stdarg.h>

#include "BxDll.h"
#include "BxTypes.h"
#include "BxStatus.h"
#include "BxEnumerator.h"
#include "BxDevice.h"
#include "BxStream.h"


EXTERN_C_BEGIN

/**
\brief Initialize the bxapi library.
Initializer function. Must be called before any subsequent
usage of the bxapi library. If you call any other bxapi function before this returns successfully these functions will return BX_E_NOT_INITIALIZED.
For each successful call of BxapiInit a matching BxapiExit() call must be made.
\post - The bxapi library is initialized and ready to be used. The library's usage count is increment by one.
\return Status of the operation.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BX_CALL BxapiInit();


/**
\brief Free of bxapi library.
Frees all resources used by the bxapi library. For each successful call of BxapiInit() a matching BxapiExit() call must be made.
\pre - BxapiInit has been called successfully at least once.
\post - The library's usage count is decremented by one. If the usage count drops to 0 all resources are freed. 
\return Status of the operation.
\threading
This function is thread-safe. Calling this function and the usage count drops to 0 while other threads access the API will result in undefined behavior.
*/
BX_API BXSTATUS BX_CALL BxapiExit();


/**
\brief Check if library is loadable.
Utility function, to check if dependencies, i.e. a named BCON adapter library, are present.
This function can be called prior to BxapiInit
\return Status of the operation.
*/
BX_API BXSTATUS BX_CALL BxapiCheckRuntimeDependencies();


/**
\brief Translates a status code into readable string.
Translates a status code into readable string.
This function can be called prior to BxapiInit. BxapiInit has to be called prior to calling BxapiGetStatusMessage to get status messages of the BCON adapter library.
\param[in] status Status to decode into string.
\param[in] pBuffer The buffer for the returned string. The string is zero terminated and encoded in utf8 format. This parameter can be NULL to retrieve the required buffer size. If pBuffer is NULL BufferSize must also be 0.
\param[in] BufferSize Size of the buffer pBuffer points to in number of bytes. This parameter can be 0 to retrieve the required size.
\param[in,out] pRequiredSize (optional) Returns the required size of the buffer in bytes including terminating 0.
If the buffer is not large enough to hold the full string, BX_E_INSUFFICIENT_BUFFER is returned and the required size is returned in pRequiredSize
\return Status of the operation.
\threading
This function is thread-safe.
*/
BX_API BXSTATUS BX_CALL BxapiGetStatusMessage(
    BXSTATUS status,
    char *pBuffer,
    size_t BufferSize,
    size_t *pRequiredSize);

/// Severity state of logging output
enum BxTraceLevel
{
      BxapiTraceLevel_Critical = 10        ///< Critical unrecoverable errors
    , BxapiTraceLevel_Error = 20           ///< An error occurred. The operations has not been completed.
    , BxapiTraceLevel_Warning = 30         ///< Warning message. An operation went wrong, but the program can recover/continue.
    , BxapiTraceLevel_Information = 40     ///< Informational message
    , BxapiTraceLevel_Verbose = 50         ///< Same as informational but very verbose.
    , BxapiTraceLevel_Debug = 60           ///< Very verbose message usually for debugging purposes. Like function entry exit messages
};

/// Source of logging output
enum BxTraceSource
{
      BxapiTraceSource_BxApi = 1        ///< output is from bxapi
    , BxapiTraceSource_Adapter          ///< output is from the adapter DLL
};


/**
\brief This function can be used to write trace messages to the trace output of the host application.
If the host application passes a pointer to a function, you can use it to write to the trace output of the host application.
The level parameter specifies the severity of the output. Use any of the provided BxTraceLevel to allow filtering of the output.
The source parameter specifies the source of the output (bxapi or adapter dll)
The pFormat parameter specifies the format string (see printf). Do not add line breaks to the format string.
The argList parameter points to the variable arg list
*/
typedef void (BX_CDECL *BxapiTraceFunc)(BxTraceLevel level, BxTraceSource source, const char* pFormat, va_list argList);

/**
\brief Sets the trace function to write to the host trace output
Sets the trace function to write to the host trace output.
This function can and should be called before BxapiInit().
\param[in] pTraceFunc Pointer to a function. If this pTraceFunc is not NULL it is called to write to the host application.
\return Status of the operation.
\threading
Calling this function while other threads access the API can result in undefined behavior.
*/
BX_API BXSTATUS BX_CALL BxapiSetTraceFunction(BxapiTraceFunc pTraceFunc);

EXTERN_C_END
