//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2019-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  MP
//-----------------------------------------------------------------------------
/*!
\file
\brief  Master include for the Compression library
*/

#pragma once

#include <compression/Compression.h>
#include <compression/CompressionVersion.h>
#include <compression/Decompressor.h>
#include <compression/Exception.h>

#if defined (_WIN32) && !defined (COMPRESSION_NO_AUTO_IMPLIB)

#define COMPRESSION_API_VERSION_SUFFIX "_v" COMPRESSION_API_VERSIONSTRING_MAJOR

#if (defined(_DEBUG) || defined(DEBUG)) && defined(COMPRESSION_API_BUILD_DEBUG)
#   define COMPRESSION_API_CONFIGURATION "d"
#else
#   define COMPRESSION_API_CONFIGURATION ""
#endif

#define COMPRESSION_API_SUFFIX( config, extension ) config "." extension

 // generic
#define COMPRESSION_API_LIB_SUFFIX        COMPRESSION_API_SUFFIX( COMPRESSION_API_VERSION_SUFFIX COMPRESSION_API_CONFIGURATION, "lib" )
#define COMPRESSION_API_DLL_SUFFIX        COMPRESSION_API_SUFFIX( COMPRESSION_API_VERSION_SUFFIX COMPRESSION_API_CONFIGURATION, "dll" )

#define COMPRESSION_API_LIB_NAME( module )  module COMPRESSION_API_SUFFIX( COMPRESSION_API_VERSION_SUFFIX COMPRESSION_API_CONFIGURATION, "lib" )
#define COMPRESSION_API_DLL_NAME( module )  module COMPRESSION_API_SUFFIX( COMPRESSION_API_VERSION_SUFFIX COMPRESSION_API_CONFIGURATION, "dll" )

#if defined(COMPRESSION_API_STATIC)
#   pragma comment(lib, COMPRESSION_API_LIB_NAME( "CompressionStatic" ))
#else
#   pragma comment(lib, COMPRESSION_API_LIB_NAME( "Compression" ))
#endif

#endif
