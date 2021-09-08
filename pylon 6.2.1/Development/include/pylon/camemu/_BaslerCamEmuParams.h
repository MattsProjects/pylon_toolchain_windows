

//-----------------------------------------------------------------------------
//  Copyright (c) 2004-2021 Basler AG
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Basler Cam Emu interface
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_BaslerCamEmu_PARAMS_H
#define Basler_BaslerCamEmu_PARAMS_H

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
namespace Basler_BaslerCamEmu
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    //! Valid values for PixelFormat
    enum PixelFormatEnums
    {
        PixelFormat_Mono8,  //!<Sets the pixel format to Mono 8.
        PixelFormat_Mono16,  //!<Sets the pixel format to Mono 16.
        PixelFormat_BGRA8Packed,  //!<Sets the pixel format to BGRA 8 Packed.
        PixelFormat_BGR8Packed,  //!<Sets the pixel format to BGR 8 Packed.
        PixelFormat_RGB8Packed,  //!<Sets the pixel format to Mono 8.
        PixelFormat_RGB16Packed,  //!<Sets the pixel format to RGB 16 Packed.
        PixelFormat_BayerGR8,  //!<Sets the pixel format to Bayer GR 8.
        PixelFormat_BayerRG8,  //!<Sets the pixel format to Bayer RG 8.
        PixelFormat_BayerGB8,  //!<Sets the pixel format to Bayer GB 8.
        PixelFormat_BayerBG8   //!<Sets the pixel format to Bayer BG 8.

    };

    //! Valid values for PixelSize
    enum PixelSizeEnums
    {
        PixelSize_Bpp8,  //!<Indicates that the depth of the pixel values in the acquired images is 8 bits per pixel.
        PixelSize_Bpp16,  //!<Indicates that the depth of the pixel values in the acquired images is 16 bits per pixel.
        PixelSize_Bpp24,  //!<Indicates that the depth of the pixel values in the acquired images is 24 bits per pixel.
        PixelSize_Bpp32,  //!<Indicates that the depth of the pixel values in the acquired images is 32 bits per pixel.
        PixelSize_Bpp48   //!<Indicates that the depth of the pixel values in the acquired images is 48 bits per pixel.

    };

    //! Valid values for TestImageSelector
    enum TestImageSelectorEnums
    {
        TestImageSelector_Off,  //!<Sets the camera's test image generation capability to disabled.
        TestImageSelector_Testimage1,  //!<Sets the camera to generate and transmit test images with a test image 1 pattern.
        TestImageSelector_Testimage2   //!<Sets the camera to generate and transmit test images with a test image 2 pattern.

    };

    //! Valid values for ImageFileMode
    enum ImageFileModeEnums
    {
        ImageFileMode_Off,  //!<Sets the mode to off.
        ImageFileMode_On   //!<Sets the mode to on.

    };

    //! Valid values for AcquisitionMode
    enum AcquisitionModeEnums
    {
        AcquisitionMode_SingleFrame,  //!<Sets the acquisition mode to single frame.
        AcquisitionMode_Continuous   //!<Sets the acquisition mode to continuous.

    };

    //! Valid values for TriggerSelector
    enum TriggerSelectorEnums
    {
        TriggerSelector_AcquisitionStart   //!<Selects the acquisition start trigger for configuration.

    };

    //! Valid values for TriggerMode
    enum TriggerModeEnums
    {
        TriggerMode_Off,  //!<Sets the mode for the selected trigger to off
        TriggerMode_On   //!<Sets the mode for the selected trigger to on

    };

    //! Valid values for TriggerSource
    enum TriggerSourceEnums
    {
        TriggerSource_Software   //!<Sets the software trigger as the signal source for the selected trigger.

    };

    //! Valid values for ExposureMode
    enum ExposureModeEnums
    {
        ExposureMode_Timed   //!<Sets the exposure mode to timed

    };

    //! Valid values for AcquisitionStatusSelector
    enum AcquisitionStatusSelectorEnums
    {
        AcquisitionStatusSelector_FrameTriggerWait   //!<Device is currently waiting for a Frame trigger.

    };

    //! Valid values for UserSetSelector
    enum UserSetSelectorEnums
    {
        UserSetSelector_Default   //!<Default Selection

    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************


    //! Basler Cam Emu interface
    class CBaslerCamEmu_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS

            //! Constructor
        CBaslerCamEmu_Params( void );

        //! Destructor
        ~CBaslerCamEmu_Params( void );

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

    //! \name AnalogControls - This category includes items that control the analog characteristics of the video signal.
    //@{
    /*!
        \brief This is an integer value that sets the selected gain control in device specific units.

        Sets the 'raw' value of the selected gain control. The 'raw' value is an integer value that sets the selected gain control in units specific to the camera.

        \b Visibility = Beginner


    */
        GENAPI_NAMESPACE::IInteger& GainRaw;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Sets the format of the pixel data transmitted for acquired images.

            This enumeration sets the format of the pixel data transmitted for acquired images.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<PixelFormatEnums >& PixelFormat;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Indicates the depth of the pixel values in the image in bits per pixel.

            This is a read only feature. This enumeration provides a list of values that indicate the depth of the pixel values in the acquired images in bits per pixel. This value will always be coherent with the pixel format setting.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<PixelSizeEnums >& PixelSize;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Indicates the minimum possible pixel value that could be transferred from the camera.

            This is a read only feature. It indicates the minimum possible pixel value that could be transferred from the camera.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& PixelDynamicRangeMin;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Indicates the maximum possible pixel value that could be transferred from the camera.

            This is a read only feature. It indicates the maximum possible pixel value that could be transferred from the camera.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& PixelDynamicRangeMax;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Selecting a test image from the list will enable the test image.

            This enumeration provides a list of the available test images. Selecting a test image from the list will enable the test image.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<TestImageSelectorEnums >& TestImageSelector;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Enter the name of an image filename or a path to a directory containing image files.

            Enter the name of an image filename in a format supported by pylon or the path to a directory containing image files.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& ImageFilename;

        //@}


        //! \name ImageFormat - This category includes items that control the size of the acquired image and the format of the transferred pixel data.
        //@{
        /*!
            \brief Enables loading files from disk for image acquisition.

            Enables loading files from disk for image acquisition.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<ImageFileModeEnums >& ImageFileMode;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Indicates the width of the camera's sensor in pixels.

            This is a read only element. It is an integer that indicates the actual width of the camera's sensor in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& SensorWidth;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Indicates the height of the camera's sensor in pixels.

            This is a read only element. It is an integer that indicates the actual height of the camera's sensor in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& SensorHeight;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Indicates the maximum allowed width of the image in pixels.

            This is a read only element. It is an integer that indicates maximum allowed width of the image in pixels taking into account any function that may limit the allowed width.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& WidthMax;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Indicates the maximum allowed height of the image in pixels.

            This is a read only element. It is an integer that indicates maximum allowed height of the image in pixels taking into account any function that may limit the allowed height.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& HeightMax;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Sets the width of the area of interest in pixels.

            This value sets the width of the area of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Width;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Sets the height of the area of interest in pixels.

            This value sets the height of the area of interest in pixels.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& Height;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Sets the X offset (left offset) of the area of interest in pixels.

            This value sets the X offset (left offset) for the area of interest in pixels, i.e., the distance in pixels between the left side of the sensor and the left side of the image area.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& OffsetX;

        //@}


        //! \name AOI - This category includes items used to set the size and position of the area of interest.
        //@{
        /*!
            \brief Sets the Y offset (top offset) for the area of interest in pixels.

            This value sets the Y offset (top offset) for the area of interest, i.e., the distance in pixels between the top of the sensor and the top of the image area.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& OffsetY;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Controls the emulated absolute exposure time in microseconds (us).

            Controls the emulated absolute exposure time in microseconds (us).

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& ExposureTimeAbs;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Dummy: Sets the time base (in microseconds) that is used when the exposure time is set with the 'exposure time raw' setting.

            Dummy: This float value sets the time base (in microseconds) that is used when the exposure time is set with the 'raw' setting.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& ExposureTimeBaseAbs;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Dummy: Sets the 'raw' exposure time.  Actual exposure time = raw exposure setting  x  exposure time base abs setting.

            Dummy: This value sets an integer that will be used as a multiplier for the exposure timebase. The actual exposure time equals the current exposure time raw setting times the current exposure time base abs setting.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& ExposureTimeRaw;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Sets the image acquisition mode.

            This enumeration sets the image acquisition mode.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<AcquisitionModeEnums >& AcquisitionMode;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Starts the acquisition of images.

            This command starts the acquisition of images. If the camera is set for single frame acquisition, it will start acquisition of one frame. If the camera is set for continuous frame acquisition, it will start continuous acquisition of frames.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& AcquisitionStart;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Stops the acquisition of images.

            If the camera is set for continuous image acquisition and acquisition has been started, this command stops the acquisition of images.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& AcquisitionStop;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Selects the trigger type to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.

            This enumeration selects the trigger type to configure. Once a trigger type has been selected, all changes to the trigger settings will be applied to the selected trigger.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerSelectorEnums >& TriggerSelector;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Sets the mode for the selected trigger.

            This enumeration sets the trigger mode for the selected trigger.

            \b Visibility = Beginner


            \b Selected by : TriggerSelector

        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerModeEnums >& TriggerMode;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Generates a software trigger signal that is used when the trigger source is set to 'software'.

            This command generates a software trigger signal. The software trigger signal will be used if the trigger source is set to 'Software'.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::ICommand& TriggerSoftware;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Sets the signal source for the selected trigger.

            This enumeration sets the signal source for the selected trigger.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<TriggerSourceEnums >& TriggerSource;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Sets the exposure mode.

            This enumeration sets the exposure mode.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IEnumerationT<ExposureModeEnums >& ExposureMode;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Enables setting the camera's acquisition frame rate to a specified value.

            This boolean value enables setting  the camera's acquisition frame rate to a specified value.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IBoolean& AcquisitionFrameRateEnable;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief If the acquisition frame rate feature is enabled, this value sets the camera's acquisition frame rate in frames per second.

            Sets the 'absolute' value of the acquisition frame rate. The 'absolute' value is a float value that sets the acquisition frame rate in frames per second.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& AcquisitionFrameRateAbs;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Dummy framerate feature.

            Dummy framerate feature. Does not correspond to the real transferred frame rate.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IFloat& ResultingFrameRateAbs;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief This enumeration is used to select which internal acquisition signal to read using AcquisitionStatus.

            This enumeration is used to select which internal acquisition signal to read using AcquisitionStatus.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<AcquisitionStatusSelectorEnums >& AcquisitionStatusSelector;

        //@}


        //! \name AcquisitionTrigger - This category includes items used to set the image acquisition parameters and to start and stop acquisition.
        //@{
        /*!
            \brief Reads the selected acquisition status.

            This feature is used to read the state (True or False) of the internal acquisition signal selected using AcquisitionStatusSelector.

            \b Visibility = Expert

            \b Selected by : AcquisitionStatusSelector

        */
        GENAPI_NAMESPACE::IBoolean& AcquisitionStatus;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief Indicates the name of the device's vendor.

            This is a read only element. It is a text description that indicates the name of the device's vendor.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceVendorName;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief Indicates the model name of the device.

            This is a read only element. It is a text description that indicates the model name of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceModelName;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief Provides additional information from the vendor about the device.

            This is a read only element. It is a string that provides additional information from the vendor about the camera.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceManufacturerInfo;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief Indicates the version of the device.

            This is a read only element. It is a string that indicates the version of the device.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceVersion;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief Indicates the version of the device's firmware and software.

            This is a read only element. It is a string that indicates the version of the device's firmware and software.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceFirmwareVersion;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief A device ID that is user programmable.

            This is a read/write element. It is a user programmable string.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IString& DeviceUserID;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief .



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IEnumerationT<UserSetSelectorEnums >& UserSetSelector;

        //@}


        //! \name DeviceInformation - Contains parameters to retrieve information about the current device or to configure the current device.
        //@{
        /*!
            \brief



            \b Visibility = Invisible

        */
        GENAPI_NAMESPACE::IBoolean& ChunkModeActive;

        //@}


        //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification.
        //@{
        /*!
            \brief Size of the payload in bytes.

            Size of the payload in bytes. This is the total number of bytes sent in the payload. Image data + chunk data if present. No packet headers.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& PayloadSize;

        //@}


        //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification.
        //@{
        /*!
            \brief Number of failed buffers to generate.

            Number of failed buffers to generate.

            \b Visibility = Beginner


        */
        GENAPI_NAMESPACE::IInteger& ForceFailedBufferCount;

        //@}


        //! \name TransportLayer - This category includes items related to the IIDC 1394 transport specification.
        //@{
        /*!
            \brief Marks the next buffer as failed.

            Marks the next buffer as a failed buffer.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::ICommand& ForceFailedBuffer;

        //@}



    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
        CBaslerCamEmu_Params( CBaslerCamEmu_Params& );

        //! not implemented assignment operator
        CBaslerCamEmu_Params& operator=( CBaslerCamEmu_Params& );

    //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CBaslerCamEmu_Params::CBaslerCamEmu_Params( void )
        : GainRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelFormat( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>() )
        , PixelSize( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>() )
        , PixelDynamicRangeMin( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelDynamicRangeMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , TestImageSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>() )
        , ImageFilename( *new GENAPI_NAMESPACE::CStringRef() )
        , ImageFileMode( *new GENAPI_NAMESPACE::CEnumerationTRef<ImageFileModeEnums>() )
        , SensorWidth( *new GENAPI_NAMESPACE::CIntegerRef() )
        , SensorHeight( *new GENAPI_NAMESPACE::CIntegerRef() )
        , WidthMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , HeightMax( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Width( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Height( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OffsetX( *new GENAPI_NAMESPACE::CIntegerRef() )
        , OffsetY( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ExposureTimeAbs( *new GENAPI_NAMESPACE::CFloatRef() )
        , ExposureTimeBaseAbs( *new GENAPI_NAMESPACE::CFloatRef() )
        , ExposureTimeRaw( *new GENAPI_NAMESPACE::CIntegerRef() )
        , AcquisitionMode( *new GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>() )
        , AcquisitionStart( *new GENAPI_NAMESPACE::CCommandRef() )
        , AcquisitionStop( *new GENAPI_NAMESPACE::CCommandRef() )
        , TriggerSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>() )
        , TriggerMode( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>() )
        , TriggerSoftware( *new GENAPI_NAMESPACE::CCommandRef() )
        , TriggerSource( *new GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>() )
        , ExposureMode( *new GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>() )
        , AcquisitionFrameRateEnable( *new GENAPI_NAMESPACE::CBooleanRef() )
        , AcquisitionFrameRateAbs( *new GENAPI_NAMESPACE::CFloatRef() )
        , ResultingFrameRateAbs( *new GENAPI_NAMESPACE::CFloatRef() )
        , AcquisitionStatusSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionStatusSelectorEnums>() )
        , AcquisitionStatus( *new GENAPI_NAMESPACE::CBooleanRef() )
        , DeviceVendorName( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceModelName( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceManufacturerInfo( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceVersion( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceFirmwareVersion( *new GENAPI_NAMESPACE::CStringRef() )
        , DeviceUserID( *new GENAPI_NAMESPACE::CStringRef() )
        , UserSetSelector( *new GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>() )
        , ChunkModeActive( *new GENAPI_NAMESPACE::CBooleanRef() )
        , PayloadSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ForceFailedBufferCount( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ForceFailedBuffer( *new GENAPI_NAMESPACE::CCommandRef() )

    {
    }

    inline CBaslerCamEmu_Params::~CBaslerCamEmu_Params( void )
    {
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&GainRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMin);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMax);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&ImageFilename);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<ImageFileModeEnums>*> (&ImageFileMode);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&SensorWidth);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&SensorHeight);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&WidthMax);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&HeightMax);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Width);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Height);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&OffsetX);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&OffsetY);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&ExposureTimeAbs);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&ExposureTimeBaseAbs);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ExposureTimeRaw);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStart);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStop);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&TriggerSoftware);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&AcquisitionFrameRateEnable);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&AcquisitionFrameRateAbs);
        delete static_cast <GENAPI_NAMESPACE::CFloatRef*> (&ResultingFrameRateAbs);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionStatusSelectorEnums>*> (&AcquisitionStatusSelector);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&AcquisitionStatus);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceVendorName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceModelName);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceManufacturerInfo);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceVersion);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceFirmwareVersion);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&DeviceUserID);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector);
        delete static_cast <GENAPI_NAMESPACE::CBooleanRef*> (&ChunkModeActive);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PayloadSize);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ForceFailedBufferCount);
        delete static_cast <GENAPI_NAMESPACE::CCommandRef*> (&ForceFailedBuffer);

    }

    inline void CBaslerCamEmu_Params::_Initialize( GENAPI_NAMESPACE::INodeMap* _Ptr )
    {
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&GainRaw)->SetReference( _Ptr->GetNode( "GainRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetReference( _Ptr->GetNode( "PixelFormat" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetNumEnums( 10 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_Mono8, "Mono8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_Mono16, "Mono16" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BGRA8Packed, "BGRA8Packed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BGR8Packed, "BGR8Packed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_RGB8Packed, "RGB8Packed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_RGB16Packed, "RGB16Packed" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerGR8, "BayerGR8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerRG8, "BayerRG8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerGB8, "BayerGB8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelFormatEnums>*> (&PixelFormat)->SetEnumReference( PixelFormat_BayerBG8, "BayerBG8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetReference( _Ptr->GetNode( "PixelSize" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetNumEnums( 5 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp8, "Bpp8" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp16, "Bpp16" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp24, "Bpp24" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp32, "Bpp32" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelSizeEnums>*> (&PixelSize)->SetEnumReference( PixelSize_Bpp48, "Bpp48" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMin)->SetReference( _Ptr->GetNode( "PixelDynamicRangeMin" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelDynamicRangeMax)->SetReference( _Ptr->GetNode( "PixelDynamicRangeMax" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetReference( _Ptr->GetNode( "TestImageSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetNumEnums( 3 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage1, "Testimage1" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TestImageSelectorEnums>*> (&TestImageSelector)->SetEnumReference( TestImageSelector_Testimage2, "Testimage2" );        static_cast<GENAPI_NAMESPACE::CStringRef*> (&ImageFilename)->SetReference( _Ptr->GetNode( "ImageFilename" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ImageFileModeEnums>*> (&ImageFileMode)->SetReference( _Ptr->GetNode( "ImageFileMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ImageFileModeEnums>*> (&ImageFileMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ImageFileModeEnums>*> (&ImageFileMode)->SetEnumReference( ImageFileMode_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ImageFileModeEnums>*> (&ImageFileMode)->SetEnumReference( ImageFileMode_On, "On" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&SensorWidth)->SetReference( _Ptr->GetNode( "SensorWidth" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&SensorHeight)->SetReference( _Ptr->GetNode( "SensorHeight" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&WidthMax)->SetReference( _Ptr->GetNode( "WidthMax" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&HeightMax)->SetReference( _Ptr->GetNode( "HeightMax" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Width)->SetReference( _Ptr->GetNode( "Width" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Height)->SetReference( _Ptr->GetNode( "Height" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&OffsetX)->SetReference( _Ptr->GetNode( "OffsetX" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&OffsetY)->SetReference( _Ptr->GetNode( "OffsetY" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&ExposureTimeAbs)->SetReference( _Ptr->GetNode( "ExposureTimeAbs" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&ExposureTimeBaseAbs)->SetReference( _Ptr->GetNode( "ExposureTimeBaseAbs" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ExposureTimeRaw)->SetReference( _Ptr->GetNode( "ExposureTimeRaw" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetReference( _Ptr->GetNode( "AcquisitionMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetEnumReference( AcquisitionMode_SingleFrame, "SingleFrame" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionModeEnums>*> (&AcquisitionMode)->SetEnumReference( AcquisitionMode_Continuous, "Continuous" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStart)->SetReference( _Ptr->GetNode( "AcquisitionStart" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&AcquisitionStop)->SetReference( _Ptr->GetNode( "AcquisitionStop" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector)->SetReference( _Ptr->GetNode( "TriggerSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSelectorEnums>*> (&TriggerSelector)->SetEnumReference( TriggerSelector_AcquisitionStart, "AcquisitionStart" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetReference( _Ptr->GetNode( "TriggerMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetEnumReference( TriggerMode_Off, "Off" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerModeEnums>*> (&TriggerMode)->SetEnumReference( TriggerMode_On, "On" );        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&TriggerSoftware)->SetReference( _Ptr->GetNode( "TriggerSoftware" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetReference( _Ptr->GetNode( "TriggerSource" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<TriggerSourceEnums>*> (&TriggerSource)->SetEnumReference( TriggerSource_Software, "Software" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetReference( _Ptr->GetNode( "ExposureMode" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<ExposureModeEnums>*> (&ExposureMode)->SetEnumReference( ExposureMode_Timed, "Timed" );        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&AcquisitionFrameRateEnable)->SetReference( _Ptr->GetNode( "AcquisitionFrameRateEnable" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&AcquisitionFrameRateAbs)->SetReference( _Ptr->GetNode( "AcquisitionFrameRateAbs" ) );
        static_cast<GENAPI_NAMESPACE::CFloatRef*> (&ResultingFrameRateAbs)->SetReference( _Ptr->GetNode( "ResultingFrameRateAbs" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionStatusSelectorEnums>*> (&AcquisitionStatusSelector)->SetReference( _Ptr->GetNode( "AcquisitionStatusSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionStatusSelectorEnums>*> (&AcquisitionStatusSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<AcquisitionStatusSelectorEnums>*> (&AcquisitionStatusSelector)->SetEnumReference( AcquisitionStatusSelector_FrameTriggerWait, "FrameTriggerWait" );        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&AcquisitionStatus)->SetReference( _Ptr->GetNode( "AcquisitionStatus" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceVendorName)->SetReference( _Ptr->GetNode( "DeviceVendorName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceModelName)->SetReference( _Ptr->GetNode( "DeviceModelName" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceManufacturerInfo)->SetReference( _Ptr->GetNode( "DeviceManufacturerInfo" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceVersion)->SetReference( _Ptr->GetNode( "DeviceVersion" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceFirmwareVersion)->SetReference( _Ptr->GetNode( "DeviceFirmwareVersion" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&DeviceUserID)->SetReference( _Ptr->GetNode( "DeviceUserID" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetReference( _Ptr->GetNode( "UserSetSelector" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetNumEnums( 1 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<UserSetSelectorEnums>*> (&UserSetSelector)->SetEnumReference( UserSetSelector_Default, "Default" );        static_cast<GENAPI_NAMESPACE::CBooleanRef*> (&ChunkModeActive)->SetReference( _Ptr->GetNode( "ChunkModeActive" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PayloadSize)->SetReference( _Ptr->GetNode( "PayloadSize" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ForceFailedBufferCount)->SetReference( _Ptr->GetNode( "ForceFailedBufferCount" ) );
        static_cast<GENAPI_NAMESPACE::CCommandRef*> (&ForceFailedBuffer)->SetReference( _Ptr->GetNode( "ForceFailedBuffer" ) );

    }

    inline const char* CBaslerCamEmu_Params::_GetVendorName( void )
    {
        return "Basler";
    }

    inline const char* CBaslerCamEmu_Params::_GetModelName( void )
    {
        return "BaslerCamEmu";
    }

    //! \endcond

} // namespace Basler_BaslerCamEmu

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#   endif
#endif

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_BaslerCamEmu_PARAMS_H
