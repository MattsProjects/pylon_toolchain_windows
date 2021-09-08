#ifndef __PYLONDLL_H__
#define __PYLONDLL_H__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/DeviceInfo.h>
#include <pylon/Container.h>
#include <pylon/TlInfo.h>

namespace Pylon
{
    interface ITransportLayer;

    typedef ITransportLayer* (*TLCREATEFUNC)(const CTlInfo&);
    typedef void (*TLDESTROYFUNC)(const ITransportLayer*);
    typedef size_t( *TLINFOLISTFUNC )(TlInfoList_t&, bool /*true = append to list, false = clear and set list*/);

}
#endif //__PYLONDLL_H__
