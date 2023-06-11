//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_REGEX_H
#define GREAT_BUCT_COMPILER_REGEX_H

#include "token.h"
#include <map>
#include <vector>

namespace gbc::lex {
    using path = std::string;

    class Regex {
    private:
        std::vector<Token> _tokens;
        std::map<token_name, token_pattern> name2pattern;

    public:
        bool read_from_file(path);
        token_pattern expand(token_pattern);
        bool definition_to_expression();
        bool infix_to_postfix();
        std::vector<Token> tokens();
        void debug();
    };

    void regex_class_tester();
} // gbc namespace


#endif //GREAT_BUCT_COMPILER_REGEX_H
