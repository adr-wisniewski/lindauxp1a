#include "MessageCommand.h"
#include "ProcessorCommand.h"

namespace Linda
{
    namespace Test
    {
        MessageCommand::MessageCommand()
        : mOrdinal(-1)
        {

        }

        MessageCommand::MessageCommand(int ordinal)
        : mOrdinal(ordinal)
        {

        }

        /*virtual*/ MessageCommand::~MessageCommand()
        {
        }

        /*virtual*/ void MessageCommand::DoSerialize(Archive &stream) const
        {
            stream << mOrdinal;
        }

        /*virtual*/ void MessageCommand::DoUnserialize(Archive &stream)
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
