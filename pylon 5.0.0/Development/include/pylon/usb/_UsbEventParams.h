





//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the PylonUsb Event Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_UsbEventParams_PARAMS_H
#define Basler_UsbEventParams_PARAMS_H

#ifdef __GNUC__
#define GENAPI_DEPRECATED_FEATURE __attribute__((deprecated))
#elif defined(_MSC_VER)
#define GENAPI_DEPRECATED_FEATURE __declspec(deprecated)
#else
#define GENAPI_DEPRECATED_FEATURE
#endif

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


//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UsbEventParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
    //! Valid values for Status
    enum StatusEnums
    {
        Status_Closed,  //!<The low level event grabber is closed.
        Status_Open   //!<The low level event grabber is open.
        
    };


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to the PylonUsb Event Grabber parameters
    class CUsbEventParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUsbEventParams_Params(void);

            //! Destructor
            ~CUsbEventParams_Params(void);

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
        
    //! \name Root - USB event grabber parameters.
    //@{
    /*!
        \brief Number of buffers to be used.

        Number of Buffers that are going to be used receiving events.
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &NumBuffer;
    
    //@}
    

    //! \name Root - USB event grabber parameters.
    //@{
    /*!
        \brief The maximum number of requests to be enqueued to the driver.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &NumMaxQueuedUrbs;
    
    //@}
    

    //! \name Root - USB event grabber parameters.
    //@{
    /*!
        \brief The priority of the thread that handles USB requests of the event stream interface.

        
    
        \b Visibility = Guru
    
    */
    GenApi::IInteger &TransferLoopThreadPriority;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The total count of processed events.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &Statistic_Total_Event_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The count of processed events with an error status.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &Statistic_Failed_Event_Count;
    
    //@}
    

    //! \name Statistic - Statistical data.
    //@{
    /*!
        \brief The status code of the last failed event buffer.

        
    
        \b Visibility = Expert
    
    */
    GenApi::IInteger &Statistic_Last_Failed_Event_Buffer_Status;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUsbEventParams_Params(CUsbEventParams_Params&);

            //! not implemented assignment operator
            CUsbEventParams_Params& operator=(CUsbEventParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CUsbEventParams_Params::CUsbEventParams_Params(void)
        : NumBuffer( *new GenApi::CIntegerRef() )
        , NumMaxQueuedUrbs( *new GenApi::CIntegerRef() )
        , TransferLoopThreadPriority( *new GenApi::CIntegerRef() )
        , Statistic_Total_Event_Count( *new GenApi::CIntegerRef() )
        , Statistic_Failed_Event_Count( *new GenApi::CIntegerRef() )
        , Statistic_Last_Failed_Event_Buffer_Status( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CUsbEventParams_Params::~CUsbEventParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&NumBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&NumMaxQueuedUrbs );
        delete static_cast < GenApi::CIntegerRef*> (&TransferLoopThreadPriority );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Total_Event_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Failed_Event_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Last_Failed_Event_Buffer_Status );
        
    }

    inline void CUsbEventParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&NumBuffer )->SetReference(_Ptr->GetNode("NumBuffer"));
    static_cast<GenApi::CIntegerRef*> (&NumMaxQueuedUrbs )->SetReference(_Ptr->GetNode("NumMaxQueuedUrbs"));
    static_cast<GenApi::CIntegerRef*> (&TransferLoopThreadPriority )->SetReference(_Ptr->GetNode("TransferLoopThreadPriority"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Total_Event_Count )->SetReference(_Ptr->GetNode("Statistic_Total_Event_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Failed_Event_Count )->SetReference(_Ptr->GetNode("Statistic_Failed_Event_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Last_Failed_Event_Buffer_Status )->SetReference(_Ptr->GetNode("Statistic_Last_Failed_Event_Buffer_Status"));
    
    }

    inline const char* CUsbEventParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CUsbEventParams_Params::_GetModelName(void)
    {
        return "UsbEventParams";
    }

    //! \endcond

} // namespace Basler_UsbEventParams

#undef GENAPI_DEPRECATED_FEATURE
#endif // Basler_UsbEventParams_PARAMS_H
