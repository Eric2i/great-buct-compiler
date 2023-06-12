//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_DFA_H
#define GREAT_BUCT_COMPILER_DFA_H

#include "fa.h"
#include "token.h"

namespace gbc::lex {

class DFA : public FA {

private:
    std::vector<std::vector<Token>> _tokens;

public:
    std::vector<std::vector<Token>> get_tokens();

};

} // gbc

#endif //GREAT_BUCT_COMPILER_DFA_H
