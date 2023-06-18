//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_NFA_H
#define GREAT_BUCT_COMPILER_NFA_H

#include <map>
#include <vector>
#include "FA.h"
#include "rules.h"

namespace gbc::lex {
    using NFAState = int;

    struct NFA {
        Alphabet alphabet;
        NFAState start{};  // initial state
        NFAState accept{}; // final state
        std::map<NFAState, Token> tokens;
        std::map<NFAState, State> states;
        NFA() = default;
    };


    NFA char2NFA(char c);

    NFA Union(NFA Ns, NFA Nt);

    NFA Concat(NFA Ns, NFA Nt);

    NFA KleenClosure(NFA N);

    NFA PositiveClosure(NFA N);

    void reset_state_counter();

    NFA build_from_rules(LexicalRules &rules);

    /*DEBUG*/
    void show_NFA(NFA &);

    int report_counter();
}

#endif //GREAT_BUCT_COMPILER_NFA_H
