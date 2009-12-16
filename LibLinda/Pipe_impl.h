/* 
 * File:   Pipe_impl.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 18:08
 */

#ifndef _PIPE_IMPL_H
#define	_PIPE_IMPL_H

#include <sstream>

#include "PipeBase.h"

namespace Linda
{
    template<TProduct>
    Pipe<TProduct>::Pipe<TProduct>()
        : PipeBase()
    {
        // empty
    }

    template<TProduct>
    Pipe<TProduct>::Pipe<TProduct>(int readDescriptor, int writeDescriptor)
        : PipeBase(readDescriptor, writeDescriptor)
    {
        // empty
    }

    template<TProduct>
    void Pipe<TProduct>::Write(const TProduct &p)
    {
        int size;

        // create buffer and serialize object
        std::stringstream stream(std::stringstream::binary | std::stringstream::in);
        stream << size;                        // allocate space for size header
        p.Serialize(stream);

        // stamp with size
        size = stream.tellg() - sizeof(int);
        stream.seekg(0, std::ios::beg);
        stream << size;

        // get data and send it through pipe
        std::string data = stream.str();
        Pipe::Write(data.c_str(), data.length());
    }

    template<TProduct>
    TProduct* Pipe<TProduct>::Read()
    {
        int size;
        char buffer;

        // create buffer and read message contents
        Pipe::Read(static_cast<char*>(&size), sizeof(int));

        buffer = new char[size];
        Pipe::Read(buffer, size);

        // move data into stream
        std::stringstream stream(std::string(buffer, size), 
                std::stringstream::binary | std::stringstream::out);
        
        delete buffer;

        // unserialize object
        return TProduct::Unserialize(stream);
    }

}

#endif	/* _PIPE_IMPL_H */

