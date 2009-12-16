/* 
 * File:   Exception.cpp
 * Author: adrian
 * 
 * Created on 15 grudzień 2009, 10:23
 */

#include "Exception.h"
#include <string>

namespace Linda
{

Exception::Exception(int errno, std::string &prefix)
: runtime_error(prefix + std::string(": ") + std::string(strerror(errno)))
{
    
}

Exception::Exception(const char* str)
: std::runtime_error(std::string(str))
{

}

}

