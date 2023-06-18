//
// Created by Eric2i Hsiung on 2023/6/17.
//

#include "../../src/include/lex/lexical_analyzer.h"
#include <iostream>

namespace gbc::lex {
    auto lexical_analyzer_tester() {
        LexicalRules regex;
        std::cerr << "reading Lexical Rules..." << std::endl; regex.read_from_file("../test/lex/tokens.txt");
        std::cerr << "building NFA..." << std::endl; NFA nfa = build_from_rules(regex);
        std::cerr << "building DFA..." << std::endl; DFA dfa; dfa.NFA2DFA(nfa);
        std::cerr << "Minimizing DFA..." << std::endl;DFA minDFA = DFAMinimize(dfa);
//        show_DFA(minDFA);
        path src = "../test/lex/sourceCode.txt";
        LexicalAnalyzer analyzer(minDFA);
        std::cerr << "Parsing Source Codes..." << std::endl; auto result = analyzer.parse(src);
        return result;
    }
}