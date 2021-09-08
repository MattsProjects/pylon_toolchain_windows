//-----------------------------------------------------------------------------
//  Copyright (c) 2019-2021 Basler AG
//  Author:  DV
//-----------------------------------------------------------------------------
#pragma once

#include <pylon/Platform.h>
#include <pylon/PylonBase.h>
#include <pylon/Interface.h>
#include <pylon/internal/InterfaceBaseImpl.h>
#include <pylon/internal/InterfacePrivate.h>
#include <PlatformHelper/SimpleMutex.h>
#include <pylon/TransportLayer.h>

#if defined(PYLON_WIN_BUILD)
#pragma warning(push)
#pragma warning(disable: 4251) // class 'Baselibs::CSimpleMutex' needs to have dll-interface to be used by clients of class 'Pylon::CDefaultInterface' m_lock will never be acesses outside of this class
#endif

namespace Pylon
{
    // This is a default interface.
    // All IDeviceFactory functions are redirected to the parent transport layer.
    // All IInterface internal functions are dummy implementations.
    class PYLONBASE_API CDefaultInterface : public CInterfaceBase<IInterface>, public IInterfacePrivate
    {
    public:
        CDefaultInterface( ITransportLayer* parentTl, const CInterfaceInfo& info );
        ~CDefaultInterface();

        // not copyable
        CDefaultInterface( const CDefaultInterface& ) = delete;
        CDefaultInterface& operator=( const CDefaultInterface& ) = delete;

        /// \name IInterfacePrivate implementation
        // \{
        virtual void Delete();
        // \}

        /// \name IDeviceFactory implementation
        // \{
        virtual IPylonDevice* CreateDevice( const CDeviceInfo& deviceInfo ) override;
        virtual IPylonDevice* CreateFirstDevice( const CDeviceInfo& deviceInfo/*= CDeviceInfo()*/ ) override;
        virtual IPylonDevice* CreateDevice( const CDeviceInfo& deviceInfo, const StringList_t& InjectedXmlStrings ) override;
        virtual IPylonDevice* CreateFirstDevice( const CDeviceInfo& deviceInfo, const StringList_t& InjectedXmlStrings ) override;
        virtual IPylonDevice* CreateDevice( const String_t& fullName ) override;
        virtual void DestroyDevice( IPylonDevice* pDevice ) override;
        virtual bool IsDeviceAccessible( const CDeviceInfo& deviceInfo, AccessModeSet mode /*= Control*/, EDeviceAccessiblityInfo* pAccessibilityInfo /*= NULL*/ ) override;
        // \}

    protected:
        virtual void InternalOpen() override;
        virtual void InternalClose() override;
        virtual bool InternalIsOpen() const override;
        virtual const CInterfaceInfo& InternalGetInterfaceInfo() const override;
        virtual GENAPI_NAMESPACE::INodeMap* InternalGetNodeMap() override;
        virtual int InternalEnumerateDevices( DeviceInfoList_t& ) override;

    private:
        bool m_open;
        ITransportLayer* m_parentTl;
        CInterfaceInfo m_interfaceInfo;
        mutable Baselibs::CSimpleMutex m_lock;
    };

} // namespace Pylon

#if defined(PYLON_WIN_BUILD)
#pragma warning(pop)
#endif
