//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2021 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------

#if !defined(PROPERTY_IMPL_H)
#define PROPERTY_IMPL_H


#define PROPERTY_GETTER_IMPL(Name, Class) \
    String_t Class::Get##Name() const  \
    { \
        String_t value; \
        if ( ! GetPropertyValue( Key::Name##Key, value) )  \
          value = CInfoBase::PropertyNotAvailable; \
        return value; \
    }

#define PROPERTY_SETTER_IMPL(Name, Class) \
        Class& Class::Set##Name( const String_t& v) \
        { \
            SetPropertyValue(Key::Name##Key, v ); \
            return *this; \
        }

#define PROPERTY_AVAILABLE_IMPL(Name, Class, Available) \
        bool Class::Is##Name##Available() const\
        { \
            return GetPropertyAvailable( Key::Name##Key); \
        }

#define PROPERTY_IMPL(Name, Class) \
    PROPERTY_GETTER_IMPL(Name, Class)  \
    PROPERTY_SETTER_IMPL(Name, Class) \
    PROPERTY_AVAILABLE_IMPL(Name, Class, Available)
#endif
