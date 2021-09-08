//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2008-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  Thomas Koeller
//-----------------------------------------------------------------------------

#if !defined(PLATFORM_PRIVATE_H)
#define PLATFORM_PRIVATE_H

#include <pylon/Platform.h>
#include <PlatformHelper/BaseLibsPlatform.h>

#if defined(PYLON_WIN_BUILD)

#   define SUPPORT_IEEE1394             1
#   define SUPPORT_GIGE                 1
#   define SUPPORT_USB                  1
#   define SUPPORT_BCON                 1
#   define SUPPORT_CAMERALINK           1
#   define HAVE_TESTDATACOLLECTOR_H

#elif defined (PYLON_UNIX_BUILD)

#include <pylon/autoconf.h>

//autotools default to not specifying NDEBUG. But our source expects NDEBUG to
//be specified in release build. So we error out here.
#if !defined(NDEBUG) && !defined(_DEBUG)
#   error "Neither NDEBUG nor _DEBUG specified. Maybe you should call configure with --disable-debug?"
#endif

#else

#error Unsupported platform

#endif

#endif /* !defined(PLATFORM_PRIVATE_H) */
