//
// Created by Eric2i Hsiung on 2023/6/3.
//

#ifndef GREAT_BUCT_COMPILER_FA_H
#define GREAT_BUCT_COMPILER_FA_H

#include "graph.h"
#include <vector>
#include <map>
#include <set>

typedef int state_type;
typedef char label_type;
typedef int state_number;

namespace gbc {
namespace lex {

class FA {

public:

    state_number _countState;

    std::vector<state_type> _endState;
    std::vector<state_type> _startState;

    std::vector<label_type> _supportChar;

    std::vector<std::map<label_type, std::set<state_type>>> _faTable;

    std::map<state_type, std::vector<state_type>> _nextState;
    std::map<state_type, std::vector<label_type>> _nextEdge;

    std::set<state_type> epsilonExtend(const std::set<state_type> x);
    std::set<state_type> moveFromAState(const state_type x, const label_type c);
    std::set<state_type> moveFromASetOfState(const std::set<state_type> x, const label_type c);

    void findNextState(const state_type x);
    void findNextEdge(const state_type x);

    void printFA();
    void printEndState();
    void printStartState();
    void printCharSet();

};

} // lex
} // gbc


#endif //GREAT_BUCT_COMPILER_FA_H