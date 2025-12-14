#include <iostream>

#include "lexer.hpp"


int main() {
    std::string test = "int main()";

    Lexer l(test);
    l.tokenize();
    l.printTokens();
    return 0;
}
