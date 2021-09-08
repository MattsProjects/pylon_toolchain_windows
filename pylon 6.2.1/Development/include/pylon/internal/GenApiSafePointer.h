//-----------------------------------------------------------------------------
// Copied and modified GenICam Pointer.h
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of template CSafePointer
\ingroup GenApi_PublicUtilities
*/

#pragma once

#ifndef GENAPI_SAFEPOINTER_H
#define GENAPI_SAFEPOINTER_H

#include <assert.h>

#include <Base/GCBase.h>

#include <GenApi/GenApiNamespace.h>
#include <GenApi/IBase.h>
#include <GenApi/INode.h>
#include <GenApi/IValue.h>
#include <GenApi/ICategory.h>
#include <GenApi/IInteger.h>
#include <GenApi/IFloat.h>
#include <GenApi/IRegister.h>
#include <GenApi/IEnumeration.h>
#include <GenApi/IEnumEntry.h>
#include <GenApi/IBoolean.h>
#include <GenApi/IPort.h>
#include <GenApi/IPortRecorder.h>
#include <GenApi/IPortConstruct.h>
#include <GenApi/IChunkPort.h>
#include <GenApi/IString.h>
#include <GenApi/INodeMap.h>
#include <GenApi/IDestroy.h>
#include <GenApi/IDeviceInfo.h>
#include <GenApi/ISelector.h>
#include <GenApi/ICommand.h>
#include <GenApi/NodeCallback.h>


#include <assert.h>

namespace GENAPI_NAMESPACE
{
    //*************************************************************
    // CSafePointer class
    //*************************************************************

    /**
    \brief Encapsulates a GenApi pointer dealing with the dynamic_cast automatically
    \ingroup GenApi_PublicUtilities
    */
    template <class T, class B = IBase>
    class CSafePointer : private CNodeCallback
    {

    public:
        //! Default constructor.
        CSafePointer( void ) throw()
            : CNodeCallback( NULL, cbPostOutsideLock )
            , m_pT( NULL )
            , m_callbackHandle( 0 )
        {
        }

        //! Constructor from INode pointer type.
        CSafePointer( B* pB )
            : CNodeCallback( NULL, cbPostOutsideLock )
            , m_pT( NULL )
            , m_callbackHandle( 0 )
        {
            attach( pB );
        }

        CSafePointer( const CSafePointer& rhs )
            : CNodeCallback( NULL, cbPostOutsideLock )
            , m_pT( NULL )
            , m_callbackHandle( 0 )
        {
            attach( rhs.m_pT );
        }

        CSafePointer& operator=( const CSafePointer& rhs )
        {
            attach( rhs.m_pT );
            return *this;
        }


        virtual ~CSafePointer( void )
        {
            remove();
        }

    private:
        void attach( B* pB )
        {
            remove();
            INode* pNode = dynamic_cast<INode*>(pB);
            T* pT = dynamic_cast<T*>(pB);
            if (pT)
            {
                m_pT = pT;
                if (pNode)
                {
                    m_callbackHandle = pNode->RegisterCallback( this );
                }
                else
                {
                    INodeMap* pNodeMap = dynamic_cast<INodeMap*>(pB);
                    if (pNodeMap)
                    {
                        INode* pRoot = pNodeMap->GetNode( "Root" );
                        if (pRoot)
                        {
                            m_callbackHandle = pRoot->RegisterCallback( this );
                        }
                    }
                }
            }
        }


        void remove( bool doDeregister = true )
        {
            if (doDeregister)
            {
                try
                {
                    if (m_pT)
                    {
                        INode* pNode = dynamic_cast<INode*>(m_pT);
                        if (pNode)
                        {
                            pNode->DeregisterCallback( m_callbackHandle );
                        }
                        else
                        {
                            INodeMap* pNodeMap = dynamic_cast<INodeMap*>(m_pT);
                            if (pNodeMap)
                            {
                                INode* pRoot = pNodeMap->GetNode( "Root" );
                                if (pRoot)
                                {
                                    pRoot->DeregisterCallback( m_callbackHandle );
                                }
                            }
                        }
                    }
                }
                catch (...)
                {
                    assert( false && "Deregister callback failed." );
                }
            }
            m_callbackHandle = 0;
            m_pT = NULL;
        }
    public:

            //implements CNodeCallback
        virtual void operator()( ECallbackType /*CallbackType*/ ) const
        {
            //no op
        }

        //implements CNodeCallback
        virtual void Destroy()
        {
            remove( false );
        }

        //! Assign INode Pointer
        void operator=( B* pB )
        {
            attach( pB );
        }

        //! Dereferencing
        operator T* (void) const
        {
            if (NULL == m_pT)
                throw LOGICAL_ERROR_EXCEPTION( "NULL pointer dereferenced" );
            return m_pT;
        }

        //! Dereferencing
        T& operator*( void ) const
        {
            if (NULL == m_pT)
                throw LOGICAL_ERROR_EXCEPTION( "NULL pointer dereferenced" );
            return *m_pT;
        }

        //! Dereferencing
        T& operator()( void ) const
        {
            if (NULL == m_pT)
                throw LOGICAL_ERROR_EXCEPTION( "NULL pointer dereferenced" );
            return *m_pT;
        }

        //! Dereferencing
        T* operator->( void ) const
        {
            if (NULL == m_pT)
                throw LOGICAL_ERROR_EXCEPTION( "NULL pointer dereferenced" );
            return m_pT;
        }

        //! true if the pointer is valid
        bool IsValid() const throw()
        {
            return m_pT != NULL;
        }

        //! true if the pointer is valid
        operator bool( void ) const throw()
        {
            return m_pT != NULL;
        }

        //! pointer equal
        bool operator==( T* pT ) const
        {
            return m_pT == pT;
        }

        //! pointer equal
        bool operator==( const CSafePointer<T, B>& rT ) const
        {
            return m_pT == rT.m_pT;
        }

        //! pointer equal
        bool operator==( int nMustBeNull ) const
        {
            if (0 != nMustBeNull)
                throw LOGICAL_ERROR_EXCEPTION( "argument must be NULL" );
            return NULL == m_pT;
        }

        //! pointer equal
        bool operator!=( T* pT ) const
        {
            return m_pT != pT;
        }

        //! pointer equal
        bool operator!=( const CSafePointer<T, B>& rT ) const
        {
            return m_pT != rT.m_pT;
        }

        //! pointer equal
        bool operator!=( int nMustBeNull ) const
        {
            if (0 != nMustBeNull)
                throw LOGICAL_ERROR_EXCEPTION( "argument must be NULL" );
            return NULL != m_pT;
        }

        T* get() const
        {
            return m_pT;
        }

    protected:

        //! Underlying raw pointer.
        T* m_pT;
        CallbackHandleType m_callbackHandle;
    };

    //*************************************************************
    // Smartpointer for all interface
    //*************************************************************

    //! \addtogroup GenApi_PublicUtilities
    //! \{

    //! SmartPointer for IBase interface pointer
    typedef CSafePointer<IBase> CSafeBasePtr;

    //! SmartPointer for INode interface pointer
    typedef CSafePointer<INode> CSafeNodePtr;

    //! SmartPointer for IValue interface pointer
    typedef CSafePointer<IValue> CSafeValuePtr;

    //! SmartPointer for ICategory interface pointer
    typedef CSafePointer<ICategory> CSafeCategoryPtr;

    //! SmartPointer for IBoolean interface pointer
    typedef CSafePointer<IBoolean> CSafeBooleanPtr;

    //! SmartPointer for IInteger interface pointer
    typedef CSafePointer<IInteger> CSafeIntegerPtr;

    //! SmartPointer for IString interface pointer
    typedef CSafePointer<IString> CSafeStringPtr;

    //! SmartPointer for IRegister interface pointer
    typedef CSafePointer<IRegister> CSafeRegisterPtr;

    //! SmartPointer for IEnumeration interface pointer
    typedef CSafePointer<IEnumeration> CSafeEnumerationPtr;

    //! SmartPointer for IEnumEntry interface pointer
    typedef CSafePointer<IEnumEntry> CSafeEnumEntryPtr;

    //! SmartPointer for IPort interface pointer
    typedef CSafePointer<IPort> CSafePortPtr;

    //! SmartPointer for IPortReplay interface pointer
    typedef CSafePointer<IPortReplay> CSafePortReplayPtr;

    //! SmartPointer for IPortRecorder interface pointer
    typedef CSafePointer<IPortRecorder> CSafePortRecorderPtr;

    //! SmartPointer for IPortWriteList interface pointer
    typedef CSafePointer<IPortWriteList, IPortWriteList> CSafePortWriteListPtr;

    //! SmartPointer for IChunkPort interface pointer
    typedef CSafePointer<IChunkPort> CSafeChunkPortPtr;

    //! SmartPointer for INodeMap interface pointer
    typedef CSafePointer<INodeMap, INodeMap> CSafeNodeMapPtr;

    //! SmartPointer for IDeviceInfo interface pointer
    typedef CSafePointer<IDeviceInfo, INodeMap> CSafeDeviceInfoPtr;

    //! SmartPointer for ISelector interface pointer
    typedef CSafePointer<ISelector> CSafeSelectorPtr;

    //! SmartPointer for ICommand interface pointer
    typedef CSafePointer<ICommand> CSafeCommandPtr;

    //! SmartPointer for IFloat interface pointer
    class CSafeFloatPtr : public CSafePointer<IFloat, IBase>
    {
    public:
        //! Default constructor.
        CSafeFloatPtr() throw()
            : CSafePointer<IFloat, IBase>()
        {
        }

        //! Constructor from IBase pointer type.
        CSafeFloatPtr( IBase* pB )
            : CSafePointer<IFloat, IBase>( pB )
        {
        }

        //! Assign IBase Pointer
        void operator=( IBase* pB )
        {
            CSafePointer<IFloat, IBase>::operator =( pB );
        }

        //! gets the interface of an integer alias node.
        IInteger* GetIntAlias()
        {
            return dynamic_cast<IInteger*>(m_pT->GetNode()->GetCastAlias());
        }

        //! gets the interface of an enum alias node.
        IEnumeration* GetEnumAlias()
        {
            return dynamic_cast<IEnumeration*>(m_pT->GetNode()->GetCastAlias());
        }
    };

    //! \}

    //! \addtogroup GenApi_PublicImpl
    //! \{

    //! SmartPointer for IPortConstruct interface pointer
    typedef CSafePointer<IPortConstruct> CSafePortConstructPtr;

    //! Checks if a node is readable
    template <class T, class B>
    inline bool IsReadable( const CSafePointer<T, B>& ptr )
    {
        return ptr.IsValid() && IsReadable( ptr->GetAccessMode() );
    }

    //! Checks if a node is Writable
    template <class T, class B>
    inline bool IsWritable( const CSafePointer<T, B>& ptr )
    {
        return ptr.IsValid() && IsWritable( ptr->GetAccessMode() );
    }

    //! Checks if a node is Implemented
    template <class T, class B>
    inline bool IsImplemented( const CSafePointer<T, B>& ptr )
    {
        return ptr.IsValid() && IsImplemented( ptr->GetAccessMode() );
    }

    //! Checks if a node is Available
    template <class T, class B>
    inline bool IsAvailable( const CSafePointer<T, B>& ptr )
    {
        return ptr.IsValid() && IsAvailable( ptr->GetAccessMode() );
    }

    template<class Client, class Member, class T, class B>
    inline intptr_t RegisterSafe( CSafePointer<T, B>& ptr, Client& c, Member m, ECallbackType CallbackType = cbPostInsideLock )
    {
        if (ptr)
        {
            CNodeCallback* pCallback( make_NodeCallback( ptr->GetNode(), c, m, CallbackType ) );
            return ptr->GetNode()->RegisterCallback( pCallback );
        }
        return 0;
    }


    template<class Client, class Member>
    inline intptr_t RegisterSafe( CSafeNodePtr& ptr, Client& c, Member m, ECallbackType CallbackType = cbPostInsideLock )
    {
        if (ptr)
        {
            CNodeCallback* pCallback( make_NodeCallback( ptr.get(), c, m, CallbackType ) );
            return ptr->RegisterCallback( pCallback );
        }
        return 0;
    }

    template <class T, class B>
    inline void DeregisterSafe( CSafePointer<T, B>& ptr, GENAPI_NAMESPACE::CallbackHandleType pCallbackInfo )
    {
        if (ptr)
        {
            assert( reinterpret_cast<CNodeCallback*>(pCallbackInfo)->GetNode() == ptr->GetNode() );
            Deregister( pCallbackInfo );
        }
    }

    inline void DeregisterSafe( CSafeNodePtr& ptr, GENAPI_NAMESPACE::CallbackHandleType pCallbackInfo )
    {
        if (ptr)
        {
            assert( reinterpret_cast<CNodeCallback*>(pCallbackInfo)->GetNode() == ptr.get() );
            Deregister( pCallbackInfo );
        }
    }
}

#endif // ifndef GENAPI_SAFEPOINTER_H
