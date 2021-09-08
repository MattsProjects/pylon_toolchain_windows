
    




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



#ifndef Basler_UsbChunkData_PARAMS_H
#define Basler_UsbChunkData_PARAMS_H

#include <GenApi/IEnumerationT.h>
#include <GenApi/NodeMapRef.h>
#include <GenApi/DLLLoad.h>

//! The namespace containing the device's control interface and related enumeration types
namespace Basler_UsbChunkData
{

    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************
    
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


    //**************************************************************************************************
    // Parameter class
    //**************************************************************************************************
    

    //! Basler USB3Vision camera interface
    class CUsbChunkData_Params
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
		// If you want to show the following methods in the help file
		// add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            CUsbChunkData_Params(void);

            //! Destructor
            ~CUsbChunkData_Params(void);

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
        
	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Selects which Gain to retrieve data from.

	Selects which Gain to retrieve data from.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<ChunkGainSelectorEnums > &ChunkGainSelector;
    
    //@}
    

	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Returns the gain used to capture the image.

	Returns the gain used to capture the image.
	
		\b Visibility = Beginner
        
	
		\b Selected by : ChunkGainSelector
	
    */
    GenApi::IFloat &ChunkGain;
    
    //@}
    

	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Returns the exposure time used to capture the image.

	Returns the exposure time used to capture the image.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IFloat &ChunkExposureTime;
    
    //@}
    

	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Indicates the value of the timestamp when the image was acquired

	This integer indicates the value of the timestamp when the image was acquired.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &ChunkTimestamp;
    
    //@}
    

	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Indicates the value of CRC checksum

	This integer indicates the value of CRC checksum.
	
		\b Visibility = Beginner
        
	
    */
    GenApi::IInteger &ChunkPayloadCRC16;
    
    //@}
    

	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Selects which counter to retrieve data from.

	Selects which counter to retrieve data from.
	
		\b Visibility = Expert
	
    */
    GenApi::IEnumerationT<ChunkCounterSelectorEnums > &ChunkCounterSelector;
    
    //@}
    

	//! \name ChunkData - This category includes items related to the chunk data that can be appended to the image data
    //@{
	/*!	
		\brief Indicates the value of the selected Chunk counter

	Indicates the value of the selected Chunk counter.
	
		\b Visibility = Beginner
        
	
		\b Selected by : ChunkCounterSelector
	
    */
    GenApi::IInteger &ChunkCounterValue;
    
    //@}
    


    private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            CUsbChunkData_Params(CUsbChunkData_Params&);

            //! not implemented assignment operator
            CUsbChunkData_Params& operator=(CUsbChunkData_Params&);

        //! \endcond
    };


    //**************************************************************************************************
    // Parameter class implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS

    inline CUsbChunkData_Params::CUsbChunkData_Params(void)
        : ChunkGainSelector( *new GenApi::CEnumerationTRef<ChunkGainSelectorEnums>() )
        , ChunkGain( *new GenApi::CFloatRef() )
        , ChunkExposureTime( *new GenApi::CFloatRef() )
        , ChunkTimestamp( *new GenApi::CIntegerRef() )
        , ChunkPayloadCRC16( *new GenApi::CIntegerRef() )
        , ChunkCounterSelector( *new GenApi::CEnumerationTRef<ChunkCounterSelectorEnums>() )
        , ChunkCounterValue( *new GenApi::CIntegerRef() )
        
    {
    }

    inline CUsbChunkData_Params::~CUsbChunkData_Params(void)
    {
        delete static_cast < GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector );
        delete static_cast < GenApi::CFloatRef*> (&ChunkGain );
        delete static_cast < GenApi::CFloatRef*> (&ChunkExposureTime );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkTimestamp );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkPayloadCRC16 );
        delete static_cast < GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector );
        delete static_cast < GenApi::CIntegerRef*> (&ChunkCounterValue );
        
    }

    inline void CUsbChunkData_Params::_Initialize(GenApi::INodeMap* _Ptr)
    {
        static_cast<GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector )->SetReference(_Ptr->GetNode("ChunkGainSelector"));
    static_cast<GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<ChunkGainSelectorEnums> *> (&ChunkGainSelector )->SetEnumReference( ChunkGainSelector_All, "All" );		static_cast<GenApi::CFloatRef*> (&ChunkGain )->SetReference(_Ptr->GetNode("ChunkGain"));
    static_cast<GenApi::CFloatRef*> (&ChunkExposureTime )->SetReference(_Ptr->GetNode("ChunkExposureTime"));
    static_cast<GenApi::CIntegerRef*> (&ChunkTimestamp )->SetReference(_Ptr->GetNode("ChunkTimestamp"));
    static_cast<GenApi::CIntegerRef*> (&ChunkPayloadCRC16 )->SetReference(_Ptr->GetNode("ChunkPayloadCRC16"));
    static_cast<GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector )->SetReference(_Ptr->GetNode("ChunkCounterSelector"));
    static_cast<GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector )->SetNumEnums(1);
	static_cast<GenApi::CEnumerationTRef<ChunkCounterSelectorEnums> *> (&ChunkCounterSelector )->SetEnumReference( ChunkCounterSelector_Counter1, "Counter1" );		static_cast<GenApi::CIntegerRef*> (&ChunkCounterValue )->SetReference(_Ptr->GetNode("ChunkCounterValue"));
    
    }

    inline const char* CUsbChunkData_Params::_GetVendorName(void)
    {
        return "Basler";
    }

    inline const char* CUsbChunkData_Params::_GetModelName(void)
    {
        return "UsbChunkData";
    }

    //! \endcond

} // namespace Basler_UsbChunkData

#endif // Basler_UsbChunkData_PARAMS_H
