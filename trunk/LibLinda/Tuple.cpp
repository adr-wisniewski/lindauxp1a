#include "Tuple.h"

namespace Linda
{
    TupleValue* new_clone( const TupleValue& t )
    {
        return t.clone();
    }
}