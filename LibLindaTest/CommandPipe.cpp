/* 
 * File:   CommandPipe.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 10:50
 */

#include "CommandPipe.h"

namespace Linda
{

namespace Test
{

   CommandPipe::CommandPipe() : Linda::Pipe()
   {

   }

   CommandPipe::CommandPipe(int readDescriptor, int writeDescriptor)
    : Linda::Pipe(readDescriptor, writeDescriptor)
   {

   }

   int CommandPipe::Write(Command *c)
   {
       int size = c->GetSerializedSize();
       int code = c->GetCode();
       int len  = size + 2 * sizeof(int);

       char *buffer = new char[len];
       int *ibuffer = static_cast<int*>(buffer);
       
       ibuffer[0] = size;
       ibuffer[1] = code;

       c->Serialize(static_cast<void*>(&buffer[2*sizeof(int)]));

       // TODO: co z EINTR ?
       Pipe::Write(static_cast<void*>(buffer), len);

       delete [] buffer;
   }

    Command* CommandPipe::Read()
    {
        int header[2];

        // read command - end of file means empty command
        if(!Pipe::Read(static_cast<void*>(header), sizeof(header)))
            return static_cast<Command*>(0);

        // unserialize command
        return Command::Unserialize(header[0], header[1], this);
    }
}

}


