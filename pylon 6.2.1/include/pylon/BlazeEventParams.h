//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

/*!
\file
\brief A parameter class containing all parameters as members that are available for blaze-101

blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
*/

//-----------------------------------------------------------------------------
//  This file is generated automatically
//  Do not modify!
//-----------------------------------------------------------------------------

#ifndef BASLER_PYLON_BLAZEEVENTPARAMS_H
#define BASLER_PYLON_BLAZEEVENTPARAMS_H

#pragma once

// common parameter types
#include <pylon/ParameterIncludes.h>
#include <pylon/EnumParameterT.h>

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4250 ) // warning C4250: 'Pylon::CXYZParameter': inherits 'Pylon::CParameter::Pylon::CParameter::ZYX' via dominance
#endif

//! The namespace containing the a control interface and related enumeration types for blaze-101
namespace Pylon
{
namespace BlazeEventParams_Params
{
    //**************************************************************************************************
    // Enumerations
    //**************************************************************************************************

    
    
    //**************************************************************************************************
    // Parameter class BlazeEventParams
    //**************************************************************************************************
    

    /*!
    \brief A parameter class containing all parameters as members that are available for blaze-101

    blaze-101 fw-4.1.0-20210519153005;fw-4.1.0-0-gd35a96ce
    */
    class BlazeEventParams
    {
    //----------------------------------------------------------------------------------------------------------------
    // Implementation
    //----------------------------------------------------------------------------------------------------------------
    protected:
        // If you want to show the following methods in the help file
        // add the string HIDE_CLASS_METHODS to the ENABLED_SECTIONS tag in the doxygen file
        //! \cond HIDE_CLASS_METHODS
        
            //! Constructor
            BlazeEventParams(void);

            //! Destructor
            ~BlazeEventParams(void);

            //! Initializes the references
            void _Initialize(GENAPI_NAMESPACE::INodeMap*);

    //! \endcond

    private:
        class BlazeEventParams_Data;
        BlazeEventParams_Data* m_pData;


    //----------------------------------------------------------------------------------------------------------------
    // References to features
    //----------------------------------------------------------------------------------------------------------------
    public:
        private:
        //! \cond HIDE_CLASS_METHODS

            //! not implemented copy constructor
            BlazeEventParams(BlazeEventParams&);

            //! not implemented assignment operator
            BlazeEventParams& operator=(BlazeEventParams&);

        //! \endcond
    };

    //**************************************************************************************************
    // Enumeration support classes
    //**************************************************************************************************
    //! \cond HIDE_CLASS_METHODS

    ///////////////////////////////////////////////////////////////////////////
    //
    namespace EnumParameterClasses
    {
    }

    //! \endcond
    //**************************************************************************************************
    // Parameter class BlazeEventParams implementation
    //**************************************************************************************************

    //! \cond HIDE_CLASS_METHODS
    
    ///////////////////////////////////////////////////////////////////////////
    //
    class BlazeEventParams::BlazeEventParams_Data
    {
    public:
    };


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeEventParams::BlazeEventParams(void)
        : m_pData(new BlazeEventParams_Data())
    {
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline BlazeEventParams::~BlazeEventParams(void)
    {
        delete m_pData;
    }


    ///////////////////////////////////////////////////////////////////////////
    //
    inline void BlazeEventParams::_Initialize(GENAPI_NAMESPACE::INodeMap* pNodeMap)
    {
        (void)pNodeMap;
    }

    //! \endcond

} // namespace Pylon
} // namespace BlazeEventParams_Params

#ifdef _MSC_VER
#pragma warning( pop )
#endif

#endif // BASLER_PYLON_BLAZEEVENTPARAMS_H