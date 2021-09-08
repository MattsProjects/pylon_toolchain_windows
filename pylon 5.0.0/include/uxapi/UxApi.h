//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2015 Basler
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Master header of the UX API library.
 */
#pragma once

#include <malloc.h>
#include "UxDll.h"
#include "UxTypes.h"
#include "UxStatus.h"
#include "Enumerator.h"
#include "UxDevice.h"
#include "UxStream.h"
#include "UxEventStream.h"
#include "UxNotification.h"
#include "UxUtilities.h"

/**
\brief The UXAPI namespace
*/
namespace uxapi
{

    // ----------------------------------------------------------------------
    // Init()
    // ----------------------------------------------------------------------
    /**

        \brief Initialize UX library

        Static initializer function. Must be called once before any subsequent
        usage of the UX library.

        \return Status of the operation.
     */
    UX_API UXSTATUS UX_CALL Init();

    // ----------------------------------------------------------------------
    // Exit()
    // ----------------------------------------------------------------------
    /**

        \brief Finish usage of UX library

        Static cleanup function. Must be called once before the process exits.

        \return Status of the operation.
    */
    UX_API UXSTATUS UX_CALL Exit();


    // ----------------------------------------------------------------------
    // CheckRuntimeDependencies()
    // ----------------------------------------------------------------------
    /**

        \brief Check if library is loadable

        Utility function, to check if dependencies are loadable. This is only required on linux, where libusb is loaded at runtime.
        This function can be called prior to Init()

        \return Status of the operation.
    */
    UX_API UXSTATUS UX_CALL CheckRuntimeDependencies();


    // ----------------------------------------------------------------------
    // GetStatusMessage()
    // ----------------------------------------------------------------------
    /**

    \brief Retrieve the message text of a status code

    Loads resource files and checks whether the message text is defined. May be called from multiple threads

    \param[in] StatusToDecode Status to decode into string.
    \param[in] Buffer The buffer for the returned string. This parameter can be NULL to retrieve the required buffer size.
    \param[in] BufferSize Size in number of characters. This parameter can be 0 to retrieve the required buffer size.
    \param[in,out] RequiredSize (optional) Required size of the Buffer including terminating 0.

    If the buffer is not large enough to hold the full string, the beginning of the string terminated by 0 is returned.

    \return Status of the retrieval.
    */
    UX_API UXSTATUS UX_CALL GetStatusMessage(
        UXSTATUS StatusToDecode,
        char *Buffer,
        size_t BufferSize,
        size_t *RequiredSize );

    // --------------------------------------------------------------------------
    // GetStatusMessage( UXSTATUS )
    // --------------------------------------------------------------------------
    /**

    \brief Retrieve the message text of a status code

    Loads resource files and checks whether the message text is defined. May be called from multiple threads

    \param[in]  StatusToDecode Status to decode into string
    \param[in]  StatusDecoded String representation of status

    \return Status of the retrieval.
    */
    template<class StringT>
    inline UXSTATUS GetStatusMessageString(
        UXSTATUS StatusToDecode,
        StringT& StatusDecoded)
    {
        // Get size of message
        size_t bufferSize(0);
        UXSTATUS status = uxapi::GetStatusMessage(StatusToDecode, NULL, 0, &bufferSize);
        if (!UX_SUCCESS( status ))
            return status;

        // Allocate buffer for message
        //TODO error handling for linux & windows (windows used _malloca)
        char* buffer = static_cast<char*>(malloc( bufferSize));

        // Get status message
        status = uxapi::GetStatusMessage(StatusToDecode, buffer, bufferSize, NULL);
        StatusDecoded = buffer;

        // Free the buffer
        free( buffer);
        return status;
    }
}
