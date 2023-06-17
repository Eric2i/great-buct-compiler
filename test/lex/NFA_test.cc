//
// Created by Eric2i Hsiung on 2023/6/17.
//

#include "../../src/include/lex/nfa.h"

namespace gbc::lex {
    bool nfa_tester() {
        reset_state_counter();
        // create several NFAs
        NFA n1 = char2NFA('a');
        NFA n2 = char2NFA('b');
        NFA uni = Union(n1, n2);
        NFA cat = Concat(n1, n2);
        NFA Star = KleenClosure(n1);
        NFA Pos = PositiveClosure(n2);

        // report maximum number of nodes
        std::cerr << "number of nodes: " << report_counter() << std::endl << std::endl;

        // show each NFA
        show_NFA(n1);
        // 0-a->1

        show_NFA(n2);
        // 2-b->3

        show_NFA(uni);
        // 0-a->1
        // 1-!->5
        // 2-b->3
        // 3-!->5
        // 4-!->0
        // 4-!->2

        show_NFA(cat);
        // 0-a->1
        // 1-!->2
        // 2-b->3
        // 3-!->7
        // 6-!->0

        show_NFA(Star);
        // 0-a->1
        // 1-!->0
        // 1-!->9
        // 8-!->0
        // 8-!->9

        show_NFA(Pos);
        // 2-b->3
        // 3-!->2
        // 3-!->11
        // 10-!->2
        return true;
    }
}