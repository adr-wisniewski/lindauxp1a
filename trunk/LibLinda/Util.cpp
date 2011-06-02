#include "Util.h"

#include <cstdlib>
#include <cstdio>

namespace Linda
{
    void debug_print(const std::string &message)
    {
        write(STDERR_FILENO, message.c_str(), message.length());
        fflush(stderr);
    }

    void debug_print(const boost::format &message)
    {
        debug_print(boost::str(message));
    }

    std::string trim_right (const std::string & s, const std::string & t)
    {
        std::string d (s);
        std::string::size_type i (d.find_last_not_of (t));
        if (i == std::string::npos)
            return "";
        else
            return d.erase (d.find_last_not_of (t) + 1) ;
    }

    std::string trim_left (const std::string & s, const std::string & t)
    {
        std::string d (s);
        return d.erase (0, s.find_first_not_of (t)) ;
    }

    std::string trim (const std::string & s, const std::string & t)
    {
        std::string d (s);
        return trim_left (trim_right (d, t), t) ;
    }
}
