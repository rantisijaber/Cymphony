//
// Created by Jaber Rantisi on 12/11/25.
//

#ifndef CYMPHONY_TOKEN_UTILS_HPP
#define CYMPHONY_TOKEN_UTILS_HPP
#include "token.hpp"

namespace token_utils {
    TokenType get_token_type(char c); // will do switch for all single character tokens
    TokenType get_token_type(const std::unordered_map<std::string_view, TokenType>& multi_char_map,
                            std::string_view str);
    TokenType get_operator_token_type(char c);
    TokenType get_punctuation_token_type(char c);
    bool is_keyword(std::string_view str);
    bool is_identifier(char c);
    bool is_number(char c);
    bool is_punctuation(char c);
    bool is_operator(char c);

}
#endif //CYMPHONY_TOKEN_UTILS_HPP