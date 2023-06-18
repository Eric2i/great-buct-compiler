////
//// Created by Dysprosium on 2023/6/18.
////
//
//#include "../include/semantics/number_ast.h"
//#include "../include/semantics/llvm_config.h"
//#include <charconv>
//
//static std::unique_ptr<llvm::LLVMContext> TheContext;
//static std::unique_ptr<llvm::Module> TheModule;
//static std::unique_ptr<llvm::IRBuilder<>> Builder;
//static std::map<std::string, llvm::Value *> NamedValues;
//
//llvm::Value *gbc::semantic::NumberAST::CodeGen() {
//  auto token = this->map_[this->id];
//  token.SetValue(token.unknown());
//  int result{};
//  std::from_chars(token.value().data(), token.value().data() + token.value().size(), result);
//  double db = result;
//  return llvm::ConstantFP::get(*LLVMConfig::TheContext, llvm::APFloat(db));
//}
//
//gbc::semantic::NumberAST::NumberAST(gbc::grammar::TokenId id) : ASTNode(id) {}
