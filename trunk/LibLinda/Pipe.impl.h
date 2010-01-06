/* 
 * File:   Pipe_impl.h
 * Author: adrian
 *
 * Created on 16 grudzień 2009, 18:08
 */

#ifndef _PIPE_IMPL_H
#define	_PIPE_IMPL_H

#include <sstream>
#include <unistd.h>
#include <boost/format.hpp>
#include <boost/scoped_array.hpp>

#include "Exception.h"
#include "Util.h"
#include "Archive.h"
#include <signal.h>

namespace Linda
{
    template<class TProduct>
    Pipe<TProduct>::Pipe()
        : PipeBase()
    {
        signal(SIGPIPE, SIG_IGN);
    }

    template<class TProduct>
    Pipe<TProduct>::Pipe(int readDescriptor, int writeDescriptor)
        : PipeBase(readDescriptor, writeDescriptor)
    {
        signal(SIGPIPE, SIG_IGN);
    }

    template<class TProduct>
    void Pipe<TProduct>::Write(const TProduct &p)
    {
        try
        {
            Archive stream;
            Archive wrapper;

            // serialize
            p.Serialize(stream);
            std::string data = stream.Get();

            // stamp with size  
            wrapper << data;

            // get data and send it through pipe
            std::string packet = wrapper.Get();
            PipeBase::Write(packet.c_str(), packet.length());
        }
        catch(std::stringstream::failure &e)
        {
            throw Exception(boost::format("Pipe<TProduct>::Write io exception: %1%") % e.what());
        }
    }

    template<class TProduct>
    std::auto_ptr<TProduct> Pipe<TProduct>::Read()
    {
        try
        {
            int size;

            // create buffer and read message contents
            if(!PipeBase::Read(reinterpret_cast<char*>(&size), sizeof(int)))
                return std::auto_ptr<TProduct>();

            boost::scoped_array<char> buffer(new char[size]);
            PipeBase::Read(buffer.get(), size);

            // move data into stream
            Archive stream(std::string(buffer.get(), size));

            // unserialize object
            return Serializable<TProduct>::Unserialize(stream);
        }
        catch(std::stringstream::failure &e)
        {
            throw Exception(boost::format("Pipe<TProduct>::Read io exception: %1%") % e.what());
        }
    }

}

#endif	/* _PIPE_IMPL_H */

