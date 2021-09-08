//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Declaration of the CConfigFileRegistryImpl class
*/


#ifndef __PYLONCONFIGFILEREGISTRYIMPL_H__
#define __PYLONCONFIGFILEREGISTRYIMPL_H__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#if _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251 ) // needs to have dll-interface...
#endif
#include <boost/regex.hpp>

#include <pylon/internal/ConfigFileRegistry.h>

#include <pylon/internal/WrapXml.h>

#include <list>
#include <map>
#include <memory> // for std::shared_pointer

#include <LicenseManager/LicenseManager.h>
#include <LicenseManager/BasicPropertyContext.h>

class CPylonXmlRegistryTest;

namespace Pylon
{

    // ===========================================================================
    //
    // Declaration of the CBindingRule class
    //
    // ===========================================================================
    class CBindingRule
    {
    public:
        CBindingRule(
            unsigned int priority,
            const String_t& manufacturer,
            const String_t& name,
            const String_t& sn,
            const String_t& fileName,
            const StringList_t& additionalFileNames,
            bool download,
            bool custom
            );

        unsigned int GetPriority() const
        {
            return m_priority;
        }

        const boost::regex& GetManufacturerExpr() const
        {
            return m_manufacturer;
        }

        const boost::regex& GetNameExpr() const
        {
            return m_name;
        }

        const boost::regex& GetSerialNumberExpr() const
        {
            return m_sn;
        }

        const String_t& GetFileName() const
        {
            return m_fileName;
        }

        const StringList_t& GetAdditionalFileNames() const
        {
            return m_additionalFileNames;
        }
        bool Download() const
        {
            return m_download;
        }

        bool IsCustomRule() const
        {
            return m_custom;
        }

    private:
        unsigned int    m_priority;
        boost::regex    m_manufacturer;
        boost::regex    m_name;
        boost::regex    m_sn;
        String_t        m_fileName;
        StringList_t    m_additionalFileNames;
        bool            m_download;
        bool            m_custom;
    private:
        CBindingRule();  // *JS* unimplemented private default c'tor to prevent C4510
    };

    typedef std::list<CBindingRule> BindingRuleContainer_t;
    typedef std::map<String_t, BindingRuleContainer_t*> Tl2BindingRules_t;


    /**
    \brief Implementation of the XML config file registry
    */

    class PYLONBASE_API CConfigFileRegistryImpl
    {
    public:

        /// Creates the registry. Configuration files are searched.
        CConfigFileRegistryImpl();
        ~CConfigFileRegistryImpl();

        CConfigFileRegistry::CBinding GetXmlFileBinding( const CDeviceInfo& di );
        BindingRuleContainer_t GetMatchingRules( const String_t& tl, const String_t& manufacturer, const String_t& name, const String_t& sn );

    private:
        void AddRulesFromResources( const String_t& resourceName );
        void AddRulesFromRegistryDir();
        void AddRuleFile( const String_t& fileName );
        void AddRules( const String_t& xml );
        void AddRules( CXmlNode );
        void ProcessTransportLayerNode( const CXmlNode& node, bool isCustomRule );
        void ProcessRuleNode( const String_t& strTlName, const CXmlNode& node, bool isCustomRule );
        // Previously called SetLicense
        void SetPropertyData( const void* pLicense, size_t licenseSize, const void* pPublicKey = NULL, size_t publicKeySize = 0 );

        Tl2BindingRules_t m_BindingRules;
        std::shared_ptr<SECURITY_NAMESPACE::LICENSEMANAGER_CLASSNAME> m_ptrLicenseManager;

        friend class ::CPylonXmlRegistryTest;
        friend class CConfigFileRegistry;

    };

}


#if _MSC_VER
#pragma warning(pop)
#endif

#endif
