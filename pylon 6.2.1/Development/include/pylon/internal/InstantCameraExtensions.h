//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------

#ifndef INCLUDED_INSTANTCAMERAEXTENSIONS_H_3483698
#define INCLUDED_INSTANTCAMERAEXTENSIONS_H_3483698

namespace Pylon
{
    class IExternalLock
    {
    public:
        //Acquire the lock
        virtual void Lock() = 0;

        //Release the lock
        virtual void Unlock() = 0;
    };


    ///non public extensions of the instant camera
    class IInstantCameraExtensions
    {
    public:
        //triggers event processing, used by camera array
        virtual void ProcessAllEvents() = 0;

        //sets a provider for an external lock
        //this method must not be called while holding the original lock, otherwise the behavior is undefined
        virtual void SetExternalLock( IExternalLock* lock ) = 0;

        //the grab loop thread automatically stops the acquisition after grabbing a defined number of images is done
        //this can cause threading issues, because locks are not acquired properly or the high priority grab thread executes a user callback
        //default is enabled, set to false to disable this feature
        virtual void SetStopAcquisitionFromGrabLoopThread( bool enable ) = 0;

        //must be called outside the instant camera lock
        virtual void JoinWithGrabLoopThreadIfNeeded() = 0;
    };
}

#endif /* INCLUDED_INSTANTCAMERAEXTENSIONS_H_3483698 */
