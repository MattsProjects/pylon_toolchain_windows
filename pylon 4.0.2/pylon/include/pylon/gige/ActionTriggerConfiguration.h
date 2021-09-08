//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2010-2013 Basler
//  http://www.baslerweb.com
//  Author: Hartmut Nebelung
//-----------------------------------------------------------------------------
/*!
\file
\brief An instant camera configuration for triggering via GigE Vision action commands.
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
    const uint32_t DefaultDeviceKey(0x34638452);
    const uint32_t DefaultGroupKey(0x24);
    const uint32_t AnyGroupMask(0xffffffff);

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

    */
    class CActionTriggerConfiguration : public CConfigurationEventHandler
    {
    public:
        struct Parameter
        {
            uint32_t DeviceKey;
            uint32_t GroupKey;
            uint32_t GroupMask;
        };

        // constructors and assignment
        CActionTriggerConfiguration( uint32_t DeviceKey, uint32_t GroupKey, uint32_t GroupMask=AnyGroupMask )
        {
            m_Parameter.DeviceKey = DeviceKey;
            m_Parameter.GroupKey = GroupKey;
            m_Parameter.GroupMask = GroupMask;
        }
        CActionTriggerConfiguration( const Parameter& p )
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
        static void ApplyConfiguration( GenApi::INodeMap& deviceNodeMap, const Parameter& p )
        {
            ApplyConfiguration( deviceNodeMap, p.DeviceKey, p.GroupKey, p.GroupMask );
        }
        /// Apply action trigger configuration to a given camera device node map.
        static void ApplyConfiguration( GenApi::INodeMap& deviceNodeMap, uint32_t DeviceKey, uint32_t GroupKey, uint32_t GroupMask = AnyGroupMask )
        {
            using namespace GenApi;


            GenApi::CCategoryPtr ptrActionCategory = deviceNodeMap.GetNode( "ActionControl" );
            if (! GenApi::IsAvailable( ptrActionCategory ))
            {
                throw RUNTIME_EXCEPTION( "Device doesn't support action commands (could not find category \"ActionControl\"." );
            }

            GenApi::CIntegerPtr ptrActionSelector(deviceNodeMap.GetNode( "ActionSelector" ) );
            
            // Select the first action (usually "Action 1")
            ptrActionSelector->SetValue( ptrActionSelector->GetMin() );
            GenICam::gcstring selectedAction = gcstring( "Action" ) += ptrActionSelector->ToString();
            

            GenApi::CIntegerPtr( deviceNodeMap.GetNode( "ActionDeviceKey" ) )->SetValue( DeviceKey );
            GenApi::CIntegerPtr( deviceNodeMap.GetNode( "ActionGroupKey" ) )->SetValue( GroupKey );
            GenApi::CIntegerPtr( deviceNodeMap.GetNode( "ActionGroupMask" ) )->SetValue( GroupMask );

            // The goal is to issue a trigger for each single frame. Configure the 
            // corresponding trigger mode, disable all other trigger types.
            {

                // Get required enumerations.
                CEnumerationPtr triggerSelector( deviceNodeMap.GetNode( "TriggerSelector" ) );
                CEnumerationPtr triggerMode( deviceNodeMap.GetNode( "TriggerMode" ) );

                // Check the available camera trigger mode(s) 
                const String_t triggerName( "FrameStart" );
                if (!IsAvailable( triggerSelector->GetEntryByName( triggerName ) ))
                {
                    throw RUNTIME_EXCEPTION( "Device does not support \"FrameStart\"" );
                }

                // Get all enumeration entries of Trigger Selector.
                GenApi::NodeList_t triggerSelectorEntries;
                triggerSelector->GetEntries( triggerSelectorEntries );

                // Iterate through all available trigger modes, configure the frame start 
                // trigger, disable all other trigger types.
                for (GenApi::NodeList_t::iterator it = triggerSelectorEntries.begin(); it != triggerSelectorEntries.end(); ++it) 
                {
                    // Set Trigger Mode to off if the trigger is available.
                    GenApi::CEnumEntryPtr pEntry( *it );
                    if (IsAvailable( pEntry )) 
                    {
                        String_t triggerNameOfEntry( pEntry->GetSymbolic() );
                        triggerSelector->FromString( triggerNameOfEntry );
                        if (triggerName == triggerNameOfEntry)
                        {
                            // Activate trigger.
                            triggerMode->FromString( "On" );

                            // Set the trigger source to the selected action.
                            CEnumerationPtr( deviceNodeMap.GetNode( "TriggerSource" ) )->FromString( selectedAction );

                        }
                        else
                        {
                            triggerMode->FromString( "Off" );
                        }
                    }
                } 
            }

            //Set acquisition mode.
            CEnumerationPtr( deviceNodeMap.GetNode( "AcquisitionMode" ) )->FromString( "Continuous" );
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
        Parameter m_Parameter;
    };

    /** 
     * @}
     */
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_ACTIONTRIGGERCONFIGURATION_H_4655834 */
