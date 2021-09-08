#pragma once

#include <Base/GCString.h>
#include <GenApi/INodeMap.h>
#include <GenApi/IDestroy.h>
#include <GenApi/NodeMapFactory.h>
#include <pylon/stdinclude.h> // for PYLON_ASSERT
#include <pylon/internal/EmbeddedNodeMapFactory.h>

namespace Pylon
{

    // simple wrapper class to instantiate a genicam3 nodemap
    // use together with PYLON_POWER_NODE macro to get easy access to
    // nodes in the nodemap

    // class CMyPowerNodeMap : public CPylonPowerNodeMapPtr
    //{
    //    CMyPowerNodeMap() {}
    //
    //    PYLON_POWER_NODE(Width, GENAPI_NAMESPACE::IInteger)
    //    PYLON_POWER_NODE(PixelFormat, GENAPI_NAMESPACE::IEnumeration)
    //    PYLON_POWER_NODE(EnumEntry_PixelFormat_Mono8, GENAPI_NAMESPACE::IEnumEntry)
    //};

    class CPylonPowerNodeMapPtr
    {
    public:
        CPylonPowerNodeMapPtr()
            : m_pNodeMap( NULL )
        {
        }


        //////////////////////////////////////////////////////////////////////
        //
        CPylonPowerNodeMapPtr( GENAPI_NAMESPACE::INodeMap* pNodeMap )
            : m_pNodeMap( pNodeMap )
        {
            PYLON_ASSERT2( m_pNodeMap == NULL || dynamic_cast<GENAPI_NAMESPACE::IDestroy*>(m_pNodeMap) != NULL, "NodeMap should be IDestroyable derived." );
        }


        //////////////////////////////////////////////////////////////////////
        //
        virtual ~CPylonPowerNodeMapPtr()
        {
            destroy();
        }


        //////////////////////////////////////////////////////////////////////
        //
        bool loadFromString( const char* pszXML )
        {
            if (pszXML == NULL)
            {
                return false;
            }

            GENICAM_NAMESPACE::gcstring strXML;

            GENAPI_NAMESPACE::CNodeMapFactory fac( pszXML );
            GENAPI_NAMESPACE::INodeMap* pNodeMap = fac.CreateNodeMap();

            // nodemap has been successfully created, replace the current with new newly created
            attach( pNodeMap );

            return true;
        }


        //////////////////////////////////////////////////////////////////////
        //
        bool loadFromResource( const char* pszName )
        {
            if (pszName == NULL)
            {
                return false;
            }

            GENAPI_NAMESPACE::INodeMap* pNodeMap = CreateNodeMapFromEmbeddedXML( pszName );
            if (pNodeMap != NULL)
            {
                attach( pNodeMap );
                return true;
            }

            return false;
        }


        //////////////////////////////////////////////////////////////////////
        //
        void attach( GENAPI_NAMESPACE::INodeMap* pNodeMap )
        {
            destroy();
            m_pNodeMap = pNodeMap;
        }


        //////////////////////////////////////////////////////////////////////
        //
        GENAPI_NAMESPACE::INodeMap* detach()
        {
            GENAPI_NAMESPACE::INodeMap* pNodeMap = m_pNodeMap;
            m_pNodeMap = NULL;

            return pNodeMap;
        }


        //////////////////////////////////////////////////////////////////////
        //
        bool destroy()
        {
            // TODO: call CNodeMapFactory to destroy when its available
            GENAPI_NAMESPACE::IDestroy* pDestroyable = dynamic_cast<GENAPI_NAMESPACE::IDestroy*>(m_pNodeMap);
            PYLON_ASSERT2( m_pNodeMap == NULL || pDestroyable != NULL, "NodeMap should be IDestroyable derived." );
            if (pDestroyable != NULL)
            {
                pDestroyable->Destroy();
                m_pNodeMap = NULL;
                return true;
            }

            return false;
        }


        //////////////////////////////////////////////////////////////////////
        //
        bool isValid() const
        {
            bool res = m_pNodeMap != NULL;
            return res;
        }


        //////////////////////////////////////////////////////////////////////
        //
        GENAPI_NAMESPACE::INodeMap* get()
        {
            if (m_pNodeMap == NULL)
            {
                throw RUNTIME_EXCEPTION( "NULL pointer dereferenced" );
            }

            return m_pNodeMap;
        }


        //////////////////////////////////////////////////////////////////////
        //
        const GENAPI_NAMESPACE::INodeMap* get() const
        {
            if (m_pNodeMap == NULL)
            {
                throw RUNTIME_EXCEPTION( "NULL pointer dereferenced" );
            }

            return m_pNodeMap;
        }


        //////////////////////////////////////////////////////////////////////
        //
        GENAPI_NAMESPACE::INodeMap* operator -> ()
        {
            if (m_pNodeMap == NULL)
            {
                throw RUNTIME_EXCEPTION( "NULL pointer dereferenced" );
            }

            return m_pNodeMap;
        }

        //////////////////////////////////////////////////////////////////////
        //
        operator GENAPI_NAMESPACE::INodeMap* ()
        {
            if (m_pNodeMap == NULL)
            {
                throw RUNTIME_EXCEPTION( "NULL pointer dereferenced" );
            }

            return m_pNodeMap;
        }

        //////////////////////////////////////////////////////////////////////
        //
        GENAPI_NAMESPACE::INodeMap& operator* ()
        {
            if (m_pNodeMap == NULL)
            {
                throw RUNTIME_EXCEPTION( "NULL pointer dereferenced" );
            }

            return *m_pNodeMap;
        }

    private:
        // no copy
        CPylonPowerNodeMapPtr( const CPylonPowerNodeMapPtr& );
        CPylonPowerNodeMapPtr& operator=( const CPylonPowerNodeMapPtr& );

    protected:
        GENAPI_NAMESPACE::INodeMap* m_pNodeMap;
    };

} // namespace Pylon

// usage:
// PYLON_POWER_NODE (Width, GENAPI_NAMESPACE::IInteger)
// results in a memberfunc
// GENAPI_NAMESPACE::INode* GetWidth()
#define PYLON_POWER_NODE(nodeName_, type_) \
    private: \
    mutable GENAPI_NAMESPACE::CPointer<type_> m_ptr##nodeName_ ; \
    public: \
    type_* get_##nodeName_ () \
    { \
        if (!m_ptr##nodeName_.IsValid()) \
        { \
            m_ptr##nodeName_ = this->get()->GetNode(#nodeName_); \
        } \
        return (type_*)m_ptr##nodeName_; \
    } \
    \
    const type_* get_##nodeName_() const \
    { \
        if (!m_ptr##nodeName_.IsValid()) \
                        { \
            m_ptr##nodeName_ = this->get()->GetNode(#nodeName_); \
                        } \
        return (type_*)m_ptr##nodeName_; \
    }

