//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Declaration of the CConfigFileRegistry class
*/


#ifndef __PYLONCONFIGFILEREGISTRY_H__
#define __PYLONCONFIGFILEREGISTRY_H__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/stdinclude.h>
#include <pylon/PylonBase.h>

namespace Pylon
{

    class CDeviceInfo;
    class CConfigFileRegistryImpl;

    /**
      Manages the mapping camera <--> XML configuration file
      */
    class PYLONBASE_API CConfigFileRegistry
    {
    public:
        class CBinding
        {
        public:
            /// Returns true, when file from device should be used
            bool DownloadFromDevice() const
            {
                return m_loadFromDevice;
            }

            /// Returns true if no binding provided by a rule file has been found and this is the default binding.
            bool IsDefaultBinding() const
            {
                return m_isDefaultBinding;
            }

            /// Returns true, when a local file name is provided
            bool UseLocalFile() const
            {
                return m_useLocalFile;
            }

            /// Returns true, when a additional (local) file name is provided
            bool UseAdditionalFile() const
            {
                return m_useAdditionalFile;
            }

            /// Returns true, when a local location of the file is available
            bool XmlFileLocation( String_t& location ) const
            {
                if (m_useLocalFile)
                {
                    location = m_fileName;
                }
                return m_useLocalFile;
            }

            /// Returns true, when the (local) location of an additional file is available
            bool AdditionalXmlFileLocations( StringList_t& additionalLocations ) const
            {
                if (m_useAdditionalFile)
                {
                    additionalLocations = m_additionalFileNames;
                }
                return m_useAdditionalFile;
            }

        private:
            CBinding( bool loadFromDevice, bool useLocalFile, const char* filename, bool useAdditionalFile, StringList_t& additionalFileNames );
            CBinding( bool loadFromDevice, bool useLocalFile, const char* filename, bool isDefaultBinding = false );

        private:

            bool m_isDefaultBinding;
            bool m_loadFromDevice;
            bool m_useLocalFile;
            String_t m_fileName;
            bool m_useAdditionalFile;
            StringList_t m_additionalFileNames;



            friend class CConfigFileRegistryImpl;


        };


        /// retrieve the one and only instance (singleton)
        static CConfigFileRegistry& GetInstance();

        /// returns the result of the xml configuration rules
        CBinding GetXmlFileBinding( const CDeviceInfo& di );

        // Previously called SetLicense
        void SetPropertyData( const void* pLicense, size_t licenseSize, const void* pPublicKey = NULL, size_t publicKeySize = 0 );

        ~CConfigFileRegistry();

    private:
        CConfigFileRegistry();

        //! \name No copying and assignment supported
        // \{
        CConfigFileRegistry( const CConfigFileRegistry& );
        CConfigFileRegistry operator=( const CConfigFileRegistry& );
        // \}

        CConfigFileRegistryImpl* m_pImpl;
    };





} // namespace




#endif
