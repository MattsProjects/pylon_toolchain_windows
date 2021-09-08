//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
*/

#ifndef __INFOPRIVATE_H__
#define __INFOPRIVATE_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/PylonBase.h>
#include <pylon/Info.h>
#include <map>

namespace Pylon
{
    interface PUBLIC_INTERFACE IPropertyValueComparer
    {
        ///Compares two property values applying background knowledge on how to compare the values
        virtual bool PropertyValuesAreEqual( const String_t& key, const String_t& valueA, const String_t& valueB ) const = 0;
    };

#ifdef _MSC_VER
#   pragma warning( push )
#   pragma warning( disable: 4251 ) //  class xyz needs to have dll interface
#endif //_MSC_VER
    class PYLONBASE_API CPropertyBag : public IProperties
    {
    public:
        CPropertyBag();
        CPropertyBag( const CPropertyBag& );
        virtual ~CPropertyBag();

        int GetPropertyNames( StringList_t& ) const;
        bool GetPropertyAvailable( const String_t& Name ) const;
        bool GetPropertyValue( const String_t& Name, String_t& Value ) const;
        IProperties& SetPropertyValue( const String_t& Name, const String_t& Value );
        bool IsSubset( const IProperties& Subset ) const;
        bool IsSubset( const IProperties& Subset, const IPropertyValueComparer* comparer ) const;

        CPropertyBag& operator=( const CPropertyBag& );

        bool IsModified() const;
        bool IsExtended() const;
        void ClearAccessFlags();

        int GetCount() const;

    public:
        uint8_t m_contextData[64];

    protected:
        bool IsHiddenProperty( const Pylon::String_t& strKeyname ) const;

    protected:
        typedef std::map< String_t, String_t> PropertyMap_t;

        PropertyMap_t   m_Properties;
        bool            m_isModified;
        bool            m_isExtended;
    };
#ifdef _MSC_VER
#   pragma warning(pop)
#endif //_MSC_VER

    /*!
    \brief Holds a property map and exposes setter and getter methods

    Serves as base class for device info implementations
    */
    class PYLONBASE_API CInfoImpl : public CPropertyBag
    {
    public:
        CInfoImpl();

        bool IsUserProvided() const;
        void ClearUserProvidedFlag();

        bool operator==( const CInfoImpl& rhs );

    protected:
        bool            m_IsUserProvided;
    };


    template <class T>
    class CInfoPrivateT : public T
    {
    public:
        bool IsUserProvided() const
        {
            return T::m_pImpl->IsUserProvided();
        }
        bool IsModified() const
        {
            return T::m_pImpl->IsModified();
        }
        bool IsExtended() const
        {
            return T::m_pImpl->IsExtended();
        }
        void ClearUserProvidedFlag()
        {
            T::m_pImpl->ClearUserProvidedFlag();
        }
        void ClearAccessFlags()
        {
            T::m_pImpl->ClearAccessFlags();
        }
    };



}

#endif
