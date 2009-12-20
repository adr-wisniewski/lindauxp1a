#include "Serializable.h"
#include <boost/scoped_array.hpp>

namespace Linda
{
    void SerializeString(const std::string &s, std::ostream &stream)
    {
        size_t length = s.length();
        stream << length;

        stream.write(s.c_str(), length);
    }

    std::string UnserializeString(std::istream &stream)
    {
        size_t length;
        stream >> length;

        boost::scoped_array<char> buffer(new char[length]);
        stream.read(buffer.get(), length);

        return std::string(buffer.get(), length);
    }
}
