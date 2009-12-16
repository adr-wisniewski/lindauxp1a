/* 
 * File:   CommandVisitor.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 14:04
 */

#ifndef _COMMANDPROCESSOR_H
#define	_COMMANDPROCESSOR_H

#include "CreateCommand.h"
#include "KillCommand.h"
#include "StatCommand.h"
#include "OutputCommand.h"
#include "InputCommand.h"
#include "ReadCommand.h"

namespace Linda
{
    namespace Test
    {
        class CommandVisitor
        {
        public:
            virtual void Process(CreateCommand &c)    = 0;
            virtual void Process(KillCommand &c)      = 0;
            virtual void Process(StatCommand &c)      = 0;
            virtual void Process(OutputCommand &c)    = 0;
            virtual void Process(InputCommand &c)     = 0;
            virtual void Process(ReadCommand &c)      = 0;

        };
    }
}

#endif	/* _COMMANDPROCESSOR_H */

