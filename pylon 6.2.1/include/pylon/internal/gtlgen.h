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



//------------------------------------------------------------------------------
// IsReadable for IBoolean
// IsWritable for IBoolean
// IsImplemented for IBoolean
// IsAvailable for IBoolean
//------------------------------------------------------------------------------

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::CBooleanPtr& psBoolean )
    {
        //is not NULL?
        if (psBoolean)
        {
            return GENAPI_NAMESPACE::IsReadable( psBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IBoolean* pBoolean )
    {
        //is not NULL?
        if (pBoolean)
        {
            return GENAPI_NAMESPACE::IsReadable( pBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IBoolean& pBoolean )
    {
        return IsReadable( &pBoolean );
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::CBooleanPtr& psBoolean )
    {
        //is not NULL?
        if (psBoolean)
        {
            return GENAPI_NAMESPACE::IsWritable( psBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IBoolean* pBoolean )
    {
        //is not NULL?
        if (pBoolean)
        {
            return GENAPI_NAMESPACE::IsWritable( pBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IBoolean& pBoolean )
    {
        return IsWritable( &pBoolean );
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::CBooleanPtr& psBoolean )
    {
        //is not NULL?
        if (psBoolean)
        {
            return GENAPI_NAMESPACE::IsImplemented( psBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IBoolean* pBoolean )
    {
        //is not NULL?
        if (pBoolean)
        {
            return GENAPI_NAMESPACE::IsImplemented( pBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IBoolean& pBoolean )
    {
        return IsImplemented( &pBoolean );
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::CBooleanPtr& psBoolean )
    {
        //is not NULL?
        if (psBoolean)
        {
            return GENAPI_NAMESPACE::IsAvailable( psBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IBoolean* pBoolean )
    {
        //is not NULL?
        if (pBoolean)
        {
            return GENAPI_NAMESPACE::IsAvailable( pBoolean->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IBoolean& pBoolean )
    {
        return IsAvailable( &pBoolean );
    }

//------------------------------------------------------------------------------
// IsReadable for IInteger
// IsWritable for IInteger
// IsImplemented for IInteger
// IsAvailable for IInteger
//------------------------------------------------------------------------------

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::CIntegerPtr& psInteger )
    {
        //is not NULL?
        if (psInteger)
        {
            return GENAPI_NAMESPACE::IsReadable( psInteger->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IInteger* pInteger )
    {
        //is not NULL?
        if (pInteger)
        {
            return GENAPI_NAMESPACE::IsReadable( pInteger->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IInteger& pInteger )
    {
        return IsReadable( &pInteger );
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::CIntegerPtr& psInteger )
    {
        //is not NULL?
        if (psInteger)
        {
            return GENAPI_NAMESPACE::IsWritable( psInteger->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IInteger* pInteger )
    {
        //is not NULL?
        if (pInteger)
        {
            return GENAPI_NAMESPACE::IsWritable( pInteger->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IInteger& pInteger )
    {
        return IsWritable( &pInteger );
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::CIntegerPtr& psInteger )
    {
        //is not NULL?
        if (psInteger)
        {
            return GENAPI_NAMESPACE::IsImplemented( psInteger->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IInteger* pInteger )
    {
        //is not NULL?
        if (pInteger)
        {
            return GENAPI_NAMESPACE::IsImplemented( pInteger->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IInteger& pInteger )
    {
        return IsImplemented( &pInteger );
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::CIntegerPtr& psInteger )
    {
        //is not NULL?
        if (psInteger)
        {
            return GENAPI_NAMESPACE::IsAvailable( psInteger->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IInteger* pInteger )
    {
        //is not NULL?
        if (pInteger)
        {
            return GENAPI_NAMESPACE::IsAvailable( pInteger->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IInteger& pInteger )
    {
        return IsAvailable( &pInteger );
    }

//------------------------------------------------------------------------------
// IsReadable for IEnumeration
// IsWritable for IEnumeration
// IsImplemented for IEnumeration
// IsAvailable for IEnumeration
//------------------------------------------------------------------------------

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::CEnumerationPtr& psEnumeration )
    {
        //is not NULL?
        if (psEnumeration)
        {
            return GENAPI_NAMESPACE::IsReadable( psEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IEnumeration* pEnumeration )
    {
        //is not NULL?
        if (pEnumeration)
        {
            return GENAPI_NAMESPACE::IsReadable( pEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IEnumeration& pEnumeration )
    {
        return IsReadable( &pEnumeration );
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::CEnumerationPtr& psEnumeration )
    {
        //is not NULL?
        if (psEnumeration)
        {
            return GENAPI_NAMESPACE::IsWritable( psEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IEnumeration* pEnumeration )
    {
        //is not NULL?
        if (pEnumeration)
        {
            return GENAPI_NAMESPACE::IsWritable( pEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IEnumeration& pEnumeration )
    {
        return IsWritable( &pEnumeration );
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::CEnumerationPtr& psEnumeration )
    {
        //is not NULL?
        if (psEnumeration)
        {
            return GENAPI_NAMESPACE::IsImplemented( psEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IEnumeration* pEnumeration )
    {
        //is not NULL?
        if (pEnumeration)
        {
            return GENAPI_NAMESPACE::IsImplemented( pEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IEnumeration& pEnumeration )
    {
        return IsImplemented( &pEnumeration );
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::CEnumerationPtr& psEnumeration )
    {
        //is not NULL?
        if (psEnumeration)
        {
            return GENAPI_NAMESPACE::IsAvailable( psEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IEnumeration* pEnumeration )
    {
        //is not NULL?
        if (pEnumeration)
        {
            return GENAPI_NAMESPACE::IsAvailable( pEnumeration->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IEnumeration& pEnumeration )
    {
        return IsAvailable( &pEnumeration );
    }

//------------------------------------------------------------------------------
// IsReadable for IFloat
// IsWritable for IFloat
// IsImplemented for IFloat
// IsAvailable for IFloat
//------------------------------------------------------------------------------

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::CFloatPtr& psFloat )
    {
        //is not NULL?
        if (psFloat)
        {
            return GENAPI_NAMESPACE::IsReadable( psFloat->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IFloat* pFloat )
    {
        //is not NULL?
        if (pFloat)
        {
            return GENAPI_NAMESPACE::IsReadable( pFloat->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IFloat& pFloat )
    {
        return IsReadable( &pFloat );
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::CFloatPtr& psFloat )
    {
        //is not NULL?
        if (psFloat)
        {
            return GENAPI_NAMESPACE::IsWritable( psFloat->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IFloat* pFloat )
    {
        //is not NULL?
        if (pFloat)
        {
            return GENAPI_NAMESPACE::IsWritable( pFloat->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IFloat& pFloat )
    {
        return IsWritable( &pFloat );
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::CFloatPtr& psFloat )
    {
        //is not NULL?
        if (psFloat)
        {
            return GENAPI_NAMESPACE::IsImplemented( psFloat->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IFloat* pFloat )
    {
        //is not NULL?
        if (pFloat)
        {
            return GENAPI_NAMESPACE::IsImplemented( pFloat->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IFloat& pFloat )
    {
        return IsImplemented( &pFloat );
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::CFloatPtr& psFloat )
    {
        //is not NULL?
        if (psFloat)
        {
            return GENAPI_NAMESPACE::IsAvailable( psFloat->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IFloat* pFloat )
    {
        //is not NULL?
        if (pFloat)
        {
            return GENAPI_NAMESPACE::IsAvailable( pFloat->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IFloat& pFloat )
    {
        return IsAvailable( &pFloat );
    }

//------------------------------------------------------------------------------
// IsReadable for IString
// IsWritable for IString
// IsImplemented for IString
// IsAvailable for IString
//------------------------------------------------------------------------------

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::CStringPtr& psString )
    {
        //is not NULL?
        if (psString)
        {
            return GENAPI_NAMESPACE::IsReadable( psString->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IString* pString )
    {
        //is not NULL?
        if (pString)
        {
            return GENAPI_NAMESPACE::IsReadable( pString->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( const GENAPI_NAMESPACE::IString& pString )
    {
        return IsReadable( &pString );
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::CStringPtr& psString )
    {
        //is not NULL?
        if (psString)
        {
            return GENAPI_NAMESPACE::IsWritable( psString->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IString* pString )
    {
        //is not NULL?
        if (pString)
        {
            return GENAPI_NAMESPACE::IsWritable( pString->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( const GENAPI_NAMESPACE::IString& pString )
    {
        return IsWritable( &pString );
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::CStringPtr& psString )
    {
        //is not NULL?
        if (psString)
        {
            return GENAPI_NAMESPACE::IsImplemented( psString->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IString* pString )
    {
        //is not NULL?
        if (pString)
        {
            return GENAPI_NAMESPACE::IsImplemented( pString->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( const GENAPI_NAMESPACE::IString& pString )
    {
        return IsImplemented( &pString );
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::CStringPtr& psString )
    {
        //is not NULL?
        if (psString)
        {
            return GENAPI_NAMESPACE::IsAvailable( psString->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IString* pString )
    {
        //is not NULL?
        if (pString)
        {
            return GENAPI_NAMESPACE::IsAvailable( pString->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( const GENAPI_NAMESPACE::IString& pString )
    {
        return IsAvailable( &pString );
    }


//------------------------------------------------------------------------------
// IsReadable for INodeMap and Objects providing GetNodeMap()
//------------------------------------------------------------------------------
    //IsReadable
    inline bool IsReadable( GENAPI_NAMESPACE::INode* pNode )
    {
        //is not NULL?
        if (pNode)
        {
            return GENAPI_NAMESPACE::IsReadable( pNode->GetAccessMode() );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( GENAPI_NAMESPACE::INode& pNode )
    {
        return IsReadable( &pNode );
    }

    //IsReadable
    inline bool IsReadable( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return IsReadable( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //IsReadable
    inline bool IsReadable( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsReadable( &pNodeMap, nodeName );
    }

    //IsReadable
    template <typename T>
    inline bool IsReadable( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return IsReadable( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //IsReadable
    template <typename T>
    inline bool IsReadable( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsReadable( &object, nodeName );
    }

//------------------------------------------------------------------------------
// IsWritable for INodeMap and Objects providing GetNodeMap()
//------------------------------------------------------------------------------
    //IsWritable
    inline bool IsWritable( GENAPI_NAMESPACE::INode* pNode )
    {
        //is not NULL?
        if (pNode)
        {
            return GENAPI_NAMESPACE::IsWritable( pNode->GetAccessMode() );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( GENAPI_NAMESPACE::INode& pNode )
    {
        return IsWritable( &pNode );
    }

    //IsWritable
    inline bool IsWritable( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return IsWritable( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //IsWritable
    inline bool IsWritable( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsWritable( &pNodeMap, nodeName );
    }

    //IsWritable
    template <typename T>
    inline bool IsWritable( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return IsWritable( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //IsWritable
    template <typename T>
    inline bool IsWritable( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsWritable( &object, nodeName );
    }

//------------------------------------------------------------------------------
// IsImplemented for INodeMap and Objects providing GetNodeMap()
//------------------------------------------------------------------------------
    //IsImplemented
    inline bool IsImplemented( GENAPI_NAMESPACE::INode* pNode )
    {
        //is not NULL?
        if (pNode)
        {
            return GENAPI_NAMESPACE::IsImplemented( pNode->GetAccessMode() );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( GENAPI_NAMESPACE::INode& pNode )
    {
        return IsImplemented( &pNode );
    }

    //IsImplemented
    inline bool IsImplemented( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return IsImplemented( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //IsImplemented
    inline bool IsImplemented( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsImplemented( &pNodeMap, nodeName );
    }

    //IsImplemented
    template <typename T>
    inline bool IsImplemented( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return IsImplemented( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //IsImplemented
    template <typename T>
    inline bool IsImplemented( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsImplemented( &object, nodeName );
    }

//------------------------------------------------------------------------------
// IsAvailable for INodeMap and Objects providing GetNodeMap()
//------------------------------------------------------------------------------
    //IsAvailable
    inline bool IsAvailable( GENAPI_NAMESPACE::INode* pNode )
    {
        //is not NULL?
        if (pNode)
        {
            return GENAPI_NAMESPACE::IsAvailable( pNode->GetAccessMode() );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( GENAPI_NAMESPACE::INode& pNode )
    {
        return IsAvailable( &pNode );
    }

    //IsAvailable
    inline bool IsAvailable( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        //is not NULL?
        if (pNodeMap)
        {
            return IsAvailable( pNodeMap->GetNode( nodeName ) );
        }
        return false;
    }

    //IsAvailable
    inline bool IsAvailable( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsAvailable( &pNodeMap, nodeName );
    }

    //IsAvailable
    template <typename T>
    inline bool IsAvailable( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        if (pObject)
        {
            return IsAvailable( pObject->GetNodeMap(), nodeName );
        }
        return false;
    }

    //IsAvailable
    template <typename T>
    inline bool IsAvailable( T& object, const GENICAM_NAMESPACE::gcstring& nodeName )
    {
        return IsAvailable( &object, nodeName );
    }


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

    //correct min, max
    inline double CorrectDoubleValue( double min, double max, double v )
    {
        double result = v;

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
        return result;
    }
    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IBoolean* pBoolean, bool valueToSet )
    {
        if (pBoolean)
        {
            //is writable
            if (GENAPI_NAMESPACE::IsWritable( pBoolean->GetAccessMode() ))
            {
                pBoolean->SetValue( valueToSet );
                return true;
            }
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IInteger* pInteger, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pInteger)
        {
            //is writable
            if (GENAPI_NAMESPACE::IsWritable( pInteger->GetAccessMode() ))
            {
                int64_t min = pInteger->GetMin();
                int64_t max = pInteger->GetMax();
                int64_t inc = pInteger->GetInc();
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
                pInteger->SetValue( valueToSet );
                return true;
            }
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IEnumeration* pEnumeration, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        if (pEnumeration)
        {
            //is writable
            if (GENAPI_NAMESPACE::IsWritable( pEnumeration->GetAccessMode() ))
            {
                GENAPI_NAMESPACE::IEnumEntry* entry = pEnumeration->GetEntryByName( valueToSet );
                if (!(entry && GENAPI_NAMESPACE::IsAvailable( entry )))
                {
                    return false;
                }
                pEnumeration->FromString( valueToSet );
                return true;
            }
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IFloat* pFloat, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pFloat)
        {
            //is writable
            if (GENAPI_NAMESPACE::IsWritable( pFloat->GetAccessMode() ))
            {
                double min = pFloat->GetMin();
                double max = pFloat->GetMax();
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
                pFloat->SetValue( valueToSet );
                return true;
            }
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IString* pString, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        if (pString)
        {
            //is writable
            if (GENAPI_NAMESPACE::IsWritable( pString->GetAccessMode() ))
            {
                pString->SetValue( valueToSet );
                return true;
            }
        }
        return false;
    }




//------------------------------------------------------------------------------
// GetMin node type pointer
//------------------------------------------------------------------------------

    //tries to get the min valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::IInteger* pInteger, long long defaultValue )
    {
        //is not NULL?
        if (pInteger)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pInteger->GetAccessMode() ))
            {
                return pInteger->GetMin();
            }
        }
        return defaultValue;
    }

    //tries to get the min valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::IFloat* pFloat, double defaultValue )
    {
        //is not NULL?
        if (pFloat)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pFloat->GetAccessMode() ))
            {
                return pFloat->GetMin();
            }
        }
        return defaultValue;
    }


//------------------------------------------------------------------------------
// GetMax node type pointer
//------------------------------------------------------------------------------

    //tries to get the max valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::IInteger* pInteger, long long defaultValue )
    {
        //is not NULL?
        if (pInteger)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pInteger->GetAccessMode() ))
            {
                return pInteger->GetMax();
            }
        }
        return defaultValue;
    }

    //tries to get the max valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::IFloat* pFloat, double defaultValue )
    {
        //is not NULL?
        if (pFloat)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pFloat->GetAccessMode() ))
            {
                return pFloat->GetMax();
            }
        }
        return defaultValue;
    }


//------------------------------------------------------------------------------
// GetInc node type pointer
//------------------------------------------------------------------------------

    //tries to get the inc valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::IInteger* pInteger, long long defaultValue )
    {
        //is not NULL?
        if (pInteger)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pInteger->GetAccessMode() ))
            {
                return pInteger->GetInc();
            }
        }
        return defaultValue;
    }


//------------------------------------------------------------------------------
// Basic get node type pointer
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline bool GetValue( GENAPI_NAMESPACE::IBoolean* pBoolean, bool defaultValue )
    {
        //is not NULL?
        if (pBoolean)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pBoolean->GetAccessMode() ))
            {
                return pBoolean->GetValue();
            }
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::IInteger* pInteger, long long defaultValue )
    {
        //is not NULL?
        if (pInteger)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pInteger->GetAccessMode() ))
            {
                return pInteger->GetValue();
            }
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::IEnumeration* pEnumeration, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        //is not NULL?
        if (pEnumeration)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pEnumeration->GetAccessMode() ))
            {
                return pEnumeration->ToString();
            }
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::IFloat* pFloat, double defaultValue )
    {
        //is not NULL?
        if (pFloat)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pFloat->GetAccessMode() ))
            {
                return pFloat->GetValue();
            }
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::IString* pString, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        //is not NULL?
        if (pString)
        {
            //is readable?
            if (GENAPI_NAMESPACE::IsReadable( pString->GetAccessMode() ))
            {
                return pString->GetValue();
            }
        }
        return defaultValue;
    }



//------------------------------------------------------------------------------
// Basic set node type reference
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IBoolean& nodeType, bool valueToSet )
    {
        return SetValue( &nodeType, valueToSet );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IInteger& nodeType, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &nodeType, valueToSet, valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IEnumeration& nodeType, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        return SetValue( &nodeType, valueToSet );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IFloat& nodeType, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &nodeType, valueToSet, valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::IString& nodeType, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        return SetValue( &nodeType, valueToSet );
    }



//------------------------------------------------------------------------------
// GetMin node type reference
//------------------------------------------------------------------------------

    //tries to get the min valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::IInteger& nodeType, long long defaultValue )
    {
        return GetMin( &nodeType, defaultValue );
    }

    //tries to get the min valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::IFloat& nodeType, double defaultValue )
    {
        return GetMin( &nodeType, defaultValue );
    }


//------------------------------------------------------------------------------
// GetMax node type reference
//------------------------------------------------------------------------------

    //tries to get the max valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::IInteger& nodeType, long long defaultValue )
    {
        return GetMax( &nodeType, defaultValue );
    }

    //tries to get the max valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::IFloat& nodeType, double defaultValue )
    {
        return GetMax( &nodeType, defaultValue );
    }


//------------------------------------------------------------------------------
// GetInc node type reference
//------------------------------------------------------------------------------

    //tries to get the inc valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::IInteger& nodeType, long long defaultValue )
    {
        return GetInc( &nodeType, defaultValue );
    }


//------------------------------------------------------------------------------
// Basic get node type reference
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline bool GetValue( GENAPI_NAMESPACE::IBoolean& nodeType, bool defaultValue )
    {
        return GetValue( &nodeType, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::IInteger& nodeType, long long defaultValue )
    {
        return GetValue( &nodeType, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::IEnumeration& nodeType, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        return GetValue( &nodeType, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::IFloat& nodeType, double defaultValue )
    {
        return GetValue( &nodeType, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::IString& nodeType, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        return GetValue( &nodeType, defaultValue );
    }


//------------------------------------------------------------------------------
// Basic set GENAPI_NAMESPACE::INode*
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, bool valueToSet )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IBoolean* pBoolean = dynamic_cast<GENAPI_NAMESPACE::IBoolean*>(pNode);
            return SetValue( pBoolean, valueToSet );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IInteger* pInteger = dynamic_cast<GENAPI_NAMESPACE::IInteger*>(pNode);
            return SetValue( pInteger, valueToSet, valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IEnumeration* pEnumeration = dynamic_cast<GENAPI_NAMESPACE::IEnumeration*>(pNode);
            if (pEnumeration)
            {
                return SetValue( pEnumeration, valueToSet );
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
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IFloat* pFloat = dynamic_cast<GENAPI_NAMESPACE::IFloat*>(pNode);
            return SetValue( pFloat, valueToSet, valueCorrection );
        }
        return false;
    }



//------------------------------------------------------------------------------
// GetMin GENAPI_NAMESPACE::INode*
//------------------------------------------------------------------------------

    //tries to get the min valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, long long defaultValue )
    {
        GENAPI_NAMESPACE::IInteger* pInteger = dynamic_cast<GENAPI_NAMESPACE::IInteger*>(pNode);
        return GetMin( pInteger, defaultValue );
    }

    //tries to get the min valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INode* pNode, double defaultValue )
    {
        GENAPI_NAMESPACE::IFloat* pFloat = dynamic_cast<GENAPI_NAMESPACE::IFloat*>(pNode);
        return GetMin( pFloat, defaultValue );
    }


//------------------------------------------------------------------------------
// GetMax GENAPI_NAMESPACE::INode*
//------------------------------------------------------------------------------

    //tries to get the max valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, long long defaultValue )
    {
        GENAPI_NAMESPACE::IInteger* pInteger = dynamic_cast<GENAPI_NAMESPACE::IInteger*>(pNode);
        return GetMax( pInteger, defaultValue );
    }

    //tries to get the max valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INode* pNode, double defaultValue )
    {
        GENAPI_NAMESPACE::IFloat* pFloat = dynamic_cast<GENAPI_NAMESPACE::IFloat*>(pNode);
        return GetMax( pFloat, defaultValue );
    }


//------------------------------------------------------------------------------
// GetInc GENAPI_NAMESPACE::INode*
//------------------------------------------------------------------------------

    //tries to get the inc valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, long long defaultValue )
    {
        GENAPI_NAMESPACE::IInteger* pInteger = dynamic_cast<GENAPI_NAMESPACE::IInteger*>(pNode);
        return GetInc( pInteger, defaultValue );
    }


//------------------------------------------------------------------------------
// Basic get GENAPI_NAMESPACE::INode*
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline bool GetValue( GENAPI_NAMESPACE::INode* pNode, bool defaultValue )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IBoolean* pBoolean = dynamic_cast<GENAPI_NAMESPACE::IBoolean*>(pNode);
            return GetValue( pBoolean, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, long long defaultValue )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IInteger* pInteger = dynamic_cast<GENAPI_NAMESPACE::IInteger*>(pNode);
            return GetValue( pInteger, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INode* pNode, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IEnumeration* pEnumeration = dynamic_cast<GENAPI_NAMESPACE::IEnumeration*>(pNode);
            if (pEnumeration)
            {
                return GetValue( pEnumeration, defaultValue );
            }
            else
            {
                //is alternative node type?
                GENAPI_NAMESPACE::IString* pString = dynamic_cast<GENAPI_NAMESPACE::IString*>(pNode);
                return GetValue( pString, defaultValue );
            }
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INode* pNode, double defaultValue )
    {
        //is not NULL?
        if (pNode)
        {
            GENAPI_NAMESPACE::IFloat* pFloat = dynamic_cast<GENAPI_NAMESPACE::IFloat*>(pNode);
            return GetValue( pFloat, defaultValue );
        }
        return defaultValue;
    }


//------------------------------------------------------------------------------
// Basic set GENAPI_NAMESPACE::INode* variants
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, unsigned char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, unsigned int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, unsigned long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, unsigned long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, const char* valueToSet )
    {
        return SetValue( pNode, static_cast<GENICAM_NAMESPACE::gcstring>(valueToSet) );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode* pNode, float valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( pNode, static_cast<double>(valueToSet), valueCorrection );
    }



//------------------------------------------------------------------------------
// GetMin GENAPI_NAMESPACE::INode* variants
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, char defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, unsigned char defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, int defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, unsigned int defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, long defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, unsigned long defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode* pNode, unsigned long long defaultValue )
    {
        return GetMin( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INode* pNode, float defaultValue )
    {
        return GetMin( pNode, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// GetMax GENAPI_NAMESPACE::INode* variants
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, char defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, unsigned char defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, int defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, unsigned int defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, long defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, unsigned long defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode* pNode, unsigned long long defaultValue )
    {
        return GetMax( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INode* pNode, float defaultValue )
    {
        return GetMax( pNode, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// GetInc GENAPI_NAMESPACE::INode* variants
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, char defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, unsigned char defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, int defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, unsigned int defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, long defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, unsigned long defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode* pNode, unsigned long long defaultValue )
    {
        return GetInc( pNode, static_cast<long long>(defaultValue) );
    }


//------------------------------------------------------------------------------
// Basic get GENAPI_NAMESPACE::INode* variants
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, char defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, unsigned char defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, int defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, unsigned int defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, long defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, unsigned long defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode* pNode, unsigned long long defaultValue )
    {
        return GetValue( pNode, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INode* pNode, const char* defaultValue )
    {
        return GetValue( pNode, static_cast<GENICAM_NAMESPACE::gcstring>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INode* pNode, float defaultValue )
    {
        return GetValue( pNode, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// Basic set GENAPI_NAMESPACE::INode&
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, bool valueToSet )
    {
        return SetValue( &node, valueToSet );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, valueToSet, valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        return SetValue( &node, valueToSet );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, valueToSet, valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, unsigned char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, unsigned int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, unsigned long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, unsigned long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, const char* valueToSet )
    {
        return SetValue( &node, static_cast<GENICAM_NAMESPACE::gcstring>(valueToSet) );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INode& node, float valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &node, static_cast<double>(valueToSet), valueCorrection );
    }



//------------------------------------------------------------------------------
// GetMin GENAPI_NAMESPACE::INode&
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, long long defaultValue )
    {
        return GetMin( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INode& node, double defaultValue )
    {
        return GetMin( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, char defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, unsigned char defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, int defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, unsigned int defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, long defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, unsigned long defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INode& node, unsigned long long defaultValue )
    {
        return GetMin( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INode& node, float defaultValue )
    {
        return GetMin( &node, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// GetMax GENAPI_NAMESPACE::INode&
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, long long defaultValue )
    {
        return GetMax( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INode& node, double defaultValue )
    {
        return GetMax( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, char defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, unsigned char defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, int defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, unsigned int defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, long defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, unsigned long defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INode& node, unsigned long long defaultValue )
    {
        return GetMax( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INode& node, float defaultValue )
    {
        return GetMax( &node, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// GetInc GENAPI_NAMESPACE::INode&
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, long long defaultValue )
    {
        return GetInc( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, char defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, unsigned char defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, int defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, unsigned int defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, long defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, unsigned long defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INode& node, unsigned long long defaultValue )
    {
        return GetInc( &node, static_cast<long long>(defaultValue) );
    }


//------------------------------------------------------------------------------
// Basic get GENAPI_NAMESPACE::INode&
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline bool GetValue( GENAPI_NAMESPACE::INode& node, bool defaultValue )
    {
        return GetValue( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, long long defaultValue )
    {
        return GetValue( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INode& node, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        return GetValue( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INode& node, double defaultValue )
    {
        return GetValue( &node, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, char defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, unsigned char defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, int defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, unsigned int defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, long defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, unsigned long defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INode& node, unsigned long long defaultValue )
    {
        return GetValue( &node, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INode& node, const char* defaultValue )
    {
        return GetValue( &node, static_cast<GENICAM_NAMESPACE::gcstring>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INode& node, float defaultValue )
    {
        return GetValue( &node, static_cast<double>(defaultValue) );
    }



//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type bool
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, bool valueToSet )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), valueToSet );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, bool valueToSet )
    {
        return SetValue( &pNodeMap, nodeName, valueToSet );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, bool valueToSet )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, valueToSet );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, bool valueToSet )
    {
        return SetValue( &object, nodeName, valueToSet );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type long long
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), valueToSet, valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, valueToSet, valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, valueToSet, valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, valueToSet, valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type const GENICAM_NAMESPACE::gcstring&
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), valueToSet );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        return SetValue( &pNodeMap, nodeName, valueToSet );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, valueToSet );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& valueToSet )
    {
        return SetValue( &object, nodeName, valueToSet );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type double
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), valueToSet, valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, valueToSet, valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, valueToSet, valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, double valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, valueToSet, valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type char
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type unsigned char
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type int
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type unsigned int
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type long
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type unsigned long
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type unsigned long long
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<long long>(valueToSet), valueCorrection );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type const char*
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const char* valueToSet )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<GENICAM_NAMESPACE::gcstring>(valueToSet) );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const char* valueToSet )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<GENICAM_NAMESPACE::gcstring>(valueToSet) );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, const char* valueToSet )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<GENICAM_NAMESPACE::gcstring>(valueToSet) );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, const char* valueToSet )
    {
        return SetValue( &object, nodeName, static_cast<GENICAM_NAMESPACE::gcstring>(valueToSet) );
    }

//------------------------------------------------------------------------------
// Set for INodeMap and Objects providing GetNodeMap() with type float
//------------------------------------------------------------------------------

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pNodeMap)
        {
            return SetValue( pNodeMap->GetNode( nodeName ), static_cast<double>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    inline bool SetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &pNodeMap, nodeName, static_cast<double>(valueToSet), valueCorrection );
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, float valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        if (pObject)
        {
            return SetValue( pObject->GetNodeMap(), nodeName, static_cast<double>(valueToSet), valueCorrection );
        }
        return false;
    }

    //tries to set the valueToSet, node type is resolved by valueToSet type, returns true if valueToSet has been set
    template <typename T>
    inline bool SetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, float valueToSet, EValueCorrection valueCorrection = ValueCorrection_ToNearestValue )
    {
        return SetValue( &object, nodeName, static_cast<double>(valueToSet), valueCorrection );
    }



//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetMin( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type double
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        return GetMin( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type unsigned char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type unsigned int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type unsigned long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type unsigned long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMin for INodeMap and Objects providing GetNodeMap() with type float
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        if (pNodeMap)
        {
            return GetMin( pNodeMap->GetNode( nodeName ), static_cast<double>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMin( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        return GetMin( &pNodeMap, nodeName, static_cast<double>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMin( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        if (pObject)
        {
            return GetMin( pObject->GetNodeMap(), nodeName, static_cast<double>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMin( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        return GetMin( &object, nodeName, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetMax( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type double
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        return GetMax( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type unsigned char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type unsigned int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type unsigned long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type unsigned long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetMax for INodeMap and Objects providing GetNodeMap() with type float
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        if (pNodeMap)
        {
            return GetMax( pNodeMap->GetNode( nodeName ), static_cast<double>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetMax( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        return GetMax( &pNodeMap, nodeName, static_cast<double>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMax( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        if (pObject)
        {
            return GetMax( pObject->GetNodeMap(), nodeName, static_cast<double>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetMax( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        return GetMax( &object, nodeName, static_cast<double>(defaultValue) );
    }


//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetInc( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type unsigned char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type unsigned int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type unsigned long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// GetInc for INodeMap and Objects providing GetNodeMap() with type unsigned long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetInc( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetInc( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetInc( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pObject)
        {
            return GetInc( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetInc( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetInc( &object, nodeName, static_cast<long long>(defaultValue) );
    }


//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type bool
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline bool GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, bool defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline bool GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, bool defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline bool GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, bool defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline bool GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, bool defaultValue )
    {
        return GetValue( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long long defaultValue )
    {
        return GetValue( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type const GENICAM_NAMESPACE::gcstring&
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline GENICAM_NAMESPACE::gcstring GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline GENICAM_NAMESPACE::gcstring GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, const GENICAM_NAMESPACE::gcstring& defaultValue )
    {
        return GetValue( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type double
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, defaultValue );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, defaultValue );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, double defaultValue )
    {
        return GetValue( &object, nodeName, defaultValue );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, char defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type unsigned char
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned char defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, int defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type unsigned int
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned int defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, long defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type unsigned long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type unsigned long long
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline int64_t GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<long long>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<long long>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline int64_t GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, unsigned long long defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<long long>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type const char*
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const char* defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<GENICAM_NAMESPACE::gcstring>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline GENICAM_NAMESPACE::gcstring GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, const char* defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<GENICAM_NAMESPACE::gcstring>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline GENICAM_NAMESPACE::gcstring GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, const char* defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<GENICAM_NAMESPACE::gcstring>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline GENICAM_NAMESPACE::gcstring GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, const char* defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<GENICAM_NAMESPACE::gcstring>(defaultValue) );
    }

//------------------------------------------------------------------------------
// Get for INodeMap and Objects providing GetNodeMap() with type float
//------------------------------------------------------------------------------

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INodeMap* pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        if (pNodeMap)
        {
            return GetValue( pNodeMap->GetNode( nodeName ), static_cast<double>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    inline double GetValue( GENAPI_NAMESPACE::INodeMap& pNodeMap, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        return GetValue( &pNodeMap, nodeName, static_cast<double>(defaultValue) );
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetValue( T* pObject, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        if (pObject)
        {
            return GetValue( pObject->GetNodeMap(), nodeName, static_cast<double>(defaultValue) );
        }
        return defaultValue;
    }

    //tries to get the valueToSet, node type is resolved by default valueToSet type
    template <typename T>
    inline double GetValue( T& object, const GENICAM_NAMESPACE::gcstring& nodeName, float defaultValue )
    {
        return GetValue( &object, nodeName, static_cast<double>(defaultValue) );
    }

}
#endif /* INCLUDED_GTL_H_4828242 */
