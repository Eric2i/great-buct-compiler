//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_TOKEN_H
#define GREAT_BUCT_COMPILER_TOKEN_H

#include <string>
#include "alphabet.h"

namespace gbc::lex {
    using token_id = long long;
    typedef std::string token_name;
    typedef std::string token_pattern;

    class Token {
    private:
        token_id _id;
        token_name _name;
        token_pattern _pattern;
    public:
        Token();
        Token(token_id, token_name, token_pattern);

        [[nodiscard]] token_id id() const;
        token_name name();
        token_pattern pattern();

        bool update_pattern(token_pattern);
        bool infix_to_postfix();
        bool operator<(const Token &X) const;
    };

    bool isRegexCharacter(char c);
} // gbc



#endif //GREAT_BUCT_COMPILER_TOKEN_H
