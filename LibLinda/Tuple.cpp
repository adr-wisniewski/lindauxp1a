#include "Tuple.h"
#include "Exception.h"

namespace Linda
{

    Tuple::Value::Value(float value)
    : mType(TypeFloat), mFloatValue(value)
    {

    }

    Tuple::Value::Value(int value)
    : mType(TypeInt), mIntValue(value)
    {

    }

    Tuple::Value::Value(const std::string &value)
    : mType(TypeString), mStringValue(new std::string(value))
    {

    }

     Tuple::Value::~Value()
     {
         if(mType == TypeString)
             delete mStringValue;
     }

     Tuple::Value::Type Tuple::Value::GetType() const
     {
         return mType;
     }

     float Tuple::Value::ValueFloat() const
     {
         if(mType != TypeFloat)
             throw Linda::Exception("Tuple::Value::ValueFloat: invalid type");

         return mFloatValue;
     }

     int Tuple::Value::ValueInt() const
     {
         if(mType != TypeInt)
             throw Linda::Exception("Tuple::Value::ValueInt: invalid type");

         return mIntValue;
     }

     const std::string& Tuple::Value::ValueString() const
     {
         if(mType != TypeString)
             throw Linda::Exception("Tuple::Value::ValueString: invalid type");

         return *mStringValue;
     }


}
