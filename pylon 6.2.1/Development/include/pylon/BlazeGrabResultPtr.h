//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief grab result ptr class.
*/

#ifndef INCLUDED_BLAZEFILE_H_19854797
#define INCLUDED_BLAZEFILE_H_19854797

#pragma once

#include "BlazeGrabResultData.h"
#include <pylon/private/DeviceSpecificGrabResultPtr.h>

namespace Pylon
{
    /// The grab result smart pointer.
    PYLON_DEFINE_DEVICE_SPECIFIC_GRAB_RESULT_PTR( BlazeGrabResultPtr, BlazeGrabResultData)

} // namespace Pylon

#endif /* INCLUDED_BLAZEFILE_H_19854797 */