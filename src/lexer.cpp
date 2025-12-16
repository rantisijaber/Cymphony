//
// Created by Jaber Rantisi on 12/11/25.
//
#include <iostream>
#include <string_view>
#include "lexer.hpp"
#include "token_utils.hpp"


void Lexer::printTokens() const {
    for (const Token& token : tokens_) {
        token.print_token();
    }
}

void Lexer::advance() {

    if (pos_ >= source_code_.size()) return;


    if (source_code_[pos_] == '\n') {
        col_ = 0;
        line_++;
    }
    col_++;
    current_char_ = source_code_[++pos_];
}

void Lexer::tokenize() {
    while (pos_ < source_code_.size()) {

        if (isspace(current_char_)) {
            advance();
            continue;
        }

        if (token_utils::is_operator(current_char_)) {
            const size_t start_pos = pos_;
            int line = line_;
            int start_col = col_;

            advance();
            while (token_utils::is_operator(current_char_)) {
                advance();
            }

            if (pos_ - start_pos > 1) {
                const std::string_view value(source_code_.data() + start_pos, pos_ - start_pos);
                tokens_.emplace_back(token_utils::get_token_type(multi_char_operator_map, value), line, start_col);
            } else {
                tokens_.emplace_back(token_utils::get_token_type(source_code_[start_pos]), line, start_col);
            }

        }

        if (token_utils::is_punctuation(current_char_)) {
            int line = line_;
            int start_col = col_;

            tokens_.emplace_back(token_utils::get_token_type(current_char_), line, start_col);
            advance();
        }

        if (std::isdigit(current_char_)) {
            const size_t start_pos = pos_;
            int line = line_;
            int start_col = col_;

            advance();
            while (std::isdigit(current_char_)) {
                advance();
            }
            tokens_.emplace_back(TokenType::Number,
                source_code_.substr(start_pos, pos_ - start_pos),
                line, start_col);
        }

        if (std::isalpha(current_char_) || current_char_ == '_') {
            const size_t start_pos = pos_;
            int line = line_;
            int start_col = col_;

            advance();
            while (std::isalnum(current_char_) || current_char_ == '_') {
                advance();
            }
            const std::string_view value(source_code_.data() + start_pos, pos_ - start_pos);
            token_utils::is_keyword(value) ?
                tokens_.emplace_back(token_utils::get_token_type(multi_char_keyword_map, value), line, start_col)
                : tokens_.emplace_back(TokenType::Identifier, std::string(value), line, start_col);
        }

        if (pos_ == source_code_.size()) tokens_.emplace_back(TokenType::Eof, line_, col_);
    }
}

