#include "MessageCommand.h"
#include "ProcessorCommand.h"

namespace Linda
{
    namespace Test
    {
        /*virtual*/ void MessageCommand::DoSerialize(std::ostream &stream) const
        {
            stream << mOrdinal;
        }

        /*virtual*/ void MessageCommand::DoUnserialize(std::istream &stream)
        {
            stream >> mOrdinal;
        }

        int MessageCommand::Ordinal() const
        {
            return mOrdinal;
        }

        void MessageCommand::Ordinal(int value)
        {
            mOrdinal = value;
        }
    }
}
