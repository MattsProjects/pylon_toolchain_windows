//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2021-2022 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//------------------------------------------------------------------------------
/*!
\file
\brief Contains an interface that can be used to receive output data from a \c CRecipe.
*/

#pragma once

#include <pylon/stdinclude.h>

#include <pylondataprocessing/PylonDataProcessing.h>
#include <pylondataprocessing/VariantContainer.h>

namespace Pylon
{
    namespace DataProcessing
    {
        class CRecipe;
        class CUpdate;
    }
}

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */
namespace Pylon
{
    namespace DataProcessing
    {
        /*!
         \brief
            An interface that can be used to receive output data from a \c CRecipe.

         \threading
            This interface is called from multiple internal threads of the \c CRecipe.
        */
        class IOutputObserver
        {
        public:
            virtual ~IOutputObserver() = default;

            /*!
             \brief
                This method is called when an output of the \c CRecipe pushes data out.

             \param[in]  recipe          The recipe that produced the output.
             \param[in]  value           A variant container containing the output data.
             \param[in]  update          The corresponding update.
             \param[in]  userProvidedId  This ID is passed to distinguish between different events.
                                         This ID has been passed when calling \c CRecipe::RegisterOutputObserver().

             \error
                C++ Exceptions thrown by this method are caught and ignored.
            */
            virtual void OutputDataPush(CRecipe& recipe, CVariantContainer value, const CUpdate& update, intptr_t userProvidedId) = 0;
        };
    }
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif
