//-----------------------------------------------------------------------------
//  Copyright (C) 2012-2016 Basler AG
//-----------------------------------------------------------------------------
#pragma once

#include <uxapi/UxTypes.h>
#include <uxapi/UxDll.h>


namespace uxapi
{
    // forward
    class CUxDevice;

    typedef size_t UxCallbackHandle;    ///< UxCallbackHandle type definition.

    const UxCallbackHandle cInvalidCallbackHandle = (UxCallbackHandle)0;    ///< Invalid callback handle.

    /// Type of callback.
    enum ECallbackType
    {
          CallbackType_DeviceArrived = 1    ///< Generic USB device has been connected to the system. See UxCallbackData::pwszDeviceName which device has triggered the callback.
        , CallbackType_DeviceRemoved        ///< Generic USB device disconnected from the system. See UxCallbackData::pwszDeviceName which device has triggered the callback.
        , CallbackType_DeviceNodeChanged    ///< A device has been added to or removed from the system. Applications that maintain lists of devices in the system should refresh their lists.
        , CallbackType_UxDeviceArrived = 10 ///< Specific UxDevice has been connected to the system. Note: the pDevice member of UxCallbackData will be NULL.
        , CallbackType_UxDeviceRemoved      ///< Specific UxDevice has been disconnected from the system.
        , CallbackType_UxDeviceSuspended    ///< Specific UxDevice has been suspended (e.g. by device power down)
    };

    //
    // -----------------------------------------------------------------------
    //struct UxCallbackData
    // -----------------------------------------------------------------------
    /**
    * \brief Information passed to callback functions
    */
    struct UxCallbackData
    {
        ECallbackType   CallbackType; ///< See ECallbackType
        void*           Context; ///< Context parameter passed when registering the callback
        CUxDevice*      pDevice; ///< pointer to CUxDevice object, may be NULL!
        const char*     pszDeviceInstanceID; ///< Internal device instance ID as reported by the system, encoded in utf-8 may be NULL.
    };

    /**
    \brief A device notification callback function type.
    \threading
    The callback registry is locked for other threads while the uxapi is calling a callback function.
    */
    typedef void(__stdcall * UxCallbackFuncPointer)( const UxCallbackData* );

    // -----------------------------------------------------------------------
    //struct UxCallbackParams
    // -----------------------------------------------------------------------
    /**
    * \brief Information required for callback
    */
    struct UxCallbackParams {
        ECallbackType               CallbackType;       ///< See ECallbackType
        void*                       Context;            ///< Context parameter. This will be passed to the callback function.
        CUxDevice*                  pDevice;            ///< Pointer to CUxDevice object. This must be set if CallbackType is set to CallbackType_UxDeviceRemoved. For any other CallbackType this will be ignored.
        UxCallbackFuncPointer       CallbackFunction;   ///< Address of a callback function. The callback must have the following signature: void __stdcall MyCallbackFunction( const UxCallbackData* pData);
    };

    /**
    \brief Register a callback function. See uxapi::UxCallbackParams for information. On success a callback handle will be returned in pCallbackHandle.
    \threading
    The callback registration is thread-safe.
    */
    UX_API UXSTATUS UxRegisterCallback(const UxCallbackParams* pParams, UxCallbackHandle* pCallbackHandle);

    /**
    \brief Deregister a callback function. The CallbackHandle is returned by the uxapi::UxRegisterCallback function.
    \threading
    The callback deregistration is thread-safe.
    */
    UX_API UXSTATUS UxDeregisterCallback(UxCallbackHandle CallbackHandle);

} // namespace uxapi
