//
// Created by Dysprosium on 2023/6/5.
//

#ifndef GREAT_BUCT_COMPILER_SRC_GRAMMAR_LL_1_PARSER_H_
#define GREAT_BUCT_COMPILER_SRC_GRAMMAR_LL_1_PARSER_H_
#include "grammar_parser.h"

namespace gbc::grammar {

// The LL1 parser extends Grammar Parser and is used to define
// whether a serial of tokens_ from Lex is conformed to the syntax rules
class LL1Parser : GrammarParser {

// public:
//  // Eliminate left recursive
//  void Preprocess() override;
//
//  void GetFirst();
//
//  void GetFollower();
//
//  // Build analysis table
//  void BuildAnalysisTable() override;
//
//  // Analyze whether
//  void Analyze() override;
};

} // grammar

#endif //GREAT_BUCT_COMPILER_SRC_GRAMMAR_LL_1_PARSER_H_
