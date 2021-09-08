//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2015 Basler AG
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
    /**
    \brief Reads the value from an address.
    \param pSource The source of type SourceT.
    \param address The address to read from.
    \param v The Value to read.
    */
    template <typename SourceT, typename ValueT>
    inline UXSTATUS ReadMem( SourceT* pSource, uint64_t address, ValueT& v)
    {
        if ( !pSource )
        {
            return UX_E_INVALID_PARAMETER;
        }

        size_t len = sizeof(ValueT);
        UXSTATUS result = pSource->ReadMem( &v, address, &len);
        if ( UX_SUCCESS(result) && len != sizeof(ValueT))
        {
            return UX_E_READ_FAILED;
        }
        return result;
    }

    /**
    \brief Reads the value from an address.
    \param pSource The source of type SourceT.
    \param address The address to write to.
    \param v The Value to write.
    */
    template <typename SourceT, typename ValueT>
    inline UXSTATUS WriteMem( SourceT* pSource, uint64_t address, ValueT v)
    {
        if ( !pSource )
        {
            return UX_E_INVALID_PARAMETER;
        }

        UXSTATUS result = pSource->WriteMem( &v, address, sizeof(ValueT));
        return result;
    }

    /// Collects results.
    class CResultCollector
    {
    public:

        /// Constructor
        CResultCollector()
            : firstError( UX_OK)
            , lastResult( UX_OK)
        {

        }

        /**
        \brief Assigns a result
        \param result The result to assign.
        \return Returns this.
        */
        CResultCollector& operator=( UXSTATUS result)
        {
            if ( UX_ERROR( result))
            {
                if ( firstError == UX_OK)
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

    UX_API bool IsBufferedTransferDevice(const char* ManufacturerInfo);
    UX_API bool IsBufferedTransferDevice(const wchar_t* ManufacturerInfo);
}
