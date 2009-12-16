/* 
 * File:   OutputRequest.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 17:07
 */

#ifndef _OUTPUTREQUEST_H
#define	_OUTPUTREQUEST_H

#include "RequestMessage.h"
#include "Tuple.h"

namespace Linda
{
    class OutputRequest : public RequestMessage
    {

    protected:
        Tuple mTuple;
    };
}

#endif	/* _OUTPUTREQUEST_H */

