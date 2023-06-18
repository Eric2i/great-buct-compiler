//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_TOKEN_H
#define GREAT_BUCT_COMPILER_TOKEN_H

#include <string>
#include "alphabet.h"

namespace gbc::lex {
    using token_id = long long;
    using token_name = std::string;
    using token_pattern = std::string;
    using attribute_t = std::string;

    class Token {
    public:
        Token();

        Token(token_id, token_name, token_pattern);

        [[nodiscard]] token_id id() const;

        token_name name();

        token_pattern pattern();

        attribute_t type();

        attribute_t value();

        bool update_pattern(token_pattern);

        bool infix_to_postfix();

        bool operator<(const Token &X) const;

    private:
        token_id _id;
        token_name _name;
        token_pattern _pattern;
        attribute_t _type;
        attribute_t _value;
    };

    bool isRegexCharacter(char c);
} // gbc



#endif //GREAT_BUCT_COMPILER_TOKEN_H
