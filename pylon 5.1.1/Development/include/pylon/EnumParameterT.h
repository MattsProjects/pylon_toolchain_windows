//------------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2018 Basler AG
//  http://www.baslerweb.com
//------------------------------------------------------------------------------
/*!
\file
\brief Contains a template class for the use with C++ enum extended enum parameters used in generated APIs.
*/

#ifndef INCLUDED_BASLER_PYLON_CENUMPARAMETERT_H
#define INCLUDED_BASLER_PYLON_CENUMPARAMETERT_H

#pragma once

#include <pylon/EnumParameter.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4275 ) // Class needs to have a dll interface to be used by clients of the class.
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

namespace Pylon
{
    /*!
    \brief A template class for the use with C++ enum extended enum parameters used in generated APIs.
    */
    template<typename EnumT>
    interface IEnumParameterT : virtual public IEnumerationEx
    {
    public:
        using IEnumerationEx::SetValue;
        using IEnumerationEx::TrySetValue;
        using IEnumerationEx::GetValueOrDefault;
        using IEnumerationEx::CanSetValue;
        

        /*!
        \brief Sets the value passed.
        \param[in] value The value to set.
        \param[in] verify Enables AccessMode and Range verification (default = true)
        \error
             Can throw exceptions if the parameter is not writable or writing the value fails.
        */
        virtual void SetValue(EnumT value, bool verify = true) = 0;


        /*!
        \brief Sets the value passed.
        \param[in] value The value to set.
        \error
             Can throw exceptions if the parameter is not readable or if reading the value fails.
        */
        virtual IEnumParameterT<EnumT>& operator=(EnumT value) = 0;


        /*!
        \brief Gets the current parameter value.
        \param verify Enables Range verification (default = false). The AccessMode is always checked
        \param ignoreCache If true the value is read ignoring any caches (default = false)
        \return Returns the current parameter value.
        \error
             Can throw exceptions if the parameter is not readable or if reading the value fails.
        */
        virtual EnumT GetValue(bool verify = false, bool ignoreCache = false) = 0;


        /*!
        \brief Gets the current parameter value.
        \return Returns the current parameter value.
        \error
             Can throw exceptions if the parameter is not readable or if reading the value fails.
        */
        virtual EnumT operator()() = 0;


        /*!
        \brief Sets the value passed.
        \param[in] value The value to set.
        \error
             Can throw exceptions if the parameter is not writable or writing the value fails.
        */
        virtual IEnumParameterT<EnumT>& operator=(const GENICAM_NAMESPACE::gcstring& value) = 0;

        //! returns the EnumEntry object belonging to the Value
        virtual GENAPI_NAMESPACE::IEnumEntry* GetEntry(const EnumT value) = 0;


        /*!
        \brief Gets the parameter value if the parameter is readable. Otherwise, returns the default value.
        \return Returns the parameter value if the parameter is readable. Otherwise, returns the default value.
        \param[in] defaultValue   The default value returned if the parameter is not readable.
        \threading
        Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
        Can throw exceptions if reading the value fails.
        */
        virtual EnumT GetValueOrDefault(EnumT defaultValue) = 0;


        /*!
        \brief Sets the value passed if the parameter is writable and the value is contained in the set of settable enumeration values.
        \return Returns false if the parameter is not writable or the value is not contained in the set of settable enumeration values.
        \param[in] value   The value to set.
        \pre The value must be contained in the set of settable enumeration values.
        \threading
        Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
        Can throw exceptions if the preconditions are not met or if writing the value fails.
        */
        virtual bool TrySetValue(EnumT value) = 0;


        /*!
        \brief Indicates if the value passed can be set.
        \return Returns true if the value can be set, otherwise false.
        \param[in] value   The value to be checked.
        \threading
        Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
        Does not throw exceptions.
        */
        virtual bool CanSetValue(EnumT value) = 0;
    };
    
    
    
    //A template class for the use with C++ enum extended enum parameters used in generated APIs.
    template<typename EnumT>
    class CEnumParameterT : public CEnumParameter, virtual public IEnumParameterT<EnumT>
    {
    public:
        CEnumParameterT()
        {
        }
        
        CEnumParameterT(GENAPI_NAMESPACE::INode* pNode)
            : CEnumParameter(pNode)
        {
        }
        
    
        using CEnumParameter::SetValue;

        // Implements IEnumParameterT<EnumT>
        virtual void SetValue(EnumT value, bool verify = true)
        {
            SetValue(GetTable(), static_cast<size_t>(value), verify);
        }
        

        // Implements IEnumParameterT<EnumT>
        virtual CEnumParameterT<EnumT>& operator=(EnumT value)
        {
            SetValue(value);
            return *this;
        }
        

        // Implements IEnumParameterT<EnumT>
        virtual EnumT GetValue(bool verify = false, bool ignoreCache = false)
        {
            EnumT result = static_cast<EnumT>(CEnumParameter::GetValue(GetTable(), verify, ignoreCache));
            return result;
        }
        

        // Implements IEnumParameterT<EnumT>
        virtual EnumT operator()()
        {
            EnumT result = GetValue();
            return result;
        }


        // Implements IEnumParameterT<EnumT>
        virtual CEnumParameterT<EnumT>& operator=(const GENICAM_NAMESPACE::gcstring& value)
        {
            FromString(value);
            return *this;
        }
        

        // Implements IEnumParameterT<EnumT>
        virtual GENAPI_NAMESPACE::IEnumEntry* GetEntry(const EnumT value)
        {
            GENAPI_NAMESPACE::IEnumEntry* result = CEnumParameter::GetEntry(GetTable(), static_cast<size_t>(value));
            return result;
        }

        // Implements IEnumParameterT<EnumT>
        virtual EnumT GetValueOrDefault(EnumT defaultValue)
        {
            if (this->IsReadable())
            {
                EnumT result = GetValue();
                return result;
            }
            return defaultValue;
        }

        // Implements IEnumParameterT<EnumT>
        virtual bool TrySetValue(EnumT value)
        {
            if (this->IsWritable() && CEnumParameter::CanSetValue(GetTable(), static_cast<size_t>(value)))
            {
                SetValue(value);
                return true;
            }
            return false;
        }


        // Implements IEnumParameterT<EnumT>
        virtual bool CanSetValue(EnumT value)
        {
            bool result = CEnumParameter::CanSetValue(GetTable(), static_cast<size_t>(value));
            return result;
        }


        protected:
        //must be provides by specific enum instance
        virtual const Table_t& GetTable() const = 0;
    };
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_BASLER_PYLON_CENUMPARAMETERT_H */