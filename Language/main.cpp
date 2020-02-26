#include <iostream>

#include "repl.h"
#include "lexer.h"

int main()
{
    lexer::Lexer lexer;
    REPL repl(&lexer);
    repl.start();

    return 0;
}
