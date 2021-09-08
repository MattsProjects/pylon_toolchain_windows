//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2008-2013 Basler
//  http://www.baslerweb.com
//  Author:  TK
//-----------------------------------------------------------------------------
#ifndef __PYLON_SYNCH_H__
#define __PYLON_SYNCH_H__

#if _MSC_VER > 1000
#   pragma once
#endif

#pragma message( "WARNING: The pylon Synch.h header file has been deprecated and will be removed in future versions of pylon. Use 'genapi/Synch.h' instead.")

#include <pylon/Platform.h>
#include <genapi/Synch.h>

namespace Pylon
{
    // \cond
    
    typedef PYLON_DEPRECATED("Pylon::CLock has been deprecated. Use GenApi::CLock instead. The Pylon::CLock type will be removed in future versions of pylon.") GenApi::CLock CLock;

    typedef PYLON_DEPRECATED("Pylon::AutoLock has been deprecated. Use GenApi::AutoLock instead. The Pylon::AutoLock type will be removed in future versions of pylon.") GenApi::AutoLock AutoLock;

    template< class Object>
    class PYLON_DEPRECATED("Pylon::LockableObject has been deprecated. Use GenApi::LockableObject instead. The Pylon::LockableObject class will be removed in future versions of pylon.") 
        LockableObject : public GenApi::LockableObject<Object> 
    {
    };
    
    // \endcond
}

#endif // __PYLON_SYNCH_H__
