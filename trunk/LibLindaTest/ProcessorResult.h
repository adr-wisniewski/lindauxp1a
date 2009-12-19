/* 
 * File:   ResultVisitor.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:26
 */

#ifndef _PROCESSORRESULT_H
#define	_PROCESSORRESULT_H

#include "ResultBasic.h"
#include "ResultStat.h"

namespace Linda
{
    namespace Test
    {
        class ProcessorResult
        {
        public:
            virtual void Process(ResultBasic &c)    = 0;
            virtual void Process(ResultStat &c)     = 0;

        };
    }
}

#endif	/* _PROCESSORRESULT_H */

