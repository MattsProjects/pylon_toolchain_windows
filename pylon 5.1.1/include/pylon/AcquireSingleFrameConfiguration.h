//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2018 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief An instant camera configuration for single frame acquisition.
    Use together with Pylon::CInstantCamera::GrabOne() only.
    This  instant camera configuration is provided as header-only file. The code
    can be copied and modified for creating own configuration classes.
*/

#ifndef INCLUDED_ACQUIRESINGLEFRAMECONFIGURATION_H_6529309
#define INCLUDED_ACQUIRESINGLEFRAMECONFIGURATION_H_6529309

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/InstantCamera.h>
#include <pylon/ParameterIncludes.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiGeneric
     * @{
     */

    /*!
    \class  CAcquireSingleFrameConfiguration
    \brief  An instant camera configuration for single frame acquisition, Use together with CInstantCamera::GrabOne() only.

        The %CAcquireSingleFrameConfiguration is provided as header-only file.
        The code can be copied and modified for creating own configuration classes.

        \note Grabbing single images using Software Trigger (CSoftwareTriggerConfiguration) is recommended if you want to maximize frame rate.
        This is because the overhead per grabbed image is reduced compared to Single Frame Acquisition.
        The grabbing can be started using CInstantCamera::StartGrabbing().
        Images are grabbed using the CInstantCamera::WaitForFrameTriggerReady(), CInstantCamera::ExecuteSoftwareTrigger() and CInstantCamera::RetrieveResult() methods instead of using CInstantCamera::GrabOne().
        The grab can be stopped using CInstantCamera::StopGrabbing() when done.

    */
    class CAcquireSingleFrameConfiguration : public CConfigurationEventHandler
    {
    public:
        /// Destructor
        virtual ~CAcquireSingleFrameConfiguration()
        { 
        }

        /// Apply acquire single frame configuration.
        static void ApplyConfiguration( GENAPI_NAMESPACE::INodeMap& nodemap)
        {
            using namespace GENAPI_NAMESPACE;

            //Disable all trigger types.
            {
                // Get required enumerations.
                CEnumParameter triggerSelector(nodemap, "TriggerSelector");
                CEnumParameter triggerMode(nodemap, "TriggerMode");

                if (triggerSelector.IsWritable())
                {
                    // Get all settable enumeration entries of Trigger Selector.
                    StringList_t triggerSelectorEntries;
                    triggerSelector.GetSettableValues(triggerSelectorEntries);

                    // Turn Trigger Mode off For all Trigger Selector entries.
                    for (StringList_t::const_iterator it = triggerSelectorEntries.begin(); it != triggerSelectorEntries.end(); ++it)
                    {
                        // Set Trigger Mode to off if the trigger is available.
                        triggerSelector.SetValue(*it);
                        triggerMode.SetValue("Off");
                    }
                }
            }

            //Set acquisition mode.
            CEnumParameter(nodemap, "AcquisitionMode").SetValue("SingleFrame");
        }

        //Set basic camera settings
        virtual void OnOpened( CInstantCamera& camera)
        {
            try
            {
                ApplyConfiguration( camera.GetNodeMap());
            }
            catch (const GenericException& e)
            {
                throw RUNTIME_EXCEPTION( "Could not apply configuration. Pylon::GenericException caught in OnOpened method msg=%hs", e.what());
            }
            catch (const std::exception& e)
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

#endif /* INCLUDED_ACQUIRESINGLEFRAMECONFIGURATION_H_6529309 */
