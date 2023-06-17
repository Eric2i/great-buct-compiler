//
// Created by Dysprosium on 2023/6/5.
//

#ifndef GREAT_BUCT_COMPILER_SRC_GRAMMAR_GRAMMAR_PARSER_H_
#define GREAT_BUCT_COMPILER_SRC_GRAMMAR_GRAMMAR_PARSER_H_

#include <set>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include "../lex/token.h"

namespace gbc::grammar {

using TokenId = long long;
using Tokens = std::vector<lex::Token>;
using TokenStringSet = std::set<std::string>;
using TokenSet = std::set<TokenId>;
using TokenMap = std::map<std::string, TokenId>;
using TokenMapRe = std::map<TokenId, std::string>;
using Production = std::map<TokenId, std::vector<std::vector<TokenId>>>;

class GrammarParser {

 public:
  enum SpecialToken {
    EPSILON = -1, // The token id of epsilon
    EOT = -2      // The token id of end of text
  };
  [[maybe_unused]] TokenId start_ = 0; // The token id of the start
  TokenStringSet tokens_; // The token set which contains token in string
  TokenSet terminals_; // Terminals
  TokenSet non_terminals_; // Non-Terminals
  // The map which map a token string with the token id and its reverse version
  // Example: { "A": 0, "B": 1 }
  TokenMap token_map_;
  TokenMapRe token_map_re_;

  // The left part of production is the token id of the left.
  // The right part of the production is the vector of possible products,
  // and the product is a vector of token ids accordingly.
  // Example: real production A -> aA | b
  //          token map: { "A": 0, "a": 1, "b": 2 }
  //          production: {0: [[1, 0], 2]}
  Production productions;
 public:

  // TODO: The relative path of syntax rule file
  std::string syntax_rules_path = "../test/syntax_demo.json";

 public:
  explicit GrammarParser(std::string s) {
    syntax_rules_path = std::move(s);
    std::ifstream f(syntax_rules_path);
    nlohmann::json data = nlohmann::json::parse(f);

    std::map<std::string, std::vector<std::vector<std::string>>> temp_productions;
    for (const auto &rule : data["rules"]) {
      TokenId non_terminal_id = tokens_.size();
      token_map_.insert({rule["name"], non_terminal_id});
      token_map_re_.insert({non_terminal_id, rule["name"]});
      non_terminals_.insert(non_terminal_id);
      tokens_.insert(rule["name"]);
      for (const auto &production : rule["productions"]) {
        std::vector<std::string> right;
        for (const auto &symbol : production["symbols"]) {
          right.push_back(symbol["value"]);
          if (symbol["type"] == "terminal") {
            if (auto res = tokens_.find(symbol["value"]); res == tokens_.end()) {
              TokenId terminal_id = tokens_.size();
              token_map_.insert({symbol["value"], terminal_id});
              token_map_re_.insert({terminal_id, symbol["value"]});
              terminals_.insert(terminal_id);
              tokens_.insert(symbol["value"]);
            }
          }
        }
        temp_productions[rule["name"]].push_back(right);
      }
    }

    token_map_.insert({std::string(), EPSILON});
    token_map_re_.insert({EPSILON, std::string()});
    token_map_.insert({"$", EOT});
    token_map_re_.insert({EOT, "$"});

    for (const auto &[nt, symbols] : temp_productions) {
      for (const auto &symbol : symbols) {
        std::vector<TokenId> right;
        for (const auto &item : symbol) {
          if (item == "epsilon") {
            right.push_back(EPSILON);
          } else {
            right.push_back(token_map_[item]);
          }

        }
        productions[token_map_[nt]].push_back(right);
      }
    }

  }

  bool IsTerminal(TokenId id);
  bool IsNonTerminal(TokenId id);

 public:
  enum PrintOption {
    TOKENS = 0,
    TERMINALS = 1,
    NON_TERMINALS = 2,
    TOKEN_MAP = 3,
    PRODUCTIONS = 4
  };
  void Print(PrintOption option);
 public:
  virtual void Preprocess() = 0;
  virtual void BuildAnalysisTable() = 0;
  virtual void Analyze(Tokens tokens) = 0;
};

} // gbc

#endif //GREAT_BUCT_COMPILER_SRC_GRAMMAR_GRAMMAR_PARSER_H_
