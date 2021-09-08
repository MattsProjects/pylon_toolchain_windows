//------------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2018 Basler AG
//  http://www.baslerweb.com
//------------------------------------------------------------------------------
/*!
\file
\brief Contains the class CParameter used for simplifying access to %GenApi parameters.
*/

#ifndef INCLUDED_BASLER_PYLON_CPARAMETER_H
#define INCLUDED_BASLER_PYLON_CPARAMETER_H

#pragma once

#include <pylon/PylonBase.h>
#include <GenApi/IValue.h>


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
    /// Lists possible parameter info values.
    enum EParameterInfo
    {
        /// The identifier a parameter, that can be used to access the node via a node map using GenApi::INodMap::GetNode(),
        /// or the value of an enumeration parameter when using CEnumParameter::GetEntryByNameAsParameter().
        ParameterInfo_Name,
        /// The a name of a parameter or an enumeration value that can be used for displaying in a user interface.
        ParameterInfo_DisplayName,
        /// The a short description of a parameter or an enumeration value.
        ParameterInfo_ToolTip,
        /// The a long description of a parameter or an enumeration value.
        ParameterInfo_Description
    };


    /*!
    \brief Extends the GenApi::IValue interface with convenience methods.
    */
    interface IValueEx : virtual public GENAPI_NAMESPACE::IValue
    {
        /*!
        \brief Returns true if the parameter is readable.
        \error 
            Does not throw C++ exceptions.
        \return Returns true if the parameter is readable.
        */
        virtual bool IsReadable() = 0;

        
        /*!
        \brief Returns true if the parameter is writable.
        \error 
            Does not throw C++ exceptions.
        \return Returns true if the parameter is writable.
        */
        virtual bool IsWritable() = 0;
        

        /*!
        \brief Returns true if a node is attached.
        \return Returns true if a node is attached.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool IsValid() const = 0;
        

        /*!
        \brief Gets the parameter information.
        \param[in] info The type information to return.
        \return Returns the parameter information.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
            Throws an exception if no node is attached.
            Can throw exceptions if the retrieval of the information fails.
        */
        virtual String_t GetInfo(EParameterInfo info) = 0;
        

        /*!
        \brief Gets the parameter information if the parameter is attached t a node, see IsValid().
        \param[in] info The type information to return.
        \brief Otherwise, returns the default information.
        This method is useful if you want to display parameter information and handle the case that some parameters are not available for a device.
        \return Returns the parameter information if the parameter is attached t a node. Otherwise, returns the default information.
        \param[in] defaultInfo   The default information returned if the parameter is not attached to a node.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if the retrieval of the information fails.
        */
        virtual String_t GetInfoOrDefault(EParameterInfo info, const String_t defaultInfo) = 0;
        
        
        /*!
        \brief Gets the parameter value as string if the parameter is readable.
        \brief Otherwise, returns the default value.
        \return Returns the parameter value if the parameter is readable. Otherwise, returns the default value.
        \param[in] defaultValue   The default value returned if the parameter is not readable.
        \threading
             Multiple calls to the parameter are used. These calls are not synchronized by a lock.
        \error
             Can throw exceptions if reading the value fails.
        */
        virtual String_t ToStringOrDefault(const String_t& defaultValue) = 0;    };


    /*!
    \brief CParameter class used for simplifying access to %GenApi parameters.
    */
    class PYLONBASE_API CParameter : virtual public IValueEx
    {
    public:
        /*!
        \brief Creates an empty CParameter object.
        \error
            Does not throw C++ exceptions.
        */
        CParameter();
        

        /*!
        \brief Creates a CParameter object and attaches it to a node, typically retrieved for a Nodemap calling GetNode().
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
        CParameter(GENAPI_NAMESPACE::INode* pNode);

        
        /*!
        \brief Creates a CParameter object and attaches it to a node of a matching type.
        \param[in] pValue The node to attach.
        \post
            The parameter object must not be used to access the node's functionality if the source of the attached \c pValue has been destroyed until Release() has been called or a new node has been attached.
        \error
            Does not throw C++ exceptions.
        */
        CParameter(GENAPI_NAMESPACE::IValue* pValue);
        
        
        /*!
        \brief Creates a CParameter object and attaches it to a node retrieved from the provided node map.
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
        CParameter(GENAPI_NAMESPACE::INodeMap* pNodeMap, const char* name);
        

        /*!
        \brief Creates a CParameter object and attaches it to a node retrieved from the provided node map.
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
        CParameter(GENAPI_NAMESPACE::INodeMap& nodeMap, const char* name);

        
        /*!
        \brief Copys a CParameter object.
        \param[in] rhs The object to copy.
        \error
            Does not throw C++ exceptions.
        */
        CParameter(const CParameter& rhs);


        /*!
        \brief Destroys the CParameter object.
        Does not access the attached node.
        \error
            Does not throw C++ exceptions.
        */
        virtual ~CParameter();


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
        \param[in] pValue The node to assign.
        \return Returns true if the node has been attached.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool Attach(GENAPI_NAMESPACE::IValue* pValue);

        
        /*!
        \brief Assigns a CParameter object.
        \param[in] rhs The object to assign.
        \error
            Does not throw C++ exceptions.
        */
        CParameter& operator=(const CParameter& rhs);


        /*!
        \brief Returns true if the same nodes are attached or both parameters are empty.
        \param[in] rhs The object to compare to.
        \return Returns true if the same nodes are attached or both parameters are empty.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator==(const CParameter& rhs) const;
        

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
        \param[in] pValue The node to compare to.
        \return Returns true if the the attached node pointer is equal.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator==(const GENAPI_NAMESPACE::IValue* pValue) const;


        /*!
        \brief Returns true if different nodes are attached.
        \param[in] rhs The object to compare to.
        \return Returns true if true if different nodes are attached.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator!=(const CParameter& rhs) const;
        

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
        \param[in] pValue The node to compare to.
        \return Returns true if the the attached node pointer is not equal.
        \error
            Does not throw C++ exceptions.
        */
        virtual bool operator!=(const GENAPI_NAMESPACE::IValue* pValue) const;


        /*!
        \brief Releases the attached node.
        \error
            Does not throw C++ exceptions.
        */
        virtual void Release();

        
        


        // Implements GenApi::IBase
        virtual GENAPI_NAMESPACE::EAccessMode GetAccessMode() const;

        // Implements GenApi::IValue
        virtual GENAPI_NAMESPACE::INode* GetNode();

        // Implements GenApi::IValue
        virtual GENICAM_NAMESPACE::gcstring ToString(bool Verify = false, bool IgnoreCache = false);

        // Implements GenApi::IValue    
        virtual void FromString(const GENICAM_NAMESPACE::gcstring& ValueStr, bool Verify = true);

        // Implements GenApi::IValue
        virtual bool IsValueCacheValid() const;


        // Implements IValueEx
        virtual bool IsReadable();
        
        // Implements IValueEx
        virtual bool IsWritable();
        
        // Implements IValueEx
        virtual bool IsValid() const;
        
        // Implements IValueEx
        virtual String_t GetInfo(EParameterInfo info);
        
        // Implements IValueEx
        virtual String_t GetInfoOrDefault(EParameterInfo info, const String_t defaultInfo);
        
        // Implements IValueEx
        virtual String_t ToStringOrDefault(const String_t& defaultValue);        
    protected:
        GENAPI_NAMESPACE::IValue* m_pValue;
    };
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_BASLER_PYLON_CPARAMETER_H */