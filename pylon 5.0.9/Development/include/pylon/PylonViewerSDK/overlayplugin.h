//-----------------------------------------------------------------------------
//  Copyright (c) 2006-2017 Basler AG
//  Section: Basler Components
//  Project: pylon
//  Subproject: PylonQtApps
//-----------------------------------------------------------------------------
/*!
    \file
    \brief Interface for Color Converter plugins
*/

#ifndef PYLONVIEWERSDK_OVERLAYPLUGIN_H
#define PYLONVIEWERSDK_OVERLAYPLUGIN_H

#include <pylon/PylonIncludes.h>
#include <PylonViewerSdk/plugin.h>

namespace PylonViewerSdk
{

    /**
      Interface for a plugin that works on the raw input image and
      modifies the RGBA image passed in to the plugin along with the raw
      image buffer.
    */
    struct IOverlayPlugin : public IPlugin
    {
        /**
        Processes the raw buffer and modifies the RGB buffer.

        \param pRaw   The raw image data

        \param format The image's size, format, etc.

        \param pRgba  Pointer to the pixel data of the converted RGBA image

        \param bitmapHandle Platform specific handle to the RGBA image. When bitmapHandle
            equals NULL, no handle is available for the platform
        */
        virtual void processBuffer(
            const void* pRaw,
            const Pylon::SImageFormat& format,
            Pylon::SBGRA8Pixel *pRgba,
            const unsigned int linePitchDest,
            void* bitmapHandle
        ) = 0;
    };


} // namespace PylonViewerSdk

#endif
