//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2014 Basler AG
//  http://www.baslerweb.com
//  Author: Hartmut Nebelung
//-----------------------------------------------------------------------------
/*!
\file
\brief An instant camera configuration for triggering via GigE Vision action commands. 
       This  instant camera configuration is provided as header-only file. The code
       can be copied and modified for creating own configuration classes.
*/

#ifndef INCLUDED_ACTIONTRIGGERCONFIGURATION_H_4655834
#define INCLUDED_ACTIONTRIGGERCONFIGURATION_H_4655834

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/InstantCamera.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiGigE
     * @{
     */
    // Arbitrarily chosen constants for camera selection. For an explanation and 
    // tips see the "Multi-Camera Applications and GigE Vision 2.0" White paper
    const uint32_t AllGroupMask(0xffffffff);  // camera will respond to any mask other than 0

    /*!
    \class  CActionTriggerConfiguration
    \brief  Changes the configuration of the camera so that it is triggered by the first 
    available action command.

    This configuration enables the frame start trigger and disables all other trigger 
    types. As trigger source the first available action command is selected, i.e., the 
    camera will be triggered by action commands issued by the application.

    In contrast to using the software trigger triggering with action commands allows 
    to trigger multiple cameras simultaneously.

    Either register this configuration as an Instant Camera's event handler or apply 
    the configuration to the node map of an opened pylon device using one of the 
    ApplyConfiguration methods.

    The %CActionTriggerConfiguration is provided as header-only file.
    The code can be copied and modified for creating own configuration classes.
    */
    class CActionTriggerConfiguration : public CConfigurationEventHandler
    {
    public:
        struct ActionParameter
        {
            uint32_t DeviceKey;
            uint32_t GroupKey;
            uint32_t GroupMask;

            ActionParameter()
                : DeviceKey(0), GroupKey(0), GroupMask(AllGroupMask)
            {
            }
            ActionParameter(uint32_t DeviceKey_, uint32_t GroupKey_, uint32_t GroupMask_ = AllGroupMask)
                : DeviceKey(DeviceKey_), GroupKey(GroupKey_), GroupMask(GroupMask_)
            {
            }
        };

        // constructors and assignment
        CActionTriggerConfiguration( uint32_t DeviceKey, uint32_t GroupKey, uint32_t GroupMask=AllGroupMask ) :
            m_Parameter(DeviceKey, GroupKey, GroupMask)
        {
        }
        CActionTriggerConfiguration( const ActionParameter& p )
          :  m_Parameter( p )
        {
        }
        CActionTriggerConfiguration( const CActionTriggerConfiguration& other )
        {
            m_Parameter = other.m_Parameter;
        }
        CActionTriggerConfiguration& operator=( const CActionTriggerConfiguration& rhs )
        {
            m_Parameter = rhs.m_Parameter;
            return *this;
        }
 
        /// Apply action trigger configuration to a given camera device node map.
        static void ApplyConfiguration( GenApi::INodeMap& deviceNodeMap, const ActionParameter& p )
        {
            ApplyConfiguration( deviceNodeMap, p.DeviceKey, p.GroupKey, p.GroupMask );
        }

        /// Apply action trigger configuration to a given camera device node map.
        static void ApplyConfiguration( GenApi::INodeMap& deviceNodeMap, uint32_t DeviceKey, uint32_t GroupKey, uint32_t GroupMask = AllGroupMask )
        {
            using namespace GenApi;

            //////////////////////////////////////////////////////////////////
            // get the nodes we need and do a check before we start changing the camera configuration

            GenApi::CIntegerPtr ptrActionDeviceKey( deviceNodeMap.GetNode( "ActionDeviceKey" ) );
            GenApi::CIntegerPtr ptrActionGroupKey(  deviceNodeMap.GetNode( "ActionGroupKey"  ) );
            GenApi::CIntegerPtr ptrActionGroupMask( deviceNodeMap.GetNode( "ActionGroupMask" ) ); 
            GenApi::CIntegerPtr ptrActionSelector(  deviceNodeMap.GetNode( "ActionSelector"  ) );

            if (! GenApi::IsAvailable(ptrActionDeviceKey) ||
                ! GenApi::IsAvailable(ptrActionGroupKey) ||
                ! GenApi::IsAvailable(ptrActionGroupMask) ||
                ! GenApi::IsAvailable(ptrActionSelector) )
            {
                throw RUNTIME_EXCEPTION( "Device doesn't support action commands." );
            }

            if (! GenApi::IsWritable(ptrActionDeviceKey) ||
                ! GenApi::IsWritable(ptrActionGroupKey) ||
                ! GenApi::IsWritable(ptrActionGroupMask) ||
                ! GenApi::IsWritable(ptrActionSelector) )
            {
                throw RUNTIME_EXCEPTION( "ActionCommand features are not writable." );
            }

            // Get required enumerations to configure triggering on action commands
            GenApi::CEnumerationPtr ptrTriggerSelector( deviceNodeMap.GetNode( "TriggerSelector" ) );
            GenApi::CEnumerationPtr ptrTriggerSource(   deviceNodeMap.GetNode( "TriggerSource"   ) );
            GenApi::CEnumerationPtr ptrTriggerMode(     deviceNodeMap.GetNode( "TriggerMode"     ) );

            // to use triggering we need to switch Continuous Grab
            GenApi::CEnumerationPtr ptrAcquisitionMode( deviceNodeMap.GetNode( "AcquisitionMode" ) );

            if (! GenApi::IsWritable(ptrTriggerSelector) ||
                ! GenApi::IsWritable(ptrTriggerSource) ||
                ! GenApi::IsWritable(ptrTriggerMode) )
            {
                throw RUNTIME_EXCEPTION( "Trigger nodes not writable" );
            }

            // Check the available camera trigger mode(s) 
            const String_t triggerName( "FrameStart" );
            if (!IsAvailable( ptrTriggerSelector->GetEntryByName( triggerName ) ))
            {
                throw RUNTIME_EXCEPTION( "Device does not support \"FrameStart\"" );
            }


            if (! GenApi::IsWritable(ptrAcquisitionMode) )
            {
                throw RUNTIME_EXCEPTION( "Acquisition mode not writable" );
            }


            //////////////////////////////////////////////////////////////////
            // start changing the camera configuration

            // Select the first action (usually "Action 1")
            ptrActionSelector->SetValue( ptrActionSelector->GetMin() );
            GenICam::gcstring selectedAction = gcstring( "Action" ) += ptrActionSelector->ToString();
            

            ptrActionDeviceKey->SetValue( DeviceKey );
            ptrActionGroupKey->SetValue( GroupKey );
            ptrActionGroupMask->SetValue( GroupMask );

            // The goal is to issue a trigger for each single frame. Configure the 
            // corresponding trigger mode, disable all other trigger types.
            {

                // Get all enumeration entries of Trigger Selector.
                GenApi::NodeList_t triggerSelectorEntries;
                ptrTriggerSelector->GetEntries( triggerSelectorEntries );

                // Iterate through all available trigger modes, configure the frame start 
                // trigger, disable all other trigger types.
                for (GenApi::NodeList_t::iterator it = triggerSelectorEntries.begin(); it != triggerSelectorEntries.end(); ++it) 
                {
                    // Set Trigger Mode to off if the trigger is available.
                    GenApi::CEnumEntryPtr pEntry( *it );
                    if (IsAvailable( pEntry )) 
                    {
                        String_t triggerNameOfEntry( pEntry->GetSymbolic() );
                        ptrTriggerSelector->FromString( triggerNameOfEntry );
                        if (triggerName == triggerNameOfEntry)
                        {
                            // Activate trigger.
                            ptrTriggerMode->FromString( "On" );

                            // Set the trigger source to the selected action.
                            ptrTriggerSource->FromString( selectedAction );

                        }
                        else
                        {
                            ptrTriggerMode->FromString( "Off" );
                        }
                    }
                } 
            }

            // Set acquisition mode.
            ptrAcquisitionMode->FromString( "Continuous" );
        }

    private:
        // Apply settings when the camera is opened. 
        /* virtual */ void OnOpened( CInstantCamera& camera )
        {
            try
            {
                ApplyConfiguration( camera.GetNodeMap(), m_Parameter);
            }
            catch (GenICam::GenericException& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. GenICam::GenericException caught in OnOpened method msg=%hs", e.what() );
            }
            catch (std::exception& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. std::exception caught in OnOpened method msg=%hs", e.what() );
            }
            catch (...)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. Unknown exception caught in OnOpened method." );
            }
        }

    private:
        ActionParameter m_Parameter;
    };

    /** 
     * @}
     */
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_ACTIONTRIGGERCONFIGURATION_H_4655834 */
