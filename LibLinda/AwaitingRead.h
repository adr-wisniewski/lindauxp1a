/* 
 * File:   AwaitingRead.h
 * Author: adrian
 *
 * Created on 5 styczeń 2010, 00:07
 */

#ifndef _AWAITINGREAD_H
#define	_AWAITINGREAD_H

#include "Query.h"

namespace Linda
{

    struct AwaitingRead
    {
        int     workerId;
        bool    isRemoving;
        Query   query;
    };

}

#endif	/* _AWAITINGREAD_H */

