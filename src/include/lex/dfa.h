//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_DFA_H
#define GREAT_BUCT_COMPILER_DFA_H

#include "fa.h"
#include <map>
#include <set>
#include <vector>

typedef int state_type;
typedef int NFAState;
typedef char label_type;

namespace gbc {
namespace lex {

class DFA : public FA {

public:

    void NFA2DFA();
    void simplify();
};

} // lex
} // gbc

#endif //GREAT_BUCT_COMPILER_DFA_H