//
// Created by BustDot on 2023/6/16.
//
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "AST.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#ifndef GREAT_BUCT_COMPILER_PARSER_H
namespace gbc::grammar {
  static int CurTok;
  static int getNextToken() { return CurTok = gettok(); }

/// BinopPrecedence - This holds the precedence for each binary operator that is
/// defined.
  static std::map<char, int> BinopPrecedence = {{'<', 10}, {'+', 20}, {'-', 20}, {'*', 40}};
  /// GetTokPrecedence - Get the precedence of the pending binary operator token.
  static int GetTokPrecedence() {
    if (!isascii(CurTok))
      return -1;

    // Make sure it's a declared binop.
    int TokPrec = BinopPrecedence[CurTok];
    if (TokPrec <= 0)
      return -1;
    return TokPrec;
  }

/// LogError* - These are little helper functions for error handling.
  std::unique_ptr<ExprAST> LogError(const char *Str) {
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
  }

  std::unique_ptr<PrototypeAST> LogErrorP(const char *Str) {
    LogError(Str);
    return nullptr;
  }

  static std::unique_ptr<ExprAST> ParseExpression();

/// numberexpr ::= number
  static std::unique_ptr<ExprAST> ParseNumberExpr() {
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken(); // consume the number
    return std::move(Result);
  }

/// parenexpr ::= '(' expression ')'
  static std::unique_ptr<ExprAST> ParseParenExpr() {
    getNextToken(); // eat (.
    auto V = ParseExpression();
    if (!V)
      return nullptr;

    if (CurTok != ')')
      return LogError("expected ')'");
    getNextToken(); // eat ).
    return V;
  }

/// identifierexpr
///   ::= identifier
///   ::= identifier '(' expression* ')'
  static std::unique_ptr<ExprAST> ParseIdentifierExpr() {
    std::string IdName = IdentifierStr;

    getNextToken(); // eat identifier.

    if (CurTok != '(') // Simple variable ref.
      return std::make_unique<VariableExprAST>(IdName);

    // Call.
    getNextToken(); // eat (
    std::vector<std::unique_ptr<ExprAST>> Args;
    if (CurTok != ')') {
      while (true) {
        if (auto Arg = ParseExpression())
          Args.push_back(std::move(Arg));
        else
          return nullptr;

        if (CurTok == ')')
          break;

        if (CurTok != ',')
          return LogError("Expected ')' or ',' in argument list");
        getNextToken();
      }
    }

    // Eat the ')'.
    getNextToken();

    return std::make_unique<CallExprAST>(IdName, std::move(Args));
  }

/// primary
///   ::= identifierexpr
///   ::= numberexpr
///   ::= parenexpr
  static std::unique_ptr<ExprAST> ParsePrimary() {
    switch (CurTok) {
      default:
        return LogError("unknown token when expecting an expression");
      case tok_identifier:
        return ParseIdentifierExpr();
      case tok_number:
        return ParseNumberExpr();
      case '(':
        return ParseParenExpr();
    }
  }

/// binoprhs
///   ::= ('+' primary)*
  static std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec,
                                                std::unique_ptr<ExprAST> LHS) {
    // If this is a binop, find its precedence.
    while (true) {
      int TokPrec = GetTokPrecedence();

      // If this is a binop that binds at least as tightly as the current binop,
      // consume it, otherwise we are done.
      if (TokPrec < ExprPrec)
        return LHS;

      // Okay, we know this is a binop.
      int BinOp = CurTok;
      getNextToken(); // eat binop

      // Parse the primary expression after the binary operator.
      auto RHS = ParsePrimary();
      if (!RHS)
        return nullptr;

      // If BinOp binds less tightly with RHS than the operator after RHS, let
      // the pending operator take RHS as its LHS.
      int NextPrec = GetTokPrecedence();
      if (TokPrec < NextPrec) {
        RHS = ParseBinOpRHS(TokPrec + 1, std::move(RHS));
        if (!RHS)
          return nullptr;
      }

      // Merge LHS/RHS.
      LHS =
          std::make_unique<BinaryExprAST>(BinOp, std::move(LHS), std::move(RHS));
    }
  }

/// expression
///   ::= primary binoprhs
///
  static std::unique_ptr<ExprAST> ParseExpression() {
    auto LHS = ParsePrimary();
    if (!LHS)
      return nullptr;

    return ParseBinOpRHS(0, std::move(LHS));
  }

/// prototype
///   ::= id '(' id* ')'
  static std::unique_ptr<PrototypeAST> ParsePrototype() {
    if (CurTok != tok_identifier)
      return LogErrorP("Expected function name in prototype");

    std::string FnName = IdentifierStr;
    getNextToken();

    if (CurTok != '(')
      return LogErrorP("Expected '(' in prototype");

    std::vector<std::string> ArgNames;
    while (getNextToken() == tok_identifier)
      ArgNames.push_back(IdentifierStr);
    if (CurTok != ')')
      return LogErrorP("Expected ')' in prototype");

    // success.
    getNextToken(); // eat ')'.

    return std::make_unique<PrototypeAST>(FnName, std::move(ArgNames));
  }

/// definition ::= 'def' prototype expression
  static std::unique_ptr<FunctionAST> ParseDefinition() {
    getNextToken(); // eat def.
    auto Proto = ParsePrototype();
    if (!Proto)
      return nullptr;

    if (auto E = ParseExpression())
      return std::make_unique<FunctionAST>(std::move(Proto), std::move(E));
    return nullptr;
  }

/// toplevelexpr ::= expression
  static std::unique_ptr<FunctionAST> ParseTopLevelExpr() {
    if (auto E = ParseExpression()) {
      // Make an anonymous proto.
      auto Proto = std::make_unique<PrototypeAST>("__anon_expr",
                                                  std::vector<std::string>());
      return std::make_unique<FunctionAST>(std::move(Proto), std::move(E));
    }
    return nullptr;
  }

/// external ::= 'extern' prototype
  static std::unique_ptr<PrototypeAST> ParseExtern() {
    getNextToken(); // eat extern.
    return ParsePrototype();
  }

}
#define GREAT_BUCT_COMPILER_PARSER_H

#endif //GREAT_BUCT_COMPILER_PARSER_H
