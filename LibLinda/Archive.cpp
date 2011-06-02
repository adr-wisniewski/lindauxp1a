/* 
 * File:   Archive.cpp
 * Author: adrian
 * 
 * Created on 6 styczeń 2010, 11:22
 */

#include "Archive.h"
#include <boost/scoped_array.hpp>

namespace Linda
{
    Archive::Archive()
    :mBuffer(std::ios_base::out | std::ios_base::binary)
    {
        mBuffer.exceptions ( std::stringstream::eofbit
        | std::stringstream::failbit
        | std::stringstream::badbit );
    }

    Archive::Archive(const std::string &data)
    :mBuffer(data,std::ios_base::in | std::ios_base::binary)
    {
        mBuffer.exceptions ( std::stringstream::eofbit
        | std::stringstream::failbit
        | std::stringstream::badbit );
    }

    std::string Archive::Get()
    {
        return mBuffer.str();
    }

    Archive& Archive::operator<<(const std::string &value)
    {
        int length = value.length();

        mBuffer.write(reinterpret_cast<char*>(&length), sizeof(size_t));
        mBuffer.write(value.c_str(), length);
        return *this;
    }

    Archive& Archive::operator>>(std::string &value)
    {
        int length;

        // read length
        mBuffer.read(reinterpret_cast<char*>(&length), sizeof(size_t));

        // read contents
        boost::scoped_array<char> buffer(new char[length]);
        mBuffer.read(buffer.get(), length);

        // put it into value
        value = std::string(buffer.get(), length);
        return *this;
    }
}


