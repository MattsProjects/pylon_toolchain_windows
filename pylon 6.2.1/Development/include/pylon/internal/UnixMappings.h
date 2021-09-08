//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2015-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  TvdM
//-----------------------------------------------------------------------------
/*!
\file
\brief map strcase* to Iso C++
*/
#ifndef INCLUDED_PYLONLINUXMAPPING_H_6746942
#define INCLUDED_PYLONLINUXMAPPING_H_6746942

#if defined (PYLON_UNIX_BUILD)
#   define _stricmp     strcasecmp
#   define _strnicmp    strncasecmp
#   define PYLON_UNALIGNED
#endif


#endif
