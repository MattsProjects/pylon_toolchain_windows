//------------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief    Non Generated part of template library for supporting access to GenAPI
*/

#ifndef INCLUDED_GTLSTATIC_H_06380868
#define INCLUDED_GTLSTATIC_H_06380868

#include <assert.h>

namespace gtl
{
//------------------------------------------------------------------------------
// SetValueFromList for Enumerations
//------------------------------------------------------------------------------
    //set first value from null terminated List that can be set, returns one based index of value set on success else 0
    inline unsigned int SetValueFromList( GENAPI_NAMESPACE::INode* pNode, const char** nullTerminatedList )
    {
        if (pNode)
        {
            for (unsigned int i = 1; *nullTerminatedList; ++nullTerminatedList, ++i)
            {
                if (SetValue( pNode, *nullTerminatedList ))
                {
                    return i;
                }
            }
        }
        return 0;
    }
    //set first value from null terminated List that can be set, returns one based index of value set on success else 0
    inline unsigned int SetValueFromList( GENAPI_NAMESPACE::INode& node, const char** nullTerminatedList )
    {
        return SetValueFromList( &node, nullTerminatedList );
    }


    //set first value from null terminated List that can be set, returns one based index of value set on success else 0
    inline unsigned int SetValueFromList( GENAPI_NAMESPACE::INodeMap* pNodemap, const GENICAM_NAMESPACE::gcstring& nodeName, const char** nullTerminatedList )
    {
        if (pNodemap)
        {
            return  SetValueFromList( pNodemap->GetNode( nodeName ), nullTerminatedList );
        }
        return 0;
    }

    //set first value from null terminated List that can be set, returns one based index of value set on success else 0
    inline unsigned int SetValueFromList( GENAPI_NAMESPACE::INodeMap& nodemap, const GENICAM_NAMESPACE::gcstring& nodeName, const char** nullTerminatedList )
    {
        return SetValueFromList( &nodemap, nodeName, nullTerminatedList );
    }

    //set first value from null terminated List that can be set, returns one based index of value set on success else 0
    template <typename T>
    inline unsigned int SetValueFromList( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, const char** nullTerminatedList )
    {
        if (pObject != NULL)
        {
            return SetValueFromList( pObject->GetNodeMap(), nodeName, nullTerminatedList );
        }
        return 0;
    }

    //set first value from null terminated List that can be set, returns one based index of value set on success else 0
    template <typename T>
    inline unsigned int SetValueFromList( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, const char** nullTerminatedList )
    {
        return SetValueFromList( &object, nodeName, nullTerminatedList );
    }


//------------------------------------------------------------------------------
// Execute for INodeMap and Objects providing GetNodeMap()
//------------------------------------------------------------------------------

    //Execute
    inline bool Execute( GENAPI_NAMESPACE::INode* pNode )
    {
        if (pNode)
        {
            //is writable?
            if (GENAPI_NAMESPACE::IsWritable( pNode->GetAccessMode() ))
            {
                //is correct node type?
                GENAPI_NAMESPACE::ICommand* pCommand = dynamic_cast<GENAPI_NAMESPACE::ICommand*>(pNode);
                if (pCommand)
                {
                    pCommand->Execute();
                    return true;
                }
            }
        }
        return false;
    }

    //Execute
    inline bool Execute( GENAPI_NAMESPACE::INode& node )
    {
        return Execute( &node );
    }

    //Execute
    inline bool Execute( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return Execute( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //Execute
    inline bool Execute( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return Execute( &pNodeMap, nodeName );
    }

    //Execute
    template <typename T>
    inline bool Execute( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return Execute( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //Execute
    template <typename T>
    inline bool Execute( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return Execute( &object, nodeName );
    }

    //------------------------------------------------------------------------------
    // CanExecute for INodeMap and Objects providing GetNodeMap()
    //------------------------------------------------------------------------------

    //CanExecute
    inline bool CanExecute( GENAPI_NAMESPACE::INode* pNode )
    {
        if (pNode)
        {
            //is writable?
            if (GENAPI_NAMESPACE::IsWritable( pNode->GetAccessMode() ))
            {
                //is correct node type?
                GENAPI_NAMESPACE::ICommand* pCommand = dynamic_cast<GENAPI_NAMESPACE::ICommand*>(pNode);
                if (pCommand)
                {
                    return pCommand->IsDone();
                }
            }
        }
        return false;
    }

    //CanExecute
    inline bool CanExecute( GENAPI_NAMESPACE::INode& node )
    {
        return CanExecute( &node );
    }

    //CanExecute
    inline bool CanExecute( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return CanExecute( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //CanExecute
    inline bool CanExecute( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return CanExecute( &pNodeMap, nodeName );
    }

    //CanExecute
    template <typename T>
    inline bool CanExecute( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return CanExecute( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //CanExecute
    template <typename T>
    inline bool CanExecute( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return CanExecute( &object, nodeName );
    }
}

#endif /* INCLUDED_GTLSTATIC_H_06380868 */
