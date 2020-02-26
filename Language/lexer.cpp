#include "lexer.h"
#include "constants.h"
#include <cstring>
#include <cassert>
#include <iostream>

namespace lexer
{
Lexer::Lexer(const std::string &context)
    : _context(context), _position(0), _readPosition(0)
{
}

Token Lexer::nextToken()
{
    assert(_symbol.size() == 1);

    skipWhiteSpace();
    Token token = Token(TokenType::Unknown, "");
    if (_symbol == Constants::PLUS)
        token = Token(_symbol);
    if (_symbol == Constants::MINUS)
        token = Token(_symbol);
    if (_symbol == Constants::ASSIGN)
        token = handlerAssign();
    if (_symbol == Constants::GREATER_THEN)
        token = handlerGreater();
    if (_symbol == Constants::LESS_THEN)
        token = handlerLess();
    if (_symbol == Constants::NOT)
        token = handlerNotEqual();
    if (_symbol == Constants::COMMA)
        token = Token(_symbol);
    if (_symbol == Constants::SEMICOLON)
        token = Token(_symbol);
    if (_symbol == Constants::LEFT_PARENT)
        token = Token(_symbol);
    if (_symbol == Constants::RIGHT_PARENT)
        token = Token(_symbol);
    if (_symbol == Constants::LEFT_BRACE)
        token = Token(_symbol);
    if (_symbol == Constants::RIGHT_BRACE)
        token = Token(_symbol);

    if (isalpha(_symbol.at(0)))
    {
        std::string literal = readIdentifier();
        token = Token(TokenTypeHelper::lookUpIdentifier(literal), literal);
    }
    if (isdigit(_symbol.at(0)))
    {
        std::string number = readNumber();
        token = Token(TokenType::Identifier, number);
    }

    if (_position == _context.size())
        token = Token(TokenType::Eof, Constants::END_OF_FILE);

    readChar();

    return token;
}

void Lexer::setInput(const std::string context)
{
    _context = context;
    _symbol = '\0';
    _position = _readPosition = 0;
    readChar();
}

void Lexer::readChar()
{
    if (_readPosition >= _context.size())
        _symbol = '\0';
    else
        _symbol = _context.at(_readPosition);
    _position = _readPosition++;
}

std::string Lexer::readIdentifier()
{
    size_t startPos = _position;
    while (isIdentifierValidated())
        readChar();

    return _context.substr(startPos, _readPosition - startPos);
}

std::string Lexer::readNumber()
{
    size_t startPos = _position;
    while (isNumberValidated())
        readChar();
    return _context.substr(startPos, _readPosition - startPos);
}

void Lexer::skipWhiteSpace()
{
    while(isSpace())
        readChar();
}

bool Lexer::isSpace() const
{
    return _position < _context.size() && isspace(_context.at(_position));
}

std::string Lexer::peekChar() const
{
    std::string nextChar;
    if (_readPosition >= _context.size())
        nextChar = '\0';
    else
        nextChar = _context.at(_readPosition);
    return nextChar;
}

Token Lexer::handlerAssign()
{
    if (peekChar() == Constants::ASSIGN)
    {
        readChar();
        return Token(TokenType::Eq, Constants::EQUAL);
    }
    else
    {
        return Token(_symbol);
    }
}

Token Lexer::handlerGreater()
{
    if (peekChar() == Constants::ASSIGN)
    {
        readChar();
        return Token(TokenType::Ge, Constants::GREATER_EQUAL);
    }
    else
    {
        return Token(_symbol);
    }
}

Token Lexer::handlerLess()
{
    if (peekChar() == Constants::ASSIGN)
    {
        readChar();
        return Token(TokenType::Le, Constants::LESS_EQUAL);
    }
    else
    {
        return Token(_symbol);
    }
}

Token Lexer::handlerNotEqual()
{
    if (peekChar() == Constants::ASSIGN)
    {
        readChar();
        return Token(TokenType::Ne, Constants::NOT_EQUAL);
    }
    else
    {
        // Unary operator [!] don't implemented in this version
        assert(false);
        return Token(TokenType::Unknown, Constants::UNKNOWN);
    }
}

bool Lexer::isIdentifierValidated() const
{
    const bool isNextIndexValid{ _position + 1 < _context.size() };
    return isalpha(_context.at(_position)) && isNextIndexValid && isalpha(_context.at(_position + 1));
}

bool Lexer::isNumberValidated() const
{
    const bool isNextIndexValid{ _position + 1 < _context.size() };
    return isdigit(_context.at(_position)) && isNextIndexValid && isdigit(_context.at(_position + 1));
}
}
