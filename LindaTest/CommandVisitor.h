/* 
 * File:   CommandVisitor.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 14:04
 */

#ifndef _COMMANDVISITOR_H
#define	_COMMANDVISITOR_H

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
        class CommandVisitor
        {
        public:
            virtual void Visit(CommandCreate &c)    = 0;
            virtual void Visit(CommandKill &c)      = 0;
            virtual void Visit(CommandStat &c)      = 0;
            virtual void Visit(CommandOutput &c)    = 0;
            virtual void Visit(CommandInput &c)     = 0;
            virtual void Visit(CommandRead &c)      = 0;

        };
    }
}

#endif	/* _COMMANDVISITOR_H */

