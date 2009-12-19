/* 
 * File:   Exception.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 10:23
 */

#include "Exception.h"
#include <cstring>
#include <string>

namespace Linda
{

    Exception::Exception(const char* str)
    : std::runtime_error(std::string(str))
    {

    }
    
    Exception::Exception(const boost::format &format)
    : std::runtime_error(boost::str(format))
    {

    }

    Exception::Exception(int errno, const char *prefix)
    : runtime_error(boost::str(boost::format("%1%: %2%") % prefix % strerror(errno)))
    {

    }
}

