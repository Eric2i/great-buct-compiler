//
// Created by Dysprosium on 2023/6/18.
//

#ifndef GREAT_BUCT_COMPILER_SRC_GRAMMAR_AST_H_
#define GREAT_BUCT_COMPILER_SRC_GRAMMAR_AST_H_

#include "grammar_parser.h"
#include <deque>
#include <utility>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"

namespace gbc::grammar {

class ASTNode {

 public:
  enum class Type {
    UNDEFINED,
    NUMBER,
    VARIABLE,
    BINARY,
    CALL,
    PROTOTYPE,
    FUNCTION,
  };

 public:
  TokenId id;
  ASTNode *father{};
  std::vector<ASTNode *> children;
  TokenIdMap map_;
  Type type_;
  Tokens tokens_;

 public:
  ASTNode* lhs_;
  ASTNode* rhs_;
  char op;

 public:
  explicit ASTNode(TokenId id) : id(id) {};
  ASTNode(TokenId id, Tokens tokens) : id(id), tokens_(std::move(tokens)) {}
  void AddChild(ASTNode* &child, ASTNode* &father);
  void Print();
  const std::vector<ASTNode *> &GetChildren() const;

  llvm::Value *CodeGen();
};

} // gbc

#endif //GREAT_BUCT_COMPILER_SRC_GRAMMAR_AST_H_
