#include "repl.h"
#include "lexer.h"

#include <cassert>
#include <iostream>

static const std::string EXIT = "exit";

REPL::REPL(lexer::Lexer *lexer)
    : _lexer(lexer)
{
}

void REPL::start()
{
    std::string input;
    do
    {
        std::getline(std::cin, input);
        parseInput(input);
    } while (input != EXIT);
}

void REPL::parseInput(const std::string &input)
{
    _lexer->setInput(input);
    Token token = _lexer->nextToken();
    if (token.type() == TokenType::Unknown)
        assert(false);

    while (token.type() != TokenType::Eof)
    {
        std::cout << token << std::endl;
        token = _lexer->nextToken();
    };
}
