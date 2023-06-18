//
// Created by Dysprosium on 2023/6/5.
//

#ifndef GREAT_BUCT_COMPILER_SRC_GRAMMAR_LL_1_PARSER_H_
#define GREAT_BUCT_COMPILER_SRC_GRAMMAR_LL_1_PARSER_H_
#include "grammar_parser.h"
#include "unordered_map"
#include "ast.h"
namespace gbc::grammar {

using FirstOrFollowSet = std::unordered_map<TokenId, std::set<TokenId>>;
using SelectTable = std::unordered_map<TokenId, std::unordered_map<TokenId, std::pair<TokenId, std::vector<TokenId>>>>;

// The LL1 parser extends Grammar Parser and is used to define
// whether a serial of tokens_ from Lex is conformed to the syntax rules
class LL1Parser : public GrammarParser {

 public:
  FirstOrFollowSet first_;
  FirstOrFollowSet follow_;
  SelectTable select_;

 public:
  explicit LL1Parser(const std::string &s) : GrammarParser(s) {};
 public:
  // Eliminate left recursive
  // It is based on the A -> Aa | b which is equivalent to the following productions
  // A -> bA' and A' -> aA' | e
  void Preprocess() override;

  // Get first set
  void GetFirst();

  // Get follow set
  void GetFollow();

  // Build analysis table
  void BuildAnalysisTable() override;

  // Analyze whether a serial of tokens live up to the syntax rules
  void Analyze(Tokens tokens) override;
  void AnalyzeLL1();

  enum LL1PrintOption {
    FIRST = 0,
    FOLLOW = 1,
    SELECT = 2,
  };
  void LL1Print(LL1PrintOption option);
};

} // grammar

#endif //GREAT_BUCT_COMPILER_SRC_GRAMMAR_LL_1_PARSER_H_
