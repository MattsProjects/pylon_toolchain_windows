//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2019 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for Usb, GigE, and BCON
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_Basler_UniversalTLParams_PARAMS_H
#define BASLER_PYLON_Basler_UniversalTLParams_PARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UniversalTLParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************



    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! A parameter class containing all parameters as members that are available for Usb, GigE, and BCON
    class PYLONBASE_API CUniversalTLParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUniversalTLParams_Params(void);

            //! Destructor
            ~CUniversalTLParams_Params(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

            //! Return the vendor of the camera
            const char* _GetVendorName(void);

            //! Returns the camera model name
            const char* _GetModelName(void);
        
        //! \endcond

    private:
        class CUniversalTLParams_ParamsData;
        CUniversalTLParams_ParamsData* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        
    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Enables sending all commands and receiving all acknowledges twice - Applies to: GigE

        Enables sending all commands and receiving all acknowledges twice. This option should only be enabled in case of network problems.
    
        \b Visibility = Guru

    */
    Pylon::IBooleanEx& CommandDuplicationEnable;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Heartbeat timeout value on the host side in milliseconds - Applies to: GigE

    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& HeartbeatTimeout;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Maximum number of retries for read operations after a read operation has timed out - Applies to: GigE

    
        \b Visibility = Guru

    */
    Pylon::IIntegerEx& MaxRetryCountRead;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Maximum number of retries for write operations after a write operation has timed out - Applies to: GigE

    
        \b Visibility = Guru

    */
    Pylon::IIntegerEx& MaxRetryCountWrite;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Enables mapping of certain SFNC 1 x node names to SFNC 2 x node names - Applies to: Usb

    
        \b Visibility = Guru

    */
    Pylon::IBooleanEx& MigrationModeEnable;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Read access timeout value in milliseconds - Applies to: GigE

    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& ReadTimeout;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Number of timeouts during read and write operations when waiting for a response from the device - Applies to: GigE

    
        \b Visibility = Guru

    */
    Pylon::IIntegerEx& StatisticReadWriteTimeoutCount;
    
    //@}


    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Last error status of a read or write operation - Applies to: Usb and BCON

    
        \b Visibility = Expert

    */
    Pylon::IIntegerEx& Statistic_Last_Error_Status;
    
    //@}


    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Last error status of a read or write operation - Applies to: Usb and BCON

    
        \b Visibility = Expert

    */
    Pylon::IStringEx& Statistic_Last_Error_Status_Text;
    
    //@}


    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Number of failed read operations - Applies to: Usb and BCON

    
        \b Visibility = Expert

    */
    Pylon::IIntegerEx& Statistic_Read_Operations_Failed_Count;
    
    //@}


    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Number of read pipe resets - Applies to: Usb

    
        \b Visibility = Expert

    */
    Pylon::IIntegerEx& Statistic_Read_Pipe_Reset_Count;
    
    //@}


    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Number of failed write operations - Applies to: Usb and BCON

    
        \b Visibility = Expert

    */
    Pylon::IIntegerEx& Statistic_Write_Operations_Failed_Count;
    
    //@}


    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief Number of write pipe resets - Applies to: Usb

    
        \b Visibility = Expert

    */
    Pylon::IIntegerEx& Statistic_Write_Pipe_Reset_Count;
    
    //@}


    //! \name Root - Transport layer-specific parameters.
    //@{
    /*!
        \brief Write access timeout in milliseconds - Applies to: GigE

    
        \b Visibility = Beginner

    */
    Pylon::IIntegerEx& WriteTimeout;
    
    //@}



    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUniversalTLParams_Params(CUniversalTLParams_Params&);

            //! not implemented assignment operator
            CUniversalTLParams_Params& operator=(CUniversalTLParams_Params&);

        //! \endcond
    };


} // namespace Basler_UniversalTLParams

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_Basler_UniversalTLParams_PARAMS_H
