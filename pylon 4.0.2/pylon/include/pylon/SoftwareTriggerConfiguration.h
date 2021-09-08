//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (C) 2010-2013 Basler
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief An instant camera configuration for software trigger,
       Use togehter with Pylon::CInstantCamera::WaitForFrameTriggerReady() and Pylon::CInstantCamera::ExecuteSoftwareTrigger().
*/

#ifndef INCLUDED_SOFTWARETRIGGERCONFIGURATION_H_4655834
#define INCLUDED_SOFTWARETRIGGERCONFIGURATION_H_4655834

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/InstantCamera.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiGeneric
     * @{
     */

    /*!
    \class  CSoftwareTriggerConfiguration
    \brief  Changes the configuration of the camera so that it is triggered by software trigger.
            Use togehter with CInstantCamera::WaitForFrameTriggerReady() and CInstantCamera::ExecuteSoftwareTrigger().
    */
    class CSoftwareTriggerConfiguration : public CConfigurationEventHandler
    {
    public:
        /// Apply software trigger configuration.
        static void ApplyConfiguration( GenApi::INodeMap& nodemap)
        {
            using namespace GenApi;

            //Disable all trigger types.
            {
                // Get required enumerations.
                CEnumerationPtr triggerSelector( nodemap.GetNode("TriggerSelector"));
                CEnumerationPtr triggerMode( nodemap.GetNode("TriggerMode"));

                // Check the available camera trigger mode(s) to select the appropriate one: acquisition start trigger mode 
                // (used by previous cameras, i.e. for cameras supporting only the legacy image acquisition control mode;
                // do not confuse with acquisition start command) or frame start trigger mode
                // (used by newer cameras, i.e.for cameras using the standard image acquisition control mode;
                // equivalent to the acquisition start trigger mode in the legacy image acquisition control mode).
                String_t triggerName( "FrameStart");
                if ( !IsAvailable( triggerSelector->GetEntryByName(triggerName)))
                {
                    triggerName = "AcquisitionStart";
                    if ( !IsAvailable( triggerSelector->GetEntryByName(triggerName)))
                    {
                        throw RUNTIME_EXCEPTION( "Could not select trigger. Neither FrameStart nor AcquisitionStart is available.");
                    }
                }

                // Get all enumeration entries of Trigger Selector.
                GenApi::NodeList_t triggerSelectorEntries;
                triggerSelector->GetEntries( triggerSelectorEntries );

                // Turn Trigger Mode off For all Trigger Selector entries.
                for ( GenApi::NodeList_t::iterator it = triggerSelectorEntries.begin(); it != triggerSelectorEntries.end(); ++it) 
                {
                    // Set Trigger Mode to off if the trigger is available.
                    GenApi::CEnumEntryPtr pEntry(*it);
                    if ( IsAvailable( pEntry)) 
                    {
                        String_t triggerNameOfEntry( pEntry->GetSymbolic());
                        triggerSelector->FromString( triggerNameOfEntry);
                        if ( triggerName == triggerNameOfEntry)
                        {
                            // Activate trigger.
                            triggerMode->FromString( "On");

                            // The trigger source must be set to 'Software'.
                            CEnumerationPtr(nodemap.GetNode("TriggerSource"))->FromString("Software");

                            //// Alternative hardware trigger configuration:
                            //// This configuration can be copied and modified to create a hardware trigger configuration.
                            //// Remove setting the 'TriggerSource' to 'Software' (see above) and 
                            //// use the commented lines as a starting point.
                            //// The camera user's manual contains more information about available configurations.
                            //// The pylon Viewer tool can be used to test the selected settings first.

                            //// The trigger source must be set to the trigger input, e.g. 'Line1'.
                            //CEnumerationPtr(nodemap.GetNode("TriggerSource"))->FromString("Line1");

                            ////The trigger activation must be set to e.g. 'RisingEdge'.
                            //CEnumerationPtr(nodemap.GetNode("TriggerActivation"))->FromString("RisingEdge");
                        }
                        else
                        {
                            triggerMode->FromString( "Off");
                        }
                    }
                } 
            }

            //Set acquisition mode.
            CEnumerationPtr(nodemap.GetNode("AcquisitionMode"))->FromString("Continuous");
        }

        //Set basic camera settings
        virtual void OnOpened( CInstantCamera& camera)
        {
            try
            {
                ApplyConfiguration( camera.GetNodeMap());
            }
            catch (GenICam::GenericException& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. GenICam::GenericException caught in OnOpened method msg=%hs", e.what());
            }
            catch (std::exception& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. std::exception caught in OnOpened method msg=%hs", e.what());
            }
            catch (...)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. Unknown exception caught in OnOpened method.");
            }
        }
    };

    /** 
     * @}
     */
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* INCLUDED_SOFTWARETRIGGERCONFIGURATION_H_4655834 */
