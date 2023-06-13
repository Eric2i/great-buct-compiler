//
// Created by Dysprosium on 2023/6/5.
//

#include "spdlog/spdlog.h"
#include "../include/grammar/grammar_parser.h"

namespace gbc::grammar {

bool GrammarParser::IsTerminal(TokenId id) {
  return terminals_.find(id) != terminals_.end();
}

bool GrammarParser::IsNonTerminal(TokenId id) {
  return non_terminals_.find(id) != non_terminals_.end();

}
void GrammarParser::Print(GrammarParser::PrintOption option) {
  switch (option) {
    case TOKENS:
      spdlog::info("[Tokens]");
      for (const auto &item : tokens_) {
        spdlog::info(item);
      }
      break;
    case TERMINALS:
      spdlog::info("[Terminals]");
      for (const auto &item : terminals_) {
        spdlog::info("token id: {}, token: {}",item, token_map_re_[item]);
      }
      break;
    case NON_TERMINALS:
      spdlog::info("[Non-Terminals]");
      for (const auto &item : non_terminals_) {
        spdlog::info("token id: {}, token: {}", item, token_map_re_[item]);
      }
      break;
    case TOKEN_MAP:
      spdlog::info("[Token map]");
      for (const auto &[k, v] : token_map_) {
        spdlog::info("token id: {}, token: {}", v, k);
      }
      break;
    case PRODUCTIONS:
      spdlog::info("[Productions]");
      for (const auto &[nt, symbols] : productions) {
        std::string left = token_map_re_[nt];
        for (const auto &symbol : symbols) {
          std::string right;
          for (const auto &item : symbol) {
            right += token_map_re_[item] + " ";
          }
          spdlog::info("{} -> {}", left, right);
        }
      }
      break;
  }
}

} // gbc

