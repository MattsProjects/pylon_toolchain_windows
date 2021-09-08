//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of the IPylonDevicePrivate interface
*/
#pragma once


#ifndef PYLONDEVICEPRIVATE_H__
#define PYLONDEVICEPRIVATE_H__

#include <vector>
#include "../Device.h"

namespace Pylon
{

    /** Private interface used by the factory for
        device creation
    */
    interface PUBLIC_INTERFACE IPylonDevicePrivate
    {
        /// Creates the node map
        virtual void CreateNodemapFromXmlData( const std::vector<uint8_t>& xmlData, const StringList_t& injectedXmlStrings, bool extractChunks ) = 0;

        /// Chunk node maps are supported at all
        virtual bool GetChunkDataNodeMapSupported() = 0;

        /// Chunk data XML description is available
        virtual bool ChunkDataXmlDescriptionAvailable() = 0;

        /// Delete function
        virtual void Delete() = 0;
    };

} // namespace Pylon

#endif // PYLONDEVICEPRIVATE_H__
