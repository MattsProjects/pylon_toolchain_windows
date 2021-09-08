//-----------------------------------------------------------------------------
//  Copyright (c) 2012-2021 Basler AG
//-----------------------------------------------------------------------------
/**
 * \file
 * \brief Helper functions for using the API.
 */
#pragma once

#include "UxDll.h"
#include <stdint.h>

namespace uxapi
{
    /// Collects results.
    class CResultCollector
    {
    public:

        /// Constructor
        CResultCollector()
            : firstError( UX_OK )
            , lastResult( UX_OK )
        {

        }

        /**
        \brief Assigns a result
        \param result The result to assign.
        \return Returns this.
        */
        CResultCollector& operator=( UXSTATUS result )
        {
            if (UX_ERROR( result ))
            {
                if (firstError == UX_OK)
                {
                    firstError = result;
                }
            }
            lastResult = result;

            return *this;
        }

        /**
        \brief Cast operator.
        \returns Returns the last result.
        */
        operator UXSTATUS()
        {
            return lastResult;
        }

        UXSTATUS firstError;    ///< The first error.
        UXSTATUS lastResult;    ///< The last result.
    };

    UX_API bool IsBufferedTransferDevice( const char* ManufacturerInfo );
    UX_API bool IsBufferedTransferDevice( const wchar_t* ManufacturerInfo );
}
