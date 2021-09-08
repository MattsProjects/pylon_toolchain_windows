//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  SK
//-----------------------------------------------------------------------------
/*!
\file   Contains function declarations for pylon image window.
*/

#ifndef INCLUDED_PYLONGUIC_H_01474726
#define INCLUDED_PYLONGUIC_H_01474726

#ifdef PYLONGUI_EXPORTS
#   define PYLONGUI_API APIEXPORT
#else
#   define PYLONGUI_API APIIMPORT

#   ifndef PYLON_NO_AUTO_IMPLIB
#       pragma comment(lib, PYLON_LIB_NAME( "PylonGUI" ))
#   endif
#endif

PYLONGUI_API int    PylonImageWindow_Create( size_t winIndex, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT );
PYLONGUI_API int    PylonImageWindow_Show( size_t winIndex, int nShow = SW_SHOW );
PYLONGUI_API int    PylonImageWindow_Hide( size_t winIndex );
PYLONGUI_API int    PylonImageWindow_Close( size_t winIndex );
PYLONGUI_API HWND   PylonImageWindow_GetWindowHandle( size_t winIndex );
PYLONGUI_API void   PylonImageWindow_SetImageRaw( size_t winIndex, void* pBuffer, size_t bufferSize, Pylon::EPixelType pixelType, uint32_t width, uint32_t height, size_t paddingX, Pylon::EImageOrientation orientation );
PYLONGUI_API void   PylonImageWindow_DisplayImageRaw( size_t winIndex, void* pBuffer, size_t bufferSize, Pylon::EPixelType pixelType, uint32_t width, uint32_t height, size_t paddingX, Pylon::EImageOrientation orientation );

#endif /* INCLUDED_PYLONGUIC_H_01474726 */
