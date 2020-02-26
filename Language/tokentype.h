#ifndef TOKENTYPEHELPER_H
#define TOKENTYPEHELPER_H

#include <string>
#include <map>

enum class TokenType
{
    Unknown,
    Identifier,
    Eof,

    Plus,
    Minus,
    Assign,

    Eq, // equal ==
    Ne, // not equal !=
    Gt, // greater-then sign >
    Lt, // less-then sign <
    Ge, // greater-then or equal >=
    Le, // less-then or equal <=

    Comma,
    Semicolon,

    LeftParent,
    RightParent,
    LeftBrace,
    RightBrace,

    Let,
    Func,
    If,
    Else,
    Return,
};

class TokenTypeHelper
{
public:
    static std::string convertToString(TokenType type);
    static TokenType getTokenTypeFromLiteral(const std::string &literal);
    static TokenType lookUpIdentifier(const std::string &identifier);

private:
    static std::map<std::string, TokenType> keyWords;
};

#endif // TOKENTYPEHELPER_H
