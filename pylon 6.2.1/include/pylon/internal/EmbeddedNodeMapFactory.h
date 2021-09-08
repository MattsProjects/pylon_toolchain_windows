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

#ifndef INCLUDED_EMBEDDEDNODEMAPFACTORY_H_7156031
#define INCLUDED_EMBEDDEDNODEMAPFACTORY_H_7156031

#include <GenICamFwd.h>
#include <pylon/PylonLinkage.h>

#ifdef PYLON_WIN_BUILD
#  pragma comment(lib, PYLON_LIB_NAME( "ResourceHelper" ))
#endif

namespace Pylon
{
    GENAPI_NAMESPACE::INodeMap* CreateNodeMapFromEmbeddedXML( const char* pszName );
}

#endif /* INCLUDED_EMBEDDEDNODEMAPFACTORY_H_7156031 */
