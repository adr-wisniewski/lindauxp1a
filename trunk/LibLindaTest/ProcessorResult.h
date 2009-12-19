/* 
 * File:   ResultVisitor.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:26
 */

#ifndef _PROCESSORRESULT_H
#define	_PROCESSORRESULT_H

#include "MessageResult.h"
#include "StatResult.h"

namespace Linda
{
    namespace Test
    {
        class ProcessorResult
        {
        public:
            virtual void Process(MessageResult &c)      = 0;
            virtual void Process(StatResult &c)         = 0;

        };
    }
}

#endif	/* _PROCESSORRESULT_H */

