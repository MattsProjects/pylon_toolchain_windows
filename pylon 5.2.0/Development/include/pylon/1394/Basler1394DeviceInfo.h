//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2019 Basler AG
//  http://www.baslerweb.com
//  Author:  Hartmut Nebelung, AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of CBasler1394CameraInfo
*/


#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#ifndef __BASLER1394DEVICEINFO_H__
#define __BASLER1394DEVICEINFO_H__

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/PylonBase.h>
#include <pylon/DeviceInfo.h>

namespace Pylon
{
    /*!
    \brief FireWire specific Device Info object. Does not support SerialNumber property.
    \ingroup Pylon_TransportLayer
    */
    class PYLONBASE_API CBasler1394DeviceInfo : public CDeviceInfo
    {
    public:
        CBasler1394DeviceInfo();
        CBasler1394DeviceInfo(const CDeviceInfo&);
        virtual ~CBasler1394DeviceInfo();
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // __BASLER1394DEVICEINFO_H__
