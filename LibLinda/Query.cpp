#include "Query.h"

namespace Linda
{
    /*virtual*/ bool Query::IsSatisfied(const Tuple &tuple)
    {
        // get list of values
        const Tuple::ValueList &values = tuple.Values();

        //check size
        if(values.size() != mValues.size())
            return false;

        // iterate
        Tuple::ValueList::const_iterator ti, te;
        Query::ValueList::const_iterator qi, qe;

        for(ti = values.begin(), te = values.end(),
                qi = mValues.begin(), qe = mValues.end();
                ti !=te && qi != qe;
                ++ti, ++qi)
        {
            if(!qi->IsSatisfied(*ti))
                return false;
        }

        // finally!
        return true;
    }

    QueryValue* new_clone( const QueryValue& q )
    {
        return q.clone();
    }
}