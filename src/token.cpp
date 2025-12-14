//
// Created by Jaber Rantisi on 12/12/25.
//

#include "token.hpp"

void Token::print_token() const {
    if (value_.empty()) {
        std::cout << "TYPE: " << token_type_to_string()
        << " LINE: " << line_ << " COLUMN: " << column_ << std::endl;
    } else {
        std::cout << "TYPE: " << token_type_to_string()
        << " VALUE: " << value_ << " LINE: " << line_
        << " COLUMN: " << column_ << std::endl;
    }


}

[[nodiscard]] std::string Token::token_type_to_string() const {
    switch (type_) {
        case TokenType::Identifier:
            return "IDENTIFIER";
        case TokenType::Number:
            return "NUMBER";
        case TokenType::String:
            return "STRING";
        case TokenType::Plus:
            return "OPERATOR (PLUS)";
        case TokenType::Minus:
            return "OPERATOR (MINUS)";
        case TokenType::Multiply:
            return "OPERATOR (MULTIPLY)";
        case TokenType::Divide:
            return "OPERATOR (DIVIDE)";
        case TokenType::Mod:
            return "OPERATOR (MOD)";
        case TokenType::Assign:
            return "OPERATOR (ASSIGN)";
        case TokenType::EqualEqual:
            return "OPERATOR (EQUAL_EQUAL)";
        case TokenType::NotEqual:
            return "OPERATOR (NOT_EQUAL)";
        case TokenType::Less:
            return "OPERATOR (LESS)";
        case TokenType::LessEqual:
            return "OPERATOR (LESS_EQUAL)";
        case TokenType::Greater:
            return "OPERATOR (GREATER)";
        case TokenType::GreaterEqual:
            return "OPERATOR (GREATER_EQUAL)";
        case TokenType::Dot:
            return "OPERATOR (DOT)";
        case TokenType::Increment:
            return "OPERATOR (INCREMENT)";
        case TokenType::Decrement:
            return "OPERATOR (DECREMENT)";
        case TokenType::PlusEquals:
            return "OPERATOR (PLUS_EQUALS)";
        case TokenType::MultiplyEquals:
            return "OPERATOR (MULTIPLY_EQUALS)";
        case TokenType::MinusEquals:
            return "OPERATOR (MINUS_EQUALS)";
        case TokenType::DivideEquals:
            return "OPERATOR (DIVIDE_EQUALS)";
        case TokenType::ModEquals:
            return "OPERATOR (MOD_EQUALS)";
        case TokenType::BitwiseAnd:
            return "OPERATOR (BITWISE_AND)";
        case TokenType::LogicAnd:
            return "OPERATOR (LOGIC_AND)";
        case TokenType::BitwiseOr:
            return "OPERATOR (BITWISE_OR)";
        case TokenType::LogicOr:
            return "OPERATOR (LOGIC_OR)";
        case TokenType::BitwiseXor:
            return "OPERATOR (BITWISE_XOR)";
        case TokenType::LogicXor:
            return "OPERATOR (LOGIC_XOR)";
        case TokenType::BitwiseNo:
            return "OPERATOR (BITWISE_NO)";
        case TokenType::LogicNo:
            return "OPERATOR (LOGIC_NO)";
        case TokenType::If:
            return "KEYWORD (IF)";
        case TokenType::Else:
            return "KEYWORD (ELSE)";
        case TokenType::For:
            return "KEYWORD (FOR)";
        case TokenType::While:
            return "KEYWORD (WHILE)";
        case TokenType::Do:
            return "KEYWORD (DO)";
        case TokenType::Boolean:
            return "KEYWORD (BOOLEAN)";
        case TokenType::Int:
            return "KEYWORD (INT)";
        case TokenType::Double:
            return "KEYWORD (DOUBLE)";
        case TokenType::Float:
            return "KEYWORD (FLOAT)";
        case TokenType::Character:
            return "KEYWORD (CHARACTER)";
        case TokenType::Long:
            return "KEYWORD (LONG)";
        case TokenType::Struct:
            return "KEYWORD (STRUCT)";
        case TokenType::Interface:
            return "KEYWORD (INTERFACE)";
        case TokenType::Inherits:
            return "KEYWORD (INHERITS)";
        case TokenType::Implements:
            return "KEYWORD (IMPLEMENTS)";
        case TokenType::Return:
            return "KEYWORD (RETURN)";
        case TokenType::Const:
            return "KEYWORD (CONST)";
        case TokenType::Void:
            return "KEYWORD (VOID)";
        case TokenType::Public:
            return "KEYWORD (PUBLIC)";
        case TokenType::Private:
            return "KEYWORD (PRIVATE)";
        case TokenType::Protected:
            return "KEYWORD (PROTECTED)";
        case TokenType::LParen:
            return "PUNCTUATION (LEFT_PAREN)";
        case TokenType::RParen:
            return "PUNCTUATION (RIGHT_PAREN)";
        case TokenType::LCurly:
            return "PUNCTUATION (LEFT_CURLY)";
        case TokenType::RCurly:
            return "PUNCTUATION (RIGHT_CURLY)";
        case TokenType::LBracket:
            return "PUNCTUATION (LEFT_BRACKET)";
        case TokenType::RBracket:
            return "PUNCTUATION (RIGHT_BRACKET)";
        case TokenType::Comma:
            return "PUNCTUATION (COMMA)";
        case TokenType::Semicolon:
            return "PUNCTUATION (SEMICOLON)";
        case TokenType::Colon:
            return "PUNCTUATION (COLON)";
        case TokenType::Eof:
            return "END_OF_FILE";
        default:
            return "UNKNOWN";
    }
}