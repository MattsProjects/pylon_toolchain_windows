

//-----------------------------------------------------------------------------
//  Copyright (c) 2004-2021 Basler AG
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



#ifndef Basler_BconCameraParams_PARAMS_H
#define Basler_BconCameraParams_PARAMS_H

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>

// common node types
#include <GenApi/IBoolean.h>
#include <GenApi/ICategory.h>
#include <GenApi/ICommand.h>
#include <GenApi/IEnumeration.h>
#include <GenApi/IEnumEntry.h>
#include <GenApi/IFloat.h>
#include <GenApi/IInteger.h>
#include <GenApi/IString.h>
#include <GenApi/IRegister.h>

#ifdef __GNUC__
#   undef GCC_VERSION
#   define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#   undef GCC_DIAGNOSTIC_AWARE
#   define GCC_DIAGNOSTIC_AWARE          (GCC_VERSION >= 40200)
#   undef GCC_DIAGNOSTIC_PUSH_POP_AWARE
#   define GCC_DIAGNOSTIC_PUSH_POP_AWARE (GCC_VERSION >= 40600)
#else
#   undef GCC_DIAGNOSTIC_AWARE
#   define GCC_DIAGNOSTIC_AWARE 0
#endif

#ifdef __GNUC__
    // GCC_DIAGNOSTIC_AWARE ensures that the internal deprecated warnings can be ignored by gcc.
    // As a result older gcc will not generate warnings about really used deprecated features.
#   if GCC_DIAGNOSTIC_AWARE
#       define GENAPI_DEPRECATED_FEATURE __attribute__((deprecated))
#   else
#       define GENAPI_DEPRECATED_FEATURE
#   endif
#elif defined(_MSC_VER)
#   define GENAPI_DEPRECATED_FEATURE __declspec(deprecated)
#else
#   define GENAPI_DEPRECATED_FEATURE
#endif

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic push
#   endif
#   pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif


//! The namespace containing the device's control interface and related enumeration types
namespace Basler_BconCameraParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    //! Valid values for GainSelector
    enum GainSelectorEnums
    {
        GainSelector_All   //!<Gain will be applied to all channels or taps.

    };

    //! Valid values for GainAuto
    enum GainAutoEnums
    {
        GainAuto_Off,  //!<Gain is adjusted manually using the Gain parameter.
        GainAuto_Once,  //!<Gain is automatically adjusted once by the device.
        GainAuto_Continuous   //!<Gain is constantly adjusted by the device.

    };

    //! Valid values for BlackLevelSelector
    enum BlackLevelSelectorEnums
    {
        BlackLevelSelector_All   //!<Black level will be applied to all channels or taps.

    };

    //! Valid values for BslColorSpaceMode
    enum BslColorSpaceModeEnums
    {
        BslColorSpaceMode_RGB,  //!<Color space is set to RGB.
        BslColorSpaceMode_sRGB   //!<Color space is set to sRGB

    };

    //! Valid values for BinningHorizontalMode
    enum BinningHorizontalModeEnums
    {
        BinningHorizontalMode_Average,  //!<The values of the affected pixels are averaged.
        BinningHorizontalMode_Sum   //!<The values of the affected pixels are summed.

    };

    //! Valid values for BinningVerticalMode
    enum BinningVerticalModeEnums
    {
        BinningVerticalMode_Average,  //!<The values of the affected pixels are averaged.
        BinningVerticalMode_Sum   //!<The values of the affected pixels are summed.

    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_RGB8,  //!<Red, green, blue 8 bit.
        PixelFormat_YCbCr422_8,  //!<YCrCb 422 8 bit.
        PixelFormat_BayerGR8,  //!<Bayer green red 8 bit.
        PixelFormat_BayerGR12,  //!<Bayer green red 12 bit.
        PixelFormat_Mono8,  //!<Mono 8 bit packed.
        PixelFormat_Mono12,  //!<Mono 12 bit packed.
        PixelFormat_BayerBG8,  //!<Bayer blue green 8 bit.
        PixelFormat_BayerGB8,  //!<Bayer green blue 8 bit.
        PixelFormat_BayerRG8,  //!<Bayer red green 8 bit.
        PixelFormat_BayerBG12,  //!<Bayer blue green 12 bit.
        PixelFormat_BayerGB12,  //!<Bayer green blue 12 bit.
        PixelFormat_BayerRG12   //!<Bayer red green 12 bit.

    };

    //! Valid values for PixelColorFilter
    enum PixelColorFilterEnums
    {
        PixelColorFilter_None,  //!<No color filter applied.
        PixelColorFilter_BayerGR,  //!<Bayer green red filter applied.
        PixelColorFilter_BayerRG,  //!<Bayer red green filter applied.
        PixelColorFilter_BayerGB,  //!<Bayer green blue filter applied.
        PixelColorFilter_BayerBG   //!<Bayer blue green filter applied.

    };

    //! Valid values for TestPattern
    enum TestPatternEnums
    {
        TestPattern_Off,  //!<No test pattern. Displays the original image.
        TestPattern_GreyDiagonalSawtooth8,  //!<
        TestPattern_ColorDiagonalSawtooth8   //!<

    };

    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_SingleFrame,  //!<One frame is captured.
        AcquisitionMode_Continuous   //!<Frames are captured continuously until stopped with the AcquisitionStop command.

    };

    //! Valid values for SensorShutterMode
    enum SensorShutterModeEnums
    {
        SensorShutterMode_Global,  //!<The shutter opens and closes at the same time for all pixels.
        SensorShutterMode_Rolling,  //!<The shutter opens and closes sequentially for groups (typically lines) of pixels.
        SensorShutterMode_GlobalReset   //!<The shutter opens at the same time for all pixels but ends in a sequential manner.

    };

    //! Valid values for OverlapMode
    enum OverlapModeEnums
    {
        OverlapMode_On,  //!<Overlapping exposure and image readout.
        OverlapMode_Off   //!<Non-overlapping exposure and image readout.

    };

    //! Valid values for BslImmediateTriggerMode
    enum BslImmediateTriggerModeEnums
    {
        BslImmediateTriggerMode_On,  //!<The immediate trigger mode is enabled.
        BslImmediateTriggerMode_Off   //!<The immediate trigger mode is disabled.

    };

    //! Valid values for ExposureAuto
    enum ExposureAutoEnums
    {
        ExposureAuto_Off,  //!<Length of exposure is adjusted manually using the ExposureTime parameter.
        ExposureAuto_Once,  //!<Length of exposure is adjusted once by the device.
        ExposureAuto_Continuous   //!<Exposure duration is constantly adjusted by the device to maximize the dynamic range.

    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_FrameStart   //!<Selects a trigger that starts the capture of one frame.

    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!<Disables the selected trigger.
        TriggerMode_On   //!<Enables the selected trigger.

    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Software,  //!<Specifies that the trigger signal will be applied via software using the TriggerSoftware command.
        TriggerSource_Line1,  //!<Specifies that the trigger signal will be applied via hardware on physical input line 1.
        TriggerSource_Line3   //!<Specifies that the trigger signal will be applied via hardware on physical input line 3.

    };

    //! Valid values for TriggerActivation
    enum TriggerActivationEnums
    {
        TriggerActivation_RisingEdge,  //!<Sets the selected trigger active on the rising edge of the source signal.
        TriggerActivation_FallingEdge   //!<Sets the selected trigger active on the falling edge of the source signal.

    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed,  //!<Timed exposure.
        ExposureMode_TriggerWidth   //!<Uses the width of the current frame or line trigger signals pulse to control the length of the exposure.

    };

    //! Valid values for LightSourcePreset
    enum LightSourcePresetEnums
    {
        LightSourcePreset_Off,  //!<
        LightSourcePreset_Tungsten2800K,  //!<Color preset for image acquisition with tungsten incandescent light (2800 K).
        LightSourcePreset_Daylight5000K,  //!<Color preset for image acquisition with daylight of 5000 K.
        LightSourcePreset_Daylight6500K   //!<Color preset for image acquisition with daylight of 6500 K.

    };

    //! Valid values for BalanceWhiteAuto
    enum BalanceWhiteAutoEnums
    {
        BalanceWhiteAuto_Off,  //!<White balance is adjusted manually using the BalanceRatioSelector and BalanceRatio parameters.
        BalanceWhiteAuto_Once,  //!<White balance is automatically adjusted once by the device.
        BalanceWhiteAuto_Continuous   //!<White balance is constantly adjusted by the device.

    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Red,  //!<Balance ratio will be applied to the red channel.
        BalanceRatioSelector_Green,  //!<Balance ratio will be applied to the green channel.
        BalanceRatioSelector_Blue   //!<Balance ratio will be applied to the blue channel.

    };

    //! Valid values for BslContrastMode
    enum BslContrastModeEnums
    {
        BslContrastMode_Linear,  //!<Linear contrast enhancement is used to adjust the contrast.
        BslContrastMode_SCurve   //!<S-curve contrast enhancement is used to adjust the contrast.

    };

    //! Valid values for DefectPixelCorrectionMode
    enum DefectPixelCorrectionModeEnums
    {
        DefectPixelCorrectionMode_Off,  //!<
        DefectPixelCorrectionMode_On,  //!<
        DefectPixelCorrectionMode_StaticOnly   //!<

    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!<Index of the physical line and the associated I/O control block to use.
        LineSelector_Line2,  //!<Index of the physical line and the associated I/O control block to use.
        LineSelector_Line3   //!<Index of the physical line and the associated I/O control block to use.

    };

    //! Valid values for LineMode
    enum LineModeEnums
    {
        LineMode_Input,  //!<The selected physical line is used to input an electrical signal.
        LineMode_Output   //!<The selected physical line is used to output an electrical signal.

    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_ExposureActive,  //!<Device is exposing a frame (or line).
        LineSource_UserOutput1,  //!<The User Output 1 bit state as defined by its current UserOutputValue.
        LineSource_UserOutput2,  //!<The User Output 2 bit state as defined by its current UserOutputValue.
        LineSource_UserOutput3,  //!<The User Output 3 bit state as defined by its current UserOutputValue.
        LineSource_UserOutput4,  //!<The User Output 4 bit state as defined by its current UserOutputValue.
        LineSource_FlashWindow   //!<

    };

    //! Valid values for LineFormat
    enum LineFormatEnums
    {
        LineFormat_LVDS   //!<The line is currently accepting or sending LVDS level signals.

    };

    //! Valid values for UserOutputSelector
    enum UserOutputSelectorEnums
    {
        UserOutputSelector_UserOutput1,  //!<Selects bit 1 of the User Output register.
        UserOutputSelector_UserOutput2   //!<Selects  bit 2 of the User Output register.

    };

    //! Valid values for AutoFunctionProfile
    enum AutoFunctionProfileEnums
    {
        AutoFunctionProfile_Smart,  //!<
        AutoFunctionProfile_MinimizeGain,  //!<
        AutoFunctionProfile_MinimizeExposureTime,  //!<
        AutoFunctionProfile_AntiFlicker50Hz,  //!<
        AutoFunctionProfile_AntiFlicker60Hz   //!<

    };

    //! Valid values for AutoFunctionROISelector
    enum AutoFunctionROISelectorEnums
    {
        AutoFunctionROISelector_ROI1,  //!<Selects Auto Function ROI 1.
        AutoFunctionROISelector_ROI2   //!<Selects Auto Function ROI 2.

    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_Default,  //!<Selects the default user set containing factory settings.
        UserSetSelector_UserSet1,  //!<Selects the user set 1.
        UserSetSelector_UserSet2,  //!<Selects the user set 2.
        UserSetSelector_UserSet3   //!<Selects the user set 3.

    };

    //! Valid values for UserSetDefault
    enum UserSetDefaultEnums
    {
        UserSetDefault_Default,  //!<Selects the default user set as the default startup set.
        UserSetDefault_UserSet1,  //!<Selects the user set 1 as the default startup set.
        UserSetDefault_UserSet2,  //!<Selects the user set 2 as the default startup set.
        UserSetDefault_UserSet3   //!<Selects the user set 3 as the default startup set.

    };

    //! Valid values for BconPixelsPerClockCycle
    enum BconPixelsPerClockCycleEnums
    {
        BconPixelsPerClockCycle_One,  //!< On each clock cycle, data for one pixel is transmitted via the BCON interface.
        BconPixelsPerClockCycle_Two   //!<On each clock cycle, data for two pixels is transmitted via the BCON interface.

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
        BconClockFrequency_MHz_12   //!<

    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan   //!<2D sensor.

    };

    //! Valid values for BslDeviceRole
    enum BslDeviceRoleEnums
    {
        BslDeviceRole_Camera,  //!<
        BslDeviceRole_Updater   //!<

    };

    //! Valid values for DeviceIndicatorMode
    enum DeviceIndicatorModeEnums
    {
        DeviceIndicatorMode_Inactive,  //!<Indicators are inactive (off).
        DeviceIndicatorMode_Active   //!<Indicators are active showing their respective status.

    };

    //! Valid values for DeviceClockSelector
    enum DeviceClockSelectorEnums
    {
        DeviceClockSelector_Bcon   //!<The BCON device clock is selected.

    };

    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************


    //! Basler USB3Vision camera interface
    class CBconCameraParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS

            //! Constructor
        CBconCameraParams_Params( void );

        //! Destructor
        ~CBconCameraParams_Params( void );

        //! Initializes the references
        void _Initialize( GENAPI_NAMESPACE::INodeMap* );

        //! Return the vendor of the camera
        const char* _GetVendorName( void );

        //! Returns the camera model name
        const char* _GetModelName( void );

    //! \endcond

//----------------------------------------------------------------------------------------------------------------
// References to features
//----------------------------------------------------------------------------------------------------------------
    public:

    //! \name AnalogControl - Category that contains the analog control parameters.
    //@{
    /*!
        \brief Selects which gain is controlled by the various gain features.

        Selects which gain is controlled by the various gain features.

        \b Visibility = Guru

    */
        GENAPI_NAMESPACE::IEnumerationT<GainSelectorEnums >& GainSelector;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Controls the selected gain as an absolute physical value.

            Controls the selected gain as an absolute physical value. This is an amplification factor applied to the video signal.

            \b Visibility = Beginner


            \b Selected by : GainSelector, GainSelector

        */
        GENAPI_NAMESPACE::IFloat& Gain;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

            \b Selected by : GainSelector

        */
        GENAPI_NAMESPACE::IInteger& GainRaw;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Sets the automatic gain control (AGC) mode.

            Sets the automatic gain control (AGC) mode.

            \b Visibility = Beginner


            \b Selected by : GainSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<GainAutoEnums >& GainAuto;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Sets the lower limit for the GainAuto adjustments.

            Sets the lower limit for the GainAuto adjustments.

            \b Visibility = Expert

            \b Selected by : GainSelector, GainSelector

        */
        GENAPI_NAMESPACE::IFloat& AutoGainLowerLimit;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

            \b Selected by : GainSelector

        */
        GENAPI_NAMESPACE::IInteger& AutoGainLowerLimitRaw;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Sets the upper limit for the GainAuto adjustments.

            Sets the upper limit for the GainAuto adjustments.

            \b Visibility = Expert

            \b Selected by : GainSelector, GainSelector

        */
        GENAPI_NAMESPACE::IFloat& AutoGainUpperLimit;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

            \b Selected by : GainSelector

        */
        GENAPI_NAMESPACE::IInteger& AutoGainUpperLimitRaw;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Selects the black level control to configure.

            Selects the black level control to configure. Once a black level control has been selected, all changes to the black level settings will be applied to the selected control.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::IEnumerationT<BlackLevelSelectorEnums >& BlackLevelSelector;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Controls the analog black level as an absolute physical value.

            Controls the analog black level as an absolute physical value. This represents a DC offset applied to the video signal.

            \b Visibility = Beginner


            \b Selected by : BlackLevelSelector, BlackLevelSelector

        */
        GENAPI_NAMESPACE::IFloat& BlackLevel;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

            \b Selected by : BlackLevelSelector

        */
        GENAPI_NAMESPACE::IInteger& BlackLevelRaw;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& GammaRaw;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Adjusts the brightness of the pixel values output by the camera's sensor.

            Adjusts the brightness of the pixel values output by the camera's sensor to account for a non-linearity in the human perception of brightness. Note that perception of brightness also depends on the color space mode set.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& Gamma;

        //@}


        //! \name AnalogControl - Category that contains the analog control parameters.
        //@{
        /*!
            \brief Sets the color space for image acquisition.

            Sets the color space for image acquisition. Note that perception of brightness also depends on the gamma correction value set.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<BslColorSpaceModeEnums >& BslColorSpaceMode;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Actual width of the sensor in pixels.

            Actual width of the sensor in pixels.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& SensorWidth;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Actual height of the sensor in pixels.

            Actual height of the sensor in pixels.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& SensorHeight;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Maximum width of the image in pixels.

            Maximum width of the image in pixels. The dimension is calculated after horizontal binning, decimation or any other function changing the horizontal dimension of the image.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& WidthMax;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Maximum height of the image in pixels.

            Maximum height of the image in pixels. This dimension is calculated after vertical binning, decimation or any other function changing the vertical dimension of the image.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& HeightMax;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Width of the region of interest in pixels.

            Width of the region of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Width;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Height of the region of interest in pixels.

            Height of the region of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Height;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Horizontal offset from the origin to the region of interest in pixels.

            Horizontal offset from the origin to the region of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& OffsetX;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Vertical offset from the origin to the region of interest in pixels.

            Vertical offset from the origin to the region of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& OffsetY;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Sets the mode used to combine horizontal pixels when BinningHorizontal is used.

            Sets the mode used to combine horizontal pixels when BinningHorizontal is used.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BinningHorizontalModeEnums >& BinningHorizontalMode;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Sets the number of horizontal pixels to combine.

            Sets the number of horizontal pixels to combine. This reduces the horizontal resolution (width) of the image and increases the signal-to-noise ratio. Depending on the BinningHorizontalMode used, it may also increase the camera's response to light.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& BinningHorizontal;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Sets the mode used to combine vertical pixels when BinningVertical is used.

            Sets the mode used to combine vertical pixels when BinningVertical is used.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BinningVerticalModeEnums >& BinningVerticalMode;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Sets the number of vertical pixels to combine.

            Sets the number of vertical pixels to combine. This reduces the vertical resolution (height) of the image and increases the signal-to-noise ratio. Depending on the BinningVerticalMode used, it may also increase the camera's response to light.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& BinningVertical;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Mirrors the captured image horizontally.

            Mirrors the captured image horizontally. The position of the region of interest relative to the sensor remains the same.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IBoolean& ReverseX;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Mirrors the captured image vertically.

            Mirrors the captured image vertically. The position of the region of interest relative to the sensor remains the same.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IBoolean& ReverseY;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Sets the pixel format of the device.

            Sets the pixel format of the device. The pixel format represents all the information provided by PixelCoding, PixelSize, PixelColorFilter combined in a single parameter.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<PixelFormatEnums >& PixelFormat;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Type of color filter that is applied to the image.

            Type of color filter that is applied to the image.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<PixelColorFilterEnums >& PixelColorFilter;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Minimum value that can be returned during the digitization process.

            Minimum value that can be returned during the digitization process. This corresponds to the darkest value of the camera. For color cameras, this returns the smallest value that can be applied to each color component.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& PixelDynamicRangeMin;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Maximum value that will be returned during the digitization process.

            Maximum value that will be returned during the digitization process. This corresponds to the brightest value of the camera. For color cameras, this returns the biggest value that can be applied to each color component.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& PixelDynamicRangeMax;

        //@}


        //! \name ImageFormatControl - Category that contains the image format control parameters.
        //@{
        /*!
            \brief Selects the type of image test pattern that is generated by the device.

            Selects the type of image test pattern that is generated by the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<TestPatternEnums >& TestPattern;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the image acquisition mode of the device.

            Sets the image acquisition mode of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<AcquisitionModeEnums >& AcquisitionMode;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Starts the image acquisition by the device.

            Starts the image acquisition by the device. The number of frames captured is specified by AcquisitionMode.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& AcquisitionStart;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Stops the image acquisition by the device at the end of the current frame.

            Stops the image acquisition by the device at the end of the current frame. It is mainly used when AcquisitionMode is set to Continuous, but can be used in any acquisition mode.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& AcquisitionStop;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the shutter mode of the device.

            Sets the shutter mode of the device.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::IEnumerationT<SensorShutterModeEnums >& SensorShutterMode;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Configures overlapping exposure and image readout.

            Configures overlapping exposure and image readout.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<OverlapModeEnums >& OverlapMode;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the immediate trigger mode.

            Sets the immediate trigger mode. If this mode is enabled, exposure starts immediately after triggering, but changes to image parameters become effective with a short delay, i.e., after one or more images have been acquired.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BslImmediateTriggerModeEnums >& BslImmediateTriggerMode;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the exposure time. ExposureMode must be set to Timed and ExposureAuto must be set to Off.

            Sets the exposure time. ExposureMode must be set to Timed and ExposureAuto must be set to Off. This controls the length of time the photosensitive cells are exposed to light.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& ExposureTime;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& ExposureTimeRaw;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the automatic exposure mode. ExposureMode must be set to Timed.

            Sets the automatic exposure mode. ExposureMode must be set to Timed.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<ExposureAutoEnums >& ExposureAuto;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the lower limit for the ExposureAuto adjustments.

            Sets the lower limit for the ExposureAuto adjustments.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IFloat& AutoExposureTimeLowerLimit;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& AutoExposureTimeLowerLimitRaw;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the upper limit for the ExposureAuto adjustments.

            Sets the upper limit for the ExposureAuto adjustments.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IFloat& AutoExposureTimeUpperLimit;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& AutoExposureTimeUpperLimitRaw;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Selects the type of trigger to configure.

            Selects the type of trigger to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerSelectorEnums >& TriggerSelector;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Enables or disables the selected trigger.

            Enables or disables the selected trigger.

            \b Visibility = Beginner


            \b Selected by : TriggerSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerModeEnums >& TriggerMode;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Generates a software trigger signal.

            Generates a software trigger signal. TriggerSource must be set to Software.

            \b Visibility = Beginner


            \b Selected by : TriggerSelector

        */
        GENAPI_NAMESPACE::ICommand& TriggerSoftware;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Specifies the internal signal or the physical input line to use as the trigger source.

            Specifies the internal signal or the physical input line to use as the trigger source. The selected trigger must have its TriggerMode set to On.

            \b Visibility = Beginner


            \b Selected by : TriggerSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerSourceEnums >& TriggerSource;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Specifies the activation mode of the trigger.

            Specifies the activation mode of the trigger.

            \b Visibility = Beginner


            \b Selected by : TriggerSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerActivationEnums >& TriggerActivation;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Sets the exposure mode.

            Sets the exposure mode.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::IEnumerationT<ExposureModeEnums >& ExposureMode;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& AcquisitionFramePeriodRaw;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief Controls the acquisition rate (in hertz) at which frames are captured.

            Controls the acquisition rate (in hertz) at which frames are captured.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& AcquisitionFrameRate;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief The current frame rate of the device.

            The current frame rate of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& ResultingFrameRate;

        //@}


        //! \name AcquisitionControl - Category that contains the acquisition and trigger control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& ResultingFramePeriod;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Selects the light source preset.

            Selects the light source preset. The colors in the image will be corrected so that they are appropriate for the selected light source.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<LightSourcePresetEnums >& LightSourcePreset;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

            \b Selected by : BalanceRatioSelector

        */
        GENAPI_NAMESPACE::IInteger& BalanceRatioRaw;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Controls the mode for automatic white balancing between the color channels.

            Controls the mode for automatic white balancing between the color channels. The white balancing ratios are automatically adjusted.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BalanceWhiteAutoEnums >& BalanceWhiteAuto;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Selects a balance ratio to configure.

            Selects a balance ratio control to configure. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BalanceRatioSelectorEnums >& BalanceRatioSelector;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Sets the value of the selected balance ratio control as a float value.

            Sets the value of the selected balance ratio control as a float value.

            \b Visibility = Expert

            \b Selected by : BalanceRatioSelector, BalanceRatioSelector

        */
        GENAPI_NAMESPACE::IFloat& BalanceRatio;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Hue shift to be applied.

            Hue shift to be applied. Adjusting the hue shifts the colors of the image. This can be useful, e.g., for correcting minor color shifts or creating false-color images.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& BslHueValue;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& BslSaturationValueRaw;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Amount of saturation to be applied.

            Amount of saturation to be applied. Adjusting the saturation changes the colorfulness (intensity) of the colors. A higher saturation, for example, will make colors easier to distinguish.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IFloat& BslSaturationValue;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& ContrastEnhancementRaw;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Increases the contrast by setting the darkest regions of the image to black.

            Increases the contrast by setting the darkest regions of the image to black. A digital gain is applied to the remaining pixels to maintain the original saturation level.

            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IFloat& ContrastEnhancement;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Sets the contrast mode.

            Sets the contrast mode. This specifies which type of contrast enhancement is used to adjust the contrast.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<BslContrastModeEnums >& BslContrastMode;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& BslBrightnessRaw;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Amount of brightness to be applied.

            Amount of brightness to be applied. This allows you to lighten or darken the entire image.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& BslBrightness;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& BslContrastRaw;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Amount of contrast to be applied.

            Amount of contrast to be applied. The more contrast you apply, the more defined the difference between light and dark areas in the image will be.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& BslContrast;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Identifies outlier pixels and adjusts their intensity value.

            Identifies pixels that have a significantly greater or lesser intensity value than its neighboring pixels (outlier pixels) and adjusts their intensity value.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<DefectPixelCorrectionModeEnums >& DefectPixelCorrectionMode;

        //@}


        //! \name ImageQualityControl - Category that contains the image quality control parameters.
        //@{
        /*!
            \brief Increases the sharpness of the captured images.

            Increases the sharpness of the captured images. The higher the sharpness, the more distinct the image subject's contours will be.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& SharpnessEnhancement;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Selects the physical line (or pin) of the external device connector to configure.

            Selects the physical line (or pin) of the external device connector to configure.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<LineSelectorEnums >& LineSelector;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Controls if the physical line is used to input or output a signal.

            Controls if the physical line is used to input or output a signal.

            \b Visibility = Expert

            \b Selected by : LineSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<LineModeEnums >& LineMode;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Controls the inversion of the signal of the selected input or output line.

            Controls the inversion of the signal of the selected input or output line.

            \b Visibility = Expert

            \b Selected by : LineSelector

        */
        GENAPI_NAMESPACE::IBoolean& LineInverter;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Selects which internal acquisition or I/O source signal to output on the selected line.

            Selects which internal acquisition or I/O source signal to output on the selected line. LineMode must be set to Output.

            \b Visibility = Expert

            \b Selected by : LineSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<LineSourceEnums >& LineSource;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Controls the current electrical format of the selected physical input or output line.

            Controls the current electrical format of the selected physical input or output line.

            \b Visibility = Expert

            \b Selected by : LineSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<LineFormatEnums >& LineFormat;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

            \b Selected by : LineSelector

        */
        GENAPI_NAMESPACE::IInteger& LineDebouncerTimeRaw;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Sets the debouncer time for the selected input line.

            Sets the debouncer time for the selected input line.

            \b Visibility = Expert

            \b Selected by : LineSelector, LineSelector

        */
        GENAPI_NAMESPACE::IFloat& LineDebouncerTime;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Returns the current status of the selected input or output line.

            Returns the current status of the selected input or output line.

            \b Visibility = Expert

            \b Selected by : LineSelector

        */
        GENAPI_NAMESPACE::IBoolean& LineStatus;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Returns the current status of all available line signals in a single bit field.

            Returns the current status of all available line signals in a single bit field.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& LineStatusAll;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Selects which bit of the User Output register will be set by UserOutputValue.

            Selects which bit of the User Output register will be set by UserOutputValue.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<UserOutputSelectorEnums >& UserOutputSelector;

        //@}


        //! \name DigitalIOControl - Category that contains the digital input and output control parameters.
        //@{
        /*!
            \brief Sets the value of the bit selected by UserOutputSelector.

            Sets the value of the bit selected by UserOutputSelector.

            \b Visibility = Expert

            \b Selected by : UserOutputSelector

        */
        GENAPI_NAMESPACE::IBoolean& UserOutputValue;

        //@}


        //! \name AutoFunctionControl - Category that contains the auto function control parameters.
        //@{
        /*!
            \brief Sets the target gray value for the selected auto function.

            Sets the target gray value for the selected auto function.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IFloat& AutoTargetBrightness;

        //@}


        //! \name AutoFunctionControl - Category that contains the auto function control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& AutoTargetBrightnessRaw;

        //@}


        //! \name AutoFunctionControl - Category that contains the auto function control parameters.
        //@{
        /*!
            \brief Sets the backlight compensation.

            Sets the backlight compensation that allows the camera to compensate for underexposure. This is done by excluding a given percentage of the brightest pixels in the image from the target average gray value calculations.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IFloat& AutoBacklightCompensation;

        //@}


        //! \name AutoFunctionControl - Category that contains the auto function control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& AutoBacklightCompensationRaw;

        //@}


        //! \name AutoFunctionControl - Category that contains the auto function control parameters.
        //@{
        /*!
            \brief Specifies how gain and exposure time will be balanced.

            Specifies how gain and exposure time will be balanced when the camera is making automatic adjustments.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<AutoFunctionProfileEnums >& AutoFunctionProfile;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Selects the Auto Function ROI.

            Selects the Auto Function ROI.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<AutoFunctionROISelectorEnums >& AutoFunctionROISelector;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Sets the width of the auto function region of interest in pixels.

            This value sets the width of the auto function region of interest in pixels.

            \b Visibility = Beginner


            \b Selected by : AutoFunctionROISelector

        */
        GENAPI_NAMESPACE::IInteger& AutoFunctionROIWidth;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Sets the height of the auto function region of interest in pixels.

            This value sets the height of the auto function region of interest in pixels.

            \b Visibility = Beginner


            \b Selected by : AutoFunctionROISelector

        */
        GENAPI_NAMESPACE::IInteger& AutoFunctionROIHeight;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Sets the starting column of the auto function region of interest in pixels.

            This value sets the starting column of the auto function region of interest in pixels.

            \b Visibility = Beginner


            \b Selected by : AutoFunctionROISelector

        */
        GENAPI_NAMESPACE::IInteger& AutoFunctionROIOffsetX;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Sets the starting line of the auto function region of interest in pixels.

            This value sets the starting line of the auto function region of interest in pixels.

            \b Visibility = Beginner


            \b Selected by : AutoFunctionROISelector

        */
        GENAPI_NAMESPACE::IInteger& AutoFunctionROIOffsetY;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Selects brightness to be adjusted by an auto function.

            For the selected Auto Function ROI, brightness will be adjusted by an auto function. Depending on the Auto Function Profile setting, the adjustment will be done either by the Gain Auto or by the Exposure Auto auto function.

            \b Visibility = Beginner


            \b Selected by : AutoFunctionROISelector

        */
        GENAPI_NAMESPACE::IBoolean& AutoFunctionROIUseBrightness;

        //@}


        //! \name AutoFunctionROIControl - Selects and configures Auto Function ROIs.
        //@{
        /*!
            \brief Selects white balance to be adjusted by the related auto function.

            For the selected Auto Function ROI, white balance will be adjusted by the Balance White Auto auto function.

            \b Visibility = Beginner


            \b Selected by : AutoFunctionROISelector

        */
        GENAPI_NAMESPACE::IBoolean& AutoFunctionROIUseWhiteBalance;

        //@}


        //! \name UserSetControl - Category that contains the user set control parameters.
        //@{
        /*!
            \brief Selects the user set to load, save, or configure.

            Selects the user set to load, save, or configure. Once a user set has been selected, all changes to the user set settings will be applied to the selected user set.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<UserSetSelectorEnums >& UserSetSelector;

        //@}


        //! \name UserSetControl - Category that contains the user set control parameters.
        //@{
        /*!
            \brief Loads the selected configuration into the memory of the device and makes it the active user set.

            Loads the selected configuration into the memory of the device and makes it the active user set. Once the selected set is loaded, the parameters in the selected set will control the camera.

            \b Visibility = Beginner


            \b Selected by : UserSetSelector

        */
        GENAPI_NAMESPACE::ICommand& UserSetLoad;

        //@}


        //! \name UserSetControl - Category that contains the user set control parameters.
        //@{
        /*!
            \brief Saves the current active user set into the selected user set.

            Saves the current active user set into the selected user set.

            \b Visibility = Beginner


            \b Selected by : UserSetSelector

        */
        GENAPI_NAMESPACE::ICommand& UserSetSave;

        //@}


        //! \name UserSetControl - Category that contains the user set control parameters.
        //@{
        /*!
            \brief Sets the user set to be used as the default startup set.

            Sets the user set to be used as the default startup set. This user set will be loaded as the active set whenever the camera is powered on or reset.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<UserSetDefaultEnums >& UserSetDefault;

        //@}


        //! \name TestControl - Category that contains the test control parameters.
        //@{
        /*!
            \brief Tests the device's pending acknowledge feature.

            Tests the device's pending acknowledge feature. When this feature is written, the device waits a time period corresponding to the value of TestPendingAck before acknowledging the write.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::IInteger& TestPendingAck;

        //@}


        //! \name TransportLayerControl - Category that contains the transport layer control parameters.
        //@{
        /*!
            \brief Used by the transport layer to prevent critical features from changing during acquisition.

            Used by the transport layer to prevent critical features from changing during acquisition.

            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& TLParamsLocked;

        //@}


        //! \name TransportLayerControl - Category that contains the transport layer control parameters.
        //@{
        /*!
            \brief Sets the number of pixels transmitted per clock cycle via the BCON interface.

            Sets the number of pixels transmitted per clock cycle via the BCON interface.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BconPixelsPerClockCycleEnums >& BconPixelsPerClockCycle;

        //@}


        //! \name TransportLayerControl - Category that contains the transport layer control parameters.
        //@{
        /*!
            \brief Sets the clock frequency for the BCON transport layer.

            Sets the clock frequency for the BCON transport layer.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<BconClockFrequencyEnums >& BconClockFrequency;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Name of the manufacturer of the device.

            Name of the manufacturer of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceVendorName;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Model of the device.

            Model of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceModelName;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Manufacturer information about the device.

            Manufacturer information about the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceManufacturerInfo;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Version of the device.

            Version of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceVersion;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Firmware version of the device.

            Firmware version of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceFirmwareVersion;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Serial number of the device.

            Serial number of the device. This string is a unique identifier of the device.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IString& DeviceSerialNumber;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief User-programmable device identifier.

            User-programmable device identifier.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IString& DeviceUserID;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Scan type of the sensor of the device.

            Scan type of the sensor of the device.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<DeviceScanTypeEnums >& DeviceScanType;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Major version of the Standard Features Naming Convention that was used to create the GenICam XML file of the device.

            Major version of the Standard Features Naming Convention that was used to create the GenICam XML file of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& DeviceSFNCVersionMajor;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Minor version of the Standard Features Naming Convention that was used to create the GenICam XML file of the device.

            Minor version of the Standard Features Naming Convention that was used to create the GenICam XML file of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& DeviceSFNCVersionMinor;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Sub-minor version of the Standard Features Naming Convention that was used to create the GenICam XML file of the device.

            Sub-minor version of the Standard Features Naming Convention that was used to create the GenICam XML file of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& DeviceSFNCVersionSubMinor;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Resets the device to its power-up state.

            Resets the device to its power-up state. After reset, the device must be rediscovered.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::ICommand& DeviceReset;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IString& BslFirmwareName;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IString& BslFirmwareLabel;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& BslFirmwareCompatibilityID;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IEnumerationT<BslDeviceRoleEnums >& BslDeviceRole;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& BslDeviceRoleKey;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Controls the behavior of the indicators (such as LEDs) showing the status of the device.

            Controls the behavior of the indicators (such as LEDs) showing the status of the device.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<DeviceIndicatorModeEnums >& DeviceIndicatorMode;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Prepare the device for registers streaming without checking for consistency.

            Prepare the device for registers streaming without checking for consistency.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::ICommand& DeviceRegistersStreamingStart;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Announce the end of registers streaming.

            Announce the end of registers streaming.

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::ICommand& DeviceRegistersStreamingEnd;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Sets the device clock.

            Sets the device clock. Once a device clock has been set, the device clock frequency can be read using the DeviceClockFrequency parameter.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<DeviceClockSelectorEnums >& DeviceClockSelector;

        //@}


        //! \name DeviceControl - Category that contains the device information and control parameters.
        //@{
        /*!
            \brief Indicates the device clock frequency.

            Indicates the device clock frequency.

            \b Visibility = Expert

            \b Selected by : DeviceClockSelector

        */
        GENAPI_NAMESPACE::IFloat& DeviceClockFrequency;

        //@}


        //! \name CalibrationControl -
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& DefectPixelCorrectionVersion;

        //@}


        //! \name CalibrationControl -
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& DefectPixelTableSize;

        //@}


        //! \name CalibrationControl -
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::ICommand& CalibStore;

        //@}


        //! \name CalibrationControl -
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& CalibLockChallenge;

        //@}


        //! \name CalibrationControl -
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IInteger& CalibLockResponse;

        //@}



    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
        CBconCameraParams_Params( CBconCameraParams_Params& );

        //! not implemented assignment operator
        CBconCameraParams_Params& operator=( CBconCameraParams_Params& );

    //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CBconCameraParams_Params::CBconCameraParams_Params( void )
        : GainSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<GainSelectorEnums>() )
        , Gain( *new GENAPI_NAMESPACE::CFloatRef() )
        , GainRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , GainAuto( *new GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>() )
        , AutoGainLowerLimit( *new GENAPI_NAMESPACE::CFloatRef() )
        , AutoGainLowerLimitRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoGainUpperLimit( *new GENAPI_NAMESPACE::CFloatRef() )
        , AutoGainUpperLimitRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BlackLevelSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<BlackLevelSelectorEnums>() )
        , BlackLevel( *new GENAPI_NAMESPACE::CFloatRef() )
        , BlackLevelRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , GammaRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Gamma( *new GENAPI_NAMESPACE::CFloatRef() )
        , BslColorSpaceMode( *new GENAPI_NAMESPACE::CEnumerationTRef<BslColorSpaceModeEnums>() )
        , SensorWidth( *new GENAPI_NAMESPACE::CIntegerRef() )
        , SensorHeight( *new GENAPI_NAMESPACE::CIntegerRef() )
        , WidthMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , HeightMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Width( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Height( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OffsetX( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OffsetY( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BinningHorizontalMode( *new GENAPI_NAMESPACE::CEnumerationTRef<BinningHorizontalModeEnums>() )
        , BinningHorizontal( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BinningVerticalMode( *new GENAPI_NAMESPACE::CEnumerationTRef<BinningVerticalModeEnums>() )
        , BinningVertical( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ReverseX( *new GENAPI_NAMESPACE::CBooleanRef() )
        , ReverseY( *new GENAPI_NAMESPACE::CBooleanRef() )
        , PixelFormat( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>() )
        , PixelColorFilter( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>() )
        , PixelDynamicRangeMin( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelDynamicRangeMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TestPattern( *new GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>() )
        , AcquisitionMode( *new GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>() )
        , AcquisitionStart( *new GENAPI_NAMESPACE::CCommandRef() )
        , AcquisitionStop( *new GENAPI_NAMESPACE::CCommandRef() )
        , SensorShutterMode( *new GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>() )
        , OverlapMode( *new GENAPI_NAMESPACE::CEnumerationTRef<OverlapModeEnums>() )
        , BslImmediateTriggerMode( *new GENAPI_NAMESPACE::CEnumerationTRef<BslImmediateTriggerModeEnums>() )
        , ExposureTime( *new GENAPI_NAMESPACE::CFloatRef() )
        , ExposureTimeRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ExposureAuto( *new GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>() )
        , AutoExposureTimeLowerLimit( *new GENAPI_NAMESPACE::CFloatRef() )
        , AutoExposureTimeLowerLimitRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoExposureTimeUpperLimit( *new GENAPI_NAMESPACE::CFloatRef() )
        , AutoExposureTimeUpperLimitRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TriggerSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>() )
        , TriggerMode( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>() )
        , TriggerSoftware( *new GENAPI_NAMESPACE::CCommandRef() )
        , TriggerSource( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>() )
        , TriggerActivation( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerActivationEnums>() )
        , ExposureMode( *new GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>() )
        , AcquisitionFramePeriodRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AcquisitionFrameRate( *new GENAPI_NAMESPACE::CFloatRef() )
        , ResultingFrameRate( *new GENAPI_NAMESPACE::CFloatRef() )
        , ResultingFramePeriod( *new GENAPI_NAMESPACE::CIntegerRef() )
        , LightSourcePreset( *new GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>() )
        , BalanceRatioRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BalanceWhiteAuto( *new GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>() )
        , BalanceRatioSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>() )
        , BalanceRatio( *new GENAPI_NAMESPACE::CFloatRef() )
        , BslHueValue( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BslSaturationValueRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BslSaturationValue( *new GENAPI_NAMESPACE::CFloatRef() )
        , ContrastEnhancementRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ContrastEnhancement( *new GENAPI_NAMESPACE::CFloatRef() )
        , BslContrastMode( *new GENAPI_NAMESPACE::CEnumerationTRef<BslContrastModeEnums>() )
        , BslBrightnessRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BslBrightness( *new GENAPI_NAMESPACE::CFloatRef() )
        , BslContrastRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BslContrast( *new GENAPI_NAMESPACE::CFloatRef() )
        , DefectPixelCorrectionMode( *new GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>() )
        , SharpnessEnhancement( *new GENAPI_NAMESPACE::CFloatRef() )
        , LineSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>() )
        , LineMode( *new GENAPI_NAMESPACE::CEnumerationTRef<LineModeEnums>() )
        , LineInverter( *new GENAPI_NAMESPACE::CBooleanRef() )
        , LineSource( *new GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>() )
        , LineFormat( *new GENAPI_NAMESPACE::CEnumerationTRef<LineFormatEnums>() )
        , LineDebouncerTimeRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , LineDebouncerTime( *new GENAPI_NAMESPACE::CFloatRef() )
        , LineStatus( *new GENAPI_NAMESPACE::CBooleanRef() )
        , LineStatusAll( *new GENAPI_NAMESPACE::CIntegerRef() )
        , UserOutputSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<UserOutputSelectorEnums>() )
        , UserOutputValue( *new GENAPI_NAMESPACE::CBooleanRef() )
        , AutoTargetBrightness( *new GENAPI_NAMESPACE::CFloatRef() )
        , AutoTargetBrightnessRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoBacklightCompensation( *new GENAPI_NAMESPACE::CFloatRef() )
        , AutoBacklightCompensationRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoFunctionProfile( *new GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>() )
        , AutoFunctionROISelector( *new GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionROISelectorEnums>() )
        , AutoFunctionROIWidth( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoFunctionROIHeight( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoFunctionROIOffsetX( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoFunctionROIOffsetY( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AutoFunctionROIUseBrightness( *new GENAPI_NAMESPACE::CBooleanRef() )
        , AutoFunctionROIUseWhiteBalance( *new GENAPI_NAMESPACE::CBooleanRef() )
        , UserSetSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>() )
        , UserSetLoad( *new GENAPI_NAMESPACE::CCommandRef() )
        , UserSetSave( *new GENAPI_NAMESPACE::CCommandRef() )
        , UserSetDefault( *new GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>() )
        , TestPendingAck( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TLParamsLocked( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BconPixelsPerClockCycle( *new GENAPI_NAMESPACE::CEnumerationTRef<BconPixelsPerClockCycleEnums>() )
        , BconClockFrequency( *new GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>() )
        , DeviceVendorName( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceModelName( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceManufacturerInfo( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceVersion( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceFirmwareVersion( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceSerialNumber( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceUserID( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceScanType( *new GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>() )
        , DeviceSFNCVersionMajor( *new GENAPI_NAMESPACE::CIntegerRef() )
        , DeviceSFNCVersionMinor( *new GENAPI_NAMESPACE::CIntegerRef() )
        , DeviceSFNCVersionSubMinor( *new GENAPI_NAMESPACE::CIntegerRef() )
        , DeviceReset( *new GENAPI_NAMESPACE::CCommandRef() )
        , BslFirmwareName( *new GENAPI_NAMESPACE::CStringRef() )
        , BslFirmwareLabel( *new GENAPI_NAMESPACE::CStringRef() )
        , BslFirmwareCompatibilityID( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BslDeviceRole( *new GENAPI_NAMESPACE::CEnumerationTRef<BslDeviceRoleEnums>() )
        , BslDeviceRoleKey( *new GENAPI_NAMESPACE::CIntegerRef() )
        , DeviceIndicatorMode( *new GENAPI_NAMESPACE::CEnumerationTRef<DeviceIndicatorModeEnums>() )
        , DeviceRegistersStreamingStart( *new GENAPI_NAMESPACE::CCommandRef() )
        , DeviceRegistersStreamingEnd( *new GENAPI_NAMESPACE::CCommandRef() )
        , DeviceClockSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<DeviceClockSelectorEnums>() )
        , DeviceClockFrequency( *new GENAPI_NAMESPACE::CFloatRef() )
        , DefectPixelCorrectionVersion( *new GENAPI_NAMESPACE::CIntegerRef() )
        , DefectPixelTableSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , CalibStore( *new GENAPI_NAMESPACE::CCommandRef() )
        , CalibLockChallenge( *new GENAPI_NAMESPACE::CIntegerRef() )
        , CalibLockResponse( *new GENAPI_NAMESPACE::CIntegerRef() )

    {
    }

    inline CBconCameraParams_Params::~CBconCameraParams_Params( void )
    {
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<GainSelectorEnums>*> (&GainSelector);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&Gain);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&GainRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>*> (&GainAuto);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AutoGainLowerLimit);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoGainLowerLimitRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AutoGainUpperLimit);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoGainUpperLimitRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BlackLevelSelectorEnums>*> (&BlackLevelSelector);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&BlackLevel);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BlackLevelRaw);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&GammaRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&Gamma);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BslColorSpaceModeEnums>*> (&BslColorSpaceMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&SensorWidth);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&SensorHeight);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&WidthMax);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&HeightMax);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Width);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Height);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&OffsetX);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&OffsetY);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BinningHorizontalModeEnums>*> (&BinningHorizontalMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BinningHorizontal);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BinningVerticalModeEnums>*> (&BinningVerticalMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BinningVertical);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&ReverseX);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&ReverseY);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMin);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMax);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>*> (&TestPattern);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStart);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStop);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>*> (&SensorShutterMode);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<OverlapModeEnums>*> (&OverlapMode);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BslImmediateTriggerModeEnums>*> (&BslImmediateTriggerMode);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&ExposureTime);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ExposureTimeRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>*> (&ExposureAuto);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AutoExposureTimeLowerLimit);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoExposureTimeLowerLimitRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AutoExposureTimeUpperLimit);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoExposureTimeUpperLimitRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&TriggerSoftware);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerActivationEnums>*> (&TriggerActivation);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AcquisitionFramePeriodRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AcquisitionFrameRate);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&ResultingFrameRate);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ResultingFramePeriod);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BalanceRatioRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>*> (&BalanceWhiteAuto);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&BalanceRatio);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BslHueValue);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BslSaturationValueRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&BslSaturationValue);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ContrastEnhancementRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&ContrastEnhancement);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BslContrastModeEnums>*> (&BslContrastMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BslBrightnessRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&BslBrightness);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BslContrastRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&BslContrast);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>*> (&DefectPixelCorrectionMode);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&SharpnessEnhancement);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LineModeEnums>*> (&LineMode);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&LineInverter);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LineFormatEnums>*> (&LineFormat);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&LineDebouncerTimeRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&LineDebouncerTime);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&LineStatus);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&LineStatusAll);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<UserOutputSelectorEnums>*> (&UserOutputSelector);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&UserOutputValue);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AutoTargetBrightness);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoTargetBrightnessRaw);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AutoBacklightCompensation);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoBacklightCompensationRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionROISelectorEnums>*> (&AutoFunctionROISelector);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIWidth);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIHeight);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIOffsetX);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIOffsetY);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&AutoFunctionROIUseBrightness);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&AutoFunctionROIUseWhiteBalance);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&UserSetLoad);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&UserSetSave);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&TestPendingAck);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&TLParamsLocked);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BconPixelsPerClockCycleEnums>*> (&BconPixelsPerClockCycle);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceVendorName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceModelName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceManufacturerInfo);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceVersion);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceFirmwareVersion);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceSerialNumber);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceUserID);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&DeviceSFNCVersionMajor);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&DeviceSFNCVersionMinor);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&DeviceSFNCVersionSubMinor);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&DeviceReset);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&BslFirmwareName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&BslFirmwareLabel);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BslFirmwareCompatibilityID);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BslDeviceRoleEnums>*> (&BslDeviceRole);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BslDeviceRoleKey);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<DeviceIndicatorModeEnums>*> (&DeviceIndicatorMode);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&DeviceRegistersStreamingStart);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&DeviceRegistersStreamingEnd);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<DeviceClockSelectorEnums>*> (&DeviceClockSelector);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&DeviceClockFrequency);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&DefectPixelCorrectionVersion);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&DefectPixelTableSize);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&CalibStore);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&CalibLockChallenge);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&CalibLockResponse);

    }

    inline void CBconCameraParams_Params::_Initialize( GENAPI_NAMESPACE::INodeMap* _Ptr )
    {
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainSelectorEnums>*> (&GainSelector)->SetReference( _Ptr->GetNode( "GainSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainSelectorEnums>*> (&GainSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainSelectorEnums>*> (&GainSelector)->SetEnumReference( GainSelector_All, "All" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&Gain)->SetReference( _Ptr->GetNode( "Gain" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&GainRaw)->SetReference( _Ptr->GetNode( "GainRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>*> (&GainAuto)->SetReference( _Ptr->GetNode( "GainAuto" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>*> (&GainAuto)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>*> (&GainAuto)->SetEnumReference( GainAuto_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>*> (&GainAuto)->SetEnumReference( GainAuto_Once, "Once" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainAutoEnums>*> (&GainAuto)->SetEnumReference( GainAuto_Continuous, "Continuous" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AutoGainLowerLimit)->SetReference( _Ptr->GetNode( "AutoGainLowerLimit" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoGainLowerLimitRaw)->SetReference( _Ptr->GetNode( "AutoGainLowerLimitRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AutoGainUpperLimit)->SetReference( _Ptr->GetNode( "AutoGainUpperLimit" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoGainUpperLimitRaw)->SetReference( _Ptr->GetNode( "AutoGainUpperLimitRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BlackLevelSelectorEnums>*> (&BlackLevelSelector)->SetReference( _Ptr->GetNode( "BlackLevelSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BlackLevelSelectorEnums>*> (&BlackLevelSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BlackLevelSelectorEnums>*> (&BlackLevelSelector)->SetEnumReference( BlackLevelSelector_All, "All" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&BlackLevel)->SetReference( _Ptr->GetNode( "BlackLevel" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BlackLevelRaw)->SetReference( _Ptr->GetNode( "BlackLevelRaw" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&GammaRaw)->SetReference( _Ptr->GetNode( "GammaRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&Gamma)->SetReference( _Ptr->GetNode( "Gamma" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslColorSpaceModeEnums>*> (&BslColorSpaceMode)->SetReference( _Ptr->GetNode( "BslColorSpaceMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslColorSpaceModeEnums>*> (&BslColorSpaceMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslColorSpaceModeEnums>*> (&BslColorSpaceMode)->SetEnumReference( BslColorSpaceMode_RGB, "RGB" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslColorSpaceModeEnums>*> (&BslColorSpaceMode)->SetEnumReference( BslColorSpaceMode_sRGB, "sRGB" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&SensorWidth)->SetReference( _Ptr->GetNode( "SensorWidth" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&SensorHeight)->SetReference( _Ptr->GetNode( "SensorHeight" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&WidthMax)->SetReference( _Ptr->GetNode( "WidthMax" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&HeightMax)->SetReference( _Ptr->GetNode( "HeightMax" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Width)->SetReference( _Ptr->GetNode( "Width" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Height)->SetReference( _Ptr->GetNode( "Height" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&OffsetX)->SetReference( _Ptr->GetNode( "OffsetX" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&OffsetY)->SetReference( _Ptr->GetNode( "OffsetY" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningHorizontalModeEnums>*> (&BinningHorizontalMode)->SetReference( _Ptr->GetNode( "BinningHorizontalMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningHorizontalModeEnums>*> (&BinningHorizontalMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningHorizontalModeEnums>*> (&BinningHorizontalMode)->SetEnumReference( BinningHorizontalMode_Average, "Average" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningHorizontalModeEnums>*> (&BinningHorizontalMode)->SetEnumReference( BinningHorizontalMode_Sum, "Sum" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BinningHorizontal)->SetReference( _Ptr->GetNode( "BinningHorizontal" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningVerticalModeEnums>*> (&BinningVerticalMode)->SetReference( _Ptr->GetNode( "BinningVerticalMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningVerticalModeEnums>*> (&BinningVerticalMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningVerticalModeEnums>*> (&BinningVerticalMode)->SetEnumReference( BinningVerticalMode_Average, "Average" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BinningVerticalModeEnums>*> (&BinningVerticalMode)->SetEnumReference( BinningVerticalMode_Sum, "Sum" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BinningVertical)->SetReference( _Ptr->GetNode( "BinningVertical" ) );
        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&ReverseX)->SetReference( _Ptr->GetNode( "ReverseX" ) );
        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&ReverseY)->SetReference( _Ptr->GetNode( "ReverseY" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetReference( _Ptr->GetNode( "PixelFormat" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetNumEnums( 12 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_RGB8, "RGB8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_YCbCr422_8, "YCbCr422_8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerGR8, "BayerGR8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerGR12, "BayerGR12" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_Mono8, "Mono8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_Mono12, "Mono12" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerBG8, "BayerBG8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerGB8, "BayerGB8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerRG8, "BayerRG8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerBG12, "BayerBG12" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerGB12, "BayerGB12" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerRG12, "BayerRG12" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetReference( _Ptr->GetNode( "PixelColorFilter" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetNumEnums( 5 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetEnumReference( PixelColorFilter_None, "None" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetEnumReference( PixelColorFilter_BayerGR, "BayerGR" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetEnumReference( PixelColorFilter_BayerRG, "BayerRG" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetEnumReference( PixelColorFilter_BayerGB, "BayerGB" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelColorFilterEnums>*> (&PixelColorFilter)->SetEnumReference( PixelColorFilter_BayerBG, "BayerBG" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMin)->SetReference( _Ptr->GetNode( "PixelDynamicRangeMin" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMax)->SetReference( _Ptr->GetNode( "PixelDynamicRangeMax" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>*> (&TestPattern)->SetReference( _Ptr->GetNode( "TestPattern" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>*> (&TestPattern)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>*> (&TestPattern)->SetEnumReference( TestPattern_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>*> (&TestPattern)->SetEnumReference( TestPattern_GreyDiagonalSawtooth8, "GreyDiagonalSawtooth8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestPatternEnums>*> (&TestPattern)->SetEnumReference( TestPattern_ColorDiagonalSawtooth8, "ColorDiagonalSawtooth8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetReference( _Ptr->GetNode( "AcquisitionMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetEnumReference( AcquisitionMode_SingleFrame, "SingleFrame" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetEnumReference( AcquisitionMode_Continuous, "Continuous" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStart)->SetReference( _Ptr->GetNode( "AcquisitionStart" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStop)->SetReference( _Ptr->GetNode( "AcquisitionStop" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>*> (&SensorShutterMode)->SetReference( _Ptr->GetNode( "SensorShutterMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>*> (&SensorShutterMode)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>*> (&SensorShutterMode)->SetEnumReference( SensorShutterMode_Global, "Global" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>*> (&SensorShutterMode)->SetEnumReference( SensorShutterMode_Rolling, "Rolling" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<SensorShutterModeEnums>*> (&SensorShutterMode)->SetEnumReference( SensorShutterMode_GlobalReset, "GlobalReset" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<OverlapModeEnums>*> (&OverlapMode)->SetReference( _Ptr->GetNode( "OverlapMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<OverlapModeEnums>*> (&OverlapMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<OverlapModeEnums>*> (&OverlapMode)->SetEnumReference( OverlapMode_On, "On" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<OverlapModeEnums>*> (&OverlapMode)->SetEnumReference( OverlapMode_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslImmediateTriggerModeEnums>*> (&BslImmediateTriggerMode)->SetReference( _Ptr->GetNode( "BslImmediateTriggerMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslImmediateTriggerModeEnums>*> (&BslImmediateTriggerMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslImmediateTriggerModeEnums>*> (&BslImmediateTriggerMode)->SetEnumReference( BslImmediateTriggerMode_On, "On" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslImmediateTriggerModeEnums>*> (&BslImmediateTriggerMode)->SetEnumReference( BslImmediateTriggerMode_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&ExposureTime)->SetReference( _Ptr->GetNode( "ExposureTime" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ExposureTimeRaw)->SetReference( _Ptr->GetNode( "ExposureTimeRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>*> (&ExposureAuto)->SetReference( _Ptr->GetNode( "ExposureAuto" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>*> (&ExposureAuto)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>*> (&ExposureAuto)->SetEnumReference( ExposureAuto_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>*> (&ExposureAuto)->SetEnumReference( ExposureAuto_Once, "Once" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureAutoEnums>*> (&ExposureAuto)->SetEnumReference( ExposureAuto_Continuous, "Continuous" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AutoExposureTimeLowerLimit)->SetReference( _Ptr->GetNode( "AutoExposureTimeLowerLimit" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoExposureTimeLowerLimitRaw)->SetReference( _Ptr->GetNode( "AutoExposureTimeLowerLimitRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AutoExposureTimeUpperLimit)->SetReference( _Ptr->GetNode( "AutoExposureTimeUpperLimit" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoExposureTimeUpperLimitRaw)->SetReference( _Ptr->GetNode( "AutoExposureTimeUpperLimitRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector)->SetReference( _Ptr->GetNode( "TriggerSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector)->SetEnumReference( TriggerSelector_FrameStart, "FrameStart" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetReference( _Ptr->GetNode( "TriggerMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetEnumReference( TriggerMode_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetEnumReference( TriggerMode_On, "On" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&TriggerSoftware)->SetReference( _Ptr->GetNode( "TriggerSoftware" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetReference( _Ptr->GetNode( "TriggerSource" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetEnumReference( TriggerSource_Software, "Software" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetEnumReference( TriggerSource_Line1, "Line1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetEnumReference( TriggerSource_Line3, "Line3" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerActivationEnums>*> (&TriggerActivation)->SetReference( _Ptr->GetNode( "TriggerActivation" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerActivationEnums>*> (&TriggerActivation)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerActivationEnums>*> (&TriggerActivation)->SetEnumReference( TriggerActivation_RisingEdge, "RisingEdge" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerActivationEnums>*> (&TriggerActivation)->SetEnumReference( TriggerActivation_FallingEdge, "FallingEdge" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetReference( _Ptr->GetNode( "ExposureMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_Timed, "Timed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_TriggerWidth, "TriggerWidth" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AcquisitionFramePeriodRaw)->SetReference( _Ptr->GetNode( "AcquisitionFramePeriodRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AcquisitionFrameRate)->SetReference( _Ptr->GetNode( "AcquisitionFrameRate" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&ResultingFrameRate)->SetReference( _Ptr->GetNode( "ResultingFrameRate" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ResultingFramePeriod)->SetReference( _Ptr->GetNode( "ResultingFramePeriod" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset)->SetReference( _Ptr->GetNode( "LightSourcePreset" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset)->SetNumEnums( 4 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset)->SetEnumReference( LightSourcePreset_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset)->SetEnumReference( LightSourcePreset_Tungsten2800K, "Tungsten2800K" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset)->SetEnumReference( LightSourcePreset_Daylight5000K, "Daylight5000K" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LightSourcePresetEnums>*> (&LightSourcePreset)->SetEnumReference( LightSourcePreset_Daylight6500K, "Daylight6500K" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BalanceRatioRaw)->SetReference( _Ptr->GetNode( "BalanceRatioRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>*> (&BalanceWhiteAuto)->SetReference( _Ptr->GetNode( "BalanceWhiteAuto" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>*> (&BalanceWhiteAuto)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>*> (&BalanceWhiteAuto)->SetEnumReference( BalanceWhiteAuto_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>*> (&BalanceWhiteAuto)->SetEnumReference( BalanceWhiteAuto_Once, "Once" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceWhiteAutoEnums>*> (&BalanceWhiteAuto)->SetEnumReference( BalanceWhiteAuto_Continuous, "Continuous" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetReference( _Ptr->GetNode( "BalanceRatioSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetEnumReference( BalanceRatioSelector_Red, "Red" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetEnumReference( BalanceRatioSelector_Green, "Green" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetEnumReference( BalanceRatioSelector_Blue, "Blue" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&BalanceRatio)->SetReference( _Ptr->GetNode( "BalanceRatio" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BslHueValue)->SetReference( _Ptr->GetNode( "BslHueValue" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BslSaturationValueRaw)->SetReference( _Ptr->GetNode( "BslSaturationValueRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&BslSaturationValue)->SetReference( _Ptr->GetNode( "BslSaturationValue" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ContrastEnhancementRaw)->SetReference( _Ptr->GetNode( "ContrastEnhancementRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&ContrastEnhancement)->SetReference( _Ptr->GetNode( "ContrastEnhancement" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslContrastModeEnums>*> (&BslContrastMode)->SetReference( _Ptr->GetNode( "BslContrastMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslContrastModeEnums>*> (&BslContrastMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslContrastModeEnums>*> (&BslContrastMode)->SetEnumReference( BslContrastMode_Linear, "Linear" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslContrastModeEnums>*> (&BslContrastMode)->SetEnumReference( BslContrastMode_SCurve, "SCurve" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BslBrightnessRaw)->SetReference( _Ptr->GetNode( "BslBrightnessRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&BslBrightness)->SetReference( _Ptr->GetNode( "BslBrightness" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BslContrastRaw)->SetReference( _Ptr->GetNode( "BslContrastRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&BslContrast)->SetReference( _Ptr->GetNode( "BslContrast" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>*> (&DefectPixelCorrectionMode)->SetReference( _Ptr->GetNode( "DefectPixelCorrectionMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>*> (&DefectPixelCorrectionMode)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>*> (&DefectPixelCorrectionMode)->SetEnumReference( DefectPixelCorrectionMode_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>*> (&DefectPixelCorrectionMode)->SetEnumReference( DefectPixelCorrectionMode_On, "On" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DefectPixelCorrectionModeEnums>*> (&DefectPixelCorrectionMode)->SetEnumReference( DefectPixelCorrectionMode_StaticOnly, "StaticOnly" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&SharpnessEnhancement)->SetReference( _Ptr->GetNode( "SharpnessEnhancement" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetReference( _Ptr->GetNode( "LineSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetEnumReference( LineSelector_Line1, "Line1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetEnumReference( LineSelector_Line2, "Line2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetEnumReference( LineSelector_Line3, "Line3" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineModeEnums>*> (&LineMode)->SetReference( _Ptr->GetNode( "LineMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineModeEnums>*> (&LineMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineModeEnums>*> (&LineMode)->SetEnumReference( LineMode_Input, "Input" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineModeEnums>*> (&LineMode)->SetEnumReference( LineMode_Output, "Output" );        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&LineInverter)->SetReference( _Ptr->GetNode( "LineInverter" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetReference( _Ptr->GetNode( "LineSource" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetNumEnums( 6 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_ExposureActive, "ExposureActive" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_UserOutput1, "UserOutput1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_UserOutput2, "UserOutput2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_UserOutput3, "UserOutput3" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_UserOutput4, "UserOutput4" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_FlashWindow, "FlashWindow" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineFormatEnums>*> (&LineFormat)->SetReference( _Ptr->GetNode( "LineFormat" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineFormatEnums>*> (&LineFormat)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineFormatEnums>*> (&LineFormat)->SetEnumReference( LineFormat_LVDS, "LVDS" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&LineDebouncerTimeRaw)->SetReference( _Ptr->GetNode( "LineDebouncerTimeRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&LineDebouncerTime)->SetReference( _Ptr->GetNode( "LineDebouncerTime" ) );
        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&LineStatus)->SetReference( _Ptr->GetNode( "LineStatus" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&LineStatusAll)->SetReference( _Ptr->GetNode( "LineStatusAll" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserOutputSelectorEnums>*> (&UserOutputSelector)->SetReference( _Ptr->GetNode( "UserOutputSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserOutputSelectorEnums>*> (&UserOutputSelector)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserOutputSelectorEnums>*> (&UserOutputSelector)->SetEnumReference( UserOutputSelector_UserOutput1, "UserOutput1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserOutputSelectorEnums>*> (&UserOutputSelector)->SetEnumReference( UserOutputSelector_UserOutput2, "UserOutput2" );        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&UserOutputValue)->SetReference( _Ptr->GetNode( "UserOutputValue" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AutoTargetBrightness)->SetReference( _Ptr->GetNode( "AutoTargetBrightness" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoTargetBrightnessRaw)->SetReference( _Ptr->GetNode( "AutoTargetBrightnessRaw" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AutoBacklightCompensation)->SetReference( _Ptr->GetNode( "AutoBacklightCompensation" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoBacklightCompensationRaw)->SetReference( _Ptr->GetNode( "AutoBacklightCompensationRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetReference( _Ptr->GetNode( "AutoFunctionProfile" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetNumEnums( 5 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetEnumReference( AutoFunctionProfile_Smart, "Smart" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetEnumReference( AutoFunctionProfile_MinimizeGain, "MinimizeGain" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetEnumReference( AutoFunctionProfile_MinimizeExposureTime, "MinimizeExposureTime" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetEnumReference( AutoFunctionProfile_AntiFlicker50Hz, "AntiFlicker50Hz" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionProfileEnums>*> (&AutoFunctionProfile)->SetEnumReference( AutoFunctionProfile_AntiFlicker60Hz, "AntiFlicker60Hz" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionROISelectorEnums>*> (&AutoFunctionROISelector)->SetReference( _Ptr->GetNode( "AutoFunctionROISelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionROISelectorEnums>*> (&AutoFunctionROISelector)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionROISelectorEnums>*> (&AutoFunctionROISelector)->SetEnumReference( AutoFunctionROISelector_ROI1, "ROI1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AutoFunctionROISelectorEnums>*> (&AutoFunctionROISelector)->SetEnumReference( AutoFunctionROISelector_ROI2, "ROI2" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIWidth)->SetReference( _Ptr->GetNode( "AutoFunctionROIWidth" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIHeight)->SetReference( _Ptr->GetNode( "AutoFunctionROIHeight" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIOffsetX)->SetReference( _Ptr->GetNode( "AutoFunctionROIOffsetX" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AutoFunctionROIOffsetY)->SetReference( _Ptr->GetNode( "AutoFunctionROIOffsetY" ) );
        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&AutoFunctionROIUseBrightness)->SetReference( _Ptr->GetNode( "AutoFunctionROIUseBrightness" ) );
        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&AutoFunctionROIUseWhiteBalance)->SetReference( _Ptr->GetNode( "AutoFunctionROIUseWhiteBalance" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetReference( _Ptr->GetNode( "UserSetSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetNumEnums( 4 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetEnumReference( UserSetSelector_Default, "Default" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetEnumReference( UserSetSelector_UserSet1, "UserSet1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetEnumReference( UserSetSelector_UserSet2, "UserSet2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetEnumReference( UserSetSelector_UserSet3, "UserSet3" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&UserSetLoad)->SetReference( _Ptr->GetNode( "UserSetLoad" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&UserSetSave)->SetReference( _Ptr->GetNode( "UserSetSave" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault)->SetReference( _Ptr->GetNode( "UserSetDefault" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault)->SetNumEnums( 4 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault)->SetEnumReference( UserSetDefault_Default, "Default" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault)->SetEnumReference( UserSetDefault_UserSet1, "UserSet1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault)->SetEnumReference( UserSetDefault_UserSet2, "UserSet2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetDefaultEnums>*> (&UserSetDefault)->SetEnumReference( UserSetDefault_UserSet3, "UserSet3" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TestPendingAck)->SetReference( _Ptr->GetNode( "TestPendingAck" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&TLParamsLocked)->SetReference( _Ptr->GetNode( "TLParamsLocked" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconPixelsPerClockCycleEnums>*> (&BconPixelsPerClockCycle)->SetReference( _Ptr->GetNode( "BconPixelsPerClockCycle" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconPixelsPerClockCycleEnums>*> (&BconPixelsPerClockCycle)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconPixelsPerClockCycleEnums>*> (&BconPixelsPerClockCycle)->SetEnumReference( BconPixelsPerClockCycle_One, "One" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconPixelsPerClockCycleEnums>*> (&BconPixelsPerClockCycle)->SetEnumReference( BconPixelsPerClockCycle_Two, "Two" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetReference( _Ptr->GetNode( "BconClockFrequency" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetNumEnums( 10 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_84, "MHz_84" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_76, "MHz_76" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_68, "MHz_68" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_60, "MHz_60" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_52, "MHz_52" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_44, "MHz_44" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_36, "MHz_36" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_28, "MHz_28" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_20, "MHz_20" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BconClockFrequencyEnums>*> (&BconClockFrequency)->SetEnumReference( BconClockFrequency_MHz_12, "MHz_12" );        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceVendorName)->SetReference( _Ptr->GetNode( "DeviceVendorName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceModelName)->SetReference( _Ptr->GetNode( "DeviceModelName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceManufacturerInfo)->SetReference( _Ptr->GetNode( "DeviceManufacturerInfo" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceVersion)->SetReference( _Ptr->GetNode( "DeviceVersion" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceFirmwareVersion)->SetReference( _Ptr->GetNode( "DeviceFirmwareVersion" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceSerialNumber)->SetReference( _Ptr->GetNode( "DeviceSerialNumber" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceUserID)->SetReference( _Ptr->GetNode( "DeviceUserID" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetReference( _Ptr->GetNode( "DeviceScanType" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetEnumReference( DeviceScanType_Areascan, "Areascan" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&DeviceSFNCVersionMajor)->SetReference( _Ptr->GetNode( "DeviceSFNCVersionMajor" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&DeviceSFNCVersionMinor)->SetReference( _Ptr->GetNode( "DeviceSFNCVersionMinor" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&DeviceSFNCVersionSubMinor)->SetReference( _Ptr->GetNode( "DeviceSFNCVersionSubMinor" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&DeviceReset)->SetReference( _Ptr->GetNode( "DeviceReset" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&BslFirmwareName)->SetReference( _Ptr->GetNode( "BslFirmwareName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&BslFirmwareLabel)->SetReference( _Ptr->GetNode( "BslFirmwareLabel" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BslFirmwareCompatibilityID)->SetReference( _Ptr->GetNode( "BslFirmwareCompatibilityID" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslDeviceRoleEnums>*> (&BslDeviceRole)->SetReference( _Ptr->GetNode( "BslDeviceRole" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslDeviceRoleEnums>*> (&BslDeviceRole)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslDeviceRoleEnums>*> (&BslDeviceRole)->SetEnumReference( BslDeviceRole_Camera, "Camera" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BslDeviceRoleEnums>*> (&BslDeviceRole)->SetEnumReference( BslDeviceRole_Updater, "Updater" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BslDeviceRoleKey)->SetReference( _Ptr->GetNode( "BslDeviceRoleKey" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceIndicatorModeEnums>*> (&DeviceIndicatorMode)->SetReference( _Ptr->GetNode( "DeviceIndicatorMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceIndicatorModeEnums>*> (&DeviceIndicatorMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceIndicatorModeEnums>*> (&DeviceIndicatorMode)->SetEnumReference( DeviceIndicatorMode_Inactive, "Inactive" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceIndicatorModeEnums>*> (&DeviceIndicatorMode)->SetEnumReference( DeviceIndicatorMode_Active, "Active" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&DeviceRegistersStreamingStart)->SetReference( _Ptr->GetNode( "DeviceRegistersStreamingStart" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&DeviceRegistersStreamingEnd)->SetReference( _Ptr->GetNode( "DeviceRegistersStreamingEnd" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceClockSelectorEnums>*> (&DeviceClockSelector)->SetReference( _Ptr->GetNode( "DeviceClockSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceClockSelectorEnums>*> (&DeviceClockSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceClockSelectorEnums>*> (&DeviceClockSelector)->SetEnumReference( DeviceClockSelector_Bcon, "Bcon" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&DeviceClockFrequency)->SetReference( _Ptr->GetNode( "DeviceClockFrequency" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&DefectPixelCorrectionVersion)->SetReference( _Ptr->GetNode( "DefectPixelCorrectionVersion" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&DefectPixelTableSize)->SetReference( _Ptr->GetNode( "DefectPixelTableSize" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&CalibStore)->SetReference( _Ptr->GetNode( "CalibStore" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&CalibLockChallenge)->SetReference( _Ptr->GetNode( "CalibLockChallenge" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&CalibLockResponse)->SetReference( _Ptr->GetNode( "CalibLockResponse" ) );

    }

    inline const char* CBconCameraParams_Params::_GetVendorName( void )
    {
        return "Basler";
    }

    inline const char* CBconCameraParams_Params::_GetModelName( void )
    {
        return "BconCameraParams";
    }

    //! \endcond

} // namespace Basler_BconCameraParams

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#   endif
#endif

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_BconCameraParams_PARAMS_H
