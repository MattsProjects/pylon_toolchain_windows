//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2021-2022 Basler AG
//  http://www.baslerweb.com
//  Author:  TvdM
//------------------------------------------------------------------------------
/*!
\file
\brief Contains an interface that can be used to receive event data from a \c CRecipe.
*/

#pragma once

#include <pylon/stdinclude.h>
#include <pylondataprocessing/PylonDataProcessing.h>

namespace Pylon
{
    namespace DataProcessing
    {
        class CRecipe;
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
            Data associated with an event inside the recipe. Currently, only errors are supported.
         */
        struct PYLONDATAPROCESSING_API CEventData
        {
            /*!
               \brief
                  Type of event. Currently, only errors are supported.
            */
            enum EEventType
            {
                EventType_Error = 1,     //!< An error (e.g., of a vtool) is signaled as set (new error).
                EventType_ErrorReset = 2 //!< An error (e.g., of a vtool) is signaled as reset (removed error).
            } eventType;

            /*!
              \brief
                 Descriptive text, e.g., error message.
             */
            String_t description;

            /*!
            \brief
               Fully-qualified name of the signaled event, e.g., more detailed type of error.
            */
            String_t eventClass;

            /*!
            \brief
               Fully-qualified name of the owner who signaled the event, e.g., name of the vTool.
            */
            String_t eventSourceName;
        };

        /*!
         \brief
            An interface that can be used to receive event data from a \c CRecipe.

         \threading
            This interface is called from multiple internal threads of the \c CRecipe.
        */
        class IEventObserver
        {
        public:
            virtual ~IEventObserver() = default;

            /*!
             \brief
                This method is called when the graph of the \c CRecipe detects an event, e.g., an error change of a vtool.

             \param[in]  recipe          The recipe that produced the output.
             \param[in]  events          List of event infos as plain C array.
             \param[in]  numEvents       Number of entries in that list.

             \error
                C++ Exceptions thrown by this method are caught and ignored.
            */
            virtual bool OnEventSignaled(CRecipe& recipe, const CEventData* events, size_t numEvents) = 0;
        };
    }
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif
