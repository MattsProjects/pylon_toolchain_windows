//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Contains the BCON specific grab result ptr class.
*/

#ifndef INCLUDED_BCON_GRABRESULTPTR_H
#define INCLUDED_BCON_GRABRESULTPTR_H

#include <pylon/bcon/BaslerBconGrabResultData.h>
#include <pylon/private/DeviceSpecificGrabResultPtr.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiBcon
     * @{
     */

    /// The BCON specific grab result smart pointer.
    PYLON_DEFINE_DEVICE_SPECIFIC_GRAB_RESULT_PTR( CBaslerBconGrabResultPtr, CBaslerBconGrabResultData )

     /**
     * @}
     */
}

#endif /* INCLUDED_BCON_GRABRESULTPTR_H */
