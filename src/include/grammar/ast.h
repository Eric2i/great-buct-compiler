//
// Created by Dysprosium on 2023/6/18.
//

#ifndef GREAT_BUCT_COMPILER_SRC_GRAMMAR_AST_H_
#define GREAT_BUCT_COMPILER_SRC_GRAMMAR_AST_H_

#include "grammar_parser.h"
namespace gbc::grammar {

class ASTNode {

  TokenId id;
  ASTNode *father{};
  std::vector<ASTNode *> children;
 public:
  explicit ASTNode(TokenId id) : id(id) {};
  ASTNode* BuildSubTreeFromProduction(Tokens children);
  void AddChild(ASTNode* &child);
  void Print();
  const std::vector<ASTNode *> &GetChildren() const;
};

} // gbc

#endif //GREAT_BUCT_COMPILER_SRC_GRAMMAR_AST_H_
