//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief  Contains the plug-in interface for pylon stream grabbers.
*/

#ifndef INCLUDED_STREAMGRABBERPLUGIN_H_2681085
#define INCLUDED_STREAMGRABBERPLUGIN_H_2681085

#include <pylon/stdinclude.h>
#include <pylon/StreamGrabber.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

namespace Pylon
{
    class GrabResult;
    class CModifiableGrabResult;

    /*!
    \interface  IStreamGrabberPlugin
    \brief  Usable to extend the capabilities of a pylon stream grabber.
    */
    interface IStreamGrabberPlugin
    {
        /*!
        \brief Initialize the pylon stream grabber plug-in.

        This method is called after a stream grabber has been retrieved.

        \attention Special care must be taken when making calls to the passed stream grabber
                   to not put it into an unexpected or bad state.

        \param[in]  pStreamGrabber The pointer to the stream grabber.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void Initialize( IStreamGrabber* pStreamGrabber ) = 0;


        /*!
        \brief Preprocess a grab result.

        This method can be used to preprocess a grab result.

        \param[in]      resultIn  The the grab result retrieved from the stream grabber.
        \param[in,out]  resultOut The the grab result that is returned to the user instead.

        \error
            Can not throw C++ exceptions.
            The status, the error code, and the error description of the \c resultOut parameter
            can be used to indicate error conditions to the user.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void PreprocessResult( const GrabResult& resultIn, CModifiableGrabResult& resultOut ) = 0;


        /*!
        \brief This method is called before the grab is prepared.

        The corresponding method is IStreamGrabber::PrepareGrab().

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnStreamGrabberPrepareGrab() = 0;


        /*!
        \brief This method is called after the grab has been prepared.

        The corresponding method is IStreamGrabber::PrepareGrab().

        \error
            Can throw C++ exceptions with base type GenICam::GenericException.
            Thrown exception will propagate to the pylon user code.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnStreamGrabberGrabPrepared() = 0;


        /*!
        \brief This method is called before the grab is finished.

        The corresponding method is IStreamGrabber::FinishGrab().

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnStreamGrabberFinishGrab() = 0;


        /*!
        \brief This method is called after the grab has finished.

        The corresponding method is IStreamGrabber::FinishGrab().

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnStreamGrabberGrabFinished() = 0;


        /*!
        \brief This method is called after the worker thread starts.

        This method is called if an additional worker thread is used.
        The worker thread retrieves the results from the stream grabber,
        calls PreprocessResult(), and puts the result of the preprocessing
        into another output queue.
        The call to this method can be used adjust the priority of
        the worker thread.

        \error
            Can not throw C++ exceptions.

        \threading
            Calls to this method are not synchronized.
        */
        virtual void OnWorkerThreadStarting() = 0;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */


#endif /* INCLUDED_STREAMGRABBERPLUGIN_H_2681085 */
