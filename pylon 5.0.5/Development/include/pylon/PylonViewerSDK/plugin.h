//-----------------------------------------------------------------------------
//  Copyright (c) 2006-2016 Basler AG
//  Section: Basler Components
//  Project: pylon
//  Subproject: PylonQtApps
//-----------------------------------------------------------------------------
/*!
    \file
    \brief Declaration of plugin interfaces used by the pylon Viewerstyle used for Pylon Qt Applications
*/
#pragma once

#ifndef PYLONVIEWERSDK_PLUGIN_H
#define PYLONVIEWERSDK_PLUGIN_H

#include <pylon/PylonIncludes.h>
#include <GenICamFwd.h>

namespace PylonViewerSdk
{
    /**
      A plugin's type
    */
    enum PluginType
    {
        ptUndefined = -1,
        ptColorConverter,  //< to be executed after the decoupler
        ptOverlay          //< to be executed after color converters
    };


    /**
      The base interface for PylonViewer plugins
    */
    struct IPlugin
    {
        /// Returns the plugin's display name
        virtual const char* getDisplayName() const = 0;

        /// Returns the nodemap used to parameterize the plugin
        virtual GenApi::INodeMap* GetNodeMap() const = 0;

        /// Returns the plugin's type
        virtual PluginType getType() const = 0;

        /// The sequence of execution of plugins is Plugins of the same type are executed in a the Returns a hint for the order
        virtual unsigned int getPriority() const  = 0;

        /// Returns true, when the plugin is enabled
        virtual bool isEnabled() const = 0;
    };



    const unsigned int gPluginSystemVersionMajor = 1;
    const unsigned int gPluginSystemVersionMinor = 0;

    /**
      \name Plugin Functions

      Functions to be exported by PylonViewer Plugin Dlls
    */
    // \{
    typedef IPlugin* (*fnPluginCreateInstance)(void);
    typedef void (*fnPluginDestroyInstance)( IPlugin* );

    typedef void (*fnPylonViewerPluginInfo)(
        unsigned int &versionMajor,
        unsigned int &versionMinor,
        PluginType& pluginType,
        GenICam::gcstring& name
    );
    //\}


}

#endif
