//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief Handles general XML loading and node map creation tasks for devices.
*/

#ifndef INCLUDED_DEFAULTTRANSPORTLAYERPARAMSFACTORY_H_7156031
#define INCLUDED_DEFAULTTRANSPORTLAYERPARAMSFACTORY_H_7156031

#include <GenICamFwd.h>
#include <pylon/Platform.h>
#include <pylon/PylonBase.h>

namespace Pylon
{
    PYLONBASE_API GENAPI_NAMESPACE::INodeMap* CDECL CreateDefaultTransportLayerParams();
    PYLONBASE_API void CDECL DestroyDefaultTransportLayerParams( GENAPI_NAMESPACE::INodeMap* nodeMap );
}

#endif /* INCLUDED_DEFAULTTRANSPORTLAYERPARAMSFACTORY_H_7156031 */
