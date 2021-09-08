//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2010-2013 Basler
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief  Include for linking pylon and implicitly genicam bootstrapper
*/

//WARNING: requires delay loaded GenICam dlls
//Enter under 'Configuration Properties' -> 'Linker' -> 'Input' -> 'Delay Loaded DLLs'
//e.g.: GCBase_MDd_vc100_V2_1.dll;GenApi_MDd_vc100_V2_1.dll;Log_MDd_vc80_V2_1.dll;Log4Cpp_MDd_vc100_V2_1.dll
//e.g.: GCBase_MD_vc100_V2_1.dll;GenApi_MD_vc100_V2_1.dll;Log_MD_vc100_V2_1.dll;Log4Cpp_MD_vc100_V2_1.dll

#ifndef PYLONBOOTSTRAPPER_H_INCLUDED__
#define PYLONBOOTSTRAPPER_H_INCLUDED__

#include "pylon/Platform.h"

#if defined(PYLON_WIN_BUILD)
#   if (defined(_DEBUG) || defined(DEBUG)) && defined(PYLON_BUILD_DEBUG)
#       pragma comment(lib, "PylonBootstrapperd.lib")
#   else
#       pragma comment(lib, "PylonBootstrapper.lib")
#   endif

#   if defined PYLON_64_BUILD
#       pragma comment(linker, "/include:gPylonBootstrapper")
#   else
#       pragma comment(linker, "/include:_gPylonBootstrapper")
#   endif

#   pragma comment(lib, "user32.lib")
#   pragma comment(lib, "shell32.lib")
#   pragma comment(lib, "kernel32.lib")
#endif

#endif //PYLONBOOTSTRAPPER_H_INCLUDED__
