/* 
 * File:   ResultVisitor.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:26
 */

#ifndef _RESULTPROCESSOR_H
#define	_RESULTPROCESSOR_H

#include "ResultMessage.h"
#include "StatResult.h"

namespace Linda
{
    namespace Test
    {
        class ResultProcessor
        {
        public:
            virtual void Process(ResultMessage &c)      = 0;
            virtual void Process(StatResult &c)         = 0;

        };
    }
}

#endif	/* _RESULTPROCESSOR_H */

