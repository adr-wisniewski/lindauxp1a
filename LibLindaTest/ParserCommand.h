/* 
 * File:   ParserCommand.h
 * Author: adrian
 *
 * Created on 28 grudzień 2009, 16:55
 */

#ifndef _PARSERCOMMAND_H
#define	_PARSERCOMMAND_H

#include <boost/shared_ptr.hpp>
#include <utility>
#include <string>
#include <stdexcept>
#include <map>
#include <set>

#include "MessageCommand.h"
#include <Tuple.h>
#include <Query.h>


namespace Linda
{
    namespace Test
    {
        class ParserCommand
        {
        public:
            ParserCommand();

            boost::shared_ptr<MessageCommand> Parse(const std::string &input, int ordinal);

            class ParseException : public std::runtime_error
            {
            public:
                ParseException(const std::string &what);
            };

            enum TokenType
            {
                TT_EOS = 1,

                TT_LParen,
                TT_RParen,
                TT_Comma,
                TT_Colon,

                TT_Operator,
                TT_AnyValue,
                TT_String,
                TT_Integer,
                TT_Float,

                TT_Invalid
            };

        protected:

            // lexer
            enum
            {
                TokenTypeCount = TT_Invalid
            };

            static std::string TokenNames[TokenTypeCount];

            typedef std::pair<TokenType, std::string>   Token;
            typedef std::string::iterator               Position;

            void Init(const std::string &input);
            Token GetNext();

            std::string source;
            Position previous;
            Position current;
            Position end;

            // parser
            typedef std::set<TokenType> TokenTypes;
            typedef boost::shared_ptr<MessageCommand> (ParserCommand::*parser)();
            typedef std::map<std::string, parser> ParserMap;

            Token accept(TokenType type);
            Token accept(TokenType type1, TokenType type2);
            Token accept(TokenType type1, TokenType type2, TokenType type3);
            Token accept(TokenTypes types);

            boost::shared_ptr<MessageCommand> ParseCommandCreate();
            boost::shared_ptr<MessageCommand> ParseCommandKill();
            boost::shared_ptr<MessageCommand> ParseCommandStat();
            boost::shared_ptr<MessageCommand> ParseCommandOutput();
            boost::shared_ptr<MessageCommand> ParseCommandInput();
            boost::shared_ptr<MessageCommand> ParseCommandRead();

            boost::shared_ptr<Tuple> ParseTuple();
            boost::shared_ptr<Query> ParseQuery();

            template <class TType>
            boost::shared_ptr<TupleValue> ParseTupleValue();
            
            template <class TType>
            boost::shared_ptr<QueryValue> ParseQueryValue();


            std::string UnexceptedToken(Token got, TokenTypes excepted);

            ParserMap Parsers;
            int mOrdinal;
        };
    }
}



#endif	/* _PARSERCOMMAND_H */

