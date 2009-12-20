/* 
 * File:   Pipe_impl.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 18:08
 */

#ifndef _PIPE_IMPL_H
#define	_PIPE_IMPL_H

#include <limits.h>
#include <sstream>
#include <boost/format.hpp>

#include "Exception.h"

namespace Linda
{
    template<class TProduct>
    Pipe<TProduct>::Pipe()
        : PipeBase()
    {
        // empty
    }

    template<class TProduct>
    Pipe<TProduct>::Pipe(int readDescriptor, int writeDescriptor)
        : PipeBase(readDescriptor, writeDescriptor)
    {
        // empty
    }

    template<class TProduct>
    void Pipe<TProduct>::Write(const TProduct &p)
    {
        int size;

        // create buffer 
        std::stringstream stream(std::stringstream::binary | std::stringstream::in);
        stream.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);

        // allocate space for size header
        stream << size;

        // serialize
        p.Serialize(static_cast<std::ostream&>(stream));

        // check size
        if(static_cast<int>(stream.tellg()) > PIPE_BUF)
            throw Exception(boost::format("Message too big: %1%B") % size);

        // stamp with size
        size = static_cast<int>(stream.tellg()) - sizeof(int);
        stream.seekg(0, std::ios::beg);
        stream << size;

        // get data and send it through pipe
        std::string data = stream.str();
        PipeBase::Write(data.c_str(), data.length());
    }

    template<class TProduct>
    TProduct* Pipe<TProduct>::Read()
    {
        int size;
        char* buffer;

        // create buffer and read message contents
        PipeBase::Read(reinterpret_cast<char*>(&size), sizeof(int));

        buffer = new char[size];
        PipeBase::Read(buffer, size);

        // move data into stream
        std::stringstream stream(std::string(buffer, size), 
                std::stringstream::binary | std::stringstream::out);

        stream.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
        
        delete buffer;

        // unserialize object
        return Serializable<TProduct>::Unserialize(static_cast<std::istream&>(stream));
    }

}

#endif	/* _PIPE_IMPL_H */

