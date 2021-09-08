//-----------------------------------------------------------------------------
//  Basler pylon
//  Copyright (c) 2016-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  BR
//-----------------------------------------------------------------------------
/*!
\file
\internal
\brief Declaration of the IXmlFileProviderPrivate interface
*/

#ifndef INCLUDED_PYLONXMLFILEPROVIDERPRIVATE_H
#define INCLUDED_PYLONXMLFILEPROVIDERPRIVATE_H

#pragma once

#include <vector>

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/stdinclude.h>
#include <pylon/XmlFileProvider.h>

namespace Pylon
{
    class CDeviceInfo;

    /**
    \ Internal
    */
    interface IXmlFileProviderPrivate : IXmlFileProvider
    {
        virtual void ProvideXmlFileRaw( const CDeviceInfo& di, std::vector<uint8_t>& xmlData ) = 0;
    };
}


#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_PYLONXMLFILEPROVIDERPRIVATE_H */

