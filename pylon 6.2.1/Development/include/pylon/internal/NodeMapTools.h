//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  Urs Helmig
//-----------------------------------------------------------------------------
/*!
\file
\brief    Declaration of GenICam NodeMap functions
*/
#ifndef __NODEMAPTOOLS_H__
#define __NODEMAPTOOLS_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../PylonBase.h"
#include "../ThreadPriority.h"


namespace Pylon
{

    void PYLONBASE_API SetGenICamNodeValuesFromKeyValueStr( GENAPI_NAMESPACE::INodeMap* pNodeMap, const char* keyValueStr );
    void PYLONBASE_API SetupRTThreadPriorityCapabilities( GENAPI_NAMESPACE::INodeMap* pNodeMap, Pylon::String_t nodeNameBase );
    void PYLONBASE_API SetNodemapRTThreadPriority( GENAPI_NAMESPACE::INodeMap* pNodeMap, Pylon::String_t nodeNameBase, THREADHANDLE thread );

} // namespace Pylon

#endif // __NODEMAPTOOLS_H__
