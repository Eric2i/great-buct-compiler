//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_NFA_H
#define GREAT_BUCT_COMPILER_NFA_H

#include "fa.h"
#include "graph.h"
#include <set>
#include <stack>
#include <map>
#include <string>
#include <vector>

typedef int state_type;
typedef char label_type;

namespace gbc {
namespace lex {

class NFA: public FA {

public:

    std::vector<std::set<state_type>> _dfaStates;
    std::stack<char> _operatorStack;

    NFA(const std::string &regex);

    void calculate();

};

} // lex
} // gbc


#endif //GREAT_BUCT_COMPILER_NFA_H