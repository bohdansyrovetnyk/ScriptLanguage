#include "token.h"
#include <iostream>
#include <iomanip>

Token::Token()
    : _type(TokenType::Unknown), _literal(TokenTypeHelper::convertToString(TokenType::Unknown))
{
}

Token::Token(TokenType type, const std::string &literal)
    : _type(type), _literal(literal)
{
}

Token::Token(const std::string &literal)
    : Token(TokenTypeHelper::getTokenTypeFromLiteral(literal), literal)
{
}

TokenType Token::type() const
{
    return _type;
}

std::string Token::literal() const
{
    return _literal;
}

std::ostream &operator <<(std::ostream &stream, const Token &token)
{
    static constexpr size_t TYPE_OFFSET{ 10 };
    static constexpr size_t LITERAL_OFFSET{ 6 };

    stream << "{ Type: " << std::setw(TYPE_OFFSET) << std::left << TokenTypeHelper::convertToString(token.type())
           << ", Literal: " << std::setw(LITERAL_OFFSET) << std::left << token.literal() << " }";
    return stream;
}
