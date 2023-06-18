//
// Created by Dysprosium on 2023/6/18.
//

#ifndef GREAT_BUCT_COMPILER_SRC_INCLUDE_SEMANTICS_NUMBER_AST_H_
#define GREAT_BUCT_COMPILER_SRC_INCLUDE_SEMANTICS_NUMBER_AST_H_

#include "../grammar/ast.h"

namespace gbc::semantic {
 class NumberAST: public grammar::ASTNode{
  public:
   explicit NumberAST(grammar::TokenId id);
  private:
   llvm::Value *CodeGen() ;
};
}

#endif //GREAT_BUCT_COMPILER_SRC_INCLUDE_SEMANTICS_NUMBER_AST_H_
