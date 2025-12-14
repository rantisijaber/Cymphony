//
// Created by Jaber Rantisi on 12/12/25.
//

#ifndef CYMPHONY_LEXER_HPP
#define CYMPHONY_LEXER_HPP
#include <vector>

#include "token.hpp"

class Lexer {
    std::vector<Token> tokens_;
    std::string source_code_;
    int pos_ = 0;
    int line_ = 1;
    int col_ = 1;
    char current_char_;
public:
    std::unordered_map<std::string_view, TokenType> multi_char_operator_map = {
        {"==", TokenType::EqualEqual},
        {"!=", TokenType::NotEqual},
        {"<=", TokenType::LessEqual},
        {">=", TokenType::GreaterEqual},
        {"++", TokenType::Increment},
        {"--", TokenType::Decrement},
        {"+=", TokenType::PlusEquals},
        {"-=", TokenType::MinusEquals},
        {"*=", TokenType::MultiplyEquals},
        {"/=", TokenType::DivideEquals},
        {"%=", TokenType::ModEquals}
    };

    std::unordered_map<std::string_view, TokenType> multi_char_keyword_map = {
        {"if", TokenType::If},
        {"else", TokenType::Else},
        {"for", TokenType::For},
        {"while", TokenType::While},
        {"do", TokenType::Do},
        {"boolean", TokenType::Boolean},
        {"int", TokenType::Int},
        {"double", TokenType::Double},
        {"float", TokenType::Float},
        {"char", TokenType::Character},
        {"long", TokenType::Long},
        {"struct", TokenType::Struct},
        {"interface", TokenType::Interface},
        {"inherits", TokenType::Inherits},
        {"implements", TokenType::Implements},
        {"return", TokenType::Return},
        {"const", TokenType::Const},
        {"void", TokenType::Void},
        {"public", TokenType::Public},
        {"private", TokenType::Private},
        {"protected", TokenType::Protected}
    };



    explicit Lexer(std::string& source_code)
        :   source_code_(std::move(source_code)) {
        current_char_ = pos_ < source_code_.size() ? source_code_[pos_] : '\0';

    }

    [[nodiscard]] const std::vector<Token>& tokens() const {
        return tokens_;
    }
    void printTokens() const;
    void advance();
    void tokenize();

};

#endif //CYMPHONY_LEXER_HPP