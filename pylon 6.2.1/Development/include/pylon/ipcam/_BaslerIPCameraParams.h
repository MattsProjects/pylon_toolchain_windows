

//-----------------------------------------------------------------------------
//  Copyright (c) 2004-2021 Basler AG
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Basler IP Camera interface
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_BaslerIPCamera_PARAMS_H
#define Basler_BaslerIPCamera_PARAMS_H

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
namespace Basler_BaslerIPCamera
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_EXPOSUREMODE_PRIO_NONE,  //!<Automatic exposure control - no priority
        ExposureMode_EXPOSUREMODE_PRIO_FRAMERATE,  //!<Automatic exposure control - priorize framerate
        ExposureMode_EXPOSUREMODE_PRIO_QUALITY,  //!<Automatic exposure control - priorize quality
        ExposureMode_EXPOSUREMODE_MANUAL_GAIN,  //!<Automatic exposure control - manual gain
        ExposureMode_EXPOSUREMODE_MANUAL_EXPOSURETIME,  //!<Automatic exposure control - manual exposure time
        ExposureMode_EXPOSUREMODE_MANUAL   //!<TODO

    };

    //! Valid values for ShutterMode
    enum ShutterModeEnums
    {
        ShutterMode_SHUTTERMODE_AUTO,  //!<Automatic shutter control
        ShutterMode_SHUTTERMODE_MANUAL   //!<TODO

    };

    //! Valid values for GainMode
    enum GainModeEnums
    {
        GainMode_GAINMODE_AUTO,  //!<Automatic shutter control
        GainMode_GAINMODE_MANUAL   //!<TODO

    };

    //! Valid values for IrisMode
    enum IrisModeEnums
    {
        IrisMode_IRISMODE_AUTO,  //!<Automatic shutter control
        IrisMode_IRISMODE_OPEN,  //!<TODO
        IrisMode_IRISMODE_CLOSE,  //!<TODO
        IrisMode_IRISMODE_MANUAL   //!<TODO

    };

    //! Valid values for WhiteBalanceMode
    enum WhiteBalanceModeEnums
    {
        WhiteBalanceMode_WHITEBALANCEMODE_AUTO,  //!<Automatic shutter control
        WhiteBalanceMode_WHITEBALANCEMODE_AUTO2,  //!<Automatic shutter control
        WhiteBalanceMode_WHITEBALANCEMODE_DAYLIGHT,  //!<TODO
        WhiteBalanceMode_WHITEBALANCEMODE_INCANDESCENT,  //!<TODO
        WhiteBalanceMode_WHITEBALANCEMODE_FLUORESCENT_1,  //!<TODO
        WhiteBalanceMode_WHITEBALANCEMODE_FLUORESCENT_2,  //!<TODO
        WhiteBalanceMode_WHITEBALANCEMODE_MANUAL,  //!<TODO
        WhiteBalanceMode_WHITEBALANCEMODE_MANUAL_RGB   //!<TODO

    };

    //! Valid values for IRFilterMode
    enum IRFilterModeEnums
    {
        IRFilterMode_IRFILTER_AUTO,  //!<Automatic shutter control
        IRFilterMode_IRFILTER_OPEN,  //!<TODO
        IRFilterMode_IRFILTER_CLOSE,  //!<TODO
        IRFilterMode_IRFILTER_WHATEVER5   //!<TODO

    };

    //! Valid values for BalanceRatioSelector
    enum BalanceRatioSelectorEnums
    {
        BalanceRatioSelector_Red,  //!<Selects the red balance ratio control for adjustment
        BalanceRatioSelector_Green,  //!<Selects the green balance ratio control for adjustment
        BalanceRatioSelector_Blue   //!<Selects the blue balance ratio control for adjustment

    };

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_Unsupported,  //!<Sets the pixel format to Mono 8
        PixelFormat_BGR8Packed,  //!<Sets the pixel format to YUV JPEG
        PixelFormat_BayerBG8,  //!<Sets the pixel format to Bayer GB 8
        PixelFormat_BayerBG16   //!<Sets the pixel format to Bayer BG 16

    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp8,  //!<Indicates that the depth of the pixel values in the acquired images is 8 bits per pixel
        PixelSize_Bpp16,  //!<Indicates that the depth of the pixel values in the acquired images is 16 bits per pixel
        PixelSize_Bpp24   //!<Indicates that the depth of the pixel values in the acquired images is 24 bits per pixel

    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!<Sets the camera's test image generation capability to disabled
        TestImageSelector_Testimage1,  //!<Sets the camera to generate and transmit test images with a test image 1 pattern
        TestImageSelector_Testimage2,  //!<Sets the camera to generate and transmit test images with a test image 2 pattern
        TestImageSelector_Testimage3,  //!<Sets the camera to generate and transmit test images with a test image 3 pattern
        TestImageSelector_Testimage4,  //!<Sets the camera to generate and transmit test images with a test image 4 pattern
        TestImageSelector_Testimage5,  //!<Sets the camera to generate and transmit test images with a test image 5 pattern
        TestImageSelector_Testimage6,  //!<Sets the camera to generate and transmit test images with a test image 6 pattern
        TestImageSelector_Testimage7   //!<Sets the camera to generate and transmit test images with a test image 6 pattern

    };

    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_SingleFrame,  //!<Sets the acquisition mode to single frame
        AcquisitionMode_Continuous   //!<Sets the acquisition mode to continuous

    };

    //! Valid values for LineSelector
    enum LineSelectorEnums
    {
        LineSelector_Line1,  //!<Selects input line 1 for configuration
        LineSelector_Out1   //!<Selects output line 1 for configuration

    };

    //! Valid values for LineSource
    enum LineSourceEnums
    {
        LineSource_UserOutput   //!<

    };

    //! Valid values for DeviceScanType
    enum DeviceScanTypeEnums
    {
        DeviceScanType_Areascan,  //!<Indicates that the device has an area scan type of sensor
        DeviceScanType_Linescan   //!<Indicates that the device has an Line scan type of sensor

    };

    //! Valid values for TemperatureSelector
    enum TemperatureSelectorEnums
    {
        TemperatureSelector_Sensorboard   //!<Temperature on sensor board

    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************


    //! Basler IP Camera interface
    class CBaslerIPCamera_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS

            //! Constructor
        CBaslerIPCamera_Params( void );

        //! Destructor
        ~CBaslerIPCamera_Params( void );

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

    //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
    //@{
    /*!
        \brief



        \b Visibility = Beginner


    */
        GENAPI_NAMESPACE::IString& FactoryMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<ExposureModeEnums >& ExposureMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<ShutterModeEnums >& ShutterMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<GainModeEnums >& GainMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<IrisModeEnums >& IrisMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& IrisDutyCycle;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& IrisPeriod;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief TODO

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<WhiteBalanceModeEnums >& WhiteBalanceMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief !tbd

            !tbd

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& AdcAdr;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief !tbd

            !tbd

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& AdcVal;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief State of the IR cut filter

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<IRFilterModeEnums >& IRFilterMode;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& CoreBoardId;

        //@}


        //! \name IpcamControls - This category includes items that are specific to the Basler IPCAM
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& SensorBoardId;

        //@}


        //! \name ImageControls - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief This is an integer value that sets the selected gain control in device specific units

            Sets the 'raw' value of the selected gain control. The 'raw' value is an integer value that sets the selected gain control in units specific to the camera.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& GainRaw;

        //@}


        //! \name ImageControls - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief !tbd

            !tbd

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& BrightnessRaw;

        //@}


        //! \name ImageControls - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief Selects a balance ratio to configure. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.

            This enumeration selects a balance ratio control to configuration. Once a balance ratio control has been selected, all changes to the balance ratio settings will be applied to the selected control.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<BalanceRatioSelectorEnums >& BalanceRatioSelector;

        //@}


        //! \name ImageControls - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief Sets the value of the selected balance ratio control as an integer

            This value sets the selected balance ratio control as an integer.

            \b Visibility = Beginner


            \b Selected by : BalanceRatioSelector

        */
        GENAPI_NAMESPACE::IInteger& BalanceRatioRaw;

        //@}


        //! \name ImageControls - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& WhitePoint_X;

        //@}


        //! \name ImageControls - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& WhitePoint_Y;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Sets the format of the pixel data transmitted for acquired images

            This enumeration sets the format of the pixel data transmitted for acquired images.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<PixelFormatEnums >& PixelFormat;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Indicates the depth of the pixel values in the image in bits per pixel

            This is a read only feature. This enumeration provides a list of values that indicate the depth of the pixel values in the acquired images in bits per pixel. This value will always be coherent with the pixel format setting.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<PixelSizeEnums >& PixelSize;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Indicates the minimum possible pixel value that could be transferred from the camera

            This a read only feature. It indicates the minimum possible pixel value that could be transferred from the camera.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& PixelDynamicRangeMin;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Indicates the maximum possible pixel value that could be transferred from the camera

            This a read only feature. It indicates the maximum possible pixel value that could be transferred from the camera.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& PixelDynamicRangeMax;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Selecting a test image from the list will enable the test image

            This enumeration provides a list of the available test images. Selecting a test image from the list will enable the test image.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<TestImageSelectorEnums >& TestImageSelector;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Quality of the Jpeg

            Quality of the Jpeg

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Quality;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief Quality of the Jpeg for CTT

            Quality of the Jpeg for CTT

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& CTTJpegQuality;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& OverlayText;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest
        //@{
        /*!
            \brief Sets the width of the area of interest in pixels

            This value sets the width of the area of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Width;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest
        //@{
        /*!
            \brief Sets the height of the area of interest in pixels

            This value sets the height of the area of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Height;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest
        //@{
        /*!
            \brief Sets the X offset (left offset) of the area of interest in pixels

            This value sets the X offset (left offset) for the area of interest in pixels, i.e., the distance in pixels between the left side of the sensor and the left side of the image area.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& OffsetX;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest
        //@{
        /*!
            \brief Sets the Y offset (top offset) for the area of interest in pixels

            This value sets the Y offset (top offset) for the area of interest, i.e., the distance in pixels between the top of the sensor and the top of the image area.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& OffsetY;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest
        //@{
        /*!
            \brief Displays the total width

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& WidthMax;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest
        //@{
        /*!
            \brief Displays the total height

            TODO

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& HeightMax;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
        //@{
        /*!
            \brief Controls the Absolute exposure time in microseconds (us).

            Controls the Absolute exposure time in microseconds (us).

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& ExposureTimeAbs;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
        //@{
        /*!
            \brief Sets the image acquisition mode

            This enumeration sets the image acquisition mode.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<AcquisitionModeEnums >& AcquisitionMode;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
        //@{
        /*!
            \brief Starts the acquisition of images

            This command starts the acquisition of images. If the camera is set for single frame acquisition, it will start acquisition of one frame. If the camera is set for continuous frame acquisition, it will start continuous acquisition of frames.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& AcquisitionStart;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition
        //@{
        /*!
            \brief Stops the acquisition of images

            If the camera is set for continuous image acquisition and acquisition has been started, this command stops the acquisition of images.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& AcquisitionStop;

        //@}


        //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
        //@{
        /*!
            \brief Selects the I/O line to configure. Once a line has been selected, all changes to the line settings will be applied to the selected line.

            This enumeration selects the I/O line to configure. Once a line has been selected, all changes to the line settings will be applied to the selected line.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<LineSelectorEnums >& LineSelector;

        //@}


        //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
        //@{
        /*!
            \brief Sets the source signal for the selected line (if the selected line is an output)

            This enumeration selects the internally generated camera signal (source signal) for the selected line when the selected line is an output.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<LineSourceEnums >& LineSource;

        //@}


        //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
        //@{
        /*!
            \brief A single bitfield indicating the current logical state of all available line signals at time of polling

            This integer value is a single bitfield that indicates the current logical state of all available lines at time of polling.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& LineStatusAll;

        //@}


        //! \name DigitalIO - This category includes items used to control the operation of the camera's digital I/O lines
        //@{
        /*!
            \brief A single bitfield that sets the state of all user settable output signals in one access

            This integer value is a single bitfield that sets the state of all user settable output signals in one access.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& UserOutputValueAll;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceVendorName;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceModelName;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceManufacturerInfo;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceVersion;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceFirmwareVersion;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceID;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceUserID;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief Indicates the scan type of the device's sensor

            This enumeration lists the possible scan types for the sensor in the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<DeviceScanTypeEnums >& DeviceScanType;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief Lists the temperature sources available for readout

            Lists the temperature sources available for readout

            \b Visibility = Guru

        */
        GENAPI_NAMESPACE::IEnumerationT<TemperatureSelectorEnums >& TemperatureSelector;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief Shows the current temperature of the selected target in degrees celcius

            Shows the current temperature of the selected target in degrees celcius

            \b Visibility = Guru

            \b Selected by : TemperatureSelector

        */
        GENAPI_NAMESPACE::IFloat& TemperatureAbs;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& CurDateTime;

        //@}


        //! \name DeviceInformation - This category includes items that control the analog characteristics of the video signal
        //@{
        /*!
            \brief



            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& SetDateTime;

        //@}


        //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification
        //@{
        /*!
            \brief Size of the payload in bytes

            Size of the payload in bytes. This is the total number of bytes sent in the payload. Image data + chunk data if present. No packet headers.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& PayloadSize;

        //@}



    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
        CBaslerIPCamera_Params( CBaslerIPCamera_Params& );

        //! not implemented assignment operator
        CBaslerIPCamera_Params& operator=( CBaslerIPCamera_Params& );

    //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CBaslerIPCamera_Params::CBaslerIPCamera_Params( void )
        : FactoryMode( *new GENAPI_NAMESPACE::CStringRef() )
        , ExposureMode( *new GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>() )
        , ShutterMode( *new GENAPI_NAMESPACE::CEnumerationTRef<ShutterModeEnums>() )
        , GainMode( *new GENAPI_NAMESPACE::CEnumerationTRef<GainModeEnums>() )
        , IrisMode( *new GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>() )
        , IrisDutyCycle( *new GENAPI_NAMESPACE::CIntegerRef() )
        , IrisPeriod( *new GENAPI_NAMESPACE::CIntegerRef() )
        , WhiteBalanceMode( *new GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>() )
        , AdcAdr( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AdcVal( *new GENAPI_NAMESPACE::CIntegerRef() )
        , IRFilterMode( *new GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>() )
        , CoreBoardId( *new GENAPI_NAMESPACE::CStringRef() )
        , SensorBoardId( *new GENAPI_NAMESPACE::CStringRef() )
        , GainRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BrightnessRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , BalanceRatioSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>() )
        , BalanceRatioRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , WhitePoint_X( *new GENAPI_NAMESPACE::CIntegerRef() )
        , WhitePoint_Y( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelFormat( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>() )
        , PixelSize( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>() )
        , PixelDynamicRangeMin( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelDynamicRangeMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TestImageSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>() )
        , Quality( *new GENAPI_NAMESPACE::CIntegerRef() )
        , CTTJpegQuality( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OverlayText( *new GENAPI_NAMESPACE::CStringRef() )
        , Width( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Height( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OffsetX( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OffsetY( *new GENAPI_NAMESPACE::CIntegerRef() )
        , WidthMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , HeightMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ExposureTimeAbs( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AcquisitionMode( *new GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>() )
        , AcquisitionStart( *new GENAPI_NAMESPACE::CCommandRef() )
        , AcquisitionStop( *new GENAPI_NAMESPACE::CCommandRef() )
        , LineSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>() )
        , LineSource( *new GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>() )
        , LineStatusAll( *new GENAPI_NAMESPACE::CIntegerRef() )
        , UserOutputValueAll( *new GENAPI_NAMESPACE::CIntegerRef() )
        , DeviceVendorName( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceModelName( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceManufacturerInfo( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceVersion( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceFirmwareVersion( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceID( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceUserID( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceScanType( *new GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>() )
        , TemperatureSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<TemperatureSelectorEnums>() )
        , TemperatureAbs( *new GENAPI_NAMESPACE::CFloatRef() )
        , CurDateTime( *new GENAPI_NAMESPACE::CStringRef() )
        , SetDateTime( *new GENAPI_NAMESPACE::CStringRef() )
        , PayloadSize( *new GENAPI_NAMESPACE::CIntegerRef() )

    {
    }

    inline CBaslerIPCamera_Params::~CBaslerIPCamera_Params( void )
    {
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&FactoryMode);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<ShutterModeEnums>*> (&ShutterMode);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<GainModeEnums>*> (&GainMode);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&IrisDutyCycle);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&IrisPeriod);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AdcAdr);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&AdcVal);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&CoreBoardId);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&SensorBoardId);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&GainRaw);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BrightnessRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&BalanceRatioRaw);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&WhitePoint_X);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&WhitePoint_Y);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMin);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMax);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Quality);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&CTTJpegQuality);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&OverlayText);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Width);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Height);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&OffsetX);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&OffsetY);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&WidthMax);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&HeightMax);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ExposureTimeAbs);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStart);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStop);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&LineStatusAll);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&UserOutputValueAll);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceVendorName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceModelName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceManufacturerInfo);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceVersion);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceFirmwareVersion);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceID);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceUserID);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TemperatureSelectorEnums>*> (&TemperatureSelector);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&TemperatureAbs);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&CurDateTime);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&SetDateTime);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PayloadSize);

    }

    inline void CBaslerIPCamera_Params::_Initialize( GENAPI_NAMESPACE::INodeMap* _Ptr )
    {
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&FactoryMode)->SetReference( _Ptr->GetNode( "FactoryMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetReference( _Ptr->GetNode( "ExposureMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetNumEnums( 6 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_EXPOSUREMODE_PRIO_NONE, "EXPOSUREMODE_PRIO_NONE" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_EXPOSUREMODE_PRIO_FRAMERATE, "EXPOSUREMODE_PRIO_FRAMERATE" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_EXPOSUREMODE_PRIO_QUALITY, "EXPOSUREMODE_PRIO_QUALITY" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_EXPOSUREMODE_MANUAL_GAIN, "EXPOSUREMODE_MANUAL_GAIN" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_EXPOSUREMODE_MANUAL_EXPOSURETIME, "EXPOSUREMODE_MANUAL_EXPOSURETIME" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_EXPOSUREMODE_MANUAL, "EXPOSUREMODE_MANUAL" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ShutterModeEnums>*> (&ShutterMode)->SetReference( _Ptr->GetNode( "ShutterMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ShutterModeEnums>*> (&ShutterMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ShutterModeEnums>*> (&ShutterMode)->SetEnumReference( ShutterMode_SHUTTERMODE_AUTO, "SHUTTERMODE_AUTO" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ShutterModeEnums>*> (&ShutterMode)->SetEnumReference( ShutterMode_SHUTTERMODE_MANUAL, "SHUTTERMODE_MANUAL" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainModeEnums>*> (&GainMode)->SetReference( _Ptr->GetNode( "GainMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainModeEnums>*> (&GainMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainModeEnums>*> (&GainMode)->SetEnumReference( GainMode_GAINMODE_AUTO, "GAINMODE_AUTO" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<GainModeEnums>*> (&GainMode)->SetEnumReference( GainMode_GAINMODE_MANUAL, "GAINMODE_MANUAL" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode)->SetReference( _Ptr->GetNode( "IrisMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode)->SetNumEnums( 4 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode)->SetEnumReference( IrisMode_IRISMODE_AUTO, "IRISMODE_AUTO" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode)->SetEnumReference( IrisMode_IRISMODE_OPEN, "IRISMODE_OPEN" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode)->SetEnumReference( IrisMode_IRISMODE_CLOSE, "IRISMODE_CLOSE" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IrisModeEnums>*> (&IrisMode)->SetEnumReference( IrisMode_IRISMODE_MANUAL, "IRISMODE_MANUAL" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&IrisDutyCycle)->SetReference( _Ptr->GetNode( "IrisDutyCycle" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&IrisPeriod)->SetReference( _Ptr->GetNode( "IrisPeriod" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetReference( _Ptr->GetNode( "WhiteBalanceMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetNumEnums( 8 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_AUTO, "WHITEBALANCEMODE_AUTO" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_AUTO2, "WHITEBALANCEMODE_AUTO2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_DAYLIGHT, "WHITEBALANCEMODE_DAYLIGHT" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_INCANDESCENT, "WHITEBALANCEMODE_INCANDESCENT" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_FLUORESCENT_1, "WHITEBALANCEMODE_FLUORESCENT_1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_FLUORESCENT_2, "WHITEBALANCEMODE_FLUORESCENT_2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_MANUAL, "WHITEBALANCEMODE_MANUAL" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<WhiteBalanceModeEnums>*> (&WhiteBalanceMode)->SetEnumReference( WhiteBalanceMode_WHITEBALANCEMODE_MANUAL_RGB, "WHITEBALANCEMODE_MANUAL_RGB" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AdcAdr)->SetReference( _Ptr->GetNode( "AdcAdr" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&AdcVal)->SetReference( _Ptr->GetNode( "AdcVal" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode)->SetReference( _Ptr->GetNode( "IRFilterMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode)->SetNumEnums( 4 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode)->SetEnumReference( IRFilterMode_IRFILTER_AUTO, "IRFILTER_AUTO" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode)->SetEnumReference( IRFilterMode_IRFILTER_OPEN, "IRFILTER_OPEN" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode)->SetEnumReference( IRFilterMode_IRFILTER_CLOSE, "IRFILTER_CLOSE" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<IRFilterModeEnums>*> (&IRFilterMode)->SetEnumReference( IRFilterMode_IRFILTER_WHATEVER5, "IRFILTER_WHATEVER5" );        static_cast<GENAPI_NAMESPACE::CStringRef*> (&CoreBoardId)->SetReference( _Ptr->GetNode( "CoreBoardId" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&SensorBoardId)->SetReference( _Ptr->GetNode( "SensorBoardId" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&GainRaw)->SetReference( _Ptr->GetNode( "GainRaw" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BrightnessRaw)->SetReference( _Ptr->GetNode( "BrightnessRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetReference( _Ptr->GetNode( "BalanceRatioSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetEnumReference( BalanceRatioSelector_Red, "Red" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetEnumReference( BalanceRatioSelector_Green, "Green" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<BalanceRatioSelectorEnums>*> (&BalanceRatioSelector)->SetEnumReference( BalanceRatioSelector_Blue, "Blue" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&BalanceRatioRaw)->SetReference( _Ptr->GetNode( "BalanceRatioRaw" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&WhitePoint_X)->SetReference( _Ptr->GetNode( "WhitePoint_X" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&WhitePoint_Y)->SetReference( _Ptr->GetNode( "WhitePoint_Y" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetReference( _Ptr->GetNode( "PixelFormat" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetNumEnums( 4 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_Unsupported, "Unsupported" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BGR8Packed, "BGR8Packed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerBG8, "BayerBG8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerBG16, "BayerBG16" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetReference( _Ptr->GetNode( "PixelSize" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp8, "Bpp8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp16, "Bpp16" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp24, "Bpp24" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMin)->SetReference( _Ptr->GetNode( "PixelDynamicRangeMin" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMax)->SetReference( _Ptr->GetNode( "PixelDynamicRangeMax" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetReference( _Ptr->GetNode( "TestImageSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetNumEnums( 8 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage1, "Testimage1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage2, "Testimage2" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage3, "Testimage3" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage4, "Testimage4" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage5, "Testimage5" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage6, "Testimage6" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage7, "Testimage7" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Quality)->SetReference( _Ptr->GetNode( "Quality" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&CTTJpegQuality)->SetReference( _Ptr->GetNode( "CTTJpegQuality" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&OverlayText)->SetReference( _Ptr->GetNode( "OverlayText" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Width)->SetReference( _Ptr->GetNode( "Width" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Height)->SetReference( _Ptr->GetNode( "Height" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&OffsetX)->SetReference( _Ptr->GetNode( "OffsetX" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&OffsetY)->SetReference( _Ptr->GetNode( "OffsetY" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&WidthMax)->SetReference( _Ptr->GetNode( "WidthMax" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&HeightMax)->SetReference( _Ptr->GetNode( "HeightMax" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ExposureTimeAbs)->SetReference( _Ptr->GetNode( "ExposureTimeAbs" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetReference( _Ptr->GetNode( "AcquisitionMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetEnumReference( AcquisitionMode_SingleFrame, "SingleFrame" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetEnumReference( AcquisitionMode_Continuous, "Continuous" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStart)->SetReference( _Ptr->GetNode( "AcquisitionStart" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStop)->SetReference( _Ptr->GetNode( "AcquisitionStop" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetReference( _Ptr->GetNode( "LineSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetEnumReference( LineSelector_Line1, "Line1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSelectorEnums>*> (&LineSelector)->SetEnumReference( LineSelector_Out1, "Out1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetReference( _Ptr->GetNode( "LineSource" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<LineSourceEnums>*> (&LineSource)->SetEnumReference( LineSource_UserOutput, "UserOutput" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&LineStatusAll)->SetReference( _Ptr->GetNode( "LineStatusAll" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&UserOutputValueAll)->SetReference( _Ptr->GetNode( "UserOutputValueAll" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceVendorName)->SetReference( _Ptr->GetNode( "DeviceVendorName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceModelName)->SetReference( _Ptr->GetNode( "DeviceModelName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceManufacturerInfo)->SetReference( _Ptr->GetNode( "DeviceManufacturerInfo" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceVersion)->SetReference( _Ptr->GetNode( "DeviceVersion" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceFirmwareVersion)->SetReference( _Ptr->GetNode( "DeviceFirmwareVersion" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceID)->SetReference( _Ptr->GetNode( "DeviceID" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceUserID)->SetReference( _Ptr->GetNode( "DeviceUserID" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetReference( _Ptr->GetNode( "DeviceScanType" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetEnumReference( DeviceScanType_Areascan, "Areascan" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<DeviceScanTypeEnums>*> (&DeviceScanType)->SetEnumReference( DeviceScanType_Linescan, "Linescan" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TemperatureSelectorEnums>*> (&TemperatureSelector)->SetReference( _Ptr->GetNode( "TemperatureSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TemperatureSelectorEnums>*> (&TemperatureSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TemperatureSelectorEnums>*> (&TemperatureSelector)->SetEnumReference( TemperatureSelector_Sensorboard, "Sensorboard" );        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&TemperatureAbs)->SetReference( _Ptr->GetNode( "TemperatureAbs" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&CurDateTime)->SetReference( _Ptr->GetNode( "CurDateTime" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&SetDateTime)->SetReference( _Ptr->GetNode( "SetDateTime" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PayloadSize)->SetReference( _Ptr->GetNode( "PayloadSize" ) );

    }

    inline const char* CBaslerIPCamera_Params::_GetVendorName( void )
    {
        return "Basler";
    }

    inline const char* CBaslerIPCamera_Params::_GetModelName( void )
    {
        return "BaslerIPCamera";
    }

    //! \endcond

} // namespace Basler_BaslerIPCamera

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#   endif
#endif

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_BaslerIPCamera_PARAMS_H
