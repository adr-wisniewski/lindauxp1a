/* 
 * File:   StatResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:28
 */

#ifndef _STATRESULT_H
#define	_STATRESULT_H

#include "ResultMessage.h"
#include <UnserializableMessage.h>

namespace Linda
{
    namespace Test
    {
        static const int StatResultCode = 1;

        class StatResult :
            public ResultMessage,
            private UnserializableMessage<StatResult, ResultMessage, StatResultCode>
        {

        };
    }
}

#endif	/* _STATRESULT_H */

