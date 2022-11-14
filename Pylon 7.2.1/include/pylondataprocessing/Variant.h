//------------------------------------------------------------------------------
//  Basler Data Processing SDK
//  Copyright (c) 2021-2022 Basler AG
//  http://www.baslerweb.com
//  Author:  AG, BR
//------------------------------------------------------------------------------
/*!
 \file

 \brief
    Contains the variant class that can be used to represent any data type processed by a \c CRecipe.
*/

#pragma once
#include <pylon/stdinclude.h>
#include <pylon/PylonImage.h>

#include <pylondataprocessing/PylonDataProcessing.h>
#include <pylondataprocessing/VariantDataType.h>

#ifdef _MSC_VER
#pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

namespace Pylon
{
    namespace DataProcessing
    {
        /*!
         \brief
            A variant class that can be used to represent any data type processed by a \c CRecipe.

         \threading
            The \c CVariant class is not thread-safe.
        */
        class PYLONDATAPROCESSING_API CVariant
        {
        public:
            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_None.

             \post
                <ul>
                    <li>No data is held.</li>
                    <li>\c GetDataType() returns \c VariantDataType_None.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant();

            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_Boolean.

             \param[in] value The value to assign.

             \post
                <ul>
                    <li>The \c value passed is copied and held by the \c CVariant created.</li>
                    <li>\c GetDataType() returns \c VariantDataType_Boolean.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant(bool value);

            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_Int64.

             \param[in] value The value to assign.

             \post
                 <ul>
                     <li>The \c value passed is copied and held by the \c CVariant created.</li>
                     <li>\c GetDataType() returns \c VariantDataType_Int64.</li>
                 </ul>

             \error
                 Doesn't throw C++ exceptions.
            */
            CVariant(int64_t value);

            /*!
             \brief
                Creates a CVariant of type VariantDataType_UInt64.

             \param[in] value The value to assign.

             \post
                <ul>
                    <li>The \c value passed is copied and held by the \c CVariant created.</li>
                    <li>\c GetDataType() returns \c VariantDataType_UInt64.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant(uint64_t value);

            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_Float.

             \param[in] value The value to assign.

             \post
                 <ul>
                     <li>The \c value passed is copied and held by the \c CVariant created.</li>
                     <li>\c GetDataType() returns \c VariantDataType_Float.</li>
                 </ul>

             \error
                 Doesn't throw C++ exceptions.
            */
            CVariant(double value);

            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_String.

             \param[in] value The value to assign.

             \post
                <ul>
                    <li>The \c value passed is copied and held by the \c CVariant created.</li>
                    <li>\c GetDataType() returns \c VariantDataType_String.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant(const String_t& value);

            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_String.

             \param[in] value The value to assign.

             \post
                 <ul>
                    <li>The \c value passed is copied and held by the \c CVariant created.</li>
                    <li>\c GetDataType() returns \c VariantDataType_String.</li>
                 </ul>

             \error
                 Doesn't throw C++ exceptions.
            */
            CVariant(const char* value);

            /*!
             \brief
                Creates a \c CVariant array of type \c VariantDataType_String with \c VariantDataType_String as elements.

             \param[in] valueList The list of values to assign. Empty list is allowed.

             \post
                 <ul>
                    <li>The \c valueList passed is copied and held by the \c CVariant created .</li>
                    <li>\c GetDataType() returns \c VariantDataType_String.</li>
                    <li>\c IsArray() returns \c true.</li>
                 </ul>

             \error
                 Doesn't throw C++ exceptions.
            */
            CVariant(const StringList_t& valueList);

            /*!
             \brief
                Creates a \c CVariant of type \c VariantDataType_PylonImage.

             \param[in] value The value to assign.

             \post
                <ul>
                    <li>The \c value passed is shallow-copied (see \c CPylonImage copy constructor for more information) and held by the \c CVariant created.</li>
                    <li>\c GetDataType() returns \c VariantDataType_PylonImage.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant(const CPylonImage& value);

            /*!
             \brief
                Copies a variant.

             \param[in] other The variant to copy.

             \post
                <ul>
                    <li>The \c rhs variant passed is shallow-copied.</li>
                    <li>If the value of one of the two variant objects is changed, a copy of the variant object is created with copy-on-write and the value is assigned.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant(const CVariant& other);

            /*!
             \brief
                Move constructs a variant.

             \param[in] other The variant to move the content from.

             \post
                <ul>
                    <li>The content of the \c other variant passed will be moved to the new instance without any copy.</li>
                    <li>The \c other variant will be reset to its initial state afterwards.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant(CVariant&& other);

            /*!
             \brief
                Assign a variant.

             \param[in] rhs The \c CVariant to assign.

             \post
                <ul>
                    <li>The \c rhs variant passed is shallow-copied.</li>
                    <li>If the value of one of the two variant objects is changed, a copy of the variant object is created with copy-on-write and the value is assigned.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant& operator=(const CVariant& rhs);

            /*!
             \brief
                Move assigns a variant.

             \param[in] rhs The \c CVariant to move the content from.

             \post
                <ul>
                    <li>The content of the \c rhs variant passed will be moved to the new instance without any copy.</li>
                    <li>The \c rhs variant will be reset to its initial state afterwards.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant& operator=(CVariant&& rhs);

            /*!
             \brief
                Compares a variant object.

             \param[in] rhs The variant to compare to.

             \return
                \c true if the same data in variant objects is referenced.

             \error
                Doesn't throw C++ exceptions.
            */
            bool IsEqualInstance(const CVariant& rhs) const;

            /*!
             \brief
                Overloaded operator to compare a variant object.

             \param[in] rhs The variant to compare to.

             \return
                \c true if the same data in variant objects is referenced.
             */
            bool operator==(const CVariant& rhs) const;

            /*!
             \brief
                Returns a deep copy of the variant object.

            \return
                A deep copy of the variant object.

             \post
                <ul>
                    <li>The value the variant references to is copied.</li>
                    <li>If the current variant references a subvalue of a composite type, only the subtype of the composite type is copied.</li>
                    <li>The deep copy is held by the variant returned.</li>
                </ul>

             \error
                Doesn't throw C++ exceptions.
            */
            CVariant Copy() const;

            /*!
             \brief
                Destroys a variant object.

             \note
                Any C++ exception thrown internally while destroying the variant will be caught and ignored.

             \post
                 <ul>
                     <li>Any data held is released or deleted depending on the data type held.</li>
                 </ul>

             \error
                 Doesn't throw C++ exceptions.
            */
            virtual ~CVariant();

            /*!
             \brief
                Creates a variant using a known type name.

             This factory method is mainly used to create composite data types (\c VariantDataType_Composite) used as input data for a recipe.

             See the documentation of the vTools connected to input pins of the recipe for more information about composite data types and the correct type name in case composite data types
             are used.

             \param[in] typeName The name of the data type to create.

             \return
                A newly created variant of the type passed with \c typeName.

             \pre
                 <ul>
                     <li>\c CanCreateFromTypeName() returns \c true for \c typeName.</li>
                 </ul>

             \post
                 <ul>
                    <li>The data type is created.</li>
                    <li>The default value is assigned.</li>
                 </ul>

             \error
                 Throws an exception if the preconditions are not met.
            */
            static CVariant CreateFromTypeName(const String_t& typeName);

            /*!
             \brief
                Returns \c true if a variant with the type name passed can be created.

             \param[in] typeName The name of the data type to check.

             \return
                \c true if a variant with the type name passed can be created using \c CreateFromTypeName().

             \error
                Doesn't throw C++ exceptions.
            */
            static bool CanCreateFromTypeName(const String_t& typeName);

            /*!
             \brief
                Returns the data type of the variant.

             \return
                The data type of the data held.

             \error
                Doesn't throw C++ exceptions.
            */
            EVariantDataType GetDataType() const;

            /*!
             \brief
                Returns the number of subvalues.

             \return
                The number of subvalues. For example, returns 2 for a PointF{double X, double Y}.

             \error
                Doesn't throw C++ exceptions.
            */
            size_t GetNumSubValues() const;

            /*!
             \brief
                Returns the name of a subvalue of the value referenced by the variant.

             \note
                The position of a subvalue is not fixed and can change for different versions of pylon.

             \param[in] index The index.

             \return
                The name of a subvalue of the value referenced by the variant. For example, returns "x" for a PointF{double X, double Y} if 0 is passed as \c index. For example, returns "y" for a
                PointF{double X, double Y} if 1 is passed as \c index.

             \pre
                <ul>
                    <li>\c GetNumSubValues() returns a value larger than zero.</li>
                    <li>The \c index passed is smaller than the value returned by \c GetNumSubValues().</li>
                </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            String_t GetSubValueName(size_t index) const;

            /*!
             \brief
                Returns \c true if a sub alue of the value referenced by the variant with the name passed exists.

             \param[in] subValueName The name of the subvalue.

             \return
                \c true if a subvalue of the value referenced by the variant with the name passed exists. For example, returns \c true for a PointF{double X, double Y} if "x" is passed. For example,
                returns \c false for a PointF{double X, double Y} if "z" is passed.

             \error
                Doesn't throw C++ exceptions.
            */
            bool HasSubValue(const String_t& subValueName) const;

            /*!
             \brief
                Returns a variant object referencing the subvalue.

             \param[in] subValueName The name of the subvalue.

             \return
                A variant object referencing the subvalue with name \c subValueName.

             \pre
                <ul>
                   <li>A subvalue of the value referenced by the variant with the \c subValueName passed exists.</li>
                </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            CVariant GetSubValue(const String_t& subValueName) const;

            /*!
             \brief
                Changes the value of a subvalue of the value referenced by this variant.

             \param[in] subValueName    The name of the subvalue.
             \param[in] newValue        The new value for the subvalue.

             \pre
                <ul>
                    <li>A subvalue with the \c subValueName passed exists in the value referenced by the variant.</li>
                    <li>\c newValue must be compatible in type with the subvalue to change.</li>
                </ul>

             \post
                <ul>
                    <li>The subvalue has been changed to the new value.</li>
                </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            void SetSubValue(const String_t& subValueName, const CVariant& newValue);

            /*!
             \brief
                Returns the name of the type that can be used with \c CreateFromTypeName().

             \pre
                <ul>
                    <li>The data type of the variant must not be VariantDataType_None.</li>
                </ul>

             \return
                The name of the type, that can be used with \c CreateFromTypeName().

             \error
                Throws an exception if the preconditions are not met.
            */
            String_t GetTypeName() const;

            /*!
             \brief
                Returns the name of the value referenced by the variant.

             \param[in] pOptionalRootValueName  The name of the root value that can optionally be provided by the user. The name of root value depends on the context the variant is used in. For
                                                example, "lineStartPoint" can be used for a PointF{double X, double Y}.

             \return
                The name of the value referenced by the variant if it references a subvalue. \c pOptionalRootValueName or an empty string if it doesn't reference a subvalue. The name of the value with
                index in square brackets, e.g., \c line[2], referenced by the variant if it references an array item.

             \error
                Doesn't throw C++ exceptions.
            */
            String_t GetValueName(const char* pOptionalRootValueName = nullptr) const;

            /*!
             \brief
                Returns \c true if the value referenced is an array.

             \return
                \c true if the value referenced is an array.

             \error
                Doesn't throw C++ exceptions.
            */
            bool IsArray() const;

            /*!
             \brief
                Returns the number of values in an array.

             \return
                The number of values in an array. Returns 0 if the value is not an array.

             \error
                Doesn't throw C++ exceptions.
            */
            size_t GetNumArrayValues() const;

            /*!
             \brief
                Returns a variant object referencing the array item value.

             \param[in] index The index.

             \return
                A variant object referencing the array item value.

             \pre
                <ul>
                    <li>\c GetNumArrayValues() returns a value larger than zero.</li>
                    <li>The \c index passed is smaller than the value returned by \c GetNumArrayValues().</li>
                </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            CVariant GetArrayValue(size_t index) const;

            /*!
             \brief
                Changes the size of an array so that it contains \c size items.

            If \c size is smaller than the current array size, the array size is reduced to its first \c size elements, removing those beyond.

            If \c size is greater than the current array size, the array size is increased by inserting as many elements as needed at the end to reach a size of \c size.

            Inserted elements will be of type \c VariantDataType_None.

             \param[in] size The new size.

             \pre
                <ul>
                    <li>\c IsArray() returns \c true.</li>
                </ul>

             \post
                <ul>
                    <li>The array size has changed.</li>
                    <li>Any old values inside the array are preserved if the new \c size is greater or equal than the previous array size.</li>
                </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>Memory allocation fails.</li>
                </ul>
            */
            void ChangeArraySize(size_t size);

            /*!
             \brief
                Changes the value of an array item of the value referenced by this variant.

             \param[in] index       The index.
             \param[in] newValue    The new value for the array item.

             \pre
                 <ul>
                    <li>\c IsArray() returns \c true.</li>
                    <li>\c GetNumArrayValues() is greater than \c index.</li>
                    <li>The \c newValue must be compatible in type with the array item to change.</li>
                 </ul>

             \post
                 <ul>
                    <li>The entry in the array at the given index has been changed to the new value.</li>
                 </ul>

             \error
                 Throws an exception if the preconditions are not met.
            */
            void SetArrayItemValue(size_t index, const CVariant& newValue);

            /*!
                \brief
                Checks whether the value can be converted to target type.

                \param[in] targetType The target variant data type for conversion.

                \return
                \c true if the value can be converted to target type.

                \error
                Doesn't throw C++ exceptions.
            */
            bool CanConvert(EVariantDataType targetType);

            /*!
             \brief
                Converts value to target type.

             \c CanConvert() can be used to check whether this \c CVariant can be converted to \c targetType.

             \param[in] targetType The target variant data type for conversion.

             \return
                A variant object referencing the converted item value.

             \pre
                <ul>
                    <li>\c CanConvert() returns \c true.</li>
                </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            CVariant Convert(EVariantDataType targetType);

            /*!
             \brief
                Returns the value of the variant for a basic type as bool.

             \note
                Conversions exist for \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, and \c VariantDataType_String.
                Can be checked with \c CanConvert(VariantDataType_Boolean).

             \return
                The value of the variant as \c bool.

             \pre
                 <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                    <li>\c CanConvert(VariantDataType_Boolean) returns \c true.</li>
                 </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            bool ToBool() const;

            /*!
             \brief
                Returns the value of the variant for a basic type as int64_t.

             \note
                The value is undefined if a conversion exceeds the range of the target value.

                Conversions exist for \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, and \c VariantDataType_String.
                Can be checked with \c CanConvert(VariantDataType_Int64).

             \return
                Returns the value of the variant as int64_t.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                    <li>\c CanConvert(VariantDataType_Int64) returns \c true.</li>
                </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            int64_t ToInt64() const;

            /*!
             \brief
                Returns the value of the variant for a basic type as uint64_t.

             \note
                The value is undefined if a conversion exceeds the range of the target value.

                Conversions exist for \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or \c VariantDataType_String.
                Can be checked with \c CanConvert(VariantDataType_UInt64).

             \return
                Returns the value of the variant as uint64_t.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                    <li>\c CanConvert(VariantDataType_UInt64) returns \c true.</li>
                </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            uint64_t ToUInt64() const;

            /*!
             \brief
                Returns the value of the variant for a basic type as double.

             \note
                Conversions exist for \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or \c VariantDataType_String.
                Can be checked with \c CanConvert(VariantDataType_Float).

             \return
                Returns the value of the variant as double.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                    <li>\c CanConvert(VariantDataType_Float) returns \c true.</li>
                </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            double ToDouble() const;

            /*!
             \brief
                Returns the value of the variant for a basic type as string.

             \note
                The string conversion always uses a dot for decimals.

                Conversions exist for \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or \c VariantDataType_String.
                Can be checked with \c CanConvert(VariantDataType_String).

             \return
                Returns the value of the variant as string.

             \pre
                 <ul>
                   <li>\c IsArray() returns \c false.</li>
                   <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float,
                   \c VariantDataType_String or \c VariantDataType_Composite</li>
                   <li>\c CanConvert(VariantDataType_String) returns \c true.</li>
                </ul>

            \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            String_t ToString() const;

            /*!
             \brief
                Returns the value of the variant for a basic type as CPylonImage.

             \return
                Returns the value of the variant as CPylonImage.

             \pre
                 <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_PylonImage.</li>
                    <li>\c CanConvert(VariantDataType_PylonImage) returns \c true.</li>
                 </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            CPylonImage ToImage() const;

            /*!
             \brief
                Changes the value referenced by the variant.

             \param[in] newValue The new value for the referenced value.

             \pre
                 <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                 </ul>

             \post
                 <ul>
                    <li>The referenced value has been changed to the value of \c newValue.</li>
                    <li>The data type returned by \c GetDataType() has not changed.</li>
                 </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            void FromBool(bool newValue);

            /*!
             \brief
                Changes the value referenced by the variant.

             \param[in] newValue The new value for the referenced value.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The variant data type is able to represent the value.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                </ul>

             \post
                 <ul>
                    <li>The referenced value has been changed to the value of \c newValue.</li>
                    <li>The data type returned by \c GetDataType() has not changed.</li>
                 </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            void FromInt64(int64_t newValue);

            /*!
             \brief
                Changes the value referenced by the variant.

             \param[in] newValue The new value for the referenced value.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The variant data type is able to represent the value.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                </ul>

             \post
                 <ul>
                    <li>The referenced value has been changed to the value of \c newValue.</li>
                    <li>The data type returned by \c GetDataType() has not changed.</li>
                 </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            void FromUInt64(uint64_t newValue);

            /*!
             \brief
                Changes the value referenced by the variant.

             \param[in] newValue The new value for the referenced value.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The variant data type is able to represent the value.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                </ul>

            \attention
                If data type is an integer data type, the value is NOT rounded in a mathematical way. It is truncated equivalent to static_cast<int64_t>.

             \post
                 <ul>
                    <li>The referenced value has been changed to the value of \c newValue.</li>
                    <li>The data type returned by \c GetDataType() has not changed.</li>
                 </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            void FromDouble(double newValue);

            /*!
             \brief
                Changes the value referenced by the variant.

             \note
                This method will fail if the content of \c newValue is not convertible to the type of this \c CVariant.

             \param[in] newValue The new value for the referenced value.

             \pre
                <ul>
                    <li>\c IsArray() returns \c false.</li>
                    <li>The variant data type is able to represent the value.</li>
                    <li>The type of this \c CVariant is \c VariantDataType_Boolean, \c VariantDataType_Int64, \c VariantDataType_UInt64, \c VariantDataType_Float, or
                        \c VariantDataType_String.</li>
                </ul>

             \post
                <ul>
                   <li>The referenced value has been changed to the value of \c newValue if the conversion succeeded.</li>
                   <li>The data type returned by \c GetDataType() has not changed.</li>
                </ul>

             \error
                Throws an exception if:
                <ul>
                    <li>The preconditions are not met.</li>
                    <li>The conversion fails.</li>
                </ul>
            */
            void FromString(const String_t& newValue);

            /*!
             \brief
                Changes the value referenced by the variant.

             \param[in] newValue The new value for the referenced value.

             \pre
                <ul>
                    <li>\c newValue must be a valid image.</li>
                   <li>\c IsArray() returns \c false.</li>
                   <li>The type of this \c CVariant is \c VariantDataType_PylonImage.</li>
                </ul>

             \post
                <ul>
                   <li>The referenced value has been changed to the value of \c newValue.</li>
                   <li>The data type returned by \c GetDataType() has not changed.</li>
                </ul>

             \error
                Throws an exception if the preconditions are not met.
            */
            void FromImage(const CPylonImage& newValue);

            /*!
             \brief
                Use this method to get the error description of the value.

             \param[in] checkSubValues Optionally, also check the subvalues.

             \return
                Error description if the value is in error state, an empty string otherwise.

             \error
                Doesn't throw C++ exceptions.
            */
            String_t GetErrorDescription(bool checkSubValues = true) const;

            /*!
             \brief
                Use this method to check the error state of the value.

             \param[in] checkSubValues Optionally, check also the subvalues.

             \return
                \c true if the value is in error state.

             \error
                Doesn't throw C++ exceptions.
            */
            bool HasError(bool checkSubValues = true) const;

        protected:
            struct VariantImpl;
            VariantImpl* m_pImpl;
        };
    }
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
