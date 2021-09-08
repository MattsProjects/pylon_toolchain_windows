#pragma once
#include <pylon/internal/InfoPrivate.h>
#include <PlatformHelper/ProtectedMap.h>


namespace Pylon
{
    ///////////////////////////////////////////////////////////////////////////
    // Just for protected map extraction purposes
    class CProtectedDeviceInfo
        : public CInfoBase
    {
    public:
        SECURITY_NAMESPACE::CProtectedMap* GetContextData()
        {
            return SECURITY_NAMESPACE::CProtectedMap::GetMap( this->m_pImpl->m_contextData );
        }

        const SECURITY_NAMESPACE::CProtectedMap* GetContextData() const
        {
            return SECURITY_NAMESPACE::CProtectedMap::GetMap( this->m_pImpl->m_contextData );
        }
    };
}
