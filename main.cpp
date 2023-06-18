//
// Created by Dysprosium on 2023/6/5.
//

//#include "test/lex/regex_test.cc"
//#include "test/lex/NFA_test.cc"
//#include "test/lex/DFA_test.cc"
//#include "test/lex/analyzer_test.cc"
#include "src/include/grammar/ll_1_parser.h"
#include "src/include/lex/lexical_analyzer.h"
#include <fstream>
#include <iostream>

auto lexical() {
  gbc::lex::LexicalRules regex;
  std::cerr << "reading Lexical Rules..." << std::endl;
  regex.read_from_file("../test/lex/tokens.txt");
  std::cerr << "building NFA..." << std::endl;
  gbc::lex::NFA nfa = build_from_rules(regex);
  std::cerr << "building DFA..." << std::endl;
  gbc::lex::DFA dfa;
  dfa.NFA2DFA(nfa);
  std::cerr << "Minimizing DFA..." << std::endl;
  gbc::lex::DFA minDFA = DFAMinimize(dfa);
//        show_DFA(minDFA);
  gbc::lex::path src = "../test/lex/sourceCode.txt";
  gbc::lex::LexicalAnalyzer analyzer(minDFA);
  std::cerr << "Parsing Source Codes..." << std::endl;
  auto result = analyzer.parse(src);
  return result;
}

auto grammar_analyzer_tester() {
  auto res = lexical();
  gbc::grammar::LL1Parser parser = gbc::grammar::LL1Parser("../test/syntax_rule.json");

  parser.Print(gbc::grammar::GrammarParser::PRODUCTIONS);
  parser.Preprocess();
  parser.Print(gbc::grammar::GrammarParser::TOKENS);
  parser.Print(gbc::grammar::GrammarParser::TERMINALS);
  parser.Print(gbc::grammar::GrammarParser::NON_TERMINALS);
  parser.Print(gbc::grammar::GrammarParser::TOKEN_MAP);
  parser.Print(gbc::grammar::GrammarParser::PRODUCTIONS);
  parser.GetFirst();
  parser.LL1Print(gbc::grammar::LL1Parser::FIRST);
  parser.GetFollow();
  parser.LL1Print(gbc::grammar::LL1Parser::FOLLOW);
  parser.BuildAnalysisTable();
  parser.LL1Print(gbc::grammar::LL1Parser::SELECT);

  std::vector<gbc::lex::Token> tks{};
  for (const auto &i : res) {
    for (const auto &tk : i) {
      tks.push_back(tk);
    }
  }

  parser.Analyze(tks);
}

int main() {
//    LexicalRulesTester();
//    gbc::lex::nfa_tester();
//    gbc::lex::rules_to_dfa_tester();
//    gbc::lex::lexical_analyzer_tester();
  grammar_analyzer_tester();
  return 0;
}