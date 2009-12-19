/* 
 * File:   Exception.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 10:23
 */

#ifndef _EXCEPTION_H
#define	_EXCEPTION_H

#include <stdexcept>
#include <boost/format.hpp>

namespace Linda
{

    class Exception : public std::runtime_error
    {
    public:
        Exception(const char* str);
        Exception(const boost::format &format);
        Exception(int errno, const char *prefix);
    };
}

#endif	/* _EXCEPTION_H */

