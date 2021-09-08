
    




//-----------------------------------------------------------------------------
//  (c) 2004-2008 by Basler Vision Technologies
//  Section: Vision Components
//  Project: GenApi
//-----------------------------------------------------------------------------
/*!
\file
\brief Interface to the USB transport layer specific parameters.
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------



#ifndef Basler_UsbTLParams_PARAMS_H
#define Basler_UsbTLParams_PARAMS_H

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>

//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UsbTLParams
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    

    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Interface to the USB transport layer specific parameters.
    class CUsbTLParams_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
		// If you want to show the following methods in the help file
		// add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUsbTLParams_Params(void);

            //! Destructor
            ~CUsbTLParams_Params(void);

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
        
	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The total count of read pipe resets.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Read_Pipe_Reset_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The total count of write pipe resets.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Write_Pipe_Reset_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The total count of failed read operations.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Read_Operations_Failed_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The total count of failed write operations.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Write_Operations_Failed_Count;
    
    //@}
    

	//! \name Statistic - Statistical data.
    //@{
	/*!	
		\brief The last error status for a read or write operation.

	
	
		\b Visibility = Expert
	
    */
    GenApi::IInteger &Statistic_Last_Error_Status;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUsbTLParams_Params(CUsbTLParams_Params&);

            //! not implemented assignment operator
            CUsbTLParams_Params& operator=(CUsbTLParams_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CUsbTLParams_Params::CUsbTLParams_Params(void)
        : Statistic_Read_Pipe_Reset_Count( *new GenApi::CIntegerRef() )
        , Statistic_Write_Pipe_Reset_Count( *new GenApi::CIntegerRef() )
        , Statistic_Read_Operations_Failed_Count( *new GenApi::CIntegerRef() )
        , Statistic_Write_Operations_Failed_Count( *new GenApi::CIntegerRef() )
        , Statistic_Last_Error_Status( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CUsbTLParams_Params::~CUsbTLParams_Params(void)
    {
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Read_Pipe_Reset_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Write_Pipe_Reset_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Read_Operations_Failed_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Write_Operations_Failed_Count );
        delete static_cast < GenApi::CIntegerRef*> (&Statistic_Last_Error_Status );
        
    }

    inline void CUsbTLParams_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CIntegerRef*> (&Statistic_Read_Pipe_Reset_Count )->SetReference(_Ptr->GetNode("Statistic_Read_Pipe_Reset_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Write_Pipe_Reset_Count )->SetReference(_Ptr->GetNode("Statistic_Write_Pipe_Reset_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Read_Operations_Failed_Count )->SetReference(_Ptr->GetNode("Statistic_Read_Operations_Failed_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Write_Operations_Failed_Count )->SetReference(_Ptr->GetNode("Statistic_Write_Operations_Failed_Count"));
    static_cast<GenApi::CIntegerRef*> (&Statistic_Last_Error_Status )->SetReference(_Ptr->GetNode("Statistic_Last_Error_Status"));
    
    }

    inline const char* CUsbTLParams_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CUsbTLParams_Params::_GetModelName(void)
    {
        return "UsbTLParams";
    }

    //! \endcond

} // namespace Basler_UsbTLParams

#endif // Basler_UsbTLParams_PARAMS_H
