//
// Created by Jaber Rantisi on 12/11/25.
//

#ifndef CYMPHONY_TOKEN_UTILS_HPP
#define CYMPHONY_TOKEN_UTILS_HPP
#include "token.hpp"

namespace token_utils {
    TokenType getSingleCharTokenType(char c); // will do switch for all single character tokens
    TokenType getKeywordTokenType(const std::string& str);
    TokenType getMultiCharTokenType(const std::unordered_map<std::string, TokenType>& multi_char_map,
                                    const std::string& str);
    TokenType getOperatorTokenType(char c);
    TokenType getPunctuationTokenType(char c);
    bool isKeyword(const std::string& str);
    bool isCharIdentifier(char c);
    bool isNumber(char c);
    bool isCharPunctuation(char c);
    bool isCharOperator(char c);

}
#endif //CYMPHONY_TOKEN_UTILS_HPP