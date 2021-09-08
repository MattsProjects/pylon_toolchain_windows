//------------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2018 Basler AG
//  http://www.baslerweb.com
//------------------------------------------------------------------------------
/*!
\file
\brief Contains the class CEnumParameter used for simplifying access to %GenApi parameters.
*/

#ifndef INCLUDED_BASLER_PYLON_CENUMPARAMETER_H
#define INCLUDED_BASLER_PYLON_CENUMPARAMETER_H

#pragma once

#include <pylon/PylonBase.h>
#include <GenApi/IEnumeration.h>
#include <pylon/Parameter.h>

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
    \brief Extends the GenApi::IEnumeration interface with convenience methods.
    */
    interface IEnumerationEx : virtual public GENAPI_NAMESPACE::IEnumeration, virtual public IValueEx
    {
        using GENAPI_NAMESPACE::IEnumeration::operator=;
    
        /*!
        \brief Gets the parameter value if the parameter is readable. Otherwise, returns the default value.
        \return Returns the parameter value if the parameter is readable. Otherwise, returns the default value.
        \param[in] defaultValue   The default value returned if the parameter is not readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if reading the value fails.
        */
        virtual String_t GetValueOrDefault(const String_t& defaultValue) = 0;


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
        virtual bool TrySetValue(const String_t& value) = 0;


        /*!
        \brief Sets the first valid value from a list of values.
        Example:
        \code
        CEnumParameter pixelFormat(nodemap, "PixelFormat");
        const char* list[] = { "BayerGR8", "BayerRG8", "BayerGB8", "BayerBG8", "Mono8", NULL };
        pixelFormat.SetValue(list);
        \endcode
        \param[in] nullTerminatedList   The list of possible values to set. The list is terminated by a NULL value.
        \pre
        <ul>
        <li>The parameter must be writable.
        <li>At least one value contained in the list passed must be contained in the set of settable enumeration values.
        </ul>
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if the parameter is not writable, no value is valid, or writing the value fails.
        */
        virtual void SetValue(const char** nullTerminatedList) = 0;


        /*!
        \brief Sets the first valid value from a list of values if the parameter is writable.
        Example:
        \code
        CEnumParameter pixelFormat(nodemap, "PixelFormat");
        const char* list[] = { "BayerGR8", "BayerRG8", "BayerGB8", "BayerBG8", "Mono8", NULL };
        pixelFormat.TrySetValue(list);
        \endcode
        \param[in] nullTerminatedList   The list of possible values to set. The list is terminated by a NULL value.
        \return Returns false if the parameter is not writable.
        \pre At least one value contained in the passed list must be contained in the set of settable enumeration values.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if the parameter is not writable, no value is valid, or writing the value fails.
        */
        virtual bool TrySetValue(const char** nullTerminatedList) = 0;


        /*!
        \brief Indicates if the value passed can be set.
        \return Returns true if the value can be set, otherwise false.
        \param[in] value   The value to be checked.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Does not throw exceptions.
        */
        virtual bool CanSetValue(const String_t& value) = 0;

        
        /*!
        \brief Sets the value passed
        Calls FromString().
        \param[in] value   The value to set.
        \pre The value must be contained in the set of settable enumeration values.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if the parameter is not writable, no value is valid, or writing the value fails.
        */
        virtual void SetValue(const String_t& value) = 0;
        
        
        /*!
        \brief Gets the current parameter value.
        \return Returns the current parameter value.
        \pre The parameter must be readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if the parameter is not readable or if reading the value fails.
        */
        virtual String_t GetValue() = 0;
        

        /*!
        \brief Gets a list of all values of the enumeration that are currently settable.
        \param[out] values Returns a list of all values of the enumeration that are currently settable.
        \pre The parameter must be readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions.
        */
        virtual void GetSettableValues(GENAPI_NAMESPACE::StringList_t& values) = 0;
        

        /*!
        \brief Gets a list of all values of the enumeration including the values that are currently not settable.
        \param[out] values Returns a list of all values of the enumeration including the values that are currently not settable.
        \pre The parameter must be readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions.
        */
        virtual void GetAllValues(GENAPI_NAMESPACE::StringList_t& values) = 0;
        
        
        /*!
        \brief Get the an entry as parameter.
        This method can be used to access information about the enumeration value represented by the entry using CParameter::GetInfo().
        \param[in] value The value corresponding to the entry that is returned.
        \pre The parameter must be readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions.
        */
        virtual CParameter GetEntryByNameAsParameter(const GENICAM_NAMESPACE::gcstring& value) = 0;


        /*!
        \brief Get the entry corresponding to the currently set value as parameter.
        This method can be used to access information about the enumeration value represented by the entry using CParameter::GetInfo().
        \pre The parameter must be readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions.
        */
        virtual CParameter GetCurrentEntryAsParameter() = 0;
        
        
    };
    

    /*!
    \brief CEnumParameter class used for simplifying access to %GenApi parameters.
    */
    class PYLONBASE_API CEnumParameter : virtual public IEnumerationEx, public CParameter
    {
    public:
        /*!
        \brief Creates an empty CEnumParameter object.
        \error
            Does not throw C++ exceptions.
        */
        CEnumParameter();
        

        /*!
        \brief Creates a CEnumParameter object and attaches it to a node, typically retrieved for a Nodemap calling GetNode().
        \param[in] pNode The node to attach.
        \post
        <ul>
        <li>If the passed node does not match the parameter type the parameter will be empty, see IsValid().
        <li>If the passed node does match the parameter type it is attached and the parameter object can be used to access the node's functionality.
        <li>The parameter object must not be used to access the node's functionality if the source of the attached \c pNode has been destroyed until Release() has been called or a new node has been attached.
        </ul>            
        \error
            Does not throw C++ exceptions.
        */
        CEnumParameter(GENAPI_NAMESPACE::INode* pNode);

        
        /*!
        \brief Creates a CEnumParameter object and attaches it to a node of a matching type.
        \param[in] pEnumeration The node to attach.
        \post
            The parameter object must not be used to access the node's functionality if the source of the attached \c pEnumeration has been destroyed until Release() has been called or a new node has been attached.
        \error
            Does not throw C++ exceptions.
        */
        CEnumParameter(GENAPI_NAMESPACE::IEnumeration* pEnumeration);
        
        
        /*!
        \brief Creates a CEnumParameter object and attaches it to a node retrieved from the provided node map.
        \param[in] pNodeMap The node map. The source of the parameter.
        \param[in] name The name of the parameter to attach.
        \post
        <ul>
        <li>If \c pNodeMap or \c name is NULL the parameter will be empty, see IsValid().
        <li>If the node does not match the parameter type the parameter will be empty, see IsValid().
        <li>If the node does match the parameter type it is attached and the parameter object can be used to access the node's functionality.
        <li>The parameter object must not be used to access the node's functionality if the provided node map has been destroyed until Release() has been called or a new node has been attached.
        </ul>            
        \error
            The call to GenApi::INodeMap::GetNode can throw C++ exceptions.
        */
        CEnumParameter(GENAPI_NAMESPACE::INodeMap* pNodeMap, const char* name);
        

        /*!
        \brief Creates a CEnumParameter object and attaches it to a node retrieved from the provided node map.
        \param[in] nodeMap The node map. The source of the parameter.
        \param[in] name The name of the parameter to attach.
        \post
        <ul>
        <li>If \c name is NULL the parameter will be empty, see IsValid().        
        <li>If the node does not match the parameter type the parameter will be empty, see IsValid().
        <li>If the node does match the parameter type it is attached and the parameter object can be used to access the node's functionality.
        <li>The parameter object must not be used to access the node's functionality if the provided node map has been destroyed until Release() has been called or a new node has been attached.
        </ul>            
        \error
            The call to GenApi::INodeMap::GetNode can throw C++ exceptions.
        */
        CEnumParameter(GENAPI_NAMESPACE::INodeMap& nodeMap, const char* name);

        
        /*!
        \brief Copys a CEnumParameter object.
        \param[in] rhs The object to copy.
        \error
            Does not throw C++ exceptions.
        */
        CEnumParameter(const CEnumParameter& rhs);


        /*!
        \brief Destroys the CEnumParameter object.
        Does not access the attached node.
        \error
            Does not throw C++ exceptions.
        */
        virtual ~CEnumParameter();


        /*!
        \brief Attaches a node retrieved from the provided node map.
        \param[in] pNodeMap The node map. The source of the parameter.
        \param[in] name The name of the parameter to attach.
        \return Returns true if the node has been attached.
        \post
        <ul>
        <li>If \c pNodeMap or \c name is NULL the parameter will be empty, see IsValid().
        <li>If the node does not match the parameter type the parameter will be empty, see IsValid().
        <li>If the node does match the parameter type it is attached and the parameter object can be used to access the node's functionality.
        <li>The parameter object must not be used to access the node's functionality if the provided node map has been destroyed until Release() has been called or a new node has been attached.
        </ul>            
        \error
            The call to GenApi::INodeMap::GetNode can throw C++ exceptions.
        */
        virtual bool Attach(GENAPI_NAMESPACE::INodeMap* pNodeMap, const char* name);
        

        /*!
        \brief Attaches a node retrieved from the provided node map.
        \param[in] nodeMap The node map. The source of the parameter.
        \param[in] name The name of the parameter to attach.
        \return Returns true if the node has been attached.
        \post
        <ul>
        <li>If \c name is NULL the parameter will be empty, see IsValid().        
        <li>If the node does not match the parameter type the parameter will be empty, see IsValid().
        <li>If the node does match the parameter type it is attached and the parameter object can be used to access the node's functionality.
        <li>The parameter object must not be used to access the node's functionality if the provided node map has been destroyed until Release() has been called or a new node has been attached.
        </ul>            
        \error
            The call to GenApi::INodeMap::GetNode can throw C++ exceptions.
        */
        virtual bool Attach(GENAPI_NAMESPACE::INodeMap& nodeMap, const char* name);


        /*!
        \brief Attaches a node, typically retrieved for a Nodemap calling GetNode().
        \param[in] pNode The node to assign.
        \return Returns true if the node has been attached.
        \post
        <ul>
        <li>If the passed node does not match the parameter type the parameter will be empty, see IsValid().
        <li>If the passed node does match the parameter type it is attached and the parameter object can be used to access the node's functionality.
        <li>The parameter object must not be used to access the node's functionality if the source of the attached  \c pNode has been destroyed until Release() has been called or a new node has been attached.
        </ul>            
        \error
            Does not throw C++ exceptions.
        */
        virtual bool Attach(GENAPI_NAMESPACE::INode* pNode);


        /*!
        \brief Assigns a node of the same type to the parameter object.
        \param[in] pEnumeration The node to assign.
        \return Returns true if the node has been attached.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool Attach(GENAPI_NAMESPACE::IEnumeration* pEnumeration);

        
        /*!
        \brief Assigns a CEnumParameter object.
        \param[in] rhs The object to assign.
        \error
            Does not throw C++ exceptions.
        */
        CEnumParameter& operator=(const CEnumParameter& rhs);


        /*!
        \brief Returns true if the same nodes are attached or both parameters are empty.
        \param[in] rhs The object to compare to.
        \return Returns true if the same nodes are attached or both parameters are empty.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator==(const CEnumParameter& rhs) const;
        

        /*!
        \brief Returns true if the the attached node pointer is equal.
        \param[in] pNode The node to compare to.
        \return Returns true if the the attached node pointer is equal.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator==(const GENAPI_NAMESPACE::INode* pNode) const;
        
        
        /*!
        \brief Returns true if the the attached node pointer is equal.
        \param[in] pEnumeration The node to compare to.
        \return Returns true if the the attached node pointer is equal.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator==(const GENAPI_NAMESPACE::IEnumeration* pEnumeration) const;


        /*!
        \brief Returns true if different nodes are attached.
        \param[in] rhs The object to compare to.
        \return Returns true if true if different nodes are attached.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator!=(const CEnumParameter& rhs) const;
        

        /*!
        \brief Returns true if the the attached node pointer is not equal.
        \param[in] pNode The node to compare to.
        \return Returns true if the the attached node pointer is not equal.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator!=(const GENAPI_NAMESPACE::INode* pNode) const;
        
        
        /*!
        \brief Returns true if the the attached node pointer is not equal.
        \param[in] pEnumeration The node to compare to.
        \return Returns true if the the attached node pointer is not equal.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator!=(const GENAPI_NAMESPACE::IEnumeration* pEnumeration) const;


        /*!
        \brief Releases the attached node.
        \error
            Does not throw C++ exceptions.
        */
        virtual void Release();

        
        // Implements IValueEx
        virtual bool IsValid() const;
        

        // Implements GenApi::IEnumeration
        virtual void GetSymbolics(GENAPI_NAMESPACE::StringList_t & Symbolics);

        // Implements GenApi::IEnumeration
        virtual void GetEntries(GENAPI_NAMESPACE::NodeList_t & Entries);

        // Implements GenApi::IEnumeration
        virtual GENAPI_NAMESPACE::IEnumeration& operator=(const GENICAM_NAMESPACE::gcstring& ValueStr);

        // Implements GenApi::IEnumeration
        virtual void SetIntValue(int64_t Value, bool Verify = true);

        // Implements GenApi::IEnumeration
        virtual GENICAM_NAMESPACE::gcstring operator*();

        // Implements GenApi::IEnumeration
        virtual int64_t GetIntValue(bool Verify = false, bool IgnoreCache = false);

        // Implements GenApi::IEnumeration
        virtual GENAPI_NAMESPACE::IEnumEntry *GetEntryByName(const GENICAM_NAMESPACE::gcstring& Symbolic);

        // Implements GenApi::IEnumeration
        virtual GENAPI_NAMESPACE::IEnumEntry *GetEntry(const int64_t IntValue);

        // Implements GenApi::IEnumeration
        virtual GENAPI_NAMESPACE::IEnumEntry *GetCurrentEntry(bool Verify = false, bool IgnoreCache = false);


        // Implements IEnumerationEx
        virtual String_t GetValueOrDefault(const String_t& defaultValue);

        // Implements IEnumerationEx
        virtual bool TrySetValue(const String_t& value);

        // Implements IEnumerationEx
        virtual void SetValue(const char** nullTerminatedList);

        // Implements IEnumerationEx
        virtual bool TrySetValue(const char** nullTerminatedList);
        
        // Implements IEnumerationEx
        virtual bool CanSetValue(const String_t& value);
        
        // Implements IEnumerationEx
        virtual void SetValue(const String_t& value);
        
        // Implements IEnumerationEx
        virtual String_t GetValue();
        
        // Implements IEnumerationEx
        virtual void GetSettableValues(GENAPI_NAMESPACE::StringList_t& values);
        
        // Implements IEnumerationEx
        virtual void GetAllValues(GENAPI_NAMESPACE::StringList_t& values);
        
        // Implements IEnumerationEx
        virtual CParameter GetEntryByNameAsParameter(const GENICAM_NAMESPACE::gcstring& value);

        // Implements IEnumerationEx
        virtual CParameter GetCurrentEntryAsParameter();



    public:
        // Start - For the use with C++ enum extended enum parameters used in generated APIs
        struct TableItem_t
        {
            const char* szName;
            const size_t sizeOfName;
        };
        struct Table_t
        {
            const size_t tableSize;
            const TableItem_t* items;
        };
    protected:
        void SetValue(const Table_t& table, size_t index, bool verify);
        size_t /*index*/ GetValue(const Table_t& table, bool verify, bool ignoreCache);
        GENAPI_NAMESPACE::IEnumEntry* GetEntry(const Table_t& table, size_t index);
        bool CanSetValue(const Table_t& table, size_t index);
        // End - For the use with C++ enum extended enum parameters used in generated APIs
        
    protected:
        GENAPI_NAMESPACE::IEnumeration* m_pFeature;
    };
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_BASLER_PYLON_CENUMPARAMETER_H */