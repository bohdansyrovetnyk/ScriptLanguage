#ifndef TOKEN_H
#define TOKEN_H

#include "tokentype.h"

class Token final
{
public:
    Token();
    Token(TokenType type, const std::string &literal);
    Token(const std::string &literal);
    TokenType type() const;
    std::string literal() const;

    friend std::ostream& operator << (std::ostream &stream, const Token &token);

private:
    TokenType _type;
    std::string _literal;
};

#endif // TOKEN_H
