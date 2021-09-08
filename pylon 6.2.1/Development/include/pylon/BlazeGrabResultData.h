//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result data class.
*/

#ifndef INCLUDED_BLAZEFILE_H_90437477
#define INCLUDED_BLAZEFILE_H_90437477

#pragma once

#include "BlazeChunkDataParams.h"
#include <pylon/GrabResultData.h>

namespace Pylon
{
    /// The grab result data.
    class BlazeGrabResultData : public CGrabResultData, public BlazeChunkDataParams_Params::BlazeChunkDataParams
    {
    protected:
        // Internal use only. The grab result data class should only be created by the instant camera class.
        friend class CBlazeInstantCamera;
        BlazeGrabResultData()
        {
        }

        // Internal use only.
        virtual void Destroy()
        {
            delete this;
        }

        // Internal use only.
        virtual void Initialize()
        {
            _Initialize( &GetChunkDataNodeMap());
        }
    };

} // namespace Pylon

#endif /* INCLUDED_BLAZEFILE_H_90437477 */