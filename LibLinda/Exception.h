/* 
 * File:   Exception.h
 * Author: adrian
 *
 * Created on 15 grudzień 2009, 10:23
 */

#ifndef _EXCEPTION_H
#define	_EXCEPTION_H

#include <stdexcept>

namespace Linda
{

    class Exception : public std::runtime_error
    {
    public:
        Exception(int errno, const char *prefix);
        Exception(const char* str);
    };
}

#endif	/* _EXCEPTION_H */

