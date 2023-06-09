//
// Created by Dysprosium on 2023/6/5.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "src/include/grammar/grammar_parser.h"

//int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }
//
//TEST_CASE("testing the factorial function") {
//
//  std::ifstream f("syntax_rules_path");
//  nlohmann::json data = nlohmann::json::parse(f);
//CHECK(factorial(1) == 1);
//CHECK(factorial(2) == 2);
//CHECK(factorial(3) == 6);
//CHECK(factorial(10) == 3628800);
//}
//


int main() {
  gbc::grammar::GrammarParser parser = gbc::grammar::GrammarParser("../test/syntax_demo.json");
  parser.Print(gbc::grammar::GrammarParser::TOKENS);
  parser.Print(gbc::grammar::GrammarParser::TERMINALS);
  parser.Print(gbc::grammar::GrammarParser::NON_TERMINALS);
  parser.Print(gbc::grammar::GrammarParser::TOKEN_MAP);
  parser.Print(gbc::grammar::GrammarParser::PRODUCTIONS);
}