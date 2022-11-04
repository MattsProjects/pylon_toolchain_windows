//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2021-2022 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//------------------------------------------------------------------------------
/*!
 \file

 \brief
    Contains an enumeration that lists the built-in variant data types.
*/

#pragma once

#include <pylondataprocessing/PylonDataProcessing.h>

/*!
 * \namespace Pylon
 * \brief The Pylon namespace
 */
namespace Pylon
{
    /*!
     * \namespace Pylon::DataProcessing
     * \brief The DataProcessing namespace
     */
    namespace DataProcessing
    {
         /*!
         \brief
            Lists the built-in variant data types consisting of basic data types and a composite data type.

         Basic data types are used to build composite data types.
         Composite data types are defined by the vTools used in a recipe connected to inputs and outputs of the recipe.
        **/
        enum EVariantDataType
        {
            // Basic types
            VariantDataType_Int64 = 1,       //!< Corresponds to C++ data type int64_t. Default value = 0
            VariantDataType_UInt64 = 2,      //!< Corresponds to C++ data type uint64_t. Default value = 0
            VariantDataType_Boolean = 3,     //!< Corresponds to C++ data type bool. Default value = false
            VariantDataType_String = 4,      //!< Corresponds to C++ data type Pylon::String_t. The character encoding is UTF8. Default value = Pylon::String_t()
            VariantDataType_Float = 5,       //!< Corresponds to C++ data type double. Default value = 0.0
            VariantDataType_PylonImage = 6,  //!< Corresponds to C++ data type Pylon::CPylonImage. Default value = CPylonImage()

            // Composite type
            VariantDataType_Composite = 7,   //!< A composite struct of basic types, e.g., Thresholds { UInt8 lowerThreshold, UInt8 upperThreshold}.
                                             //!< Structs can be nested.
                                             //!< See the documentation of the vTools connected to inputs and outputs of the recipe
                                             //!< for more information about composite data types in case composite data types are used.

            //special
            VariantDataType_None = 0         //!< Corresponds to C++ data type void, no data is held.
        };
    }
}
