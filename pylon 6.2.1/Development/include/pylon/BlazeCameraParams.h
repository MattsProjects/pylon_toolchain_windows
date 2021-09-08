//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2020 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for blaze-101

blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_BLAZECAMERAPARAMS_H
#define BASLER_PYLON_BLAZECAMERAPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for blaze-101
namespace Pylon
{
namespace BlazeCameraParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_Continuous  //!< Frames are captured continuously until stopped with the AcquisitionStop command - Applies to: blaze-101
    };

    //! Valid values for ComponentSelector
    enum ComponentSelectorEnums
    {
        ComponentSelector_Confidence,  //!< The acquisition of confidence map of the acquired image is controlled - Applies to: blaze-101
        ComponentSelector_Intensity,  //!< The acquisition of intensity (monochrome or color) of the visible reflected light is controlled - Applies to: blaze-101
        ComponentSelector_Range  //!< The acquisition of range (distance) data is controlled - Applies to: blaze-101
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!< 2D sensor - Applies to: blaze-101
        DeviceScanType_Areascan3D,  //!< Device outputs 2D range image - Applies to: blaze-101
        DeviceScanType_Linescan,  //!< 1D sensor - Applies to: blaze-101
        DeviceScanType_Linescan3D  //!< Device outputs 1D range image - Applies to: blaze-101
    };

    //! Valid values for DeviceTemperatureSelector
    enum DeviceTemperatureSelectorEnums
    {
        DeviceTemperatureSelector_CPU,  //!< Temperature of the device's CPU - Applies to: blaze-101
        DeviceTemperatureSelector_Illumination,  //!< Temperature of the device's illumination board - Applies to: blaze-101
        DeviceTemperatureSelector_Sensorboard  //!< Temperature of the device's sensor board - Applies to: blaze-101
    };

    //! Valid values for DeviceType
    enum DeviceTypeEnums
    {
        DeviceType_Peripheral,  //!< Controllable device (with no data stream handling) - Applies to: blaze-101
        DeviceType_Receiver,  //!< Data stream receiver device - Applies to: blaze-101
        DeviceType_Transceiver,  //!< Data stream receiver and transmitter device - Applies to: blaze-101
        DeviceType_Transmitter  //!< Data stream transmitter device - Applies to: blaze-101
    };

    //! Valid values for IntensityCalculation
    enum IntensityCalculationEnums
    {
        IntensityCalculation_Method1,  //!< Method 1 is used to calculate the intensity image - Applies to: blaze-101
        IntensityCalculation_Method2  //!< Method 2 is used to calculate the intensity image   - Applies to: blaze-101
    };

    //! Valid values for LastError
    enum LastErrorEnums
    {
        LastError_Illumination,  //!< Indicates a problem with the VCSELs - Applies to: blaze-101
        LastError_NoError,  //!< Indicates that no error was detected - Applies to: blaze-101
        LastError_OverTemperature,  //!< The over temperature state has been detected - Applies to: blaze-101
        LastError_OverTrigger  //!< The over trigger state has been detected - Applies to: blaze-101
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_Todo  //!< TODO - Applies to: blaze-101
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!< The selected physical line is used to Input an electrical signal - Applies to: blaze-101
        LineMode_Output  //!< The selected physical line is used to Output an electrical signal - Applies to: blaze-101
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line0,  //!< Index of the physical line and associated I/O control block to use - Applies to: blaze-101
        LineSelector_Line1  //!< Index of the physical line and associated I/O control block to use - Applies to: blaze-101
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_Todo  //!< TODO - Applies to: blaze-101
    };

    //! Valid values for OperatingMode
    enum OperatingModeEnums
    {
        OperatingMode_LongRange,  //!< The operating mode is set to Long Range - Applies to: blaze-101
        OperatingMode_ShortRange  //!< The operating mode is set to Short Range - Applies to: blaze-101
    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_Confidence16,  //!< Confidence 16-bit - Applies to: blaze-101
        PixelFormat_Confidence8,  //!< Confidence 8-bit - Applies to: blaze-101
        PixelFormat_Coord3D_ABC32f,  //!< 3D coordinate A-B-C 32-bit floating point - Applies to: blaze-101
        PixelFormat_Coord3D_C16,  //!< 3D coordinate C 16-bit - Applies to: blaze-101
        PixelFormat_Mono12,  //!< Monochrome 12-bit unpacked - Applies to: blaze-101
        PixelFormat_Mono16,  //!< Monochrome 16-bit - Applies to: blaze-101
        PixelFormat_Mono8,  //!< Monochrome 8-bit - Applies to: blaze-101
        PixelFormat_RGB8  //!< Red-Green-Blue 8-bit - Applies to: blaze-101
    };

    //! Valid values for PtpStatus
    enum PtpStatusEnums
    {
        PtpStatus_Disabled,  //!< Disabled - Applies to: blaze-101
        PtpStatus_Faulty,  //!< Faulty - Applies to: blaze-101
        PtpStatus_Initializing,  //!< Initializing - Applies to: blaze-101
        PtpStatus_Listening,  //!< Listening - Applies to: blaze-101
        PtpStatus_Master,  //!< Master - Applies to: blaze-101
        PtpStatus_Passive,  //!< Passive - Applies to: blaze-101
        PtpStatus_PreMaster,  //!< Pre Master - Applies to: blaze-101
        PtpStatus_Slave,  //!< Slave - Applies to: blaze-101
        PtpStatus_Uncalibrated  //!< Uncalibrated - Applies to: blaze-101
    };

    //! Valid values for Scan3dCoordinateSelector
    enum Scan3dCoordinateSelectorEnums
    {
        Scan3dCoordinateSelector_CoordinateA,  //!< The first (X or Theta) coordinate - Applies to: blaze-101
        Scan3dCoordinateSelector_CoordinateB,  //!< The second (Y or Phi) coordinate - Applies to: blaze-101
        Scan3dCoordinateSelector_CoordinateC  //!< The third (Z or Rho) coordinate - Applies to: blaze-101
    };

    //! Valid values for Scan3dCoordinateSystem
    enum Scan3dCoordinateSystemEnums
    {
        Scan3dCoordinateSystem_Cartesian  //!< Default value - Applies to: blaze-101
    };

    //! Valid values for Scan3dCoordinateSystemReference
    enum Scan3dCoordinateSystemReferenceEnums
    {
        Scan3dCoordinateSystemReference_Anchor  //!< Default value - Applies to: blaze-101
    };

    //! Valid values for Scan3dDistanceUnit
    enum Scan3dDistanceUnitEnums
    {
        Scan3dDistanceUnit_DeviceSpecific,  //!< Distance values are in device-specific units - Applies to: blaze-101
        Scan3dDistanceUnit_Millimeter  //!< Distance values are in millimeter units (default) - Applies to: blaze-101
    };

    //! Valid values for Scan3dOutputMode
    enum Scan3dOutputModeEnums
    {
        Scan3dOutputMode_CalibratedABC_Grid,  //!< 3 Coordinates in grid organization - Applies to: blaze-101
        Scan3dOutputMode_CalibratedC,  //!< Calibrated 2 5D Depth map - Applies to: blaze-101
        Scan3dOutputMode_UncalibratedC  //!< Uncalibrated 2 5D Depth map - Applies to: blaze-101
    };

    //! Valid values for TemperatureState
    enum TemperatureStateEnums
    {
        TemperatureState_Critical,  //!< The temperature is critical - Applies to: blaze-101
        TemperatureState_Error,  //!< Temperature is outside specified range - Applies to: blaze-101
        TemperatureState_Ok  //!< The temperature is normal - Applies to: blaze-101
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!< Disables the selected trigger - Applies to: blaze-101
        TriggerMode_On  //!< Enable the selected trigger - Applies to: blaze-101
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_FrameStart  //!< Selects a trigger starting the capture of one frame - Applies to: blaze-101
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Line0,  //!< Specifies which physical line (or pin) and associated I/O control block to use as external source for the trigger signal - Applies to: blaze-101
        TriggerSource_Software  //!< Specifies that the trigger source will be generated by software using the TriggerSoftware command - Applies to: blaze-101
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput0  //!< Selects the bit 0 of the User Output register - Applies to: blaze-101
    };


    
    
    //**************************************************************************************************
    // Parameter class BlazeCameraParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for blaze-101

    blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
    */
    class BlazeCameraParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BlazeCameraParams(void);

            //! Destructor
            ~BlazeCameraParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BlazeCameraParams_Data;
        BlazeCameraParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Controls the acquisition rate (in Hertz) at which the frames are captured - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionFrameRate;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Controls if the AcquisitionFrameRate feature is writable and used to control the acquisition rate - Applies to: blaze-101

        Controls if the AcquisitionFrameRate feature is writable and used to control the acquisition rate. Otherwise, the acquisition rate is implicitly controlled by the combination of other features like ExposureTime, etc...
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionFrameRateEnable;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Sets the acquisition mode of the device - Applies to: blaze-101

        Sets the acquisition mode of the device. It defines mainly the number of frames to capture during an acquisition and the way the acquisition stops.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionModeEnums>& AcquisitionMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Starts the Acquisition of the device - Applies to: blaze-101

        Starts the Acquisition of the device. The number of frames captured is specified by AcquisitionMode.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStart;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Stops the Acquisition of the device at the end of the current Frame - Applies to: blaze-101

        Stops the Acquisition of the device at the end of the current Frame. It is mainly used when AcquisitionMode is Continuous but can be used in any acquisition mode.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStop" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStop;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables the ambiguity filter - Applies to: blaze-101

        Enables the ambiguity filter. The ambiguity filter removes pixels whose depth data is ambiguous. In certain demanding scenes, e.g., because of stray light or multi-path effects, detection may fail. In this case, the filter should be disabled. The ambiguity filter is only available when the Fast Mode parameter is disabled.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AmbiguityFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AmbiguityFilter;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Strength of the ambiguity filter - Applies to: blaze-101

        Strength of the ambiguity filter. The higher the value, the stronger the filter. Higher values increase the reliablity of the filter.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AmbiguityFilterThreshold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AmbiguityFilterThreshold;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Clears the last error - Applies to: blaze-101

        Clears the last error. If a previous error exists, the previous error can still be retrieved.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ClearLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ClearLastError;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Controls if the selected component streaming is active - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: ComponentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ComponentEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ComponentEnable;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Selects a component to activate/deactivate its data streaming - Applies to: blaze-101

    
        Visibility: Beginner

        Selecting Parameters: PixelFormat and ComponentEnable

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ComponentSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ComponentSelectorEnums>& ComponentSelector;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Confidence threshold for pixels - Applies to: blaze-101

        Confidence threshold for pixels. Pixels have to exceed the confidence value specified here in order to be taken into account for the distance measurement. The threshold value is based on the gray values of the confidence map.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ConfidenceThreshold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ConfidenceThreshold;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief End of the three-dimensional ROI - Applies to: blaze-101

        The Minimum Depth and the Maximum Depth parameters together define the desired three-dimensional ROI. In the point cloud display, points outside the ROI will be ignored. When using the Mono16 or RGB8 pixel formats, points in front of the ROI receive the minimum distance value, while points beyond the ROI receive the maximum distance value.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DepthMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DepthMax;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Start of the three-dimensional ROI - Applies to: blaze-101

        The Minimum Depth and the Maximum Depth parameters together define the desired three-dimensional ROI. In the point cloud display, points outside the ROI will be ignored. When using the Mono16 or RGB8 pixel formats, points in front of the ROI receive the minimum distance value, while points beyond the ROI receive the maximum distance value.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DepthMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DepthMin;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the number of event channels supported by the device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceEventChannelCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceEventChannelCount;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Identifier of the product family of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceFamilyName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceFamilyName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Version of the firmware in the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceFirmwareVersion;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Returns the number of physical connection of the device used by a particular Link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkConnectionCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkConnectionCount;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Selects which Link of the device to control - Applies to: blaze-101

    
        Visibility: Beginner

        Selecting Parameters: DeviceLinkConnectionCount

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Manufacturer information about the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceManufacturerInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceManufacturerInfo;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Model of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceModelName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Resets the device to its power up state - Applies to: blaze-101

        Resets the device to its power up state. After reset, the device must be rediscovered.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceReset;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Major version of the Standard Features Naming Convention that was used to create the device's GenICam XML - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMajor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Minor version of the Standard Features Naming Convention that was used to create the device's GenICam XML - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Sub minor version of Standard Features Naming Convention that was used to create the device's GenICam XML - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionSubMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionSubMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Scan type of the sensor of the device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceScanType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceScanTypeEnums>& DeviceScanType;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Device's serial number - Applies to: blaze-101

        Device's serial number. This string is a unique identifier of the device.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSerialNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceSerialNumber;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the number of streaming channels supported by the device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceStreamChannelCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceStreamChannelCount;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Major version of the Transport Layer of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTLVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceTLVersionMajor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Minor version of the Transport Layer of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTLVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceTLVersionMinor;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Device temperature in degrees Celsius (C) - Applies to: blaze-101

        Device temperature in degrees Celsius (C). It is measured at the location selected by DeviceTemperatureSelector.
    
        Visibility: Expert

        Selected by: DeviceTemperatureSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& DeviceTemperature;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Selects the location within the device, where the temperature will be measured - Applies to: blaze-101

    
        Visibility: Expert

        Selecting Parameters: DeviceTemperature

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperatureSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceTemperatureSelectorEnums>& DeviceTemperatureSelector;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Returns the device type - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceTypeEnums>& DeviceType;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief User-programmable device identifier - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceUserID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceUserID;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Name of the manufacturer of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVendorName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVendorName;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Version of the device - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVersion;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Exposure time of the camera - Applies to: blaze-101

        Exposure time of the camera. This controls for how long the photosensitive cells are exposed to light. If the operating mode is changed, the exposure time is set to the recommended default value. Reducing the exposure time may reduce measurement accuracy and is only recommended when the image is overexposed.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTime;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Enables the fast mode - Applies to: blaze-101

        The fast mode can be used to achieve the maximum frame rate, but this reduces image quality and measurement accuracy. 
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FastMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& FastMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Total time required for exposing and reading out all subframes from the sensor - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameDuration;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables gamma correction on the intensity image - Applies to: blaze-101

        A nonlinear operation to lighten the dark regions of the image.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GammaCorrection" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GammaCorrection;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Generates a file with diagnostic information - Applies to: blaze-101

        Generates a file with diagnostic information. The file is called DiagnosticInfo.tar.gz and it is placed on a web server. If you experience problems with the camera, execute this command and download the DiagnosticInfo.tar.gz file from http://camera-ip:8080/. Please include this file if you contact Basler support.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GenerateDiagnosticInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GenerateDiagnosticInfo;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Reports the default gateway IP address of the given logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentDefaultGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentDefaultGateway;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Reports the IP address for the given logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentIPAddress;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Controls whether the DHCP IP configuration scheme is activated on the given logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPConfigurationDHCP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevCurrentIPConfigurationDHCP;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Controls whether the Link Local Address IP configuration scheme is activated on the given logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPConfigurationLLA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevCurrentIPConfigurationLLA;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Controls whether the PersistentIP configuration scheme is activated on the given logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPConfigurationPersistentIP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevCurrentIPConfigurationPersistentIP;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Reports the subnet mask of the given logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentSubnetMask;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Selects which logical link to control - Applies to: blaze-101

    
        Visibility: Beginner

        Selecting Parameters: GevMACAddress, GevCurrentIPConfigurationLLA, GevCurrentIPConfigurationDHCP, GevCurrentIPConfigurationPersistentIP, GevCurrentIPAddress, GevCurrentSubnetMask, GevCurrentDefaultGateway, GevPersistentIPAddress, GevPersistentSubnetMask and GevPersistentDefaultGateway

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevInterfaceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevInterfaceSelector;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief MAC address of the logical link - Applies to: blaze-101

    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevMACAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevMACAddress;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Controls the persistent default gateway for this logical link - Applies to: blaze-101

        Controls the persistent default gateway for this logical link. It is only used when the device boots with the Persistent IP configuration scheme.
    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentDefaultGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentDefaultGateway;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Controls the Persistent IP address for this logical link - Applies to: blaze-101

        Controls the Persistent IP address for this logical link. It is only used when the device boots with the Persistent IP configuration scheme.
    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentIPAddress;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Controls the Persistent subnet mask associated with the Persistent IP address on this logical link - Applies to: blaze-101

        Controls the Persistent subnet mask associated with the Persistent IP address on this logical link. It is only used when the device boots with the Persistent IP configuration scheme.
    
        Visibility: Beginner

        Selected by: GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentSubnetMask;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief This GigE Vision specific feature corresponds to DeviceStreamChannelPacketSize and should be kept in sync with it - Applies to: blaze-101

        This GigE Vision specific feature corresponds to DeviceStreamChannelPacketSize and should be kept in sync with it. It specifies the stream packet size, in bytes, to send on the selected channel for a GVSP transmitter or specifies the maximum packet size supported by a GVSP receiver.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSPacketSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPSPacketSize;

    //@}


    //! \name Categories: GigEVision
    //@{
    /*!
        \brief Number of timestamp clock ticks in 1 second - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampTickFrequency" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevTimestampTickFrequency;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Height of the image provided by the device (in pixels) - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Height" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Height;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Maximum height of the image (in pixels) - Applies to: blaze-101

        Maximum height of the image (in pixels). This dimension is calculated after vertical binning, decimation or any other function changing the vertical dimension of the image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=HeightMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& HeightMax;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Sets the method for calculating the intensity data - Applies to: blaze-101

        Sets the method for calculating the intensity data. The intensity calculation is available only if the Operating Mode parameter is set to Long Range and the Fast Mode parameter is disabled.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=IntensityCalculation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<IntensityCalculationEnums>& IntensityCalculation;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the last error code in the memory - Applies to: blaze-101

        Indicates the last error code in the memory. To delete the last error code from the list of error codes, use the ClearLastError command.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LastErrorEnums>& LastError;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Controls the current electrical format of the selected physical input or output Line - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineFormatEnums>& LineFormat;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Controls the inversion of the signal of the selected input or output Line - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineInverter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineInverter;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Controls if the physical Line is used to Input or Output a signal - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineModeEnums>& LineMode;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Selects the physical line (or pin) of the external device connector or the virtual line of the Transport Layer to configure - Applies to: blaze-101

    
        Visibility: Expert

        Selecting Parameters: LineFormat, LineSource, LineStatus, LineInverter and LineMode

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSelectorEnums>& LineSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Selects which internal acquisition or I/O source signal to output on the selected Line - Applies to: blaze-101

        Selects which internal acquisition or I/O source signal to output on the selected Line. LineMode must be Output.
    
        Visibility: Expert

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSourceEnums>& LineSource;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Returns the current status of the selected input or output Line - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineStatus;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Operating channel of the camera - Applies to: blaze-101

        Operating channel of the camera. In multi-camera setups, use a different channel on each camera. This ensures that the cameras are operating at different frequencies and their light sources will not interfere with the other cameras' light sources.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MultiCameraChannel" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MultiCameraChannel;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Horizontal offset from the origin to the region of interest (in pixels) - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetX;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Vertical offset from the origin to the region of interest (in pixels) - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetY;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Sets the operating mode of the camera - Applies to: blaze-101

        Sets the operating mode of the camera. The choice you make here, affects the working range of the camera, i.e., the Minimum Working Range and Maximum Working Range parameters. If the operating mode is changed, the exposure time is set to the recommended default value.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OperatingMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<OperatingModeEnums>& OperatingMode;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables the outlier removal filter - Applies to: blaze-101

        Enables the outlier removal filter. The outlier removal filter pixels that differ significantly from their local environment.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OutlierRemoval" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& OutlierRemoval;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Strength of the outlier removal filter - Applies to: blaze-101

        Strength of the outlier removal filter. The higher the value, the more outliers will be removed.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OutlierRemovalThreshold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OutlierRemovalThreshold;

    //@}


    //! \name Categories: TransportLayerControl
    //@{
    /*!
        \brief Provides the number of bytes transferred for each image or chunk on the stream channel - Applies to: blaze-101

        Provides the number of bytes transferred for each image or chunk on the stream channel. This includes any end-of-line, end-of-frame statistics or other stamp data. This is the total size of data payload for a data block.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadSize;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Format of the pixels provided by the device - Applies to: blaze-101

        Format of the pixels provided by the device. It represents all the information provided by PixelSize, PixelColorFilter combined in a single feature.
    
        Visibility: Beginner

        Selected by: ComponentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelFormatEnums>& PixelFormat;

    //@}


    //! \name Categories: PtpControl
    //@{
    /*!
        \brief Latches the current values from the device's PTP clock data set - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PtpDataSetLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& PtpDataSetLatch;

    //@}


    //! \name Categories: PtpControl
    //@{
    /*!
        \brief Enables the Precision Time Protocol (PTP) - Applies to: blaze-101

        Enables the Precision Time Protocol (PTP). The PTP settings can only be changed if no image acquisition is in progress.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PtpEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& PtpEnable;

    //@}


    //! \name Categories: PtpControl
    //@{
    /*!
        \brief Returns the latched offset from the PTP master clock in nanoseconds - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PtpOffsetFromMaster" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PtpOffsetFromMaster;

    //@}


    //! \name Categories: PtpControl
    //@{
    /*!
        \brief Returns the latched state of the PTP clock - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PtpStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PtpStatusEnums>& PtpStatus;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Time required for reading out each subframe from the sensor - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReadoutTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ReadoutTime;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Time during which the sensor is reset before the next subframe is acquired - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResetTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ResetTime;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Maximum valid transmitted coordinate value of the selected Axis - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: Scan3dCoordinateSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dAxisMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dAxisMax;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Minimum valid transmitted coordinate value of the selected Axis - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: Scan3dCoordinateSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dAxisMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dAxisMin;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Adds an offset to the measured distance - Applies to: blaze-101

        This parameter allows you to adjust
  the internal camera calibration.
  The offset specified by Scan3dCalibrationOffset is added to the radial 
  distances the camera measures.
  The camera transforms the radial distances into x, y, z coordinates in a 
  Cartesian coordinate system whose origin lies in the camera's optical center.
  The Scan3dCalibrationOffset parameter can be used to manually correct a
  temperature-dependent drift.
  Note: Since Scan3dCalibrationOffset is added to the radial distances, it can't
  be used to translate the origin of the coordinate system, i.e., it can't be
  used to add a constant offset to the z coordinate.
  Specifically, you should not use it in an attempt to shift the origin of the
  camera's coordinate system from the optical center to
  the front of the camera housing. Trying to do so will result in measurement
  errors causing planar surfaces to appear curved.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dCalibrationOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dCalibrationOffset;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Offset when transforming a pixel from relative coordinates to world coordinates - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: Scan3dCoordinateSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dCoordinateOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dCoordinateOffset;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Scale factor when transforming a pixel from relative coordinates to world coordinates - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: Scan3dCoordinateSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dCoordinateScale" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dCoordinateScale;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Selects the individual coordinates in the vectors for 3D information/transformation - Applies to: blaze-101

    
        Visibility: Expert

        Selecting Parameters: Scan3dAxisMax, Scan3dAxisMin, Scan3dInvalidDataValue, Scan3dInvalidDataFlag, Scan3dCoordinateOffset and Scan3dCoordinateScale

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dCoordinateSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<Scan3dCoordinateSelectorEnums>& Scan3dCoordinateSelector;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Specifies the Coordinate system to use for the device - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dCoordinateSystem" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<Scan3dCoordinateSystemEnums>& Scan3dCoordinateSystem;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Defines coordinate system reference location - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dCoordinateSystemReference" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<Scan3dCoordinateSystemReferenceEnums>& Scan3dCoordinateSystemReference;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Specifies the unit used when delivering (calibrated) distance data - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dDistanceUnit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<Scan3dDistanceUnitEnums>& Scan3dDistanceUnit;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Returns the focal length of the camera in pixel - Applies to: blaze-101

        Returns the focal length of the camera in pixel. The focal length depends on the selected region. The value of this feature takes into account horizontal binning, decimation, or any other function changing the image resolution.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dFocalLength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dFocalLength;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Enables the definition of a non-valid flag value in the data stream - Applies to: blaze-101

        Enables the definition of a non-valid flag value in the data stream. Note that the confidence output is an alternate recommended way to identify non-valid pixels. Using an Scan3dInvalidDataValue may give processing penalties due to special handling.
    
        Visibility: Expert

        Selected by: Scan3dCoordinateSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dInvalidDataFlag" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& Scan3dInvalidDataFlag;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Value which identifies a non-valid pixel if Scan3dInvalidDataFlag is enabled - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: Scan3dCoordinateSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dInvalidDataValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dInvalidDataValue;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Controls the Calibration and data organization of the device and the coordinates transmitted - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dOutputMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<Scan3dOutputModeEnums>& Scan3dOutputMode;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Returns the value of the horizontal position of the principal point, relative to the region origin, i e - Applies to: blaze-101

        Returns the value of the horizontal position of the principal point, relative to the region origin, i.e. OffsetX. The value of this feature takes into account horizontal binning, decimation, or any other function changing the image resolution.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dPrincipalPointU" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dPrincipalPointU;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Returns the value of the vertical position of the principal point, relative to the region origin, i e - Applies to: blaze-101

        Returns the value of the vertical position of the principal point, relative to the region origin, i.e. OffsetY. The value of this feature takes into account vertical binning, decimation, or any other function changing the image resolution.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Scan3dPrincipalPointV" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Scan3dPrincipalPointV;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Effective height of the sensor in pixels - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorHeight;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Physical size (pitch) in the y direction of a photo sensitive pixel unit - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorPixelHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SensorPixelHeight;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Physical size (pitch) in the x direction of a photo sensitive pixel unit - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorPixelWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SensorPixelWidth;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Distance between the sensor plane and the front of the housing - Applies to: blaze-101

        Distance between the sensor plane and the front of the housing. This value can be used to calculate the distance between the optical center and the front of the housing.
    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorPosition" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SensorPosition;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Effective width of the sensor in pixels - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorWidth;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables the spatial noise filter - Applies to: blaze-101

        Enables the spatial noise filter. The spatial noise filter uses the values of neighboring pixels to filter out noise in an image. It is based on the raw data of the image.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SpatialFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SpatialFilter;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Time that passes between triggering the camera and exposure starting - Applies to: blaze-101

    
        Visibility: Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StartupTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StartupTime;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Enables the synchronous free run mode - Applies to: blaze-101

        Enables the synchronous free run mode. If enabled, the camera will generate all required frame start or line start trigger signals internally. You don't need to apply frame start or line start trigger signals to the camera. The synchronous free run settings are only available if PTP is enabled.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SyncFreeRunTimerEnable;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief High 32 bits of the synchronous free run trigger start time - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerStartTimeHigh" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncFreeRunTimerStartTimeHigh;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Low 32 bits of the synchronous free run trigger start time - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerStartTimeLow" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncFreeRunTimerStartTimeLow;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Updates synchronous free run settings - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerUpdate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SyncFreeRunTimerUpdate;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Indicates the temperature state - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureState" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureStateEnums>& TemperatureState;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables the temporal noise filter - Applies to: blaze-101

        Enables the temporal noise filter. The temporal noise filter uses the values of the same pixel at different points in time to filter out noise in an image. It is based on the depth data of the image.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemporalFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TemporalFilter;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Strength of the temporal filter - Applies to: blaze-101

        Strength of the temporal filter. The higher the value, the stronger the filter. High values may cause motion artifacts, while low values reduce the efficacy of the filter.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemporalFilterStrength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TemporalFilterStrength;

    //@}


    //! \name Categories: ImageQualityControl
    //@{
    /*!
        \brief Enables the thermal drift correction - Applies to: blaze-101

        Activates the correction of the thermal drift.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ThermalDriftCorrection" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ThermalDriftCorrection;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Latches the current timestamp counter into TimestampLatchValue - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TimestampLatch;

    //@}


    //! \name Categories: DeviceControl
    //@{
    /*!
        \brief Returns the latched value of the timestamp counter - Applies to: blaze-101

    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatchValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimestampLatchValue;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Controls if the selected trigger is active - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerModeEnums>& TriggerMode;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Selects the type of trigger to configure - Applies to: blaze-101

    
        Visibility: Expert

        Selecting Parameters: TriggerMode, TriggerSoftware and TriggerSource

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSelectorEnums>& TriggerSelector;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Generates an internal trigger - Applies to: blaze-101

        Generates an internal trigger. TriggerSource must be set to Software.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSoftware" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TriggerSoftware;

    //@}


    //! \name Categories: AcquisitionControl
    //@{
    /*!
        \brief Specifies the internal signal or physical input Line to use as the trigger source - Applies to: blaze-101

        Specifies the internal signal or physical input Line to use as the trigger source. The selected trigger must have its TriggerMode set to On.
    
        Visibility: Expert

        Selected by: TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSourceEnums>& TriggerSource;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Selects which bit of the User Output register will be set by UserOutputValue - Applies to: blaze-101

    
        Visibility: Expert

        Selecting Parameters: UserOutputValue

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserOutputSelectorEnums>& UserOutputSelector;

    //@}


    //! \name Categories: DigitalIOControl
    //@{
    /*!
        \brief Sets the value of the bit selected by UserOutputSelector - Applies to: blaze-101

    
        Visibility: Expert

        Selected by: UserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& UserOutputValue;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Width of the image provided by the device (in pixels) - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Width" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Width;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Maximum width of the image (in pixels) - Applies to: blaze-101

        Maximum width of the image (in pixels). The dimension is calculated after horizontal binning, decimation or any other function changing the horizontal dimension of the image.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WidthMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WidthMax;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Maximum working range of the camera - Applies to: blaze-101

        Maximum working range of the camera. Beyond this, results will be ambguous.
    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WorkingRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WorkingRangeMax;

    //@}


    //! \name Categories: ImageFormatControl
    //@{
    /*!
        \brief Minimum working range of the camera - Applies to: blaze-101

    
        Visibility: Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WorkingRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WorkingRangeMin;

    //@}


    //! \name Categories: Scan3dControl
    //@{
    /*!
        \brief Distance between the origin of the z axis to the front of the camera housing - Applies to: blaze-101

        Distance between the origin of the z axis to the front of the camera housing. Due to mechanical tolerances, this offset is device-specific and needs to be taken into account when measuring absolute distances.
    
        Visibility: Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ZOffsetOriginToCameraFront" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ZOffsetOriginToCameraFront;

    //@}


        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BlazeCameraParams(BlazeCameraParams&);

            //! not implemented assignment operator
            BlazeCameraParams& operator=(BlazeCameraParams&);

        //! \endcond
    };

    //**************************************************************************************************
    // Enumeration support classes
    //**************************************************************************************************
    //! \cond HIDE_CLASS_METHODS

    ///////////////////////////////////////////////////////////////////////////
    //
    namespace EnumParameterClasses
    {
        ///////////////////////////////////////////////////////////////////////////
        //
        class AcquisitionModeEnumParameter : public Pylon::CEnumParameterT<AcquisitionModeEnums>
        {
        public:
            AcquisitionModeEnumParameter()
            {
            }

            virtual ~AcquisitionModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Continuous", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class ComponentSelectorEnumParameter : public Pylon::CEnumParameterT<ComponentSelectorEnums>
        {
        public:
            ComponentSelectorEnumParameter()
            {
            }

            virtual ~ComponentSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Confidence", 11),
                    TableItem_t("Intensity", 10),
                    TableItem_t("Range", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceScanTypeEnumParameter : public Pylon::CEnumParameterT<DeviceScanTypeEnums>
        {
        public:
            DeviceScanTypeEnumParameter()
            {
            }

            virtual ~DeviceScanTypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Areascan", 9),
                    TableItem_t("Areascan3D", 11),
                    TableItem_t("Linescan", 9),
                    TableItem_t("Linescan3D", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceTemperatureSelectorEnumParameter : public Pylon::CEnumParameterT<DeviceTemperatureSelectorEnums>
        {
        public:
            DeviceTemperatureSelectorEnumParameter()
            {
            }

            virtual ~DeviceTemperatureSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CPU", 4),
                    TableItem_t("Illumination", 13),
                    TableItem_t("Sensorboard", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class DeviceTypeEnumParameter : public Pylon::CEnumParameterT<DeviceTypeEnums>
        {
        public:
            DeviceTypeEnumParameter()
            {
            }

            virtual ~DeviceTypeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Peripheral", 11),
                    TableItem_t("Receiver", 9),
                    TableItem_t("Transceiver", 12),
                    TableItem_t("Transmitter", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class IntensityCalculationEnumParameter : public Pylon::CEnumParameterT<IntensityCalculationEnums>
        {
        public:
            IntensityCalculationEnumParameter()
            {
            }

            virtual ~IntensityCalculationEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Method1", 8),
                    TableItem_t("Method2", 8)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LastErrorEnumParameter : public Pylon::CEnumParameterT<LastErrorEnums>
        {
        public:
            LastErrorEnumParameter()
            {
            }

            virtual ~LastErrorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 4;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Illumination", 13),
                    TableItem_t("NoError", 8),
                    TableItem_t("OverTemperature", 16),
                    TableItem_t("OverTrigger", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineFormatEnumParameter : public Pylon::CEnumParameterT<LineFormatEnums>
        {
        public:
            LineFormatEnumParameter()
            {
            }

            virtual ~LineFormatEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineModeEnumParameter : public Pylon::CEnumParameterT<LineModeEnums>
        {
        public:
            LineModeEnumParameter()
            {
            }

            virtual ~LineModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Input", 6),
                    TableItem_t("Output", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineSelectorEnumParameter : public Pylon::CEnumParameterT<LineSelectorEnums>
        {
        public:
            LineSelectorEnumParameter()
            {
            }

            virtual ~LineSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line0", 6),
                    TableItem_t("Line1", 6)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class LineSourceEnumParameter : public Pylon::CEnumParameterT<LineSourceEnums>
        {
        public:
            LineSourceEnumParameter()
            {
            }

            virtual ~LineSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Todo", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class OperatingModeEnumParameter : public Pylon::CEnumParameterT<OperatingModeEnums>
        {
        public:
            OperatingModeEnumParameter()
            {
            }

            virtual ~OperatingModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("LongRange", 10),
                    TableItem_t("ShortRange", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class PixelFormatEnumParameter : public Pylon::CEnumParameterT<PixelFormatEnums>
        {
        public:
            PixelFormatEnumParameter()
            {
            }

            virtual ~PixelFormatEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 8;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Confidence16", 13),
                    TableItem_t("Confidence8", 12),
                    TableItem_t("Coord3D_ABC32f", 15),
                    TableItem_t("Coord3D_C16", 12),
                    TableItem_t("Mono12", 7),
                    TableItem_t("Mono16", 7),
                    TableItem_t("Mono8", 6),
                    TableItem_t("RGB8", 5)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class PtpStatusEnumParameter : public Pylon::CEnumParameterT<PtpStatusEnums>
        {
        public:
            PtpStatusEnumParameter()
            {
            }

            virtual ~PtpStatusEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 9;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Disabled", 9),
                    TableItem_t("Faulty", 7),
                    TableItem_t("Initializing", 13),
                    TableItem_t("Listening", 10),
                    TableItem_t("Master", 7),
                    TableItem_t("Passive", 8),
                    TableItem_t("PreMaster", 10),
                    TableItem_t("Slave", 6),
                    TableItem_t("Uncalibrated", 13)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class Scan3dCoordinateSelectorEnumParameter : public Pylon::CEnumParameterT<Scan3dCoordinateSelectorEnums>
        {
        public:
            Scan3dCoordinateSelectorEnumParameter()
            {
            }

            virtual ~Scan3dCoordinateSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CoordinateA", 12),
                    TableItem_t("CoordinateB", 12),
                    TableItem_t("CoordinateC", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class Scan3dCoordinateSystemEnumParameter : public Pylon::CEnumParameterT<Scan3dCoordinateSystemEnums>
        {
        public:
            Scan3dCoordinateSystemEnumParameter()
            {
            }

            virtual ~Scan3dCoordinateSystemEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Cartesian", 10)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class Scan3dCoordinateSystemReferenceEnumParameter : public Pylon::CEnumParameterT<Scan3dCoordinateSystemReferenceEnums>
        {
        public:
            Scan3dCoordinateSystemReferenceEnumParameter()
            {
            }

            virtual ~Scan3dCoordinateSystemReferenceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Anchor", 7)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class Scan3dDistanceUnitEnumParameter : public Pylon::CEnumParameterT<Scan3dDistanceUnitEnums>
        {
        public:
            Scan3dDistanceUnitEnumParameter()
            {
            }

            virtual ~Scan3dDistanceUnitEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("DeviceSpecific", 15),
                    TableItem_t("Millimeter", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class Scan3dOutputModeEnumParameter : public Pylon::CEnumParameterT<Scan3dOutputModeEnums>
        {
        public:
            Scan3dOutputModeEnumParameter()
            {
            }

            virtual ~Scan3dOutputModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("CalibratedABC_Grid", 19),
                    TableItem_t("CalibratedC", 12),
                    TableItem_t("UncalibratedC", 14)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TemperatureStateEnumParameter : public Pylon::CEnumParameterT<TemperatureStateEnums>
        {
        public:
            TemperatureStateEnumParameter()
            {
            }

            virtual ~TemperatureStateEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 3;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Critical", 9),
                    TableItem_t("Error", 6),
                    TableItem_t("Ok", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerModeEnumParameter : public Pylon::CEnumParameterT<TriggerModeEnums>
        {
        public:
            TriggerModeEnumParameter()
            {
            }

            virtual ~TriggerModeEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Off", 4),
                    TableItem_t("On", 3)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerSelectorEnumParameter : public Pylon::CEnumParameterT<TriggerSelectorEnums>
        {
        public:
            TriggerSelectorEnumParameter()
            {
            }

            virtual ~TriggerSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("FrameStart", 11)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class TriggerSourceEnumParameter : public Pylon::CEnumParameterT<TriggerSourceEnums>
        {
        public:
            TriggerSourceEnumParameter()
            {
            }

            virtual ~TriggerSourceEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 2;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("Line0", 6),
                    TableItem_t("Software", 9)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


        ///////////////////////////////////////////////////////////////////////////
        //
        class UserOutputSelectorEnumParameter : public Pylon::CEnumParameterT<UserOutputSelectorEnums>
        {
        public:
            UserOutputSelectorEnumParameter()
            {
            }

            virtual ~UserOutputSelectorEnumParameter()
            {
            }
        protected:
            virtual const Table_t& GetTable() const
            {
                static const size_t cItemCount = 1;
                static const TableItem_t cItems[cItemCount] =
                {
                    TableItem_t("UserOutput0", 12)
                };
                static const Table_t table(cItems, cItemCount);
                return table;
            }
        };


    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BlazeCameraParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BlazeCameraParams::BlazeCameraParams_Data
    {
    public:
        Pylon::CFloatParameter AcquisitionFrameRate;
        Pylon::CBooleanParameter AcquisitionFrameRateEnable;
        EnumParameterClasses::AcquisitionModeEnumParameter AcquisitionMode;
        Pylon::CCommandParameter AcquisitionStart;
        Pylon::CCommandParameter AcquisitionStop;
        Pylon::CBooleanParameter AmbiguityFilter;
        Pylon::CIntegerParameter AmbiguityFilterThreshold;
        Pylon::CCommandParameter ClearLastError;
        Pylon::CBooleanParameter ComponentEnable;
        EnumParameterClasses::ComponentSelectorEnumParameter ComponentSelector;
        Pylon::CIntegerParameter ConfidenceThreshold;
        Pylon::CIntegerParameter DepthMax;
        Pylon::CIntegerParameter DepthMin;
        Pylon::CIntegerParameter DeviceEventChannelCount;
        Pylon::CStringParameter DeviceFamilyName;
        Pylon::CStringParameter DeviceFirmwareVersion;
        Pylon::CIntegerParameter DeviceLinkConnectionCount;
        Pylon::CIntegerParameter DeviceLinkSelector;
        Pylon::CStringParameter DeviceManufacturerInfo;
        Pylon::CStringParameter DeviceModelName;
        Pylon::CCommandParameter DeviceReset;
        Pylon::CIntegerParameter DeviceSFNCVersionMajor;
        Pylon::CIntegerParameter DeviceSFNCVersionMinor;
        Pylon::CIntegerParameter DeviceSFNCVersionSubMinor;
        EnumParameterClasses::DeviceScanTypeEnumParameter DeviceScanType;
        Pylon::CStringParameter DeviceSerialNumber;
        Pylon::CIntegerParameter DeviceStreamChannelCount;
        Pylon::CIntegerParameter DeviceTLVersionMajor;
        Pylon::CIntegerParameter DeviceTLVersionMinor;
        Pylon::CFloatParameter DeviceTemperature;
        EnumParameterClasses::DeviceTemperatureSelectorEnumParameter DeviceTemperatureSelector;
        EnumParameterClasses::DeviceTypeEnumParameter DeviceType;
        Pylon::CStringParameter DeviceUserID;
        Pylon::CStringParameter DeviceVendorName;
        Pylon::CStringParameter DeviceVersion;
        Pylon::CFloatParameter ExposureTime;
        Pylon::CBooleanParameter FastMode;
        Pylon::CIntegerParameter FrameDuration;
        Pylon::CBooleanParameter GammaCorrection;
        Pylon::CCommandParameter GenerateDiagnosticInfo;
        Pylon::CIntegerParameter GevCurrentDefaultGateway;
        Pylon::CIntegerParameter GevCurrentIPAddress;
        Pylon::CBooleanParameter GevCurrentIPConfigurationDHCP;
        Pylon::CBooleanParameter GevCurrentIPConfigurationLLA;
        Pylon::CBooleanParameter GevCurrentIPConfigurationPersistentIP;
        Pylon::CIntegerParameter GevCurrentSubnetMask;
        Pylon::CIntegerParameter GevInterfaceSelector;
        Pylon::CIntegerParameter GevMACAddress;
        Pylon::CIntegerParameter GevPersistentDefaultGateway;
        Pylon::CIntegerParameter GevPersistentIPAddress;
        Pylon::CIntegerParameter GevPersistentSubnetMask;
        Pylon::CIntegerParameter GevSCPSPacketSize;
        Pylon::CIntegerParameter GevTimestampTickFrequency;
        Pylon::CIntegerParameter Height;
        Pylon::CIntegerParameter HeightMax;
        EnumParameterClasses::IntensityCalculationEnumParameter IntensityCalculation;
        EnumParameterClasses::LastErrorEnumParameter LastError;
        EnumParameterClasses::LineFormatEnumParameter LineFormat;
        Pylon::CBooleanParameter LineInverter;
        EnumParameterClasses::LineModeEnumParameter LineMode;
        EnumParameterClasses::LineSelectorEnumParameter LineSelector;
        EnumParameterClasses::LineSourceEnumParameter LineSource;
        Pylon::CBooleanParameter LineStatus;
        Pylon::CIntegerParameter MultiCameraChannel;
        Pylon::CIntegerParameter OffsetX;
        Pylon::CIntegerParameter OffsetY;
        EnumParameterClasses::OperatingModeEnumParameter OperatingMode;
        Pylon::CBooleanParameter OutlierRemoval;
        Pylon::CIntegerParameter OutlierRemovalThreshold;
        Pylon::CIntegerParameter PayloadSize;
        EnumParameterClasses::PixelFormatEnumParameter PixelFormat;
        Pylon::CCommandParameter PtpDataSetLatch;
        Pylon::CBooleanParameter PtpEnable;
        Pylon::CIntegerParameter PtpOffsetFromMaster;
        EnumParameterClasses::PtpStatusEnumParameter PtpStatus;
        Pylon::CIntegerParameter ReadoutTime;
        Pylon::CIntegerParameter ResetTime;
        Pylon::CFloatParameter Scan3dAxisMax;
        Pylon::CFloatParameter Scan3dAxisMin;
        Pylon::CFloatParameter Scan3dCalibrationOffset;
        Pylon::CFloatParameter Scan3dCoordinateOffset;
        Pylon::CFloatParameter Scan3dCoordinateScale;
        EnumParameterClasses::Scan3dCoordinateSelectorEnumParameter Scan3dCoordinateSelector;
        EnumParameterClasses::Scan3dCoordinateSystemEnumParameter Scan3dCoordinateSystem;
        EnumParameterClasses::Scan3dCoordinateSystemReferenceEnumParameter Scan3dCoordinateSystemReference;
        EnumParameterClasses::Scan3dDistanceUnitEnumParameter Scan3dDistanceUnit;
        Pylon::CFloatParameter Scan3dFocalLength;
        Pylon::CBooleanParameter Scan3dInvalidDataFlag;
        Pylon::CFloatParameter Scan3dInvalidDataValue;
        EnumParameterClasses::Scan3dOutputModeEnumParameter Scan3dOutputMode;
        Pylon::CFloatParameter Scan3dPrincipalPointU;
        Pylon::CFloatParameter Scan3dPrincipalPointV;
        Pylon::CIntegerParameter SensorHeight;
        Pylon::CFloatParameter SensorPixelHeight;
        Pylon::CFloatParameter SensorPixelWidth;
        Pylon::CFloatParameter SensorPosition;
        Pylon::CIntegerParameter SensorWidth;
        Pylon::CBooleanParameter SpatialFilter;
        Pylon::CIntegerParameter StartupTime;
        Pylon::CBooleanParameter SyncFreeRunTimerEnable;
        Pylon::CIntegerParameter SyncFreeRunTimerStartTimeHigh;
        Pylon::CIntegerParameter SyncFreeRunTimerStartTimeLow;
        Pylon::CCommandParameter SyncFreeRunTimerUpdate;
        EnumParameterClasses::TemperatureStateEnumParameter TemperatureState;
        Pylon::CBooleanParameter TemporalFilter;
        Pylon::CIntegerParameter TemporalFilterStrength;
        Pylon::CBooleanParameter ThermalDriftCorrection;
        Pylon::CCommandParameter TimestampLatch;
        Pylon::CIntegerParameter TimestampLatchValue;
        EnumParameterClasses::TriggerModeEnumParameter TriggerMode;
        EnumParameterClasses::TriggerSelectorEnumParameter TriggerSelector;
        Pylon::CCommandParameter TriggerSoftware;
        EnumParameterClasses::TriggerSourceEnumParameter TriggerSource;
        EnumParameterClasses::UserOutputSelectorEnumParameter UserOutputSelector;
        Pylon::CBooleanParameter UserOutputValue;
        Pylon::CIntegerParameter Width;
        Pylon::CIntegerParameter WidthMax;
        Pylon::CIntegerParameter WorkingRangeMax;
        Pylon::CIntegerParameter WorkingRangeMin;
        Pylon::CFloatParameter ZOffsetOriginToCameraFront;
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeCameraParams::BlazeCameraParams(void)
        : m_pData(new BlazeCameraParams_Data())
        , AcquisitionFrameRate(m_pData->AcquisitionFrameRate)
        , AcquisitionFrameRateEnable(m_pData->AcquisitionFrameRateEnable)
        , AcquisitionMode(m_pData->AcquisitionMode)
        , AcquisitionStart(m_pData->AcquisitionStart)
        , AcquisitionStop(m_pData->AcquisitionStop)
        , AmbiguityFilter(m_pData->AmbiguityFilter)
        , AmbiguityFilterThreshold(m_pData->AmbiguityFilterThreshold)
        , ClearLastError(m_pData->ClearLastError)
        , ComponentEnable(m_pData->ComponentEnable)
        , ComponentSelector(m_pData->ComponentSelector)
        , ConfidenceThreshold(m_pData->ConfidenceThreshold)
        , DepthMax(m_pData->DepthMax)
        , DepthMin(m_pData->DepthMin)
        , DeviceEventChannelCount(m_pData->DeviceEventChannelCount)
        , DeviceFamilyName(m_pData->DeviceFamilyName)
        , DeviceFirmwareVersion(m_pData->DeviceFirmwareVersion)
        , DeviceLinkConnectionCount(m_pData->DeviceLinkConnectionCount)
        , DeviceLinkSelector(m_pData->DeviceLinkSelector)
        , DeviceManufacturerInfo(m_pData->DeviceManufacturerInfo)
        , DeviceModelName(m_pData->DeviceModelName)
        , DeviceReset(m_pData->DeviceReset)
        , DeviceSFNCVersionMajor(m_pData->DeviceSFNCVersionMajor)
        , DeviceSFNCVersionMinor(m_pData->DeviceSFNCVersionMinor)
        , DeviceSFNCVersionSubMinor(m_pData->DeviceSFNCVersionSubMinor)
        , DeviceScanType(m_pData->DeviceScanType)
        , DeviceSerialNumber(m_pData->DeviceSerialNumber)
        , DeviceStreamChannelCount(m_pData->DeviceStreamChannelCount)
        , DeviceTLVersionMajor(m_pData->DeviceTLVersionMajor)
        , DeviceTLVersionMinor(m_pData->DeviceTLVersionMinor)
        , DeviceTemperature(m_pData->DeviceTemperature)
        , DeviceTemperatureSelector(m_pData->DeviceTemperatureSelector)
        , DeviceType(m_pData->DeviceType)
        , DeviceUserID(m_pData->DeviceUserID)
        , DeviceVendorName(m_pData->DeviceVendorName)
        , DeviceVersion(m_pData->DeviceVersion)
        , ExposureTime(m_pData->ExposureTime)
        , FastMode(m_pData->FastMode)
        , FrameDuration(m_pData->FrameDuration)
        , GammaCorrection(m_pData->GammaCorrection)
        , GenerateDiagnosticInfo(m_pData->GenerateDiagnosticInfo)
        , GevCurrentDefaultGateway(m_pData->GevCurrentDefaultGateway)
        , GevCurrentIPAddress(m_pData->GevCurrentIPAddress)
        , GevCurrentIPConfigurationDHCP(m_pData->GevCurrentIPConfigurationDHCP)
        , GevCurrentIPConfigurationLLA(m_pData->GevCurrentIPConfigurationLLA)
        , GevCurrentIPConfigurationPersistentIP(m_pData->GevCurrentIPConfigurationPersistentIP)
        , GevCurrentSubnetMask(m_pData->GevCurrentSubnetMask)
        , GevInterfaceSelector(m_pData->GevInterfaceSelector)
        , GevMACAddress(m_pData->GevMACAddress)
        , GevPersistentDefaultGateway(m_pData->GevPersistentDefaultGateway)
        , GevPersistentIPAddress(m_pData->GevPersistentIPAddress)
        , GevPersistentSubnetMask(m_pData->GevPersistentSubnetMask)
        , GevSCPSPacketSize(m_pData->GevSCPSPacketSize)
        , GevTimestampTickFrequency(m_pData->GevTimestampTickFrequency)
        , Height(m_pData->Height)
        , HeightMax(m_pData->HeightMax)
        , IntensityCalculation(m_pData->IntensityCalculation)
        , LastError(m_pData->LastError)
        , LineFormat(m_pData->LineFormat)
        , LineInverter(m_pData->LineInverter)
        , LineMode(m_pData->LineMode)
        , LineSelector(m_pData->LineSelector)
        , LineSource(m_pData->LineSource)
        , LineStatus(m_pData->LineStatus)
        , MultiCameraChannel(m_pData->MultiCameraChannel)
        , OffsetX(m_pData->OffsetX)
        , OffsetY(m_pData->OffsetY)
        , OperatingMode(m_pData->OperatingMode)
        , OutlierRemoval(m_pData->OutlierRemoval)
        , OutlierRemovalThreshold(m_pData->OutlierRemovalThreshold)
        , PayloadSize(m_pData->PayloadSize)
        , PixelFormat(m_pData->PixelFormat)
        , PtpDataSetLatch(m_pData->PtpDataSetLatch)
        , PtpEnable(m_pData->PtpEnable)
        , PtpOffsetFromMaster(m_pData->PtpOffsetFromMaster)
        , PtpStatus(m_pData->PtpStatus)
        , ReadoutTime(m_pData->ReadoutTime)
        , ResetTime(m_pData->ResetTime)
        , Scan3dAxisMax(m_pData->Scan3dAxisMax)
        , Scan3dAxisMin(m_pData->Scan3dAxisMin)
        , Scan3dCalibrationOffset(m_pData->Scan3dCalibrationOffset)
        , Scan3dCoordinateOffset(m_pData->Scan3dCoordinateOffset)
        , Scan3dCoordinateScale(m_pData->Scan3dCoordinateScale)
        , Scan3dCoordinateSelector(m_pData->Scan3dCoordinateSelector)
        , Scan3dCoordinateSystem(m_pData->Scan3dCoordinateSystem)
        , Scan3dCoordinateSystemReference(m_pData->Scan3dCoordinateSystemReference)
        , Scan3dDistanceUnit(m_pData->Scan3dDistanceUnit)
        , Scan3dFocalLength(m_pData->Scan3dFocalLength)
        , Scan3dInvalidDataFlag(m_pData->Scan3dInvalidDataFlag)
        , Scan3dInvalidDataValue(m_pData->Scan3dInvalidDataValue)
        , Scan3dOutputMode(m_pData->Scan3dOutputMode)
        , Scan3dPrincipalPointU(m_pData->Scan3dPrincipalPointU)
        , Scan3dPrincipalPointV(m_pData->Scan3dPrincipalPointV)
        , SensorHeight(m_pData->SensorHeight)
        , SensorPixelHeight(m_pData->SensorPixelHeight)
        , SensorPixelWidth(m_pData->SensorPixelWidth)
        , SensorPosition(m_pData->SensorPosition)
        , SensorWidth(m_pData->SensorWidth)
        , SpatialFilter(m_pData->SpatialFilter)
        , StartupTime(m_pData->StartupTime)
        , SyncFreeRunTimerEnable(m_pData->SyncFreeRunTimerEnable)
        , SyncFreeRunTimerStartTimeHigh(m_pData->SyncFreeRunTimerStartTimeHigh)
        , SyncFreeRunTimerStartTimeLow(m_pData->SyncFreeRunTimerStartTimeLow)
        , SyncFreeRunTimerUpdate(m_pData->SyncFreeRunTimerUpdate)
        , TemperatureState(m_pData->TemperatureState)
        , TemporalFilter(m_pData->TemporalFilter)
        , TemporalFilterStrength(m_pData->TemporalFilterStrength)
        , ThermalDriftCorrection(m_pData->ThermalDriftCorrection)
        , TimestampLatch(m_pData->TimestampLatch)
        , TimestampLatchValue(m_pData->TimestampLatchValue)
        , TriggerMode(m_pData->TriggerMode)
        , TriggerSelector(m_pData->TriggerSelector)
        , TriggerSoftware(m_pData->TriggerSoftware)
        , TriggerSource(m_pData->TriggerSource)
        , UserOutputSelector(m_pData->UserOutputSelector)
        , UserOutputValue(m_pData->UserOutputValue)
        , Width(m_pData->Width)
        , WidthMax(m_pData->WidthMax)
        , WorkingRangeMax(m_pData->WorkingRangeMax)
        , WorkingRangeMin(m_pData->WorkingRangeMin)
        , ZOffsetOriginToCameraFront(m_pData->ZOffsetOriginToCameraFront)
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeCameraParams::~BlazeCameraParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BlazeCameraParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        m_pData->AcquisitionFrameRate.Attach(pNodeMap, "AcquisitionFrameRate");
        m_pData->AcquisitionFrameRateEnable.Attach(pNodeMap, "AcquisitionFrameRateEnable");
        m_pData->AcquisitionMode.Attach(pNodeMap, "AcquisitionMode");
        m_pData->AcquisitionStart.Attach(pNodeMap, "AcquisitionStart");
        m_pData->AcquisitionStop.Attach(pNodeMap, "AcquisitionStop");
        m_pData->AmbiguityFilter.Attach(pNodeMap, "AmbiguityFilter");
        m_pData->AmbiguityFilterThreshold.Attach(pNodeMap, "AmbiguityFilterThreshold");
        m_pData->ClearLastError.Attach(pNodeMap, "ClearLastError");
        m_pData->ComponentEnable.Attach(pNodeMap, "ComponentEnable");
        m_pData->ComponentSelector.Attach(pNodeMap, "ComponentSelector");
        m_pData->ConfidenceThreshold.Attach(pNodeMap, "ConfidenceThreshold");
        m_pData->DepthMax.Attach(pNodeMap, "DepthMax");
        m_pData->DepthMin.Attach(pNodeMap, "DepthMin");
        m_pData->DeviceEventChannelCount.Attach(pNodeMap, "DeviceEventChannelCount");
        m_pData->DeviceFamilyName.Attach(pNodeMap, "DeviceFamilyName");
        m_pData->DeviceFirmwareVersion.Attach(pNodeMap, "DeviceFirmwareVersion");
        m_pData->DeviceLinkConnectionCount.Attach(pNodeMap, "DeviceLinkConnectionCount");
        m_pData->DeviceLinkSelector.Attach(pNodeMap, "DeviceLinkSelector");
        m_pData->DeviceManufacturerInfo.Attach(pNodeMap, "DeviceManufacturerInfo");
        m_pData->DeviceModelName.Attach(pNodeMap, "DeviceModelName");
        m_pData->DeviceReset.Attach(pNodeMap, "DeviceReset");
        m_pData->DeviceSFNCVersionMajor.Attach(pNodeMap, "DeviceSFNCVersionMajor");
        m_pData->DeviceSFNCVersionMinor.Attach(pNodeMap, "DeviceSFNCVersionMinor");
        m_pData->DeviceSFNCVersionSubMinor.Attach(pNodeMap, "DeviceSFNCVersionSubMinor");
        m_pData->DeviceScanType.Attach(pNodeMap, "DeviceScanType");
        m_pData->DeviceSerialNumber.Attach(pNodeMap, "DeviceSerialNumber");
        m_pData->DeviceStreamChannelCount.Attach(pNodeMap, "DeviceStreamChannelCount");
        m_pData->DeviceTLVersionMajor.Attach(pNodeMap, "DeviceTLVersionMajor");
        m_pData->DeviceTLVersionMinor.Attach(pNodeMap, "DeviceTLVersionMinor");
        m_pData->DeviceTemperature.Attach(pNodeMap, "DeviceTemperature");
        m_pData->DeviceTemperatureSelector.Attach(pNodeMap, "DeviceTemperatureSelector");
        m_pData->DeviceType.Attach(pNodeMap, "DeviceType");
        m_pData->DeviceUserID.Attach(pNodeMap, "DeviceUserID");
        m_pData->DeviceVendorName.Attach(pNodeMap, "DeviceVendorName");
        m_pData->DeviceVersion.Attach(pNodeMap, "DeviceVersion");
        m_pData->ExposureTime.Attach(pNodeMap, "ExposureTime");
        m_pData->FastMode.Attach(pNodeMap, "FastMode");
        m_pData->FrameDuration.Attach(pNodeMap, "FrameDuration");
        m_pData->GammaCorrection.Attach(pNodeMap, "GammaCorrection");
        m_pData->GenerateDiagnosticInfo.Attach(pNodeMap, "GenerateDiagnosticInfo");
        m_pData->GevCurrentDefaultGateway.Attach(pNodeMap, "GevCurrentDefaultGateway");
        m_pData->GevCurrentIPAddress.Attach(pNodeMap, "GevCurrentIPAddress");
        m_pData->GevCurrentIPConfigurationDHCP.Attach(pNodeMap, "GevCurrentIPConfigurationDHCP");
        m_pData->GevCurrentIPConfigurationLLA.Attach(pNodeMap, "GevCurrentIPConfigurationLLA");
        m_pData->GevCurrentIPConfigurationPersistentIP.Attach(pNodeMap, "GevCurrentIPConfigurationPersistentIP");
        m_pData->GevCurrentSubnetMask.Attach(pNodeMap, "GevCurrentSubnetMask");
        m_pData->GevInterfaceSelector.Attach(pNodeMap, "GevInterfaceSelector");
        m_pData->GevMACAddress.Attach(pNodeMap, "GevMACAddress");
        m_pData->GevPersistentDefaultGateway.Attach(pNodeMap, "GevPersistentDefaultGateway");
        m_pData->GevPersistentIPAddress.Attach(pNodeMap, "GevPersistentIPAddress");
        m_pData->GevPersistentSubnetMask.Attach(pNodeMap, "GevPersistentSubnetMask");
        m_pData->GevSCPSPacketSize.Attach(pNodeMap, "GevSCPSPacketSize");
        m_pData->GevTimestampTickFrequency.Attach(pNodeMap, "GevTimestampTickFrequency");
        m_pData->Height.Attach(pNodeMap, "Height");
        m_pData->HeightMax.Attach(pNodeMap, "HeightMax");
        m_pData->IntensityCalculation.Attach(pNodeMap, "IntensityCalculation");
        m_pData->LastError.Attach(pNodeMap, "LastError");
        m_pData->LineFormat.Attach(pNodeMap, "LineFormat");
        m_pData->LineInverter.Attach(pNodeMap, "LineInverter");
        m_pData->LineMode.Attach(pNodeMap, "LineMode");
        m_pData->LineSelector.Attach(pNodeMap, "LineSelector");
        m_pData->LineSource.Attach(pNodeMap, "LineSource");
        m_pData->LineStatus.Attach(pNodeMap, "LineStatus");
        m_pData->MultiCameraChannel.Attach(pNodeMap, "MultiCameraChannel");
        m_pData->OffsetX.Attach(pNodeMap, "OffsetX");
        m_pData->OffsetY.Attach(pNodeMap, "OffsetY");
        m_pData->OperatingMode.Attach(pNodeMap, "OperatingMode");
        m_pData->OutlierRemoval.Attach(pNodeMap, "OutlierRemoval");
        m_pData->OutlierRemovalThreshold.Attach(pNodeMap, "OutlierRemovalThreshold");
        m_pData->PayloadSize.Attach(pNodeMap, "PayloadSize");
        m_pData->PixelFormat.Attach(pNodeMap, "PixelFormat");
        m_pData->PtpDataSetLatch.Attach(pNodeMap, "PtpDataSetLatch");
        m_pData->PtpEnable.Attach(pNodeMap, "PtpEnable");
        m_pData->PtpOffsetFromMaster.Attach(pNodeMap, "PtpOffsetFromMaster");
        m_pData->PtpStatus.Attach(pNodeMap, "PtpStatus");
        m_pData->ReadoutTime.Attach(pNodeMap, "ReadoutTime");
        m_pData->ResetTime.Attach(pNodeMap, "ResetTime");
        m_pData->Scan3dAxisMax.Attach(pNodeMap, "Scan3dAxisMax");
        m_pData->Scan3dAxisMin.Attach(pNodeMap, "Scan3dAxisMin");
        m_pData->Scan3dCalibrationOffset.Attach(pNodeMap, "Scan3dCalibrationOffset");
        m_pData->Scan3dCoordinateOffset.Attach(pNodeMap, "Scan3dCoordinateOffset");
        m_pData->Scan3dCoordinateScale.Attach(pNodeMap, "Scan3dCoordinateScale");
        m_pData->Scan3dCoordinateSelector.Attach(pNodeMap, "Scan3dCoordinateSelector");
        m_pData->Scan3dCoordinateSystem.Attach(pNodeMap, "Scan3dCoordinateSystem");
        m_pData->Scan3dCoordinateSystemReference.Attach(pNodeMap, "Scan3dCoordinateSystemReference");
        m_pData->Scan3dDistanceUnit.Attach(pNodeMap, "Scan3dDistanceUnit");
        m_pData->Scan3dFocalLength.Attach(pNodeMap, "Scan3dFocalLength");
        m_pData->Scan3dInvalidDataFlag.Attach(pNodeMap, "Scan3dInvalidDataFlag");
        m_pData->Scan3dInvalidDataValue.Attach(pNodeMap, "Scan3dInvalidDataValue");
        m_pData->Scan3dOutputMode.Attach(pNodeMap, "Scan3dOutputMode");
        m_pData->Scan3dPrincipalPointU.Attach(pNodeMap, "Scan3dPrincipalPointU");
        m_pData->Scan3dPrincipalPointV.Attach(pNodeMap, "Scan3dPrincipalPointV");
        m_pData->SensorHeight.Attach(pNodeMap, "SensorHeight");
        m_pData->SensorPixelHeight.Attach(pNodeMap, "SensorPixelHeight");
        m_pData->SensorPixelWidth.Attach(pNodeMap, "SensorPixelWidth");
        m_pData->SensorPosition.Attach(pNodeMap, "SensorPosition");
        m_pData->SensorWidth.Attach(pNodeMap, "SensorWidth");
        m_pData->SpatialFilter.Attach(pNodeMap, "SpatialFilter");
        m_pData->StartupTime.Attach(pNodeMap, "StartupTime");
        m_pData->SyncFreeRunTimerEnable.Attach(pNodeMap, "SyncFreeRunTimerEnable");
        m_pData->SyncFreeRunTimerStartTimeHigh.Attach(pNodeMap, "SyncFreeRunTimerStartTimeHigh");
        m_pData->SyncFreeRunTimerStartTimeLow.Attach(pNodeMap, "SyncFreeRunTimerStartTimeLow");
        m_pData->SyncFreeRunTimerUpdate.Attach(pNodeMap, "SyncFreeRunTimerUpdate");
        m_pData->TemperatureState.Attach(pNodeMap, "TemperatureState");
        m_pData->TemporalFilter.Attach(pNodeMap, "TemporalFilter");
        m_pData->TemporalFilterStrength.Attach(pNodeMap, "TemporalFilterStrength");
        m_pData->ThermalDriftCorrection.Attach(pNodeMap, "ThermalDriftCorrection");
        m_pData->TimestampLatch.Attach(pNodeMap, "TimestampLatch");
        m_pData->TimestampLatchValue.Attach(pNodeMap, "TimestampLatchValue");
        m_pData->TriggerMode.Attach(pNodeMap, "TriggerMode");
        m_pData->TriggerSelector.Attach(pNodeMap, "TriggerSelector");
        m_pData->TriggerSoftware.Attach(pNodeMap, "TriggerSoftware");
        m_pData->TriggerSource.Attach(pNodeMap, "TriggerSource");
        m_pData->UserOutputSelector.Attach(pNodeMap, "UserOutputSelector");
        m_pData->UserOutputValue.Attach(pNodeMap, "UserOutputValue");
        m_pData->Width.Attach(pNodeMap, "Width");
        m_pData->WidthMax.Attach(pNodeMap, "WidthMax");
        m_pData->WorkingRangeMax.Attach(pNodeMap, "WorkingRangeMax");
        m_pData->WorkingRangeMin.Attach(pNodeMap, "WorkingRangeMin");
        m_pData->ZOffsetOriginToCameraFront.Attach(pNodeMap, "ZOffsetOriginToCameraFront");
    }

    //! \endcond

} // namespace Pylon
} // namespace BlazeCameraParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BLAZECAMERAPARAMS_H