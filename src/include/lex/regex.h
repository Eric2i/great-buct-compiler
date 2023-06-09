//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_REGEX_H
#define GREAT_BUCT_COMPILER_REGEX_H

#include "token.h"
#include <map>

namespace gbc::lex {
    typedef long long regex_id;
    typedef std::string path;

    class Regex {
    private:
        std::vector<Token> tokens;
        std::map<token_name, token_pattern> name2pattern;

    public:
        bool read_from_file(path);
        token_pattern expand(token_pattern);
        bool definition_to_expression();
        bool infix_to_postfix();
        void debug();
    };

    void regex_class_tester();
} // gbc namespace


#endif //GREAT_BUCT_COMPILER_REGEX_H
