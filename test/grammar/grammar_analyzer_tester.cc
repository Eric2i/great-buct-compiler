//
// Created by Dysprosium on 2023/6/18.
//
#include "../../src/include/grammar/ll_1_parser.h"
#include "../../src/include/lex/lexical_analyzer.h"

namespace gbc ::grammar {
auto lexical() {
  lex::LexicalRules regex;
  std::cerr << "reading Lexical Rules..." << std::endl;
  regex.read_from_file("../test/lex/tokens.txt");
  std::cerr << "building NFA..." << std::endl;
  lex::NFA nfa = build_from_rules(regex);
  std::cerr << "building DFA..." << std::endl;
  lex::DFA dfa;
  dfa.NFA2DFA(nfa);
  std::cerr << "Minimizing DFA..." << std::endl;
  lex::DFA minDFA = DFAMinimize(dfa);
//        show_DFA(minDFA);
  lex::path src = "../test/lex/sourceCode.txt";
  lex::LexicalAnalyzer analyzer(minDFA);
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

  std::vector<lex::Token> tks{};
  for (const auto &i : res) {
    for (const auto &tk : i) {
      tks.push_back(tk);
    }
  }

  parser.Analyze(tks);
}

} // gbc::grammar
