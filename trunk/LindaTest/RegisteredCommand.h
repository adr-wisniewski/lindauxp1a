/* 
 * File:   RegisteredCommand.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 14:33
 */

#ifndef _REGISTEREDCOMMAND_H
#define	_REGISTEREDCOMMAND_H

#include "Command.h"

namespace Linda
{
    namespace Test
    {
        /**
         * CRTP patter for automatic registering registering commands in factory
         */
        template<class TCommand>
        class RegisteredCommand
        {
            static bool IsRegistered;
            static Command* Create(int bufsize, void* buf);
        };
        
        template<class TCommand>
        bool RegisteredCommand<TCommand>::IsRegistered
            = Command::RegisterFactoryMethod(TCommand::smCode, RegisteredCommand<TCommand>::Create);

        template<class TCommand, int>
        static Command* RegisteredCommand<TCommand>::Create(int bufsize ,void* buf)
        {
            return TCommand::Create(bufsize, buf);
        }
    }
}

#endif	/* _REGISTEREDCOMMAND_H */

