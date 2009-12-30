/* 
 * File:   ParserCommand.cpp
 * Author: adrian
 * 
 * Created on 28 grudzień 2009, 16:55
 */

#include <map>

#include "ParserCommand.h"
#include <boost/format.hpp>
#include <ctype.h>
#include <sstream>
#include <boost/lexical_cast.hpp>

#include "CommandCreate.h"
#include "CommandKill.h"
#include "CommandStat.h"
#include "CommandInput.h"
#include "CommandOutput.h"
#include "CommandRead.h"

namespace Linda
{
namespace Test
{
    /*static*/ std::string ParserCommand::TokenNames[TokenTypeCount] = {
        "end of input",         //TT_EOS

        "left parenthesis",     //TT_LParen
        "right parenthesis",    //TT_RParen
        "comma",                //TT_Comma
        "colon",                //TT_Colon

        "operator",             //TT_Operator
        "string",               //TT_String
        "integer",              //TT_Integer
        "float",                //TT_Float

        "invalid",              //TT_Invalid
    };

    template<class TType>
    struct ParseTraits
    {

    };

    template<>
    struct ParseTraits<int>
    {
        static const ParserCommand::TokenType TokenType = ParserCommand::TT_Integer;
        static const bool AllowEqual = true;
    };

    template<>
    struct ParseTraits<float>
    {
        static const ParserCommand::TokenType TokenType = ParserCommand::TT_Float;
        static const bool AllowEqual = false;
    };

    template<>
    struct ParseTraits<std::string>
    {
        static const ParserCommand::TokenType TokenType = ParserCommand::TT_String;
        static const bool AllowEqual = true;
    };

    template<class TType>
    boost::shared_ptr<QueryValue> CreateQueryValue(TType value, std::string oper)
    {
        if(oper == "=")
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationEqual>(value));
        }
        else if(oper == "!=")
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationNotEqual>(value));
        }
        else if(oper == "<")
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationLess>(value));
        }
        else if(oper == "<=")
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationEqualLess>(value));
        }
        else if(oper == ">")
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationGreater>(value));
        }
        else // oper == ">="
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationEqualGreater>(value));
        }
    }

    ParserCommand::ParserCommand()
    {
        Parsers["create"]   = &ParserCommand::ParseCommandCreate;
        Parsers["kill"]     = &ParserCommand::ParseCommandKill;
        Parsers["stat"]     = &ParserCommand::ParseCommandStat;
        Parsers["output"]   = &ParserCommand::ParseCommandOutput;
        Parsers["input"]    = &ParserCommand::ParseCommandInput;
        Parsers["read"]     = &ParserCommand::ParseCommandRead;
    }

    boost::shared_ptr<MessageCommand> ParserCommand::Parse(const std::string &input, int ordinal)
    {
        // initialize lexer
        Init(input);
        mOrdinal = ordinal;

        // get command name
        Token token = accept(TT_String);

        // find parser
        for(ParserMap::iterator i = Parsers.begin(), e = Parsers.end(); i != e; ++i)
        {
            if(token.second == i->first)
                return (this->*(i->second))();
        }

        // unknown command
        throw ParseException(boost::str(
            boost::format("Unknown command: '%1%'") % token.second)
        );
    }

    void ParserCommand::Init(const std::string &input)
    {
        source      = input;
        previous    = source.begin();
        current     = previous;
        end         = source.end();
    }

    ParserCommand::Token ParserCommand::GetNext()
    {
        // skip white spaces
        while(current != end && isspace(*current))
            ++current;

        // detect end of string
        if(current == end)
            return std::make_pair(TT_EOS, "");

        // initialize search
        char c = *current;
        TokenType type = TT_Invalid;

        // mark beginning
        previous = current;
        
        // check characters
        switch(c)
        {
        case '(':
            ++current;
            type = TT_LParen;
            break;

        case ')':
            ++current;
            type = TT_RParen;
            break;

        case ',':
            ++current;
            type = TT_Comma;
            break;

        case ':':
            ++current;
            type = TT_Colon;
            break;

        case '=':
            ++current;
            type = TT_Operator;
            break;

        case '*':
            ++current;
            type = TT_AnyValue;
            break;

        case '>':
        case '<':
            ++current;

            if(*current == '=')
                ++current;

            type = TT_Operator;
            break;

        case '!':
            ++current;
            if(*current == '=')
            {
                ++current;
                type = TT_Operator;
            }
            else
            {
                current = previous; // back
            }
            break;

        default:
            // check digits for integer and float
            if(isdigit(c))
            {
                // read all digits
                while(++current != end && isdigit(c = *current));

                // if its not float - then its int
                if(current == end || c != '.')
                {
                    type = TT_Integer;
                }
                else
                {
                    // next character must be a digit
                    if(++current == end || !isdigit(*current))
                    {
                        type = TT_Invalid;
                    }
                    else
                    {
                        // read all digits again
                        while(++current != end && isdigit(*current));

                        type = TT_Float;
                    }
                }
            }

            // check alpha for strings
            else if(isalpha(c))
            {
                // read all alphanum
                while(++current != end && isalnum(c = *current));

                type = TT_String;
            }
        }

        // detect invalid tokens
        if(type == TT_Invalid)
            throw ParseException(boost::str(
                boost::format("Invalid token '%1%' at position %2%")
                    % std::string(previous,current)
                    % (previous - source.begin())
            ));

        // return result
        return std::make_pair(type, std::string(previous,current));
    }

    ParserCommand::Token ParserCommand::accept(TokenType type)
    {
        TokenTypes types;
        types.insert(type);
        
        return accept(types);
    }

    ParserCommand::Token ParserCommand::accept(TokenType type1, TokenType type2)
    {
        TokenTypes types;
        types.insert(type1);
        types.insert(type2);

        return accept(types);
    }

    ParserCommand::Token ParserCommand::accept(TokenType type1, TokenType type2, TokenType type3)
    {
        TokenTypes types;
        types.insert(type1);
        types.insert(type2);
        types.insert(type3);

        return accept(types);
    }

    ParserCommand::Token ParserCommand::accept(TokenTypes types)
    {
        Token result = GetNext();

        if(types.find(result.first) == types.end())
            throw ParseException(UnexceptedToken(result, types));

        return result;
    }

    boost::shared_ptr<MessageCommand> ParserCommand::ParseCommandCreate()
    {
        Token number = accept(TT_Integer);
        accept(TT_EOS);

        return boost::shared_ptr<MessageCommand>(new CommandCreate(
            mOrdinal,
            boost::lexical_cast<int>(number.second)
        ));
    }

    boost::shared_ptr<MessageCommand> ParserCommand::ParseCommandKill()
    {
        Token number = accept(TT_Integer);
        accept(TT_EOS);

        return boost::shared_ptr<MessageCommand>(new CommandKill(
            mOrdinal,
            boost::lexical_cast<int>(number.second)
        ));
    }

    boost::shared_ptr<MessageCommand> ParserCommand::ParseCommandStat()
    {
        accept(TT_EOS);

        return boost::shared_ptr<MessageCommand>(new CommandStat());
    }

    boost::shared_ptr<MessageCommand> ParserCommand::ParseCommandOutput()
    {
        Token number = accept(TT_String);
        boost::shared_ptr<Tuple> tuple = ParseTuple();

        return boost::shared_ptr<MessageCommand>(new CommandOutput(
            mOrdinal,
            boost::lexical_cast<int>(number.second),
            *tuple
        ));
    }

    boost::shared_ptr<MessageCommand> ParserCommand::ParseCommandInput()
    {
        Token number = accept(TT_String);
        boost::shared_ptr<Query> query = ParseQuery();

        return boost::shared_ptr<MessageCommand>(new CommandInput(
            mOrdinal,
            boost::lexical_cast<int>(number.second),
            *query
        ));
    }

    boost::shared_ptr<MessageCommand> ParserCommand::ParseCommandRead()
    {
        Token number = accept(TT_String);
        boost::shared_ptr<Query> query = ParseQuery();

        return boost::shared_ptr<MessageCommand>(new CommandRead(
            mOrdinal,
            boost::lexical_cast<int>(number.second),
            *query
        ));
    }

    boost::shared_ptr<Tuple> ParserCommand::ParseTuple()
    {
        boost::shared_ptr<Tuple> result(new Tuple());
        Token token;

        accept(TT_LParen);

        do
        {
            token = accept(TT_String);
            
            if(token.second == "int")
            {
                result->Values().push_back(ParseTupleValue<int>().get());
            }
            else if(token.second == "float")
            {
                result->Values().push_back(ParseTupleValue<float>().get());
            }
            else if(token.second == "string")
            {
                result->Values().push_back(ParseTupleValue<std::string>().get());
            }
            else
            {
                throw ParseException(boost::str(
                    boost::format("Invalid data type '%1%' at position %2%")
                        % token.second
                        % (previous - source.begin())
                ));
            }

            token = accept(TT_Comma, TT_RParen);
        }
        while( token.first != TT_RParen);

        return result;
    }

    boost::shared_ptr<Query> ParserCommand::ParseQuery()
    {
        boost::shared_ptr<Query> result(new Query());
        Token token;

        accept(TT_LParen);

        do
        {
            Token token = accept(TT_String);

            if(token.second == "int")
            {
                result->Values().push_back(ParseQueryValue<int>().get());
            }
            else if(token.second == "float")
            {
                result->Values().push_back(ParseQueryValue<float>().get());
            }
            else if(token.second == "string")
            {
                result->Values().push_back(ParseQueryValue<std::string>().get());
            }
            else
            {
                throw ParseException(boost::str(
                    boost::format("Invalid data type '%1%' at position %2%")
                        % token.second
                        % (previous - source.begin())
                ));
            }

            token = accept(TT_Comma, TT_RParen);
        }
        while( token.first != TT_RParen);

        return result;

    }


    template <class TType>
    boost::shared_ptr<TupleValue> ParserCommand::ParseTupleValue()
    {
        accept(TT_Colon);
        Token token = accept(ParseTraits<TType>::TokenType);

        // push value
       return boost::shared_ptr<TupleValue>(new ConcreteTupleValue<TType>(
            boost::lexical_cast<TType>(token.second)
        ));
    }

    template <class TType>
    boost::shared_ptr<QueryValue> ParserCommand::ParseQueryValue()
    {
        Token token;
        Token oper;

        oper = accept(TT_Operator);

        if(oper.second == "=")
        {
            if(ParseTraits<TType>::AllowEqual)
            {
                token = accept(ParseTraits<TType>::TokenType, TT_AnyValue);
            }
            else
            {
                token = accept(TT_AnyValue);
            }
        }
        else
            token = accept(ParseTraits<TType>::TokenType);


        // push value
        if(token.first == TT_AnyValue)
        {
            return boost::shared_ptr<QueryValue>(new ConcreteQueryValue<TType, OperationNotEqual>());
        }
        else
        {
            return CreateQueryValue(boost::lexical_cast<TType>(token.second), oper.second);
        }
    }

    std::string ParserCommand::UnexceptedToken(Token got, TokenTypes excepted)
    {
        std::stringstream result;
        result  << "Unexcepted token '"
                << TokenNames[static_cast<int>(got.first)]
                <<"' at position " 
                << (previous - source.begin());

        return result.str();
    }

    ParserCommand::ParseException::ParseException(const std::string &what)
    : std::runtime_error(what)
    {

    }
}
}

