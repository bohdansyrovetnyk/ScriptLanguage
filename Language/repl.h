#ifndef REPL_H
#define REPL_H

#include <string>

namespace lexer
{
class Lexer;
}

class REPL
{
public:
    REPL(lexer::Lexer *lexer);
    void start();

private:
    void parseInput(const std::string &input);

private:
    lexer::Lexer *_lexer{ nullptr };
};

#endif // REPL_H
