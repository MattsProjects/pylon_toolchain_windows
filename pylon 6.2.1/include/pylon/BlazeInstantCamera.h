//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Instant camera class for Basler blaze cameras.
*/

#pragma once

#pragma warning(push, 1)

#include "BlazeCameraParams.h"
#include "BlazeStreamParams.h"
#include "BlazeEventParams.h"
#include "BlazeTLParams.h"
#include "BlazeConfigurationEventHandler.h"
#include "BlazeImageEventHandler.h"
#include "BlazeCameraEventHandler.h"
#include "BlazeGrabResultPtr.h"
#include <pylon/private/DeviceSpecificInstantCamera.h>
#include <pylon/gige/PylonGigEDevice.h>
#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>
#include <Base/GCException.h>
#include "BlazeDefaultConfiguration.h"

#pragma warning(pop)

namespace Pylon
{
    class CBlazeInstantCamera;

    /// Lists all the types used by the CBlazeInstantCamera camera class.
    struct BlazeTraits
    {
        /// The type of the final camera class.
        typedef CBlazeInstantCamera InstantCamera_t;
        /// \copybrief BlazeCameraParams_Params::BlazeCameraParams
        typedef BlazeCameraParams_Params::BlazeCameraParams CameraParams_t;
        /// \copybrief Pylon::IPylonDevice
        typedef IPylonDevice IPylonDevice_t;
        /// \copybrief Pylon::CDeviceInfo
        typedef Pylon::CDeviceInfo DeviceInfo_t;
        /// \copybrief BlazeTLParams_Params::BlazeTLParams
        typedef CNodeMapProxyT<BlazeTLParams_Params::BlazeTLParams> TlParams_t;
        /// The parameters of the stream grabber.
        typedef CNodeMapProxyT<BlazeStreamParams_Params::BlazeStreamParams> StreamGrabberParams_t;
        /// The parameters of the event grabber.
        typedef CNodeMapProxyT<BlazeEventParams_Params::BlazeEventParams> EventGrabberParams_t;
        /// The configuration event handler class.
        typedef CBlazeConfigurationEventHandler ConfigurationEventHandler_t;
        /// The image event handler class.
        typedef CBlazeImageEventHandler ImageEventHandler_t;
        /// The camera event handler class.
        typedef CBlazeCameraEventHandler CameraEventHandler_t;
        /// The grab result data.
        typedef BlazeGrabResultData GrabResultData_t;
        /// The grab result smart pointer.
        typedef BlazeGrabResultPtr GrabResultPtr_t;
        
        //! Can be used to check whether the DeviceClass() can be used for enumeration.
        static bool HasSpecificDeviceClass() { return true; }
        //! The name of this device class. Use this one for enumeration.
        static String_t DeviceClass() { return BaslerGenTlBlazeDeviceClass; }
    };

    /*!
    \class  CBlazeInstantCamera
    \brief  Extends the CInstantCamera by a generated parameter interface classes combining user selected sources.
    */
    class CBlazeInstantCamera : public CDeviceSpecificInstantCameraT<BlazeTraits>
    {
    public:
        /*!
            \copybrief CInstantCamera::CInstantCamera()
            \copydetails CInstantCamera::CInstantCamera
        */
        CBlazeInstantCamera()
        {
            // By registering the CBlazeDefaultConfiguration, range, intensity and confidence data will be delivered.
            // Range data is represented as point clouds.
            this->RegisterConfiguration(new CBlazeDefaultConfiguration, RegistrationMode_ReplaceAll, Cleanup_Delete);
        }

        /*!
            \copybrief CInstantCamera::CInstantCamera( IPylonDevice* , ECleanup )
            \copydetails CInstantCamera::CInstantCamera( IPylonDevice* , ECleanup )
        */
        CBlazeInstantCamera(IPylonDevice* pDevice, ECleanup cleanupProcedure = Cleanup_Delete)
            : CDeviceSpecificInstantCameraT<BlazeTraits>(pDevice, cleanupProcedure)
        {
            // By registering the CBlazeDefaultConfiguration, range, intensity and confidence data will be delivered.
            // Range data is represented as point clouds.
            this->RegisterConfiguration(new CBlazeDefaultConfiguration, RegistrationMode_ReplaceAll, Cleanup_Delete);
        }

        /*!
            \copybrief CInstantCamera::~CInstantCamera
            \copydetails CInstantCamera::~CInstantCamera
        */
        ~CBlazeInstantCamera()
        {
            Attach( NULL);
            InternalShutdownEventHandlers();
        }

        /*!
        \brief Enables/disables use of persistent IP address and DHCP usage of the attached %Pylon Device.

        See Pylon::IPylonGigEDevice::ChangeIpConfiguration()

        \pre
        <ul>
        <li> A %Pylon Device is attached.
        <li> The %Pylon Device is open.
        </ul>

        \error
            The Instant Camera object is still valid after error.

        \threading
            This method is synchronized using the lock provided by GetLock().
        */
        void ChangeIpConfiguration( bool EnablePersistentIp, bool EnableDhcp )
        {
            AutoLock lock( CInstantCamera::GetLock());
            GetGigEDevice()->ChangeIpConfiguration( EnablePersistentIp, EnableDhcp );
        }

        /*!
        \brief Reads the persistent IP address from the attached %Pylon Device.

        See Pylon::IPylonGigEDevice::GetPersistentIpAddress()

        \pre
        <ul>
        <li> A %Pylon Device is attached.
        <li> The %Pylon Device is open.
        </ul>
        \error
            The Instant Camera object is still valid after error.

        \threading
            This method is synchronized using the lock provided by GetLock().
        */
        void GetPersistentIpAddress(String_t& IpAddress, String_t& SubnetMask, String_t& DefaultGateway)
        {
            AutoLock lock( CInstantCamera::GetLock());
            GetGigEDevice()->GetPersistentIpAddress( IpAddress, SubnetMask, DefaultGateway );
        }

        /*!
        \brief Writes a persistent IP address to the attached %Pylon Device.

        See Pylon::IPylonGigEDevice::SetPersistentIpAddress()

        \pre
        <ul>
        <li> A %Pylon Device is attached.
        <li> The %Pylon Device is open.
        </ul>
        \error
            The Instant Camera object is still valid after error.

        \threading
            This method is synchronized using the lock provided by GetLock().
        */
        void SetPersistentIpAddress(const String_t& IpAddress,
            const String_t& SubnetMask,
            const String_t& DefaultGateway)

        {
            AutoLock lock( CInstantCamera::GetLock());
            GetGigEDevice()->SetPersistentIpAddress( IpAddress, SubnetMask, DefaultGateway );
        }

    protected:
        //Get the pointer for the GigE device.
        virtual IPylonGigEDevice* GetGigEDevice()
        {
            IPylonDevice* pDevice = CInstantCamera::GetDevice();
            IPylonGigEDevice* pGigEDevice = dynamic_cast<IPylonGigEDevice*>(pDevice);

            // Check whether device type matches camera type.
            if ( !pGigEDevice )
            {
                throw LOGICAL_ERROR_EXCEPTION("The attached pylon device type must be a GigE device.");
            }

            return pGigEDevice;
        }

        //Create device grab result data. Is subject to change without notice.
        virtual CGrabResultData* CreateDeviceSpecificGrabResultData()
        {
            return new GrabResultData_t();
        }
    };

} // namespace Pylon
