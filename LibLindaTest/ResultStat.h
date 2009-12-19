/* 
 * File:   StatResult.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 20:28
 */

#ifndef _RESULTSTAT_H
#define	_RESULTSTAT_H

#include "MessageResult.h"
#include <MessageUnserializable.h>

namespace Linda
{
    namespace Test
    {

        class StatResult;

        typedef MessageUnserializable<StatResult, Message<Result_tag>, 2>
            UnserializableStatResult;

        class StatResult :
            public MessageResult,
            private UnserializableStatResult
        {
        public:
            virtual void DoSerialize(std::ostream &stream);
            virtual Message* DoUnserialize(std::istream &stream);

            virtual int GetCode() const;
            virtual void Process(ProcessorCommand *processor);
        };
    }
}

#endif	/* _RESULTSTAT_H */

