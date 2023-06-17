//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_NFA_H
#define GREAT_BUCT_COMPILER_NFA_H

#include <map>
#include <vector>
#include "FA.h"

namespace gbc::lex {

    struct NFA {
        int start;  // initial state
        int accept; // final state
        std::map<int, State> states;
    };

    NFA char2NFA(char c);

    NFA Union(NFA Ns, NFA Nt);

    NFA Concat(NFA Ns, NFA Nt);

    NFA KleenClosure(NFA N);

    NFA PositiveClosure(NFA N);

    void reset_state_counter();

/*DEBUG*/
    void show_NFA(NFA &);

    int report_counter();
}

#endif //GREAT_BUCT_COMPILER_NFA_H
