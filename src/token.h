#ifndef TOKEN_H
#define TOKEN_H

#include <cctype>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <stdexcept>

enum TokenType {
    None,
    Operator,
    Operand,
};

// A token can be two things.
// 1. `TokenType::Operator`.
// 2. `TokenType::Operand`.
//
// One or the other but not both.
class Token {
    private:
        // The precedence of a `Token`. If `Token` is an `Operand` the value will always be 0.
        // Otherwise, the value varies.
        int m_precedence;
        
        TokenType m_type;

        char m_op;
        double m_value;

        // Only to be used by non-numeric characters.
        int set_precedence(char c);

        bool is_binary_op(char c);

    public:
        // Made for compatability. Won't actually be used for processing. 
        // Only used to initialize an empty token that is to be reseated.
        // Or for any other similar process.
        Token();

        // Creates a token.
        Token(std::string num);

        // Returns `true` if `Token` is `TokenType::Operator`. `false` if it is an `TokenType::Operand`.
        bool is_operator();

        // Returns `true` if the instance has greater precedence.
        bool has_greater_precedence(Token target);

        // Returns `true` if `m_value` is `TokenType::None`
        bool is_invalid();

        // Only to be used when `m_type == TokenType::Operand`
        void update_value(int value);

        // Will return `int` or `char` based on `TokenType`.
        template <typename T>
        T get_value();
};

#endif
