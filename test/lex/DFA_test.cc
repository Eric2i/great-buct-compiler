//
// Created by Eric2i Hsiung on 2023/6/17.
//

#include "../../src/include/lex/dfa.h"
#include <iostream>

namespace gbc::lex {
    bool rules_to_dfa_tester() {
        LexicalRules regex;
        regex.read_from_file("../test/lex/tokens.txt");
        regex.definition_to_expression();
        regex.infix_to_postfix();

        auto nfa = build_from_rules(regex);

        DFA dfa;
        dfa.NFA2DFA(nfa);

        dfa = DFAMinimize(dfa);
        show_DFA(dfa);
        return true;
    }
}