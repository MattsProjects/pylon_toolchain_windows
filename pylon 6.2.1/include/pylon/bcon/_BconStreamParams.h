

//-----------------------------------------------------------------------------
//  Copyright (c) 2004-2021 Basler AG
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the pylon BCON Stream Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_BconStreamParams_PARAMS_H
#define Basler_BconStreamParams_PARAMS_H

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
namespace Basler_BconStreamParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    //! Valid values for PixelPerClockCycle
    enum PixelPerClockCycleEnums
    {
        PixelPerClockCycle_One,  //!<One pixel per clock cycle is transmitted.
        PixelPerClockCycle_Two   //!<Two pixels per clock cycle are transmitted.

    };

    //! Valid values for Status
    enum StatusEnums
    {
        Status_Closed,  //!<
        Status_Open,  //!<
        Status_Grabbing   //!<

    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************


    //! Interface to the pylon BCON Stream Grabber parameters
    class CBconStreamParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS

            //! Constructor
        CBconStreamParams_Params( void );

        //! Destructor
        ~CBconStreamParams_Params( void );

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

    //! \name Root - Interface to the BCON-specific stream parameters.
    //@{
    /*!
        \brief Maximum number of buffers that can be used simultaneously for grabbing images.



        \b Visibility = Expert

    */
        GENAPI_NAMESPACE::IInteger& MaxNumBuffer;

        //@}


        //! \name Root - Interface to the BCON-specific stream parameters.
        //@{
        /*!
            \brief Maximum size (in bytes) of a buffer used for grabbing images.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& MaxBufferSize;

        //@}


        //! \name GrabberSettings - Grabber settings.
        //@{
        /*!
            \brief Pixel format on the host side.

            Pixel format on the host side. This parameter is linked with the Pixel Format camera parameter. If the camera parameter changes, the host parameter changes accordingly, but not vice versa. The host parameter should not be set to a value different from the camera parameter.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& PixelFormatValue;

        //@}


        //! \name GrabberSettings - Grabber settings.
        //@{
        /*!
            \brief Width of the image ROI on the host side.

            Width of the image ROI on the host side. This parameter is linked with the Width camera parameter. If the camera parameter changes, the host parameter changes accordingly, but not vice versa. The host parameter should not be set to a value different from the camera parameter.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Width;

        //@}


        //! \name GrabberSettings - Grabber settings.
        //@{
        /*!
            \brief Height of the image ROI on the host side.

            Height of the image ROI on the host side. This parameter is linked with the Height camera parameter. If the camera parameter changes, the host parameter changes accordingly, but not vice versa. The host parameter should not be set to a value different from the camera parameter.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Height;

        //@}


        //! \name GrabberSettings - Grabber settings.
        //@{
        /*!
            \brief Clock frequency on the host side in Hertz.

            Clock frequency on the host side in Hertz. This parameter is linked with the BconClockFrequency camera parameter. If the camera parameter changes, the host parameter changes accordingly, but not vice versa. The host parameter should not be set to a value different from the camera parameter.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& ClockFrequency;

        //@}


        //! \name GrabberSettings - Grabber settings.
        //@{
        /*!
            \brief Sets the number of pixels per clock cycle on the host side.

            Sets the number of pixels per clock cycle on the host side. This parameter is linked with the Pixels per Clock Cycle camera parameter. If the camera parameter changes, the host parameter changes accordingly, but not vice versa. The host parameter should not be set to a value different from the camera parameter.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IEnumerationT<PixelPerClockCycleEnums >& PixelPerClockCycle;

        //@}


        //! \name GrabberSettings - Grabber settings.
        //@{
        /*!
            \brief Size of the payload in bytes.

            Size of the payload in bytes. This is the total number of bytes of the image data payload produced by the frame grabber. This value is computed by the frame grabber implementation. The pylon stream grabber needs to be open to be able to compute the payload size.

            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& PayloadSize;

        //@}


        //! \name Statistic - Statistical data.
        //@{
        /*!
            \brief The total count of processed buffers.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Statistic_Total_Buffer_Count;

        //@}


        //! \name Statistic - Statistical data.
        //@{
        /*!
            \brief The count of buffers that returned with an error status.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Statistic_Failed_Buffer_Count;

        //@}


        //! \name Statistic - Statistical data.
        //@{
        /*!
            \brief The status code of the last failed buffer.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Statistic_Last_Failed_Buffer_Status;

        //@}


        //! \name Statistic - Statistical data.
        //@{
        /*!
            \brief Status code of the last failed buffer.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IString& Statistic_Last_Failed_Buffer_Status_Text;

        //@}


        //! \name Statistic - Statistical data.
        //@{
        /*!
            \brief The count of missed frames between grabbed images.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Statistic_Missed_Frame_Count;

        //@}


        //! \name Statistic - Statistical data.
        //@{
        /*!
            \brief The last grabbed block ID.



            \b Visibility = Expert

        */
        GENAPI_NAMESPACE::IInteger& Statistic_Last_Block_Id;

        //@}



    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
        CBconStreamParams_Params( CBconStreamParams_Params& );

        //! not implemented assignment operator
        CBconStreamParams_Params& operator=( CBconStreamParams_Params& );

    //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CBconStreamParams_Params::CBconStreamParams_Params( void )
        : MaxNumBuffer( *new GENAPI_NAMESPACE::CIntegerRef() )
        , MaxBufferSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelFormatValue( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Width( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Height( *new GENAPI_NAMESPACE::CIntegerRef() )
        , ClockFrequency( *new GENAPI_NAMESPACE::CIntegerRef() )
        , PixelPerClockCycle( *new GENAPI_NAMESPACE::CEnumerationTRef<PixelPerClockCycleEnums>() )
        , PayloadSize( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Total_Buffer_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Failed_Buffer_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Last_Failed_Buffer_Status( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Last_Failed_Buffer_Status_Text( *new GENAPI_NAMESPACE::CStringRef() )
        , Statistic_Missed_Frame_Count( *new GENAPI_NAMESPACE::CIntegerRef() )
        , Statistic_Last_Block_Id( *new GENAPI_NAMESPACE::CIntegerRef() )

    {
    }

    inline CBconStreamParams_Params::~CBconStreamParams_Params( void )
    {
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&MaxNumBuffer);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&MaxBufferSize);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PixelFormatValue);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Width);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Height);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&ClockFrequency);
        delete static_cast <GENAPI_NAMESPACE::CEnumerationTRef<PixelPerClockCycleEnums>*> (&PixelPerClockCycle);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&PayloadSize);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Buffer_Count);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Buffer_Count);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Failed_Buffer_Status);
        delete static_cast <GENAPI_NAMESPACE::CStringRef*> (&Statistic_Last_Failed_Buffer_Status_Text);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Missed_Frame_Count);
        delete static_cast <GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Block_Id);

    }

    inline void CBconStreamParams_Params::_Initialize( GENAPI_NAMESPACE::INodeMap* _Ptr )
    {
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxNumBuffer)->SetReference( _Ptr->GetNode( "MaxNumBuffer" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&MaxBufferSize)->SetReference( _Ptr->GetNode( "MaxBufferSize" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PixelFormatValue)->SetReference( _Ptr->GetNode( "PixelFormatValue" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Width)->SetReference( _Ptr->GetNode( "Width" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Height)->SetReference( _Ptr->GetNode( "Height" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&ClockFrequency)->SetReference( _Ptr->GetNode( "ClockFrequency" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelPerClockCycleEnums>*> (&PixelPerClockCycle)->SetReference( _Ptr->GetNode( "PixelPerClockCycle" ) );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelPerClockCycleEnums>*> (&PixelPerClockCycle)->SetNumEnums( 2 );
        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelPerClockCycleEnums>*> (&PixelPerClockCycle)->SetEnumReference( PixelPerClockCycle_One, "One" );        static_cast<GENAPI_NAMESPACE::CEnumerationTRef<PixelPerClockCycleEnums>*> (&PixelPerClockCycle)->SetEnumReference( PixelPerClockCycle_Two, "Two" );        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&PayloadSize)->SetReference( _Ptr->GetNode( "PayloadSize" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Total_Buffer_Count)->SetReference( _Ptr->GetNode( "Statistic_Total_Buffer_Count" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Failed_Buffer_Count)->SetReference( _Ptr->GetNode( "Statistic_Failed_Buffer_Count" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Failed_Buffer_Status)->SetReference( _Ptr->GetNode( "Statistic_Last_Failed_Buffer_Status" ) );
        static_cast<GENAPI_NAMESPACE::CStringRef*> (&Statistic_Last_Failed_Buffer_Status_Text)->SetReference( _Ptr->GetNode( "Statistic_Last_Failed_Buffer_Status_Text" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Missed_Frame_Count)->SetReference( _Ptr->GetNode( "Statistic_Missed_Frame_Count" ) );
        static_cast<GENAPI_NAMESPACE::CIntegerRef*> (&Statistic_Last_Block_Id)->SetReference( _Ptr->GetNode( "Statistic_Last_Block_Id" ) );

    }

    inline const char* CBconStreamParams_Params::_GetVendorName( void )
    {
        return "Basler";
    }

    inline const char* CBconStreamParams_Params::_GetModelName( void )
    {
        return "BconStreamParams";
    }

    //! \endcond

} // namespace Basler_BconStreamParams

#if GCC_DIAGNOSTIC_AWARE
#   if GCC_DIAGNOSTIC_PUSH_POP_AWARE
#       pragma GCC diagnostic pop
#   else
#       pragma GCC diagnostic warning "-Wdeprecated-declarations"
#   endif
#endif

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_BconStreamParams_PARAMS_H
