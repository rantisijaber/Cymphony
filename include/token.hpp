//
// Created by Jaber Rantisi on 12/10/25.
//

#ifndef CYMPHONY_TOKEN_HPP
#define CYMPHONY_TOKEN_HPP
#include <iostream>
#include <string>
#include "token_utils.hpp"

enum class TokenType {
    Identifier,

    // Literals
    Number,
    String,

    // Operators
    Plus,
    Minus,
    Multiply,
    Divide,
    Mod,
    Assign,
    EqualEqual,
    NotEqual,
    Less,
    LessEqual,
    Greater,
    GreaterEqual,
    Dot,
    Increment,
    Decrement,
    PlusEquals,
    MultiplyEquals,
    MinusEquals,
    DivideEquals,
    ModEquals,
    BitwiseAnd,
    LogicAnd,
    BitwiseOr,
    LogicOr,
    BitwiseXor,
    LogicXor,
    BitwiseNo,
    LogicNo,

    // Keywords
    If,
    Else,
    For,
    While,
    Do,
    Boolean,
    Int,
    Double,
    Float,
    Character,
    Long,
    Struct,
    Interface,
    Inherits,
    Implements,
    Return,
    Const,
    Void,
    Public,
    Private,
    Protected,

    // Punctuation
    LParen,
    RParen,
    LCurly,
    RCurly,
    LBracket,
    RBracket,
    Comma,
    Semicolon,
    Colon,

    // End of File
    Eof

};


struct Token {
    TokenType type_;
    std::string value_;
    int line_;
    int column_;

    // Constructor: Operators, Keywords, Punctuation, EOF
    explicit Token(const TokenType type, int const line, int const column)
        :   type_(type),
            line_(line), column_(column) {}

    // Constructor: Identifiers and Literals
    Token(const TokenType type, std::string value, const int line, const int column)
        :   type_(type), value_(std::move(value)),
            line_(line), column_(column) {}

    void printToken() const;


    [[nodiscard]] std::string tokenTypeToString() const;
};

#endif //CYMPHONY_TOKEN_HPP