/* 
 * File:   Util.h
 * Author: adrian
 *
 * Created on 28 grudzień 2009, 14:53
 */

#ifndef _UTIL_H
#define	_UTIL_H

#include <string>

namespace Linda
{
    namespace Test
    {
        const std::string SPACES = " \t\r\n";

        void debug_print(const std::string &message);

        std::string trim_right (const std::string & s, const std::string & t = SPACES);

        std::string trim_left (const std::string & s, const std::string & t = SPACES);

        std::string trim (const std::string & s, const std::string & t = SPACES);
    }
}

#endif	/* _UTIL_H */

