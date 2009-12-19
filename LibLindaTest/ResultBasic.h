/* 
 * File:   ResultBasic.h
 * Author: adrian
 *
 * Created on 19 grudzień 2009, 19:12
 */

#ifndef _RESULTBASIC_H
#define	_RESULTBASIC_H

#include "MessageResult.h"
#include <MessageUnserializable.h>

namespace Linda
{
    namespace Test
    {
        class ResultBasic;

        typedef MessageUnserializable<ResultBasic, MessageResult, 1>
            UnserializableResultBasic;

        class ResultBasic :
            public MessageResult,
            private UnserializableResultBasic
        {
        public:
            ResultBasic();
            ResultBasic(int ordinal, bool status);
            
            virtual int GetCode() const;
            virtual void Process(ProcessorResult *processor);
        };
    }
}


#endif	/* _RESULTBASIC_H */

