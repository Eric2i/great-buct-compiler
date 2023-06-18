//
// Created by Dysprosium on 2023/6/18.
//

#include "../include/grammar/ast.h"
#include "../include/semantics/llvm_config.h"
#include <charconv>

namespace gbc::grammar {

void ASTNode::AddChild(ASTNode *&child, ASTNode *&father) {
  child->father = father;
  this->children.push_back(child);
}

void ASTNode::Print() {
  std::deque<ASTNode *> q;
  q.push_back(this);
  while (!q.empty()) {
    auto f = q.front();
    q.pop_front();
    for (const auto &child : f->children) {
      q.push_back(child);
      std::cout << f->id << " -> " << child->id << std::endl;
    }
    std::cout << std::endl;
  }
}

const std::vector<ASTNode *> &ASTNode::GetChildren() const {
  return children;
}
llvm::Value *ASTNode::CodeGen() {
  switch (type_) {
    case Type::NUMBER: {
      auto token = this->tokens_[this->id];
      token.SetValue(token.unknown());
      int result{};
      std::from_chars(token.value().data(), token.value().data() + token.value().size(), result);
      double db = result;
      return llvm::ConstantFP::get(*LLVMConfig::TheContext, llvm::APFloat(db));
    }
    case Type::BINARY: {
      llvm::Value *L = lhs_->CodeGen();
      llvm::Value *R = rhs_->CodeGen();
      if (!L || !R)
        return nullptr;
      switch (op) {
        case '+':return LLVMConfig::Builder->CreateFAdd(L, R, "addtmp");
        case '-':return LLVMConfig::Builder->CreateFSub(L, R, "subtmp");
        case '*':return LLVMConfig::Builder->CreateFMul(L, R, "multmp");
        case '<':L = LLVMConfig::Builder->CreateFCmpULT(L, R, "cmptmp");
          // Convert bool 0/1 to double 0.0 or 1.0
          return LLVMConfig::Builder->CreateUIToFP(L, llvm::Type::getDoubleTy(*LLVMConfig::TheContext), "booltmp");
      }
    }
    case Type::VARIABLE: {
      auto token = this->tokens_[this->id];
      llvm::Value *V = LLVMConfig::NamedValues[token.unknown()];
      return V;

    }
    case Type::CALL:break;
    case Type::PROTOTYPE:break;
    case Type::FUNCTION:break;

      LLVMConfig::TheModule->print(llvm::errs(), nullptr);

  }
}
} // gbc
