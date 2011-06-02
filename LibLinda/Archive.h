/* 
 * File:   Archive.h
 * Author: adrian
 *
 * Created on 6 styczeń 2010, 11:22
 */

#ifndef _ARCHIVE_H
#define	_ARCHIVE_H

#include<sstream>
#include<string>
#include<unistd.h>

#include "Util.h"

namespace Linda
{

class Archive {
public:
    Archive();
    Archive(const std::string &data);

    std::string Get();

    Archive& operator<<(const std::string &value);
    Archive& operator>>(std::string &value);

    template<class TType>
    Archive& operator<<(TType value)
    {
        mBuffer.write(reinterpret_cast<char*>(&value), sizeof(TType));
        return *this;
    }

    template<class TType>
    Archive& operator>>(TType &value)
    {
        mBuffer.read(reinterpret_cast<char*>(&value), sizeof(TType));
        return *this;
    }

private:
    std::stringstream mBuffer;
};

}

#endif	/* _ARCHIVE_H */

