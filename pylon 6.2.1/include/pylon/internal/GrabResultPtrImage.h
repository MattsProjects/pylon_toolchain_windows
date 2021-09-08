//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file   Contains an adapter adapting a grab result ptr to Pylon::IImage.
*/

#ifndef INCLUDED_GRABRESULTPTRIMAGE_H_01474726
#define INCLUDED_GRABRESULTPTRIMAGE_H_01474726

#include <pylon/Image.h>
#include <pylon/GrabResultPtr.h>

namespace Pylon
{
    // Check whether the grab result ptr is unique
    // This function is only needed for CGrabResultPtrImageT.
    //template <typename T>
    //inline bool GrabResultPtrIsUnique( const T& ptr)
    //{
    //    return ptr.IsUnique();
    //}

#if _MSC_VER
#   pragma warning( push)
#   pragma warning( disable : 4512) //warning C4512: 'Pylon::CGrabResultPtrImageT<GrabResultPtrT>' : assignment operator could not be generated
#endif

    /*!
    \brief Adapts a grab result ptr to Pylon::IImage.
    */
    template <typename GrabResultPtrT>
    class CGrabResultPtrImageT : public IImage
    {
    public:
        /// Creates a grab result ptr image object.
        CGrabResultPtrImageT( GrabResultPtrT ptrRef )
            : m_grabResultPtr( ptrRef )
        {
        }

        /// Destroys a grab result ptr image object.
        virtual ~CGrabResultPtrImageT()
        {
        }

        // Implements Pylon::IImage.
        virtual bool IsValid() const
        {
            return IsValidImpl();
        }

        // Implements Pylon::IImage.
        virtual EPixelType GetPixelType() const
        {
            return IsValidImpl() ? m_grabResultPtr->GetPixelType() : PixelType_Undefined;
        }

        // Implements Pylon::IImage.
        virtual uint32_t GetWidth() const
        {
            return IsValidImpl() ? m_grabResultPtr->GetWidth() : 0;
        }

        // Implements Pylon::IImage.
        virtual uint32_t GetHeight() const
        {
            return IsValidImpl() ? m_grabResultPtr->GetHeight() : 0;
        }

        // Implements Pylon::IImage.
        virtual size_t GetPaddingX() const
        {
            return IsValidImpl() ? m_grabResultPtr->GetPaddingX() : 0;
        }

        // Implements Pylon::IImage.
        virtual EImageOrientation GetOrientation() const
        {
            return ImageOrientation_TopDown;
        }

        // Implements Pylon::IImage.
        virtual void* GetBuffer()
        {
            return IsValidImpl() ? m_grabResultPtr->GetBuffer() : NULL;
        }

        // Implements Pylon::IImage.
        virtual const void* GetBuffer() const
        {
            return IsValidImpl() ? m_grabResultPtr->GetBuffer() : NULL;
        }

        // Implements Pylon::IImage.
        virtual size_t GetImageSize() const
        {
            return IsValidImpl() ? m_grabResultPtr->GetImageSize() : 0;
        }

        // Implements Pylon::IImage.
        virtual bool IsUnique() const
        {
            return GrabResultPtrIsUnique( m_grabResultPtr );
        }

        // Implements Pylon::IImage.
        virtual bool GetStride( size_t& strideBytes ) const
        {
            return IsValidImpl() ? m_grabResultPtr->GetStride( strideBytes ) : false;
        }

    protected:
        // Check whether the grab result ptr is valid.
        bool IsValidImpl() const
        {
            return
                m_grabResultPtr
                && m_grabResultPtr->GetPixelType() != PixelType_Undefined
                && m_grabResultPtr->GrabSucceeded()
                ;
        }

        GrabResultPtrT m_grabResultPtr; ///< The grab result ptr that is adapted to IImage.
    };

    /*!
    \brief Adapts a grab result ptr to pylon image.

    \note All grab result ptr classes provide a cast operator to IImage& that can be used instead
          of this class for passing a grab result to a function or method that takes an const IImage& as parameter.
    */
    //typedef CGrabResultPtrImageT<CGrabResultPtr> CGrabResultPtrImage;

#if _MSC_VER
#   pragma warning( pop)
#endif
}

#endif /* INCLUDED_GRABRESULTPTRIMAGE_H_01474726 */
