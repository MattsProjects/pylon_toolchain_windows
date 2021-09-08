
    




//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Basler USB3Vision camera interface
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_UsbCameraParams_PARAMS_H
#define Basler_UsbCameraParams_PARAMS_H

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>

//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UsbCameraParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_Mono8,  //!<Sets the pixel format to Mono 8.
		PixelFormat_Mono12,  //!<Sets the pixel format to Mono 12.
		PixelFormat_Mono12p,  //!<Sets the pixel format to Mono 12p.
		PixelFormat_BayerGR8,  //!<Sets the pixel format to Bayer GR 8.
		PixelFormat_BayerRG8,  //!<Sets the pixel format to Bayer RG 8.
		PixelFormat_BayerGB8,  //!<Sets the pixel format to Bayer GB 8.
		PixelFormat_BayerBG8,  //!<Sets the pixel format to Bayer BG 8.
		PixelFormat_BayerGR12,  //!<Sets the pixel format to Bayer GR 12.
		PixelFormat_BayerGR12p,  //!<Sets the pixel format to Bayer GR 12p.
		PixelFormat_BayerRG12,  //!<Sets the pixel format to Bayer RG 12.
		PixelFormat_BayerRG12p,  //!<Sets the pixel format to Bayer RG 12p.
		PixelFormat_BayerGB12,  //!<Sets the pixel format to Bayer GB 12.
		PixelFormat_BayerGB12p,  //!<Sets the pixel format to Bayer GB 12p.
		PixelFormat_BayerBG12,  //!<Sets the pixel format to Bayer BG 12.
		PixelFormat_BayerBG12p,  //!<Sets the pixel format to Bayer BG 12p.
		PixelFormat_RGB8,  //!<Sets the pixel format to RGB 8
		PixelFormat_BGR8,  //!<Sets the pixel format to BGR 8
		PixelFormat_YCbCr422_8   //!<Sets the pixel format to YCbCr 422.
		
    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp8,  //!<The depth of the pixel values in the acquired images is 8 bits per pixel.
		PixelSize_Bpp12,  //!<The depth of the pixel values in the acquired images is 12 bits per pixel.
		PixelSize_Bpp16,  //!<The depth of the pixel values in the acquired images is 16 bits per pixel.
		PixelSize_Bpp24   //!<The depth of the pixel values in the acquired images is 24 bits per pixel.
		
    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_None,  //!<No Bayer filter is present on the camera.
		PixelColorFilter_BayerRG,  //!<The Bayer filter has an RG/GB alignment to the pixels in the acquired images.
		PixelColorFilter_BayerGB,  //!<The Bayer filter has a GB/RG alignment to the pixels in the acquired images.
		PixelColorFilter_BayerGR,  //!<The Bayer filter has a GR/BG alignment to the pixels in the acquired images.
		PixelColorFilter_BayerBG   //!<The Bayer filter has a BG/GR alignment to the pixels in the acquired images.
		
    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!<No test image will be output from the camera.
		TestImageSelector_Testimage1,  //!<The camera generates and transmits test images with a test image 1 pattern.
		TestImageSelector_Testimage2,  //!<The camera generates and transmits test images with a test image 2 pattern.
		TestImageSelector_Testimage3,  //!<The camera generates and transmits test images with a test image 3 pattern.
		TestImageSelector_Testimage4,  //!<The camera generates and transmits test images with a test image 4 pattern.
		TestImageSelector_Testimage5,  //!<The camera generates and transmits test images with a test image 5 pattern.
		TestImageSelector_Testimage6   //!<The camera generates and transmits test images with a test image 6 pattern.
		
    };

    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Off,  //!<Disables the Gain Auto function.
		GainAuto_Once,  //!<Sets the auto function mode of operation to 'once'.
		GainAuto_Continuous   //!<Sets the auto function mode of operation to 'continuous'.
		
    };

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All   //!<Selects all gain controls for adjustment.
		
    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All   //!<Selects all black level controls for adjustment.
		
    };

    //! Valid values for LightSourcePreset
    enum LightSourcePresetEnums
    {
        LightSourcePreset_Off,  //!<No color improvement for a specific light source is performed.
		LightSourcePreset_Daylight5000K,  //!<Color preset for image acquisition with daylight of 5000 K.
		LightSourcePreset_Daylight6500K,  //!<Color preset for image acquisition with daylight of 6500 K.
		LightSourcePreset_Tungsten2800K   //!<Color preset for image acquisition with tungsten incandescent light (2800 K).
		
    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Off,  //!<Disables the balance white auto function.
		BalanceWhiteAuto_Once,  //!<Sets the balance white auto function to 'once' operation mode.
		BalanceWhiteAuto_Continuous   //!<Sets the balance white auto function to 'continuous' operation mode.
		
    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Red,  //!<Selects the red balance ratio control for adjustment.
		BalanceRatioSelector_Green,  //!<Selects the green balance ratio control for adjustment.
		BalanceRatioSelector_Blue   //!<Selects the blue balance ratio control for adjustment.
		
    };

    //! Valid values for ColorAdjustmentSelector
    enum ColorAdjustmentSelectorEnums
    {
        ColorAdjustmentSelector_Red,  //!<Selects red for the adjustment of colors with predominant red.
		ColorAdjustmentSelector_Yellow,  //!<Selects yellow for the adjustment of colors with predominant yellow.
		ColorAdjustmentSelector_Green,  //!<Selects green the adjustment of colors with predominant green.
		ColorAdjustmentSelector_Cyan,  //!<Selects cyan for the adjustment of colors with predominant cyan.
		ColorAdjustmentSelector_Blue,  //!<Selects blue for the adjustment of colors with predominant blue.
		ColorAdjustmentSelector_Magenta   //!<Selects magenta for the adjustment of colors with predominant magenta.
		
    };

    //! Valid values for ColorTransformationSelector
    enum ColorTransformationSelectorEnums
    {
        ColorTransformationSelector_RGBtoRGB   //!<Matrix color transformation from RGB to RGB.
		
    };

    //! Valid values for ColorTransformationValueSelector
    enum ColorTransformationValueSelectorEnums
    {
        ColorTransformationValueSelector_Gain00,  //!<Element in row 0 and column 0 of the color transformation matrix.
		ColorTransformationValueSelector_Gain01,  //!<Element in row 0 and column 1 of the color transformation matrix.
		ColorTransformationValueSelector_Gain02,  //!<Element in row 0 and column 2 of the color transformation matrix.
		ColorTransformationValueSelector_Gain10,  //!<Element in row 1 and column 0 of the color transformation matrix.
		ColorTransformationValueSelector_Gain11,  //!<Element in row 1 and column 1 of the color transformation matrix
		ColorTransformationValueSelector_Gain12,  //!<Element in row 1 and column 2 of the color transformation matrix.
		ColorTransformationValueSelector_Gain20,  //!<Element in row 2 and column 0 of the color transformation matrix.
		ColorTransformationValueSelector_Gain21,  //!<Element in row 2 and column 1 of the color transformation matrix.
		ColorTransformationValueSelector_Gain22   //!<Element in row 2 and column 2 of the color transformation matrix.
		
    };

    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_SingleFrame,  //!<Sets the acquisition mode to single frame
		AcquisitionMode_Continuous   //!<Sets the acquisition mode to continuous
		
    };

    //! Valid values for ShutterMode
    enum ShutterModeEnums
    {
        ShutterMode_Global,  //!<Sets the shutter mode to global shutter
		ShutterMode_Rolling,  //!<Sets the shutter mode to rolling shutter
		ShutterMode_GlobalResetRelease   //!<Sets the shutter mode to global reset release shutter
		
    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Off,  //!<Disables the exposure auto function.
		ExposureAuto_Once,  //!<Sets the exposure auto function mode of operation to 'once'.
		ExposureAuto_Continuous   //!<Sets the exposure auto function mode of operation to 'continuous'.
		
    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!<Sets the exposure mode to 'timed'.
		ExposureMode_TriggerWidth   //!<Sets the exposure mode to 'trigger width'.
		
    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_FrameBurstStart,  //!<Selects the frame burst start trigger for configuration.
		TriggerSelector_FrameStart   //!<Selects the frame start trigger for configuration.
		
    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!<Sets the mode for the selected trigger to 'off'.
		TriggerMode_On   //!<Sets the mode for the selected trigger to 'on'.
		
    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Software,  //!<Sets the software trigger as the signal source for the selected trigger.
		TriggerSource_Line1,  //!<Sets the signal source for the selected trigger to 'line 1'.
		TriggerSource_Line2,  //!<Sets the signal source for the selected trigger to 'line 2'.
		TriggerSource_Line3,  //!<Sets the signal source for the selected trigger to 'line 3'.
		TriggerSource_Line4   //!<Sets the signal source for the selected trigger to 'line 4'.
		
    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_RisingEdge,  //!<Sets the selected trigger to become active on the rising edge of the source signal.
		TriggerActivation_FallingEdge,  //!<Sets the selected trigger to become active on the falling edge of the source signal.
		TriggerActivation_AnyEdge,  //!<Sets the selected trigger to become active on the falling or rising edge of the source signal.
		TriggerActivation_LevelHigh,  //!<Sets the selected trigger to become active when the source signal is high.
		TriggerActivation_LevelLow   //!<Sets the selected trigger to become active when the source signal is low.
		
    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_FrameBurstTriggerWait,  //!<Device is currently waiting for a trigger for the capture of one or many frames.
		AcquisitionStatusSelector_FrameBurstTriggerActive,  //!<Device is currently doing a frame burst of one or many frames.
		AcquisitionStatusSelector_FrameBurstTriggerTransfer,  //!<Device is currently transferring a frame burst of one or many frames.
		AcquisitionStatusSelector_FrameTriggerWait,  //!<Device is currently waiting for a Frame trigger.
		AcquisitionStatusSelector_FrameActive,  //!<Device is currently doing the capture of a frame.
		AcquisitionStatusSelector_FrameTransfer,  //!<Device is currently transferring a frame.
		AcquisitionStatusSelector_ExposureActive   //!<Device is doing the exposure of a frame.
		
    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_MinimizeGain,  //!<Keeps gain at minimum.
		AutoFunctionProfile_MinimizeExposureTime   //!<Keeps exposure time at minimum.
		
    };

    //! Valid values for AutoFunctionAOISelector
    enum AutoFunctionAOISelectorEnums
    {
        AutoFunctionAOISelector_AOI1,  //!<Selects Auto Function AOI 1.
		AutoFunctionAOISelector_AOI2   //!<Selects Auto Function AOI 2.
		
    };

    //! Valid values for LUTSelector
    enum LUTSelectorEnums
    {
        LUTSelector_Luminance   //!<Selects the luminance LUT for configuration
		
    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!<Selects line 1 for configuration.
		LineSelector_Line2,  //!<Selects line 2 for configuration.
		LineSelector_Line3,  //!<Selects line 3 for configuration.
		LineSelector_Line4   //!<Selects line 4 for configuration.
		
    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!<Sets the mode for the selected line to 'input'.
		LineMode_Output   //!<Sets the mode for the selected line to 'output'.
		
    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_TTL,  //!<Sets the electrical configuration of the selected line to 'TTL'.
		LineFormat_OptoCoupled   //!<Sets the electrical configuration of the selected line to 'opto-coupled'.
		
    };

    //! Valid values for LineLogic
    enum LineLogicEnums
    {
        LineLogic_Positive,  //!<Positive line logic
		LineLogic_Negative   //!<Negative line logic
		
    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_Off,  //!<Sets the source signal for the selected output line to 'off'.
		LineSource_ExposureActive,  //!<Sets the source signal for the selected output line to 'exposure active'.
		LineSource_FrameTriggerWait,  //!<Associates the 'Frame Trigger Wait' status with the selected output line.
		LineSource_FrameBurstTriggerWait,  //!<Associates the 'Frame Burst Trigger Wait' status with the selected output line.
		LineSource_Timer1Active,  //!<Sets the source signal for the selected output line to timer 1 active
		LineSource_UserOutput0,  //!<Sets the source signal for the selected output line to user settable output signal 0.
		LineSource_UserOutput1,  //!<Sets the source signal for the selected output line to user settable output signal 1.
		LineSource_UserOutput2,  //!<Sets the source signal for the selected output line to user settable output signal 2.
		LineSource_UserOutput3,  //!<Sets the source signal for the selected output line to user settable output signal 3.
		LineSource_FlashWindow   //!<
		
    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput1,  //!<Selects user settable output signal 1 for configuration.
		UserOutputSelector_UserOutput2,  //!<Selects user settable output signal 2 for configuration.
		UserOutputSelector_UserOutput3   //!<Selects user settable output signal 3 for configuration.
		
    };

    //! Valid values for CounterSelector
    enum CounterSelectorEnums
    {
        CounterSelector_Counter1   //!<Selects Counter 1 for configuration.
		
    };

    //! Valid values for CounterEventSource
    enum CounterEventSourceEnums
    {
        CounterEventSource_FrameStart   //!<Counts the number of Frame Start.
		
    };

    //! Valid values for CounterResetSource
    enum CounterResetSourceEnums
    {
        CounterResetSource_Off,  //!<Disable the Counter Reset trigger
		CounterResetSource_Software,  //!<Selects software command as the source for counter reset
		CounterResetSource_Line1,  //!<Selects line 1 as the source for counter reset
		CounterResetSource_Line2,  //!<Selects line 2 as the source for counter reset
		CounterResetSource_Line3,  //!<Selects line 3 as the source for counter reset
		CounterResetSource_Line4   //!<Selects line 4 as the source for counter reset
		
    };

    //! Valid values for CounterResetActivation
    enum CounterResetActivationEnums
    {
        CounterResetActivation_RisingEdge   //!<Resets the counter on the rising edge of the signal
		
    };

    //! Valid values for TimerSelector
    enum TimerSelectorEnums
    {
        TimerSelector_Timer1   //!<Selects Timer 1 for configuration.
		
    };

    //! Valid values for TimerTriggerSource
    enum TimerTriggerSourceEnums
    {
        TimerTriggerSource_ExposureStart   //!<Starts with the reception of the Exposure Start.
		
    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_Default,  //!<Selects the default user set.
		UserSetSelector_HighGain,  //!<High gain factory set
		UserSetSelector_AutoFunctions,  //!<Factory set using auto functions
		UserSetSelector_UserSet1,  //!<Selects the user set 1 configuration set.
		UserSetSelector_UserSet2,  //!<Selects the user set 2 configuration set.
		UserSetSelector_UserSet3   //!<Selects the user set 3 configuration set.
		
    };

    //! Valid values for UserSetDefault
    enum UserSetDefaultEnums
    {
        UserSetDefault_Default,  //!<Selects the default user set as the default startup set.
		UserSetDefault_HighGain,  //!<Selects the high gain user set as the default startup set.
		UserSetDefault_AutoFunctions,  //!<Selects the auto function user set as the default startup set.
		UserSetDefault_UserSet1,  //!<Selects user set 1 as the default startup set.
		UserSetDefault_UserSet2,  //!<Selects user set 2 as the default startup set.
		UserSetDefault_UserSet3   //!<Selects user set 3 as the default startup set.
		
    };

    //! Valid values for ChunkSelector
    enum ChunkSelectorEnums
    {
        ChunkSelector_Gain,  //!<Selects the gain chunk for enabling.
		ChunkSelector_ExposureTime,  //!<Selects the exposure time chunk for enabling.
		ChunkSelector_Timestamp,  //!<Selects the timestamp chunk for enabling.
		ChunkSelector_PayloadCRC16,  //!<Selects the CRC checksum chunk for configuration
		ChunkSelector_CounterValue   //!<Selects the counter value chunk for configuration
		
    };

    //! Valid values for ChunkGainSelector
    enum ChunkGainSelectorEnums
    {
        ChunkGainSelector_All   //!<Gain will be applied to all channels or taps
		
    };

    //! Valid values for ChunkCounterSelector
    enum ChunkCounterSelectorEnums
    {
        ChunkCounterSelector_Counter1   //!<Select counter 1
		
    };

    //! Valid values for EventSelector
    enum EventSelectorEnums
    {
        EventSelector_ExposureEnd,  //!<Device just completed the exposure of one Frame.
		EventSelector_FrameStart,  //!<Device just started the capture of one frame.
		EventSelector_FrameBurstStart,  //!<Device just started the capture of a frame burst.
		EventSelector_FrameStartOvertrigger,  //!<Selects the frame start overtrigger event for enabling.
		EventSelector_FrameBurstStartOvertrigger   //!<Selects the frame burst start overtrigger event for enabling.
		
    };

    //! Valid values for EventNotification
    enum EventNotificationEnums
    {
        EventNotification_Off,  //!<The selected Event notification is disabled.
		EventNotification_On   //!<The selected Event notification is enabled.
		
    };

    //! Valid values for BslUSBSpeedMode
    enum BslUSBSpeedModeEnums
    {
        BslUSBSpeedMode_HighSpeed,  //!<
		BslUSBSpeedMode_SuperSpeed   //!<
		
    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!<Indicates that the device has an area scan type of sensor.
		DeviceScanType_Linescan   //!<Indicates that the device has an Line scan type of sensor.
		
    };

    //! Valid values for DeviceLinkThroughputLimitMode
    enum DeviceLinkThroughputLimitModeEnums
    {
        DeviceLinkThroughputLimitMode_Off,  //!<Disables the device link throughput limit feature.
		DeviceLinkThroughputLimitMode_On   //!<Enables the device link throughput limit feature.
		
    };

    //! Valid values for DeviceTemperatureSelector
    enum DeviceTemperatureSelectorEnums
    {
        DeviceTemperatureSelector_Sensorboard,  //!<Temperature on sensor board
		DeviceTemperatureSelector_Coreboard,  //!<Temperature on core board
		DeviceTemperatureSelector_Framegrabberboard   //!<Temperature on framegrabber board
		
    };

    //! Valid values for UserDefinedValueSelector
    enum UserDefinedValueSelectorEnums
    {
        UserDefinedValueSelector_Value1,  //!<
		UserDefinedValueSelector_Value2,  //!<
		UserDefinedValueSelector_Value3,  //!<
		UserDefinedValueSelector_Value4,  //!<
		UserDefinedValueSelector_Value5   //!<
		
    };

    //! Valid values for RemoveParameterLimitSelector
    enum RemoveParameterLimitSelectorEnums
    {
        RemoveParameterLimitSelector_Gain   //!<Selects the gain limits for configuration
		
    };

    //! Valid values for ExpertFeatureAccessSelector
    enum ExpertFeatureAccessSelectorEnums
    {
        ExpertFeatureAccessSelector_ExpertFeature1,  //!<Selects the Expert Feature 1 for configuration
		ExpertFeatureAccessSelector_ExpertFeature2,  //!<Selects the Expert Feature 2 for configuration
		ExpertFeatureAccessSelector_ExpertFeature3,  //!<Selects the Expert Feature 3 for configuration
		ExpertFeatureAccessSelector_ExpertFeature4,  //!<Selects the Expert Feature 4 for configuration
		ExpertFeatureAccessSelector_ExpertFeature5,  //!<Selects the Expert Feature 5 for configuration
		ExpertFeatureAccessSelector_ExpertFeature6,  //!<Selects the Expert Feature 6 for configuration
		ExpertFeatureAccessSelector_ExpertFeature7   //!<Selects the Expert Feature 7 for configuration
		
    };

    //! Valid values for FileSelector
    enum FileSelectorEnums
    {
        FileSelector_UserData,  //!<Selects the file 'User Data'
		FileSelector_UserSet1,  //!<Selects the file 'User Set 1'
		FileSelector_UserSet2,  //!<Selects the file 'User Set 2'
		FileSelector_UserSet3,  //!<Selects the file 'User Set 3'
		FileSelector_UserGainShading1,  //!<Selects the file 'User Gain Shading 1'
		FileSelector_UserGainShading2,  //!<Selects the file 'User Gain Shading 2'
		FileSelector_UserOffsetShading1,  //!<Selects the file 'User Offset Shading 1'
		FileSelector_UserOffsetShading2,  //!<Selects the file 'User Offset Shading 2'
		FileSelector_ExpertFeature7File   //!<Selects the file 'Expert Feature 7 File'
		
    };

    //! Valid values for FileOperationSelector
    enum FileOperationSelectorEnums
    {
        FileOperationSelector_Open,  //!<Opens the file selected by FileSelector
		FileOperationSelector_Close,  //!<Closes the file selected by FileSelector
		FileOperationSelector_Read,  //!<Reads data from the selected file
		FileOperationSelector_Write   //!<Writes data to the selected file
		
    };

    //! Valid values for FileOpenMode
    enum FileOpenModeEnums
    {
        FileOpenMode_Read,  //!<Selects read-only open mode
		FileOpenMode_Write   //!<Selects write-only open mode
		
    };

    //! Valid values for FileOperationStatus
    enum FileOperationStatusEnums
    {
        FileOperationStatus_Success,  //!<Successful file operation
		FileOperationStatus_Failure   //!<Failing file operation
		
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Basler USB3Vision camera interface
    class CUsbCameraParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
		// If you want to show the following methods in the help file
		// add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUsbCameraParams_Params(void);

            //! Destructor
            ~CUsbCameraParams_Params(void);

            //! Initializes the references
            void _Initialize(GenApi::INodeMap*);

            //! Return the vendor of the camera
            const char* _GetVendorName(void);

            //! Returns the camera model name
            const char* _GetModelName(void);
        
        //! \endcond

    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        
	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the width of the camera's sensor in pixels.

	This is a read only parameter. It is of integer type and indicates the actual width of the camera's sensor in pixels.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &SensorWidth;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the height of the camera's sensor in pixels.

	This is a read only parameter. It is of integer type and indicates the actual height of the camera's sensor in pixels.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &SensorHeight;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the camera's maximum allowed width of the area of interest (AOI) in pixels.

	This is a read only parameter. It is of integer type and indicates the maximum allowed width of the camera's area of interest (AOI) in pixels. It takes into account any function that may limit the maximum width.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &WidthMax;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the camera's maximum allowed height of the area of interest (AOI) in pixels.

	This is a read only parameter. It is of integer type and indicates the maximum allowed height of the camera's area of interest (AOI) in pixels. It takes into account any function that may limit the maximum height.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &HeightMax;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the width of the camera's area of interest (AOI) in pixels.

	This parameter is of integer type and determines the width of the camera's area of interest (AOI) in pixels. Depending on the camera model, the parameter can be set in different increments.
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &Width;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the height of the camera's area of interest (AOI) in pixels.

	This parameter is of integer type and determines the height of the camera's area of interest (AOI) in pixels. Depending on the camera model, the parameter can be set in different increments.
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &Height;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the X offset (left offset) of the area of interest (AOI) in pixels.

	The Offset X parameter determines the position of the area of interest (AOI) in the x direction. Since the position of the AOI is referenced to the top left corner of the sensor array, the Offset X parameter sets the distance in pixels between the left side of the sensor and the left side of the AOI.
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &OffsetX;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the Y offset (top offset) of the area of interest (AOI) in pixels.

	The Offset Y parameter determines the position of the area of interest (AOI) in the y direction. Since the position of the AOI is referenced to the top left corner of the sensor array, the Offset Y parameter sets the distance in pixels between the top of the sensor and the top of the AOI.
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &OffsetY;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Enables the horizontal centering of the image.

	This feature is used to center the image horizontally.
	
		\b Visibility = Beginner
	
    */
    GenApi::IBoolean &CenterX;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Enables the vertical centering of the image.

	This feature is used to center the image vertically.
	
		\b Visibility = Beginner
	
    */
    GenApi::IBoolean &CenterY;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Enables the horizontal mirroring of the image.

	This feature is used to mirror the captured image horizontally. The pixel values for each line in a captured image will be swapped end-for-end about the line's center. You can use the AOI feature when using the reverse X feature. Note that the position of the AOI relative to the sensor remains the same.
	
		\b Visibility = Expert
	
    */
    GenApi::IBoolean &ReverseX;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Enables the vertical mirroring of the image.

	This feature is used to mirror the captured image vertically. The pixel values for each row in a captured image will be swapped end-for-end about the row's center. You can use the AOI feature when using the reverse Y feature. Note that the position of the AOI relative to the sensor remains the same.
	
		\b Visibility = Expert
	
    */
    GenApi::IBoolean &ReverseY;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the number of adjacent horizontal pixels to be summed.

	Binning increases the camera's response to light by summing the charges from adjacent pixels into one pixel. The Binning Horizontal parameter sets the number of adjacent horizontal pixels to be summed. Their summed charges will be reported out of the camera as a single pixel.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &BinningHorizontal;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the number of adjacent vertical pixels to be summed.

	Binning increases the camera's response to light by summing the charges from adjacent pixels into one pixel. The Binning Vertical parameter sets the number of adjacent vertical pixels to be summed. Their summed charges will be reported out of the camera as a single pixel.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &BinningVertical;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Sets the format of the pixel data transmitted for acquired images.

	The Pixel Format parameter determines the format (layout) of the image data that will be output from the camera. The available pixel formats depend on the camera model and whether the camera is monochrome or color.
	
		\b Visibility = Beginner
	
    */
    GenApi::IEnumerationT<PixelFormatEnums > &PixelFormat;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the depth of the pixel values in the image in bits per pixel.

	This is a read only feature. This enumeration provides a list of values that indicate the depth of the pixel values in the acquired images in bits per pixel. This value will always be coherent with the pixel format setting.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<PixelSizeEnums > &PixelSize;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the current alignment of the camera's Bayer filter to the pixels in the acquired images.

	This is a read only feature. This enumeration provides a list of values that indicate the current alignment of the camera's Bayer filter to the pixels in the acquired images. The alignment of the Bayer filter depends on the camera model.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<PixelColorFilterEnums > &PixelColorFilter;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the minimum possible pixel value that could be transferred from the camera.

	This a read only feature. The Dynamic Range Min parameter indicates the minimum possible pixel value that could be transferred from the camera.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &PixelDynamicRangeMin;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Indicates the maximum possible pixel value that could be transferred from the camera.

	This a read only feature. The Dynamic Range Max parameter indicates the maximum possible pixel value that could be transferred from the camera.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &PixelDynamicRangeMax;
    
    //@}
    

	//! \name ImageFormatControl - This category includes image format controls
    //@{
	/*!	
		\brief Selecting a test image from the list will output the test image.

	The Test Image Selector is used to set the camera to output a test image. You can set the value of the Test Image Selector to one of the test images or to 'test image off'.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<TestImageSelectorEnums > &TestImageSelector;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Adjusts the Gain Raw parameter value automatically.

	The gain auto function is the 'automatic' counterpart to manually setting the Gain Raw parameter. It allows to adjust the Gain Raw parameter value automatically within set limits until a target average gray value for the pixel data from the related Auto Function AOI is reached.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<GainAutoEnums > &GainAuto;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Selects the gain control to configure.

	The Gain Selector parameter is used to select the gain control to configure. Once a gain control has been selected, all changes to the gain settings will be applied to the selected control.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<GainSelectorEnums > &GainSelector;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Sets the selected gain control in dB.

	This is a float value that sets the selected gain control in dB.
	
		\b Visibility = Beginner
        
	
		\b Selected by : GainSelector
	
    */
    GenApi::IFloat &Gain;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Selcts a black level control to configure.

	This enumeration selects the black level control to configure. Once a black level control has been selected, all changes to the black level settings will be applied to the selected control.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<BlackLevelSelectorEnums > &BlackLevelSelector;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Sets the value of the selected black level control as a float

	This value sets the selected black level control as a float value. Adjusting the camera's black level will result in an offset to the pixel values output by the camera.
	
		\b Visibility = Beginner
        
	
		\b Selected by : BlackLevelSelector
	
    */
    GenApi::IFloat &BlackLevel;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Performs gamma correction of pixel intensity.

	The gamma correction feature lets you modify the brightness of the pixel values output by the camera's sensor to account for a non-linearity in the human perception of brightness.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &Gamma;
    
    //@}
    

	//! \name AnalogControl - 
    //@{
	/*!	
		\brief Sets the value of the selected digital shift control

	This value sets the selected digital shift control
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &DigitalShift;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Selects the light source preset.

	This parameter determines the light source preset. The colors in the image will be corrected so that they are appropriate for the selected light source.
	
		\b Visibility = Beginner
	
    */
    GenApi::IEnumerationT<LightSourcePresetEnums > &LightSourcePreset;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Adjusts the white balance setting automatically.

	Balance White Auto is the 'automatic' counterpart to manually setting the white balance. Automatic white balancing is a two-step process. First, the Balance Ratio Abs parameter values for red, green, and blue are each set to 1.5. Then, assuming a 'gray world' model, the Balance Ratio Abs parameter values are automatically adjusted such that the average values for the 'red' and 'blue' pixels match the average value for the 'green' pixels.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<BalanceWhiteAutoEnums > &BalanceWhiteAuto;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Selects a balance ratio to configure.

	This enumeration selects a balance ratio control to configure. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<BalanceRatioSelectorEnums > &BalanceRatioSelector;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Sets the value of the selected balance ratio control as a float.

	This value sets the selected balance ratio control as a float value.
	
		\b Visibility = Beginner
        
	
		\b Selected by : BalanceRatioSelector
	
    */
    GenApi::IFloat &BalanceRatio;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Selects the color for color adjustment

	Selects the color for color adjustment.
Those colors in the image will be adjusted where the selected color predominates.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<ColorAdjustmentSelectorEnums > &ColorAdjustmentSelector;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Adjustment of hue of the selected color (float)

	Sets a floating point value for the adjustment of hue of the selected color.
	
		\b Visibility = Expert
	
		\b Selected by : ColorAdjustmentSelector
	
    */
    GenApi::IFloat &ColorAdjustmentHue;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Adjustment of saturation of the selected color (float)

	Sets a floating point value for the adjustment of saturation of the selected color.
	
		\b Visibility = Expert
	
		\b Selected by : ColorAdjustmentSelector
	
    */
    GenApi::IFloat &ColorAdjustmentSaturation;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Selects the matrix color transformation between color spaces

	Selects the matrix color transformation between color spaces.
Generally, the related color spaces are used for internal processing: The color signals provided by the sensor are transformed to the RGB color space to allow further transformations (to account for the type of light source, for color adjustment, for white balance, etc.).
The color transformation selected here does not refer to the color space selected for the transmission of image data out of the camera.

	
		\b Visibility = Guru
	
    */
    GenApi::IEnumerationT<ColorTransformationSelectorEnums > &ColorTransformationSelector;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Selects the element to be entered in the color transformation matrix.

	Selects the element to be entered in the 3 x 3 color transformation matrix for custom matrix color transformation.
Note: Depending on the camera model, some elements in the color transformation matrix may be preset and can not be changed.

	
		\b Visibility = Guru
	
		\b Selected by : ColorTransformationSelector
	
    */
    GenApi::IEnumerationT<ColorTransformationValueSelectorEnums > &ColorTransformationValueSelector;
    
    //@}
    

	//! \name ImageQualityControl - 
    //@{
	/*!	
		\brief Sets a floating point value for the selected element in the color transformation matrix

	Sets a floating point value for the selected element in the color transformation matrix.
	
		\b Visibility = Guru
	
		\b Selected by : ColorTransformationSelector, ColorTransformationValueSelector
	
    */
    GenApi::IFloat &ColorTransformationValue;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the image acquisition mode.

	This enumeration sets the image acquisition mode. 
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<AcquisitionModeEnums > &AcquisitionMode;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Starts the acquisition of images.

	This command starts the acquisition of images. If the camera is set for single frame acquisition, it will start acquisition of one frame. If the camera is set for continuous frame acquisition, it will start continuous acquisition of frames.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::ICommand &AcquisitionStart;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Stops the acquisition of images.

	If the camera is set for continuous image acquisition and acquisition has been started, this command stops the acquisition of images.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::ICommand &AcquisitionStop;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the shutter mode

	This enumeration sets the shutter mode.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<ShutterModeEnums > &ShutterMode;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Adjusts the Auto Exposure Time Abs parameter value automatically.

	Exposure Auto is the 'automatic' counterpart to manually setting the Exposure Time Abs parameter. It adjusts the Exposure Time Abs parameter value automatically within set limits until a target average gray value for the pixel data of the related Auto Function AOI is reached.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<ExposureAutoEnums > &ExposureAuto;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the exposure mode.

	This enumeration sets the exposure mode.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<ExposureModeEnums > &ExposureMode;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the camera's exposure time directly in microseconds.

	This float value sets the camera's exposure time in microseconds.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &ExposureTime;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the maximum overlap time of the sensor exposure with sensor readout in trigger width exposure mode in microseconds.

	This float value sets the maximum overlap time (in microseconds) of the sensor exposure with sensor readout in trigger width exposure mode.
	
		\b Visibility = Expert
	
    */
    GenApi::IFloat &ExposureOverlapTimeMax;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Number of frames to acquire for each FrameBurstStart trigger

	Number of frames to acquire for each FrameBurstStart trigger
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &AcquisitionBurstFrameCount;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Selects the trigger type to configure.

	This enumeration selects the trigger type to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<TriggerSelectorEnums > &TriggerSelector;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the mode for the selected trigger.

	This enumeration sets the trigger mode for the selected trigger.
	
		\b Visibility = Beginner
        
	
		\b Selected by : TriggerSelector
	
    */
    GenApi::IEnumerationT<TriggerModeEnums > &TriggerMode;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Generates a software trigger signal that is used when the trigger source is set to 'software trigger'.

	This command generates a software trigger signal. The software trigger signal will be used when the trigger source is set to 'software trigger'.
	
		\b Visibility = Expert
	
		\b Selected by : TriggerSelector
	
    */
    GenApi::ICommand &TriggerSoftware;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the signal source for the selected trigger.

	The Trigger Source parameter specifies the source signal that will act as the frame start trigger signal.
	
		\b Visibility = Expert
	
		\b Selected by : TriggerSelector
	
    */
    GenApi::IEnumerationT<TriggerSourceEnums > &TriggerSource;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the signal transition needed to activate the selected trigger.

	This enumeration sets the signal transition needed to activate the selected trigger.
	
		\b Visibility = Expert
	
		\b Selected by : TriggerSelector
	
    */
    GenApi::IEnumerationT<TriggerActivationEnums > &TriggerActivation;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the trigger delay time in microseconds.

	This float value sets the absolute trigger delay in microseconds to apply after the trigger reception before effectively activating it.
	
		\b Visibility = Expert
	
    */
    GenApi::IFloat &TriggerDelay;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Enables setting the camera's acquisition frame rate to a specified value.

	This boolean value enables setting the camera's acquisition frame rate to a specified value.
	
		\b Visibility = Beginner
	
    */
    GenApi::IBoolean &AcquisitionFrameRateEnable;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Sets the camera's acquisition frame rate in frames per second.

	The Acquisition Frame Rate parameter sets the 'absolute' value of the acquisition frame rate. The 'absolute' value is a float value that sets the acquisition frame rate in frames per second.
	
		\b Visibility = Beginner
	
    */
    GenApi::IFloat &AcquisitionFrameRate;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Indicates the maximum allowed frame acquisition rate.

	The Resulting Frame Rate parameter indicates the 'absolute' value of the maximum allowed acquisition frame rate. The 'absolute' value is a float value that indicates the maximum allowed acquisition frame rate in frames per second given the current settings for the area of interest, exposure time, and bandwidth.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &ResultingFrameRate;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Indicates the sensor readout time given the current settings.

	The Sensor Readout Time parameter indicates the sensor readout time given the current settings.
	
		\b Visibility = Guru
	
    */
    GenApi::IFloat &SensorReadoutTime;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Selects which internal acquisition signal to read using the Acquisition Status parameter.

	This enumeration is used to select which internal acquisition signal to read using Acquisition Status parameter.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<AcquisitionStatusSelectorEnums > &AcquisitionStatusSelector;
    
    //@}
    

	//! \name AcquisitionControl - 
    //@{
	/*!	
		\brief Reports the selected acquisition status.

	This feature is used to read the state (true or false) of the internal acquisition signal selected using the Acquisition Status Selector parameter.
	
		\b Visibility = Expert
	
		\b Selected by : AcquisitionStatusSelector
	
    */
    GenApi::IBoolean &AcquisitionStatus;
    
    //@}
    

	//! \name AutoFunctionControl - This category includes items that parameterize the Auto Functions
    //@{
	/*!	
		\brief Sets the target average brightness for the gain auto function and the exposure auto function.

	This float value sets the target average brightness for the gain auto function and the exposure auto function.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &AutoTargetBrightness;
    
    //@}
    

	//! \name AutoFunctionControl - This category includes items that parameterize the Auto Functions
    //@{
	/*!	
		\brief Selects the strategy for controlling gain and shutter simultaneously.

	The auto function profile specifies whether the gain or the exposure time will be kept as low as possible when the camera is making automatic adjustments to achieve a target average gray value for the pixel data from the Auto Function AOI that was related to the gain auto and the exposure auto function. By default, the auto function profile feature minimizes gain.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<AutoFunctionProfileEnums > &AutoFunctionProfile;
    
    //@}
    

	//! \name AutoFunctionControl - This category includes items that parameterize the Auto Functions
    //@{
	/*!	
		\brief Sets the lower limit of the Gain parameter.

	This float value sets the lower limit of the Gain parameter.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &AutoGainLowerLimit;
    
    //@}
    

	//! \name AutoFunctionControl - This category includes items that parameterize the Auto Functions
    //@{
	/*!	
		\brief Sets the upper limit of the Gain parameter.

	This float value sets the upper limit of the Gain parameter.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &AutoGainUpperLimit;
    
    //@}
    

	//! \name AutoFunctionControl - This category includes items that parameterize the Auto Functions
    //@{
	/*!	
		\brief Sets the lower limit of the Exposure Time parameter.

	This float value sets the lower limit of the Exposure Time parameter.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &AutoExposureTimeLowerLimit;
    
    //@}
    

	//! \name AutoFunctionControl - This category includes items that parameterize the Auto Functions
    //@{
	/*!	
		\brief Sets the upper limit of the Exposure Time parameter.

	This float value sets the upper limit of the Exposure Time parameter.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &AutoExposureTimeUpperLimit;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief Selects the Auto Function AOI.

	Selects the Auto Function AOI.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<AutoFunctionAOISelectorEnums > &AutoFunctionAOISelector;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief Sets the width of the auto function area of interest in pixels.

	This value sets the width of the auto function area of interest in pixels.
	
		\b Visibility = Beginner
        
	
		\b Selected by : AutoFunctionAOISelector
	
    */
    GenApi::IInteger &AutoFunctionAOIWidth;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief Sets the height of the auto function area of interest in pixels.

	This value sets the height of the auto function area of interest in pixels.
	
		\b Visibility = Beginner
        
	
		\b Selected by : AutoFunctionAOISelector
	
    */
    GenApi::IInteger &AutoFunctionAOIHeight;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief Sets the starting column of the auto function area of interest in pixels.

	The Offset X parameter determines the position of the auto function area of interest in the x direction.
	
		\b Visibility = Beginner
        
	
		\b Selected by : AutoFunctionAOISelector
	
    */
    GenApi::IInteger &AutoFunctionAOIOffsetX;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief Sets the starting line of the auto function area of interest in pixels.

	The Offset Y parameter determines the position of the auto function area of interest in the y direction.
	
		\b Visibility = Beginner
        
	
		\b Selected by : AutoFunctionAOISelector
	
    */
    GenApi::IInteger &AutoFunctionAOIOffsetY;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Beginner
        
	
		\b Selected by : AutoFunctionAOISelector
	
    */
    GenApi::IBoolean &AutoFunctionAOIUseBrightness;
    
    //@}
    

	//! \name AutoFunctionAOIControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Beginner
        
	
		\b Selected by : AutoFunctionAOISelector
	
    */
    GenApi::IBoolean &AutoFunctionAOIUseWhiteBalance;
    
    //@}
    

	//! \name LUTControl - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
	/*!	
		\brief Selects the lookup table (LUT) to configure. Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT.

	This enumeration the lookup table (LUT) to configure. Once a LUT has been selected, all changes to the LUT settings will be applied to the selected LUT.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<LUTSelectorEnums > &LUTSelector;
    
    //@}
    

	//! \name LUTControl - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
	/*!	
		\brief Enables the selected LUT

	This boolean value enables the selected LUT.
	
		\b Visibility = Expert
	
		\b Selected by : LUTSelector
	
    */
    GenApi::IBoolean &LUTEnable;
    
    //@}
    

	//! \name LUTControl - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
	/*!	
		\brief Sets the LUT element to access 

	This value sets the LUT element to access. This value is used to index into a LUT array.
	
		\b Visibility = Guru
	
		\b Selected by : LUTSelector
	
    */
    GenApi::IInteger &LUTIndex;
    
    //@}
    

	//! \name LUTControl - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
	/*!	
		\brief Sets the value of the LUT element at the LUT index

	This value sets the value of the LUT element at the LUT index.
	
		\b Visibility = Guru
	
		\b Selected by : LUTSelector, LUTIndex
	
    */
    GenApi::IInteger &LUTValue;
    
    //@}
    

	//! \name LUTControl - This category includes items used to control the operation of the camera's lookup table (LUT)
    //@{
	/*!	
		\brief Accesses the entire content of the selected LUT in one chunk access

	Accesses the entire content of the selected LUT in one chunk access
	
		\b Visibility = Guru
	
		\b Selected by : LUTSelector
	
    */
    GenApi::IRegister &LUTValueAll;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Selects the I/O line to configure.

	This enumeration selects the I/O line to configure. Once a line has been selected, all changes to the line settings will be applied to the selected line.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<LineSelectorEnums > &LineSelector;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Sets the mode for the selected line.

	This feature controls whether the physical line is used to input or output a signal. When a line supports input and output mode, the default state is 'input' to avoid possible electrical contention. The Line Mode parameter can take any of the following values: Input: The selected physical line is used to input an electrical signal. Output: The selected physical line is used to output an electrical signal.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IEnumerationT<LineModeEnums > &LineMode;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Reports the electrical configuration of the selected line.

	This feature reports the current electrical format of the selected physical input or output line. The Line Format parameter can take any of the following values: No Connect: The line is not connected. Tri-state: The line is currently in tri-state mode (not driven). TTL: The line is currently accepting or sending TTL level signals. LVDS: The line is currently accepting or sending LVDS level signals. RS-422: The line is currently accepting or sending RS-422 level signals. Opto-coupled: The line is opto-coupled.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IEnumerationT<LineFormatEnums > &LineFormat;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Reports the line logic of the selected line.

	Reports the line logic of the selected line. The line logic can be positive or negative.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IEnumerationT<LineLogicEnums > &LineLogic;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Sets the source signal for the selected line (if the selected line is an output).

	This enumeration selects the internally generated camera signal (source signal) for the selected line when the selected line is an output. 
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IEnumerationT<LineSourceEnums > &LineSource;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Enables the signal inverter function for the selected input or output line.

	This boolean value enables the signal inverter function for the selected input or output line.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IBoolean &LineInverter;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Sets the absolute value of the selected line debouncer time in microseconds.

	This float value sets the absolute value of the selected line debouncer time in microseconds.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IFloat &LineDebouncerTime;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Sets the absolute value (in microseconds) for the minimum signal width of an output signal.

	This float value sets the absolute value (in microseconds) for the minimum signal width of a signal that is received from the frequency converter or from the shaft encoder module and that is associated with a digital output line.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IFloat &LineMinimumOutputPulseWidth;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Indicates that an overload condition was detected on the selected line.

	This boolean value indicates that an overload condition was detected on the selected line.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IBoolean &LineOverloadStatus;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Indicates the current logical state for the selected line.

	This boolean value indicates the current logical state for the selected line at the time of polling.
	
		\b Visibility = Beginner
        
	
		\b Selected by : LineSelector
	
    */
    GenApi::IBoolean &LineStatus;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief A single bitfield indicating the current logical state of all available line signals at time of polling.

	This integer value is a single bitfield that indicates the current logical state of all available lines at time of polling.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &LineStatusAll;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Selects the user settable output signal to configure.

	This enumeration selects the user settable output signal to configure. Once a user settable output signal has been selected, all changes to the user settable output signal settings will be applied to the selected user settable output signal.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<UserOutputSelectorEnums > &UserOutputSelector;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief Sets the state of the selected user settable output signal.

	This boolean value sets the state of the selected user settable output signal.
	
		\b Visibility = Beginner
        
	
		\b Selected by : UserOutputSelector
	
    */
    GenApi::IBoolean &UserOutputValue;
    
    //@}
    

	//! \name DigitalIOControl - This category includes items used to control the operation of the camera's digital I/O lines
    //@{
	/*!	
		\brief A single bitfield that sets the state of all user settable output signals in one access.

	This integer value is a single bitfield that sets the state of all user settable output signals in one access.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &UserOutputValueAll;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Selects which Counter to configure

	Selects which Counter to configure.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<CounterSelectorEnums > &CounterSelector;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Select the events that will be the source to increment the Counter

	Select the events that will be the source to increment the Counter.
	
		\b Visibility = Beginner
        
	
		\b Selected by : CounterSelector
	
    */
    GenApi::IEnumerationT<CounterEventSourceEnums > &CounterEventSource;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Selects the signals that will be the source to reset the Counter

	Selects the signals that will be the source to reset the Counter.
	
		\b Visibility = Beginner
        
	
		\b Selected by : CounterSelector
	
    */
    GenApi::IEnumerationT<CounterResetSourceEnums > &CounterResetSource;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Selects the Activation mode of the Counter Reset Source signal

	Selects the Activation mode of the Counter Reset Source signal.
	
		\b Visibility = Beginner
        
	
		\b Selected by : CounterSelector
	
    */
    GenApi::IEnumerationT<CounterResetActivationEnums > &CounterResetActivation;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Does a software reset of the selected counter

	Does a software reset of the selected counter.
	
		\b Visibility = Beginner
        
	
		\b Selected by : CounterSelector
	
    */
    GenApi::ICommand &CounterReset;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Selects which Timer to configure.

	Selects which Timer to configure.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<TimerSelectorEnums > &TimerSelector;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Sets the duration (in microseconds) of the Timer pulse.

	Sets the duration (in microseconds) of the Timer pulse.
	
		\b Visibility = Beginner
        
	
		\b Selected by : TimerSelector
	
    */
    GenApi::IFloat &TimerDuration;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Sets the delay (in microseconds) of the Timer pulse.

	Sets the delay (in microseconds) of the Timer pulse.
	
		\b Visibility = Beginner
        
	
		\b Selected by : TimerSelector
	
    */
    GenApi::IFloat &TimerDelay;
    
    //@}
    

	//! \name CounterAndTimerControl - This category contains the Counter and Timer control features.
    //@{
	/*!	
		\brief Selects the source of the trigger to start the Timer.

	Selects the source of the trigger to start the Timer.
	
		\b Visibility = Beginner
        
	
		\b Selected by : TimerSelector
	
    */
    GenApi::IEnumerationT<TimerTriggerSourceEnums > &TimerTriggerSource;
    
    //@}
    

	//! \name UserSetControl - This category includes items that control the user sets feature that is used to save sets of parameters in the camera
    //@{
	/*!	
		\brief Selects the user set to load, save, or configure.

	This enumeration selects the user set to load, save, or configure. Once a user set has been selected, all changes to the user set settings will be applied to the selected user set.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<UserSetSelectorEnums > &UserSetSelector;
    
    //@}
    

	//! \name UserSetControl - This category includes items that control the user sets feature that is used to save sets of parameters in the camera
    //@{
	/*!	
		\brief Loads the selected configuration into the camera's volatile memory and makes it the active user set.

	This command loads the selected user set from the non-volatile memory in the camera to the volatile memory and makes the selected set the active user set. Once the selected set is loaded, the parameters in the selected set will control the camera.
	
		\b Visibility = Beginner
        
	
		\b Selected by : UserSetSelector
	
    */
    GenApi::ICommand &UserSetLoad;
    
    //@}
    

	//! \name UserSetControl - This category includes items that control the user sets feature that is used to save sets of parameters in the camera
    //@{
	/*!	
		\brief Saves the current active user set into the selected user set. 

	This command copies the parameters in the current active user set into the selected user set in the camera's non-volatile memory.
	
		\b Visibility = Beginner
        
	
		\b Selected by : UserSetSelector
	
    */
    GenApi::ICommand &UserSetSave;
    
    //@}
    

	//! \name UserSetControl - This category includes items that control the user sets feature that is used to save sets of parameters in the camera
    //@{
	/*!	
		\brief Sets the user set to be used as the default startup set.

	This enumeration sets the user set to be used as the default startup set. The user set that has been selected as the default startup set will be loaded as the active set whenever the camera is powered on or reset.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<UserSetDefaultEnums > &UserSetDefault;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Enables the chunk mode

	This boolean value enables the camera's chunk mode.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IBoolean &ChunkModeActive;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Selects chunks for enabling.

	This enumeration selects chunks for enabling.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IEnumerationT<ChunkSelectorEnums > &ChunkSelector;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Enables the inclusion of the selected chunk in the payload data

	This boolean value enables the inclusion of the selected chunk in the payload data.
	
		\b Visibility = Beginner
        
	
		\b Selected by : ChunkSelector
	
    */
    GenApi::IBoolean &ChunkEnable;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Selects which Gain to retrieve data from.

	Selects which Gain to retrieve data from.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<ChunkGainSelectorEnums > &ChunkGainSelector;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Returns the gain used to capture the image.

	Returns the gain used to capture the image.
	
		\b Visibility = Beginner
        
	
		\b Selected by : ChunkGainSelector
	
    */
    GenApi::IFloat &ChunkGain;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Returns the exposure time used to capture the image.

	Returns the exposure time used to capture the image.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &ChunkExposureTime;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Indicates the value of the timestamp when the image was acquired

	This integer indicates the value of the timestamp when the image was acquired.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &ChunkTimestamp;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Indicates the value of CRC checksum

	This integer indicates the value of CRC checksum.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &ChunkPayloadCRC16;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Selects which counter to retrieve data from.

	Selects which counter to retrieve data from.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<ChunkCounterSelectorEnums > &ChunkCounterSelector;
    
    //@}
    

	//! \name ChunkDataControl - This category includes items that control the chunk features available on the camera.
    //@{
	/*!	
		\brief Indicates the value of the selected Chunk counter

	Indicates the value of the selected Chunk counter.
	
		\b Visibility = Beginner
        
	
		\b Selected by : ChunkCounterSelector
	
    */
    GenApi::IInteger &ChunkCounterValue;
    
    //@}
    

	//! \name EventControl - This category contains Event control features.
    //@{
	/*!	
		\brief Selects which Event to signal to the host application.

	Selects which Event to signal to the host application.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<EventSelectorEnums > &EventSelector;
    
    //@}
    

	//! \name EventControl - This category contains Event control features.
    //@{
	/*!	
		\brief Activate or deactivate the notification to the host application of the occurrence of the selected
Event.

	Activate or deactivate the notification to the host application of the occurrence of the selected
Event.
	
		\b Visibility = Expert
	
		\b Selected by : EventSelector
	
    */
    GenApi::IEnumerationT<EventNotificationEnums > &EventNotification;
    
    //@}
    

	//! \name EventExposureEndData - This category includes items available for an exposure end event
    //@{
	/*!	
		\brief Returns the unique identifier of the ExposureEnd type of Event

	Returns the unique identifier of the ExposureEnd type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventExposureEnd;
    
    //@}
    

	//! \name EventExposureEndData - This category includes items available for an exposure end event
    //@{
	/*!	
		\brief Indicates the time stamp for an exposure end event

	This enumeration value indicates the time stamp for an exposure end event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventExposureEndTimestamp;
    
    //@}
    

	//! \name EventExposureEndData - This category includes items available for an exposure end event
    //@{
	/*!	
		\brief Indicates the frame ID for an exposure end event

	This enumeration value indicates the frame ID for an exposure end event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventExposureEndFrameID;
    
    //@}
    

	//! \name EventFrameStartData - This category includes items available for a frame start event
    //@{
	/*!	
		\brief Returns the unique identifier of the FrameStart type of Event

	Returns the unique identifier of the FrameStart type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameStart;
    
    //@}
    

	//! \name EventFrameStartData - This category includes items available for a frame start event
    //@{
	/*!	
		\brief Indicates the time stamp for a frame start event

	This enumeration value indicates the time stamp for a frame start event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameStartTimestamp;
    
    //@}
    

	//! \name EventFrameStartData - This category includes items available for a frame start event
    //@{
	/*!	
		\brief Indicates the frame ID for a frame start event

	This enumeration value indicates the frame ID for a frame start event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameStartFrameID;
    
    //@}
    

	//! \name EventFrameBurstStartData - This category includes items available for a frame burst start event
    //@{
	/*!	
		\brief Returns the unique identifier of the FrameBurstStart type of Event

	Returns the unique identifier of the FrameBurstStart type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameBurstStart;
    
    //@}
    

	//! \name EventFrameBurstStartData - This category includes items available for a frame burst start event
    //@{
	/*!	
		\brief Indicates the time stamp for a frame burst start event

	This enumeration value indicates the time stamp for a frame burst start event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameBurstStartTimestamp;
    
    //@}
    

	//! \name EventFrameBurstStartData - This category includes items available for a frame burst start event
    //@{
	/*!	
		\brief Indicates the frame ID for a frame burst start event

	This enumeration value indicates the frame ID for a frame burst start event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameBurstStartFrameID;
    
    //@}
    

	//! \name EventFrameStartOvertriggerData - This category includes items available for a frame start overtrigger event
    //@{
	/*!	
		\brief Returns the unique identifier of the FrameOvertriggerStart type of Event

	Returns the unique identifier of the FrameStartOvertrigger type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameStartOvertrigger;
    
    //@}
    

	//! \name EventFrameStartOvertriggerData - This category includes items available for a frame start overtrigger event
    //@{
	/*!	
		\brief Indicates the time stamp for a frame start overtrigger event

	This enumeration value indicates the time stamp for a frame start overtrigger event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameStartOvertriggerTimestamp;
    
    //@}
    

	//! \name EventFrameStartOvertriggerData - This category includes items available for a frame start overtrigger event
    //@{
	/*!	
		\brief Indicates the frame ID for a frame start overtrigger event

	This enumeration value indicates the frame ID for a frame start overtrigger event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameStartOvertriggerFrameID;
    
    //@}
    

	//! \name EventFrameBurstStartOvertriggerData - This category includes items available for a frame burst start overtrigger event
    //@{
	/*!	
		\brief Returns the unique identifier of the FrameBurstOvertriggerStart type of Event

	Returns the unique identifier of the FrameBurstStartOvertrigger type of Event. This feature can be used to register a callback function to be notified of the event occurrence. Its value uniquely identifies the type of event that will be received.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameBurstStartOvertrigger;
    
    //@}
    

	//! \name EventFrameBurstStartOvertriggerData - This category includes items available for a frame burst start overtrigger event
    //@{
	/*!	
		\brief Indicates the time stamp for a frame burst start overtrigger event

	This enumeration value indicates the time stamp for a frame burst start overtrigger event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameBurstStartOvertriggerTimestamp;
    
    //@}
    

	//! \name EventFrameBurstStartOvertriggerData - This category includes items available for a frame burst start overtrigger event
    //@{
	/*!	
		\brief Indicates the frame ID for a frame burst start overtrigger event

	This enumeration value indicates the frame ID for a frame burst start overtrigger event.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &EventFrameBurstStartOvertriggerFrameID;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief Size of the payload in bytes

	Size of the payload in bytes. This is the total number of bytes sent in the payload. 
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &PayloadSize;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Beginner
	
    */
    GenApi::IEnumerationT<BslUSBSpeedModeEnums > &BslUSBSpeedMode;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief Expected Size of a single Payload Transfer.

	Expected Size of a single Payload Transfer.
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &SIPayloadTransferSize;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief Expected Number of Payload Transfers.

	Expected Number of Payload Transfers.
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &SIPayloadTransferCount;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief Size of first final Payload Transfer.

	Size of first final Payload Transfer.
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &SIPayloadFinalTransfer1Size;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief Size of second final Payload Transfer.

	Size of second final Payload Transfer.
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &SIPayloadFinalTransfer2Size;
    
    //@}
    

	//! \name TransportLayerControl - This category includes items related to the USB3 Vision transport layer
    //@{
	/*!	
		\brief Test PENDING_ACK feature

	On write, the device waits a time period of TestPendingAck ms before acknowledging the write.
If this time period is longer than the value in the Maximum Device Response Time register, the device must use PENDING_ACK during the completion of this request.
On reads the device returns the current value without any additional wait time.
	
		\b Visibility = Invisible
	
    */
    GenApi::IInteger &TestPendingAck;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the name of the device's vendor.

	This is a read only element. It is a text description that indicates the name of the device's vendor.
	
		\b Visibility = Beginner
	
    */
    GenApi::IString &DeviceVendorName;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the model name of the device.

	This is a read only element. It is a text description that indicates the model name of the device.
	
		\b Visibility = Beginner
	
    */
    GenApi::IString &DeviceModelName;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Provides additional information from the vendor about the device.

	This is a read only element. It is a string that provides additional information from the vendor about the camera.
	
		\b Visibility = Beginner
	
    */
    GenApi::IString &DeviceManufacturerInfo;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the version of the device.

	This is a read only element. It is a string that indicates the version of the device.
	
		\b Visibility = Beginner
	
    */
    GenApi::IString &DeviceVersion;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the version of the device's firmware and software.

	This is a read only element. It is a string that indicates the version of the device's firmware and software.
	
		\b Visibility = Beginner
	
    */
    GenApi::IString &DeviceFirmwareVersion;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the serial number of the device.

	This is a read only element. It is a string that indicates the serial number of the device.
	
		\b Visibility = Beginner
	
    */
    GenApi::IString &DeviceSerialNumber;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the scan type of the device's sensor.

	This enumeration lists the possible scan types for the sensor in the device.
	
		\b Visibility = Beginner
	
    */
    GenApi::IEnumerationT<DeviceScanTypeEnums > &DeviceScanType;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief A device ID that is user programmable

	This is a read/write element. It is a user programmable string.
	
		\b Visibility = Expert
	
    */
    GenApi::IString &DeviceUserID;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Selects the link of the device to control.

	The Device Link Selector parameter is of type integer and selects the link of the device to control.
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &DeviceLinkSelector;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the speed of transmission negotiated on the selected link.

	The Device Link Speed parameter is of type integer and indicates the speed of transmission negotiated on the selected link.
	
		\b Visibility = Expert
	
		\b Selected by : DeviceLinkSelector
	
    */
    GenApi::IInteger &DeviceLinkSpeed;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Controls if the device link throughput limit is active.

	Controls if the device link throughput limit is active. When disabled, lower level throughput limit specific features are expected to control the throughput. When enabled, the device link throughput limit controls the overall throughput.
	
		\b Visibility = Beginner
        
	
		\b Selected by : DeviceLinkSelector
	
    */
    GenApi::IEnumerationT<DeviceLinkThroughputLimitModeEnums > &DeviceLinkThroughputLimitMode;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Limits the average stream interface bandwidth to device link throughput limit bytes per second.

	The Device Link Throughput Limit parameter is of type integer and sets the limit of the average stream interface bandwidth to device link throughput limit bytes per second.
	
		\b Visibility = Beginner
	
		\b Selected by : DeviceLinkSelector
	
    */
    GenApi::IInteger &DeviceLinkThroughputLimit;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Indicates the actual bandwidth the camera will use.

	This value indicates the actual bandwidth (in bytes per second) that the camera will use to transmit image data and chunk data given the current AOI settings, chunk feature settings, and the pixel format setting.
	
		\b Visibility = Expert
	
		\b Selected by : DeviceLinkSelector
	
    */
    GenApi::IInteger &DeviceLinkCurrentThroughput;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Lists the temperature sources available for readout.

	This enumeration lists the temperature sources available for readout.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<DeviceTemperatureSelectorEnums > &DeviceTemperatureSelector;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Shows the current temperature of the selected target in degrees centigrade.

	This float value shows the current temperature of the selected target in degrees centigrade.
	
		\b Visibility = Expert
	
		\b Selected by : DeviceTemperatureSelector
	
    */
    GenApi::IFloat &DeviceTemperature;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief Immediately resets and reboots the device.

	This is a command that immediately resets and reboots the device.
	
		\b Visibility = Guru
	
    */
    GenApi::ICommand &DeviceReset;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &DeviceSFNCVersionMajor;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &DeviceSFNCVersionMinor;
    
    //@}
    

	//! \name DeviceControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Beginner
	
    */
    GenApi::IInteger &DeviceSFNCVersionSubMinor;
    
    //@}
    

	//! \name UserDefinedValueControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Guru
	
    */
    GenApi::IEnumerationT<UserDefinedValueSelectorEnums > &UserDefinedValueSelector;
    
    //@}
    

	//! \name UserDefinedValueControl - 
    //@{
	/*!	
		\brief 

	
	
		\b Visibility = Guru
	
		\b Selected by : UserDefinedValueSelector
	
    */
    GenApi::IInteger &UserDefinedValue;
    
    //@}
    

	//! \name RemoveParameterLimitControl - This category includes items that allow removing the limits of camera parameters
    //@{
	/*!	
		\brief Selects the parameter to configure. Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter

	This enumeration selects the parameter to configure. Selects the parameter to configure. Once a parameter has been selected, all changes made using the Remove Limits feature will be applied to the selected parameter
	
		\b Visibility = Guru
	
    */
    GenApi::IEnumerationT<RemoveParameterLimitSelectorEnums > &RemoveParameterLimitSelector;
    
    //@}
    

	//! \name RemoveParameterLimitControl - This category includes items that allow removing the limits of camera parameters
    //@{
	/*!	
		\brief Removes the factory-set limits of the selected parameter.

	Removes the factory-set limits of the selected parameter. Having removed the factory-set limits you may set the parameter within extended limits. These are only defined by technical restrictions. Note:  Inferior image quality may result.
	
		\b Visibility = Guru
	
		\b Selected by : RemoveParameterLimitSelector
	
    */
    GenApi::IBoolean &RemoveParameterLimit;
    
    //@}
    

	//! \name ExpertFeatureAccess - 
    //@{
	/*!	
		\brief Selects the feature to configure. Once a feature has been selected, all changes made using the feature enable feature will be applied to the selected feature

	Selects the feature to configure. Once a feature has been selected, all changes made using the feature enable feature will be applied to the selected feature
	
		\b Visibility = Guru
	
    */
    GenApi::IEnumerationT<ExpertFeatureAccessSelectorEnums > &ExpertFeatureAccessSelector;
    
    //@}
    

	//! \name ExpertFeatureAccess - 
    //@{
	/*!	
		\brief Sets the key to access the selected feature

	Sets the key to access the selected feature
	
		\b Visibility = Guru
	
		\b Selected by : ExpertFeatureAccessSelector
	
    */
    GenApi::IInteger &ExpertFeatureAccessKey;
    
    //@}
    

	//! \name ExpertFeatureAccess - 
    //@{
	/*!	
		\brief Enable the selected Feature

	Enable the selected Feature
	
		\b Visibility = Guru
	
		\b Selected by : ExpertFeatureAccessSelector
	
    */
    GenApi::IBoolean &ExpertFeatureEnable;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief This feature selects the target file in the device

	The File Selector feature selects the target file in the device.
	
		\b Visibility = Guru
	
    */
    GenApi::IEnumerationT<FileSelectorEnums > &FileSelector;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Selects the target operation for the selected file

	The File Operation Selector feature selects the target operation for the selected file in the device. This Operation is executed when the FileOperationExecute feature is called.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector
	
    */
    GenApi::IEnumerationT<FileOperationSelectorEnums > &FileOperationSelector;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Selects the access mode in which a file is opened

	The File Open Mode feature selects the access mode in which a file is opened in the device.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector
	
    */
    GenApi::IEnumerationT<FileOpenModeEnums > &FileOpenMode;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Defines the intermediate access buffer

	The File Access Buffer feature defines the intermediate access buffer that allows the exchange of data between the device file storage and the application.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector
	
    */
    GenApi::IRegister &FileAccessBuffer;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Controls the mapping between the device file storage and the FileAccessBuffer

	This feature controls the mapping between the device file storage and the FileAccessBuffer.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector, FileOperationSelector
	
    */
    GenApi::IInteger &FileAccessOffset;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Controls the mapping between the device file storage and the FileAccessBuffer

	This feature controls the mapping between the device file storage and the FileAccessBuffer.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector, FileOperationSelector
	
    */
    GenApi::IInteger &FileAccessLength;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Represents the file operation execution status

	The File Operation Status feature represents the file operation execution status.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector, FileOperationSelector
	
    */
    GenApi::IEnumerationT<FileOperationStatusEnums > &FileOperationStatus;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Represents the file operation result

	The File Operation Result feature represents the file operation result. For Read or Write operations, the number of successfully read/written bytes is returned.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector, FileOperationSelector
	
    */
    GenApi::IInteger &FileOperationResult;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Represents the size of the selected file

	The File Size feature represents the size of the selected file in bytes.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector
	
    */
    GenApi::IInteger &FileSize;
    
    //@}
    

	//! \name FileAccessControl - This category includes items used to conduct file operations
    //@{
	/*!	
		\brief Executes the selected operation

	The File Operation Execute feature is the command that executes the operation selected by FileOperationSelector on the selected file.
	
		\b Visibility = Guru
	
		\b Selected by : FileSelector, FileOperationSelector
	
    */
    GenApi::ICommand &FileOperationExecute;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUsbCameraParams_Params(CUsbCameraParams_Params&);

            //! not implemented assignment operator
            CUsbCameraParams_Params& operator=(CUsbCameraParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CUsbCameraParams_Params::CUsbCameraParams_Params(void)
        : SensorWidth( *new GenApi::CIntegerRef() )
        , SensorHeight( *new GenApi::CIntegerRef() )
        , WidthMax( *new GenApi::CIntegerRef() )
        , HeightMax( *new GenApi::CIntegerRef() )
        , Width( *new GenApi::CIntegerRef() )
        , Height( *new GenApi::CIntegerRef() )
        , OffsetX( *new GenApi::CIntegerRef() )
        , OffsetY( *new GenApi::CIntegerRef() )
        , CenterX( *new GenApi::CBooleanRef() )
        , CenterY( *new GenApi::CBooleanRef() )
        , ReverseX( *new GenApi::CBooleanRef() )
        , ReverseY( *new GenApi::CBooleanRef() )
        , BinningHorizontal( *new GenApi::CIntegerRef() )
        , BinningVertical( *new GenApi::CIntegerRef() )
        , PixelFormat( *new GenApi::CEnumerationTRef<PixelFormatEnums>() )
        , PixelSize( *new GenApi::CEnumerationTRef<PixelSizeEnums>() )
        , PixelColorFilter( *new GenApi::CEnumerationTRef<PixelColorFilterEnums>() )
        , PixelDynamicRangeMin( *new GenApi::CIntegerRef() )
        , PixelDynamicRangeMax( *new GenApi::CIntegerRef() )
        , TestImageSelector( *new GenApi::CEnumerationTRef<TestImageSelectorEnums>() )
        , GainAuto( *new GenApi::CEnumerationTRef<GainAutoEnums>() )
        , GainSelector( *new GenApi::CEnumerationTRef<GainSelectorEnums>() )
        , Gain( *new GenApi::CFloatRef() )
        , BlackLevelSelector( *new GenApi::CEnumerationTRef<BlackLevelSelectorEnums>() )
        , BlackLevel( *new GenApi::CFloatRef() )
        , Gamma( *new GenApi::CFloatRef() )
        , DigitalShift( *new GenApi::CIntegerRef() )
        , LightSourcePreset( *new GenApi::CEnumerationTRef<LightSourcePresetEnums>() )
        , BalanceWhiteAuto( *new GenApi::CEnumerationTRef<BalanceWhiteAutoEnums>() )
        , BalanceRatioSelector( *new GenApi::CEnumerationTRef<BalanceRatioSelectorEnums>() )
        , BalanceRatio( *new GenApi::CFloatRef() )
        , ColorAdjustmentSelector( *new GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums>() )
        , ColorAdjustmentHue( *new GenApi::CFloatRef() )
        , ColorAdjustmentSaturation( *new GenApi::CFloatRef() )
        , ColorTransformationSelector( *new GenApi::CEnumerationTRef<ColorTransformationSelectorEnums>() )
        , ColorTransformationValueSelector( *new GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums>() )
        , ColorTransformationValue( *new GenApi::CFloatRef() )
        , AcquisitionMode( *new GenApi::CEnumerationTRef<AcquisitionModeEnums>() )
        , AcquisitionStart( *new GenApi::CCommandRef() )
        , AcquisitionStop( *new GenApi::CCommandRef() )
        , ShutterMode( *new GenApi::CEnumerationTRef<ShutterModeEnums>() )
        , ExposureAuto( *new GenApi::CEnumerationTRef<ExposureAutoEnums>() )
        , ExposureMode( *new GenApi::CEnumerationTRef<ExposureModeEnums>() )
        , ExposureTime( *new GenApi::CFloatRef() )
        , ExposureOverlapTimeMax( *new GenApi::CFloatRef() )
        , AcquisitionBurstFrameCount( *new GenApi::CIntegerRef() )
        , TriggerSelector( *new GenApi::CEnumerationTRef<TriggerSelectorEnums>() )
        , TriggerMode( *new GenApi::CEnumerationTRef<TriggerModeEnums>() )
        , TriggerSoftware( *new GenApi::CCommandRef() )
        , TriggerSource( *new GenApi::CEnumerationTRef<TriggerSourceEnums>() )
        , TriggerActivation( *new GenApi::CEnumerationTRef<TriggerActivationEnums>() )
        , TriggerDelay( *new GenApi::CFloatRef() )
        , AcquisitionFrameRateEnable( *new GenApi::CBooleanRef() )
        , AcquisitionFrameRate( *new GenApi::CFloatRef() )
        , ResultingFrameRate( *new GenApi::CFloatRef() )
        , SensorReadoutTime( *new GenApi::CFloatRef() )
        , AcquisitionStatusSelector( *new GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums>() )
        , AcquisitionStatus( *new GenApi::CBooleanRef() )
        , AutoTargetBrightness( *new GenApi::CFloatRef() )
        , AutoFunctionProfile( *new GenApi::CEnumerationTRef<AutoFunctionProfileEnums>() )
        , AutoGainLowerLimit( *new GenApi::CFloatRef() )
        , AutoGainUpperLimit( *new GenApi::CFloatRef() )
        , AutoExposureTimeLowerLimit( *new GenApi::CFloatRef() )
        , AutoExposureTimeUpperLimit( *new GenApi::CFloatRef() )
        , AutoFunctionAOISelector( *new GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums>() )
        , AutoFunctionAOIWidth( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIHeight( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIOffsetX( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIOffsetY( *new GenApi::CIntegerRef() )
        , AutoFunctionAOIUseBrightness( *new GenApi::CBooleanRef() )
        , AutoFunctionAOIUseWhiteBalance( *new GenApi::CBooleanRef() )
        , LUTSelector( *new GenApi::CEnumerationTRef<LUTSelectorEnums>() )
        , LUTEnable( *new GenApi::CBooleanRef() )
        , LUTIndex( *new GenApi::CIntegerRef() )
        , LUTValue( *new GenApi::CIntegerRef() )
        , LUTValueAll( *new GenApi::CRegisterRef() )
        , LineSelector( *new GenApi::CEnumerationTRef<LineSelectorEnums>() )
        , LineMode( *new GenApi::CEnumerationTRef<LineModeEnums>() )
        , LineFormat( *new GenApi::CEnumerationTRef<LineFormatEnums>() )
        , LineLogic( *new GenApi::CEnumerationTRef<LineLogicEnums>() )
        , LineSource( *new GenApi::CEnumerationTRef<LineSourceEnums>() )
        , LineInverter( *new GenApi::CBooleanRef() )
        , LineDebouncerTime( *new GenApi::CFloatRef() )
        , LineMinimumOutputPulseWidth( *new GenApi::CFloatRef() )
        , LineOverloadStatus( *new GenApi::CBooleanRef() )
        , LineStatus( *new GenApi::CBooleanRef() )
        , LineStatusAll( *new GenApi::CIntegerRef() )
        , UserOutputSelector( *new GenApi::CEnumerationTRef<UserOutputSelectorEnums>() )
        , UserOutputValue( *new GenApi::CBooleanRef() )
        , UserOutputValueAll( *new GenApi::CIntegerRef() )
        , CounterSelector( *new GenApi::CEnumerationTRef<CounterSelectorEnums>() )
        , CounterEventSource( *new GenApi::CEnumerationTRef<CounterEventSourceEnums>() )
        , CounterResetSource( *new GenApi::CEnumerationTRef<CounterResetSourceEnums>() )
        , CounterResetActivation( *new GenApi::CEnumerationTRef<CounterResetActivationEnums>() )
        , CounterReset( *new GenApi::CCommandRef() )
        , TimerSelector( *new GenApi::CEnumerationTRef<TimerSelectorEnums>() )
        , TimerDuration( *new GenApi::CFloatRef() )
        , TimerDelay( *new GenApi::CFloatRef() )
        , TimerTriggerSource( *new GenApi::CEnumerationTRef<TimerTriggerSourceEnums>() )
        , UserSetSelector( *new GenApi::CEnumerationTRef<UserSetSelectorEnums>() )
        , UserSetLoad( *new GenApi::CCommandRef() )
        , UserSetSave( *new GenApi::CCommandRef() )
        , UserSetDefault( *new GenApi::CEnumerationTRef<UserSetDefaultEnums>() )
        , ChunkModeActive( *new GenApi::CBooleanRef() )
        , ChunkSelector( *new GenApi::CEnumerationTRef<ChunkSelectorEnums>() )
        , ChunkEnable( *new GenApi::CBooleanRef() )
        , ChunkGainSelector( *new GenApi::CEnumerationTRef<ChunkGainSelectorEnums>() )
        , ChunkGain( *new GenApi::CFloatRef() )
        , ChunkExposureTime( *new GenApi::CFloatRef() )
        , ChunkTimestamp( *new GenApi::CIntegerRef() )
        , ChunkPayloadCRC16( *new GenApi::CIntegerRef() )
        , ChunkCounterSelector( *new GenApi::CEnumerationTRef<ChunkCounterSelectorEnums>() )
        , ChunkCounterValue( *new GenApi::CIntegerRef() )
        , EventSelector( *new GenApi::CEnumerationTRef<EventSelectorEnums>() )
        , EventNotification( *new GenApi::CEnumerationTRef<EventNotificationEnums>() )
        , EventExposureEnd( *new GenApi::CIntegerRef() )
        , EventExposureEndTimestamp( *new GenApi::CIntegerRef() )
        , EventExposureEndFrameID( *new GenApi::CIntegerRef() )
        , EventFrameStart( *new GenApi::CIntegerRef() )
        , EventFrameStartTimestamp( *new GenApi::CIntegerRef() )
        , EventFrameStartFrameID( *new GenApi::CIntegerRef() )
        , EventFrameBurstStart( *new GenApi::CIntegerRef() )
        , EventFrameBurstStartTimestamp( *new GenApi::CIntegerRef() )
        , EventFrameBurstStartFrameID( *new GenApi::CIntegerRef() )
        , EventFrameStartOvertrigger( *new GenApi::CIntegerRef() )
        , EventFrameStartOvertriggerTimestamp( *new GenApi::CIntegerRef() )
        , EventFrameStartOvertriggerFrameID( *new GenApi::CIntegerRef() )
        , EventFrameBurstStartOvertrigger( *new GenApi::CIntegerRef() )
        , EventFrameBurstStartOvertriggerTimestamp( *new GenApi::CIntegerRef() )
        , EventFrameBurstStartOvertriggerFrameID( *new GenApi::CIntegerRef() )
        , PayloadSize( *new GenApi::CIntegerRef() )
        , BslUSBSpeedMode( *new GenApi::CEnumerationTRef<BslUSBSpeedModeEnums>() )
        , SIPayloadTransferSize( *new GenApi::CIntegerRef() )
        , SIPayloadTransferCount( *new GenApi::CIntegerRef() )
        , SIPayloadFinalTransfer1Size( *new GenApi::CIntegerRef() )
        , SIPayloadFinalTransfer2Size( *new GenApi::CIntegerRef() )
        , TestPendingAck( *new GenApi::CIntegerRef() )
        , DeviceVendorName( *new GenApi::CStringRef() )
        , DeviceModelName( *new GenApi::CStringRef() )
        , DeviceManufacturerInfo( *new GenApi::CStringRef() )
        , DeviceVersion( *new GenApi::CStringRef() )
        , DeviceFirmwareVersion( *new GenApi::CStringRef() )
        , DeviceSerialNumber( *new GenApi::CStringRef() )
        , DeviceScanType( *new GenApi::CEnumerationTRef<DeviceScanTypeEnums>() )
        , DeviceUserID( *new GenApi::CStringRef() )
        , DeviceLinkSelector( *new GenApi::CIntegerRef() )
        , DeviceLinkSpeed( *new GenApi::CIntegerRef() )
        , DeviceLinkThroughputLimitMode( *new GenApi::CEnumerationTRef<DeviceLinkThroughputLimitModeEnums>() )
        , DeviceLinkThroughputLimit( *new GenApi::CIntegerRef() )
        , DeviceLinkCurrentThroughput( *new GenApi::CIntegerRef() )
        , DeviceTemperatureSelector( *new GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums>() )
        , DeviceTemperature( *new GenApi::CFloatRef() )
        , DeviceReset( *new GenApi::CCommandRef() )
        , DeviceSFNCVersionMajor( *new GenApi::CIntegerRef() )
        , DeviceSFNCVersionMinor( *new GenApi::CIntegerRef() )
        , DeviceSFNCVersionSubMinor( *new GenApi::CIntegerRef() )
        , UserDefinedValueSelector( *new GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums>() )
        , UserDefinedValue( *new GenApi::CIntegerRef() )
        , RemoveParameterLimitSelector( *new GenApi::CEnumerationTRef<RemoveParameterLimitSelectorEnums>() )
        , RemoveParameterLimit( *new GenApi::CBooleanRef() )
        , ExpertFeatureAccessSelector( *new GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums>() )
        , ExpertFeatureAccessKey( *new GenApi::CIntegerRef() )
        , ExpertFeatureEnable( *new GenApi::CBooleanRef() )
        , FileSelector( *new GenApi::CEnumerationTRef<FileSelectorEnums>() )
        , FileOperationSelector( *new GenApi::CEnumerationTRef<FileOperationSelectorEnums>() )
        , FileOpenMode( *new GenApi::CEnumerationTRef<FileOpenModeEnums>() )
        , FileAccessBuffer( *new GenApi::CRegisterRef() )
        , FileAccessOffset( *new GenApi::CIntegerRef() )
        , FileAccessLength( *new GenApi::CIntegerRef() )
        , FileOperationStatus( *new GenApi::CEnumerationTRef<FileOperationStatusEnums>() )
        , FileOperationResult( *new GenApi::CIntegerRef() )
        , FileSize( *new GenApi::CIntegerRef() )
        , FileOperationExecute( *new GenApi::CCommandRef() )
        
    {
    }

    inline CUsbCameraParams_Params::~CUsbCameraParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&SensorWidth );
        delete static_cast < GenApi::CIntegerRef*> (&SensorHeight );
        delete static_cast < GenApi::CIntegerRef*> (&WidthMax );
        delete static_cast < GenApi::CIntegerRef*> (&HeightMax );
        delete static_cast < GenApi::CIntegerRef*> (&Width );
        delete static_cast < GenApi::CIntegerRef*> (&Height );
        delete static_cast < GenApi::CIntegerRef*> (&OffsetX );
        delete static_cast < GenApi::CIntegerRef*> (&OffsetY );
        delete static_cast < GenApi::CBooleanRef*> (&CenterX );
        delete static_cast < GenApi::CBooleanRef*> (&CenterY );
        delete static_cast < GenApi::CBooleanRef*> (&ReverseX );
        delete static_cast < GenApi::CBooleanRef*> (&ReverseY );
        delete static_cast < GenApi::CIntegerRef*> (&BinningHorizontal );
        delete static_cast < GenApi::CIntegerRef*> (&BinningVertical );
        delete static_cast < GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat );
        delete static_cast < GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize );
        delete static_cast < GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter );
        delete static_cast < GenApi::CIntegerRef*> (&PixelDynamicRangeMin );
        delete static_cast < GenApi::CIntegerRef*> (&PixelDynamicRangeMax );
        delete static_cast < GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector );
        delete static_cast < GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto );
        delete static_cast < GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector );
        delete static_cast < GenApi::CFloatRef*> (&Gain );
        delete static_cast < GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector );
        delete static_cast < GenApi::CFloatRef*> (&BlackLevel );
        delete static_cast < GenApi::CFloatRef*> (&Gamma );
        delete static_cast < GenApi::CIntegerRef*> (&DigitalShift );
        delete static_cast < GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset );
        delete static_cast < GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto );
        delete static_cast < GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector );
        delete static_cast < GenApi::CFloatRef*> (&BalanceRatio );
        delete static_cast < GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector );
        delete static_cast < GenApi::CFloatRef*> (&ColorAdjustmentHue );
        delete static_cast < GenApi::CFloatRef*> (&ColorAdjustmentSaturation );
        delete static_cast < GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector );
        delete static_cast < GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector );
        delete static_cast < GenApi::CFloatRef*> (&ColorTransformationValue );
        delete static_cast < GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode );
        delete static_cast < GenApi::CCommandRef*> (&AcquisitionStart );
        delete static_cast < GenApi::CCommandRef*> (&AcquisitionStop );
        delete static_cast < GenApi::CEnumerationTRef<ShutterModeEnums> *> (&ShutterMode );
        delete static_cast < GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto );
        delete static_cast < GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode );
        delete static_cast < GenApi::CFloatRef*> (&ExposureTime );
        delete static_cast < GenApi::CFloatRef*> (&ExposureOverlapTimeMax );
        delete static_cast < GenApi::CIntegerRef*> (&AcquisitionBurstFrameCount );
        delete static_cast < GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector );
        delete static_cast < GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode );
        delete static_cast < GenApi::CCommandRef*> (&TriggerSoftware );
        delete static_cast < GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource );
        delete static_cast < GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation );
        delete static_cast < GenApi::CFloatRef*> (&TriggerDelay );
        delete static_cast < GenApi::CBooleanRef*> (&AcquisitionFrameRateEnable );
        delete static_cast < GenApi::CFloatRef*> (&AcquisitionFrameRate );
        delete static_cast < GenApi::CFloatRef*> (&ResultingFrameRate );
        delete static_cast < GenApi::CFloatRef*> (&SensorReadoutTime );
        delete static_cast < GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector );
        delete static_cast < GenApi::CBooleanRef*> (&AcquisitionStatus );
        delete static_cast < GenApi::CFloatRef*> (&AutoTargetBrightness );
        delete static_cast < GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile );
        delete static_cast < GenApi::CFloatRef*> (&AutoGainLowerLimit );
        delete static_cast < GenApi::CFloatRef*> (&AutoGainUpperLimit );
        delete static_cast < GenApi::CFloatRef*> (&AutoExposureTimeLowerLimit );
        delete static_cast < GenApi::CFloatRef*> (&AutoExposureTimeUpperLimit );
        delete static_cast < GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIWidth );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIHeight );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetX );
        delete static_cast < GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetY );
        delete static_cast < GenApi::CBooleanRef*> (&AutoFunctionAOIUseBrightness );
        delete static_cast < GenApi::CBooleanRef*> (&AutoFunctionAOIUseWhiteBalance );
        delete static_cast < GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector );
        delete static_cast < GenApi::CBooleanRef*> (&LUTEnable );
        delete static_cast < GenApi::CIntegerRef*> (&LUTIndex );
        delete static_cast < GenApi::CIntegerRef*> (&LUTValue );
        delete static_cast < GenApi::CRegisterRef*> (&LUTValueAll );
        delete static_cast < GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector );
        delete static_cast < GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode );
        delete static_cast < GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat );
        delete static_cast < GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic );
        delete static_cast < GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource );
        delete static_cast < GenApi::CBooleanRef*> (&LineInverter );
        delete static_cast < GenApi::CFloatRef*> (&LineDebouncerTime );
        delete static_cast < GenApi::CFloatRef*> (&LineMinimumOutputPulseWidth );
        delete static_cast < GenApi::CBooleanRef*> (&LineOverloadStatus );
        delete static_cast < GenApi::CBooleanRef*> (&LineStatus );
        delete static_cast < GenApi::CIntegerRef*> (&LineStatusAll );
        delete static_cast < GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector );
        delete static_cast < GenApi::CBooleanRef*> (&UserOutputValue );
        delete static_cast < GenApi::CIntegerRef*> (&UserOutputValueAll );
        delete static_cast < GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector );
        delete static_cast < GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource );
        delete static_cast < GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource );
        delete static_cast < GenApi::CEnumerationTRef<CounterResetActivationEnums> *> (&CounterResetActivation );
        delete static_cast < GenApi::CCommandRef*> (&CounterReset );
        delete static_cast < GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector );
        delete static_cast < GenApi::CFloatRef*> (&TimerDuration );
        delete static_cast < GenApi::CFloatRef*> (&TimerDelay );
        delete static_cast < GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource );
        delete static_cast < GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector );
        delete static_cast < GenApi::CCommandRef*> (&UserSetLoad );
        delete static_cast < GenApi::CCommandRef*> (&UserSetSave );
        delete static_cast < GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault );
        delete static_cast < GenApi::CBooleanRef*> (&ChunkModeActive );
        delete static_cast < GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector );
        delete static_cast < GenApi::CBooleanRef*> (&ChunkEnable );
        delete static_cast < GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector );
        delete static_cast < GenApi::CFloatRef*> (&ChunkGain );
        delete static_cast < GenApi::CFloatRef*> (&ChunkExposureTime );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkPayloadCRC16 );
        delete static_cast < GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkCounterValue );
        delete static_cast < GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector );
        delete static_cast < GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification );
        delete static_cast < GenApi::CIntegerRef*> (&EventExposureEnd );
        delete static_cast < GenApi::CIntegerRef*> (&EventExposureEndTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&EventExposureEndFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameStart );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameStartTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameStartFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameBurstStart );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameBurstStartTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameBurstStartFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameStartOvertrigger );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameStartOvertriggerTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameStartOvertriggerFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameBurstStartOvertrigger );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameBurstStartOvertriggerTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&EventFrameBurstStartOvertriggerFrameID );
        delete static_cast < GenApi::CIntegerRef*> (&PayloadSize );
        delete static_cast < GenApi::CEnumerationTRef<BslUSBSpeedModeEnums> *> (&BslUSBSpeedMode );
        delete static_cast < GenApi::CIntegerRef*> (&SIPayloadTransferSize );
        delete static_cast < GenApi::CIntegerRef*> (&SIPayloadTransferCount );
        delete static_cast < GenApi::CIntegerRef*> (&SIPayloadFinalTransfer1Size );
        delete static_cast < GenApi::CIntegerRef*> (&SIPayloadFinalTransfer2Size );
        delete static_cast < GenApi::CIntegerRef*> (&TestPendingAck );
        delete static_cast < GenApi::CStringRef*> (&DeviceVendorName );
        delete static_cast < GenApi::CStringRef*> (&DeviceModelName );
        delete static_cast < GenApi::CStringRef*> (&DeviceManufacturerInfo );
        delete static_cast < GenApi::CStringRef*> (&DeviceVersion );
        delete static_cast < GenApi::CStringRef*> (&DeviceFirmwareVersion );
        delete static_cast < GenApi::CStringRef*> (&DeviceSerialNumber );
        delete static_cast < GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType );
        delete static_cast < GenApi::CStringRef*> (&DeviceUserID );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceLinkSelector );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceLinkSpeed );
        delete static_cast < GenApi::CEnumerationTRef<DeviceLinkThroughputLimitModeEnums> *> (&DeviceLinkThroughputLimitMode );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceLinkThroughputLimit );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceLinkCurrentThroughput );
        delete static_cast < GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums> *> (&DeviceTemperatureSelector );
        delete static_cast < GenApi::CFloatRef*> (&DeviceTemperature );
        delete static_cast < GenApi::CCommandRef*> (&DeviceReset );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceSFNCVersionMajor );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceSFNCVersionMinor );
        delete static_cast < GenApi::CIntegerRef*> (&DeviceSFNCVersionSubMinor );
        delete static_cast < GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector );
        delete static_cast < GenApi::CIntegerRef*> (&UserDefinedValue );
        delete static_cast < GenApi::CEnumerationTRef<RemoveParameterLimitSelectorEnums> *> (&RemoveParameterLimitSelector );
        delete static_cast < GenApi::CBooleanRef*> (&RemoveParameterLimit );
        delete static_cast < GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector );
        delete static_cast < GenApi::CIntegerRef*> (&ExpertFeatureAccessKey );
        delete static_cast < GenApi::CBooleanRef*> (&ExpertFeatureEnable );
        delete static_cast < GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector );
        delete static_cast < GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector );
        delete static_cast < GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode );
        delete static_cast < GenApi::CRegisterRef*> (&FileAccessBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&FileAccessOffset );
        delete static_cast < GenApi::CIntegerRef*> (&FileAccessLength );
        delete static_cast < GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus );
        delete static_cast < GenApi::CIntegerRef*> (&FileOperationResult );
        delete static_cast < GenApi::CIntegerRef*> (&FileSize );
        delete static_cast < GenApi::CCommandRef*> (&FileOperationExecute );
        
    }

    inline void CUsbCameraParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&SensorWidth )->SetReference(_Ptr->GetNode("SensorWidth"));
    static_cast<GenApi::CIntegerRef*> (&SensorHeight )->SetReference(_Ptr->GetNode("SensorHeight"));
    static_cast<GenApi::CIntegerRef*> (&WidthMax )->SetReference(_Ptr->GetNode("WidthMax"));
    static_cast<GenApi::CIntegerRef*> (&HeightMax )->SetReference(_Ptr->GetNode("HeightMax"));
    static_cast<GenApi::CIntegerRef*> (&Width )->SetReference(_Ptr->GetNode("Width"));
    static_cast<GenApi::CIntegerRef*> (&Height )->SetReference(_Ptr->GetNode("Height"));
    static_cast<GenApi::CIntegerRef*> (&OffsetX )->SetReference(_Ptr->GetNode("OffsetX"));
    static_cast<GenApi::CIntegerRef*> (&OffsetY )->SetReference(_Ptr->GetNode("OffsetY"));
    static_cast<GenApi::CBooleanRef*> (&CenterX )->SetReference(_Ptr->GetNode("CenterX"));
    static_cast<GenApi::CBooleanRef*> (&CenterY )->SetReference(_Ptr->GetNode("CenterY"));
    static_cast<GenApi::CBooleanRef*> (&ReverseX )->SetReference(_Ptr->GetNode("ReverseX"));
    static_cast<GenApi::CBooleanRef*> (&ReverseY )->SetReference(_Ptr->GetNode("ReverseY"));
    static_cast<GenApi::CIntegerRef*> (&BinningHorizontal )->SetReference(_Ptr->GetNode("BinningHorizontal"));
    static_cast<GenApi::CIntegerRef*> (&BinningVertical )->SetReference(_Ptr->GetNode("BinningVertical"));
    static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetReference(_Ptr->GetNode("PixelFormat"));
    static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetNumEnums(18);
	static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono8, "Mono8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono12, "Mono12" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_Mono12p, "Mono12p" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR8, "BayerGR8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG8, "BayerRG8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB8, "BayerGB8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG8, "BayerBG8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR12, "BayerGR12" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGR12p, "BayerGR12p" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG12, "BayerRG12" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerRG12p, "BayerRG12p" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB12, "BayerGB12" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerGB12p, "BayerGB12p" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG12, "BayerBG12" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BayerBG12p, "BayerBG12p" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_RGB8, "RGB8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_BGR8, "BGR8" );		static_cast<GenApi::CEnumerationTRef<PixelFormatEnums> *> (&PixelFormat )->SetEnumReference( PixelFormat_YCbCr422_8, "YCbCr422_8" );		static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetReference(_Ptr->GetNode("PixelSize"));
    static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetNumEnums(4);
	static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp8, "Bpp8" );		static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp12, "Bpp12" );		static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp16, "Bpp16" );		static_cast<GenApi::CEnumerationTRef<PixelSizeEnums> *> (&PixelSize )->SetEnumReference( PixelSize_Bpp24, "Bpp24" );		static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetReference(_Ptr->GetNode("PixelColorFilter"));
    static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetNumEnums(5);
	static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_None, "None" );		static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_BayerRG, "BayerRG" );		static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_BayerGB, "BayerGB" );		static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_BayerGR, "BayerGR" );		static_cast<GenApi::CEnumerationTRef<PixelColorFilterEnums> *> (&PixelColorFilter )->SetEnumReference( PixelColorFilter_BayerBG, "BayerBG" );		static_cast<GenApi::CIntegerRef*> (&PixelDynamicRangeMin )->SetReference(_Ptr->GetNode("PixelDynamicRangeMin"));
    static_cast<GenApi::CIntegerRef*> (&PixelDynamicRangeMax )->SetReference(_Ptr->GetNode("PixelDynamicRangeMax"));
    static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetReference(_Ptr->GetNode("TestImageSelector"));
    static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetNumEnums(7);
	static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage1, "Testimage1" );		static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage2, "Testimage2" );		static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage3, "Testimage3" );		static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage4, "Testimage4" );		static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage5, "Testimage5" );		static_cast<GenApi::CEnumerationTRef<TestImageSelectorEnums> *> (&TestImageSelector )->SetEnumReference( TestImageSelector_Testimage6, "Testimage6" );		static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetReference(_Ptr->GetNode("GainAuto"));
    static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetEnumReference( GainAuto_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetEnumReference( GainAuto_Once, "Once" );		static_cast<GenApi::CEnumerationTRef<GainAutoEnums> *> (&GainAuto )->SetEnumReference( GainAuto_Continuous, "Continuous" );		static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetReference(_Ptr->GetNode("GainSelector"));
    static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<GainSelectorEnums> *> (&GainSelector )->SetEnumReference( GainSelector_All, "All" );		static_cast<GenApi::CFloatRef*> (&Gain )->SetReference(_Ptr->GetNode("Gain"));
    static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetReference(_Ptr->GetNode("BlackLevelSelector"));
    static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<BlackLevelSelectorEnums> *> (&BlackLevelSelector )->SetEnumReference( BlackLevelSelector_All, "All" );		static_cast<GenApi::CFloatRef*> (&BlackLevel )->SetReference(_Ptr->GetNode("BlackLevel"));
    static_cast<GenApi::CFloatRef*> (&Gamma )->SetReference(_Ptr->GetNode("Gamma"));
    static_cast<GenApi::CIntegerRef*> (&DigitalShift )->SetReference(_Ptr->GetNode("DigitalShift"));
    static_cast<GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset )->SetReference(_Ptr->GetNode("LightSourcePreset"));
    static_cast<GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset )->SetNumEnums(4);
	static_cast<GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset )->SetEnumReference( LightSourcePreset_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset )->SetEnumReference( LightSourcePreset_Daylight5000K, "Daylight5000K" );		static_cast<GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset )->SetEnumReference( LightSourcePreset_Daylight6500K, "Daylight6500K" );		static_cast<GenApi::CEnumerationTRef<LightSourcePresetEnums> *> (&LightSourcePreset )->SetEnumReference( LightSourcePreset_Tungsten2800K, "Tungsten2800K" );		static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetReference(_Ptr->GetNode("BalanceWhiteAuto"));
    static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetEnumReference( BalanceWhiteAuto_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetEnumReference( BalanceWhiteAuto_Once, "Once" );		static_cast<GenApi::CEnumerationTRef<BalanceWhiteAutoEnums> *> (&BalanceWhiteAuto )->SetEnumReference( BalanceWhiteAuto_Continuous, "Continuous" );		static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetReference(_Ptr->GetNode("BalanceRatioSelector"));
    static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetEnumReference( BalanceRatioSelector_Red, "Red" );		static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetEnumReference( BalanceRatioSelector_Green, "Green" );		static_cast<GenApi::CEnumerationTRef<BalanceRatioSelectorEnums> *> (&BalanceRatioSelector )->SetEnumReference( BalanceRatioSelector_Blue, "Blue" );		static_cast<GenApi::CFloatRef*> (&BalanceRatio )->SetReference(_Ptr->GetNode("BalanceRatio"));
    static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetReference(_Ptr->GetNode("ColorAdjustmentSelector"));
    static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetNumEnums(6);
	static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Red, "Red" );		static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Yellow, "Yellow" );		static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Green, "Green" );		static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Cyan, "Cyan" );		static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Blue, "Blue" );		static_cast<GenApi::CEnumerationTRef<ColorAdjustmentSelectorEnums> *> (&ColorAdjustmentSelector )->SetEnumReference( ColorAdjustmentSelector_Magenta, "Magenta" );		static_cast<GenApi::CFloatRef*> (&ColorAdjustmentHue )->SetReference(_Ptr->GetNode("ColorAdjustmentHue"));
    static_cast<GenApi::CFloatRef*> (&ColorAdjustmentSaturation )->SetReference(_Ptr->GetNode("ColorAdjustmentSaturation"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetReference(_Ptr->GetNode("ColorTransformationSelector"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<ColorTransformationSelectorEnums> *> (&ColorTransformationSelector )->SetEnumReference( ColorTransformationSelector_RGBtoRGB, "RGBtoRGB" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetReference(_Ptr->GetNode("ColorTransformationValueSelector"));
    static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetNumEnums(9);
	static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain00, "Gain00" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain01, "Gain01" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain02, "Gain02" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain10, "Gain10" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain11, "Gain11" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain12, "Gain12" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain20, "Gain20" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain21, "Gain21" );		static_cast<GenApi::CEnumerationTRef<ColorTransformationValueSelectorEnums> *> (&ColorTransformationValueSelector )->SetEnumReference( ColorTransformationValueSelector_Gain22, "Gain22" );		static_cast<GenApi::CFloatRef*> (&ColorTransformationValue )->SetReference(_Ptr->GetNode("ColorTransformationValue"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetReference(_Ptr->GetNode("AcquisitionMode"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetEnumReference( AcquisitionMode_SingleFrame, "SingleFrame" );		static_cast<GenApi::CEnumerationTRef<AcquisitionModeEnums> *> (&AcquisitionMode )->SetEnumReference( AcquisitionMode_Continuous, "Continuous" );		static_cast<GenApi::CCommandRef*> (&AcquisitionStart )->SetReference(_Ptr->GetNode("AcquisitionStart"));
    static_cast<GenApi::CCommandRef*> (&AcquisitionStop )->SetReference(_Ptr->GetNode("AcquisitionStop"));
    static_cast<GenApi::CEnumerationTRef<ShutterModeEnums> *> (&ShutterMode )->SetReference(_Ptr->GetNode("ShutterMode"));
    static_cast<GenApi::CEnumerationTRef<ShutterModeEnums> *> (&ShutterMode )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<ShutterModeEnums> *> (&ShutterMode )->SetEnumReference( ShutterMode_Global, "Global" );		static_cast<GenApi::CEnumerationTRef<ShutterModeEnums> *> (&ShutterMode )->SetEnumReference( ShutterMode_Rolling, "Rolling" );		static_cast<GenApi::CEnumerationTRef<ShutterModeEnums> *> (&ShutterMode )->SetEnumReference( ShutterMode_GlobalResetRelease, "GlobalResetRelease" );		static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetReference(_Ptr->GetNode("ExposureAuto"));
    static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetEnumReference( ExposureAuto_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetEnumReference( ExposureAuto_Once, "Once" );		static_cast<GenApi::CEnumerationTRef<ExposureAutoEnums> *> (&ExposureAuto )->SetEnumReference( ExposureAuto_Continuous, "Continuous" );		static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetReference(_Ptr->GetNode("ExposureMode"));
    static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetEnumReference( ExposureMode_Timed, "Timed" );		static_cast<GenApi::CEnumerationTRef<ExposureModeEnums> *> (&ExposureMode )->SetEnumReference( ExposureMode_TriggerWidth, "TriggerWidth" );		static_cast<GenApi::CFloatRef*> (&ExposureTime )->SetReference(_Ptr->GetNode("ExposureTime"));
    static_cast<GenApi::CFloatRef*> (&ExposureOverlapTimeMax )->SetReference(_Ptr->GetNode("ExposureOverlapTimeMax"));
    static_cast<GenApi::CIntegerRef*> (&AcquisitionBurstFrameCount )->SetReference(_Ptr->GetNode("AcquisitionBurstFrameCount"));
    static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetReference(_Ptr->GetNode("TriggerSelector"));
    static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetEnumReference( TriggerSelector_FrameBurstStart, "FrameBurstStart" );		static_cast<GenApi::CEnumerationTRef<TriggerSelectorEnums> *> (&TriggerSelector )->SetEnumReference( TriggerSelector_FrameStart, "FrameStart" );		static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetReference(_Ptr->GetNode("TriggerMode"));
    static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetEnumReference( TriggerMode_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<TriggerModeEnums> *> (&TriggerMode )->SetEnumReference( TriggerMode_On, "On" );		static_cast<GenApi::CCommandRef*> (&TriggerSoftware )->SetReference(_Ptr->GetNode("TriggerSoftware"));
    static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetReference(_Ptr->GetNode("TriggerSource"));
    static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetNumEnums(5);
	static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Software, "Software" );		static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line1, "Line1" );		static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line2, "Line2" );		static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line3, "Line3" );		static_cast<GenApi::CEnumerationTRef<TriggerSourceEnums> *> (&TriggerSource )->SetEnumReference( TriggerSource_Line4, "Line4" );		static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetReference(_Ptr->GetNode("TriggerActivation"));
    static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetNumEnums(5);
	static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_RisingEdge, "RisingEdge" );		static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_FallingEdge, "FallingEdge" );		static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_AnyEdge, "AnyEdge" );		static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_LevelHigh, "LevelHigh" );		static_cast<GenApi::CEnumerationTRef<TriggerActivationEnums> *> (&TriggerActivation )->SetEnumReference( TriggerActivation_LevelLow, "LevelLow" );		static_cast<GenApi::CFloatRef*> (&TriggerDelay )->SetReference(_Ptr->GetNode("TriggerDelay"));
    static_cast<GenApi::CBooleanRef*> (&AcquisitionFrameRateEnable )->SetReference(_Ptr->GetNode("AcquisitionFrameRateEnable"));
    static_cast<GenApi::CFloatRef*> (&AcquisitionFrameRate )->SetReference(_Ptr->GetNode("AcquisitionFrameRate"));
    static_cast<GenApi::CFloatRef*> (&ResultingFrameRate )->SetReference(_Ptr->GetNode("ResultingFrameRate"));
    static_cast<GenApi::CFloatRef*> (&SensorReadoutTime )->SetReference(_Ptr->GetNode("SensorReadoutTime"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetReference(_Ptr->GetNode("AcquisitionStatusSelector"));
    static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetNumEnums(7);
	static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameBurstTriggerWait, "FrameBurstTriggerWait" );		static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameBurstTriggerActive, "FrameBurstTriggerActive" );		static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameBurstTriggerTransfer, "FrameBurstTriggerTransfer" );		static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameTriggerWait, "FrameTriggerWait" );		static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameActive, "FrameActive" );		static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_FrameTransfer, "FrameTransfer" );		static_cast<GenApi::CEnumerationTRef<AcquisitionStatusSelectorEnums> *> (&AcquisitionStatusSelector )->SetEnumReference( AcquisitionStatusSelector_ExposureActive, "ExposureActive" );		static_cast<GenApi::CBooleanRef*> (&AcquisitionStatus )->SetReference(_Ptr->GetNode("AcquisitionStatus"));
    static_cast<GenApi::CFloatRef*> (&AutoTargetBrightness )->SetReference(_Ptr->GetNode("AutoTargetBrightness"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetReference(_Ptr->GetNode("AutoFunctionProfile"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetEnumReference( AutoFunctionProfile_MinimizeGain, "MinimizeGain" );		static_cast<GenApi::CEnumerationTRef<AutoFunctionProfileEnums> *> (&AutoFunctionProfile )->SetEnumReference( AutoFunctionProfile_MinimizeExposureTime, "MinimizeExposureTime" );		static_cast<GenApi::CFloatRef*> (&AutoGainLowerLimit )->SetReference(_Ptr->GetNode("AutoGainLowerLimit"));
    static_cast<GenApi::CFloatRef*> (&AutoGainUpperLimit )->SetReference(_Ptr->GetNode("AutoGainUpperLimit"));
    static_cast<GenApi::CFloatRef*> (&AutoExposureTimeLowerLimit )->SetReference(_Ptr->GetNode("AutoExposureTimeLowerLimit"));
    static_cast<GenApi::CFloatRef*> (&AutoExposureTimeUpperLimit )->SetReference(_Ptr->GetNode("AutoExposureTimeUpperLimit"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetReference(_Ptr->GetNode("AutoFunctionAOISelector"));
    static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetEnumReference( AutoFunctionAOISelector_AOI1, "AOI1" );		static_cast<GenApi::CEnumerationTRef<AutoFunctionAOISelectorEnums> *> (&AutoFunctionAOISelector )->SetEnumReference( AutoFunctionAOISelector_AOI2, "AOI2" );		static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIWidth )->SetReference(_Ptr->GetNode("AutoFunctionAOIWidth"));
    static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIHeight )->SetReference(_Ptr->GetNode("AutoFunctionAOIHeight"));
    static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetX )->SetReference(_Ptr->GetNode("AutoFunctionAOIOffsetX"));
    static_cast<GenApi::CIntegerRef*> (&AutoFunctionAOIOffsetY )->SetReference(_Ptr->GetNode("AutoFunctionAOIOffsetY"));
    static_cast<GenApi::CBooleanRef*> (&AutoFunctionAOIUseBrightness )->SetReference(_Ptr->GetNode("AutoFunctionAOIUseBrightness"));
    static_cast<GenApi::CBooleanRef*> (&AutoFunctionAOIUseWhiteBalance )->SetReference(_Ptr->GetNode("AutoFunctionAOIUseWhiteBalance"));
    static_cast<GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector )->SetReference(_Ptr->GetNode("LUTSelector"));
    static_cast<GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<LUTSelectorEnums> *> (&LUTSelector )->SetEnumReference( LUTSelector_Luminance, "Luminance" );		static_cast<GenApi::CBooleanRef*> (&LUTEnable )->SetReference(_Ptr->GetNode("LUTEnable"));
    static_cast<GenApi::CIntegerRef*> (&LUTIndex )->SetReference(_Ptr->GetNode("LUTIndex"));
    static_cast<GenApi::CIntegerRef*> (&LUTValue )->SetReference(_Ptr->GetNode("LUTValue"));
    static_cast<GenApi::CRegisterRef*> (&LUTValueAll )->SetReference(_Ptr->GetNode("LUTValueAll"));
    static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetReference(_Ptr->GetNode("LineSelector"));
    static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetNumEnums(4);
	static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Line1, "Line1" );		static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Line2, "Line2" );		static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Line3, "Line3" );		static_cast<GenApi::CEnumerationTRef<LineSelectorEnums> *> (&LineSelector )->SetEnumReference( LineSelector_Line4, "Line4" );		static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetReference(_Ptr->GetNode("LineMode"));
    static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetEnumReference( LineMode_Input, "Input" );		static_cast<GenApi::CEnumerationTRef<LineModeEnums> *> (&LineMode )->SetEnumReference( LineMode_Output, "Output" );		static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetReference(_Ptr->GetNode("LineFormat"));
    static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetEnumReference( LineFormat_TTL, "TTL" );		static_cast<GenApi::CEnumerationTRef<LineFormatEnums> *> (&LineFormat )->SetEnumReference( LineFormat_OptoCoupled, "OptoCoupled" );		static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetReference(_Ptr->GetNode("LineLogic"));
    static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetEnumReference( LineLogic_Positive, "Positive" );		static_cast<GenApi::CEnumerationTRef<LineLogicEnums> *> (&LineLogic )->SetEnumReference( LineLogic_Negative, "Negative" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetReference(_Ptr->GetNode("LineSource"));
    static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetNumEnums(10);
	static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_ExposureActive, "ExposureActive" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_FrameTriggerWait, "FrameTriggerWait" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_FrameBurstTriggerWait, "FrameBurstTriggerWait" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_Timer1Active, "Timer1Active" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_UserOutput0, "UserOutput0" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_UserOutput1, "UserOutput1" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_UserOutput2, "UserOutput2" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_UserOutput3, "UserOutput3" );		static_cast<GenApi::CEnumerationTRef<LineSourceEnums> *> (&LineSource )->SetEnumReference( LineSource_FlashWindow, "FlashWindow" );		static_cast<GenApi::CBooleanRef*> (&LineInverter )->SetReference(_Ptr->GetNode("LineInverter"));
    static_cast<GenApi::CFloatRef*> (&LineDebouncerTime )->SetReference(_Ptr->GetNode("LineDebouncerTime"));
    static_cast<GenApi::CFloatRef*> (&LineMinimumOutputPulseWidth )->SetReference(_Ptr->GetNode("LineMinimumOutputPulseWidth"));
    static_cast<GenApi::CBooleanRef*> (&LineOverloadStatus )->SetReference(_Ptr->GetNode("LineOverloadStatus"));
    static_cast<GenApi::CBooleanRef*> (&LineStatus )->SetReference(_Ptr->GetNode("LineStatus"));
    static_cast<GenApi::CIntegerRef*> (&LineStatusAll )->SetReference(_Ptr->GetNode("LineStatusAll"));
    static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetReference(_Ptr->GetNode("UserOutputSelector"));
    static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput1, "UserOutput1" );		static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput2, "UserOutput2" );		static_cast<GenApi::CEnumerationTRef<UserOutputSelectorEnums> *> (&UserOutputSelector )->SetEnumReference( UserOutputSelector_UserOutput3, "UserOutput3" );		static_cast<GenApi::CBooleanRef*> (&UserOutputValue )->SetReference(_Ptr->GetNode("UserOutputValue"));
    static_cast<GenApi::CIntegerRef*> (&UserOutputValueAll )->SetReference(_Ptr->GetNode("UserOutputValueAll"));
    static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetReference(_Ptr->GetNode("CounterSelector"));
    static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<CounterSelectorEnums> *> (&CounterSelector )->SetEnumReference( CounterSelector_Counter1, "Counter1" );		static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetReference(_Ptr->GetNode("CounterEventSource"));
    static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<CounterEventSourceEnums> *> (&CounterEventSource )->SetEnumReference( CounterEventSource_FrameStart, "FrameStart" );		static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetReference(_Ptr->GetNode("CounterResetSource"));
    static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetNumEnums(6);
	static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Software, "Software" );		static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Line1, "Line1" );		static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Line2, "Line2" );		static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Line3, "Line3" );		static_cast<GenApi::CEnumerationTRef<CounterResetSourceEnums> *> (&CounterResetSource )->SetEnumReference( CounterResetSource_Line4, "Line4" );		static_cast<GenApi::CEnumerationTRef<CounterResetActivationEnums> *> (&CounterResetActivation )->SetReference(_Ptr->GetNode("CounterResetActivation"));
    static_cast<GenApi::CEnumerationTRef<CounterResetActivationEnums> *> (&CounterResetActivation )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<CounterResetActivationEnums> *> (&CounterResetActivation )->SetEnumReference( CounterResetActivation_RisingEdge, "RisingEdge" );		static_cast<GenApi::CCommandRef*> (&CounterReset )->SetReference(_Ptr->GetNode("CounterReset"));
    static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetReference(_Ptr->GetNode("TimerSelector"));
    static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<TimerSelectorEnums> *> (&TimerSelector )->SetEnumReference( TimerSelector_Timer1, "Timer1" );		static_cast<GenApi::CFloatRef*> (&TimerDuration )->SetReference(_Ptr->GetNode("TimerDuration"));
    static_cast<GenApi::CFloatRef*> (&TimerDelay )->SetReference(_Ptr->GetNode("TimerDelay"));
    static_cast<GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource )->SetReference(_Ptr->GetNode("TimerTriggerSource"));
    static_cast<GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<TimerTriggerSourceEnums> *> (&TimerTriggerSource )->SetEnumReference( TimerTriggerSource_ExposureStart, "ExposureStart" );		static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetReference(_Ptr->GetNode("UserSetSelector"));
    static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetNumEnums(6);
	static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_Default, "Default" );		static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_HighGain, "HighGain" );		static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_AutoFunctions, "AutoFunctions" );		static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_UserSet1, "UserSet1" );		static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_UserSet2, "UserSet2" );		static_cast<GenApi::CEnumerationTRef<UserSetSelectorEnums> *> (&UserSetSelector )->SetEnumReference( UserSetSelector_UserSet3, "UserSet3" );		static_cast<GenApi::CCommandRef*> (&UserSetLoad )->SetReference(_Ptr->GetNode("UserSetLoad"));
    static_cast<GenApi::CCommandRef*> (&UserSetSave )->SetReference(_Ptr->GetNode("UserSetSave"));
    static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetReference(_Ptr->GetNode("UserSetDefault"));
    static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetNumEnums(6);
	static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetEnumReference( UserSetDefault_Default, "Default" );		static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetEnumReference( UserSetDefault_HighGain, "HighGain" );		static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetEnumReference( UserSetDefault_AutoFunctions, "AutoFunctions" );		static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetEnumReference( UserSetDefault_UserSet1, "UserSet1" );		static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetEnumReference( UserSetDefault_UserSet2, "UserSet2" );		static_cast<GenApi::CEnumerationTRef<UserSetDefaultEnums> *> (&UserSetDefault )->SetEnumReference( UserSetDefault_UserSet3, "UserSet3" );		static_cast<GenApi::CBooleanRef*> (&ChunkModeActive )->SetReference(_Ptr->GetNode("ChunkModeActive"));
    static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetReference(_Ptr->GetNode("ChunkSelector"));
    static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetNumEnums(5);
	static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Gain, "Gain" );		static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_ExposureTime, "ExposureTime" );		static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_Timestamp, "Timestamp" );		static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_PayloadCRC16, "PayloadCRC16" );		static_cast<GenApi::CEnumerationTRef<ChunkSelectorEnums> *> (&ChunkSelector )->SetEnumReference( ChunkSelector_CounterValue, "CounterValue" );		static_cast<GenApi::CBooleanRef*> (&ChunkEnable )->SetReference(_Ptr->GetNode("ChunkEnable"));
    static_cast<GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector )->SetReference(_Ptr->GetNode("ChunkGainSelector"));
    static_cast<GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector )->SetEnumReference( ChunkGainSelector_All, "All" );		static_cast<GenApi::CFloatRef*> (&ChunkGain )->SetReference(_Ptr->GetNode("ChunkGain"));
    static_cast<GenApi::CFloatRef*> (&ChunkExposureTime )->SetReference(_Ptr->GetNode("ChunkExposureTime"));
    static_cast<GenApi::CIntegerRef*> (&ChunkTimestamp )->SetReference(_Ptr->GetNode("ChunkTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&ChunkPayloadCRC16 )->SetReference(_Ptr->GetNode("ChunkPayloadCRC16"));
    static_cast<GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector )->SetReference(_Ptr->GetNode("ChunkCounterSelector"));
    static_cast<GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector )->SetEnumReference( ChunkCounterSelector_Counter1, "Counter1" );		static_cast<GenApi::CIntegerRef*> (&ChunkCounterValue )->SetReference(_Ptr->GetNode("ChunkCounterValue"));
    static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetReference(_Ptr->GetNode("EventSelector"));
    static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetNumEnums(5);
	static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_ExposureEnd, "ExposureEnd" );		static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_FrameStart, "FrameStart" );		static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_FrameBurstStart, "FrameBurstStart" );		static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_FrameStartOvertrigger, "FrameStartOvertrigger" );		static_cast<GenApi::CEnumerationTRef<EventSelectorEnums> *> (&EventSelector )->SetEnumReference( EventSelector_FrameBurstStartOvertrigger, "FrameBurstStartOvertrigger" );		static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetReference(_Ptr->GetNode("EventNotification"));
    static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetEnumReference( EventNotification_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<EventNotificationEnums> *> (&EventNotification )->SetEnumReference( EventNotification_On, "On" );		static_cast<GenApi::CIntegerRef*> (&EventExposureEnd )->SetReference(_Ptr->GetNode("EventExposureEnd"));
    static_cast<GenApi::CIntegerRef*> (&EventExposureEndTimestamp )->SetReference(_Ptr->GetNode("EventExposureEndTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&EventExposureEndFrameID )->SetReference(_Ptr->GetNode("EventExposureEndFrameID"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameStart )->SetReference(_Ptr->GetNode("EventFrameStart"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameStartTimestamp )->SetReference(_Ptr->GetNode("EventFrameStartTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameStartFrameID )->SetReference(_Ptr->GetNode("EventFrameStartFrameID"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameBurstStart )->SetReference(_Ptr->GetNode("EventFrameBurstStart"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameBurstStartTimestamp )->SetReference(_Ptr->GetNode("EventFrameBurstStartTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameBurstStartFrameID )->SetReference(_Ptr->GetNode("EventFrameBurstStartFrameID"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameStartOvertrigger )->SetReference(_Ptr->GetNode("EventFrameStartOvertrigger"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameStartOvertriggerTimestamp )->SetReference(_Ptr->GetNode("EventFrameStartOvertriggerTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameStartOvertriggerFrameID )->SetReference(_Ptr->GetNode("EventFrameStartOvertriggerFrameID"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameBurstStartOvertrigger )->SetReference(_Ptr->GetNode("EventFrameBurstStartOvertrigger"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameBurstStartOvertriggerTimestamp )->SetReference(_Ptr->GetNode("EventFrameBurstStartOvertriggerTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&EventFrameBurstStartOvertriggerFrameID )->SetReference(_Ptr->GetNode("EventFrameBurstStartOvertriggerFrameID"));
    static_cast<GenApi::CIntegerRef*> (&PayloadSize )->SetReference(_Ptr->GetNode("PayloadSize"));
    static_cast<GenApi::CEnumerationTRef<BslUSBSpeedModeEnums> *> (&BslUSBSpeedMode )->SetReference(_Ptr->GetNode("BslUSBSpeedMode"));
    static_cast<GenApi::CEnumerationTRef<BslUSBSpeedModeEnums> *> (&BslUSBSpeedMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<BslUSBSpeedModeEnums> *> (&BslUSBSpeedMode )->SetEnumReference( BslUSBSpeedMode_HighSpeed, "HighSpeed" );		static_cast<GenApi::CEnumerationTRef<BslUSBSpeedModeEnums> *> (&BslUSBSpeedMode )->SetEnumReference( BslUSBSpeedMode_SuperSpeed, "SuperSpeed" );		static_cast<GenApi::CIntegerRef*> (&SIPayloadTransferSize )->SetReference(_Ptr->GetNode("SIPayloadTransferSize"));
    static_cast<GenApi::CIntegerRef*> (&SIPayloadTransferCount )->SetReference(_Ptr->GetNode("SIPayloadTransferCount"));
    static_cast<GenApi::CIntegerRef*> (&SIPayloadFinalTransfer1Size )->SetReference(_Ptr->GetNode("SIPayloadFinalTransfer1Size"));
    static_cast<GenApi::CIntegerRef*> (&SIPayloadFinalTransfer2Size )->SetReference(_Ptr->GetNode("SIPayloadFinalTransfer2Size"));
    static_cast<GenApi::CIntegerRef*> (&TestPendingAck )->SetReference(_Ptr->GetNode("TestPendingAck"));
    static_cast<GenApi::CStringRef*> (&DeviceVendorName )->SetReference(_Ptr->GetNode("DeviceVendorName"));
    static_cast<GenApi::CStringRef*> (&DeviceModelName )->SetReference(_Ptr->GetNode("DeviceModelName"));
    static_cast<GenApi::CStringRef*> (&DeviceManufacturerInfo )->SetReference(_Ptr->GetNode("DeviceManufacturerInfo"));
    static_cast<GenApi::CStringRef*> (&DeviceVersion )->SetReference(_Ptr->GetNode("DeviceVersion"));
    static_cast<GenApi::CStringRef*> (&DeviceFirmwareVersion )->SetReference(_Ptr->GetNode("DeviceFirmwareVersion"));
    static_cast<GenApi::CStringRef*> (&DeviceSerialNumber )->SetReference(_Ptr->GetNode("DeviceSerialNumber"));
    static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetReference(_Ptr->GetNode("DeviceScanType"));
    static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetEnumReference( DeviceScanType_Areascan, "Areascan" );		static_cast<GenApi::CEnumerationTRef<DeviceScanTypeEnums> *> (&DeviceScanType )->SetEnumReference( DeviceScanType_Linescan, "Linescan" );		static_cast<GenApi::CStringRef*> (&DeviceUserID )->SetReference(_Ptr->GetNode("DeviceUserID"));
    static_cast<GenApi::CIntegerRef*> (&DeviceLinkSelector )->SetReference(_Ptr->GetNode("DeviceLinkSelector"));
    static_cast<GenApi::CIntegerRef*> (&DeviceLinkSpeed )->SetReference(_Ptr->GetNode("DeviceLinkSpeed"));
    static_cast<GenApi::CEnumerationTRef<DeviceLinkThroughputLimitModeEnums> *> (&DeviceLinkThroughputLimitMode )->SetReference(_Ptr->GetNode("DeviceLinkThroughputLimitMode"));
    static_cast<GenApi::CEnumerationTRef<DeviceLinkThroughputLimitModeEnums> *> (&DeviceLinkThroughputLimitMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<DeviceLinkThroughputLimitModeEnums> *> (&DeviceLinkThroughputLimitMode )->SetEnumReference( DeviceLinkThroughputLimitMode_Off, "Off" );		static_cast<GenApi::CEnumerationTRef<DeviceLinkThroughputLimitModeEnums> *> (&DeviceLinkThroughputLimitMode )->SetEnumReference( DeviceLinkThroughputLimitMode_On, "On" );		static_cast<GenApi::CIntegerRef*> (&DeviceLinkThroughputLimit )->SetReference(_Ptr->GetNode("DeviceLinkThroughputLimit"));
    static_cast<GenApi::CIntegerRef*> (&DeviceLinkCurrentThroughput )->SetReference(_Ptr->GetNode("DeviceLinkCurrentThroughput"));
    static_cast<GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums> *> (&DeviceTemperatureSelector )->SetReference(_Ptr->GetNode("DeviceTemperatureSelector"));
    static_cast<GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums> *> (&DeviceTemperatureSelector )->SetNumEnums(3);
	static_cast<GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums> *> (&DeviceTemperatureSelector )->SetEnumReference( DeviceTemperatureSelector_Sensorboard, "Sensorboard" );		static_cast<GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums> *> (&DeviceTemperatureSelector )->SetEnumReference( DeviceTemperatureSelector_Coreboard, "Coreboard" );		static_cast<GenApi::CEnumerationTRef<DeviceTemperatureSelectorEnums> *> (&DeviceTemperatureSelector )->SetEnumReference( DeviceTemperatureSelector_Framegrabberboard, "Framegrabberboard" );		static_cast<GenApi::CFloatRef*> (&DeviceTemperature )->SetReference(_Ptr->GetNode("DeviceTemperature"));
    static_cast<GenApi::CCommandRef*> (&DeviceReset )->SetReference(_Ptr->GetNode("DeviceReset"));
    static_cast<GenApi::CIntegerRef*> (&DeviceSFNCVersionMajor )->SetReference(_Ptr->GetNode("DeviceSFNCVersionMajor"));
    static_cast<GenApi::CIntegerRef*> (&DeviceSFNCVersionMinor )->SetReference(_Ptr->GetNode("DeviceSFNCVersionMinor"));
    static_cast<GenApi::CIntegerRef*> (&DeviceSFNCVersionSubMinor )->SetReference(_Ptr->GetNode("DeviceSFNCVersionSubMinor"));
    static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetReference(_Ptr->GetNode("UserDefinedValueSelector"));
    static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetNumEnums(5);
	static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value1, "Value1" );		static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value2, "Value2" );		static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value3, "Value3" );		static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value4, "Value4" );		static_cast<GenApi::CEnumerationTRef<UserDefinedValueSelectorEnums> *> (&UserDefinedValueSelector )->SetEnumReference( UserDefinedValueSelector_Value5, "Value5" );		static_cast<GenApi::CIntegerRef*> (&UserDefinedValue )->SetReference(_Ptr->GetNode("UserDefinedValue"));
    static_cast<GenApi::CEnumerationTRef<RemoveParameterLimitSelectorEnums> *> (&RemoveParameterLimitSelector )->SetReference(_Ptr->GetNode("RemoveParameterLimitSelector"));
    static_cast<GenApi::CEnumerationTRef<RemoveParameterLimitSelectorEnums> *> (&RemoveParameterLimitSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<RemoveParameterLimitSelectorEnums> *> (&RemoveParameterLimitSelector )->SetEnumReference( RemoveParameterLimitSelector_Gain, "Gain" );		static_cast<GenApi::CBooleanRef*> (&RemoveParameterLimit )->SetReference(_Ptr->GetNode("RemoveParameterLimit"));
    static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetReference(_Ptr->GetNode("ExpertFeatureAccessSelector"));
    static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetNumEnums(7);
	static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature1, "ExpertFeature1" );		static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature2, "ExpertFeature2" );		static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature3, "ExpertFeature3" );		static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature4, "ExpertFeature4" );		static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature5, "ExpertFeature5" );		static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature6, "ExpertFeature6" );		static_cast<GenApi::CEnumerationTRef<ExpertFeatureAccessSelectorEnums> *> (&ExpertFeatureAccessSelector )->SetEnumReference( ExpertFeatureAccessSelector_ExpertFeature7, "ExpertFeature7" );		static_cast<GenApi::CIntegerRef*> (&ExpertFeatureAccessKey )->SetReference(_Ptr->GetNode("ExpertFeatureAccessKey"));
    static_cast<GenApi::CBooleanRef*> (&ExpertFeatureEnable )->SetReference(_Ptr->GetNode("ExpertFeatureEnable"));
    static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetReference(_Ptr->GetNode("FileSelector"));
    static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetNumEnums(9);
	static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserData, "UserData" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserSet1, "UserSet1" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserSet2, "UserSet2" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserSet3, "UserSet3" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserGainShading1, "UserGainShading1" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserGainShading2, "UserGainShading2" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserOffsetShading1, "UserOffsetShading1" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_UserOffsetShading2, "UserOffsetShading2" );		static_cast<GenApi::CEnumerationTRef<FileSelectorEnums> *> (&FileSelector )->SetEnumReference( FileSelector_ExpertFeature7File, "ExpertFeature7File" );		static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetReference(_Ptr->GetNode("FileOperationSelector"));
    static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetNumEnums(4);
	static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Open, "Open" );		static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Close, "Close" );		static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Read, "Read" );		static_cast<GenApi::CEnumerationTRef<FileOperationSelectorEnums> *> (&FileOperationSelector )->SetEnumReference( FileOperationSelector_Write, "Write" );		static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetReference(_Ptr->GetNode("FileOpenMode"));
    static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetEnumReference( FileOpenMode_Read, "Read" );		static_cast<GenApi::CEnumerationTRef<FileOpenModeEnums> *> (&FileOpenMode )->SetEnumReference( FileOpenMode_Write, "Write" );		static_cast<GenApi::CRegisterRef*> (&FileAccessBuffer )->SetReference(_Ptr->GetNode("FileAccessBuffer"));
    static_cast<GenApi::CIntegerRef*> (&FileAccessOffset )->SetReference(_Ptr->GetNode("FileAccessOffset"));
    static_cast<GenApi::CIntegerRef*> (&FileAccessLength )->SetReference(_Ptr->GetNode("FileAccessLength"));
    static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetReference(_Ptr->GetNode("FileOperationStatus"));
    static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetNumEnums(2);
	static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetEnumReference( FileOperationStatus_Success, "Success" );		static_cast<GenApi::CEnumerationTRef<FileOperationStatusEnums> *> (&FileOperationStatus )->SetEnumReference( FileOperationStatus_Failure, "Failure" );		static_cast<GenApi::CIntegerRef*> (&FileOperationResult )->SetReference(_Ptr->GetNode("FileOperationResult"));
    static_cast<GenApi::CIntegerRef*> (&FileSize )->SetReference(_Ptr->GetNode("FileSize"));
    static_cast<GenApi::CCommandRef*> (&FileOperationExecute )->SetReference(_Ptr->GetNode("FileOperationExecute"));
    
    }

    inline const char* CUsbCameraParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CUsbCameraParams_Params::_GetModelName(void)
    {
        return "UsbCameraParams";
    }

    //! \endcond

} // namespace Basler_UsbCameraParams

#endif // Basler_UsbCameraParams_PARAMS_H
