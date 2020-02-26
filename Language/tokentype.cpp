#include "tokentype.h"
#include "constants.h"
#include <cassert>


std::map<std::string, TokenType> TokenTypeHelper::keyWords = { { Constants::LET, TokenType::Let },
                                                               { Constants::FUNC, TokenType::Func },
                                                               { Constants::IF, TokenType::If },
                                                               { Constants::ELSE, TokenType::Else },
                                                               { Constants::RETURN, TokenType::Return }
                                                             };

TokenType TokenTypeHelper::getTokenTypeFromLiteral(const std::string &literal)
{
    if (literal == Constants::IDENTIFIER)
        return TokenType::Identifier;
    if (literal == Constants::PLUS)
        return TokenType::Plus;
    if (literal == Constants::MINUS)
        return  TokenType::Minus;
    if (literal == Constants::ASSIGN)
        return TokenType::Assign;
    if (literal == Constants::EQUAL)
        return TokenType::Eq;
    if (literal == Constants::NOT_EQUAL)
        return TokenType::Ne;
    if (literal == Constants::GREATER_THEN)
        return TokenType::Gt;
    if (literal == Constants::LESS_THEN)
        return TokenType::Lt;
    if (literal == Constants::GREATER_EQUAL)
        return TokenType::Ge;
    if (literal == Constants::LESS_EQUAL)
        return TokenType::Le;
    if (literal == Constants::COMMA)
        return TokenType::Comma;
    if (literal == Constants::SEMICOLON)
        return TokenType::Semicolon;
    if (literal == Constants::LEFT_PARENT)
        return TokenType::LeftParent;
    if (literal == Constants::RIGHT_PARENT)
        return TokenType::RightParent;
    if (literal == Constants::LEFT_BRACE)
        return TokenType::LeftBrace;
    if (literal == Constants::RIGHT_BRACE)
        return TokenType::RightBrace;
    if (literal == Constants::LET)
        return TokenType::Let;
    if (literal == Constants::FUNC)
        return TokenType::Func;
    if (literal == Constants::IF)
        return TokenType::If;
    if (literal == Constants::ELSE)
        return TokenType::Else;
    if (literal == Constants::RETURN)
        return TokenType::Return;
    if (literal == Constants::END_OF_FILE)
        return TokenType::Eof;

    assert(false);
    return TokenType::Unknown;
}

TokenType TokenTypeHelper::lookUpIdentifier(const std::string &identifier)
{
    std::map<std::string, TokenType>::const_iterator it = keyWords.find(identifier);
    return it != keyWords.cend() ? (*it).second : TokenType::Identifier;
}

std::string TokenTypeHelper::convertToString(TokenType type)
{
    switch (type)
    {
    case TokenType::Unknown:
        return Constants::UNKNOWN;
    case TokenType::Identifier:
        return Constants::IDENTIFIER;
    case TokenType::Plus:
        return Constants::PLUS;
    case TokenType::Minus:
        return Constants::MINUS;
    case TokenType::Assign:
        return Constants::ASSIGN;
    case TokenType::Eq:
        return Constants::EQUAL;
    case TokenType::Ne:
        return Constants::NOT_EQUAL;
    case TokenType::Gt:
        return Constants::GREATER_THEN;
    case TokenType::Lt:
        return Constants::LESS_THEN;
    case TokenType::Ge:
        return Constants::GREATER_EQUAL;
    case TokenType::Le:
        return Constants::LESS_EQUAL;
    case TokenType::Comma:
        return Constants::COMMA;
    case TokenType::Semicolon:
        return Constants::SEMICOLON;
    case TokenType::LeftParent:
        return Constants::LEFT_PARENT;
    case TokenType::RightParent:
        return Constants::RIGHT_PARENT;
    case TokenType::LeftBrace:
        return Constants::LEFT_BRACE;
    case TokenType::RightBrace:
        return Constants::RIGHT_BRACE;
    case TokenType::Let:
        return Constants::LET;
    case TokenType::Func:
        return Constants::FUNC;
    case TokenType::If:
        return Constants::IF;
    case TokenType::Else:
        return Constants::ELSE;
    case TokenType::Return:
        return Constants::RETURN;
    case TokenType::Eof:
        return Constants::END_OF_FILE;
    default:
        assert(false);
        return Constants::UNKNOWN;
    }
}
