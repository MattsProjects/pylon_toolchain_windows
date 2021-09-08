//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2008-2013 Basler
//  http://www.baslerweb.com
//  Author:  Thomas Koeller, Hartmut Nebelung
//-----------------------------------------------------------------------------
/*!
\file
\brief Definition of the GigE-specific transport layer interface extension
*/

#ifndef TRANSPORTLAYER_GIGE_H
#define TRANSPORTLAYER_GIGE_H

#if _MSC_VER>1000
#pragma once
#endif // _MSC_VER>1000

#include <pylon/TransportLayer.h>
#include "PylonGigE.h"

namespace Pylon
{
    /*!
    \ingroup Pylon_TransportLayer
    \brief Result structure of an action command
    */
    struct GevActionResult
    {
        /// IP address of the device.
        uint32_t GevDeviceAddr;

        /// GigE Vision status code returned by the device.
        uint32_t GevStatus;
    };

    /*!
    \ingroup Pylon_TransportLayer
    \interface IGigETransportLayer
    \brief Extends the ITransportLayer interface by GigE Vision specific
           functionality.
    */
    interface PYLONGIGE_API IGigETransportLayer : public ITransportLayer
    {
        //! \brief Enumerates all available GigE Vision devices
        /*!
            In contrast to the ITransportLayer::EnumerateDevices method,
            devices having a subnet configured that is different from the subnet of the
            application will be listed.
        */
        virtual int EnumerateAllDevices(DeviceInfoList_t&, bool addToList = false) = 0;

        //! \brief "Force" a static IP address configuration in a device identified by its MAC Address
        /**
        \note When calling this function, there must be no opened camera object for
               the device to be reconfigured!

        \param MacAddress MAC address as a string, no delimiters are used. e.g., 003053061a58
        \param IpAddress Temporary IP address, "dot notation", e.g., 192.168.1.2
        \param SubnetMask Temporary SubnetMask, "dot notation", e.g. 255.255.255.0
        \param DefaultGateway Temporary DefaultGateway, "dot notation", e.g., 192.168.1.1
        */
        virtual void ForceIp(const String_t& MacAddress,
                             const String_t& IpAddress,
                             const String_t& SubnetMask,
                             const String_t& DefaultGateway) = 0;

        //! \brief Let a device restart the IP configuration cycle
        /**
        \note This function fails when the device is open, i.e., a control channel is established
        \param MacAddress MAC address as a string, no delimiters are used, e.g., 003053061a58
        */
        virtual void RestartIpConfiguration(const String_t& MacAddress) = 0;

        //! \brief Announce that a remote device is going to be used
        /*!
            \note This device must be reachable, a route is configured.
            \param IpAddress address of device in "dot notation"
            \param pInfo This optional parameter  holds the full device info iff found
        */
        virtual bool AnnounceRemoteDevice( const String_t& IpAddress, CDeviceInfo* pInfo=NULL ) = 0;
        //! \brief Stop using remote device.
        /*! \param IpAddress address of device in "dot notation" */
        virtual bool RenounceRemoteDevice( const String_t& IpAddress ) = 0;

        //! \brief Broadcast a new IP configuration
        /**
        \param MacAddress MAC address as a string, no delimiters are used. e.g., 003053061a58
        \param EnablePersistentIp If true, a persistent Ip address will be set
        \param EnableDhcp If true, DHCP is enabled
        \param IpAddress Device's new IP address, "dot notation", e.g., 192.168.1.2
        \param SubnetMask Device's new SubnetMask, "dot notation", e.g. 255.255.255.0
        \param DefaultGateway Device's new DefaultGateway, "dot notation", e.g., 192.168.1.1
        \param UserdefinedName Device's new UserdefinedName, maximal 16 character
        \return true if configuration was successfully written
        */
        virtual bool BroadcastIpConfiguration(const String_t& MacAddress,
                                              bool EnablePersistentIp,
                                              bool EnableDhcp,
                                              const String_t& IpAddress,
                                              const String_t& SubnetMask,
                                              const String_t& DefaultGateway,
                                              const String_t& UserdefinedName) = 0;
        
        //! \brief Issue an action trigger
        /**
        \param DestinationAddress, "dot notation", e.g. 192.168.1.38 (single device), 192.168.1.255 (group), 255.255.255.255 (all)
        \param DeviceKey %Key value identifying a group of devices
        \param GroupKey %Key value identifying a group of actions
        \param GroupMask Bit mask to select some action(s) of a group
        \param Timeout_ms Time in milliseconds waiting for acknowledges of the addressed devices, define zero if not interested
        \param pNumDevices Number of devices expected to acknowledge the command, optional
        \param Results Buffer with NumDevices elements to hold the acknowledge status, optional
        */
        virtual void IssueActionCommand( const String_t &BroadcastAddress, 
                                             uint32_t DeviceKey,
                                             uint32_t GroupKey,
                                             uint32_t GroupMask,
                                             uint32_t Timeout_ms = 0,
                                             uint32_t *pNumDevices = 0,
                                             GevActionResult Results[] = NULL
                                             ) = 0;
        //! \brief Issue a scheduled action trigger
        /**
        \param DestinationAddress, "dot notation", e.g. 192.168.1.38 (single device), 192.168.1.255 (group), 255.255.255.255 (all)
        \param DeviceKey %Key value identifying a group of devices
        \param GroupKey %Key value identifying a group of actions
        \param GroupMask Bit mask to select some action(s) of a group
        \param ActionTime_ns Time in nanoseconds when action is executed
        \param Timeout_ms Time in milliseconds waiting on acknowledges of the addressed devices, define zero if not interested
        \param pNumDevices Number of devices expected to acknowledge the command, optional
        \param Results Buffer with NumDevices elements to hold the acknowledge status, optional
        */
        virtual void IssueScheduledActionCommand( const String_t &BroadcastAddress, 
                                                  uint32_t DeviceKey, 
                                                  uint32_t GroupKey, 
                                                  uint32_t GroupMask, 
                                                  uint64_t ActionTime_ns, 
                                                  uint32_t Timeout_ms = 0, 
                                                  uint32_t *pNumDevices = 0, 
                                                  GevActionResult Results[] = NULL 
                                                  ) = 0;

    };
} // namespace Pylon

#endif // TRANSPORTLAYER_GIGE_H
