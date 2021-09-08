//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//  Author:  AG
//-----------------------------------------------------------------------------
/*!
\file
\brief    Generated part of template library for supporting access to GenAPI

*/

#ifndef INCLUDED_GTL_H_4828242
#define INCLUDED_GTL_H_4828242

#ifdef _MSC_VER
#   include <GenApi/Pointer.h>
#   include <GenApi/GenApi.h>
#else
#   include <PlatformHelper/GenApi_WithoutWarnings.h>
#endif

namespace gtl
{
    //Lists possible valueToSet correction strategies
    enum EValueCorrection
    {
        ValueCorrection_None,
        ValueCorrection_RoundUp,  //int only, round to larger value, float -> only min max clipping
        ValueCorrection_RoundDown, //int only, round to smaller value, float -> only min max clipping
        ValueCorrection_ToNearestValue //int only, float -> only min max clipping
    };


    [MACRO_BEGIN] [TRIM]

    //------------------------------------------------------------------------------
    // [ENTRY.]["Access Mode Test"] for I[ENTRY]["Node Type"]
    //------------------------------------------------------------------------------
        [MACRO_BEGIN.][TRIM]

            //[ENTRY.]["Access Mode Test"]
        inline bool[ENTRY.]["Access Mode Test"]( const GENAPI_NAMESPACE::C[ENTRY]["Node Type"]Ptr& ps[ENTRY]["Node Type"] )
    {
        //is not NULL?
        if (ps[ENTRY]["Node Type"])
        {
            return GENAPI_NAMESPACE::[ENTRY.]["Access Mode Test"]( ps[ENTRY]["Node Type"]->GetAccessMode() );
        }
        return false;
    }

    //[ENTRY.]["Access Mode Test"]
    inline bool[ENTRY.]["Access Mode Test"]( const GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"] )
    {
        //is not NULL?
        if (p[ENTRY]["Node Type"])
        {
            return GENAPI_NAMESPACE::[ENTRY.]["Access Mode Test"]( p[ENTRY]["Node Type"]->GetAccessMode() );
        }
        return false;
    }

    //[ENTRY.]["Access Mode Test"]
    inline bool[ENTRY.]["Access Mode Test"]( const GENAPI_NAMESPACE::I[ENTRY]["Node Type"] & p[ENTRY]["Node Type"] )
    {
        return[ENTRY.]["Access Mode Test"]( &p[ENTRY]["Node Type"] );
    }
    [MACRO_END.][MACRO_END][TRIM]


        [MACRO_BEGIN][TRIM]
        //------------------------------------------------------------------------------
        // [ENTRY]["Access Mode Test"] for INodeMap and Objects providing GetNodeMap()
        //------------------------------------------------------------------------------
            //[ENTRY]["Access Mode Test"]
        inline bool[ENTRY]["Access Mode Test"]( GENAPI_NAMESPACE::INode* pNode )
    {
        //is not NULL?
        if (pNode)
        {
            return GENAPI_NAMESPACE::[ENTRY]["Access Mode Test"]( pNode->GetAccessMode() );
        }
        return false;
    }

    //[ENTRY]["Access Mode Test"]
    inline bool[ENTRY]["Access Mode Test"]( GENAPI_NAMESPACE::INode& pNode )
    {
        return[ENTRY]["Access Mode Test"]( &pNode );
    }

    //[ENTRY]["Access Mode Test"]
    inline bool[ENTRY]["Access Mode Test"]( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return[ENTRY]["Access Mode Test"]( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //[ENTRY]["Access Mode Test"]
    inline bool[ENTRY]["Access Mode Test"]( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return[ENTRY]["Access Mode Test"]( &pNodeMap, nodeName );
    }

    //[ENTRY]["Access Mode Test"]
    template <typename T>
    inline bool[ENTRY]["Access Mode Test"]( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return[ENTRY]["Access Mode Test"]( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //[ENTRY]["Access Mode Test"]
    template <typename T>
    inline bool[ENTRY]["Access Mode Test"]( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return[ENTRY]["Access Mode Test"]( &object, nodeName );
    }

    [MACRO_END][TRIM]

    //------------------------------------------------------------------------------
    // Basic set node type pointer
    //------------------------------------------------------------------------------

        //correct min, max and increment
        inline int64_t CorrectIntValue( int64_t min, int64_t max, int64_t inc, int64_t v, EValueCorrection valueCorrection )
    {
        int64_t result = v;

        //clip min
        if (v < min)
        {
            result = min;
        }
        //clip max
        else if (v > max)
        {
            result = max;
        }
        else if (inc != 1 && ((v - min) % inc))
        {
            int64_t lowerValue = v - ((v - min) % inc);
            int64_t upperValue = lowerValue + inc;

            if (valueCorrection == ValueCorrection_ToNearestValue)
            {
                if ((v - lowerValue) >= (upperValue - v))
                {
                    result = upperValue;
                }
                else
                {
                    result = lowerValue;
                }
            }
            else if (valueCorrection == ValueCorrection_RoundUp)
            {
                result = upperValue;
            }
            else
            {
                result = lowerValue;
            }
        }

        return result;
    }


    [MACRO_BEGIN] [TRIM]
        //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
        inline bool SetValue( GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"], [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        if (p[ENTRY]["Node Type"])
        {
            //is writable
            if (GENAPI_NAMESPACE::IsWritable( p[ENTRY]["Node Type"]->GetAccessMode() ))
            {
                [BEGIN] [IF] [ENTRY] ["Node Type"] [EQUALS] ["Integer"] [TRIM]
                    int64_t min = p[ENTRY]["Node Type"]->GetMin();
                int64_t max = p[ENTRY]["Node Type"]->GetMax();
                int64_t inc = p[ENTRY]["Node Type"]->GetInc();
                //valueToSet correction enabled?
                if (valueCorrection != ValueCorrection_None)
                {
                    valueToSet = CorrectIntValue( min, max, inc, valueToSet, valueCorrection );
                }
                //check range and increment
                else
                {
                    if (valueToSet < min)
                    {
                        return false;
                    }
                    else if (valueToSet > max)
                    {
                        return false;
                    }
                    else if ((valueToSet - min) % inc)
                    {
                        return false;
                    }
                }
                p[ENTRY]["Node Type"]->SetValue( valueToSet );
                [OR] [IF] [ENTRY] ["Node Type"] [EQUALS] ["Float"] [TRIM]
                    double min = p[ENTRY]["Node Type"]->GetMin();
                double max = p[ENTRY]["Node Type"]->GetMax();
                //valueToSet correction enabled?
                if (valueCorrection != ValueCorrection_None)
                {
                    //clip min
                    if (valueToSet < min)
                    {
                        valueToSet = min;
                    }
                    //clip max
                    else if (valueToSet > max)
                    {
                        valueToSet = max;
                    }
                }
                //check range
                else
                {
                    if (valueToSet < min)
                    {
                        return false;
                    }
                    else if (valueToSet > max)
                    {
                        return false;
                    }
                }
                p[ENTRY]["Node Type"]->SetValue( valueToSet );
                [OR] [IF] [ENTRY] ["Node Type"] [EQUALS] ["Enumeration"] [TRIM]
                    GENAPI_NAMESPACE::IEnumEntry* entry = p[ENTRY]["Node Type"]->GetEntryByName( valueToSet );
                if (!(entry && GENAPI_NAMESPACE::IsAvailable( entry )))
                {
                    return false;
                }
                p[ENTRY]["Node Type"]->FromString( valueToSet );
                [OR] [TRIM]
                    p[ENTRY]["Node Type"]->SetValue( valueToSet );
                [END] [TRIM]
                    return true;
            }
        }
        return false;
    }

    [MACRO_END] [TRIM]


        [COMMENT] Min, Max, Inc values
        [MACRO_BEGIN][TRIM]

        //------------------------------------------------------------------------------
        // Get[ENTRY]["Value Constraints"] node type pointer
        //------------------------------------------------------------------------------

        [MACRO_BEGIN.][IF.][ENTRY.]["Has [ENTRY]["Value Constraints"]"][TRIM.]
            //tries to get the [ENTRY]["Value Constraints"][TO_LOWER] valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::I[ENTRY.]["Node Type"] * p[ENTRY.]["Node Type"], [ENTRY.]["C-Type"] defaultValue )
    {
        //is not NULL?
        if (p[ENTRY.]["Node Type"])
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( p[ENTRY.]["Node Type"]->GetAccessMode() ))
            {
                return p[ENTRY.]["Node Type"]->Get[ENTRY]["Value Constraints"]();
            }
        }
        return defaultValue;
    }

    [MACRO_END.][TRIM.]
        [MACRO_END][TRIM]

        //------------------------------------------------------------------------------
        // Basic get node type pointer
        //------------------------------------------------------------------------------

        [MACRO_BEGIN][TRIM]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"], [ENTRY]["C-Type"] defaultValue )
    {
        //is not NULL?
        if (p[ENTRY]["Node Type"])
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( p[ENTRY]["Node Type"]->GetAccessMode() ))
            {
                [BEGIN] [IF] [ENTRY] ["Node Type"] [EQUALS] ["Enumeration"] [TRIM]
                    return p[ENTRY]["Node Type"]->ToString();
                [OR] [TRIM]
                    return p[ENTRY]["Node Type"]->GetValue();
                [END] [TRIM]
            }
        }
        return defaultValue;
    }

    [MACRO_END] [TRIM]


    //------------------------------------------------------------------------------
    // Basic set node type reference
    //------------------------------------------------------------------------------

        [MACRO_BEGIN][TRIM]
            //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
        inline bool SetValue( GENAPI_NAMESPACE::I[ENTRY]["Node Type"] & nodeType, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        return SetValue( &nodeType, valueToSet[BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
    }

    [MACRO_END] [TRIM]

        [COMMENT] Min, Max, Inc values
        [MACRO_BEGIN][TRIM]

        //------------------------------------------------------------------------------
        // Get[ENTRY]["Value Constraints"] node type reference
        //------------------------------------------------------------------------------

        [MACRO_BEGIN.][IF.][ENTRY.]["Has [ENTRY]["Value Constraints"]"][TRIM.]
            //tries to get the [ENTRY]["Value Constraints"][TO_LOWER] valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::I[ENTRY.]["Node Type"] & nodeType, [ENTRY.]["C-Type"] defaultValue )
    {
        return Get[ENTRY]["Value Constraints"]( &nodeType, defaultValue );
    }

    [MACRO_END.][TRIM.]
        [MACRO_END][TRIM]

        //------------------------------------------------------------------------------
        // Basic get node type reference
        //------------------------------------------------------------------------------

        [MACRO_BEGIN][TRIM]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::I[ENTRY]["Node Type"] & nodeType, [ENTRY]["C-Type"] defaultValue )
    {
        return GetValue( &nodeType, defaultValue );
    }

    [MACRO_END] [TRIM]

    //------------------------------------------------------------------------------
    // Basic set GENAPI_NAMESPACE::INode*
    //------------------------------------------------------------------------------

        [MACRO_BEGIN][IF][NOT][ENTRY]["Doubled"][TRIM]
            //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
        inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        //is not NULL?
        if (pNode)
        {
            [BEGIN] [IF] [ENTRY] ["Node Type"] [EQUALS] ["Enumeration"] [TRIM]
                GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"] = dynamic_cast<GENAPI_NAMESPACE::I[ENTRY]["Node Type"] *>(pNode);
            if (p[ENTRY]["Node Type"])
            {
                return SetValue( p[ENTRY]["Node Type"], valueToSet[BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
            }
            else
            {
                //is alternative node type?
                GENAPI_NAMESPACE::IString* pString = dynamic_cast<GENAPI_NAMESPACE::IString*>(pNode);
                if (pString)
                {
                    pString->SetValue( valueToSet );
                    return true;
                }
            }
            [OR][TRIM]
                GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"] = dynamic_cast<GENAPI_NAMESPACE::I[ENTRY]["Node Type"] *>(pNode);
            return SetValue( p[ENTRY]["Node Type"], valueToSet[BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
            [END] [TRIM]
        }
        return false;
    }

    [MACRO_END] [TRIM]

        [COMMENT] Min, Max, Inc values
        [MACRO_BEGIN][TRIM]

        //------------------------------------------------------------------------------
        // Get[ENTRY]["Value Constraints"] GENAPI_NAMESPACE::INode*
        //------------------------------------------------------------------------------

        [MACRO_BEGIN.][IF.][ENTRY.]["Has [ENTRY]["Value Constraints"]"][TRIM.]
            //tries to get the [ENTRY]["Value Constraints"][TO_LOWER] valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::INode* pNode, [ENTRY.]["C-Type"] defaultValue )
    {
        GENAPI_NAMESPACE::I[ENTRY.]["Node Type"] * p[ENTRY.]["Node Type"] = dynamic_cast<GENAPI_NAMESPACE::I[ENTRY.]["Node Type"] *>(pNode);
        return Get[ENTRY]["Value Constraints"]( p[ENTRY.]["Node Type"], defaultValue );
    }

    [MACRO_END.][TRIM.]
        [MACRO_END][TRIM]

        //------------------------------------------------------------------------------
        // Basic get GENAPI_NAMESPACE::INode*
        //------------------------------------------------------------------------------

        [MACRO_BEGIN][IF][NOT][ENTRY]["Doubled"][TRIM]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::INode* pNode, [ENTRY]["C-Type"] defaultValue )
    {
        //is not NULL?
        if (pNode)
        {
            [BEGIN] [IF] [ENTRY] ["Node Type"] [EQUALS] ["Enumeration"] [TRIM]
                GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"] = dynamic_cast<GENAPI_NAMESPACE::I[ENTRY]["Node Type"] *>(pNode);
            if (p[ENTRY]["Node Type"])
            {
                return GetValue( p[ENTRY]["Node Type"], defaultValue );
            }
            else
            {
                //is alternative node type?
                GENAPI_NAMESPACE::IString* pString = dynamic_cast<GENAPI_NAMESPACE::IString*>(pNode);
                return GetValue( pString, defaultValue );
            }
            [OR][TRIM]
                GENAPI_NAMESPACE::I[ENTRY]["Node Type"] * p[ENTRY]["Node Type"] = dynamic_cast<GENAPI_NAMESPACE::I[ENTRY]["Node Type"] *>(pNode);
            return GetValue( p[ENTRY]["Node Type"], defaultValue );
            [END] [TRIM]
        }
        return defaultValue;
    }

    [MACRO_END] [TRIM]

    //------------------------------------------------------------------------------
    // Basic set GENAPI_NAMESPACE::INode* variants
    //------------------------------------------------------------------------------

        [MACRO_BEGIN][IF][ENTRY]["True Variant"][IF][NOT][ENTRY]["Doubled"][TRIM]
            //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
        inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        return SetValue( pNode, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(valueToSet)[OR]valueToSet[END][BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
    }

    [MACRO_END] [TRIM]

        [COMMENT] Min, Max, Inc values
        [MACRO_BEGIN][TRIM]

        //------------------------------------------------------------------------------
        // Get[ENTRY]["Value Constraints"] GENAPI_NAMESPACE::INode* variants
        //------------------------------------------------------------------------------

        [MACRO_BEGIN.][IF.][ENTRY.]["Has [ENTRY]["Value Constraints"]"][IF.][ENTRY.]["True Variant"][IF.][NOT.][ENTRY.]["Doubled"][TRIM.]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::INode* pNode, [ENTRY.]["C-Type"] defaultValue )
    {
        return Get[ENTRY]["Value Constraints"]( pNode, [BEGIN.]static_cast<[ENTRY.]["C-Type Target"]>(defaultValue)[OR.]defaultValue[END.] );
    }

    [MACRO_END.][TRIM.]
        [MACRO_END][TRIM]

        //------------------------------------------------------------------------------
        // Basic get GENAPI_NAMESPACE::INode* variants
        //------------------------------------------------------------------------------

        [MACRO_BEGIN][IF][ENTRY]["True Variant"][IF][NOT][ENTRY]["Doubled"][TRIM]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::INode* pNode, [ENTRY]["C-Type"] defaultValue )
    {
        return GetValue( pNode, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(defaultValue)[OR]defaultValue[END] );
    }

    [MACRO_END] [TRIM]

    //------------------------------------------------------------------------------
    // Basic set GENAPI_NAMESPACE::INode&
    //------------------------------------------------------------------------------

        [MACRO_BEGIN][IF][NOT][ENTRY]["Doubled"][TRIM]
            //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
        inline bool SetValue( GENAPI_NAMESPACE::INode& node, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        return SetValue( &node, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(valueToSet)[OR]valueToSet[END][BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
    }

    [MACRO_END] [TRIM]

        [COMMENT] Min, Max, Inc values
        [MACRO_BEGIN][TRIM]

        //------------------------------------------------------------------------------
        // Get[ENTRY]["Value Constraints"] GENAPI_NAMESPACE::INode&
        //------------------------------------------------------------------------------

        [MACRO_BEGIN.][IF.][ENTRY.]["Has [ENTRY]["Value Constraints"]"][IF.][NOT.][ENTRY.]["Doubled"][TRIM.]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::INode& node, [ENTRY.]["C-Type"] defaultValue )
    {
        return Get[ENTRY]["Value Constraints"]( &node, [BEGIN.]static_cast<[ENTRY.]["C-Type Target"]>(defaultValue)[OR.]defaultValue[END.] );
    }

    [MACRO_END.][TRIM.]
        [MACRO_END][TRIM]

        //------------------------------------------------------------------------------
        // Basic get GENAPI_NAMESPACE::INode&
        //------------------------------------------------------------------------------

        [MACRO_BEGIN][IF][NOT][ENTRY]["Doubled"][TRIM]
            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::INode& node, [ENTRY]["C-Type"] defaultValue )
    {
        return GetValue( &node, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(defaultValue)[OR]defaultValue[END] );
    }

    [MACRO_END] [TRIM]


        [MACRO_BEGIN] [IF] [NOT] [ENTRY] ["Doubled"] [TRIM]
        //------------------------------------------------------------------------------
        // Set for INodeMap and Objects providing GetNodeMap() with type [ENTRY]["C-Type"]
        //------------------------------------------------------------------------------

            //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
        inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(valueToSet)[OR]valueToSet[END][BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        return SetValue( &pNodeMap, nodeName, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(valueToSet)[OR]valueToSet[END][BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(valueToSet)[OR]valueToSet[END][BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] valueToSet[BEGIN][IF][ENTRY]["Clipable"], EValueCorrection valueCorrection = ValueCorrection_ToNearestValue[OR][END] )
    {
        return SetValue( &object, nodeName, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(valueToSet)[OR]valueToSet[END][BEGIN][IF][ENTRY]["Clipable"], valueCorrection[OR][END] );
    }

    [MACRO_END] [TRIM]

        [COMMENT] Min, Max, Inc values
        [MACRO_BEGIN][TRIM]

        [MACRO_BEGIN.][IF.][ENTRY.]["Has [ENTRY]["Value Constraints"]"][IF.][NOT.][ENTRY.]["Doubled"][TRIM.]
        //------------------------------------------------------------------------------
        // Get[ENTRY]["Value Constraints"] for INodeMap and Objects providing GetNodeMap() with type [ENTRY.]["C-Type"]
        //------------------------------------------------------------------------------

            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY.]["C-Type"] defaultValue )
    {
        if (pNodeMap)
        {
            return Get[ENTRY]["Value Constraints"]( pNodeMap->GetNode( nodeName ), [BEGIN.]static_cast<[ENTRY.]["C-Type Target"]>(defaultValue)[OR.]defaultValue[END.] );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY.]["C-Type"] defaultValue )
    {
        return Get[ENTRY]["Value Constraints"]( &pNodeMap, nodeName, [BEGIN.]static_cast<[ENTRY.]["C-Type Target"]>(defaultValue)[OR.]defaultValue[END.] );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY.]["C-Type"] defaultValue )
    {
        if (pObject)
        {
            return Get[ENTRY]["Value Constraints"]( pObject->GetNodeMap(), nodeName, [BEGIN.]static_cast<[ENTRY.]["C-Type Target"]>(defaultValue)[OR.]defaultValue[END.] );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline[ENTRY.]["C-Type for Return"] Get[ENTRY]["Value Constraints"]( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY.]["C-Type"] defaultValue )
    {
        return Get[ENTRY]["Value Constraints"]( &object, nodeName, [BEGIN.]static_cast<[ENTRY.]["C-Type Target"]>(defaultValue)[OR.]defaultValue[END.] );
    }

    [MACRO_END.][TRIM.]
        [MACRO_END][TRIM]

        [MACRO_BEGIN][IF][NOT][ENTRY]["Doubled"][TRIM]
        //------------------------------------------------------------------------------
        // Get for INodeMap and Objects providing GetNodeMap() with type [ENTRY]["C-Type"]
        //------------------------------------------------------------------------------

            //tries to get the valueToSet, node type is resolved by default valueToSet type
        inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(defaultValue)[OR]defaultValue[END] );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline[ENTRY]["C-Type for Return"] GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(defaultValue)[OR]defaultValue[END] );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline[ENTRY]["C-Type for Return"] GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(defaultValue)[OR]defaultValue[END] );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline[ENTRY]["C-Type for Return"] GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, [ENTRY]["C-Type"] defaultValue )
    {
        return GetValue( &object, nodeName, [BEGIN]static_cast<[ENTRY]["C-Type Target"]>(defaultValue)[OR]defaultValue[END] );
    }

    [MACRO_END] [TRIM]
}
#endif /* INCLUDED_GTL_H_4828242 */
