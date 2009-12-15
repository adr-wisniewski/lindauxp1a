/* 
 * File:   CommandPipe.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 10:50
 */

#ifndef _COMMANDPIPE_H
#define	_COMMANDPIPE_H

#include <Pipe.h>
#include "Command.h"

namespace Linda
{
   namespace Test
   {

        class CommandPipe : public Linda::Pipe
        {
        public:
            CommandPipe();
            CommandPipe(int readDescriptor, int writeDescriptor);
            
            int Write(Command *c);
            Command* Read();

        private:

        };
   }

}

#endif	/* _COMMANDPIPE_H */

