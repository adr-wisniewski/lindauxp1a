/* 
 * File:   CommandVisitor.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 14:04
 */

#ifndef _PROCESSORCOMMAND_H
#define	_PROCESSORCOMMAND_H

#include "CommandCreate.h"
#include "CommandKill.h"
#include "CommandStat.h"
#include "CommandOutput.h"
#include "CommandInput.h"
#include "CommandRead.h"

namespace Linda
{
    namespace Test
    {
        class ProcessorCommand
        {
        public:
            virtual void Process(CommandCreate &c)    = 0;
            virtual void Process(CommandKill &c)      = 0;
            virtual void Process(CommandStat &c)      = 0;
            virtual void Process(CommandOutput &c)    = 0;
            virtual void Process(CommandInput &c)     = 0;
            virtual void Process(CommandRead &c)      = 0;

        };
    }
}

#endif	/* _PROCESSORCOMMAND_H */

