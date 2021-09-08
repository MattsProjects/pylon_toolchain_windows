//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Some internal utility functions
*/

#pragma once

#ifndef PYLONPRIVATE_UTILITIES_H__
#define PYLONPRIVATE_UTILITIES_H__

#include <typeinfo>
#include <GenICamFwd.h>
#include <pylon/Platform.h>
#include <pylon/PylonBase.h>
#include <pylon/stdinclude.h>

namespace Pylon
{
    // forward
    class CDeviceInfo;

    // since you cannot use std::find with StringList_t we'll provide a equal function in the pylon namespace
    // see std::find
    inline StringList_t::const_iterator find( StringList_t::const_iterator first, StringList_t::const_iterator last, const String_t& val )
    {
        for (StringList_t::const_iterator it = first; it != last; ++it)
        {
            if (*it == val)
            {
                return it;
            }
        }

        return last;
    }

    // since you cannot use std::find with StringList_t we'll provide a equal function in the pylon namespace
    // see std::find
    inline StringList_t::iterator find( StringList_t::iterator first, StringList_t::iterator last, const String_t& val )
    {
        for (StringList_t::iterator it = first; it != last; ++it)
        {
            if (*it == val)
            {
                return it;
            }
        }

        return last;
    }

    // returns a key value pair in output params parsed from a string like 'key1=value1;key2=value2'
    PYLONBASE_API bool getKeyAndValueFromString( const char* pKeyValueString, const char* pSerperatorChars, size_t index, Pylon::String_t* pstrKey, Pylon::String_t* pstrValue );

    // returns a value specified by key
    PYLONBASE_API bool getValueByKeyFromString( const char* pKeyValueString, const char* pSerperatorChars, const char* pKey, Pylon::String_t* pstrValue );

    // a very lousy uri encode
    PYLONBASE_API String_t replaceSpacesWith20( const char* pszInputString );

    // extract the n'th substring of a string separated by strSep
    PYLONBASE_API bool extractSubString( Pylon::String_t& strSubString, const Pylon::String_t& strFullString, size_t nSubString, const char* pszSep );

    /// returns the path separator for the platform as a string
    PYLONBASE_API const char* getPylonPathSeperator();

    /// returns the path list delimiter for the platform as a string
    PYLONBASE_API const char* getPylonPathListDelimiter();

    /// folder types used in getPylonFolderPath
    typedef enum eFolderType
    {
        ftPylonBaseDir,    // absolute path to pylon base DLL
        ftPylonDefaultCdfDir, // location of camera description files on disk
        ftPylonSharedLib,  // where pylon main DLLs a re located
        ftPylonConfigFileRegistry, // folder where config files hare stored
        ftPylonTL,         // where TLs can be found
        ftPylonTLSupport,  // where support libraries for TLs can be found

        FolderType_PylonBaseDir = ftPylonBaseDir,              // absolute path to pylon base DLL
        FolderType_PylonDefaultCdfDir = ftPylonDefaultCdfDir,  // location of camera description files on disk
        FolderType_PylonSharedLib = ftPylonSharedLib,          // where pylon main DLLs a re located
        FolderType_PylonConfigFileRegistry = ftPylonConfigFileRegistry, // folder where config files hare stored
        FolderType_PylonTL = ftPylonTL,                        // where TLs can be found
        FolderType_PylonTLSupport = ftPylonTLSupport          // where support libraries for TLs can be found

    } FolderType;

    /// returns a pylon path specified by foldertype (see enum FolderType)
    PYLONBASE_API const char* getPylonFolderPath( FolderType folderType );

    /// reads a text file and returns it's content as string
    PYLONBASE_API void textFileToString( const String_t& filename, String_t& fileContent );


    // casts a integral type to a smaller integral type and throws a std::bad_cast exception if the conversion results in data loss.
    // usually this is used to cast 64bt values to 32 bit values
    template<typename targettype, typename sourcetype>
    targettype safe_cast( const sourcetype& source )
    {
        const targettype target = static_cast<targettype>(source);
        if (source != static_cast<sourcetype>(target))
        {
            throw std::bad_cast();
        }

        return target;
    }

    PYLONBASE_API Pylon::String_t itos( unsigned int val );

    PYLONBASE_API void SetCurrentThreadName( const char* pszThreadName );

    PYLONBASE_API void SetThreadName( unsigned long dwThreadID, const char* pszThreadName );


    PYLONBASE_API size_t    HexEncodeString( const void* pData, size_t cbData, char* pszHexEncoded, size_t cbHexEncoded, const char* pszSep = NULL );

    PYLONBASE_API String_t  HexEncodeString( const void* pData, size_t cbData, const char* pszSep = NULL );

    PYLONBASE_API size_t    HexDecodeString( const char* pszHexCodedString, void* pData, size_t cbData );

    PYLONBASE_API size_t    HexDecodeString( const String_t& strHexCodedString, void* pData, size_t cbData );

    PYLONBASE_API bool      GetValueOfEnvironmentVariable( const char* pszEnvVarName, String_t& strValue );

    // load the default TLParams from embedded XML
    PYLONBASE_API GENAPI_NAMESPACE::INodeMap* CreateDefaultTransportLayerParamsNodeMap( void );

    PYLONBASE_API void DestroyNodeMap( GENAPI_NAMESPACE::INodeMap* pNodeMap );

    PYLONBASE_API String_t TrimLeft( const String_t& s );

    PYLONBASE_API String_t TrimRight( const String_t& s );

} // namespace

#endif // PYLONPRIVATE_UTILITIES_H__
