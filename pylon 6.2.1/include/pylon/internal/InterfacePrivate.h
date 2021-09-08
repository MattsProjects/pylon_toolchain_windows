//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the IInterfacePrivate interface
*/
#pragma once

#include "pylon/Interface.h"

namespace Pylon
{

    /** Private interface used by the factory for
        Interface creation
    */
    interface PUBLIC_INTERFACE IInterfacePrivate
    {
        /// Delete method used to destroy the Interface in a generic fashion, TL agnostic
        virtual void Delete() = 0;
    };
}
