//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
#pragma once

#ifndef INCLUDED_NODEMAPPROVIDER_H_7328455
#define INCLUDED_NODEMAPPROVIDER_H_7328455

#include <GenICamFwd.h>

namespace Pylon
{
    class INodeMapProvider
    {
    public:
        virtual GENAPI_NAMESPACE::INodeMap* GetNodeMap() = 0;
    };
}

#endif /* INCLUDED_NODEMAPPROVIDER_H_7328455 */
