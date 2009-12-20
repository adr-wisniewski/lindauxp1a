/* 
 * File:   ResultBasic.h
 * Author: adrian
 *
 * Created on 19 grudzień 2009, 19:12
 */

#ifndef _RESULTBASIC_H
#define	_RESULTBASIC_H

#include "MessageResult.h"

namespace Linda
{
    namespace Test
    {
        class ResultBasic :
            public MessageResult,
            RegisterSerializable<ResultBasic, MessageResult>
        {
        public:
            ResultBasic();
            ResultBasic(int ordinal, bool status);
            
            virtual void Process(ProcessorResult *processor);

        protected:
            virtual id_t Id() const;
        };
    }
}


#endif	/* _RESULTBASIC_H */

