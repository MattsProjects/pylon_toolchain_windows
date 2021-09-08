//-----------------------------------------------------------------------------
//  Copyright (c) 2012-2021 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Master header of the UX API library.
 */
#pragma once

#include <stdlib.h>
#if defined(_MSC_VER)
#   include <malloc.h>
#endif

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
    // List of all available properties
    enum EPropertyValue
    {
        EPropertyValue_License = 0x2EA1,
        EPropertyValue_PleoraLicense = 0x2EA2,
        EPropertyValue_EnumInfo = 0xE4F1
    };


    // ----------------------------------------------------------------------
    // GetVersion()
    // ----------------------------------------------------------------------
    /**

        \brief Returns UX library version

        Static function. Can be called at any time, no Init() required.
        Can be used to check compatibility between projects.

        Returns the version in Major.Minor format.

        \return Status of the operation.
    */
    UX_API UXSTATUS UX_CALL GetVersion( uint32_t* pMajor, uint32_t* pMinor );


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
    // SetProperty()
    // ----------------------------------------------------------------------
    /**

        \brief Set the value of a property.

        \param propertyId Identifies the property.
        \param pData A pointer to the buffer containing the data.
        \param size Size of the buffer in bytes.

        \return Status of the operation.
    */
    UX_API UXSTATUS UX_CALL SetProperty( int propertyId, const void* pData, size_t size );


    // ----------------------------------------------------------------------
    // GetProperty()
    // ----------------------------------------------------------------------
    /**

        \brief Retrieve the value of a property.

        \param propertyId Identifies the property
        \param pData Pointer to the buffer for the data.
        \param pSize Size of the buffer in bytes when calling. Holds the resulting size on return.

        \return Status of the operation.
    */
    UX_API UXSTATUS UX_CALL GetProperty( int propertyId, void* pData, size_t* pSize );


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
        char* Buffer,
        size_t BufferSize,
        size_t* RequiredSize );

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
        StringT& StatusDecoded )
    {
        // Get size of message
        size_t bufferSize( 0 );
        UXSTATUS status = uxapi::GetStatusMessage( StatusToDecode, NULL, 0, &bufferSize );
        if (!UX_SUCCESS( status ))
            return status;

        // Allocate buffer for message
        //TODO error handling for linux & windows (windows used _malloca)
        char* buffer = static_cast<char*>(malloc( bufferSize ));

        // Get status message
        status = uxapi::GetStatusMessage( StatusToDecode, buffer, bufferSize, NULL );
        StatusDecoded = buffer;

        // Free the buffer
        free( buffer );
        return status;
    }
}
