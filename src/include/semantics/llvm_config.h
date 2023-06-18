//
// Created by Dysprosium on 2023/6/18.
//

#ifndef GREAT_BUCT_COMPILER_SRC_INCLUDE_SEMANTICS_LLVM_CONFIG_H_
#define GREAT_BUCT_COMPILER_SRC_INCLUDE_SEMANTICS_LLVM_CONFIG_H_

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include <map>

class LLVMConfig {
 public:
  LLVMConfig() = default;
 public:
  static std::unique_ptr<llvm::LLVMContext> TheContext;
  static std::unique_ptr<llvm::Module> TheModule;
  static std::unique_ptr<llvm::IRBuilder<>> Builder;
  static std::map<std::string, llvm::Value *> NamedValues;
};


auto LLVMConfig::TheContext = std::make_unique<llvm::LLVMContext>();
auto LLVMConfig::TheModule = std::make_unique<llvm::Module>("my cool jit", *LLVMConfig::TheContext);
auto LLVMConfig::Builder = std::make_unique<llvm::IRBuilder<>>(*LLVMConfig::TheContext);
std::map<std::string, llvm::Value *> LLVMConfig::NamedValues = {};
#endif //GREAT_BUCT_COMPILER_SRC_INCLUDE_SEMANTICS_LLVM_CONFIG_H_
