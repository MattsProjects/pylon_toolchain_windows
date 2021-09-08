//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2011-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the CBaslerBconDeviceInfo class
*/

#ifndef INCLUDED_BCON_DEVICEINFO_H
#define INCLUDED_BCON_DEVICEINFO_H

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/PylonBase.h>
#include <pylon/DeviceInfo.h>


namespace Pylon
{
    /*!
    \ingroup Pylon_TransportLayer
    \class CBaslerBconDeviceInfo
    \brief PylonBcon specific Device Info object.
    */
    class PYLONBASE_API CBaslerBconDeviceInfo : public Pylon::CDeviceInfo
    {
    public:
        CBaslerBconDeviceInfo();
        CBaslerBconDeviceInfo( const CDeviceInfo& di );
        virtual ~CBaslerBconDeviceInfo();
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_BCON_DEVICEINFO_H */
