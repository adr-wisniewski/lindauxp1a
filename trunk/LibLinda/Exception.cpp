/* 
 * File:   Exception.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 10:23
 */

#include "Exception.h"
#include <cstring>
#include <string>
#include <boost/format.hpp>

namespace Linda
{

Exception::Exception(int errno, const char *prefix)
: runtime_error(boost::str(boost::format("%1%: %2%") % prefix % strerror(errno)))
{
    
}

Exception::Exception(const char* str)
: std::runtime_error(std::string(str))
{

}

}

