/* 
 * File:   Linda.h
 * Author: adrian
 *
 * Created on 19 grudzień 2009, 11:27
 */

#ifndef _LINDA_H
#define	_LINDA_H


#include "Tuple.h"
#include "Query.h"
#include "MessageRequest.h"
#include "MessageResponse.h"
#include "Pipe.h"

namespace Linda
{
    /**
     * Intrface class for LibLinda Library
     */
    class Linda {
    public:
        Linda(int responseDescriptor, int requestDescriptor);

        bool Read(const Query &query, Tuple &tuple);
        bool Input(const Query &query, Tuple &tuple);
        bool Output(const Tuple &tuple);

    protected:
        bool HandleResponseInput(Tuple &tuple);
        bool HandleResponseOutput();

        PipeResponse mPipeResponse;
        PipeRequest mPipeRequest;
    };
}

#endif	/* _LINDA_H */

