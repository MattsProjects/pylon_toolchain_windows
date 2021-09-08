//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief The default instant camera configuration for Baslzer blaze cameras.

    This  instant camera configuration is provided as header-only file. The code
    can be copied and modified for creating own configuration classes.
*/

#ifndef INCLUDED_BLAZEDEFAULTCONTINOUSCONFIGURATION_H_12437832
#define INCLUDED_BLAZEDEFAULTCONTINOUSCONFIGURATION_H_12437832

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <utility>
#include <pylon/InstantCamera.h>
#include <pylon/ParameterIncludes.h>
#include <pylon/ConfigurationHelper.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiGeneric
    * @{
    */

    /*!
    \class  CBlazeDefauitConfiguration
    \brief Sets a default configuration for Basler blaze cameras.

    This instant camera configuration is provided as header-only file. The code
    can be copied and modified for creating own configuration classes.
    */

    class CBlazeDefaultConfiguration : public CConfigurationEventHandler
    {
        /// Apply configuration.
        static void ApplyConfiguration(GENAPI_NAMESPACE::INodeMap& nodemap)
        {
            //Disable all trigger types.
            CConfigurationHelper::DisableAllTriggers(nodemap);

            //Enable streaming in GenDC format
            auto genDCStreamingMode = CEnumParameter(nodemap, "GenDCStreamingMode");
            if (genDCStreamingMode.IsWritable())
            {
                genDCStreamingMode.SetValue("On");
            }

            //Enable all image components, send range data as point cloud.
            auto componentSelector = CEnumParameter(nodemap, "ComponentSelector");
            auto componentEnable = CBooleanParameter(nodemap, "ComponentEnable");
            auto pixelFormat = CEnumParameter(nodemap, "PixelFormat");
            if (componentSelector.IsWritable())
            {
                std::pair<String_t, String_t> formats[]{
                    {"Range", "Coord3D_ABC32f"},
                    {"Intensity", "Mono16"},
                    {"Confidence", "Confidence16"} };
                for (const auto& format : formats)
                {
                    componentSelector.SetValue(format.first);
                    if (componentEnable.IsWritable())
                    {
                        componentEnable.SetValue(true);
                    }
                    if (pixelFormat.IsWritable())
                    {
                        pixelFormat.SetValue(format.second);
                    }
                }
            }
        }

        //Set basic camera settings.
        virtual void OnOpened(CInstantCamera& camera)
        {
            try
            {
                ApplyConfiguration(camera.GetNodeMap());
            }
            catch (const GenericException& e)
            {
                throw RUNTIME_EXCEPTION("Could not apply configuration. Pylon::GenericException caught in OnOpened method msg=%hs", e.what());
            }
            catch (const std::exception& e)
            {
                throw RUNTIME_EXCEPTION("Could not apply configuration. std::exception caught in OnOpened method msg=%hs", e.what());
            }
            catch (...)
            {
                throw RUNTIME_EXCEPTION("Could not apply configuration. Unknown exception caught in OnOpened method.");
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

#endif /* INCLUDED_BLAZEDEFAULTCONTINOUSCONFIGURATION_H_12437832 */