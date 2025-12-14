//
// Created by Jaber Rantisi on 12/11/25.
//

#include "token_utils.hpp"
#include "unordered_map"



TokenType token_utils::get_token_type(const char c) {
    if (is_punctuation(c)) return get_punctuation_token_type(c);
    return get_operator_token_type(c);
}


bool token_utils::is_punctuation(const char c) {
    return c == '(' || c == ')' || c == '{' || c == '}'
    || c == '[' || c == ']' || c == ',' || c == ';';
}

bool token_utils::is_operator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/'
    || c == '%' || c == '=' || c == '<' || c == '>'
    || c == '.';
}

bool token_utils::is_keyword(const std::string_view str) {
    return str == "if" || str == "else" || str == "for" || str == "while"
    || str == "do" || str == "boolean" || str == "int" || str == "double"
    || str == "float" || str == "char" || str == "long" || str == "struct"
    || str == "interface" || str == "inherits" || str == "implements" || str == "return"
    || str == "const" || str == "void" || str == "public" || str == "private"
    || str == "protected";
}

TokenType token_utils::get_punctuation_token_type(const char c) {
    switch (c) {
        case '(':
            return TokenType::LParen;
        case ')':
            return TokenType::RParen;
        case '{':
            return TokenType::LCurly;
        case '}':
            return TokenType::RCurly;
        case '[':
            return TokenType::LBracket;
        case ']':
            return TokenType::RBracket;
        case ',':
            return TokenType::Comma;
        case ';':
            return TokenType::Semicolon;
        default:
            return TokenType::Eof;
    }
}

TokenType token_utils::get_operator_token_type(const char c) {
    switch (c) {
        case '+':
            return TokenType::Plus;
        case '-':
            return TokenType::Minus;
        case '*':
            return TokenType::Multiply;
        case '/':
            return TokenType::Divide;
        case '%':
            return TokenType::Mod;
        case '=':
            return TokenType::Assign;
        case '<':
            return TokenType::Less;
        case '>':
            return TokenType::Greater;
        case '.':
            return TokenType::Dot;
        default:
            return TokenType::Eof;
    }
}

TokenType token_utils::get_token_type(const std::unordered_map<std::string_view, TokenType>& multi_char_map, const std::string_view str) {
    if (const auto iterator = multi_char_map.find(str); iterator != multi_char_map.end()) {
        return iterator->second;
    }
    return TokenType::Eof;
}

