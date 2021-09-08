//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief BCON specific grab result data class.
*/
#ifndef INCLUDED_BCON_GRABRESULTDATA_H
#define INCLUDED_BCON_GRABRESULTDATA_H

#include <pylon/GrabResultData.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiBcon
     * @{
     */
    // This dummy implementation is used by the Device Specific Instant Camera for BCON
    // because the BCON Transport Layer does not support some features.
    class CBconDummyChunkData_Params
    {
    public:
        void _Initialize(GenApi::INodeMap*)
        {
        }
    };

    /// The BCON specific grab result data class.
    class CBaslerBconGrabResultData : public CGrabResultData, public CBconDummyChunkData_Params
    {
    protected:
        // Internal use only. The grab result data class should only be created by the Instant Camera class.
        friend class CBaslerBconInstantCamera;
        CBaslerBconGrabResultData()
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

    /**
     * @}
     */
}

#endif /* INCLUDED_BCON_GRABRESULTDATA_H */
