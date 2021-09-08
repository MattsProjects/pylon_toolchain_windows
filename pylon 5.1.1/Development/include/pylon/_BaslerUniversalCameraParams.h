//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2018 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu, and dart BCON
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_Basler_UniversalCameraParams_PARAMS_H
#define BASLER_PYLON_Basler_UniversalCameraParams_PARAMS_H

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UniversalCameraParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    //! Valid values for AcquisitionFrameRateEnum
    enum AcquisitionFrameRateEnumEnums
    {
        AcquisitionFrameRateEnum_FrameRate24,  //!< 
        AcquisitionFrameRateEnum_FrameRate25,  //!< 
        AcquisitionFrameRateEnum_FrameRate30,  //!< 
        AcquisitionFrameRateEnum_FrameRate50,  //!< 
        AcquisitionFrameRateEnum_FrameRate60  //!< 
    };

    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_SingleFrame,  //!< The acquisition mode is set to single frame.
        AcquisitionMode_Continuous,  //!< The acquisition mode is set to continuous.
        AcquisitionMode_MultiFrame  //!< Sets the acquisition mode to multi frame
    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_FrameBurstTriggerWait,  //!< A check can be performed if the device is currently waiting for a frame burst trigger.
        AcquisitionStatusSelector_FrameBurstTriggerActive,  //!< A check can be performed if the device is currently doing a frame burst of one or many frames.
        AcquisitionStatusSelector_FrameBurstTriggerTransfer,  //!< A check can be performed if the device is currently transferring a frame burst of one or many frames.
        AcquisitionStatusSelector_FrameTriggerWait,  //!< A check can be performed if the device is currently waiting for a frame trigger.
        AcquisitionStatusSelector_FrameActive,  //!< A check can be performed if the device is currently capturing a frame.
        AcquisitionStatusSelector_FrameTransfer,  //!< A check can be performed if the device is currently transferring a frame.
        AcquisitionStatusSelector_ExposureActive,  //!< A check can be performed if the device is currently exposing a frame.
        AcquisitionStatusSelector_AcquisitionTriggerWait,  //!< Device is currently waiting for a trigger for the capture of one or many frames.
        AcquisitionStatusSelector_AcquisitionActive,  //!< Device is currently doing an acquisition of one or many frames.
        AcquisitionStatusSelector_AcquisitionTransfer,  //!< Device is currently transferring an acquisition of one or many frames.
        AcquisitionStatusSelector_LineTriggerWait  //!< Device is currently waiting for a line trigger.
    };

    //! Valid values for AutoFunctionAOISelector
    enum AutoFunctionAOISelectorEnums
    {
        AutoFunctionAOISelector_AOI1,  //!< Auto function AOI 1 can be adjusted.
        AutoFunctionAOISelector_AOI2,  //!< Auto function AOI 2 can be adjusted.
        AutoFunctionAOISelector_AOI3,  //!< 
        AutoFunctionAOISelector_AOI4,  //!< 
        AutoFunctionAOISelector_AOI5,  //!< 
        AutoFunctionAOISelector_AOI6,  //!< 
        AutoFunctionAOISelector_AOI7,  //!< 
        AutoFunctionAOISelector_AOI8  //!< 
    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_MinimizeGain,  //!< Gain is kept as low as possible.
        AutoFunctionProfile_MinimizeExposureTime,  //!< Exposure time is kept as low as possible.
        AutoFunctionProfile_Smart,  //!< 
        AutoFunctionProfile_AntiFlicker50Hz,  //!< 
        AutoFunctionProfile_AntiFlicker60Hz,  //!< 
        AutoFunctionProfile_GainMinimum,  //!< Keep gain at minimum
        AutoFunctionProfile_ExposureMinimum  //!< Exposure Time at minimum
    };

    //! Valid values for AutoFunctionROISelector
    enum AutoFunctionROISelectorEnums
    {
        AutoFunctionROISelector_ROI1,  //!< Auto function ROI 1 can be adjusted.
        AutoFunctionROISelector_ROI2  //!< Auto function ROI 2 can be adjusted.
    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Red,  //!< Balance ratio will be applied to the red channel.
        BalanceRatioSelector_Green,  //!< Balance ratio will be applied to the green channel.
        BalanceRatioSelector_Blue  //!< Balance ratio will be applied to the blue channel.
    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Off,  //!< The balance white auto function is disabled.
        BalanceWhiteAuto_Once,  //!< White balance is adjusted automatically until it reaches a specific target value.
        BalanceWhiteAuto_Continuous  //!< White balance is adjusted repeatedly while images are acquired.
    };

    //! Valid values for BconClockFrequency
    enum BconClockFrequencyEnums
    {
        BconClockFrequency_MHz_84,  //!< 
        BconClockFrequency_MHz_76,  //!< 
        BconClockFrequency_MHz_68,  //!< 
        BconClockFrequency_MHz_60,  //!< 
        BconClockFrequency_MHz_52,  //!< 
        BconClockFrequency_MHz_44,  //!< 
        BconClockFrequency_MHz_36,  //!< 
        BconClockFrequency_MHz_28,  //!< 
        BconClockFrequency_MHz_20,  //!< 
        BconClockFrequency_MHz_12  //!< 
    };

    //! Valid values for BconPixelsPerClockCycle
    enum BconPixelsPerClockCycleEnums
    {
        BconPixelsPerClockCycle_One,  //!<  On each clock cycle, data for one pixel is transmitted via the BCON interface.
        BconPixelsPerClockCycle_Two  //!< On each clock cycle, data for two pixels is transmitted via the BCON interface.
    };

    //! Valid values for BinningHorizontalMode
    enum BinningHorizontalModeEnums
    {
        BinningHorizontalMode_Sum,  //!< The values of the binned pixels are summed.
        BinningHorizontalMode_Average  //!< The values of the binned pixels are averaged.
    };

    //! Valid values for BinningModeHorizontal
    enum BinningModeHorizontalEnums
    {
        BinningModeHorizontal_Summing,  //!< Sets the binning mode to summing
        BinningModeHorizontal_Averaging  //!< Sets the binning mode to averaging
    };

    //! Valid values for BinningModeVertical
    enum BinningModeVerticalEnums
    {
        BinningModeVertical_Summing,  //!< Sets the binning mode to summing
        BinningModeVertical_Averaging  //!< Sets the binning mode to averaging
    };

    //! Valid values for BinningVerticalMode
    enum BinningVerticalModeEnums
    {
        BinningVerticalMode_Sum,  //!< The values of the binned pixels are summed.
        BinningVerticalMode_Average  //!< The values of the binned pixels are averaged.
    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All,  //!< Black level will be applied to all channels or taps.
        BlackLevelSelector_AnalogAll,  //!< Selects all analog black level controls for adjustment
        BlackLevelSelector_DigitalAll,  //!< Selects all digital black level controls for adjustment
        BlackLevelSelector_Tap1,  //!< Selects the tap 1 black level control for adjustment
        BlackLevelSelector_Tap2,  //!< Selects the tap 2 black level control for adjustment
        BlackLevelSelector_Tap3,  //!< Selects the tap 3 black level control for adjustment
        BlackLevelSelector_Tap4,  //!< Selects the tap 4 black level control for adjustment
        BlackLevelSelector_Red,  //!< Selects the red black level control for adjustment
        BlackLevelSelector_Green,  //!< Selects the green black level control for adjustment
        BlackLevelSelector_Blue  //!< Selects the blue black level control for adjustment
    };

    //! Valid values for BslColorSpaceMode
    enum BslColorSpaceModeEnums
    {
        BslColorSpaceMode_RGB,  //!< Color space is set to RGB.
        BslColorSpaceMode_sRGB  //!< Color space is set to sRGB
    };

    //! Valid values for BslContrastMode
    enum BslContrastModeEnums
    {
        BslContrastMode_Linear,  //!< Linear contrast enhancement is used to adjust the contrast.
        BslContrastMode_SCurve  //!< S-curve contrast enhancement is used to adjust the contrast.
    };

    //! Valid values for BslDeviceRole
    enum BslDeviceRoleEnums
    {
        BslDeviceRole_Camera,  //!< 
        BslDeviceRole_Updater  //!< 
    };

    //! Valid values for BslImmediateTriggerMode
    enum BslImmediateTriggerModeEnums
    {
        BslImmediateTriggerMode_On,  //!< The immediate trigger mode is enabled.
        BslImmediateTriggerMode_Off  //!< The immediate trigger mode is disabled.
    };

    //! Valid values for BslUSBSpeedMode
    enum BslUSBSpeedModeEnums
    {
        BslUSBSpeedMode_LowSpeed,  //!< The USB port is operating at Low Speed, as specified in the USB standard.
        BslUSBSpeedMode_FullSpeed,  //!< The USB port is operating at Full Speed, as specified in the USB standard.
        BslUSBSpeedMode_HighSpeed,  //!< The USB port is operating at High Speed, as specified in the USB standard.
        BslUSBSpeedMode_SuperSpeed  //!< The USB port is operating at SuperSpeed, as specified in the USB standard.
    };

    //! Valid values for ChunkCounterSelector
    enum ChunkCounterSelectorEnums
    {
        ChunkCounterSelector_Counter1,  //!< Chunk data can be retrieved from counter 1.
        ChunkCounterSelector_Counter2  //!< Chunk data can be retrieved from counter 2.
    };

    //! Valid values for ChunkGainSelector
    enum ChunkGainSelectorEnums
    {
        ChunkGainSelector_All  //!< Chunk data can be retrieved from all gain channels.
    };

    //! Valid values for ChunkPixelFormat
    enum ChunkPixelFormatEnums
    {
        ChunkPixelFormat_Mono8,  //!< Indicates that the pixel data in the acquired image is in the Mono 8 format
        ChunkPixelFormat_Mono8Signed,  //!< Indicates that the pixel data in the acquired image is in the Mono 8 signed format
        ChunkPixelFormat_Mono10,  //!< Indicates that the pixel data in the acquired image is in the Mono 10 format
        ChunkPixelFormat_Mono10Packed,  //!< Indicates that the pixel data in the acquired image is in the Mono 10 Packed format
        ChunkPixelFormat_Mono10p,  //!< Indicates that the pixel data in the acquired image is in the Mono 10p format
        ChunkPixelFormat_Mono12,  //!< Indicates that the pixel data in the acquired image is in the Mono 12 format
        ChunkPixelFormat_Mono12Packed,  //!< Indicates that the pixel data in the acquired image is in the Mono 12 Packed format
        ChunkPixelFormat_Mono16,  //!< Indicates that the pixel data in the acquired image is in the Mono 16 format
        ChunkPixelFormat_BayerGR8,  //!< Indicates that the pixel data in the acquired image is in the Bayer GR 8 format
        ChunkPixelFormat_BayerRG8,  //!< Indicates that the pixel data in the acquired image is in the Bayer RG 8 format
        ChunkPixelFormat_BayerGB8,  //!< Indicates that the pixel data in the acquired image is in the Bayer GB 8 format
        ChunkPixelFormat_BayerBG8,  //!< Indicates that the pixel data in the acquired image is in the Bayer BG 8 format
        ChunkPixelFormat_BayerGR10,  //!< Indicates that the pixel data in the acquired image is in the Bayer GR 10 format
        ChunkPixelFormat_BayerRG10,  //!< Indicates that the pixel data in the acquired image is in the Bayer RG 10 format
        ChunkPixelFormat_BayerGB10,  //!< Indicates that the pixel data in the acquired image is in the Bayer GB 10 format
        ChunkPixelFormat_BayerBG10,  //!< Indicates that the pixel data in the acquired image is in the Bayer BG 10 format
        ChunkPixelFormat_BayerGR12,  //!< Indicates that the pixel data in the acquired image is in the Bayer GR 12 format
        ChunkPixelFormat_BayerRG12,  //!< Indicates that the pixel data in the acquired image is in the Bayer RG 12 format
        ChunkPixelFormat_BayerGB12,  //!< Indicates that the pixel data in the acquired image is in the Bayer GB 12 format
        ChunkPixelFormat_BayerBG12,  //!< Indicates that the pixel data in the acquired image is in the Bayer BG 12 format
        ChunkPixelFormat_BayerGR16,  //!< Indicates that the pixel data in the acquired image is in the Bayer GR 16 format
        ChunkPixelFormat_BayerRG16,  //!< Indicates that the pixel data in the acquired image is in the Bayer RG 16 format
        ChunkPixelFormat_BayerGB16,  //!< Indicates that the pixel data in the acquired image is in the Bayer GB 16 format
        ChunkPixelFormat_BayerBG16,  //!< Indicates that the pixel data in the acquired image is in the Bayer BG 16 format
        ChunkPixelFormat_RGB8Packed,  //!< Indicates that the pixel data in the acquired image is in the RGB 8 Packed format
        ChunkPixelFormat_BGR8Packed,  //!< Indicates that the pixel data in the acquired image is in the BGR 8 Packed format
        ChunkPixelFormat_RGBA8Packed,  //!< Indicates that the pixel data in the acquired image is in the RGBA 8 Packed format
        ChunkPixelFormat_BGRA8Packed,  //!< Indicates that the pixel data in the acquired image is in the BGRA 8 Packed format
        ChunkPixelFormat_RGB10Packed,  //!< Indicates that the pixel data in the acquired image is in the RGB 10 Packed format
        ChunkPixelFormat_BGR10Packed,  //!< Indicates that the pixel data in the acquired image is in the BGR 10 Packed format
        ChunkPixelFormat_RGB12Packed,  //!< Indicates that the pixel data in the acquired image is in the RGB 12 Packed format
        ChunkPixelFormat_BGR12Packed,  //!< Indicates that the pixel data in the acquired image is in the BGR 12 Packed format
        ChunkPixelFormat_RGB10V1Packed,  //!< Indicates that the pixel data in the acquired image is in the RGB 10V1 Packed format
        ChunkPixelFormat_RGB10V2Packed,  //!< Indicates that the pixel data in the acquired image is in the RGB 10V2 Packed format
        ChunkPixelFormat_YUV411Packed,  //!< Indicates that the pixel data in the acquired image is in the YUV 411 Packed format
        ChunkPixelFormat_YUV422Packed,  //!< Indicates that the pixel data in the acquired image is in the YUV 422 Packed format
        ChunkPixelFormat_YUV444Packed,  //!< Indicates that the pixel data in the acquired image is in the YUV 444 Packed format
        ChunkPixelFormat_RGB8Planar,  //!< Indicates that the pixel data in the acquired image is in the RGB 8 Planar format
        ChunkPixelFormat_RGB10Planar,  //!< Indicates that the pixel data in the acquired image is in the RGB 10 Planar format
        ChunkPixelFormat_RGB12Planar,  //!< Indicates that the pixel data in the acquired image is in the RGB 12 Planar format
        ChunkPixelFormat_RGB16Planar,  //!< Indicates that the pixel data in the acquired image is in the RGB 16 Planar format
        ChunkPixelFormat_YUV422_YUYV_Packed,  //!< Indicates that the pixel data in the acquired image is in the YUV 422 (YUYV) Packed format
        ChunkPixelFormat_BayerGB12Packed,  //!< Indicates that the pixel data in the acquired image is in the Bayer GB 12 Packed format
        ChunkPixelFormat_BayerGR12Packed,  //!< Indicates that the pixel data in the acquired image is in the Bayer GR 12 Packed format
        ChunkPixelFormat_BayerRG12Packed,  //!< Indicates that the pixel data in the acquired image is in the Bayer RG 12 Packed format
        ChunkPixelFormat_BayerBG12Packed,  //!< Indicates that the pixel data in the acquired image is in the Bayer BG 12 Packed format
        ChunkPixelFormat_RGB12V1Packed,  //!< Indicates that the pixel data in the acquired image is in RGB 12 Packed 
        ChunkPixelFormat_BayerGB10p,  //!< Indicates that the pixel data in the acquired image is in the Bayer GB 10p format
        ChunkPixelFormat_BayerGR10p,  //!< Indicates that the pixel data in the acquired image is in the Bayer GR 10p format
        ChunkPixelFormat_BayerRG10p,  //!< Indicates that the pixel data in the acquired image is in the Bayer RG 10p format
        ChunkPixelFormat_BayerBG10p  //!< Indicates that the pixel data in the acquired image is in the Bayer BG 10p format
    };

    //! Valid values for ChunkSelector
    enum ChunkSelectorEnums
    {
        ChunkSelector_Image,  //!< The image chunk can be enabled.
        ChunkSelector_Gain,  //!< The gain chunk can be enabled.
        ChunkSelector_ExposureTime,  //!< The exposure time chunk can be enabled.
        ChunkSelector_Timestamp,  //!< The timestamp chunk can be enabled.
        ChunkSelector_LineStatusAll,  //!< The line status all chunk can be enabled.
        ChunkSelector_CounterValue,  //!< The counter value chunk can be enabled.
        ChunkSelector_SequencerSetActive,  //!< The sequencer set active chunk can be enabled.
        ChunkSelector_PayloadCRC16,  //!< The CRC checksum chunk can be enabled.
        ChunkSelector_OffsetX,  //!< Selects the X offset chunk for enabling.
        ChunkSelector_OffsetY,  //!< Selects the Y offset chunk for enabling.
        ChunkSelector_Width,  //!< Selects the width chunk for enabling.
        ChunkSelector_Height,  //!< Selects the height chunk for enabling.
        ChunkSelector_PixelFormat,  //!< Selects the pixel format chunk for enabling.
        ChunkSelector_DynamicRangeMax,  //!< Selects the dynamic range max chunk for enabling.
        ChunkSelector_DynamicRangeMin,  //!< Selects the dynamic range min chunk for enabling.
        ChunkSelector_Framecounter,  //!< Selects the frame counter chunk for enabling.
        ChunkSelector_Triggerinputcounter,  //!< Selects the trigger input counter chunk for enabling.
        ChunkSelector_LineTriggerIgnoredCounter,  //!< Selects the line trigger ignored counter chunk for enabling.
        ChunkSelector_FrameTriggerIgnoredCounter,  //!< Selects the frame trigger ignored counter chunk for enabling.
        ChunkSelector_LineTriggerEndToEndCounter,  //!< Selects the line trigger end to end counter chunk for enabling.
        ChunkSelector_FrameTriggerCounter,  //!< Selects the frame trigger counter chunk for enabling.
        ChunkSelector_FramesPerTriggerCounter,  //!< Selects the frame per trigger counter chunk for enabling.
        ChunkSelector_InputStatusAtLineTrigger,  //!< Selects the input status at line trigger chunk for enabling.
        ChunkSelector_ShaftEncoderCounter,  //!< Selects the shaft encoder counter chunk for enabling.
        ChunkSelector_Stride,  //!< Selects the stride chunk for enabling.
        ChunkSelector_SequenceSetIndex,  //!< Selects the sequence set index chunk for enabling
        ChunkSelector_GainAll,  //!< 
        ChunkSelector_BrightPixel,  //!< 
        ChunkSelector_VirtLineStatusAll,  //!< Selects the virtual line status all chunk for enabling.
        ChunkSelector_LineTriggerCounter  //!< Selects the Line Trigger Counter chunk for enabling.
    };

    //! Valid values for ClConfiguration
    enum ClConfigurationEnums
    {
        ClConfiguration_Base,  //!< Base Configuration
        ClConfiguration_Medium,  //!< Medium Configuration
        ClConfiguration_Full,  //!< Full Configuration
        ClConfiguration_DualBase,  //!< DualBase Configuration
        ClConfiguration_Deca  //!< Deca Configuration
    };

    //! Valid values for ClPixelClock
    enum ClPixelClockEnums
    {
        ClPixelClock_PixelClock20,  //!< 20 MHz pixel clock
        ClPixelClock_PixelClock32_5,  //!< 32.5 MHz pixel clock
        ClPixelClock_PixelClock40,  //!< 40 MHz pixel clock
        ClPixelClock_PixelClock48,  //!< 48 MHz pixel clock
        ClPixelClock_PixelClock65,  //!< 65 MHz pixel clock
        ClPixelClock_PixelClock82,  //!< 82 MHz pixel clock
        ClPixelClock_PixelClock82_5,  //!< 82.5 MHz pixel clock
        ClPixelClock_PixelClock83,  //!< 83 MHz pixel clock
        ClPixelClock_PixelClock83_5  //!< 83.5 MHz pixel clock
    };

    //! Valid values for ClSerialPortBaudRate
    enum ClSerialPortBaudRateEnums
    {
        ClSerialPortBaudRate_Baud9600,  //!< 9600 Baud
        ClSerialPortBaudRate_Baud19200,  //!< 19200 Baud
        ClSerialPortBaudRate_Baud38400,  //!< 38400 Baud
        ClSerialPortBaudRate_Baud57600,  //!< 57600 Baud
        ClSerialPortBaudRate_Baud115200,  //!< 115200 Baud
        ClSerialPortBaudRate_Baud230400,  //!< 230400 Baud
        ClSerialPortBaudRate_Baud460800,  //!< 460800 Baud
        ClSerialPortBaudRate_Baud921600  //!< 921600 Baud
    };

    //! Valid values for ClTapGeometry
    enum ClTapGeometryEnums
    {
        ClTapGeometry_Geometry1X_1Y,  //!< 1 Zone in X, 1 zone in Y
        ClTapGeometry_Geometry1X2_1Y,  //!< 1 Zone in X with two taps, 1 zone in Y
        ClTapGeometry_Geometry1X_2YE,  //!< 1 Zone in X, 2 zone in Y with end extraction
        ClTapGeometry_Geometry1X3_1Y,  //!< 1 Zone in X with three taps, 1 zone in Y
        ClTapGeometry_Geometry1X4_1Y,  //!< 1 Zone in X with four taps, 1 zone in Y
        ClTapGeometry_Geometry1X6_1Y,  //!< 1 Zone in X with six taps, 1 zone in Y
        ClTapGeometry_Geometry1X8_1Y,  //!< 1 Zone in X with eight taps, 1 zone in Y
        ClTapGeometry_Geometry1X10_1Y,  //!< 1 Zone in X with ten taps, 1 zone in Y
        ClTapGeometry_Geometry1X,  //!< 1 Zone in X with one tap
        ClTapGeometry_Geometry1X2,  //!< 1 Zone in X with two taps
        ClTapGeometry_Geometry1X3,  //!< 1 Zone in X with three taps
        ClTapGeometry_Geometry1X4,  //!< 1 Zone in X with four taps
        ClTapGeometry_Geometry1X6,  //!< 1 Zone in X with six taps
        ClTapGeometry_Geometry1X8,  //!< 1 Zone in X with eight taps
        ClTapGeometry_Geometry1X10  //!< 1 Zone in X with ten taps
    };

    //! Valid values for ClTimeSlots
    enum ClTimeSlotsEnums
    {
        ClTimeSlots_TimeSlots1  //!< Single timeslot
    };

    //! Valid values for ColorAdjustmentSelector
    enum ColorAdjustmentSelectorEnums
    {
        ColorAdjustmentSelector_Red,  //!< Colors with predominant red can be adjusted.
        ColorAdjustmentSelector_Yellow,  //!< Colors with predominant yellow can be adjusted.
        ColorAdjustmentSelector_Green,  //!< Colors with predominant green can be adjusted.
        ColorAdjustmentSelector_Cyan,  //!< Colors with predominant cyan can be adjusted.
        ColorAdjustmentSelector_Blue,  //!< Colors with predominant blue can be adjusted.
        ColorAdjustmentSelector_Magenta  //!< Colors with predominant magenta can be adjusted.
    };

    //! Valid values for ColorOverexposureCompensationAOISelector
    enum ColorOverexposureCompensationAOISelectorEnums
    {
        ColorOverexposureCompensationAOISelector_AOI1  //!< Selects Color Overexposure Compensation AOI 1
    };

    //! Valid values for ColorSpace
    enum ColorSpaceEnums
    {
        ColorSpace_RGB,  //!< Color space is set to RGB.
        ColorSpace_sRGB  //!< Color space is set to sRGB. The image brightness is optimized for display on an sRGB monitor.
    };

    //! Valid values for ColorTransformationSelector
    enum ColorTransformationSelectorEnums
    {
        ColorTransformationSelector_RGBtoRGB,  //!< A matrix color transformation from RGB to RGB is performed on the pixels.
        ColorTransformationSelector_RGBtoYUV,  //!< A matrix color transformation from RGB to YUV is performed on the pixels.
        ColorTransformationSelector_YUVtoRGB  //!< A matrix color transformation from YUV to RGB is performed on the pixels.
    };

    //! Valid values for ColorTransformationValueSelector
    enum ColorTransformationValueSelectorEnums
    {
        ColorTransformationValueSelector_Gain00,  //!< The element in row 0 and column 0 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain01,  //!< The element in row 0 and column 1 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain02,  //!< The element in row 0 and column 2 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain10,  //!< The element in row 1 and column 0 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain11,  //!< The element in row 1 and column 1 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain12,  //!< The element in row 1 and column 2 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain20,  //!< The element in row 2 and column 0 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain21,  //!< The element in row 2 and column 1 of the color transformation matrix can be entered.
        ColorTransformationValueSelector_Gain22  //!< The element in row 2 and column 2 of the color transformation matrix can be entered.
    };

    //! Valid values for CounterEventSource
    enum CounterEventSourceEnums
    {
        CounterEventSource_FrameTrigger,  //!< The selected counter counts the number of Frame Trigger events.
        CounterEventSource_FrameStart,  //!< The selected counter counts the number of Frame Start events.
        CounterEventSource_Counter1End,  //!< The selected counter counts the number of counter 1 end events.
        CounterEventSource_Counter2End,  //!< The selected counter counts the number of counter 2 end events.
        CounterEventSource_Counter3End,  //!< The selected counter counts the number of counter 3 end events.
        CounterEventSource_Off,  //!< Counter is stopped
        CounterEventSource_AcquisitionTrigger,  //!< Counts the number of Acquisition Trigger
        CounterEventSource_AcquisitionStart,  //!< Counts the number of Acquisition Start
        CounterEventSource_AcquisitionEnd,  //!< Counts the number of Acquisition End
        CounterEventSource_FrameEnd,  //!< Counts the number of Frame End
        CounterEventSource_LineTrigger,  //!< Counts the number of Line Trigger
        CounterEventSource_LineStart,  //!< Counts the number of Line Start
        CounterEventSource_LineEnd,  //!< Counts the number of Line End
        CounterEventSource_ExposureStart,  //!< Counts the number of Exposure Start
        CounterEventSource_ExposureEnd  //!< Counts the number of Exposure End
    };

    //! Valid values for CounterResetActivation
    enum CounterResetActivationEnums
    {
        CounterResetActivation_RisingEdge,  //!< The counter resets on the rising edge of the signal.
        CounterResetActivation_FallingEdge,  //!< The counter resets on the falling edge of the signal.
        CounterResetActivation_AnyEdge,  //!< The counter resets on the falling or rising edge of the selected signal.
        CounterResetActivation_LevelHigh,  //!< The counter resets as long as the selected signal level is high.
        CounterResetActivation_LevelLow  //!< The counter resets as long as the selected signal level is low.
    };

    //! Valid values for CounterResetSource
    enum CounterResetSourceEnums
    {
        CounterResetSource_Off,  //!< The counter reset is disabled.
        CounterResetSource_Software,  //!< The selected counter can be reset by a software command.
        CounterResetSource_Line1,  //!< The selected counter can be reset by a signal applied to Line 1.
        CounterResetSource_Line2,  //!< The selected counter can be reset by a signal applied to Line 2.
        CounterResetSource_Line3,  //!< The selected counter can be reset by a signal applied to Line 3.
        CounterResetSource_Line4,  //!< The selected counter can be reset by a signal applied to Line 4.
        CounterResetSource_Counter1End,  //!< The selected counter can be reset by a counter end 1 signal.
        CounterResetSource_Counter2End,  //!< The selected counter can be reset by a counter end 2 signal.
        CounterResetSource_Counter3End,  //!< The selected counter can be reset by a counter end 3 signal.
        CounterResetSource_Counter4End,  //!< The selected counter can be reset by a counter end 4 signal.
        CounterResetSource_Line5,  //!< Selects line 5 as the source for counter reset
        CounterResetSource_Line6,  //!< Selects line 6 as the source for counter reset
        CounterResetSource_Line7,  //!< Selects line 7 as the source for counter reset
        CounterResetSource_Line8,  //!< Selects line 8 as the source for counter reset
        CounterResetSource_CC1,  //!< Selects CC1 as the source for counter reset
        CounterResetSource_CC2,  //!< Selects CC2 as the source for counter reset
        CounterResetSource_CC3,  //!< Selects CC3 as the source for counter reset
        CounterResetSource_CC4,  //!< Selects CC4 as the source for counter reset
        CounterResetSource_VInput1,  //!< Selects Virtual Input 1 as the source for counter reset
        CounterResetSource_VInput2,  //!< Selects Virtual Input 2 as the source for counter reset
        CounterResetSource_VInput3,  //!< Selects Virtual Input 3 as the source for counter reset
        CounterResetSource_VInput4,  //!< Selects Virtual Input 4 as the source for counter reset
        CounterResetSource_VInputDecActive  //!< Selects Virtual Input Decoder Active as the source for counter reset
    };

    //! Valid values for CounterSelector
    enum CounterSelectorEnums
    {
        CounterSelector_Counter1,  //!< Counter 1 can be configured.
        CounterSelector_Counter2,  //!< Counter 2 can be configured.
        CounterSelector_Counter3,  //!< Selects counter 3 for configuration
        CounterSelector_Counter4  //!< Selects counter 4 for configuration
    };

    //! Valid values for DefaultSetSelector
    enum DefaultSetSelectorEnums
    {
        DefaultSetSelector_Standard,  //!< Standard factory set
        DefaultSetSelector_HighGain,  //!< High gain factory set
        DefaultSetSelector_AutoFunctions,  //!< Factory set using auto functions
        DefaultSetSelector_Color,  //!< Factory set enabling color adjustments
        DefaultSetSelector_ColorRaw,  //!< Factory set disabling color adjustments
        DefaultSetSelector_Custom0,  //!< customer factory set 0
        DefaultSetSelector_Custom1  //!< customer factory set 1
    };

    //! Valid values for DefectPixelCorrectionMode
    enum DefectPixelCorrectionModeEnums
    {
        DefectPixelCorrectionMode_Off,  //!< 
        DefectPixelCorrectionMode_On,  //!< 
        DefectPixelCorrectionMode_StaticOnly  //!< 
    };

    //! Valid values for DemosaicingMode
    enum DemosaicingModeEnums
    {
        DemosaicingMode_Simple,  //!< Demosaicing is performed using a simple demosaicing algorithm.
        DemosaicingMode_BaslerPGI  //!< Demosaicing is performed using the Basler PGI algorithm.
    };

    //! Valid values for DeviceClockSelector
    enum DeviceClockSelectorEnums
    {
        DeviceClockSelector_Bcon  //!< The BCON device clock is selected.
    };

    //! Valid values for DeviceIndicatorMode
    enum DeviceIndicatorModeEnums
    {
        DeviceIndicatorMode_Inactive,  //!< Indicators are inactive (off).
        DeviceIndicatorMode_Active  //!< Indicators are active showing their respective status.
    };

    //! Valid values for DeviceLinkThroughputLimitMode
    enum DeviceLinkThroughputLimitModeEnums
    {
        DeviceLinkThroughputLimitMode_Off,  //!< The device link throughput limit feature is disabled.
        DeviceLinkThroughputLimitMode_On  //!< The device link throughput limit feature is enabled.
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!< The device has an area scan sensor.
        DeviceScanType_Linescan  //!< The device has a line scan sensor.
    };

    //! Valid values for DeviceTemperatureSelector
    enum DeviceTemperatureSelectorEnums
    {
        DeviceTemperatureSelector_Coreboard,  //!< The temperature is measured on the core board.
        DeviceTemperatureSelector_Sensorboard,  //!< The temperature is measured on the sensor board.
        DeviceTemperatureSelector_Framegrabberboard  //!< The temperature is measured on the frame grabber board.
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_Off,  //!< Event notifications are disabled.
        EventNotification_On,  //!< Event notifications are enabled.
        EventNotification_GenICamEvent  //!< Sets the event notification type to GenICam event
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_ExposureEnd,  //!< Event notifications for the exposure end event can be enabled.
        EventSelector_FrameStart,  //!< Event notifications for the frame start event can be enabled.
        EventSelector_FrameBurstStart,  //!< Event notifications for the frame burst start event can be enabled.
        EventSelector_FrameStartOvertrigger,  //!< Event notifications for the frame start overtrigger event can be enabled.
        EventSelector_FrameBurstStartOvertrigger,  //!< Event notifications for the frame burst start overtrigger event can be enabled.
        EventSelector_CriticalTemperature,  //!< Event notifications for the critical temperature event can be enabled.
        EventSelector_OverTemperature,  //!< Event notifications for the over temperature event can be enabled.
        EventSelector_FrameStartWait,  //!< Event notifications for the frame start wait event can be enabled.
        EventSelector_FrameBurstStartWait,  //!< Event notifications for the frame burst start wait event can be enabled.
        EventSelector_LineStartOvertrigger,  //!< Selects the line start overtrigger event for enabling.
        EventSelector_AcquisitionStartOvertrigger,  //!< Selects the acquisition start overtrigger event for enabling.
        EventSelector_FrameTimeout,  //!< Selects the frame timeout event for enabling.
        EventSelector_AcquisitionStart,  //!< Selects the acquisition start trigger event for enabling.
        EventSelector_ActionLate,  //!< TODO
        EventSelector_Line1RisingEdge,  //!< 
        EventSelector_Line2RisingEdge,  //!< 
        EventSelector_Line3RisingEdge,  //!< 
        EventSelector_Line4RisingEdge,  //!< 
        EventSelector_VirtualLine1RisingEdge,  //!< 
        EventSelector_VirtualLine2RisingEdge,  //!< 
        EventSelector_VirtualLine3RisingEdge,  //!< 
        EventSelector_VirtualLine4RisingEdge,  //!< 
        EventSelector_FrameWait,  //!< Selects the frame wait trigger event for enabling.
        EventSelector_AcquisitionWait,  //!< Selects the acquisition wait trigger event for enabling.
        EventSelector_AcquisitionStartWait,  //!< Event notifications for the acquisition start wait event can be enabled.
        EventSelector_EventOverrun  //!< Selects the event overrun event for enabling.
    };

    //! Valid values for ExpertFeatureAccessSelector
    enum ExpertFeatureAccessSelectorEnums
    {
        ExpertFeatureAccessSelector_ExpertFeature1,  //!< Expert feature 1 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature2,  //!< Expert feature 2 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature3,  //!< Expert feature 3 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature4,  //!< Expert feature 4 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature5,  //!< Expert feature 5 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature6,  //!< Expert feature 6 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature7,  //!< Expert feature 7 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature8,  //!< Expert feature 8 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature9,  //!< Expert feature 9 can be configured.
        ExpertFeatureAccessSelector_ExpertFeature1_Legacy,  //!< Selects the Expert Feature 1 for configuration
        ExpertFeatureAccessSelector_ExpertFeature10  //!< Expert feature 10 can be configured.
    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Off,  //!< The exposure time auto function is disabled.
        ExposureAuto_Once,  //!< Exposure time is adjusted automatically until it reaches a specific target value.
        ExposureAuto_Continuous  //!< Exposure time is adjusted repeatedly while images are acquired.
    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!< The timed exposure mode is set.
        ExposureMode_TriggerWidth,  //!< The trigger width exposure mode is set.
        ExposureMode_Off,  //!< Sets the exposure mode to off
        ExposureMode_TriggerControlled  //!< Sets the exposure mode to trigger controlled
    };

    //! Valid values for ExposureOverlapTimeMode
    enum ExposureOverlapTimeModeEnums
    {
        ExposureOverlapTimeMode_Manual,  //!< The camera manually sets the overlap time for each acquisition.
        ExposureOverlapTimeMode_Automatic  //!< The camera automatically uses the optimum overlap time for each acquisition.
    };

    //! Valid values for FeatureSet
    enum FeatureSetEnums
    {
        FeatureSet_Full,  //!< The 'Full' camera description file provides all features.
        FeatureSet_Basic  //!< The 'Basic' camera description file provides nearly all features.
    };

    //! Valid values for FieldOutputMode
    enum FieldOutputModeEnums
    {
        FieldOutputMode_Field0,  //!< Sets the mode to only output field 0.
        FieldOutputMode_Field1,  //!< Sets the mode to only output field 1.
        FieldOutputMode_Field0First,  //!< Sets the mode to only output field 0 and field 1 in single frames. Starting with field 0.
        FieldOutputMode_ConcatenatedNewFields,  //!< Sets the mode to output a frame consisting of field 0 in the upper half and field 1 in the lower half of the frame.
        FieldOutputMode_DeinterlacedNewFields  //!< Sets the mode to output a frame generated by deinterlacing field 0 and field 1 using the deinterlacer selected by feature Deinterlacer. 
    };

    //! Valid values for FileOpenMode
    enum FileOpenModeEnums
    {
        FileOpenMode_Read,  //!< Files are opened in read-only mode.
        FileOpenMode_Write  //!< Files are opened in write-only mode.
    };

    //! Valid values for FileOperationSelector
    enum FileOperationSelectorEnums
    {
        FileOperationSelector_Open,  //!< The currently selected file can be opened.
        FileOperationSelector_Close,  //!< The currently selected file can be closed.
        FileOperationSelector_Read,  //!< The currently selected file can be read.
        FileOperationSelector_Write  //!< The currently selected file can be written.
    };

    //! Valid values for FileOperationStatus
    enum FileOperationStatusEnums
    {
        FileOperationStatus_Success,  //!< The file operation was successful.
        FileOperationStatus_Failure  //!< The file operation has failed.
    };

    //! Valid values for FileSelector
    enum FileSelectorEnums
    {
        FileSelector_UserData,  //!< The 'User Data' file is set.
        FileSelector_UserSet1,  //!< The 'User Set 1' file is set.
        FileSelector_UserSet2,  //!< The 'User Set 2' file is set.
        FileSelector_UserSet3,  //!< The 'User Set 3' file is set.
        FileSelector_UserGainShading1,  //!< The 'User Gain Shading 1' file is set.
        FileSelector_UserGainShading2,  //!< The 'User Gain Shading 2' file is set.
        FileSelector_UserOffsetShading1,  //!< The 'User Offset Shading 1' file is set.
        FileSelector_UserOffsetShading2,  //!< The 'User Offset Shading 2' file is set.
        FileSelector_ExpertFeature7File  //!< The 'Expert Feature 7 File' file is set.
    };

    //! Valid values for FrequencyConverterInputSource
    enum FrequencyConverterInputSourceEnums
    {
        FrequencyConverterInputSource_Line1,  //!< Selects line 1 as the input source.
        FrequencyConverterInputSource_Line2,  //!< Selects line 2 as the input source.
        FrequencyConverterInputSource_Line3,  //!< Selects line 3 as the input source.
        FrequencyConverterInputSource_Line4,  //!< Selects line 4 as the input source.
        FrequencyConverterInputSource_Line5,  //!< Selects line 5 as the input source.
        FrequencyConverterInputSource_Line6,  //!< Selects line 6 as the input source. 
        FrequencyConverterInputSource_Line7,  //!< Selects line 7 as the input source.
        FrequencyConverterInputSource_Line8,  //!< Selects line 8 as the input source.
        FrequencyConverterInputSource_CC1,  //!< Selects CC1 as the input source.
        FrequencyConverterInputSource_CC2,  //!< Selects CC2 as the input source.
        FrequencyConverterInputSource_CC3,  //!< Selects CC3 as the input source.
        FrequencyConverterInputSource_CC4,  //!< Selects CC4 as the input source.
        FrequencyConverterInputSource_ShaftEncoderModuleOut  //!< Selects the output of the shaft encoder module as the input source.
    };

    //! Valid values for FrequencyConverterSignalAlignment
    enum FrequencyConverterSignalAlignmentEnums
    {
        FrequencyConverterSignalAlignment_RisingEdge,  //!< For the rising edge of each received signal a rising edge of a generated signal is provided.
        FrequencyConverterSignalAlignment_FallingEdge  //!< For the falling edge of each received signal a falling edge of a generated signal is provided.
    };

    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Off,  //!< The gain auto function is disabled.
        GainAuto_Once,  //!< Gain is adjusted automatically until it reaches a specific target value.
        GainAuto_Continuous  //!< Gain is adjusted repeatedly while images are acquired.
    };

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All,  //!< Gain will be applied to all channels or taps.
        GainSelector_DigitalAll,  //!< Gain will be applied to all digital channels.
        GainSelector_AnalogAll,  //!< Gain will be applied to all analog channels.
        GainSelector_Tap1,  //!< Selects the tap 1 gain control for adjustment
        GainSelector_Tap2,  //!< Selects the tap 2 gain control for adjustment
        GainSelector_Tap3,  //!< Selects the tap 3 gain control for adjustment
        GainSelector_Tap4,  //!< Selects the tap 4 gain control for adjustment
        GainSelector_Red,  //!< Selects the red gain control for adjustment
        GainSelector_Green,  //!< Selects the green gain control for adjustment
        GainSelector_Blue  //!< Selects the blue gain control for adjustment
    };

    //! Valid values for GammaSelector
    enum GammaSelectorEnums
    {
        GammaSelector_User,  //!< Sets gamma to user defined curve
        GammaSelector_sRGB  //!< Sets gamma to fixed sRGB curve.
    };

    //! Valid values for GevCCP
    enum GevCCPEnums
    {
        GevCCP_Exclusive,  //!< Sets the control channel privilege feature to exclusive
        GevCCP_Control,  //!< Sets the control channel privilege feature to control
        GevCCP_ExclusiveControl  //!< Sets the control channel privilege feature to exclusive control
    };

    //! Valid values for GevGVSPExtendedIDMode
    enum GevGVSPExtendedIDModeEnums
    {
        GevGVSPExtendedIDMode_Off,  //!< Off
        GevGVSPExtendedIDMode_On  //!< On
    };

    //! Valid values for GevIEEE1588Status
    enum GevIEEE1588StatusEnums
    {
        GevIEEE1588Status_Undefined,  //!< Undefined
        GevIEEE1588Status_Initializing,  //!< Initializing
        GevIEEE1588Status_Faulty,  //!< Faulty
        GevIEEE1588Status_Disabled,  //!< Disabled
        GevIEEE1588Status_Listening,  //!< Listening
        GevIEEE1588Status_PreMaster,  //!< PreMaster
        GevIEEE1588Status_Master,  //!< Master
        GevIEEE1588Status_Passive,  //!< Passive
        GevIEEE1588Status_Uncalibrated,  //!< Uncalibrated
        GevIEEE1588Status_Slave  //!< Slave
    };

    //! Valid values for GevIEEE1588StatusLatched
    enum GevIEEE1588StatusLatchedEnums
    {
        GevIEEE1588StatusLatched_Undefined,  //!< Undefined
        GevIEEE1588StatusLatched_Initializing,  //!< Initializing
        GevIEEE1588StatusLatched_Faulty,  //!< Faulty
        GevIEEE1588StatusLatched_Disabled,  //!< Disabled
        GevIEEE1588StatusLatched_Listening,  //!< Listening
        GevIEEE1588StatusLatched_PreMaster,  //!< PreMaster
        GevIEEE1588StatusLatched_Master,  //!< Master
        GevIEEE1588StatusLatched_Passive,  //!< Passive
        GevIEEE1588StatusLatched_Uncalibrated,  //!< Uncalibrated
        GevIEEE1588StatusLatched_Slave  //!< Slave
    };

    //! Valid values for GevInterfaceSelector
    enum GevInterfaceSelectorEnums
    {
        GevInterfaceSelector_NetworkInterface0  //!< Selects network interface 0 for configuration
    };

    //! Valid values for GevStreamChannelSelector
    enum GevStreamChannelSelectorEnums
    {
        GevStreamChannelSelector_StreamChannel0  //!< Selects stream channel 0 for configuration
    };

    //! Valid values for ImageFileMode
    enum ImageFileModeEnums
    {
        ImageFileMode_Off,  //!< Sets the mode to off.
        ImageFileMode_On  //!< Sets the mode to on.
    };

    //! Valid values for InterlacedIntegrationMode
    enum InterlacedIntegrationModeEnums
    {
        InterlacedIntegrationMode_FieldIntegration,  //!< Sets the integration mode to field integration
        InterlacedIntegrationMode_FrameIntegration  //!< Sets the integration mode to frame integration
    };

    //! Valid values for LUTSelector
    enum LUTSelectorEnums
    {
        LUTSelector_Luminance  //!< The luminance lookup table can be configured.
    };

    //! Valid values for LastError
    enum LastErrorEnums
    {
        LastError_NoError,  //!< Indicates that no error was detected
        LastError_Overtrigger,  //!< Indicates that the camera was overtriggered
        LastError_Userset,  //!< Indicates an error was detected while loading a userset
        LastError_InvalidParameter,  //!< Indicates that a parameter was set to an invalid value
        LastError_OverTemperature,  //!< The over temperature state has been detected
        LastError_PowerFailure,  //!< Indicates that the power supply is not sufficient
        LastError_InsufficientTriggerWidth,  //!< The trigger width was too short.
        LastError_UserDefPixFailure  //!< Indicates an user defect pixel failure
    };

    //! Valid values for LegacyBinningVertical
    enum LegacyBinningVerticalEnums
    {
        LegacyBinningVertical_Off,  //!< Sets vertical binning to disabled
        LegacyBinningVertical_Two_Rows  //!< Sets vertical binning to 2 rows
    };

    //! Valid values for LightSourcePreset
    enum LightSourcePresetEnums
    {
        LightSourcePreset_Off,  //!< No color preset is set.
        LightSourcePreset_Daylight5000K,  //!< A color preset for image acquisition with daylight of 5000 K is set.
        LightSourcePreset_Daylight6500K,  //!< A color preset for image acquisition with daylight of 6500 K is set.
        LightSourcePreset_Tungsten2800K  //!< A color preset for image acquisition with tungsten incandescent light (2800 K) is set.
    };

    //! Valid values for LightSourceSelector
    enum LightSourceSelectorEnums
    {
        LightSourceSelector_Off,  //!< No matrix color transformation for specific light source is performed.
        LightSourceSelector_Custom,  //!< Allows using a custom defined color transformation matrix.
        LightSourceSelector_Daylight,  //!< The matrix is optimized for image acquisition with daylight of 5000 K.
        LightSourceSelector_Tungsten,  //!< The matrix is optimized for image acquisition with tungsten incandescent light (3100 K).
        LightSourceSelector_Daylight6500K,  //!< The matrix is optimized for image acquisition with daylight of 6500 K.
        LightSourceSelector_LightSource0,  //!< 
        LightSourceSelector_LightSource1  //!< 
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_NoConnect,  //!< The line is not connected.
        LineFormat_TriState,  //!< The line is currently in tri-state mode (not driven).
        LineFormat_TTL,  //!< The line is currently accepting or sending TTL level signals.
        LineFormat_LVDS,  //!< The line is currently accepting or sending LVDS level signals.
        LineFormat_RS422,  //!< The line is currently accepting or sending RS-422 level signals.
        LineFormat_OptoCoupled,  //!< The line is opto-coupled.
        LineFormat_LVTTL  //!< The line is currently accepting or sending LVTTL level signals.
    };

    //! Valid values for LineLogic
    enum LineLogicEnums
    {
        LineLogic_Positive,  //!< The line logic of the currently selected line is positive.
        LineLogic_Negative  //!< The line logic of the currently selected line is negative.
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!< The selected physical line can be used to input an electrical signal.
        LineMode_Output  //!< The selected physical line can be used to output an electrical signal.
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!< Line 1 can be configured.
        LineSelector_Line2,  //!< Line 2 can be configured.
        LineSelector_Line3,  //!< Line 3 can be configured.
        LineSelector_Line4,  //!< Line 4 can be configured.
        LineSelector_Out1,  //!< Selects output line 1 for configuration
        LineSelector_Out2,  //!< Selects output line 2 for configuration
        LineSelector_Out3,  //!< Selects output line 3 for configuration
        LineSelector_Out4,  //!< Selects output line 4 for configuration
        LineSelector_Line5,  //!< Selects line 5 for configuration
        LineSelector_Line6,  //!< Selects line 6 for configuration
        LineSelector_Line7,  //!< Selects line 7 for configuration
        LineSelector_Line8,  //!< Selects line 8 for configuration
        LineSelector_CC1,  //!< Selects CC1 for configuration
        LineSelector_CC2,  //!< Selects CC2 for configuration
        LineSelector_CC3,  //!< Selects CC3 for configuration
        LineSelector_CC4,  //!< Selects CC4 for configuration
        LineSelector_ClSpare,  //!< Selects CL Spare for configuration
        LineSelector_In1,  //!< Selects input line 1 for configuration
        LineSelector_In2,  //!< Selects input line 2 for configuration
        LineSelector_In3,  //!< Selects input line 3 for configuration
        LineSelector_In4  //!< Selects input line 4 for configuration
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_Off,  //!< No source signal is set for the currently selected line.
        LineSource_ExposureActive,  //!< The source signal for the currently selected line is set to the exposure active signal.
        LineSource_FrameTriggerWait,  //!< The source signal for the currently selected line is set to the frame trigger wait signal.
        LineSource_FrameBurstTriggerWait,  //!< The source signal for the currently selected line is set to the frame burst trigger wait signal.
        LineSource_Timer1Active,  //!< Sets the source signal for the selected output line to timer 1 active
        LineSource_UserOutput0,  //!< Sets the source signal for the selected output line to user settable output signal 0.
        LineSource_UserOutput1,  //!< Sets the source signal for the selected output line to user settable output signal 1.
        LineSource_UserOutput2,  //!< Sets the source signal for the selected output line to user settable output signal 2.
        LineSource_UserOutput3,  //!< Sets the source signal for the selected output line to user settable output signal 3.
        LineSource_FlashWindow,  //!< The source signal for the currently selected line is set to the flash window signal.
        LineSource_UserOutput4,  //!< The User Output 4 bit state as defined by its current UserOutputValue.
        LineSource_LineTriggerWait,  //!< Associates the Line Trigger Wait status with the selected output line.
        LineSource_Timer2Active,  //!< Sets the source signal for the selected output line to timer 2 active
        LineSource_Timer3Active,  //!< Sets the source signal for the selected output line to timer 3 active
        LineSource_Timer4Active,  //!< Sets the source signal for the selected output line to timer 4 active
        LineSource_TimerActive,  //!< 
        LineSource_UserOutput,  //!< 
        LineSource_TriggerReady,  //!< 
        LineSource_SerialTx,  //!< 
        LineSource_AcquisitionTriggerWait,  //!< Associates the Acquisition Trigger Wait status with the selected output line.
        LineSource_ShaftEncoderModuleOut,  //!< Associates the output of the shaft encoder module with the selected output line.
        LineSource_FrequencyConverter,  //!< Associates the output of the frequency converter module with the selected output line.
        LineSource_PatternGenerator1,  //!< 
        LineSource_PatternGenerator2,  //!< 
        LineSource_PatternGenerator3,  //!< 
        LineSource_PatternGenerator4,  //!< 
        LineSource_AcquisitionTriggerReady,  //!< 
        LineSource_FrameCycle,  //!< This signal is rising with frame trigger wait and falling with exposure active
        LineSource_SyncUserOutput,  //!< 
        LineSource_SyncUserOutput0,  //!< The source signal for the currently selected line is set to the sync user settable signal 0.
        LineSource_SyncUserOutput1,  //!< The source signal for the currently selected line is set to the sync user settable signal 1.
        LineSource_SyncUserOutput2,  //!< The source signal for the currently selected line is set to the sync user settable signal 2.
        LineSource_SyncUserOutput3  //!< The source signal for the currently selected line is set to the sync user settable signal 3.
    };

    //! Valid values for OverlapMode
    enum OverlapModeEnums
    {
        OverlapMode_On,  //!< Overlapping exposure and image readout.
        OverlapMode_Off  //!< Non-overlapping exposure and image readout.
    };

    //! Valid values for ParameterSelector
    enum ParameterSelectorEnums
    {
        ParameterSelector_Gain,  //!< Selects the gain limits for configuration
        ParameterSelector_Brightness,  //!< Selects the brightness limits for configuration
        ParameterSelector_BlackLevel,  //!< Selects the blacklevel limits for configuration
        ParameterSelector_ExposureTime,  //!< Selects the exposure time limits for configuration
        ParameterSelector_Framerate,  //!< Selects the framerate limits for configuration
        ParameterSelector_AutoTargetValue,  //!< Selects the target gray value for atuofunc
        ParameterSelector_ExposureOverhead,  //!< Selects the exposure overhead limits for configuration
        ParameterSelector_ExposureOverlapMax  //!< Selects the exposure overlap time max limit for configuration
    };

    //! Valid values for PgiMode
    enum PgiModeEnums
    {
        PgiMode_Off,  //!< Basler PGI image optimizations are disabled.
        PgiMode_On  //!< Basler PGI image optimizations are enabled.
    };

    //! Valid values for PixelCoding
    enum PixelCodingEnums
    {
        PixelCoding_Mono8,  //!< 
        PixelCoding_Mono8Signed,  //!< 
        PixelCoding_Mono16,  //!< 
        PixelCoding_Mono10Packed,  //!< 
        PixelCoding_Mono12Packed,  //!< 
        PixelCoding_Raw8,  //!< 
        PixelCoding_Raw16,  //!< 
        PixelCoding_RGB8,  //!< 
        PixelCoding_BGR8,  //!< 
        PixelCoding_RGBA8,  //!< 
        PixelCoding_BGRA8,  //!< 
        PixelCoding_RGB16,  //!< 
        PixelCoding_BGR16,  //!< 
        PixelCoding_RGB10V1Packed,  //!< 
        PixelCoding_RGB10V2Packed,  //!< 
        PixelCoding_YUV411,  //!< 
        PixelCoding_YUV422,  //!< 
        PixelCoding_YUV444,  //!< 
        PixelCoding_RGB8Planar,  //!< 
        PixelCoding_RGB16Planar,  //!< 
        PixelCoding_BayerGR10p,  //!< Sets the pixel format to Bayer GR 10p
        PixelCoding_BayerRG10p,  //!< Sets the pixel format to Bayer RG 10p
        PixelCoding_BayerGB10p,  //!< Sets the pixel format to Bayer GB 10p
        PixelCoding_BayerBG10p  //!< Sets the pixel format to Bayer BG 10p
    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_None,  //!< No Bayer filter is present on the camera.
        PixelColorFilter_BayerRG,  //!< The Bayer filter has an RG/GB alignment to the pixels in the acquired images.
        PixelColorFilter_BayerGB,  //!< The Bayer filter has a GB/RG alignment to the pixels in the acquired images.
        PixelColorFilter_BayerGR,  //!< The Bayer filter has a GR/BG alignment to the pixels in the acquired images.
        PixelColorFilter_BayerBG,  //!< The Bayer filter has a BG/GR alignment to the pixels in the acquired images.
        PixelColorFilter_Bayer_RG,  //!< Indicates that the Bayer filter has an RG/GB alignment to the pixels in the acquired images
        PixelColorFilter_Bayer_GB,  //!< Indicates that the Bayer filter has a GB/RG alignment to the pixels in the acquired images
        PixelColorFilter_Bayer_GR,  //!< Indicates that the Bayer filter has a GR/BG alignment to the pixels in the acquired images
        PixelColorFilter_Bayer_BG  //!< Indicates that the Bayer filter has a BG/GR alignment to the pixels in the acquired images
    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_Mono8,  //!< The pixel format is set to Mono 8.
        PixelFormat_Mono10,  //!< The pixel format is set to Mono 10.
        PixelFormat_Mono10p,  //!< The pixel format is set to Mono 10p.
        PixelFormat_Mono12,  //!< The pixel format is set to Mono 12.
        PixelFormat_Mono12p,  //!< The pixel format is set to Mono 12p.
        PixelFormat_BayerGR8,  //!< The pixel format is set to Bayer GR 8.
        PixelFormat_BayerRG8,  //!< The pixel format is set to Bayer RG 8.
        PixelFormat_BayerGB8,  //!< The pixel format is set to Bayer GB 8.
        PixelFormat_BayerBG8,  //!< The pixel format is set to Bayer BG 8.
        PixelFormat_BayerGR10,  //!< The pixel format is set to Bayer GR 10.
        PixelFormat_BayerGR10p,  //!< The pixel format is set to Bayer GR 10p.
        PixelFormat_BayerRG10,  //!< The pixel format is set to Bayer RG 10.
        PixelFormat_BayerRG10p,  //!< The pixel format is set to Bayer RG 10p.
        PixelFormat_BayerGB10,  //!< The pixel format is set to Bayer GB 10.
        PixelFormat_BayerGB10p,  //!< The pixel format is set to Bayer GB 10p.
        PixelFormat_BayerBG10,  //!< The pixel format is set to Bayer BG 10.
        PixelFormat_BayerBG10p,  //!< The pixel format is set to Bayer BG 10p.
        PixelFormat_BayerGR12,  //!< The pixel format is set to Bayer GR 12.
        PixelFormat_BayerGR12p,  //!< The pixel format is set to Bayer GR 12p.
        PixelFormat_BayerRG12,  //!< The pixel format is set to Bayer RG 12.
        PixelFormat_BayerRG12p,  //!< The pixel format is set to Bayer RG 12p.
        PixelFormat_BayerGB12,  //!< The pixel format is set to Bayer GB 12.
        PixelFormat_BayerGB12p,  //!< The pixel format is set to Bayer GB 12p.
        PixelFormat_BayerBG12,  //!< The pixel format is set to Bayer BG 12.
        PixelFormat_BayerBG12p,  //!< The pixel format is set to Bayer BG 12p.
        PixelFormat_RGB8,  //!< The pixel format is set to RGB 8
        PixelFormat_BGR8,  //!< The pixel format is set to BGR 8
        PixelFormat_YCbCr422_8,  //!< The pixel format is set to YCbCr 422.
        PixelFormat_Mono10Packed,  //!< Sets the pixel format to Mono 10 Packed
        PixelFormat_Mono12Packed,  //!< Sets the pixel format to Mono 12 Packed
        PixelFormat_Mono16,  //!< Sets the pixel format to Mono 16
        PixelFormat_RGB8Packed,  //!< Sets the pixel format to RGB 8 Packed
        PixelFormat_BGR8Packed,  //!< Sets the pixel format to BGR 8 Packed
        PixelFormat_RGBA8Packed,  //!< Sets the pixel format to RGBA 8 Packed
        PixelFormat_BGRA8Packed,  //!< Sets the pixel format to BGRA 8 Packed
        PixelFormat_RGB10Packed,  //!< Sets the pixel format to RGB 10 Packed
        PixelFormat_BGR10Packed,  //!< Sets the pixel format to BGR 10 Packed
        PixelFormat_RGB12Packed,  //!< Sets the pixel format to RGB 12 Packed
        PixelFormat_BGR12Packed,  //!< Sets the pixel format to BGR 12 Packed
        PixelFormat_RGB10V1Packed,  //!< Sets the pixel format to RGB 10V1 Packed
        PixelFormat_RGB10V2Packed,  //!< Sets the pixel format to RGB 10V2 Packed
        PixelFormat_YUV411Packed,  //!< Sets the pixel format to YUV 411 Packed
        PixelFormat_YUV422Packed,  //!< Sets the pixel format to YUV 422 Packed
        PixelFormat_YUV444Packed,  //!< Sets the pixel format to YUV 444 Packed
        PixelFormat_RGB8Planar,  //!< Sets the pixel format to RGB 8 Planar
        PixelFormat_RGB10Planar,  //!< Sets the pixel format to RGB 10 Planar
        PixelFormat_RGB12Planar,  //!< Sets the pixel format to RGB 12 Planar
        PixelFormat_RGB16Planar,  //!< Sets the pixel format to RGB 16 Planar
        PixelFormat_YUV422_YUYV_Packed,  //!< Sets the pixel format to YUV 422 (YUYV) Packed
        PixelFormat_BayerGB12Packed,  //!< Sets the pixel format to Bayer GB 12 Packed
        PixelFormat_BayerGR12Packed,  //!< Sets the pixel format to Bayer GR 12 Packed
        PixelFormat_BayerRG12Packed,  //!< Sets the pixel format to Bayer RG 12 Packed
        PixelFormat_BayerBG12Packed,  //!< Sets the pixel format to Bayer BG 12 Packed
        PixelFormat_BayerGR16,  //!< Sets the pixel format to Bayer GR 16
        PixelFormat_BayerRG16,  //!< Sets the pixel format to Bayer RG 16
        PixelFormat_BayerGB16,  //!< Sets the pixel format to Bayer GB 16
        PixelFormat_BayerBG16,  //!< Sets the pixel format to Bayer BG 16
        PixelFormat_RGB12V1Packed,  //!< Sets the pixel format to RGB 12 Packed 
        PixelFormat_Mono8Signed,  //!< Sets the pixel format to Mono 8 Signed
        PixelFormat_Mono1Packed,  //!< Sets the pixel format to Mono 1 Packed
        PixelFormat_Mono2Packed,  //!< Sets the pixel format to Mono 2 Packed
        PixelFormat_Mono4Packed,  //!< Sets the pixel format to Mono 4 Packed
        PixelFormat_RGB16Packed  //!< Sets the pixel format to RGB 16 Packed.
    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp1,  //!< The depth of the pixel values in the acquired images is 1 bit per pixel.
        PixelSize_Bpp2,  //!< The depth of the pixel values in the acquired images is 2 bits per pixel.
        PixelSize_Bpp4,  //!< The depth of the pixel values in the acquired images is 4 bits per pixel.
        PixelSize_Bpp8,  //!< The depth of the pixel values in the acquired images is 8 bits per pixel.
        PixelSize_Bpp10,  //!< The depth of the pixel values in the acquired images is 10 bits per pixel.
        PixelSize_Bpp12,  //!< The depth of the pixel values in the acquired images is 12 bits per pixel.
        PixelSize_Bpp16,  //!< The depth of the pixel values in the acquired images is 16 bits per pixel.
        PixelSize_Bpp24,  //!< The depth of the pixel values in the acquired images is 24 bits per pixel.
        PixelSize_Bpp14,  //!< Indicates that the depth of the pixel values in the acquired images is 12 bits per pixel
        PixelSize_Bpp32,  //!< Indicates that the depth of the pixel values in the acquired images is 32 bits per pixel
        PixelSize_Bpp36,  //!< Indicates that the depth of the pixel values in the acquired images is 36 bits per pixel
        PixelSize_Bpp48,  //!< Indicates that the depth of the pixel values in the acquired images is 48 bits per pixel
        PixelSize_Bpp64  //!< Indicates that the depth of the pixel values in the acquired images is 64 bits per pixel
    };

    //! Valid values for ROIZoneMode
    enum ROIZoneModeEnums
    {
        ROIZoneMode_Off,  //!< Disables a ROI zone.
        ROIZoneMode_On  //!< Enables a ROI zone.
    };

    //! Valid values for ROIZoneSelector
    enum ROIZoneSelectorEnums
    {
        ROIZoneSelector_Zone0,  //!< Sets vertical ROI zone 0
        ROIZoneSelector_Zone1,  //!< Sets vertical ROI zone 1
        ROIZoneSelector_Zone2,  //!< Sets vertical ROI zone 2
        ROIZoneSelector_Zone3,  //!< Sets vertical ROI zone 3
        ROIZoneSelector_Zone4,  //!< Sets vertical ROI zone 4
        ROIZoneSelector_Zone5,  //!< Sets vertical ROI zone 5
        ROIZoneSelector_Zone6,  //!< Sets vertical ROI zone 6
        ROIZoneSelector_Zone7  //!< Sets vertical ROI zone 7
    };

    //! Valid values for RemoveParameterLimitSelector
    enum RemoveParameterLimitSelectorEnums
    {
        RemoveParameterLimitSelector_Gain,  //!< The factory limits of the Gain parameter can be removed.
        RemoveParameterLimitSelector_BlackLevel,  //!< The factory limits of the BlackLevel parameter can be removed.
        RemoveParameterLimitSelector_ExposureTime,  //!< The factory limits of the ExposureTime parameter can be removed.
        RemoveParameterLimitSelector_AutoTargetValue,  //!< The factory limits of the AutoTargetValue parameter can be removed.
        RemoveParameterLimitSelector_ExposureOverhead  //!< The factory limits of the ExposureOverhead parameter can be removed.
    };

    //! Valid values for SensorBitDepth
    enum SensorBitDepthEnums
    {
        SensorBitDepth_BitDepth8,  //!< 
        SensorBitDepth_BitDepth10,  //!< 
        SensorBitDepth_BitDepth12,  //!< 
        SensorBitDepth_BitDepth14,  //!< 
        SensorBitDepth_BitDepth16  //!< 
    };

    //! Valid values for SensorDigitizationTaps
    enum SensorDigitizationTapsEnums
    {
        SensorDigitizationTaps_One,  //!< 
        SensorDigitizationTaps_Two,  //!< 
        SensorDigitizationTaps_Three,  //!< 
        SensorDigitizationTaps_Four  //!< 
    };

    //! Valid values for SensorReadoutMode
    enum SensorReadoutModeEnums
    {
        SensorReadoutMode_Normal,  //!< The device operates in normal readout mode.
        SensorReadoutMode_Fast  //!< The device operates in fast readout mode.
    };

    //! Valid values for SensorShutterMode
    enum SensorShutterModeEnums
    {
        SensorShutterMode_Global,  //!< The shutter opens and closes at the same time for all pixels.
        SensorShutterMode_Rolling,  //!< The shutter opens and closes sequentially for groups (typically lines) of pixels.
        SensorShutterMode_GlobalReset  //!< The shutter opens at the same time for all pixels but ends in a sequential manner.
    };

    //! Valid values for SequenceAddressBitSelector
    enum SequenceAddressBitSelectorEnums
    {
        SequenceAddressBitSelector_Bit0,  //!< Selects bit 0 of the sequence set address
        SequenceAddressBitSelector_Bit1,  //!< Selects bit 1 of the sequence set address
        SequenceAddressBitSelector_Bit2,  //!< Selects bit 2 of the sequence set address
        SequenceAddressBitSelector_Bit3  //!< Selects bit 3 of the sequence set address
    };

    //! Valid values for SequenceAddressBitSource
    enum SequenceAddressBitSourceEnums
    {
        SequenceAddressBitSource_Line1,  //!< Selects line 1 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_Line2,  //!< Selects line 2 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_Line3,  //!< Selects line 3 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_Line4,  //!< Selects line 4 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_Line5,  //!< Selects line 5 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_Line6,  //!< Selects line 6 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_Line7,  //!< Selects line 7 as the source for the selected bit of the sequence set address.
        SequenceAddressBitSource_Line8,  //!< Selects line 8 as the source for the selected bit of the sequence set address.
        SequenceAddressBitSource_CC1,  //!< Selects CC1 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_CC2,  //!< Selects CC2 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_CC3,  //!< Selects CC3 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_CC4,  //!< Selects CC4 as the source for the selected bit of the sequence set address.
        SequenceAddressBitSource_VInput1,  //!< Selects Virtual Input 1 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_VInput2,  //!< Selects Virtual Input 2 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_VInput3,  //!< Selects Virtual Input 3 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_VInput4,  //!< Selects Virtual Input 4 as the source for the selected bit of the sequence set address
        SequenceAddressBitSource_VInputDecActive  //!< Selects Virtual Input Decoder Active as the source for the selected bit of the sequence set address
    };

    //! Valid values for SequenceAdvanceMode
    enum SequenceAdvanceModeEnums
    {
        SequenceAdvanceMode_Auto,  //!< Automatic sequence set advance
        SequenceAdvanceMode_Controlled,  //!< Sequence set advance controlled by settable source
        SequenceAdvanceMode_FreeSelection  //!< The sequence sets are selected according to the states of the input lines
    };

    //! Valid values for SequenceConfigurationMode
    enum SequenceConfigurationModeEnums
    {
        SequenceConfigurationMode_Off,  //!< Disables the sequencer for configuration
        SequenceConfigurationMode_On  //!< Enables the sequencer for configuration
    };

    //! Valid values for SequenceControlSelector
    enum SequenceControlSelectorEnums
    {
        SequenceControlSelector_Restart,  //!< Selects controls for sequence restart
        SequenceControlSelector_Advance  //!< Selects controls for sequence set advance
    };

    //! Valid values for SequenceControlSource
    enum SequenceControlSourceEnums
    {
        SequenceControlSource_Disabled,  //!< Advance via asynchronous advance only
        SequenceControlSource_AlwaysActive,  //!< Automatic sequence set advance. The sequence repeat starts with sequence set index number 1
        SequenceControlSource_Line1,  //!< The source for sequence restart or sequence set advance is line 1
        SequenceControlSource_Line2,  //!< The source for sequence restart or sequence set advance is line 2
        SequenceControlSource_Line3,  //!< The source for sequence restart or sequence set advance is line 3
        SequenceControlSource_Line4,  //!< The source for sequence restart or sequence set advance is line 4
        SequenceControlSource_Line5,  //!< The source for sequence restart or sequence set advance is line 5
        SequenceControlSource_Line6,  //!< The source for sequence restart or sequence set advance is line 6
        SequenceControlSource_Line7,  //!< The source for sequence restart or sequence set advance is line 7
        SequenceControlSource_Line8,  //!< The source for sequence restart or sequence set advance is line 8
        SequenceControlSource_CC1,  //!< The source for sequence restart or sequence set advance is CC1
        SequenceControlSource_CC2,  //!< The source for sequence restart or sequence set advance is CC2
        SequenceControlSource_CC3,  //!< The source for sequence restart or sequence set advance is CC3
        SequenceControlSource_CC4,  //!< The source for sequence restart or sequence set advance is CC4
        SequenceControlSource_VInput1,  //!< The source for sequence restart or sequence set advance is Virtual Input 1
        SequenceControlSource_VInput2,  //!< The source for sequence restart or sequence set advance is Virtual Input 2
        SequenceControlSource_VInput3,  //!< The source for sequence restart or sequence set advance is Virtual Input 3
        SequenceControlSource_VInput4,  //!< The source for sequence restart or sequence set advance is Virtual Input 4
        SequenceControlSource_VInputDecActive  //!< The source for sequence restart or sequence set advance is Virtual Input Decoder Active
    };

    //! Valid values for SequencerConfigurationMode
    enum SequencerConfigurationModeEnums
    {
        SequencerConfigurationMode_Off,  //!< The sequencer can not be configured.
        SequencerConfigurationMode_On  //!< The sequencer can be configured.
    };

    //! Valid values for SequencerMode
    enum SequencerModeEnums
    {
        SequencerMode_Off,  //!< The sequencer can not be used for image acquisition.
        SequencerMode_On  //!< The sequencer can be used for image acquisition.
    };

    //! Valid values for SequencerTriggerActivation
    enum SequencerTriggerActivationEnums
    {
        SequencerTriggerActivation_RisingEdge,  //!< The sequence set will advance on the rising edge of the source signal.
        SequencerTriggerActivation_FallingEdge,  //!< The sequence set will advance on the falling edge of the source signal.
        SequencerTriggerActivation_AnyEdge,  //!< The sequence set will advance on the falling or rising edge of the source signal.
        SequencerTriggerActivation_LevelHigh,  //!< The sequence set will advance when the source signal is high.
        SequencerTriggerActivation_LevelLow  //!< The sequence set will advance when the source signal is low.
    };

    //! Valid values for SequencerTriggerSource
    enum SequencerTriggerSourceEnums
    {
        SequencerTriggerSource_Line1,  //!< Line 1 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_Line2,  //!< Line 2 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_Line3,  //!< Line 3 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_Line4,  //!< Line 4 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_SoftwareSignal1,  //!< Software signal 1 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_SoftwareSignal2,  //!< Software signal 2 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_SoftwareSignal3,  //!< Software signal 3 is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_Counter1End,  //!< Counter 1 End is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_Counter2End,  //!< Counter 2 End is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_Counter3End,  //!< Counter 3 End is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_FrameStart,  //!< Frame Start is selected as the trigger source for sequencer set advance.
        SequencerTriggerSource_FrameEnd  //!< Frame End is selected as the trigger source for sequencer set advance.
    };

    //! Valid values for ShadingSelector
    enum ShadingSelectorEnums
    {
        ShadingSelector_OffsetShading,  //!< Selects offset shading correction.
        ShadingSelector_GainShading  //!< Selects gain shading correction.
    };

    //! Valid values for ShadingSetCreate
    enum ShadingSetCreateEnums
    {
        ShadingSetCreate_Off,  //!< 
        ShadingSetCreate_Once  //!< 
    };

    //! Valid values for ShadingSetDefaultSelector
    enum ShadingSetDefaultSelectorEnums
    {
        ShadingSetDefaultSelector_DefaultShadingSet,  //!< Selects the default shading set as the bootup shading set.
        ShadingSetDefaultSelector_UserShadingSet1,  //!< Selects the User Shading Set 1 as the bootup shading set.
        ShadingSetDefaultSelector_UserShadingSet2  //!< Selects the User Shading Set 2 as the bootup shading set.
    };

    //! Valid values for ShadingSetSelector
    enum ShadingSetSelectorEnums
    {
        ShadingSetSelector_DefaultShadingSet,  //!< Selects the default shading set for activation by the activate command.
        ShadingSetSelector_UserShadingSet1,  //!< Selects the User shading Set 1 for activation by the activate command.
        ShadingSetSelector_UserShadingSet2  //!< Selects the User shading Set 2 for activation by the activate command.
    };

    //! Valid values for ShadingStatus
    enum ShadingStatusEnums
    {
        ShadingStatus_NoError,  //!< Indicates that the latest operation related to shading correction was successful.
        ShadingStatus_StartupSetError,  //!< Indicates that a problem related to the startup shading set occurred.
        ShadingStatus_ActivateError,  //!< Indicates that the selected shading set could not be loaded.
        ShadingStatus_CreateError  //!< Indicates that a problem related to creating a shading set occurred.
    };

    //! Valid values for ShaftEncoderModuleCounterMode
    enum ShaftEncoderModuleCounterModeEnums
    {
        ShaftEncoderModuleCounterMode_FollowDirection,  //!< Tick counter increments for forward ticks and decrements for reverse ticks.
        ShaftEncoderModuleCounterMode_IgnoreDirection  //!< Tick counter increments for forward ticks and for reverse ticks.
    };

    //! Valid values for ShaftEncoderModuleLineSelector
    enum ShaftEncoderModuleLineSelectorEnums
    {
        ShaftEncoderModuleLineSelector_PhaseA,  //!< Selects phase A of the shaft encoder.
        ShaftEncoderModuleLineSelector_PhaseB  //!< Selects phase B of the shaft encoder.
    };

    //! Valid values for ShaftEncoderModuleLineSource
    enum ShaftEncoderModuleLineSourceEnums
    {
        ShaftEncoderModuleLineSource_Line1,  //!< Selects input line 1 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line2,  //!< Selects input line 2 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line3,  //!< Selects input line 3 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line4,  //!< Selects input line 4 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line5,  //!< Selects input line 5 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line6,  //!< Selects input line 6 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line7,  //!< Selects input line 7 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_Line8,  //!< Selects input line 8 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_CC1,  //!< Selects CC1 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_CC2,  //!< Selects CC2 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_CC3,  //!< Selects CC3 as signal source for the shaft encoder module.
        ShaftEncoderModuleLineSource_CC4  //!< Selects CC4 as signal source for the shaft encoder module.
    };

    //! Valid values for ShaftEncoderModuleMode
    enum ShaftEncoderModuleModeEnums
    {
        ShaftEncoderModuleMode_AnyDirection,  //!< Output of trigger signals for forward and reverse ticks provided the reverse counter is not counting.
        ShaftEncoderModuleMode_ForwardOnly  //!< Output of trigger signals for forward ticks only provided the reverse counter is not decrementing.
    };

    //! Valid values for ShutterMode
    enum ShutterModeEnums
    {
        ShutterMode_Global,  //!< The shutter mode is set to global shutter.
        ShutterMode_Rolling,  //!< The shutter mode is set to rolling shutter.
        ShutterMode_GlobalResetRelease  //!< The shutter mode is set to global reset release shutter.
    };

    //! Valid values for SoftwareSignalSelector
    enum SoftwareSignalSelectorEnums
    {
        SoftwareSignalSelector_SoftwareSignal1,  //!< Software signal 1 can be controlled.
        SoftwareSignalSelector_SoftwareSignal2,  //!< Software signal 2 can be controlled.
        SoftwareSignalSelector_SoftwareSignal3,  //!< Software signal 3 can be controlled.
        SoftwareSignalSelector_SoftwareSignal4  //!< Software signal 4 can be controlled.
    };

    //! Valid values for SpatialCorrectionStartingLine
    enum SpatialCorrectionStartingLineEnums
    {
        SpatialCorrectionStartingLine_LineRed,  //!< 
        SpatialCorrectionStartingLine_LineGreen,  //!< 
        SpatialCorrectionStartingLine_LineBlue  //!< 
    };

    //! Valid values for SyncUserOutputSelector
    enum SyncUserOutputSelectorEnums
    {
        SyncUserOutputSelector_SyncUserOutput1,  //!< Selects user settable synchronous output signal 1 for configuration
        SyncUserOutputSelector_SyncUserOutput2,  //!< Selects user settable synchronous output signal 2 for configuration
        SyncUserOutputSelector_SyncUserOutput3,  //!< Selects user settable synchronous output signal 3 for configuration
        SyncUserOutputSelector_SyncUserOutput4,  //!< Selects user settable synchronous output signal 4 for configuration
        SyncUserOutputSelector_SyncUserOutput5,  //!< Selects user settable synchronous output signal 5 for configuration
        SyncUserOutputSelector_SyncUserOutput6,  //!< Selects user settable synchronous output signal 6 for configuration
        SyncUserOutputSelector_SyncUserOutput7,  //!< Selects user settable synchronous output signal 7 for configuration
        SyncUserOutputSelector_SyncUserOutput8,  //!< Selects user settable synchronous output signal 8 for configuration
        SyncUserOutputSelector_SyncUserOutputCC1,  //!< Selects user settable synchronous output signal CC1 for configuration
        SyncUserOutputSelector_SyncUserOutputCC2,  //!< Selects user settable synchronous output signal CC2 for configuration
        SyncUserOutputSelector_SyncUserOutputCC3,  //!< Selects user settable synchronous output signal CC3 for configuration
        SyncUserOutputSelector_SyncUserOutputCC4,  //!< Selects user settable synchronous output signal CC4 for configuration
        SyncUserOutputSelector_SyncUserOutputLine1,  //!< Selects user settable synchronous output signal Line1 for configuration
        SyncUserOutputSelector_SyncUserOutputLine2,  //!< Selects user settable synchronous output signal Line2 for configuration
        SyncUserOutputSelector_SyncUserOutputLine3,  //!< Selects user settable synchronous output signal Line3 for configuration
        SyncUserOutputSelector_SyncUserOutputLine4,  //!< Selects user settable synchronous output signal Line4 for configuration
        SyncUserOutputSelector_SyncUserOutputClSpare  //!< Selects user settable synchronous output signal CL Spare for configuration
    };

    //! Valid values for TemperatureSelector
    enum TemperatureSelectorEnums
    {
        TemperatureSelector_Sensorboard,  //!< Temperature on sensor board
        TemperatureSelector_Coreboard,  //!< Temperature on core board
        TemperatureSelector_Framegrabberboard,  //!< Temperature on framegrabber board
        TemperatureSelector_Case  //!< Temperature on the camera case
    };

    //! Valid values for TemperatureState
    enum TemperatureStateEnums
    {
        TemperatureState_Ok,  //!< Temperature is normal.
        TemperatureState_Critical,  //!< Temperature is critical.
        TemperatureState_Error  //!< Temperature state could not be retrieved.
    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!< The camera does not display a test image.
        TestImageSelector_Testimage1,  //!< The camera generates and displays a test image with a test image 1 pattern.
        TestImageSelector_Testimage2,  //!< The camera generates and displays a test image with a test image 2 pattern.
        TestImageSelector_Testimage3,  //!< The camera generates and displays a test image with a test image 3 pattern.
        TestImageSelector_Testimage4,  //!< The camera generates and displays a test image with a test image 4 pattern.
        TestImageSelector_Testimage5,  //!< The camera generates and displays a test image with a test image 5 pattern.
        TestImageSelector_Testimage6,  //!< The camera generates and displays a test image with a test image 6 pattern.
        TestImageSelector_Black,  //!< Sets the camera to generate and transmit black test images
        TestImageSelector_White,  //!< Sets the camera to generate and transmit white test images
        TestImageSelector_GreyHorizontalRamp,  //!< Sets the camera to generate and transmit test images with a fixed horizontal gray gradient pattern
        TestImageSelector_GreyVerticalRamp,  //!< Sets the camera to generate and transmit test images with a fixed vertical gray gradient pattern
        TestImageSelector_GreyHorizontalRampMoving,  //!< Sets the camera to generate and transmit test images with a moving horizontal gray gradient pattern
        TestImageSelector_GreyVerticalRampMoving,  //!< Sets the camera to generate and transmit test images with a moving vertical gray gradient pattern
        TestImageSelector_HorzontalLineMoving,  //!< Sets the camera to generate and transmit test images with a moving horizontal line pattern
        TestImageSelector_VerticalLineMoving,  //!< Sets the camera to generate and transmit test images with a moving vertical line pattern
        TestImageSelector_ColorBar,  //!< Sets the camera to generate and transmit test images with a color bar pattern
        TestImageSelector_FrameCounter,  //!< Sets the camera to generate and transmit test images with a frame counter pattern
        TestImageSelector_DeviceSpecific,  //!< Sets the camera to generate and transmit test images with a camera specific pattern
        TestImageSelector_FixedDiagonalGrayGradient_8Bit,  //!< Sets the camera to generate and transmit test images with an 8 bit fixed diagonal gray gradient pattern
        TestImageSelector_MovingDiagonalGrayGradient_8Bit,  //!< Sets the camera to generate and transmit test images with an 8 bit moving diagonal gray gradient pattern
        TestImageSelector_MovingDiagonalGrayGradient_12Bit,  //!< Sets the camera to generate and transmit test images with a 12 bit moving diagonal gray gradient pattern
        TestImageSelector_MovingDiagonalGrayGradientFeatureTest_8Bit,  //!< Sets the camera to generate and transmit test images with an 8 bit moving diagonal gray gradient feature test pattern
        TestImageSelector_MovingDiagonalGrayGradientFeatureTest_12Bit,  //!< Sets the camera to generate and transmit test images with a 12 bit moving diagonal gray gradient feature test pattern
        TestImageSelector_MovingDiagonalColorGradient,  //!< Sets the camera to generate and transmit test images with a moving diagonal color gradient pattern
        TestImageSelector_Testimage7  //!< Sets the camera to generate and transmit test images with a test image 7 pattern
    };

    //! Valid values for TestPattern
    enum TestPatternEnums
    {
        TestPattern_Off,  //!< No test pattern. Displays the original image.
        TestPattern_GreyDiagonalSawtooth8,  //!< 
        TestPattern_ColorDiagonalSawtooth8  //!< 
    };

    //! Valid values for TimerSelector
    enum TimerSelectorEnums
    {
        TimerSelector_Timer1,  //!< Timer 1 can be configured.
        TimerSelector_Timer2,  //!< Selects timer 2 for configuration
        TimerSelector_Timer3,  //!< Selects timer 3 for configuration
        TimerSelector_Timer4  //!< Selects timer 4 for configuration
    };

    //! Valid values for TimerSequenceEntrySelector
    enum TimerSequenceEntrySelectorEnums
    {
        TimerSequenceEntrySelector_Entry1,  //!< 
        TimerSequenceEntrySelector_Entry2,  //!< 
        TimerSequenceEntrySelector_Entry3,  //!< 
        TimerSequenceEntrySelector_Entry4,  //!< 
        TimerSequenceEntrySelector_Entry5,  //!< 
        TimerSequenceEntrySelector_Entry6,  //!< 
        TimerSequenceEntrySelector_Entry7,  //!< 
        TimerSequenceEntrySelector_Entry8,  //!< 
        TimerSequenceEntrySelector_Entry9,  //!< 
        TimerSequenceEntrySelector_Entry10,  //!< 
        TimerSequenceEntrySelector_Entry11,  //!< 
        TimerSequenceEntrySelector_Entry12,  //!< 
        TimerSequenceEntrySelector_Entry13,  //!< 
        TimerSequenceEntrySelector_Entry14,  //!< 
        TimerSequenceEntrySelector_Entry15,  //!< 
        TimerSequenceEntrySelector_Entry16  //!< 
    };

    //! Valid values for TimerSequenceTimerSelector
    enum TimerSequenceTimerSelectorEnums
    {
        TimerSequenceTimerSelector_Timer1,  //!< 
        TimerSequenceTimerSelector_Timer2,  //!< 
        TimerSequenceTimerSelector_Timer3,  //!< 
        TimerSequenceTimerSelector_Timer4  //!< 
    };

    //! Valid values for TimerTriggerActivation
    enum TimerTriggerActivationEnums
    {
        TimerTriggerActivation_RisingEdge,  //!< Sets the type of signal change that will start the timer to rising edge
        TimerTriggerActivation_FallingEdge,  //!< Sets the type of signal change that will start the timer to falling edge
        TimerTriggerActivation_LevelHigh,  //!< 
        TimerTriggerActivation_LevelLow  //!< 
    };

    //! Valid values for TimerTriggerSource
    enum TimerTriggerSourceEnums
    {
        TimerTriggerSource_ExposureStart,  //!< The timer can be triggered by the exposure start signal.
        TimerTriggerSource_FlashWindowStart,  //!< The timer can be triggered by the flash window start signal.
        TimerTriggerSource_Off  //!< Sets the source signal for the selected timer to off
    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_RisingEdge,  //!< The selected trigger is activated on the rising edge of the source signal.
        TriggerActivation_FallingEdge,  //!< The selected trigger is activated on the falling edge of the source signal.
        TriggerActivation_AnyEdge,  //!< The selected trigger is activated on the falling or rising edge of the source signal.
        TriggerActivation_LevelHigh,  //!< The selected trigger is activated when the source signal is high.
        TriggerActivation_LevelLow  //!< The selected trigger is activated when the source signal is low.
    };

    //! Valid values for TriggerControlImplementation
    enum TriggerControlImplementationEnums
    {
        TriggerControlImplementation_Legacy,  //!< 
        TriggerControlImplementation_Standard  //!< 
    };

    //! Valid values for TriggerDelaySource
    enum TriggerDelaySourceEnums
    {
        TriggerDelaySource_Time_us,  //!< Selects the trigger delay to be expressed as a time interval (in microseconds).
        TriggerDelaySource_LineTrigger  //!< Selects the trigger delay to be expressed as a number of line triggers.
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!< The currently selected trigger is turned off.
        TriggerMode_On  //!< The currently selected trigger is turned on.
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_FrameBurstStart,  //!< The frame burst start trigger can be configured.
        TriggerSelector_FrameStart,  //!< The frame start trigger can be configured.
        TriggerSelector_AcquisitionStart,  //!< Selects the acquisition start trigger for configuration
        TriggerSelector_AcquisitionEnd,  //!< Selects the acquisition end trigger for configuration
        TriggerSelector_AcquisitionActive,  //!< Selects the acquisition active trigger for configuration
        TriggerSelector_FrameEnd,  //!< Selects the frame end trigger for configuration
        TriggerSelector_FrameActive,  //!< Selects the frame active trigger for configuration
        TriggerSelector_LineStart,  //!< Selects the line start trigger for configuration
        TriggerSelector_ExposureStart,  //!< Selects the exposure start trigger for configuration
        TriggerSelector_ExposureEnd,  //!< Selects the exposure end trigger for configuration
        TriggerSelector_ExposureActive  //!< Selects the exposure active trigger for configuration
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Software,  //!< The signal source for the selected trigger is set to software triggering.
        TriggerSource_Line1,  //!< The signal source for the selected trigger is set to line 1.
        TriggerSource_Line2,  //!< The signal source for the selected trigger is set to line 2.
        TriggerSource_Line3,  //!< The signal source for the selected trigger is set to line 3.
        TriggerSource_Line4,  //!< The signal source for the selected trigger is set to line 4.
        TriggerSource_SoftwareSignal1,  //!< The signal source for the selected trigger is set to software signal 1.
        TriggerSource_SoftwareSignal2,  //!< The signal source for the selected trigger is set to software signal 2.
        TriggerSource_SoftwareSignal3,  //!< The signal source for the selected trigger is set to software signal 3.
        TriggerSource_Line5,  //!< Sets the signal source for the selected trigger to line 5
        TriggerSource_Line6,  //!< Sets the signal source for the selected trigger to line 6
        TriggerSource_Line7,  //!< Sets the signal source for the selected trigger to line 7
        TriggerSource_Line8,  //!< Sets the signal source for the selected trigger to line 8
        TriggerSource_CC1,  //!< Sets the signal source for the selected trigger to CC1
        TriggerSource_CC2,  //!< Sets the signal source for the selected trigger to CC2
        TriggerSource_CC3,  //!< Sets the signal source for the selected trigger to CC3
        TriggerSource_CC4,  //!< Sets the signal source for the selected trigger to CC4
        TriggerSource_ShaftEncoderModuleOut,  //!< Sets the signal source for the selected trigger to the shaft encoder module.
        TriggerSource_FrequencyConverter,  //!< Sets the signal source for the selected trigger to the frequency converter module.
        TriggerSource_Timer1Start,  //!< Sets the signal source for the selected trigger to timer 1 start
        TriggerSource_Timer1End,  //!< Sets the signal source for the selected trigger to timer 1 end
        TriggerSource_Counter1Start,  //!< Sets the signal source for the selected trigger to counter 1 start
        TriggerSource_Counter1End,  //!< Sets the signal source for the selected trigger to counter 1 end
        TriggerSource_UserOutput1,  //!< Sets the signal source for the selected trigger to user output 1
        TriggerSource_UserOutput2,  //!< Sets the signal source for the selected trigger to user output 2
        TriggerSource_Action1,  //!< Sets the signal source for the selected trigger to action command signal 1
        TriggerSource_Action2,  //!< Sets the signal source for the selected trigger to action command signal 2
        TriggerSource_Action3,  //!< Sets the signal source for the selected trigger to action command signal 3
        TriggerSource_Action4,  //!< Sets the signal source for the selected trigger to action command signal 4
        TriggerSource_VInput1,  //!< Sets the signal source for the selected trigger to Virtual Input 1
        TriggerSource_VInput2,  //!< Sets the signal source for the selected trigger to Virtual Input 2
        TriggerSource_VInput3,  //!< Sets the signal source for the selected trigger to Virtual Input 3
        TriggerSource_VInput4,  //!< Sets the signal source for the selected trigger to Virtual Input 4
        TriggerSource_VInputDecActive  //!< Sets the signal source for the selected trigger to Virtual Input Decoder Active
    };

    //! Valid values for UserDefinedValueSelector
    enum UserDefinedValueSelectorEnums
    {
        UserDefinedValueSelector_Value1,  //!< The user-defined value 1 can be set or read.
        UserDefinedValueSelector_Value2,  //!< The user-defined value 2 can be set or read.
        UserDefinedValueSelector_Value3,  //!< The user-defined value 3 can be set or read.
        UserDefinedValueSelector_Value4,  //!< The user-defined value 4 can be set or read.
        UserDefinedValueSelector_Value5  //!< The user-defined value 5 can be set or read.
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput0,  //!< User settable output signal 0 can be configured.
        UserOutputSelector_UserOutput1,  //!< User settable output signal 1 can be configured.
        UserOutputSelector_UserOutput2,  //!< User settable output signal 2 can be configured.
        UserOutputSelector_UserOutput3,  //!< User settable output signal 3 can be configured.
        UserOutputSelector_UserOutput4,  //!< Selects user settable output signal 4 for configuration
        UserOutputSelector_UserOutput5,  //!< Selects user settable output signal 5 for configuration
        UserOutputSelector_UserOutput6,  //!< Selects user settable output signal 6 for configuration
        UserOutputSelector_UserOutput7,  //!< Selects user settable output signal 7 for configuration
        UserOutputSelector_UserOutput8,  //!< Selects user settable output signal 8 for configuration
        UserOutputSelector_UserOutputCC1,  //!< Selects user settable output signal CC1 for configuration
        UserOutputSelector_UserOutputCC2,  //!< Selects user settable output signal CC2 for configuration
        UserOutputSelector_UserOutputCC3,  //!< Selects user settable output signal CC3 for configuration
        UserOutputSelector_UserOutputCC4,  //!< Selects user settable output signal CC4 for configuration
        UserOutputSelector_UserOutputLine1,  //!< Selects user settable output signal Line1 for configuration
        UserOutputSelector_UserOutputLine2,  //!< Selects user settable output signal Line2 for configuration
        UserOutputSelector_UserOutputLine3,  //!< Selects user settable output signal Line3 for configuration
        UserOutputSelector_UserOutputLine4,  //!< Selects user settable output signal Line4 for configuration
        UserOutputSelector_UserOutputClSpare  //!< Selects user settable output signal CL Spare for configuration
    };

    //! Valid values for UserSetDefault
    enum UserSetDefaultEnums
    {
        UserSetDefault_Default,  //!< The default factory set is set as the as the startup set.
        UserSetDefault_HighGain,  //!< The high gain factory set is set as the startup set.
        UserSetDefault_AutoFunctions,  //!< The factory set enabling auto functions is set as the startup set.
        UserSetDefault_Color,  //!< The factory set enabling color adjustments is set as the startup set.
        UserSetDefault_ColorRaw,  //!< The factory set disabling color adjustments is set as the startup set.
        UserSetDefault_UserSet1,  //!< User set 1 is set as the startup set.
        UserSetDefault_UserSet2,  //!< User set 2 is set as the startup set.
        UserSetDefault_UserSet3  //!< User set 3 is set as the startup set.
    };

    //! Valid values for UserSetDefaultSelector
    enum UserSetDefaultSelectorEnums
    {
        UserSetDefaultSelector_Default,  //!< Selects the default user set as the default startup set
        UserSetDefaultSelector_HighGain,  //!< Selects the high gain user set as the default startup set.
        UserSetDefaultSelector_AutoFunctions,  //!< Selects the auto function user set as the default startup set.
        UserSetDefaultSelector_Color,  //!< Selects the color user set as the default startup set.
        UserSetDefaultSelector_ColorRaw,  //!< Selects the raw color user set as the default startup set.
        UserSetDefaultSelector_Custom0,  //!< Selects the custom 0 user set as the default startup set.
        UserSetDefaultSelector_Custom1,  //!< Selects the custom 1 user set as the default startup set.
        UserSetDefaultSelector_UserSet1,  //!< Selects user set 1 as the default startup set
        UserSetDefaultSelector_UserSet2,  //!< Selects user set 2 as the default startup set
        UserSetDefaultSelector_UserSet3  //!< Selects user set 3 as the default startup set
    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_Default,  //!< The default factory set can be loaded.
        UserSetSelector_HighGain,  //!< The high gain factory set can be loaded.
        UserSetSelector_AutoFunctions,  //!< The factory set enabling auto functions can be loaded.
        UserSetSelector_Color,  //!< The factory set enabling color adjustments can be loaded.
        UserSetSelector_ColorRaw,  //!< The factory set disabling color adjustments can be loaded.
        UserSetSelector_UserSet1,  //!< User set 1 can be saved, loaded, or configured.
        UserSetSelector_UserSet2,  //!< User set 2 can be saved, loaded, or configured.
        UserSetSelector_UserSet3,  //!< User set 3 can be saved, loaded, or configured.
        UserSetSelector_Custom0,  //!< Factory set enabling custom 0 settings
        UserSetSelector_Custom1  //!< Factory set enabling custom 1 settings
    };

    //! Valid values for VInpSignalReadoutActivation
    enum VInpSignalReadoutActivationEnums
    {
        VInpSignalReadoutActivation_RisingEdge,  //!< Sets the type of signal change necessary to start the signal evaluation
        VInpSignalReadoutActivation_FallingEdge  //!< Sets the type of signal change necessary to start the signal evaluation
    };

    //! Valid values for VInpSignalSource
    enum VInpSignalSourceEnums
    {
        VInpSignalSource_Line1,  //!< TODO
        VInpSignalSource_Line2,  //!< TODO
        VInpSignalSource_Line3,  //!< TODO
        VInpSignalSource_Line4,  //!< TODO
        VInpSignalSource_Line5,  //!< TODO
        VInpSignalSource_Line6,  //!< TODO
        VInpSignalSource_Line7,  //!< TODO
        VInpSignalSource_Line8,  //!< TODO
        VInpSignalSource_CC1,  //!< TODO
        VInpSignalSource_CC2,  //!< TODO
        VInpSignalSource_CC3,  //!< TODO
        VInpSignalSource_CC4  //!< TODO
    };



    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! A parameter class containing all parameters as members that are available for ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu, and dart BCON
    class PYLONBASE_API CUniversalCameraParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUniversalCameraParams_Params(void);

            //! Destructor
            ~CUniversalCameraParams_Params(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

            //! Return the vendor of the camera
            const char* _GetVendorName(void);

            //! Returns the camera model name
            const char* _GetModelName(void);
        
        //! \endcond

    private:
        class CUniversalCameraParams_ParamsData;
        CUniversalCameraParams_ParamsData* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        
    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Immediately aborts the acquisition of images - Applies to: GigE and CameraLink Camera

        This command will immediately abort any image acquisition process that is currently in progress.
    
        \b Visibility = Beginner

        \b Selected by : AcquisitionMode

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionAbort" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionAbort;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Number of frames to acquire for each FrameBurstStart trigger - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionBurstFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionBurstFrameCount;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the number of frames acquired in the multiframe acquisition mode - Applies to: GigE, 1394 and CameraLink Camera

        This value sets the number of frames acquired in the multiframe acquisition mode
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionFrameCount;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFramePeriodRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionFramePeriodRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Acquisition frame rate of the camera in frames per second - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionFrameRate;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief If the acquisition frame rate feature is enabled, this value sets the camera's acquisition frame rate in frames per second - Applies to: GigE, 1394, CameraLink Camera and CamEmu

        Sets the 'absolute' value of the acquisition frame rate. The 'absolute' value is a float value that sets the acquisition frame rate in frames per second.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionFrameRateAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Enables setting the camera's acquisition frame rate to a specified value - Applies to: ace USB, GigE, 1394, CameraLink Camera and CamEmu

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionFrameRateEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionFrameRateEnable;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IEnumParameterT<AcquisitionFrameRateEnumEnums>& AcquisitionFrameRateEnum;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the camera's acquisition line rate in lines per second - Applies to: GigE and CameraLink Camera

        Sets the 'absolute' value of the acquisition line rate. The 'absolute' value is a float value that sets the acquisition line rate in lines per second.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionLineRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AcquisitionLineRateAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the image acquisition mode - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionModeEnums>& AcquisitionMode;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Starts the acquisition of images - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Starts the acquisition of images. If the camera is set for single frame acquisition, it will start acquisition of one frame. If the camera is set for continuous frame acquisition, it will start continuous acquisition of frames.
    
        \b Visibility = Beginner

        \b Selected by : AcquisitionMode

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStart;
    
    //@}


    //! \name Category Acquisition Start  Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an acquisition start  event - Applies to: GigE

        This enumeration Indicates the stream channel index for an acquisition start  event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartEventStreamChannelIndex;
    
    //@}


    //! \name Category Acquisition Start  Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an acquisition start  event - Applies to: GigE

        This enumeration value indicates the time stamp for an acquisition start  event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartEventTimestamp;
    
    //@}


    //! \name Category Acquisition Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an acquisition start overtrigger event - Applies to: GigE and 1394

        This enumeration Indicates the stream channel index for an acquisition start overtrigger event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartOvertriggerEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartOvertriggerEventStreamChannelIndex;
    
    //@}


    //! \name Category Acquisition Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an Acquisition start overtrigger event - Applies to: GigE and 1394

        This enumeration value indicates the time stamp for an Acquisition start overtrigger event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartOvertriggerEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartOvertriggerEventTimestamp;
    
    //@}


    //! \name Category Acquisition Start Wait Event Data
    //@{
    /*!
        \brief Stream channel index of the acquisition start wait event - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartWaitEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartWaitEventStreamChannelIndex;
    
    //@}


    //! \name Category Acquisition Start Wait Event Data
    //@{
    /*!
        \brief Time stamp of the acquisition start wait event - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStartWaitEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionStartWaitEventTimestamp;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Indicates the status (true or false) of the currently selected acquisition signal - Applies to: ace USB, GigE, 1394, CameraLink Camera and CamEmu

        Indicates the status (true or false) of the currently selected acquisition signal. acquisition signal can be selected using AcquisitionStatusSelector.
    
        \b Visibility = Expert

        \b Selected by : AcquisitionStatusSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AcquisitionStatus;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the acquisition status to be checked - Applies to: ace USB, GigE, 1394, CameraLink Camera and CamEmu

        Sets the acquisition status to be checked. Once a status has been set, the status can be checked by reading the AcquisitionStatus parameter value.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStatusSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AcquisitionStatusSelectorEnums>& AcquisitionStatusSelector;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Stops the acquisition of images - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Stops the acquisition of images if the camera is set for continuous image acquisition and acquisition has been started.
    
        \b Visibility = Beginner

        \b Selected by : AcquisitionMode

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionStop" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& AcquisitionStop;
    
    //@}


    //! \name Category Acquisition Wait Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an acquisition wait event - Applies to: GigE

        This enumeration Indicates the stream channel index for an acquisition wait event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionWaitEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionWaitEventStreamChannelIndex;
    
    //@}


    //! \name Category Acquisition Wait Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an acquisition wait event - Applies to: GigE

        This enumeration value indicates the time stamp for an acquisition wait event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AcquisitionWaitEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AcquisitionWaitEventTimestamp;
    
    //@}


    //! \name Category Action Control
    //@{
    /*!
        \brief Number of action command interfaces - Applies to: GigE

        Available number of action command interfaces on the camera device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionCommandCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionCommandCount;
    
    //@}


    //! \name Category Action Control
    //@{
    /*!
        \brief Authorization key - Applies to: GigE

        Key to authorize the action for the device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionDeviceKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionDeviceKey;
    
    //@}


    //! \name Category Action Control
    //@{
    /*!
        \brief Defines a group of devices - Applies to: GigE

        Used to define a group of devices on which actions can be executed.
    
        \b Visibility = Guru

        \b Selected by : ActionSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionGroupKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionGroupKey;
    
    //@}


    //! \name Category Action Control
    //@{
    /*!
        \brief Filters out particular devices from its group - Applies to: GigE

        Used to filter out some particular devices from the group of devices defined by the action group key.
    
        \b Visibility = Guru

        \b Selected by : ActionSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionGroupMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionGroupMask;
    
    //@}


    //! \name Category Action Late Event Data
    //@{
    /*!
        \brief Stream channel index of the action late event - Applies to: GigE

        Stream channel index of the action late event. A action late event is raised when a scheduled action command with a timestamp in the past is received.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionLateEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionLateEventStreamChannelIndex;
    
    //@}


    //! \name Category Action Late Event Data
    //@{
    /*!
        \brief Time stamp of the action late event - Applies to: GigE

        Time stamp of the action late event. A action late event is raised when a scheduled action command with a timestamp in the past is received.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionLateEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionLateEventTimestamp;
    
    //@}


    //! \name Category Action Control
    //@{
    /*!
        \brief Selects the action command to configure  Once an action command has been selected, all changes to the action command settings will be applied to the selected action command - Applies to: GigE

        This enumeration selects the action command to configure. Once an action command has been selected, all changes to the action command settings will be applied to the selected action command.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ActionSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ActionSelector;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the backlight compensation - Applies to: dart USB, pulse and dart BCON

        Sets the backlight compensation that allows the camera to compensate for underexposure. This is done by excluding a given percentage of the brightest pixels in the image from the target average gray value calculations.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoBacklightCompensation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoBacklightCompensation;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoBacklightCompensationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoBacklightCompensationRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Lower limit of the Auto Exposure Time (Abs) [us] parameter - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeAbsLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeAbsLowerLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Upper limit of the Auto Exposure Time (Abs) [us] parameter - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeAbsUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeAbsUpperLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Lower limit for the ExposureTime parameter when the exposure auto function is active - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeLowerLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeLowerLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoExposureTimeLowerLimitRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Upper limit for the ExposureTime parameter when the exposure auto function is active - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoExposureTimeUpperLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoExposureTimeUpperLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoExposureTimeUpperLimitRaw;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Height of the auto function AOI (in pixels) - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Invisible

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIHeight;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Horizontal offset from the left side of the sensor to the auto function AOI (in pixels) - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Invisible

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIOffsetX;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Vertical offset from the top of the sensor to the auto function AOI (in pixels) - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Invisible

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIOffsetY;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Sets which auto function AOI can be adjusted - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOISelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionAOISelectorEnums>& AutoFunctionAOISelector;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUsageIntensity" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUsageIntensity;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUsageRedLightCorrection" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUsageRedLightCorrection;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUsageWhiteBalance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUsageWhiteBalance;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Assigns the Gain Auto and the Exposure Auto functions to the currently selected auto function AOI - Applies to: ace USB

        Assigns the Gain Auto and the Exposure Auto functions to the currently selected auto function AOI. For this parameter, Gain Auto and the Exposure Auto are considered as a single "brightness" auto function.
    
        \b Visibility = Invisible

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUseBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUseBrightness;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Assigns the Balance White auto function to the currently selected auto function AOI - Applies to: ace USB

    
        \b Visibility = Invisible

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIUseWhiteBalance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionAOIUseWhiteBalance;
    
    //@}


    //! \name Categories Auto Function AOI Control and Auto Function AOIs
    //@{
    /*!
        \brief Width of the auto function AOI (in pixels) - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Invisible

        \b Selected by : AutoFunctionAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionAOIWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionAOIWidth;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets how gain and exposure time will be balanced when the device is making automatic adjustments - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionProfile" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionProfileEnums>& AutoFunctionProfile;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Height of the auto function ROI (in pixels) - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIHeight;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Horizontal offset from the left side of the sensor to the auto function ROI (in pixels) - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIOffsetX;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Vertical offset from the top of the sensor to the auto function ROI (in pixels) - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIOffsetY;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Sets which auto function ROI can be adjusted - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROISelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<AutoFunctionROISelectorEnums>& AutoFunctionROISelector;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Assigns the Gain Auto and the Exposure Auto functions to the currently selected auto function ROI - Applies to: ace USB, dart USB, pulse and dart BCON

        Assigns the Gain Auto and the Exposure Auto functions to the currently selected auto function ROI. For this parameter, Gain Auto and the Exposure Auto are considered as a single "brightness" auto function.
    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIUseBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionROIUseBrightness;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Assigns the Balance White auto function to the currently selected auto function ROI - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIUseWhiteBalance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& AutoFunctionROIUseWhiteBalance;
    
    //@}


    //! \name Category Auto Function ROI Control
    //@{
    /*!
        \brief Width of the auto function ROI (in pixels) - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : AutoFunctionROISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoFunctionROIWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoFunctionROIWidth;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Lower limit for the Gain parameter when the gain auto function is active - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoGainLowerLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainLowerLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoGainLowerLimitRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Lower limit of the Auto Gain (Raw) parameter - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainRawLowerLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoGainRawLowerLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Upper limit of the Auto Gain (Raw) parameter - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainRawUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoGainRawUpperLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Upper limit for the Gain parameter when the gain auto function is active - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainUpperLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoGainUpperLimit;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoGainUpperLimitRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoGainUpperLimitRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Target average brightness for the gain auto function and the exposure auto function - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoTargetBrightness;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the damping for the target gray value controller - Applies to: dart USB, pulse and dart BCON

        Sets the damping for the target gray value controller. Can be used to dampen oscillation.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetBrightnessDamping" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& AutoTargetBrightnessDamping;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetBrightnessDampingRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoTargetBrightnessDampingRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetBrightnessRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoTargetBrightnessRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Target average grey value for Gain Auto and Exposure Auto - Applies to: GigE, 1394 and CameraLink Camera

        The target average grey value may range from nearly black to nearly white. Note that this range of gray values applies to 8 bit and to 16 bit (12 bit effective) output modes. Accordingly, also for 16 bit output modes, black is represented by 0 and white by 255.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=AutoTargetValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& AutoTargetValue;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Value of the currently selected balance ratio channel or tap - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatio" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceRatio;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the value of the selected balance ratio control as a float - Applies to: GigE, 1394 and CameraLink Camera

        This value sets the selected balance ratio control as a float value.
    
        \b Visibility = Beginner

        \b Selected by : BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceRatioAbs;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the value of the selected balance ratio control as an integer - Applies to: dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        This value sets the selected balance ratio control as an integer.
    
        \b Visibility = Invisible

        \b Selected by : BalanceRatioSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BalanceRatioRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the color channel to be adjusted for manual white balance - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Sets the color channel to be adjusted for manual white balance. Once a color intensity has been selected, all changes to the balance ratio parameter will be applied to the selected color intensity.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceRatioSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceRatioSelectorEnums>& BalanceRatioSelector;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Balance White adjustment damping for Balance White Auto - Applies to: GigE and CameraLink Camera

        The Balance White adjustment damping parameter controls the rate by which the color components are changed when Balance White Auto is enabled.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAdjustmentDampingAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BalanceWhiteAdjustmentDampingAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Balance White adjustment damping for Balance White Auto - Applies to: GigE and CameraLink Camera

        The Balance White adjustment damping parameter controls the rate by which the color components are changed when Balance White Auto is enabled.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAdjustmentDampingRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BalanceWhiteAdjustmentDampingRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the operation mode of the balance white auto function - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BalanceWhiteAutoEnums>& BalanceWhiteAuto;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Allows returning to previous settings - Applies to: GigE, 1394 and CameraLink Camera

        Allows returning to the color adjustment settings extant before the latest changes of the settings.
This allows you undoing the latest unwanted changes of the color adjustment settings and returning to the preceding settings.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BalanceWhiteReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& BalanceWhiteReset;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BandgapRef1" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BandgapRef1;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BandgapRef2" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BandgapRef2;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the clock frequency for the BCON transport layer - Applies to: dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BconClockFrequency" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BconClockFrequencyEnums>& BconClockFrequency;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the number of pixels transmitted per clock cycle via the BCON interface - Applies to: dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BconPixelsPerClockCycle" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BconPixelsPerClockCycleEnums>& BconPixelsPerClockCycle;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Number of adjacent horizontal pixels to be summed - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Number of adjacent horizontal pixels to be summed. Their charges will be summed and reported out of the camera as a single pixel.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningHorizontal;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the binning horizontal mode - Applies to: ace USB, dart USB, pulse, GigE and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningHorizontalMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningHorizontalModeEnums>& BinningHorizontalMode;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the horizontal binning mode - Applies to: GigE and CameraLink Camera

        This enumeration sets the horizontal binning mode.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningModeHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningModeHorizontalEnums>& BinningModeHorizontal;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the vertical binning mode - Applies to: GigE and CameraLink Camera

        This enumeration sets the vertical binning mode.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningModeVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningModeVerticalEnums>& BinningModeVertical;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Number of adjacent vertical pixels to be summed - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Number of adjacent vertical pixels to be summed. Their charges will be summed and reported out of the camera as a single pixel.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BinningVertical;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the binning vertical mode - Applies to: ace USB, dart USB, pulse, GigE and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BinningVerticalMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BinningVerticalModeEnums>& BinningVerticalMode;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Value of the currently selected black level channel or tap - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : BlackLevelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevel" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BlackLevel;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the value of the selected black level control as a float - Applies to: GigE and CameraLink Camera

        This value sets the selected black level control as a float value.
    
        \b Visibility = Beginner

        \b Selected by : BlackLevelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BlackLevelAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the value of the selected black level control as an integer - Applies to: dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        This value sets the selected black level control as an integer.
    
        \b Visibility = Invisible

        \b Selected by : BlackLevelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BlackLevelRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the black level channel or tap to be adjusted - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Sets the black level channel or tap to be adjusted. Once a black level channel or tap has been selected, all changes to the BlackLevel parameter will be applied to the selected channel or tap.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BlackLevelSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BlackLevelSelectorEnums>& BlackLevelSelector;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of brightness to be applied - Applies to: dart USB, pulse, GigE and dart BCON

        Amount of brightness to be applied. This allows you to lighten or darken the entire image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslBrightness" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslBrightness;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Brightness to be applied - Applies to: dart USB, pulse, GigE and dart BCON

        Adjusting the brightness lightens or darkens the entire image.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslBrightnessRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslBrightnessRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the color space for image acquisition - Applies to: dart USB, pulse and dart BCON

        Sets the color space for image acquisition. Note that perception of brightness also depends on the gamma correction value set.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslColorSpaceMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslColorSpaceModeEnums>& BslColorSpaceMode;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of contrast to be applied - Applies to: dart USB, pulse, GigE and dart BCON

        Amount of contrast to be applied. The more contrast you apply, the more defined the difference between light and dark areas in the image will be.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrast" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslContrast;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the contrast mode - Applies to: dart USB, pulse, GigE and dart BCON

        Sets the contrast mode. This specifies which type of contrast enhancement is used to adjust the contrast.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrastMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslContrastModeEnums>& BslContrastMode;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Contrast to be applied - Applies to: dart USB, pulse, GigE and dart BCON

        Adjusting the contrast increases the difference between light and dark areas in the image.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslContrastRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslContrastRaw;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslDeviceRole" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslDeviceRoleEnums>& BslDeviceRole;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslDeviceRoleKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslDeviceRoleKey;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslFirmwareCompatibilityID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslFirmwareCompatibilityID;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslFirmwareLabel" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& BslFirmwareLabel;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslFirmwareName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& BslFirmwareName;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Hue shift to be applied - Applies to: GigE

        Adjusting the hue shifts the colors of the image. This can be useful, e.g., for correcting minor color shifts or creating false-color images.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslHue;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Hue shift to be applied - Applies to: GigE

        Adjusting the hue shifts the colors of the image. This can be useful, e.g., for correcting minor color shifts or creating false-color images.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslHueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslHueRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Hue shift to be applied - Applies to: dart USB, pulse and dart BCON

        Hue shift to be applied. Adjusting the hue shifts the colors of the image. This can be useful, e.g., for correcting minor color shifts or creating false-color images.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslHueValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslHueValue;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the immediate trigger mode - Applies to: dart USB, pulse and dart BCON

        Sets the immediate trigger mode. If this mode is enabled, exposure starts immediately after triggering, but changes to image parameters become effective with a short delay, i.e., after one or more images have been acquired.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslImmediateTriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslImmediateTriggerModeEnums>& BslImmediateTriggerMode;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Saturation to be applied - Applies to: GigE

        Adjusting the saturation changes the intensity of the colors. A higher saturation, for example, makes colors easier to distinguish.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslSaturation;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Saturation to be applied - Applies to: GigE

        Adjusting the saturation changes the intensity of the colors. A higher saturation, for example, makes colors easier to distinguish.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslSaturationRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of saturation to be applied - Applies to: dart USB, pulse and dart BCON

        Amount of saturation to be applied. Adjusting the saturation changes the colorfulness (intensity) of the colors. A higher saturation, for example, will make colors easier to distinguish.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturationValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& BslSaturationValue;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslSaturationValueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& BslSaturationValueRaw;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Returns the speed mode of the USB port - Applies to: ace USB, dart USB and pulse

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=BslUSBSpeedMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<BslUSBSpeedModeEnums>& BslUSBSpeedMode;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CalibLockChallenge" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CalibLockChallenge;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CalibLockResponse" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CalibLockResponse;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CalibStore" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& CalibStore;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables horizontal centering of the image - Applies to: ace USB, GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterX;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables vertical centering of the image - Applies to: ace USB, GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CenterY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CenterY;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Sets which counter to retrieve chunk data from - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkCounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkCounterSelectorEnums>& ChunkCounterSelector;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Value of the selected chunk counter - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : ChunkCounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkCounterValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkCounterValue;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the maximum possible pixel value in the acquired image - Applies to: GigE and 1394

        This value indicates indicates the maximum possible pixel value acquired in the image
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkDynamicRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkDynamicRangeMax;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the minimum possible pixel value in the acquired image - Applies to: GigE and 1394

        This value indicates the minimum possible pixel value in the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkDynamicRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkDynamicRangeMin;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Enables the inclusion of the currently selected chunk in the payload data - Applies to: ace USB, GigE and 1394

    
        \b Visibility = Beginner

        \b Selected by : ChunkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkEnable;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Exposure time used to acquire the image - Applies to: ace USB, GigE and 1394

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkExposureTime;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFrameTriggerCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFrameTriggerCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFrameTriggerIgnoredCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFrameTriggerIgnoredCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the value of the frame counter when the image was acquired - Applies to: GigE and 1394

        This integer indicates the value of the frame counter when the image was acquired.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFramecounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFramecounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkFramesPerTriggerCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkFramesPerTriggerCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Gain used to acquire the image - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : ChunkGainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGain" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ChunkGain;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGainAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkGainAll;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Sets which gain channel to retrieve chunk data from - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkGainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkGainSelectorEnums>& ChunkGainSelector;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the height of the area of interest represented in the acquired image - Applies to: GigE and 1394

        This value Indicates the height of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkHeight;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Number of bits per status - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkInputStatusAtLineTriggerBitsPerLine" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerBitsPerLine;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Used to select a certain status - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkInputStatusAtLineTriggerIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerIndex;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Value of the status selected by 'Index' - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkInputStatusAtLineTriggerValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkInputStatusAtLineTriggerValue;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief A bit field that indicates the status of all of the camera's input and output lines when the image was acquired - Applies to: ace USB, GigE and 1394

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineStatusAll;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineTriggerCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineTriggerCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineTriggerEndToEndCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineTriggerEndToEndCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkLineTriggerIgnoredCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkLineTriggerIgnoredCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Enables the chunk mode - Applies to: ace USB, GigE, 1394 and CamEmu

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkModeActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ChunkModeActive;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the X offset of the area of interest represented in the acquired image - Applies to: GigE and 1394

        This value Indicates the X offset of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkOffsetX;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the Y offset of the area of interest represented in the acquired image - Applies to: GigE and 1394

        This value Indicates the Y offset of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkOffsetY;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief CRC checksum of the acquired image - Applies to: ace USB and GigE

        CRC checksum of the acquired image. The checksum is calculated using all of the image data and all of the appended chunks except for the checksum itself.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkPayloadCRC16" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkPayloadCRC16;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the format of the pixel data in the acquired image - Applies to: GigE and 1394

        This enumeration lists the pixel formats that can be indicated by the pixel format chunk.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkPixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkPixelFormatEnums>& ChunkPixelFormat;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Sets the chunk to be enabled - Applies to: ace USB, GigE and 1394

        Sets the chunk to be enabled. Once a chunk has been set, the chunk can be enabled using the ChunkEnable parameter.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ChunkSelectorEnums>& ChunkSelector;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the sequence set index number related to the acquired image - Applies to: GigE

        This value indicates the sequence set index number related to the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSequenceSetIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkSequenceSetIndex;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Index of the active sequencer set - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkSequencerSetActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkSequencerSetActive;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Shaft encoder counter at frame trigger - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkShaftEncoderCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkShaftEncoderCounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the number of bytes of data between the beginning of one line in the acquired image and the beginning of the next line in the acquired image - Applies to: GigE and 1394

        This value indicates the number of bytes of data between the beginning of one line in the acquired image and the beginning of the next line in the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkStride" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkStride;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Value of the timestamp when the image was acquired - Applies to: ace USB, GigE and 1394

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkTimestamp;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the value of the trigger input counter when the image was acquired - Applies to: GigE and 1394

        This integer indicates the value of the trigger input counter when the image was acquired.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkTriggerinputcounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkTriggerinputcounter;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief A bit field that indicates the status of all of the camera's virtual input and output lines when the image was acquired - Applies to: GigE

        This value is a bit field that indicates the status of all of the camera's virtual input and output lines when the image was acquired.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkVirtLineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkVirtLineStatusAll;
    
    //@}


    //! \name Categories Chunk Data, Chunk Data Control, Chunk Data Streams and Device Information
    //@{
    /*!
        \brief Indicates the widtth of the area of interest represented in the acquired image - Applies to: GigE and 1394

        This value Indicates the width of the area of interest represented in the acquired image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ChunkWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ChunkWidth;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IEnumParameterT<ClConfigurationEnums>& ClConfiguration;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the delay between end of transmission and start of transmission of consecutive lines - Applies to: CameraLink Camera

        The Inter-line Delay Abs parameter sets the delay between the end of transmission of a line and the start of transmission of the next line.
	The parameter sets a floating point value to express the delay in microseconds. The set value will be automatically adjusted to the nearest value that can be expressed as a multiple of the period of the currently selected pixel clock. The line valid signal (LVAL) remains low during the set delay.
	The default value of the parameter is the minimum allowed inter-line delay.
    
        \b Visibility = Guru

    */
    Pylon::IFloatEx& ClInterLineDelayAbs;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the delay between end of transmission and start of transmission of consecutive lines - Applies to: CameraLink Camera

        The Inter-line Delay Raw parameter sets the delay between the end of transmission of a line and the start of transmission of the next line.
	The parameter sets an integer value to express the delay as a number pixel clock cycles. The line valid signal (LVAL) remains low during the set number of pixel clock cycles.
	The default value of the parameter is the minimum allowed number of inter-line clock cycles.
    
        \b Visibility = Guru

    */
    Pylon::IIntegerEx& ClInterLineDelayRaw;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: CameraLink Camera

        The pixel clock used in the communication with the grabber
    
        \b Visibility = Guru

    */
    Pylon::IEnumParameterT<ClPixelClockEnums>& ClPixelClock;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief The pixel clock used in the communication with the grabber in Hz - Applies to: CameraLink Camera

    
        \b Visibility = Guru

    */
    Pylon::IFloatEx& ClPixelClockAbs;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IEnumParameterT<ClSerialPortBaudRateEnums>& ClSerialPortBaudRate;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: CameraLink Camera

        The tap geometry uniquely describes with a standardized name, the geometrical properties characterizing the different taps of a multitap camera
    
        \b Visibility = Beginner

    */
    Pylon::IEnumParameterT<ClTapGeometryEnums>& ClTapGeometry;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IEnumParameterT<ClTimeSlotsEnums>& ClTimeSlots;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Erases the last error and possibly reveals a previous error - Applies to: GigE and CameraLink Camera

        Erases the last error and possibly reveals a previous error.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ClearLastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ClearLastError;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Enables color adjustment - Applies to: GigE, 1394 and CameraLink Camera

        Enables color adjustment.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ColorAdjustmentEnable;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Hue adjustment value for the currently selected color - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        \b Selected by : ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentHue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentHue;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Adjustment of hue of the selected color (integer) - Applies to: GigE, 1394 and CameraLink Camera

        Sets an integer value for the adjustment of hue of the selected color.
    
        \b Visibility = Expert

        \b Selected by : ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentHueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorAdjustmentHueRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Allows returning to previous settings - Applies to: GigE, 1394 and CameraLink Camera

        Allows returning to the color adjustment settings extant before the latest changes of the settings.
This allows you undoing the latest unwanted changes of the color adjustment settings and returning to the preceding settings.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ColorAdjustmentReset;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Saturation adjustment value for the currently selected color - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        \b Selected by : ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSaturation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorAdjustmentSaturation;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Adjustment of saturation of the selected color (integer) - Applies to: GigE, 1394 and CameraLink Camera

        Sets an integer value for the adjustment of saturation of the selected color.
    
        \b Visibility = Expert

        \b Selected by : ColorAdjustmentSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSaturationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorAdjustmentSaturationRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the color for color adjustment - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorAdjustmentSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorAdjustmentSelectorEnums>& ColorAdjustmentSelector;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Enables color overexposure compensation - Applies to: GigE and CameraLink Camera

        Enables color overexposure compensation.
    
        \b Visibility = Beginner

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ColorOverexposureCompensationAOIEnable;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Sets the color overexposure compensation factor for the selected C O C  AOI - Applies to: GigE and CameraLink Camera

        Sets the color overexposure compensation factor controlling the extent of compensation for the selected C.O.C. AOI.
    
        \b Visibility = Guru

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIFactor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorOverexposureCompensationAOIFactor;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Sets the raw value for the color overexposure compensation factor - Applies to: GigE and CameraLink Camera

        Sets the raw value for the color overexposure compensation factor.
    
        \b Visibility = Guru

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIFactorRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorOverexposureCompensationAOIFactorRaw;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Sets the height for the selected C O C  AOI - Applies to: GigE and CameraLink Camera

        Sets the height for the selected Color Overexposure Compensation AOI.
    
        \b Visibility = Guru

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorOverexposureCompensationAOIHeight;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Sets the X offset for the selected C O C  AOI - Applies to: GigE and CameraLink Camera

        Sets the horizontal offset for the selected Color Overexposure Compensation AOI.
    
        \b Visibility = Guru

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIOffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorOverexposureCompensationAOIOffsetX;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Sets the Y offset for the selected C O C  AOI - Applies to: GigE and CameraLink Camera

        Sets the vertical offset for the selected Color Overexposure Compensation AOI.
    
        \b Visibility = Guru

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorOverexposureCompensationAOIOffsetY;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Selcts the AOI for color overexposure compensation - Applies to: GigE and CameraLink Camera

        Selcts the area of interest where color overexposure compensation will be performed. 
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOISelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorOverexposureCompensationAOISelectorEnums>& ColorOverexposureCompensationAOISelector;
    
    //@}


    //! \name Category Color Overexposure Compensation
    //@{
    /*!
        \brief Sets the width for the selected C O C  AOI - Applies to: GigE and CameraLink Camera

        Sets the width for the selected Color Overexposure Compensation AOI.
    
        \b Visibility = Guru

        \b Selected by : ColorOverexposureCompensationAOISelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorOverexposureCompensationAOIWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorOverexposureCompensationAOIWidth;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Returns the color space set for image acquisitions - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorSpace" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorSpaceEnums>& ColorSpace;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Defines the extent to which the selected light source will be considered (float) - Applies to: GigE, 1394 and CameraLink Camera

        Sets a floating point value to define the extent to which the selected light source will be considered in color matrix transformation.
If the value is set to 1 the selected light source will be fully considered. If the value is set to 0 the selected light source will not be considered.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationMatrixFactor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorTransformationMatrixFactor;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Defines the extent to which the selected light source will be considered (integer) - Applies to: GigE, 1394 and CameraLink Camera

        Sets an integer value to define the extent to which the selected light source will be considered in color matrix transformation. If the value is set to 65536 the selected light source will be fully considered. If the value is set to 0 the selected light source will not be considered.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationMatrixFactorRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorTransformationMatrixFactorRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the type of color transformation that will be performed - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationSelectorEnums>& ColorTransformationSelector;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Transformation value for the selected element in the color transformation matrix - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : ColorTransformationSelector, ColorTransformationValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ColorTransformationValue;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets an integer value for the selected element in the color transformation matrix - Applies to: GigE, 1394 and CameraLink Camera

        Sets an integer value for the selected element in the color transformation matrix.
    
        \b Visibility = Guru

        \b Selected by : ColorTransformationValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValueRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ColorTransformationValueRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the element to be entered in the color transformation matrix - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Sets the element to be entered in the color transformation matrix for custom color transformation. Note: Depending on the camera model, some elements in the color transformation matrix may be preset and can not be changed.
    
        \b Visibility = Guru

        \b Selected by : ColorTransformationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ColorTransformationValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ColorTransformationValueSelectorEnums>& ColorTransformationValueSelector;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Increases the contrast by setting the darkest regions of the image to black - Applies to: dart USB, pulse and dart BCON

        Increases the contrast by setting the darkest regions of the image to black. A digital gain is applied to the remaining pixels to maintain the original saturation level.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ContrastEnhancement" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ContrastEnhancement;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ContrastEnhancementRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ContrastEnhancementRaw;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Duration (or number of events) before the CounterEnd event is generated - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CounterDuration;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the event that increments the currently selected counter - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterEventSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterEventSourceEnums>& CounterEventSource;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Immediately resets the selected counter - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Immediately resets the selected counter. The counter starts counting immediately after the reset.
    
        \b Visibility = Beginner

        \b Selected by : CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& CounterReset;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the signal on which the counter will be reset - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetActivationEnums>& CounterResetActivation;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the source signal that can reset the currently selected counter - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : CounterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterResetSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterResetSourceEnums>& CounterResetSource;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the counter to be configured - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Sets the counter to be configured. Once a counter has been set, all changes to the counter settings will be applied to this counter.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CounterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<CounterSelectorEnums>& CounterSelector;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Shows the over temperature state of the selected target - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CriticalTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& CriticalTemperature;
    
    //@}


    //! \name Category Critical Temperature Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for a critical temperature event - Applies to: GigE

        This enumeration Indicates the stream channel index for a critical temperature event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CriticalTemperatureEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CriticalTemperatureEventStreamChannelIndex;
    
    //@}


    //! \name Category Critical Temperature Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a critical temperature event - Applies to: GigE

        This enumeration value indicates the time stamp for a critical temperature event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=CriticalTemperatureEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& CriticalTemperatureEventTimestamp;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Horizontal decimation factor - Applies to: ace USB, GigE and CameraLink Camera

        Horizontal decimation factor. It specifies the extent of horizontal sub-sampling of the acquired frame, i.e. it defines how many pixel columns are left out of transmission. This has the net effect of reducing the horizontal resolution (width) of the image by the specified decimation factor. A value of 1 indicates that the camera performs no horizontal decimation.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationHorizontal;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Vertical decimation factor - Applies to: ace USB, GigE and CameraLink Camera

        Vertical decimation factor. It specifies the extent of vertical sub-sampling of the acquired frame, i.e. it defines how many rows are left out of transmission. This has the net effect of reducing the vertical resolution (height) of the image by the specified decimation factor. A value of 1 indicates that the camera performs no vertical decimation.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DecimationVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DecimationVertical;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Selects the which factory setting will be used as default set - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DefaultSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DefaultSetSelectorEnums>& DefaultSetSelector;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Identifies outlier pixels and adjusts their intensity value - Applies to: dart USB, pulse and dart BCON

        Identifies pixels that have a significantly greater or lesser intensity value than its neighboring pixels (outlier pixels) and adjusts their intensity value.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DefectPixelCorrectionMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DefectPixelCorrectionModeEnums>& DefectPixelCorrectionMode;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DefectPixelCorrectionVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DefectPixelCorrectionVersion;
    
    //@}


    //! \name Category Calibration Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DefectPixelTableSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DefectPixelTableSize;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the demosaicing mode - Applies to: ace USB and GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DemosaicingMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DemosaicingModeEnums>& DemosaicingMode;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Indicates the device clock frequency - Applies to: dart BCON

    
        \b Visibility = Expert

        \b Selected by : DeviceClockSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceClockFrequency" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& DeviceClockFrequency;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Sets the device clock - Applies to: dart BCON

        Sets the device clock. Once a device clock has been set, the device clock frequency can be read using the DeviceClockFrequency parameter.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceClockSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceClockSelectorEnums>& DeviceClockSelector;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Version of the device's firmware - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceFirmwareVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceFirmwareVersion;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief A unique identifier for the device such as a serial number or a GUID - Applies to: GigE and CameraLink Camera

        This is a read only element. It is a string that provides a unique identifier for the device such as a serial number or a GUID.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceID;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Controls the behavior of the indicators (such as LEDs) showing the status of the device - Applies to: dart USB and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceIndicatorMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceIndicatorModeEnums>& DeviceIndicatorMode;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Actual bandwidth the camera will use - Applies to: ace USB

        Actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data given the current camera settings.
    
        \b Visibility = Expert

        \b Selected by : DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkCurrentThroughput" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkCurrentThroughput;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Sets which link of the device to control - Applies to: ace USB, dart USB and pulse

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSelector;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Speed of transmission negotiated on the selected link - Applies to: ace USB, dart USB and pulse

    
        \b Visibility = Expert

        \b Selected by : DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkSpeed" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkSpeed;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Value set to limit the maximum bandwidth of the data that will be streamed out by the device (in bytes per second) - Applies to: ace USB, dart USB and pulse

        Value set to limit the maximum bandwidth of the data that will be streamed out by the device on the currently selected link (in bytes per second).
    
        \b Visibility = Beginner

        \b Selected by : DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkThroughputLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceLinkThroughputLimit;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Controls if the device link throughput limit is active - Applies to: ace USB, dart USB and pulse

        Controls if the device link throughput limit is active. When disabled, lower level throughput limit specific features are expected to control the throughput. When enabled, the device link throughput limit controls the overall throughput.
    
        \b Visibility = Beginner

        \b Selected by : DeviceLinkSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceLinkThroughputLimitMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceLinkThroughputLimitModeEnums>& DeviceLinkThroughputLimitMode;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Additional information from the vendor about the camera - Applies to: ace USB, dart USB, pulse, GigE, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceManufacturerInfo" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceManufacturerInfo;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Model name of the device - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceModelName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceModelName;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Announce the end of registers streaming - Applies to: dart USB, pulse, GigE, CameraLink Camera and dart BCON

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceRegistersStreamingEnd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceRegistersStreamingEnd;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Prepare the device for registers streaming without checking for consistency - Applies to: dart USB, pulse, GigE, CameraLink Camera and dart BCON

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceRegistersStreamingStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceRegistersStreamingStart;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Immediately resets and reboots the device - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& DeviceReset;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Major version number of the SFNC specification that the device is compatible with - Applies to: ace USB, dart USB, pulse and dart BCON

        Major version number of the Standard Features Naming Convention (SFNC) specification that the device is compatible with.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMajor;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Minor version number of the SFNC specification that the device is compatible with - Applies to: ace USB, dart USB, pulse and dart BCON

        Minor version number of the Standard Features Naming Convention (SFNC) specification that the device is compatible with.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionMinor;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Subminor version number of the SFNC specification that the device is compatible with - Applies to: ace USB, dart USB, pulse and dart BCON

        Subminor version number of the Standard Features Naming Convention (SFNC) specification that the device is compatible with.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSFNCVersionSubMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DeviceSFNCVersionSubMinor;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Returns the scan type of the device's sensor (area or line scan) - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceScanType" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceScanTypeEnums>& DeviceScanType;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Serial number of the device - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceSerialNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceSerialNumber;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Indicates the serial number of the device - Applies to: 1394

        This is a read only element. It is an integer that indicates the serial number of the device.
    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& DeviceSerialNumber2;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Temperature of the selected location within the device (in degrees centigrade) - Applies to: ace USB

        Temperature of the selected location within the device (in degrees centigrade). The temperature is measured at the location set by DeviceTemperatureSelector.
    
        \b Visibility = Expert

        \b Selected by : DeviceTemperatureSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& DeviceTemperature;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Sets the location within the device where the temperature will be measured - Applies to: ace USB

        Sets the location within the device where the temperature will be measured. Once a location has been set, the temperature can be retrieved using the DeviceTemperature parameter.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceTemperatureSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<DeviceTemperatureSelectorEnums>& DeviceTemperatureSelector;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief User-settable ID of the device - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceUserID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceUserID;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Name of the device's vendor - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVendorName" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVendorName;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Version of the device - Applies to: ace USB, dart USB, pulse, GigE, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DeviceVersion" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& DeviceVersion;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Value set for digital shift - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Value set for digital shift. When the parameter is set to zero, digital shift will be disabled. When the parameter is set to 1, 2, 3, or 4, digital shift will be set to shift by 1, shift by 2, shift by 3, or shift by 4 respectively.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=DigitalShift" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& DigitalShift;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief When enabled, the maximum frame rate does not depend on the image transfer rate out of the camera - Applies to: GigE, 1394 and CameraLink Camera

        When enabled, the maximum frame rate onyl depends on sensor timing and timing of the trigger sequence, and not on the image transfer rate out of the camera.

Note: The maximum number of triggers within a burst sequence is limited. If the maximum number is exceeded, images may be damaged or lost.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EnableBurstAcquisition" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& EnableBurstAcquisition;
    
    //@}


    //! \name Category Event Critical Temperature Data
    //@{
    /*!
        \brief Unique identifier of the critical temperature event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventCriticalTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventCriticalTemperature;
    
    //@}


    //! \name Category Event Critical Temperature Data
    //@{
    /*!
        \brief Time stamp of the crititical temperature event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventCriticalTemperatureTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventCriticalTemperatureTimestamp;
    
    //@}


    //! \name Category Exposure End Event Data
    //@{
    /*!
        \brief Unique identifier of the exposure end event - Applies to: ace USB

        Unique identifier of the exposure end event. This parameter can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEnd" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEnd;
    
    //@}


    //! \name Category Exposure End Event Data
    //@{
    /*!
        \brief Frame ID of the exposure end event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEndFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEndFrameID;
    
    //@}


    //! \name Category Exposure End Event Data
    //@{
    /*!
        \brief Time stamp of the exposure end event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventExposureEndTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventExposureEndTimestamp;
    
    //@}


    //! \name Category Frame Burst Start Event Data
    //@{
    /*!
        \brief Unique identifier of the frame burst start event - Applies to: ace USB

        Unique identifier of the frame burst start event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStart;
    
    //@}


    //! \name Category Frame Burst Start Event Data
    //@{
    /*!
        \brief Frame ID of the frame burst start event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartFrameID;
    
    //@}


    //! \name Category Frame Burst Start Overtrigger Event Data
    //@{
    /*!
        \brief Unique identifier of the frame burst start overtrigger event - Applies to: ace USB

        Unique identifier of the frame burst start overtrigger event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertrigger;
    
    //@}


    //! \name Category Frame Burst Start Overtrigger Event Data
    //@{
    /*!
        \brief Frame ID of the frame burst start overtrigger event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertriggerFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertriggerFrameID;
    
    //@}


    //! \name Category Frame Burst Start Overtrigger Event Data
    //@{
    /*!
        \brief Time stamp of the frame burst start overtrigger event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartOvertriggerTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartOvertriggerTimestamp;
    
    //@}


    //! \name Category Frame Burst Start Event Data
    //@{
    /*!
        \brief Time stamp of the frame burst start event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartTimestamp;
    
    //@}


    //! \name Category Event Frame Burst Start Wait Data
    //@{
    /*!
        \brief Unique identifier of the frame burst start wait event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartWait" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartWait;
    
    //@}


    //! \name Category Event Frame Burst Start Wait Data
    //@{
    /*!
        \brief Time stamp of the frame brust start wait event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameBurstStartWaitTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameBurstStartWaitTimestamp;
    
    //@}


    //! \name Category Frame Start Event Data
    //@{
    /*!
        \brief Unique identifier of the frame start event - Applies to: ace USB

        Unique identifier of the frame start event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStart;
    
    //@}


    //! \name Category Frame Start Event Data
    //@{
    /*!
        \brief Frame ID of the frame start event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartFrameID;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Unique identifier of the frame start overtrigger event - Applies to: ace USB

        Unique identifier of the frame start overtrigger event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertrigger;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Frame ID of the frame start overtrigger event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertriggerFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertriggerFrameID;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Time stamp of the frame start overtrigger event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartOvertriggerTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartOvertriggerTimestamp;
    
    //@}


    //! \name Category Frame Start Event Data
    //@{
    /*!
        \brief Time stamp of the frame start event - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartTimestamp;
    
    //@}


    //! \name Category Event Frame Start
    //@{
    /*!
        \brief Unique identifier of the frame start wait event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartWait" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartWait;
    
    //@}


    //! \name Category Event Frame Start
    //@{
    /*!
        \brief Time stamp of the frame start wait event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventFrameStartWaitTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventFrameStartWaitTimestamp;
    
    //@}


    //! \name Categories Event Control and Events Generation
    //@{
    /*!
        \brief Enables event notifications for the currently selected event - Applies to: ace USB, GigE and 1394

        Enables event notifications for the currently selected event. The event can selected using the EventSelector parameter.
    
        \b Visibility = Expert

        \b Selected by : EventSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventNotification" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventNotificationEnums>& EventNotification;
    
    //@}


    //! \name Category Event Over Temperature Data
    //@{
    /*!
        \brief Unique identifier of the over temperature event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverTemperature;
    
    //@}


    //! \name Category Event Over Temperature Data
    //@{
    /*!
        \brief Time stamp of the over temperature event - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverTemperatureTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverTemperatureTimestamp;
    
    //@}


    //! \name Category EventOverrun Event Data
    //@{
    /*!
        \brief Indicates the frame ID for an event overrun event - Applies to: GigE and 1394

        This enumeration value indicates the frame ID for an event overrun event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverrunEventFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverrunEventFrameID;
    
    //@}


    //! \name Category EventOverrun Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an event overrun event - Applies to: GigE and 1394

        This enumeration value indicates the stream channel index for an event overrun event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverrunEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverrunEventStreamChannelIndex;
    
    //@}


    //! \name Category EventOverrun Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an event overrun event - Applies to: GigE and 1394

        This enumeration value indicates the time stamp for an event overrun event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventOverrunEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventOverrunEventTimestamp;
    
    //@}


    //! \name Categories Event Control and Events Generation
    //@{
    /*!
        \brief Sets the event notification to be enabled - Applies to: ace USB, GigE and 1394

        Sets the event notification to be enabled. Once an event notification has been set, the notification can be enabled using the EventNotification parameter.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<EventSelectorEnums>& EventSelector;
    
    //@}


    //! \name Category Test Event Data
    //@{
    /*!
        \brief Unique identifier of the test event - Applies to: ace USB

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventTest" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventTest;
    
    //@}


    //! \name Category Test Event Data
    //@{
    /*!
        \brief Time stamp of the test event - Applies to: ace USB

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=EventTestTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& EventTestTimestamp;
    
    //@}


    //! \name Category Expert Feature Access
    //@{
    /*!
        \brief Key to access the selected expert feature - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessKey" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExpertFeatureAccessKey;
    
    //@}


    //! \name Category Expert Feature Access
    //@{
    /*!
        \brief Sets the expert feature to be configured - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Sets the expert feature to be configured. Once a feature has been set, all changes made using the feature enable feature will be applied to this feature.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureAccessSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExpertFeatureAccessSelectorEnums>& ExpertFeatureAccessSelector;
    
    //@}


    //! \name Category Expert Feature Access
    //@{
    /*!
        \brief Enables the currently selected expert feature - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : ExpertFeatureAccessSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExpertFeatureEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ExpertFeatureEnable;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the operation mode of the exposure auto function - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Sets the operation mode of the exposure auto function. The exposure auto function automatically adjusts the exposure time within set limits until a target brightness value is reached.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureAutoEnums>& ExposureAuto;
    
    //@}


    //! \name Category Exposure End Event Data
    //@{
    /*!
        \brief Indicates the frame ID for an exposure end event - Applies to: GigE and 1394

        This enumeration value indicates the frame ID for an exposure end event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureEndEventFrameID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureEndEventFrameID;
    
    //@}


    //! \name Category Exposure End Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an exposure end event - Applies to: GigE and 1394

        This enumeration value indicates the stream channel index for an exposure end event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureEndEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureEndEventStreamChannelIndex;
    
    //@}


    //! \name Category Exposure End Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an exposure end event - Applies to: GigE and 1394

        This enumeration value indicates the time stamp for an exposure end event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureEndEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureEndEventTimestamp;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the exposure mode - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureModeEnums>& ExposureMode;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Maximum overlap of the sensor exposure with sensor readout in TriggerWidth exposure mode (in microseconds) - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureOverlapTimeMax;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the maximum overlap of the sensor exposure with sensor readout in TriggerWidth exposure mode in microseconds - Applies to: GigE and CameraLink Camera

        This float value sets the maximum overlap time (in microseconds) of the sensor exposure with sensor readout in TriggerWidth exposure mode.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMaxAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureOverlapTimeMaxAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the maximum overlap of the sensor exposure with the sensor readout in TriggerWidth exposure mode in raw units - Applies to: GigE and CameraLink Camera

        This integer value sets the maximum overlap time (in raw units) of the sensor exposure with sensor readout in TriggerWidth exposure mode.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMaxRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureOverlapTimeMaxRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the exposure overlap time mode - Applies to: ace USB and GigE

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureOverlapTimeMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ExposureOverlapTimeModeEnums>& ExposureOverlapTimeMode;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureStartDelayAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureStartDelayAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureStartDelayRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureStartDelayRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Exposure time of the camera in microseconds - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTime;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Directly sets the camera's exposure time in microseconds - Applies to: GigE, 1394, CameraLink Camera and CamEmu

        This float value sets the camera's exposure time in microseconds.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTimeAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the time base (in microseconds) that is used when the exposure time is set with the 'exposure time raw' setting - Applies to: GigE, 1394, CameraLink Camera and CamEmu

        This float value sets the time base (in microseconds) that is used when the exposure time is set with the 'raw' setting.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeBaseAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ExposureTimeBaseAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Enables the use of the exposure time base - Applies to: GigE, 1394 and CameraLink Camera

        This value enables the use of the exposure time base.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeBaseAbsEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ExposureTimeBaseAbsEnable;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the 'raw' exposure time   Actual exposure time = raw exposure setting  x  exposure time base abs setting - Applies to: dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        This value sets an integer that will be used as a multiplier for the exposure timebase. The actual exposure time equals the current exposure time raw setting times the current exposure time base abs setting.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ExposureTimeRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ExposureTimeRaw;
    
    //@}


    //! \name Category Feature Sets
    //@{
    /*!
        \brief Select a camera description file - Applies to: GigE and CameraLink Camera

        Selects a feature set description file.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FeatureSet" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FeatureSetEnums>& FeatureSet;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Selects the mode to output the fields - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FieldOutputMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FieldOutputModeEnums>& FieldOutputMode;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Access buffer for file operations - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessBuffer" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& FileAccessBuffer;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief File access length - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        File access length. Controls the mapping between the device file storage and the FileAccessBuffer.
    
        \b Visibility = Guru

        \b Selected by : FileSelector, FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessLength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessLength;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief File access offset - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        File access offset. Controls the mapping between the device file storage and the FileAccessBuffer.
    
        \b Visibility = Guru

        \b Selected by : FileSelector, FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileAccessOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileAccessOffset;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Sets the access mode in which a file is opened in the device - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOpenMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOpenModeEnums>& FileOpenMode;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Executes the operation selected by FileOperationSelector - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Executes the operation selected by FileOperationSelector on the selected file.
    
        \b Visibility = Guru

        \b Selected by : FileSelector, FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationExecute" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& FileOperationExecute;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief File operation result - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        File operation result. For read or write operations, the number of successfully read/written bytes is returned.
    
        \b Visibility = Guru

        \b Selected by : FileSelector, FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationResult" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileOperationResult;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Sets the target operation for the currently selected file - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Sets the target operation for the currently selected file. After an operation has been selected, the operation can be executed using the FileOperationExecute command.
    
        \b Visibility = Guru

        \b Selected by : FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationSelectorEnums>& FileOperationSelector;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Returns the file operation execution status - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : FileSelector, FileOperationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileOperationStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileOperationStatusEnums>& FileOperationStatus;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Sets the target file in the device - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FileSelectorEnums>& FileSelector;
    
    //@}


    //! \name Category File Access Control
    //@{
    /*!
        \brief Size of the currently selected file in bytes - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : FileSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FileSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FileSize;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Marks the next buffer as failed - Applies to: CamEmu

        Marks the next buffer as a failed buffer.
    
        \b Visibility = Expert

    */
    Pylon::ICommandEx& ForceFailedBuffer;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Number of failed buffers to generate - Applies to: CamEmu

    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& ForceFailedBufferCount;
    
    //@}


    //! \name Category Frame Start  Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an frame start  event - Applies to: GigE

        This enumeration Indicates the stream channel index for an frame start  event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartEventStreamChannelIndex;
    
    //@}


    //! \name Category Frame Start  Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an frame start  event - Applies to: GigE

        This enumeration value indicates the time stamp for an frame start  event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartEventTimestamp;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an frame start overtrigger event - Applies to: GigE and 1394

        This enumeration Indicates the stream channel index for an frame start overtrigger event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartOvertriggerEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartOvertriggerEventStreamChannelIndex;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an frame start overtrigger event - Applies to: GigE and 1394

        This enumeration value indicates the time stamp for an frame start overtrigger event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartOvertriggerEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartOvertriggerEventTimestamp;
    
    //@}


    //! \name Category Frame Start Wait Event Data
    //@{
    /*!
        \brief Stream channel index of the frame start wait event - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartWaitEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartWaitEventStreamChannelIndex;
    
    //@}


    //! \name Category Frame Start Wait Event Data
    //@{
    /*!
        \brief Time stamp of the frame start wait event - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameStartWaitEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameStartWaitEventTimestamp;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the frame timeout in microseconds - Applies to: GigE and CameraLink Camera

        Sets the frame timeout in microseconds. When the timeout expires before a frame acquisition is complete, a partial frame will be delivered.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameTimeoutAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& FrameTimeoutAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Enables the frame timeout - Applies to: GigE and CameraLink Camera

        This boolean value enables the frame timeout. 
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameTimeoutEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& FrameTimeoutEnable;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an frame timeout event - Applies to: GigE and 1394

        This enumeration Indicates the stream channel index for an frame timeout event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameTimeoutEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameTimeoutEventStreamChannelIndex;
    
    //@}


    //! \name Category Frame Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an frame timeout event - Applies to: GigE and 1394

        This enumeration value indicates the time stamp for an frame timeout event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameTimeoutEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameTimeoutEventTimestamp;
    
    //@}


    //! \name Category Frame Wait Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an frame wait event - Applies to: GigE

        This enumeration Indicates the stream channel index for an frame wait event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameWaitEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameWaitEventStreamChannelIndex;
    
    //@}


    //! \name Category Frame Wait Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an frame wait event - Applies to: GigE

        This enumeration value indicates the time stamp for an frame wait event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrameWaitEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrameWaitEventTimestamp;
    
    //@}


    //! \name Category Frequency Converter
    //@{
    /*!
        \brief Selects the input source - Applies to: GigE and CameraLink Camera

        Selects the input source for the frequency converter module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrequencyConverterInputSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FrequencyConverterInputSourceEnums>& FrequencyConverterInputSource;
    
    //@}


    //! \name Category Frequency Converter
    //@{
    /*!
        \brief Sets the multiplier value for the multiplier sub-module - Applies to: GigE and CameraLink Camera

        Sets an integer value as the multiplier for the multiplier sub-module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrequencyConverterMultiplier" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrequencyConverterMultiplier;
    
    //@}


    //! \name Category Frequency Converter
    //@{
    /*!
        \brief Sets the post-divider value for the post-divider sub-module - Applies to: GigE and CameraLink Camera

        Sets an integer value as the post-divider for the post-divider sub-module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrequencyConverterPostDivider" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrequencyConverterPostDivider;
    
    //@}


    //! \name Category Frequency Converter
    //@{
    /*!
        \brief Sets the pre-divider value for the pre-divider sub-module - Applies to: GigE and CameraLink Camera

        Sets an integer value as the pre-divider for the pre-divider sub-module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrequencyConverterPreDivider" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& FrequencyConverterPreDivider;
    
    //@}


    //! \name Category Frequency Converter
    //@{
    /*!
        \brief Enables overtriggering protection - Applies to: GigE and CameraLink Camera

        This feature ensures that the multiplier sub-module does not provide a generated signal at a too high frequency that would cause camera overtriggering.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrequencyConverterPreventOvertrigger" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& FrequencyConverterPreventOvertrigger;
    
    //@}


    //! \name Category Frequency Converter
    //@{
    /*!
        \brief Selects the signal transition relationships between received and generated signals - Applies to: GigE and CameraLink Camera

        Selects the signal transition relationships between the signals received from the pre-divider sub-module and the signals generated by the multiplier sub-module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=FrequencyConverterSignalAlignment" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<FrequencyConverterSignalAlignmentEnums>& FrequencyConverterSignalAlignment;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Value of the currently selected gain control in dB - Applies to: ace USB, dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gain" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gain;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief This is a float value that sets the selected gain control in dB - Applies to: GigE and CameraLink Camera

        Sets the 'absolute' value of the selected gain control. The 'absolute' value is a float value that sets the selected gain control in dB.
    
        \b Visibility = Beginner

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& GainAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the operation mode of the gain auto function - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Sets the operation mode of the gain auto function. The gain auto function automatically adjusts the gain within set limits until a target brightness value is reached.
    
        \b Visibility = Beginner

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainAuto" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainAutoEnums>& GainAuto;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief This is an integer value that sets the selected gain control in device specific units - Applies to: dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Sets the 'raw' value of the selected gain control. The 'raw' value is an integer value that sets the selected gain control in units specific to the camera.
    
        \b Visibility = Invisible

        \b Selected by : GainSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GainRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the gain channel or tap to be adjusted - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Sets the gain channel or tap to be adjusted. Once a gain channel or tap has been selected, all changes to the Gain parameter will be applied to the selected channel or tap.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GainSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GainSelectorEnums>& GainSelector;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Gamma correction value - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Gamma correction value. Gamma correction lets you modify the brightness of the pixel values to account for a non-linearity in the human perception of brightness.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Gamma" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& Gamma;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Enables the gamma correction - Applies to: GigE, 1394 and CameraLink Camera

        This boolean value enables the gamma correction.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GammaEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GammaEnable;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GammaRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GammaRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

        This enumeration selects the type of gamma to apply.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GammaSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GammaSelectorEnums>& GammaSelector;
    
    //@}


    //! \name Category Feature Sets
    //@{
    /*!
        \brief Select default genicam XML file - Applies to: GigE and CameraLink Camera

        If the camera contains multiple GenICam XML files, this parameter determines which of them is accessible to non-manifest-aware software accessing register address 0x0200 (first url).
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GenicamXmlFileDefault" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GenicamXmlFileDefault;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the control channel privilege feature - Applies to: GigE

        This enumeration sets the control channel privilege feature.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCCP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevCCPEnums>& GevCCP;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the current default gateway for the selected network interface - Applies to: GigE

        This is a read only element. It indicates the current default gateway for the selected network interface.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentDefaultGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentDefaultGateway;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the current IP address for the selected network interface - Applies to: GigE

        This is a read only element. It indicates the current IP address for the selected network interface.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentIPAddress;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the current IP configuration of the selected network interface - Applies to: GigE

        This value sets the IP configuration of the selected network interface, i.e., fixed IP, DHCP, auto IP. 
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentIPConfiguration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentIPConfiguration;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the current subnet mask for the selected network interface - Applies to: GigE

        This is a read only element. It indicates the current subnet mask for the selected network interface.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevCurrentSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevCurrentSubnetMask;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indictes the character set - Applies to: GigE

        This is a read only element. Its value indicates the character set. 1 = UTF8
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceModeCharacterSet" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevDeviceModeCharacterSet;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the endianess of the bootstrap registers - Applies to: GigE

        This is a read only element. It indicates the endianess of the bootstrap registers. True = big endian.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevDeviceModeIsBigEndian" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevDeviceModeIsBigEndian;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the first URL to the XML device description file - Applies to: GigE

        This is a read only element. It indicates the first URL to the XML device description file.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevFirstURL" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& GevFirstURL;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Enable the extended ID mode for GVSP - Applies to: GigE

        Enable extended ID mode for GVSP (64 bit block_id64, 32 bit packet_id32). This bit cannot be reset if the stream channels do not support the standard ID mode.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevGVSPExtendedIDMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevGVSPExtendedIDModeEnums>& GevGVSPExtendedIDMode;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the heartbeat timeout in milliseconds - Applies to: GigE

        This value sets the heartbeat timeout in milliseconds.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevHeartbeatTimeout" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevHeartbeatTimeout;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Enable usage of the IEEE 1588 V2 Precision Time Protocol to source the timestamp register  Only available when the IEEE1588_support bit of the GVCP Capability register is set  When PTP is enabled, the Timestamp Control register cannot be used to reset the timestamp  Factory default is devicespecific  When PTP is enabled or disabled, the value of Timestamp Tick Frequency and Timestamp Value registers might change to reflect the new time domain - Applies to: GigE

        This value indicates whether IEEE 1588 V2 (PTP) is enabled.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevIEEE1588;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the latched clock ID of the IEEE 1588 device - Applies to: GigE

        This is a read only element. It indicates the latched clock ID of the IEEE 1588 device. (The clock ID must first be latched using the IEEE 1588 Latch command.) The clock ID is an array of eight octets which is displayed as hexadecimal number. Leading zeros are omitted.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ClockId" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ClockId;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. It is the high part of the 1588 clock ID
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ClockIdHigh" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ClockIdHigh;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. It is the low part of the 1588 clock ID
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ClockIdLow" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ClockIdLow;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Latches the current IEEE 1588 related values of the device - Applies to: GigE

        This command latches the current IEEE 1588 related values of the device.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588DataSetLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevIEEE1588DataSetLatch;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. It indicates the latched offset from the IEEE 1588 master clock in nanoseconds. (The offset must first be latched using the IEEE 1588 Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588OffsetFromMaster" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588OffsetFromMaster;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the latched parent clock ID of the IEEE 1588 device - Applies to: GigE

        This is a read only element. It indicates the latched parent clock ID of the IEEE 1588 device. (The parent clock ID must first be latched using the IEEE 1588 Latch command.) The parent clock ID is the clock ID of the current master clock. A clock ID is an array of eight octets which is displayed as hexadecimal number. Leading zeros are omitted.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ParentClockId" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ParentClockId;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. It is the high part of the 1588 parent clock ID
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ParentClockIdHigh" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ParentClockIdHigh;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. It is the low part of the 1588 parent clock ID
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588ParentClockIdLow" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevIEEE1588ParentClockIdLow;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Provides the state of the IEEE 1588 clock - Applies to: GigE

        Provides the state of the IEEE 1588 clock. Values of this field must match the IEEE 1588 PTP port state enumeration (INITIALIZING, FAULTY, DISABLED, LISTENING, PRE_MASTER, MASTER, PASSIVE, UNCALIBRATED, SLAVE). Please refer to IEEE 1588 for additional information.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588Status" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevIEEE1588StatusEnums>& GevIEEE1588Status;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the latched state of the IEEE 1588 clock - Applies to: GigE

        This is a read only element. It indicates the latched state of the IEEE 1588 clock. (The state must first be latched using the IEEE 1588 Latch command.) The state is indicated by values 1 to 9, corresponding to the states INITIALIZING, FAULTY, DISABLED, LISTENING, PRE_MASTER, MASTER, PASSIVE, UNCALIBRATED, and SLAVE. Refer to the IEEE 1588 specification for additional information.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevIEEE1588StatusLatched" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevIEEE1588StatusLatchedEnums>& GevIEEE1588StatusLatched;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Selects the physical network interface to configure  Once a network interface has been selected, all changes to the network interface settings will be applied to the selected interface - Applies to: GigE

        This selects the physical network interface to configure. Once a network interface has been selected, all changes to the network interface settings will be applied to the selected interface.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevInterfaceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevInterfaceSelectorEnums>& GevInterfaceSelector;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the state of medium-dependent interface crossover (MDIX) for the selected network interface - Applies to: GigE

        This is a read only element. It indicates the state of medium-dependent interface crossover (MDIX) for the selected network interface.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkCrossover" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevLinkCrossover;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether the selected network interface operates in full-duplex mode - Applies to: GigE

        This is a read only element. It indicates whether the selected network interface operates in full-duplex mode.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkFullDuplex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevLinkFullDuplex;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether the selected network interface is the clock master - Applies to: GigE

        This is a read only element. It indicates whether the selected network interface is the clock master.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkMaster" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevLinkMaster;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the connection speed in Mbps for the selected network interface - Applies to: GigE

        This is a read only element. It indicates the connection speed in Mbps for the selected network interface.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevLinkSpeed" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevLinkSpeed;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the MAC address for the selected network interface - Applies to: GigE

        This is a read only element. It indicates the MAC address for the selected network interface.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevMACAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevMACAddress;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the number of message channels supported by the device - Applies to: GigE

        This is a read only element. It indicates the number of message channels supported by the device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevMessageChannelCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevMessageChannelCount;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the number of network interfaces on the device - Applies to: GigE

        This is a read only element. It indicates the number of network interfaces on the device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevNumberOfInterfaces" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevNumberOfInterfaces;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. Maximum number of elements in RX event message queue. (The value must first be latched using the IEEE 1588 Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPTPDiagnosticsQueueRxEvntMaxNumElements" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPTPDiagnosticsQueueRxEvntMaxNumElements;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. Number of push failures in RX event message queue. (The value must first be latched using the IEEE 1588 Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPTPDiagnosticsQueueRxEvntPushNumFailure" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPTPDiagnosticsQueueRxEvntPushNumFailure;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. Maximum number of elements in RX general message queue. (The value must first be latched using the IEEE 1588 Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPTPDiagnosticsQueueRxGnrlMaxNumElements" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPTPDiagnosticsQueueRxGnrlMaxNumElements;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. Number of push failures in RX general message queue. (The value must first be latched using the IEEE 1588 Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPTPDiagnosticsQueueRxGnrlPushNumFailure" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPTPDiagnosticsQueueRxGnrlPushNumFailure;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

        This is a read only element. Number of send failures. (The value must first be latched using the IEEE 1588 Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPTPDiagnosticsQueueSendNumFailure" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPTPDiagnosticsQueueSendNumFailure;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief If fixed (persistent) IP addressing is supported by the device and enabled, sets the fixed default gateway for the selected network interface  - Applies to: GigE

        This value sets the fixed default gateway for the selected network interface (if fixed IP addressing is supported by the device and enabled).
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentDefaultGateway" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentDefaultGateway;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief If fixed (persistent) IP addressing is supported by the device and enabled, sets the fixed IP address for the selected network interface  - Applies to: GigE

        This value sets the fixed IP address for the selected network interface (if fixed IP addressing is supported by the device and enabled).
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentIPAddress" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentIPAddress;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief If fixed (persistent) IP addressing is supported by the device and enabled, sets the fixed subnet mask for the selected network interface  - Applies to: GigE

        This value sets the fixed subnet mask for the selected network interface (if fixed IP addressing is supported by the device and enabled).
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevPersistentSubnetMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevPersistentSubnetMask;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the bandwidth (in bytes per second) that will be used by the camera to transmit image and chunk feature data and to handle resends and control data transmissions - Applies to: GigE

        This value indicates the base bandwidth in bytes per second that will be used by the camera to transmit image and chunk feature data and to handle resends and control data transmissions. This parameter represents a combination of the packet size and the inter-packet delay.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCBWA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCBWA;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets a percentage of the Ethernet bandwidth assigned to the camera to be held in reserve  The reserve is used for packet resends and control data transmissions   - Applies to: GigE

        This value reserves a portion of Ethernet bandwidth assigned to the camera for packet resends and for the transmission of control data between the camera and the host PC. The setting is expressed as a percentage of the bandwidth assigned parameter. For example, if the Bandwidth Assigned parameter indicates that 30 MBytes/s have been assigned to the camera and the Bandwidth Reserve parameter is set to 5%, then the bandwidth reserve will be 1.5 MBytes/s.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCBWR" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCBWR;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets a multiplier for the Bandwidth Reserve parameter  The multiplier is used to establish an extra pool of reserved bandwidth that can be used if an unusually large burst of packet resends is needed - Applies to: GigE

        This value sets a multiplier for the Bandwidth Reserve parameter. The multiplier is used to establish an extra pool of reserved bandwidth that can be used if an unusually large burst of packet resends is needed.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCBWRA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCBWRA;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the stream channel destination IPv4 address for the selected stream channel - Applies to: GigE

        This value sets the stream channel destination IPv4 address for the selected stream channel. The destination can be a unicast or a multicast.
    
        \b Visibility = Guru

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCDA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCDA;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data given the current AOI settings, chunk feature settings, and the pixel format setting - Applies to: GigE

        This value indicates the actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data given the current AOI settings, chunk feature settings, and the pixel format setting.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCDCT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCDCT;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the maximum amount of data (in bytes per second) that the camera could generate given its current settings and ideal conditions, i e , unlimited bandwidth and no packet resends - Applies to: GigE

        This value indicates the maximum amount of data (in bytes per second) that the camera could generate given its current settings and ideal conditions, i.e., unlimited bandwidth and no packet resends.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCDMT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCDMT;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the maximum time (in ticks) that the next frame transmission could be delayed due to a burst of resends - Applies to: GigE

        If the Bandwidth Reserve Accumulation parameter is set to a high value, the camera can experience periods where there is a large burst of data resends. This burst of resends will delay the start of transmission of the next acquired image. The Frame Max Jitter parameter indicates the maximum time in ticks that the next frame transmission could be delayed due to a burst of resends.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCFJM" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCFJM;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the frame transfer start delay (in ticks) for the selected stream channel - Applies to: GigE

        This value sets the frame transfer delay for the selected stream channel. This value sets a delay betweem when the camera would normally begin transmitted an acquired image (frame) and when it actually begins transmitting the acquired image.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCFTD" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCFTD;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the inter-packet delay (in ticks) for the selected stream channel - Applies to: GigE

        This value sets a delay between the transmission of each packet for the selected stream channel. The delay is measured in ticks.
    
        \b Visibility = Expert

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPD" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPD;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the port to which the device must send data streams - Applies to: GigE

        This value sets the port to which the device must send data streams.
    
        \b Visibility = Guru

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPHostPort" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPHostPort;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the index of the network interface to use - Applies to: GigE

        This value sets the index of the network interface to use.
    
        \b Visibility = Guru

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPInterfaceIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPInterfaceIndex;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Guru

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSBigEndian" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSCPSBigEndian;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Guru

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSDoNotFragment" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSCPSDoNotFragment;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: GigE

    
        \b Visibility = Guru

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSFireTestPacket" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevSCPSFireTestPacket;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the packet size in bytes for the selected stream channel - Applies to: GigE

        This value sets the packet size in bytes for the selected stream channel. Excludes data leader and data trailer. (The last packet may be smaller because the packet size is not necessarily a multiple of the block size for the stream channel.)
    
        \b Visibility = Beginner

        \b Selected by : GevStreamChannelSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSCPSPacketSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevSCPSPacketSize;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the second URL to the XML device description file - Applies to: GigE

        This is a read only element. It indicates the second URL to the XML device description file.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSecondURL" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IStringEx& GevSecondURL;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the number of stream channels supported by the device - Applies to: GigE

        This is a read only element. It indicates the number of stream channels supported by the device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevStreamChannelCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevStreamChannelCount;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Selects the stream channel to configure  Once a stream channel has been selected, all changes to the stream channel settings will be applied to the selected stream channel - Applies to: GigE

        This enumeration selects the stream channels to configure. Once a stream channel has been selected, all changes to the stream channel settings will be applied to the selected stream channel.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevStreamChannelSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<GevStreamChannelSelectorEnums>& GevStreamChannelSelector;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether IEEE 1588 (PTP) is supported - Applies to: GigE

        This is a read only element. It indicates whether whether IEEE 1588 (PTP) is supported.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIEEE1588" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIEEE1588;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether the selected network interface supports DHCP IP addressing - Applies to: GigE

        This is a read only element. It indicates whether the selected network interface supports DHCP IP addressing.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIPConfigurationDHCP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIPConfigurationDHCP;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether the selected network interface supports auto IP addressing (also known as LLA) - Applies to: GigE

        This is a read only element. It indicates whether the selected network interface supports auto IP addressing (also known as LLA).
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIPConfigurationLLA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIPConfigurationLLA;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether the selected network interface supports fixed IP addressing (also known as persistent IP addressing) - Applies to: GigE

        This is a read only element. It indicates whether the selected network interface supports fixed IP addressing (also known as persistent IP addressing).
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedIPConfigurationPersistentIP" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedIPConfigurationPersistentIP;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether multiple operations in a single message are supported - Applies to: GigE

        This is a read only element. It indicates whether multiple operations in a single message are supported.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsConcatenation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsConcatenation;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether EVENT_CMD and EVENT_ACK are supported - Applies to: GigE

        This is a read only element. It indicates whether EVENT_CMD and EVENT_ACK are supported.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsEVENT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsEVENT;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether EVENTDATA_CMD and EVENTDATA_ACK are supported - Applies to: GigE

        This is a read only element. It indicates whether EVENTDATA_CMD and EVENTDATA_ACK are supported.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsEVENTDATA" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsEVENTDATA;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether PACKETRESEND_CMD is supported - Applies to: GigE

        This is a read only element. It indicates whether PACKETRESEND_CMD is supported.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsPACKETRESEND" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsPACKETRESEND;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether WRITEMEM_CMD and WRITEMEM_ACK are supported - Applies to: GigE

        This is a read only element. It indicates whether WRITEMEM_CMD and WRITEMEM_ACK are supported
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalCommandsWRITEMEM" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalCommandsWRITEMEM;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates whether this GVSP transmitter or receiver can support 16-bit block_id - Applies to: GigE

        This is a read only element. It indicates whether this GVSP transmitter or rceiver can support 16-bit block_id.
    
        \b Visibility = Guru

        \b Selected by : GevInterfaceSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevSupportedOptionalLegacy16BitBlockID" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GevSupportedOptionalLegacy16BitBlockID;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Latches the current timestamp value of the device - Applies to: GigE

        This command latches the current timestamp value of the device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampControlLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevTimestampControlLatch;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Resets the timestamp control latch - Applies to: GigE

        This command resets the timestamp control latch.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampControlLatchReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevTimestampControlLatchReset;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Resets the timestamp value for the device - Applies to: GigE

        This command resets the timestamp value for the device
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampControlReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& GevTimestampControlReset;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the number of timestamp clock ticks in 1 second - Applies to: GigE

        This is a read only element. It indicates the number of timestamp clock ticks in 1 second.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampTickFrequency" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevTimestampTickFrequency;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the latched value of the timestamp   (The timestamp must first be latched using the Timestamp Control Latch command ) - Applies to: GigE

        This is a read only element. It indicates the latched value of the timestamp.  (The timestamp must first be latched using the Timestamp Control Latch command.)
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevTimestampValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevTimestampValue;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the major version number of the GigE Vision specification supported by this device - Applies to: GigE

        This is a read only element. It indicates the major version number of the GigE Vision specification supported by this device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevVersionMajor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevVersionMajor;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the minor version number of the GigE Vision specification supported by this device - Applies to: GigE

        This is a read only element. It indicates the minor version number of the GigE Vision specification supported by this device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GevVersionMinor" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GevVersionMinor;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Enable the Global Reset Release Mode - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GlobalResetReleaseModeEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& GlobalResetReleaseModeEnable;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Gray value adjustment damping for Gain Auto and Exposure Auto - Applies to: GigE, 1394 and CameraLink Camera

        The gray value adjustment damping parameter controls the rate by which pixel gray values are changed when Exposure Auto and/or Gain Auto are enabled.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GrayValueAdjustmentDampingAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& GrayValueAdjustmentDampingAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Gray value adjustment damping for Gain Auto and Exposure Auto - Applies to: GigE, 1394 and CameraLink Camera

        The gray value adjustment damping parameter controls the rate by which pixel gray values are changed when Exposure Auto and/or Gain Auto are enabled.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=GrayValueAdjustmentDampingRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& GrayValueAdjustmentDampingRaw;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Height of the camera's region of interest in pixels - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Height of the camera's region of interest in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Height" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Height;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Maximum allowed height of the region of interest in pixels - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Maximum allowed height of the region of interest in pixels. value takes into account any function that may limit the maximum height.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=HeightMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& HeightMax;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables loading files from disk for image acquisition - Applies to: CamEmu

    
        \b Visibility = Beginner

    */
    Pylon::IEnumParameterT<ImageFileModeEnums>& ImageFileMode;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enter the name of an image filename or a path to a directory containing image files - Applies to: CamEmu

        Enter the name of an image filename in a format supported by pylon or the path to a directory containing image files.
    
        \b Visibility = Beginner

    */
    Pylon::IStringEx& ImageFilename;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Selects the Interlaced Integration Mode - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=InterlacedIntegrationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<InterlacedIntegrationModeEnums>& InterlacedIntegrationMode;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_EPU" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_EPU;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_ERC" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_ERC;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_ERT" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_ERT;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_LKE" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_LKE;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_LKR" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_LKR;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_PHE" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_PHE;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_SQE" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_SQE;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: dart USB and pulse

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Internal_URE" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Internal_URE;
    
    //@}


    //! \name Categories LUT Control and LUT Controls 
    //@{
    /*!
        \brief Enables the selected lookup table (LUT) - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        \b Selected by : LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LUTEnable;
    
    //@}


    //! \name Categories LUT Control and LUT Controls 
    //@{
    /*!
        \brief Index of the LUT element to access - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTIndex;
    
    //@}


    //! \name Categories LUT Control and LUT Controls 
    //@{
    /*!
        \brief Sets the lookup table (LUT) to be configured - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        Sets the lookup table (LUT) to be configured. Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LUTSelectorEnums>& LUTSelector;
    
    //@}


    //! \name Categories LUT Control and LUT Controls 
    //@{
    /*!
        \brief Value of the LUT element at the LUT index position - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : LUTSelector, LUTIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LUTValue;
    
    //@}


    //! \name Categories LUT Control and LUT Controls 
    //@{
    /*!
        \brief A single register that lets you access all LUT coefficients - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        A single register that lets you access all LUT coefficients without the need to repeatedly use the LUTIndex parameter.
    
        \b Visibility = Guru

        \b Selected by : LUTSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LUTValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IRegisterEx& LUTValueAll;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Indicates the error that was detected last - Applies to: GigE and CameraLink Camera

        Indicates the error that was detected last.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LastError" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LastErrorEnums>& LastError;
    
    //@}


    //! \name Category Late Action Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for a critical temperature event - Applies to: GigE

        This enumeration Indicates the stream channel index for a critical temperature event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LateActionEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LateActionEventStreamChannelIndex;
    
    //@}


    //! \name Category Late Action Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a critical temperature event - Applies to: GigE

        This enumeration value indicates the time stamp for a critical temperature event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LateActionEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LateActionEventTimestamp;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the vertical binning feature - Applies to: GigE, 1394 and CameraLink Camera

        This enumeration sets the vertical binning feature.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LegacyBinningVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LegacyBinningVerticalEnums>& LegacyBinningVertical;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Sets the light source preset - Applies to: ace USB, dart USB, pulse and dart BCON

        Sets the light source preset. The colors in the image will be corrected so that they are appropriate for the selected light source.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LightSourcePreset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LightSourcePresetEnums>& LightSourcePreset;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Selects the type of light source to be considered for matrix color transformation - Applies to: GigE, 1394 and CameraLink Camera

        Selects the color transformation mode to select the type of light source to be considered for matrix color transformation.
    
        \b Visibility = Expert

        \b Selected by : ColorTransformationSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LightSourceSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LightSourceSelectorEnums>& LightSourceSelector;
    
    //@}


    //! \name Category Line 1 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io line 1 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io line 1 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line1RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line1RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Line 1 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a line 1 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io line 1 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line1RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line1RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Line 2 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io line 2 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io line 2 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line2RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line2RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Line 2 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a line 2 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io line 2 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line2RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line2RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Line 3 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io line 3 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io line 3 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line3RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line3RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Line 3 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a line 3 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io line 3 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line3RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line3RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Line 4 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io line 4 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io line 4 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line4RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line4RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Line 4 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a line 4 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io line 4 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Line4RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Line4RisingEdgeEventTimestamp;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Value of the selected line debouncer time in microseconds - Applies to: ace USB, dart USB and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineDebouncerTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineDebouncerTime;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the absolute value of the selected line debouncer time in microseconds - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineDebouncerTimeAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineDebouncerTimeAbs;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the raw value of the selected line debouncer time - Applies to: dart USB, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Invisible

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineDebouncerTimeRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineDebouncerTimeRaw;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Returns the electrical configuration of the currently selected line - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineFormatEnums>& LineFormat;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Enables the signal inverter function for the currently selected input or output line - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineInverter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineInverter;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Returns the line logic of the currently selected line - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineLogic" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineLogicEnums>& LineLogic;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Value for the minimum signal width of an output signal (in microseconds)  - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMinimumOutputPulseWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& LineMinimumOutputPulseWidth;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the mode for the selected line - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

        Sets the mode for the selected line. This controls whether the physical line is used to input or output a signal.
    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineModeEnums>& LineMode;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Resets the overload status of the selected line - Applies to: ace USB

        This command resets the overload status of the selected line. If the overload condition is still fulfilled, the overload status will be set again immediately.
    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineOverloadReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& LineOverloadReset;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Indicates whether an overload condition was detected on the selected line - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineOverloadStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineOverloadStatus;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Number of bytes separating the starting pixels of two consecutive lines - Applies to: ace USB

        Number of bytes separating the starting pixels of two consecutive lines. This feature is used to facilitate alignment of image data.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LinePitch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LinePitch;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables the line pitch feature - Applies to: ace USB

        Enables the line pitch feature which aligns output image data to multiples of 4 bytes.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LinePitchEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LinePitchEnable;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the I/O line to be configured - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

        Sets the I/O line to be configured. Once a line has been set, all changes to the line settings will be applied to the selected line.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSelectorEnums>& LineSelector;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the source signal for the currently selected line - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

        Sets the source signal for the currently selected line. The currently selected line must be an output line.
    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<LineSourceEnums>& LineSource;
    
    //@}


    //! \name Category Line Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an line start overtrigger event - Applies to: GigE and 1394

        This enumeration Indicates the stream channel index for an line start overtrigger event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStartOvertriggerEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStartOvertriggerEventStreamChannelIndex;
    
    //@}


    //! \name Category Line Start Overtrigger Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an line start overtrigger event - Applies to: GigE and 1394

        This enumeration value indicates the time stamp for an line start overtrigger event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStartOvertriggerEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStartOvertriggerEventTimestamp;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Indicates the current logical state of the selected line - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineStatus;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief A single bit field indicating the current logical state of all available line signals at time of polling - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

        This integer value is a single bit field that indicates the current logical state of all available lines at time of polling.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineStatusAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& LineStatusAll;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Enables the termination resistor for the selected input line - Applies to: GigE, 1394 and CameraLink Camera

        This boolean value enables the termination resistor for the selected input line.
    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=LineTermination" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& LineTermination;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the absolute value (in microseconds) for the minimum signal width of an output signal - Applies to: GigE and CameraLink Camera

        This float value sets the absolute value (in microseconds) for the minimum signal width of a signal that is received from the frequency converter or from the shaft encoder module and that is associated with a digital output line.
    
        \b Visibility = Beginner

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MinOutPulseWidthAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& MinOutPulseWidthAbs;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the raw value for the minimum signal width of an output signal - Applies to: GigE and CameraLink Camera

        This integer value sets the raw value  for the minimum signal width of a signal that is received from the frequency converter or from the shaft encoder module and that is associated with a digital output line.
    
        \b Visibility = Invisible

        \b Selected by : LineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=MinOutPulseWidthRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& MinOutPulseWidthRaw;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of noise reduction to apply - Applies to: ace USB

        Amount of noise reduction to apply. The higher the value, the less chroma noise will be visible in your images. However, too high values may result in image information loss. To enable this feature, the DemosaicingMode parameter must be set to BaslerPGI.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NoiseReduction" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& NoiseReduction;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of noise reduction to apply - Applies to: GigE

        Amount of noise reduction to apply. The higher the value, the less chroma noise will be visible in your images. However, too high values may result in image information loss. To enable this feature, the DemosaicingMode parameter must be set to BaslerPGI.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NoiseReductionAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& NoiseReductionAbs;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of noise reduction to apply - Applies to: GigE

        Amount of noise reduction to apply. The higher the value, the less chroma noise will be visible in your images. However, too high values may result in image information loss. To enable this feature, the DemosaicingMode parameter must be set to BaslerPGI.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NoiseReductionRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& NoiseReductionRaw;
    
    //@}


    //! \name Category Action Control
    //@{
    /*!
        \brief Number of separate action signals supported by the device - Applies to: GigE

        Number of separate action signals supported by the device. Determines how many action signals the device can handle in parallel, i.e. how many different action commands can be set up for the device.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=NumberOfActionSignals" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& NumberOfActionSignals;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Horizontal offset from the left side of the sensor to the region of interest (in pixels) - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetX;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Vertical offset from the top of the sensor to the region of interest (in pixels) - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OffsetY;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Shows the over temperature state of the selected target - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverTemperature" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& OverTemperature;
    
    //@}


    //! \name Category Over Temperature Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an over temperature event - Applies to: GigE

        This enumeration Indicates the stream channel index for an over temperature event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverTemperatureEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OverTemperatureEventStreamChannelIndex;
    
    //@}


    //! \name Category Over Temperature Event Data
    //@{
    /*!
        \brief Indicates the time stamp for an over temperature event - Applies to: GigE

        This enumeration value indicates the time stamp for an over temperature event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverTemperatureEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& OverTemperatureEventTimestamp;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Configures overlapping exposure and image readout - Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=OverlapMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<OverlapModeEnums>& OverlapMode;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Sets the packet size in bytes - Applies to: 1394

         This value sets the packet size in bytes.
    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& PacketSize;
    
    //@}


    //! \name Category Remove Parameter Limits
    //@{
    /*!
        \brief Selects the parameter to configure  Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter - Applies to: GigE, 1394 and CameraLink Camera

        This enumeration selects the parameter to configure. Selects the parameter to configure. Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ParameterSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ParameterSelectorEnums>& ParameterSelector;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Payload Final Transfer 1 Size - Applies to: dart USB and pulse

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadFinalTransfer1Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadFinalTransfer1Size;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Payload Final Transfer 2 Size - Applies to: dart USB and pulse

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadFinalTransfer2Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadFinalTransfer2Size;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Size of the payload in bytes - Applies to: ace USB, dart USB, pulse, GigE, 1394 and CamEmu

        Size of the payload in bytes. This is the total number of bytes sent in the payload.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadSize;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Applies to: ace USB

        This parameter takes effect only when the sequencer mode is set to On. The parameter can only be set when the sequencer configuration mode is set to On.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadTransferBlockDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadTransferBlockDelay;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Payload Transfer Count - Applies to: dart USB and pulse

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadTransferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadTransferCount;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Payload Transfer Size - Applies to: dart USB and pulse

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PayloadTransferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PayloadTransferSize;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Enables Basler PGI image optimizations - Applies to: GigE

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PgiMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PgiModeEnums>& PgiMode;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the color coding of the pixels in the acquired images - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelCoding" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelCodingEnums>& PixelCoding;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Returns the alignment of the camera's Bayer filter to the pixels in the acquired images - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelColorFilter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelColorFilterEnums>& PixelColorFilter;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Maximum possible pixel value that could be transferred from the camera - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMax;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Minimum possible pixel value that could be transferred from the camera - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelDynamicRangeMin" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& PixelDynamicRangeMin;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the format of the pixel data transmitted by the camera - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Sets the format of the pixel data transmitted by the camera. The available pixel formats depend on the camera model and whether the camera is monochrome or color.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelFormat" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelFormatEnums>& PixelFormat;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Select legacy pixel format encoding - Applies to: GigE

        This switch selects a legacy GVSP pixel format encoding, for compatibility with older camera models.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelFormatLegacy" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& PixelFormatLegacy;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Returns the depth of the pixel values in the image (in bits per pixel) - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and CamEmu

        Returns the depth of the pixel values in the image (in bits per pixel). The value will always be coherent with the pixel format setting.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=PixelSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<PixelSizeEnums>& PixelSize;
    
    //@}


    //! \name Category Remove Parameter Limits
    //@{
    /*!
        \brief Sets the number of prelines - Applies to: GigE and CameraLink Camera

        This value sets the number of prelines.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Prelines" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Prelines;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables color improved RGB raw output - Applies to: GigE, 1394 and CameraLink Camera

        Enables color improvement of RGB data and provides for their output as RGB raw data. Only available for cameras with an RGB Bayer filter.
Note: Make sure to also select a suitable raw pixel data output format.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ProcessedRawEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ProcessedRawEnable;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Provides for enabling/disabling a ROI zone - Applies to: GigE

        Provides for enabling/disabling the previously set ROI zone.
    
        \b Visibility = Expert

        \b Selected by : ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ROIZoneModeEnums>& ROIZoneMode;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets a ROI zone offset - Applies to: GigE

        Sets the ROI zone offset (pixels, in direction of assembly) for the previously enabled ROI zone. Equivalent to OffsetY for vertical zones.
    
        \b Visibility = Expert

        \b Selected by : ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneOffset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ROIZoneOffset;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets a ROI zone - Applies to: GigE

        Sets a ROI zone to be enabled, configured, and assembled with other ROI zones.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ROIZoneSelectorEnums>& ROIZoneSelector;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets a ROI zone size - Applies to: GigE

        Sets the ROI zone 'thickness' (pixels, in direction of assembly) for the previously enabled ROI zone. Equivalent to Height for vertical zones.
    
        \b Visibility = Expert

        \b Selected by : ROIZoneSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ROIZoneSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ROIZoneSize;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Indicates the sensor readout time given the current settings - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReadoutTimeAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ReadoutTimeAbs;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Indicates the recommended packet size in bytes  If a smaller packet size is used, the camera's maximum allowed frame rate will be reduced - Applies to: 1394

        This value indicates the recommended packet size in bytes. If a smaller packet size is used, the camera's maximum allowed frame rate will be reduced.
    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& RecommendedPacketSize;
    
    //@}


    //! \name Category Remove Parameter Limits
    //@{
    /*!
        \brief Removes the factory-set limits of the selected parameter - Applies to: GigE, 1394 and CameraLink Camera

        Removes the factory-set limits of the selected parameter. Having removed the factory-set limits you may set the parameter within extended limits. These are only defined by technical restrictions. Note:  Inferior image quality may result.
    
        \b Visibility = Guru

        \b Selected by : ParameterSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveLimits" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& RemoveLimits;
    
    //@}


    //! \name Category Remove Parameter Limit Control
    //@{
    /*!
        \brief Removes the factory limit of the selected parameter - Applies to: ace USB

        Removes the factory limit of the selected parameter. When the factory limit is removed, the parameter can be set within extended limits. range of the extended limit is only dictated by the physical restrictions of the camera, such as the absolute limits of the camera's variable gain control.
    
        \b Visibility = Guru

        \b Selected by : RemoveParameterLimitSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveParameterLimit" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& RemoveParameterLimit;
    
    //@}


    //! \name Category Remove Parameter Limit Control
    //@{
    /*!
        \brief Sets the parameter whose factory limits should be removed - Applies to: ace USB

        Sets the parameter whose factory limits should be removed. Once a parameter has been set, the factory limits can be removed using RemoveLimits.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=RemoveParameterLimitSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<RemoveParameterLimitSelectorEnums>& RemoveParameterLimitSelector;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFramePeriod" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ResultingFramePeriod;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Indicates the minimum allowed frame acquisition period (in microseconds) given the current settings for the area of interest, exposure time, and bandwidth - Applies to: GigE and CameraLink Camera

        Indicates the 'absolute' value of the minimum allowed acquisition frame period. The 'absolute' value is a float value that indicates the minimum allowed acquisition frame period in microseconds given the current settings for the area of interest, exposure time, and bandwidth.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFramePeriodAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFramePeriodAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Maximum allowed frame acquisition rate - Applies to: ace USB, dart USB, pulse and dart BCON

        Maximum allowed frame acquisition rate given the current camera settings (in frames per second).
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFrameRate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFrameRate;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Indicates the maximum allowed frame acquisition rate (in frames per second) given the current settings for the area of interest, exposure time, and bandwidth - Applies to: GigE, 1394, CameraLink Camera and CamEmu

        Indicates the 'absolute' value of the maximum allowed acquisition frame rate. The 'absolute' value is a float value that indicates the maximum allowed acquisition frame rate in frames per second given the current settings for the area of interest, exposure time, and bandwidth.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingFrameRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingFrameRateAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Indicates the minimum allowed line acquisition period (in microseconds) given the current settings for the area of interest, exposure time, and bandwidth - Applies to: GigE and CameraLink Camera

        Indicates the 'absolute' value of the minimum allowed acquisition line period. The 'absolute' value is a float value that indicates the minimum allowed acquisition line period in microseconds given the current settings for the area of interest, exposure time, and bandwidth.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingLinePeriodAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingLinePeriodAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Indicates the maximum allowed line acquisition rate (in lines per second) given the current settings for the area of interest, exposure time, and bandwidth - Applies to: GigE and CameraLink Camera

        Indicates the 'absolute' value of the maximum allowed acquisition line rate. The 'absolute' value is a float value that indicates the maximum allowed acquisition line rate in lines per second given the current settings for the area of interest, exposure time, and bandwidth.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ResultingLineRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ResultingLineRateAbs;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables horizontal mirroring of the image - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Enables horizontal mirroring of the image. The pixel values for each line in a captured image will be swapped end-for-end about the line's center. You can use the ROI feature when using the reverse X feature. Note that the position of the ROI relative to the sensor remains the same.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseX" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseX;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Enables vertical mirroring of the image - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Enables vertical mirroring of the image. The pixel values for each row in a captured image will be swapped end-for-end about the row's center. You can use the ROI feature when using the reverse Y feature. Note that the position of the ROI relative to the sensor remains the same.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ReverseY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ReverseY;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Size of the first final payload transfer - Applies to: ace USB

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadFinalTransfer1Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadFinalTransfer1Size;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Size of the second final payload transfer - Applies to: ace USB

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadFinalTransfer2Size" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadFinalTransfer2Size;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Expected number of payload transfers - Applies to: ace USB

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadTransferCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadTransferCount;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Expected size of a single payload transfer - Applies to: ace USB

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SIPayloadTransferSize" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SIPayloadTransferSize;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Horizontal scaling factor - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingHorizontal" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingHorizontal;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets vertical scaling factor - Applies to: GigE

        This is a float value that sets the vertical scaling factor of the image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingHorizontalAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingHorizontalAbs;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Vertical scaling factor - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingVertical" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingVertical;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets vertical scaling factor - Applies to: GigE

        This is a float value that sets the vertical scaling factor of the image.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ScalingVerticalAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& ScalingVerticalAbs;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief This feature selects the amount of data bits the sensor produces for one sample - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorBitDepth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorBitDepthEnums>& SensorBitDepth;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief This feature represents the number of digitized samples outputted simultaneously by the camera A/D conversion stage - Applies to: GigE and CameraLink Camera

        This feature represents the number of digitized samples output simultaneously by the camera A/D conversion stage.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorDigitizationTaps" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorDigitizationTapsEnums>& SensorDigitizationTaps;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Height of the camera's sensor in pixels - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorHeight;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the sensor readout mode - Applies to: ace USB and GigE

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorReadoutModeEnums>& SensorReadoutMode;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sensor readout time given the current settings - Applies to: ace USB

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorReadoutTime" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SensorReadoutTime;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the shutter mode of the device - Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorShutterMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SensorShutterModeEnums>& SensorShutterMode;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Width of the camera's sensor in pixels - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SensorWidth" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SensorWidth;
    
    //@}


    //! \name Category Sequence Control Configuration
    //@{
    /*!
        \brief Selects a bit of the sequence set address - Applies to: GigE and CameraLink Camera

        Selects a bit of the sequence set address.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAddressBitSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceAddressBitSelectorEnums>& SequenceAddressBitSelector;
    
    //@}


    //! \name Category Sequence Control Configuration
    //@{
    /*!
        \brief Selects the source for the selected bit of the sequence set address - Applies to: GigE and CameraLink Camera

        Selects the source for setting the selected bit of the sequence set address.
    
        \b Visibility = Guru

        \b Selected by : SequenceAddressBitSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAddressBitSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceAddressBitSourceEnums>& SequenceAddressBitSource;
    
    //@}


    //! \name Category Sequence Control Configuration
    //@{
    /*!
        \brief Selects the sequence set advance mode - Applies to: GigE and CameraLink Camera

        Selects the sequence set advance mode. Possible values: Auto - automatic sequence set advance as images are acquired. Controlled - sequence set advance controlled by settable source. Free selection - the sequence sets are selected according to the states of the input lines.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAdvanceMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceAdvanceModeEnums>& SequenceAdvanceMode;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Allows asynchronous advance from one sequence set to the next - Applies to: GigE and CameraLink Camera

        Allows to advance from the current sequence set to the next one. The advance is asynchronous to the cameras's frame trigger. Only available in Controlled sequence advance mode.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAsyncAdvance" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceAsyncAdvance;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Allows asynchronous restart of the sequence of sequence sets  - Applies to: GigE and CameraLink Camera

        Allows to restart the sequence of sequence sets to image acquisition, starting with the sequence set of lowest index number. The restart is asynchronous to the cameras's frame trigger. Only available in Auto and Controlled sequence advance mode.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceAsyncRestart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceAsyncRestart;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Enables or disables the sequencer for configuration - Applies to: GigE

        Enables or disables the sequencer for configuration.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceConfigurationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceConfigurationModeEnums>& SequenceConfigurationMode;
    
    //@}


    //! \name Category Sequence Control Configuration
    //@{
    /*!
        \brief Selects between sequence restart or sequence set advance - Applies to: GigE and CameraLink Camera

        Selects between controls for sequence restart or sequence set advance.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceControlSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceControlSelectorEnums>& SequenceControlSelector;
    
    //@}


    //! \name Category Sequence Control Configuration
    //@{
    /*!
        \brief Selects the source for sequence control - Applies to: GigE and CameraLink Camera

        Selects the source for sequence control. Possible values: Disabled - advance via asynchronous advance. Always Active - automatic sequence set advance. The sequence repeat starts with sequence set index number 1. Line N - the source for sequence restart or sequence set advance is line N. CCN - the source for sequence restart or sequence set advance is CCN.
    
        \b Visibility = Guru

        \b Selected by : SequenceControlSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceControlSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequenceControlSourceEnums>& SequenceControlSource;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Current sequence set - Applies to: GigE and CameraLink Camera

        Indicates the current sequence set.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceCurrentSet" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceCurrentSet;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Enables the sequencer - Applies to: GigE and CameraLink Camera

        Enables the existing sequence sets for image acquisition.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SequenceEnable;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Sets the number of sequence set executions - Applies to: GigE and CameraLink Camera

        Sets the number of consecutive executions per sequence cycle for the selected sequence set. Only available in Auto sequence advance mode.
    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetExecutions" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceSetExecutions;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Selects the index number of a sequence set - Applies to: GigE and CameraLink Camera

        Selects the index number of a sequence set.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceSetIndex;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Loads a sequence set - Applies to: GigE and CameraLink Camera

        Loads an existing sequence set to make it the current sequence set.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceSetLoad;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Stores the current sequence set - Applies to: GigE and CameraLink Camera

        Stores the current sequence set as one of the sequence sets of the sequence. Note: Storing the current sequence set will overwrite any already existing sequence set bearing the same index number. Note: The sequence set is stored in the volatile memory and will therefore be lost if the camera is reset or if power is switched off.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetStore" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequenceSetStore;
    
    //@}


    //! \name Category Sequence Control
    //@{
    /*!
        \brief Total number of sequence sets - Applies to: GigE and CameraLink Camera

        Sets the total number of sequence sets in the sequence.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequenceSetTotalNumber" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequenceSetTotalNumber;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sets whether the sequencer can be configured - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerConfigurationMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerConfigurationModeEnums>& SequencerConfigurationMode;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sets whether the sequencer can be used for image acquisition - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerModeEnums>& SequencerMode;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sets the sequencer path - Applies to: ace USB

    
        \b Visibility = Expert

        \b Selected by : SequencerSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerPathSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerPathSelector;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Index number of the currently active sequencer set - Applies to: ace USB

        Index number of the current sequencer set, i.e. of the sequencer set whose parameter values are currently present in the active set.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetActive" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetActive;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Loads the parameter values of a sequencer set into the active set - Applies to: ace USB

        Loads the parameter values of a sequencer set into the active set. The sequencer set will then be the current set.
    
        \b Visibility = Expert

        \b Selected by : SequencerSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequencerSetLoad;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Next sequencer set to follow after the current one - Applies to: ace USB

    
        \b Visibility = Expert

        \b Selected by : SequencerSetSelector, SequencerPathSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetNext" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetNext;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Saves the sequencer parameter values that are currently in the active set - Applies to: ace USB

        Saves the sequencer parameter values that are currently in the active set. The values will be saved for the sequencer set whose sequencer set index number is currently selected.
    
        \b Visibility = Expert

        \b Selected by : SequencerSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetSave" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SequencerSetSave;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sets a sequencer set by its index number - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetSelector;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sequencer set that will be used with the first frame start trigger after SequencerMode was set to On - Applies to: ace USB

        Sequencer set that will be used with the first frame start trigger after SequencerMode was set to On. Only sequencer set 0 is available.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerSetStart" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SequencerSetStart;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sets the effective logical level for sequencer set advance - Applies to: ace USB

        Sets the effective logical level for sequencer set advance. Currently, only LevelHigh is available.
    
        \b Visibility = Expert

        \b Selected by : SequencerSetSelector, SequencerPathSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerTriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerTriggerActivationEnums>& SequencerTriggerActivation;
    
    //@}


    //! \name Category Sequencer Control
    //@{
    /*!
        \brief Sets the trigger source for sequencer set advance - Applies to: ace USB

        Sets the trigger source for sequencer set advance with the currently selected path.
    
        \b Visibility = Expert

        \b Selected by : SequencerSetSelector, SequencerPathSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SequencerTriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SequencerTriggerSourceEnums>& SequencerTriggerSource;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Enables the selected kind of shading correction - Applies to: GigE and CameraLink Camera

        This boolean value enables the selected kind of shading correction.
    
        \b Visibility = Beginner

        \b Selected by : ShadingSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& ShadingEnable;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Selects the kind of shading correction - Applies to: GigE and CameraLink Camera

        This enumeration selects the kind of shading correction.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShadingSelectorEnums>& ShadingSelector;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Activates the selected shading set - Applies to: GigE and CameraLink Camera

        This command copies the selected shading set from the camera's non-volatile memory into the volatile memory. Shading correction is performed using the shading set in the volatile memory.
    
        \b Visibility = Expert

        \b Selected by : ShadingSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingSetActivate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ShadingSetActivate;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Creates a shading set - Applies to: GigE and CameraLink Camera

        ShadingSetCreate
    
        \b Visibility = Expert

        \b Selected by : ShadingSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingSetCreate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShadingSetCreateEnums>& ShadingSetCreate;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Selects the bootup shading set - Applies to: GigE and CameraLink Camera

        This enumeration selects the shading set that will be loaded into the volatile memory during camera bootup.
    
        \b Visibility = Expert

        \b Selected by : ShadingSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingSetDefaultSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShadingSetDefaultSelectorEnums>& ShadingSetDefaultSelector;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Selects the shading set to which the activate command will be applied - Applies to: GigE and CameraLink Camera

        This enumeration selects the shading set to which the activate command will be applied.
    
        \b Visibility = Expert

        \b Selected by : ShadingSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShadingSetSelectorEnums>& ShadingSetSelector;
    
    //@}


    //! \name Category Shading
    //@{
    /*!
        \brief Indicates error statuses related to shading correction - Applies to: GigE and CameraLink Camera

        This enumeratuion indicates error statuses related to shading correction.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShadingStatus" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShadingStatusEnums>& ShadingStatus;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Indicates the current value of the tick counter - Applies to: GigE and CameraLink Camera

        This integer value (read only) indicates the current value of the tick counter of the shaft encoder module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleCounter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ShaftEncoderModuleCounter;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Sets the maximum value for the tick counter - Applies to: GigE and CameraLink Camera

        This integer value sets the maximum value for the tick counter of the shaft encoder module (range: 0 to 32767). If the tick counter is incrementing and it reaches the set maximum, it willl roll over to 0. If the tick counter is decrementing and it reaches 0, it willl roll back to the set maximum.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleCounterMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ShaftEncoderModuleCounterMax;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Selects the counting mode of the tick counter - Applies to: GigE and CameraLink Camera

        Selects the counting mode of the tick counter of the shaft encoder module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleCounterMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShaftEncoderModuleCounterModeEnums>& ShaftEncoderModuleCounterMode;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Resets the tick counter to 0 - Applies to: GigE and CameraLink Camera

        This command resets the tick counter count of the shaft encoder module to 0.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleCounterReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ShaftEncoderModuleCounterReset;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Selects the phase of the shaft encoder - Applies to: GigE and CameraLink Camera

        Selects the phase of the shaft encoder as input for the shaft encoder module.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleLineSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShaftEncoderModuleLineSelectorEnums>& ShaftEncoderModuleLineSelector;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Selects the input line as signal source for the shaft encoder module - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Expert

        \b Selected by : ShaftEncoderModuleLineSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleLineSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShaftEncoderModuleLineSourceEnums>& ShaftEncoderModuleLineSource;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Selects the circumstances for the shaft encoder module to output trigger signals - Applies to: GigE and CameraLink Camera

        This enumeration value selects the circumstances for the shaft encoder module to output trigger signals.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShaftEncoderModuleModeEnums>& ShaftEncoderModuleMode;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Sets the maximum value for the reverse counter - Applies to: GigE and CameraLink Camera

        This integer value sets the maximum value for the reverse counter of the shaft encoder module (range: 0 to 32767).
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleReverseCounterMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& ShaftEncoderModuleReverseCounterMax;
    
    //@}


    //! \name Category Shaft Encoder Module
    //@{
    /*!
        \brief Resets the reverse counter to 0 - Applies to: GigE and CameraLink Camera

        This command resets the reverse counter of the shaft encoder module to 0 and informs the module that the current direction of conveyor movement is forward. Reset must be carried out before the first conveyor movement in the forward direction.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShaftEncoderModuleReverseCounterReset" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& ShaftEncoderModuleReverseCounterReset;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of sharpening to apply - Applies to: ace USB, dart USB, pulse and dart BCON

        Amount of sharpening to apply. The higher the sharpness, the more distinct the image subject's contours will be. However, too high values may result in image information loss. To enable this feature, the DemosaicingMode parameter must be set to BaslerPGI.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SharpnessEnhancement" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SharpnessEnhancement;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of sharpening to apply - Applies to: GigE

        Amount of sharpening to apply. The higher the sharpness, the more distinct the image subject's contours will be. However, too high values may result in image information loss. To enable this feature, the DemosaicingMode parameter must be set to BaslerPGI.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SharpnessEnhancementAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SharpnessEnhancementAbs;
    
    //@}


    //! \name Categories Image Quality Control and PGI Control (non-Bayer only)
    //@{
    /*!
        \brief Amount of sharpening to apply - Applies to: dart USB, pulse, GigE and dart BCON

        Amount of sharpening to apply. The higher the sharpness, the more distinct the image subject's contours will be. However, too high values may result in image information loss. To enable this feature, the DemosaicingMode parameter must be set to BaslerPGI.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SharpnessEnhancementRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SharpnessEnhancementRaw;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the shutter mode - Applies to: ace USB, GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=ShutterMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<ShutterModeEnums>& ShutterMode;
    
    //@}


    //! \name Category Software Signal Control
    //@{
    /*!
        \brief Generates a signal that can be used as a software trigger - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : SoftwareSignalSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SoftwareSignalPulse" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SoftwareSignalPulse;
    
    //@}


    //! \name Category Software Signal Control
    //@{
    /*!
        \brief Sets the software signal to control - Applies to: ace USB

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SoftwareSignalSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SoftwareSignalSelectorEnums>& SoftwareSignalSelector;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Specifies the direction of imaging and the separation (consecutive numbers) of related line captures - Applies to: GigE and CameraLink Camera

        Specifies the direction of imaging and the separation (consecutive numbers) of related line captures. Related line captures will be combined.

Positive integer: The object will pass the top sensor line first.

Negative integer: The object will pass the bottom sensor line first.

In color cameras, the top sensor line is the green line, and the bottom sensor line is the blue line.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SpatialCorrection" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SpatialCorrection;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Applies to: GigE and CameraLink Camera

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SpatialCorrectionAmount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SpatialCorrectionAmount;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Applies to: GigE and CameraLink Camera

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SpatialCorrectionStartingLine" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SpatialCorrectionStartingLineEnums>& SpatialCorrectionStartingLine;
    
    //@}


    //! \name Category Stacked Zone Imaging
    //@{
    /*!
        \brief Enables the stacked zone imaging feature - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StackedZoneImagingEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& StackedZoneImagingEnable;
    
    //@}


    //! \name Category Stacked Zone Imaging
    //@{
    /*!
        \brief This value sets the zone to access - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StackedZoneImagingIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StackedZoneImagingIndex;
    
    //@}


    //! \name Category Stacked Zone Imaging
    //@{
    /*!
        \brief Enables the selected zone - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : StackedZoneImagingIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StackedZoneImagingZoneEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& StackedZoneImagingZoneEnable;
    
    //@}


    //! \name Category Stacked Zone Imaging
    //@{
    /*!
        \brief Sets the height for the selected zone - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : StackedZoneImagingIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StackedZoneImagingZoneHeight" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StackedZoneImagingZoneHeight;
    
    //@}


    //! \name Category Stacked Zone Imaging
    //@{
    /*!
        \brief Sets the Y offset (top offset) for the selected zone - Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : StackedZoneImagingIndex

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=StackedZoneImagingZoneOffsetY" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& StackedZoneImagingZoneOffsetY;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the substrate voltage - Applies to: GigE, 1394 and CameraLink Camera

        This value sets the substrate voltage
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SubstrateVoltage" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SubstrateVoltage;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Enables the synchronous free run mode - Applies to: GigE

        When enabled the camera triggers with the specified frame rate derived from the synchronized clock.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SyncFreeRunTimerEnable;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Synchronous free run trigger start time (high 32 bits) - Applies to: GigE

        High 32 bits of the synchronous free run trigger start time.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerStartTimeHigh" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncFreeRunTimerStartTimeHigh;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Synchronous free run trigger start time (low 32 bits) - Applies to: GigE

        Low 32 bits of the synchronous free run trigger start time.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerStartTimeLow" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncFreeRunTimerStartTimeLow;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Synchronous free run trigger rate - Applies to: GigE

        Trigger rate for the clock synchronous trigger.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerTriggerRateAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& SyncFreeRunTimerTriggerRateAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Activates the synchronous free run trigger settings - Applies to: GigE

        Activates changed settings for the synchronous free run.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncFreeRunTimerUpdate" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& SyncFreeRunTimerUpdate;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Applies to: GigE and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncUserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<SyncUserOutputSelectorEnums>& SyncUserOutputSelector;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the state of the selected user settable synchronous output signal - Applies to: GigE and CameraLink Camera

        This boolean value sets the state of the selected user settable synchronous output signal.
    
        \b Visibility = Beginner

        \b Selected by : SyncUserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncUserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& SyncUserOutputValue;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief A single bitfield that sets the state of all user settable synchronous output signals in one access - Applies to: GigE and CameraLink Camera

        This integer value is a single bitfield that sets the state of all user settable synchronous output signals in one access.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=SyncUserOutputValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& SyncUserOutputValueAll;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Used by the transport layer to prevent critical features from changing during acquisition - Applies to: dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TLParamsLocked" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TLParamsLocked;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Shows the current temperature of the selected target in degrees centigrade - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        \b Selected by : TemperatureSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TemperatureAbs;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Lists the temperature sources available for readout - Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureSelectorEnums>& TemperatureSelector;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Returns the temperature state - Applies to: ace USB, GigE and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TemperatureState" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TemperatureStateEnums>& TemperatureState;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Holds all moving test images at their starting position - Applies to: ace USB and GigE

        Holds all moving test images at their starting position. All test images will be displayed at their starting positions and will stay fixed.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageResetAndHold" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TestImageResetAndHold;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Sets the test image to display - Applies to: ace USB, GigE, 1394, CameraLink Camera and CamEmu

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestImageSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TestImageSelectorEnums>& TestImageSelector;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Selects the type of image test pattern that is generated by the device - Applies to: dart USB, pulse and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestPattern" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TestPatternEnums>& TestPattern;
    
    //@}


    //! \name Categories Test Control, Transport Layer and Transport Layer Control
    //@{
    /*!
        \brief Test pending acknowledging time in milliseconds - Applies to: ace USB, dart USB, pulse and dart BCON

        Test pending acknowledging time in milliseconds. On write, the device waits for this time period before acknowledging the write. If the time period is longer than the value in the Maximum Device Response Time register, the device must use PENDING_ACK during the completion of this request. On reads, the device returns the current value without any additional wait time.
    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TestPendingAck" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TestPendingAck;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Delay of the currently selected timer in microseconds - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDelay;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Directly sets the delay for the selected timer in microseconds - Applies to: GigE, 1394 and CameraLink Camera

        This float value sets the delay for the selected timer in microseconds.
    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelayAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDelayAbs;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the 'raw' delay for the selected timer   Actual delay = raw timer delay setting  x  timer delay time base abs setting - Applies to: GigE, 1394 and CameraLink Camera

        This value sets an integer that will be used as a multiplier for the timer delay timebase. The actual delay time equals the current timer delay raw setting times the current timer delay time base abs setting.
    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelayRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerDelayRaw;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the time base (in microseconds) that is used when a timer delay is set with the 'timer delay raw' setting - Applies to: GigE, 1394 and CameraLink Camera

        This float value sets the time base (in microseconds) that is used when a timer delay is set with the 'raw' setting.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDelayTimebaseAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDelayTimebaseAbs;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Duration of the currently selected timer in microseconds - Applies to: ace USB

    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDuration" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDuration;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Directly sets the duration for the selected timer in microseconds - Applies to: GigE, 1394 and CameraLink Camera

        This float value sets the duration for the selected timer in microseconds.
    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDurationAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDurationAbs;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the 'raw' duration for the selected timer   Actual duration = raw timer duration setting  x  timer duration time base abs setting - Applies to: GigE, 1394 and CameraLink Camera

        This value sets an integer that will be used as a multiplier for the timer duration timebase. The actual duration time equals the current timer duration raw setting times the current timer duration time base abs setting.
    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDurationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerDurationRaw;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the time base (in microseconds) that is used when a timer duration is set with the 'timer duration raw' setting - Applies to: GigE, 1394 and CameraLink Camera

        This float value sets the time base (in microseconds) that is used when a timer duration is set with the 'raw' setting.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerDurationTimebaseAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TimerDurationTimebaseAbs;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the timer to be configured - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerSelectorEnums>& TimerSelector;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceCurrentEntryIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerSequenceCurrentEntryIndex;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TimerSequenceEnable;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceEntrySelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerSequenceEntrySelectorEnums>& TimerSequenceEntrySelector;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceLastEntryIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerSequenceLastEntryIndex;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : TimerSequenceTimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceTimerDelayRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerSequenceTimerDelayRaw;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : TimerSequenceTimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceTimerDurationRaw" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimerSequenceTimerDurationRaw;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : TimerSequenceTimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceTimerEnable" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TimerSequenceTimerEnable;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : TimerSequenceTimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceTimerInverter" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TimerSequenceTimerInverter;
    
    //@}


    //! \name Category Timer Sequence
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        \b Selected by : TimerSequenceEntrySelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerSequenceTimerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerSequenceTimerSelectorEnums>& TimerSequenceTimerSelector;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the type of signal transistion that will start the timer - Applies to: GigE, 1394 and CameraLink Camera

        This enumeration sets the type of signal transistion that will start the timer.
    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerTriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerTriggerActivationEnums>& TimerTriggerActivation;
    
    //@}


    //! \name Categories Counter and Timer Control and Counter and Timer Controls
    //@{
    /*!
        \brief Sets the internal camera signal used to trigger the selected timer - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : TimerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimerTriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TimerTriggerSourceEnums>& TimerTriggerSource;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Latches the current timestamp counter and stores its value in TimestampLatchValue - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatch" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TimestampLatch;
    
    //@}


    //! \name Categories Device Control and Device Information
    //@{
    /*!
        \brief Latched value of the timestamp counter - Applies to: ace USB

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TimestampLatchValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TimestampLatchValue;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the signal transition that activates the selected trigger - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerActivationEnums>& TriggerActivation;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Applies to: GigE, 1394 and CameraLink Camera

    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerControlImplementation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerControlImplementationEnums>& TriggerControlImplementation;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Trigger delay time in microseconds - Applies to: ace USB

        Trigger delay time in microseconds. The delay is applied after the trigger reception and before effectively activating the trigger.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelay" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TriggerDelay;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the trigger delay time in microseconds - Applies to: GigE, 1394 and CameraLink Camera

        This float value sets the absolute trigger delay in microseconds to apply after the trigger reception before effectively activating it.
    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelayAbs" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IFloatEx& TriggerDelayAbs;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the trigger delay expressed as number of line triggers - Applies to: GigE and CameraLink Camera

        This integer value sets the trigger delay expressed as a number of consecutive line triggers to apply after the trigger reception before effectively activating it.
    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelayLineTriggerCount" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& TriggerDelayLineTriggerCount;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Selects the kind of trigger delay - Applies to: GigE and CameraLink Camera

        Selects wheter trigger delay is defined as a time interval or as a number of consecutive line triggers.
    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerDelaySource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerDelaySourceEnums>& TriggerDelaySource;
    
    //@}


    //! \name Categories Event Control and Events Generation
    //@{
    /*!
        \brief Generates an event test signal - Applies to: ace USB

    
        \b Visibility = Invisible

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerEventTest" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TriggerEventTest;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the mode for the currently selected trigger - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerMode" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerModeEnums>& TriggerMode;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Determines whether a partial or complete frame is transmitted when the frame start trigger prematurely transitions - Applies to: GigE and CameraLink Camera

        This feature determines whether a partial or a complete frame is transmitted when the frame start trigger is used with Level High or Level Low and when the frame start trigger signal transitions while the frame is still being acquired.
    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerPartialClosingFrame" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& TriggerPartialClosingFrame;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the trigger type to be configured - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Sets the trigger type to be configured. Once a trigger type has been set, all changes to the trigger settings will be applied to the selected trigger.
    
        \b Visibility = Expert

        \b Selected by : TriggerControlImplementation

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSelectorEnums>& TriggerSelector;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Generates a software trigger signal - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Generates a software trigger signal. The software trigger signal will be used if the TriggerSource parameter is set to Software.
    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSoftware" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& TriggerSoftware;
    
    //@}


    //! \name Categories Acquisition Control, Acquisition Controls, Analog Control, Analog Controls, Auto Function Control, Auto Function Parameters, Color Improvements Control and Image Quality Control
    //@{
    /*!
        \brief Sets the signal source for the selected trigger - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Expert

        \b Selected by : TriggerSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=TriggerSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<TriggerSourceEnums>& TriggerSource;
    
    //@}


    //! \name Categories User Defined Values and User Defined Values
    //@{
    /*!
        \brief A user defined value - Applies to: ace USB, GigE, 1394 and CameraLink Camera

        A user defined value. value can serve as storage location for the camera user. It has no impact on the operation of the camera.
    
        \b Visibility = Guru

        \b Selected by : UserDefinedValueSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserDefinedValue;
    
    //@}


    //! \name Categories User Defined Values and User Defined Values
    //@{
    /*!
        \brief Sets the user-defined value to set or read - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Guru

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserDefinedValueSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserDefinedValueSelectorEnums>& UserDefinedValueSelector;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Sets the user settable output signal to be configured - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

        Sets the user settable output signal to be configured. Once a user settable output signal has been set, all changes to the user settable output signal settings will be applied to the selected user settable output signal.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserOutputSelectorEnums>& UserOutputSelector;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Enables the selected user settable output line - Applies to: ace USB, dart USB, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : UserOutputSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValue" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IBooleanEx& UserOutputValue;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief A single bit field that sets the state of all user settable output signals in one access - Applies to: ace USB, GigE, 1394 and CameraLink Camera

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValueAll" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserOutputValueAll;
    
    //@}


    //! \name Categories Digital I/O Controls and Digital I/O Control
    //@{
    /*!
        \brief Defines a mask that is used when the User Output Value All setting is used to set all of the user settable output signals in one access - Applies to: GigE and CameraLink Camera

        This integer value defines a mask that is used when the User Output Value All setting is used to set all of the user settable output signals in one access.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserOutputValueAllMask" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& UserOutputValueAllMask;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Sets the user set or the factory set to be used as the startup set - Applies to: ace USB, dart USB, pulse and dart BCON

        Sets the user set or the factory set to be used as the startup set. The startup set will be loaded as the active set whenever the camera is powered on or reset.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetDefault" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetDefaultEnums>& UserSetDefault;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Sets the configuration set to be used as the default startup set  The configuration set that has been selected as the default startup set will be loaded as the active set whenever the camera is powered on or reset - Applies to: GigE, 1394 and CameraLink Camera

        This enumeration sets the configuration set to be used as the default startup set. The configuration set that has been selected as the default startup set will be loaded as the active set whenever the camera is powered on or reset.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetDefaultSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetDefaultSelectorEnums>& UserSetDefaultSelector;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Loads the selected set into the camera's volatile memory and makes it the active configuration set - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

        Loads the selected set into the camera's volatile memory and makes it the active configuration set. Once the selected set is loaded, the parameters in the selected set will control the camera.
    
        \b Visibility = Beginner

        \b Selected by : UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetLoad" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetLoad;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Saves the current active set into the selected user set - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera and dart BCON

    
        \b Visibility = Beginner

        \b Selected by : UserSetSelector

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSave" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::ICommandEx& UserSetSave;
    
    //@}


    //! \name Categories Device Information, User Set Control and Configuration Sets
    //@{
    /*!
        \brief Sets the user set or the factory set to load, save or configure - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=UserSetSelector" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<UserSetSelectorEnums>& UserSetSelector;
    
    //@}


    //! \name Category Virtual Input I/O Controls
    //@{
    /*!
        \brief Sets the length of the input bit - Applies to: GigE and CameraLink Camera

        This integer value sets the length of the input bit in microseconds. It applies to all bits in the signal.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VInpBitLength" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VInpBitLength;
    
    //@}


    //! \name Category Virtual Input I/O Controls
    //@{
    /*!
        \brief Time span between the beginning of the input bit and the time when the high/low status is evaluated - Applies to: GigE and CameraLink Camera

        This integer value sets the time in microseconds that elapses between the beginning of the input bit and the time when the high/low status of the bit is evaluated. It applies to all bits.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VInpSamplingPoint" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VInpSamplingPoint;
    
    //@}


    //! \name Category Virtual Input I/O Controls
    //@{
    /*!
        \brief Selects when to start the signal evaluation - Applies to: GigE and CameraLink Camera

        This enumeration selects when to start the signal evaluation. The camera waits for a rising/falling edge on the input line. When the appropriate signal has been received, the camera starts evaluating the incoming bit patterns. When one bit pattern is finished, the camera waits for the next rising/falling edge to read out the next incoming bit pattern. The camera stops listening once three bits have been received.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VInpSignalReadoutActivation" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<VInpSignalReadoutActivationEnums>& VInpSignalReadoutActivation;
    
    //@}


    //! \name Category Virtual Input I/O Controls
    //@{
    /*!
        \brief Sets the I/O line on which the camera receives the virtual input signal - Applies to: GigE and CameraLink Camera

        This enumeration selects the I/O line on which the camera receives the virtual input signal.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VInpSignalSource" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IEnumParameterT<VInpSignalSourceEnums>& VInpSignalSource;
    
    //@}


    //! \name Category Virtual Line 1 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io virtual line 1 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io virtual line 1 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine1RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine1RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Virtual Line 1 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a virtual line 1 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io virtual line 1 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine1RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine1RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Virtual Line 2 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io virtual line 2 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io virtual line 2 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine2RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine2RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Virtual Line 2 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a virtual line 2 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io virtual line 2 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine2RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine2RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Virtual Line 3 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io virtual line 3 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io virtual line 3 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine3RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine3RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Virtual Line 3 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a virtual line 3 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io virtual line 3 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine3RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine3RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Virtual Line 4 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the stream channel index for an io virtual line 4 rising edge event - Applies to: GigE

        This enumeration Indicates the stream channel index for an io virtual line 4 rising edge event
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine4RisingEdgeEventStreamChannelIndex" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine4RisingEdgeEventStreamChannelIndex;
    
    //@}


    //! \name Category Virtual Line 4 Rising Edge Event Data
    //@{
    /*!
        \brief Indicates the time stamp for a virtual line 4 rising edge event - Applies to: GigE

        This enumeration value indicates the time stamp for an io virtual line 4 rising edge event.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=VirtualLine4RisingEdgeEventTimestamp" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& VirtualLine4RisingEdgeEventTimestamp;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IBooleanEx& VolatileColumnOffsetEnable;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& VolatileColumnOffsetIndex;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : VolatileColumnOffsetIndex

    */
    Pylon::IIntegerEx& VolatileColumnOffsetValue;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Invisible

    */
    Pylon::IRegisterEx& VolatileColumnOffsetValueAll;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IBooleanEx& VolatileRowOffsetEnable;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& VolatileRowOffsetIndex;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Beginner

        \b Selected by : VolatileRowOffsetIndex

    */
    Pylon::IIntegerEx& VolatileRowOffsetValue;
    
    //@}


    //! \name Category Volatile Row And Column Offset
    //@{
    /*!
        \brief Applies to: CameraLink Camera

    
        \b Visibility = Invisible

    */
    Pylon::IRegisterEx& VolatileRowOffsetValueAll;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Width of the camera's region of interest in pixels - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Width of the camera's region of interest in pixels. Depending on the camera model, the parameter can be set in different increments.
    
        \b Visibility = Beginner

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=Width" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& Width;
    
    //@}


    //! \name Categories AOI Controls, Device Information, Image Format Controls and Image Format Control
    //@{
    /*!
        \brief Maximum allowed width of the region of interest in pixels - Applies to: ace USB, dart USB, pulse, GigE, 1394, CameraLink Camera, CamEmu and dart BCON

        Maximum allowed width of the region of interest in pixels. value takes into account any function that may limit the maximum width.
    
        \b Visibility = Expert

        The <a href="https://docs.baslerweb.com/?rhcsh=1&rhmapid=WidthMax" target="_blank">Basler Product Documentation</a> may provide more information.
    */
    Pylon::IIntegerEx& WidthMax;
    
    //@}



    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUniversalCameraParams_Params(CUniversalCameraParams_Params&);

            //! not implemented assignment operator
            CUniversalCameraParams_Params& operator=(CUniversalCameraParams_Params&);

        //! \endcond
    };


} // namespace Basler_UniversalCameraParams

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_Basler_UniversalCameraParams_PARAMS_H
