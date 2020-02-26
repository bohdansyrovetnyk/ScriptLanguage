#ifndef LEXER_H
#define LEXER_H

#include "token.h"

namespace lexer
{
class Lexer
{
public:
    Lexer() = default;
    Lexer(const std::string &context);
    Token nextToken();
    void setInput(const std::string context);

private:
    void readChar();
    std::string readIdentifier();
    std::string readNumber();
    void skipWhiteSpace();

private:
    bool isIdentifierValidated() const;
    bool isNumberValidated() const;
    bool isSpace() const;
    std::string peekChar() const;

    // Handle some token
    Token handlerAssign();
    Token handlerGreater();
    Token handlerLess();
    Token handlerNotEqual();

private:
    std::string _symbol;
    std::string _context;
    size_t _position;
    size_t _readPosition;
};
}
#endif // LEXER_H
