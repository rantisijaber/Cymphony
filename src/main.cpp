#include <iostream>

#include "lexer.hpp"


int main() {
    std::string test = "int main() \n { int x = 5; \n return x; return 0; }";

    Lexer l(test);
    l.tokenize();
    l.printTokens();
    return 0;
}
