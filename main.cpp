//
// Created by Dysprosium on 2023/6/5.
//

#include "test/lex/regex_test.cc"
#include "test/lex/NFA_test.cc"
#include "test/lex/DFA_test.cc"
#include "test/lex/analyzer_test.cc"

#include <fstream>
#include <iostream>

int main() {
//    LexicalRulesTester();
//    gbc::lex::nfa_tester();
//    gbc::lex::rules_to_dfa_tester();
    gbc::lex::lexical_analyzer_tester();
    return 0;
}