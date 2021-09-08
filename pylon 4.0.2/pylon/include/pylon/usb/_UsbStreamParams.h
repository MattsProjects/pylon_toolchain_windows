
    




//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the PylonUsb Stream Grabber parameters
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_UsbStreamParams_PARAMS_H
#define Basler_UsbStreamParams_PARAMS_H

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>

//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UsbStreamParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
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
    

    //! Interface to the PylonUsb Stream Grabber parameters
    class CUsbStreamParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
		// If you want to show the following methods in the help file
		// add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUsbStreamParams_Params(void);

            //! Destructor
            ~CUsbStreamParams_Params(void);

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
        
	//! \name Root - Interface to the USB-specific stream parameters.
    //@{
	/*!	
		\brief The maximum number of buffers that can be used simultaneously.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &MaxNumBuffer;
    
    //@}
    

	//! \name Root - Interface to the USB-specific stream parameters.
    //@{
	/*!	
		\brief The maximum buffer size in bytes that can be registered.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &MaxBufferSize;
    
    //@}
    

	//! \name Root - Interface to the USB-specific stream parameters.
    //@{
	/*!	
		\brief The maximum number of requests to be enqueued to the driver.

	
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &NumMaxQueuedUrbs;
    
    //@}
    

	//! \name Root - Interface to the USB-specific stream parameters.
    //@{
	/*!	
		\brief Controls the maximum size of USB transfers.

	
        
        The default value is appropriate for most applications. 
        Reducing the value may cause a higher CPU load. USB host adapter drivers may require 
        to decrease the value in case the application fails to receive the image stream. The maximum value 
        for the Maximum Transfer Size depends on the operating system version and may be limited by the host adapter drivers.
        
        
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &MaxTransferSize;
    
    //@}
    

	//! \name Root - Interface to the USB-specific stream parameters.
    //@{
	/*!	
		\brief The priority of the thread that handles USB requests of the stream interface.

	
	
		\b Visibility = Guru
	
    */
    GenApi::IInteger &TransferLoopThreadPriority;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The total count of processed buffers.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Total_Buffer_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The count of buffers that returned with an error status.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Failed_Buffer_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The count of bad or missed frames between successfully grabbed images.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Missed_Frame_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The count of stream resynchronizations.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Resynchronization_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The last grabbed block ID.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Last_Block_Id;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The status code of the last failed buffer.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Last_Failed_Buffer_Status;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUsbStreamParams_Params(CUsbStreamParams_Params&);

            //! not implemented assignment operator
            CUsbStreamParams_Params& operator=(CUsbStreamParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CUsbStreamParams_Params::CUsbStreamParams_Params(void)
        : MaxNumBuffer( *new GenApi::CIntegerRef() )
        , MaxBufferSize( *new GenApi::CIntegerRef() )
        , NumMaxQueuedUrbs( *new GenApi::CIntegerRef() )
        , MaxTransferSize( *new GenApi::CIntegerRef() )
        , TransferLoopThreadPriority( *new GenApi::CIntegerRef() )
        , Statistic_Total_Buffer_Count( *new GenApi::CIntegerRef() )
        , Statistic_Failed_Buffer_Count( *new GenApi::CIntegerRef() )
        , Statistic_Missed_Frame_Count( *new GenApi::CIntegerRef() )
        , Statistic_Resynchronization_Count( *new GenApi::CIntegerRef() )
        , Statistic_Last_Block_Id( *new GenApi::CIntegerRef() )
        , Statistic_Last_Failed_Buffer_Status( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CUsbStreamParams_Params::~CUsbStreamParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&MaxNumBuffer );
        delete static_cast < GenApi::CIntegerRef*> (&MaxBufferSize );
        delete static_cast < GenApi::CIntegerRef*> (&NumMaxQueuedUrbs );
        delete static_cast < GenApi::CIntegerRef*> (&MaxTransferSize );
        delete static_cast < GenApi::CIntegerRef*> (&TransferLoopThreadPriority );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Total_Buffer_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Failed_Buffer_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Missed_Frame_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Resynchronization_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Last_Block_Id );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Last_Failed_Buffer_Status );
        
    }

    inline void CUsbStreamParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&MaxNumBuffer )->SetReference(_Ptr->GetNode("MaxNumBuffer"));
    static_cast<GenApi::CIntegerRef*> (&MaxBufferSize )->SetReference(_Ptr->GetNode("MaxBufferSize"));
    static_cast<GenApi::CIntegerRef*> (&NumMaxQueuedUrbs )->SetReference(_Ptr->GetNode("NumMaxQueuedUrbs"));
    static_cast<GenApi::CIntegerRef*> (&MaxTransferSize )->SetReference(_Ptr->GetNode("MaxTransferSize"));
    static_cast<GenApi::CIntegerRef*> (&TransferLoopThreadPriority )->SetReference(_Ptr->GetNode("TransferLoopThreadPriority"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Total_Buffer_Count )->SetReference(_Ptr->GetNode("Statistic_Total_Buffer_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Failed_Buffer_Count )->SetReference(_Ptr->GetNode("Statistic_Failed_Buffer_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Missed_Frame_Count )->SetReference(_Ptr->GetNode("Statistic_Missed_Frame_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Resynchronization_Count )->SetReference(_Ptr->GetNode("Statistic_Resynchronization_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Last_Block_Id )->SetReference(_Ptr->GetNode("Statistic_Last_Block_Id"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Last_Failed_Buffer_Status )->SetReference(_Ptr->GetNode("Statistic_Last_Failed_Buffer_Status"));
    
    }

    inline const char* CUsbStreamParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CUsbStreamParams_Params::_GetModelName(void)
    {
        return "UsbStreamParams";
    }

    //! \endcond

} // namespace Basler_UsbStreamParams

#endif // Basler_UsbStreamParams_PARAMS_H
