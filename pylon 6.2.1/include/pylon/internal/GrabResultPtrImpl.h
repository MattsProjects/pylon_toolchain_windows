//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief todo
*/

#ifndef INCLUDED_GRABRESULTPTRIMPL_H_1586965
#define INCLUDED_GRABRESULTPTRIMPL_H_1586965

#include <boost/shared_ptr.hpp>
#include <pylon/GrabResultPtr.h>
#include <pylon/internal/GrabResultDataImpl.h>
#include <pylon/internal/GrabResultPtrImage.h>

namespace Pylon
{
    // Check whether the boost::shared_ptr<CGrabResultData> is unique
    // This function is only needed for CGrabResultPtrImageT.
    inline bool GrabResultPtrIsUnique( const boost::shared_ptr<CGrabResultData>& ptr )
    {
        return ptr && ptr.unique() && ptr->GetGrabResultDataImpl()->bufferData.unique();
    }

    //pointer impl for hiding boost shared_ptr
    class CGrabResultPtr::CGrabResultPtrImpl
    {
    public:
        CGrabResultPtrImpl()
            : image( ptr )
        {
        }

        CGrabResultPtrImpl( boost::shared_ptr<CGrabResultData> data )
            : ptr( data )
            , image( ptr )
        {
        }
        ~CGrabResultPtrImpl()
        {
        }
        //commented coverage shows method is not used
        //CGrabResultPtrImpl(const CGrabResultPtrImpl& rhs)
        //    : ptr( rhs.ptr)
        //    , image( ptr)
        //{
        //}

        CGrabResultPtrImpl& operator=( const CGrabResultPtrImpl& rhs )
        {
            ptr = rhs.ptr;
            return *this;
        }

        boost::shared_ptr<CGrabResultData> ptr;
        CGrabResultPtrImageT<const boost::shared_ptr<CGrabResultData>&> image; ///< The view on the grab result as image.
                                                                         ///< Is placed here so that wrong usage is noticed faster.
    };

}

#endif /* INCLUDED_GRABRESULTPTRIMPL_H_1586965 */
