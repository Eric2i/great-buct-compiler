//
// Created by Dysprosium on 2023/6/5.
//

#include "../include/grammar/ll_1_parser.h"
#include "spdlog/spdlog.h"

namespace gbc::grammar {

void LL1Parser::Preprocess() {
  spdlog::info("[Preprocess to eliminate left recursive]");
  for (auto &[left, right] : productions) {
    std::vector<std::vector<TokenId>> alpha_productions;
    std::vector<std::vector<TokenId>> beta_productions;
    bool left_recursive = false;
    std::string a_prime;
    TokenId a_prime_id;
    std::vector<std::vector<TokenId>> alphas;
    std::vector<std::vector<TokenId>> betas;
    for (const auto &item : right) {
      std::vector<TokenId> alpha;
      std::vector<TokenId> beta;
      if (item[0] == left) {
        left_recursive = true;
        a_prime = token_map_re_[item[0]] + "'";
        if (auto res = token_map_.find(a_prime); res != token_map_.end()) {
          a_prime_id = res->second;
        } else {
          a_prime_id = tokens_.size();
          token_map_.insert({a_prime, a_prime_id});
          token_map_re_.insert({a_prime_id, a_prime});
          non_terminals_.insert(a_prime_id);
        }
        tokens_.insert(a_prime);
        for (int i = 1; i < item.size(); ++i) {
          alpha.push_back(item[i]);
        }
      } else {
        for (unsigned long i : item) {
          beta.push_back(i);
        }
      }
      if (!alpha.empty()) {
        alphas.push_back(alpha);
      } else if (!beta.empty()) {
        betas.push_back(beta);
      }
    }
    if (left_recursive) {
      for (auto &item : betas) {
        item.push_back(a_prime_id);
      }
      for (auto &item : alphas) {
        item.push_back(a_prime_id);
      }
      alphas.push_back(std::vector<TokenId>{EPSILON});
      productions[a_prime_id] = alphas;
      productions[left] = betas;
    } else {
      continue;
    }
  }
}

void LL1Parser::GetFirst() {
  spdlog::info("[Getting the first set of every token]");
  bool changed = true;
  while (changed) {
    changed = false;
    for (const auto &[left, right] : productions) {
      if (IsNonTerminal(left)) {
        std::set<TokenId> non_terminal_first;
        if (auto res = first_.find(left); res != first_.end()) {
          non_terminal_first = first_[left];
        }
        for (const auto &i : right) {
          for (unsigned long j : i) {
            bool no_epsilon = true;
            if (IsTerminal(j) or j == EPSILON) {
              if (auto res = non_terminal_first.find(j); res
                  == non_terminal_first.end()) {
                if (j == EPSILON) {
                  no_epsilon = false;
                }
                changed = true;
                non_terminal_first.insert(j);
              }
            }
            if (auto res = first_.find(j); res != first_.end()) {
              for (const auto &item : res->second) {
                if (item != EPSILON) {
                  if (auto find = non_terminal_first.find(item); find
                      == non_terminal_first.end()) {
                    changed = true;
                    non_terminal_first.insert(item);
                  }
                }
              }
            }
            if (no_epsilon) {
              break;
            }
          }
        }
        first_[left] = non_terminal_first;
      }
    }
  }
}
void LL1Parser::GetFollow() {
  spdlog::info("[Getting the follow set of every token]");
  bool changed = true;
  follow_[0].insert(EOT);
  while (changed) {
    changed = false;
    for (const auto &[left, right] : productions) {
      for (const auto &item : right) {
        for (int i = 0; i < item.size(); ++i) {
          // If the token is non-terminal, put the first set of the following token into the follower set
          if (IsNonTerminal(item[i])) {
            // Get the follow set of the item
            std::set<TokenId> non_terminal_follow;
            if (auto res = first_.find(left); res != first_.end()) {
              non_terminal_follow = follow_[item[i]];
            }
            bool contain_epsilon = false;
            if (i != (item.size() - 1)) {
              if (IsNonTerminal(item[i + 1])) {
                for (const auto &f : first_[item[i + 1]]) {
                  if (f == EPSILON) {
                    contain_epsilon = true;
                  } else if (auto res = non_terminal_follow.find(f); f != EPSILON
                      and res == non_terminal_follow.end()) {
                    changed = true;
                    non_terminal_follow.insert(f);
                  }
                }
              } else if (auto res = non_terminal_follow.find(item[i + 1]); res == non_terminal_follow.end()) {
                changed = true;
                non_terminal_follow.insert(item[i + 1]);
              }
            }
            if ((i == (item.size() - 1)) or contain_epsilon) {
              if (!follow_[left].empty()) {
                for (const auto &left_follower : follow_[left]) {
                  if (auto res = non_terminal_follow.find(left_follower); res == non_terminal_follow.end()) {
                    changed = true;
                    non_terminal_follow.insert(left_follower);
                  }
                }
              }
            }
            follow_[item[i]] = non_terminal_follow;
          }
        }
      }
    }
  }

}
void LL1Parser::BuildAnalysisTable() {
  spdlog::info("[Building the analysis table]");
  for (const auto &[left, right] : productions) {
    for (const auto &item : right) {
      if (item[0] != EPSILON) {
        if (IsNonTerminal(item[0])) {
          for (const auto &f : first_[item[0]]) {
            select_[left][f] = std::make_pair(left, item);
          }
        } else {
          select_[left][item[0]] = std::make_pair(left, item);
        }
      } else {
        for (const auto &f : follow_[left]) {
          select_[left][f] = std::make_pair(left, item);
        }
      }
    }
  }
}

// TODO Whether tokens should from syntax rules or regex?
void LL1Parser::Analyze(Tokens tokens) {
  spdlog::info("[Analyze tokens]");
  std::vector<size_t> tks{3, 4, 5, 6, 7, 3, 4, 15, 4, 14, 16, 4, 14, 8};
  std::deque<size_t> analysis_stack;
  analysis_stack.push_back(EOT);
  analysis_stack.push_front(0);
  int p = 0;
  while (!analysis_stack.empty()) {
    if (analysis_stack.front() == EPSILON) {
      analysis_stack.pop_front();
    }
    if (analysis_stack.front() != tks[p]) {
      auto production = select_[analysis_stack.front()][tks[p]];
      auto right = production.second;
      analysis_stack.pop_front();
      std::reverse(right.begin(), right.end());
      for (const auto &item : right) {
        analysis_stack.push_front(item);
      }
    } else if (analysis_stack.front() == tks[p]) {
      analysis_stack.pop_front();
      p++;
    }
  }
  if (p == tokens.size()) {
    std::cout << "success" << std::endl;
  }
}

void LL1Parser::LL1Print(LL1PrintOption option) {

  switch (option) {
    case FIRST:spdlog::info("[FIRST]");
      for (const auto &[k, v] : first_) {
        spdlog::info("FIRST({}): ", token_map_re_[k]);
        for (const auto &item : v) {
          spdlog::info(token_map_re_[item]);
        }
      }
      break;
    case FOLLOW:spdlog::info("[FOLLOW]");
      for (const auto &[k, v] : follow_) {
        spdlog::info("FOLLOW({}): ", token_map_re_[k]);
        for (const auto &item : v) {
          spdlog::info(token_map_re_[item]);
        }
      }
      break;
    case SELECT:spdlog::info("[SELECT]");
      for (const auto &nt : select_) {
        for (const auto &t : nt.second) {
          std::string production = token_map_re_[t.second.first] + " - > ";
          std::for_each(t.second.second.begin(), t.second.second.end(), [&](TokenId id) {
            production += token_map_re_[id] + " ";
          });
          spdlog::info("[{}, {}]: {}", token_map_re_[nt.first], token_map_re_[t.first], production);
        }
      }
      break;
  }
}
void LL1Parser::AnalyzeLL1() {
  spdlog::info("[Analyze tokens]");
  // int main() {int x = 1; return 0;}
//  std::vector<size_t> tks{3, 4, 5, 6, 7, 3, 4, 15, 4, 14, 16, 4, 14, 8};
  std::vector<size_t> tks{3, 4, 5, 6, 7, 3, 4, 15, 4, 14, 16, 4, 14, 8, 14, 15, 16};
  std::deque<size_t> analysis_stack;
  analysis_stack.push_back(EOT);
  analysis_stack.push_front(0);
  int p = 0;
  while (!analysis_stack.empty()) {
    if (analysis_stack.front() == EPSILON) {
      analysis_stack.pop_front();
    }
    if (analysis_stack.front() != tks[p]) {
      auto production = select_[analysis_stack.front()][tks[p]];
      auto right = production.second;
      analysis_stack.pop_front();
      std::reverse(right.begin(), right.end());
      for (const auto &item : right) {
        analysis_stack.push_front(item);
      }
    } else if (analysis_stack.front() == tks[p]) {
      analysis_stack.pop_front();
      p++;
    }
  }
  if (p == tks.size()) {
    spdlog::info("SUCCESS");
  } else {
    spdlog::error("ERROR OCCURRED WHEN DOING THE GRAMMAR ANALYSIS");
    std::string input{};
    for (int i = 0; i < tks.size(); ++i) {
      if (i == p) {
        input += "[error] ";
      }
      input += token_map_re_[tks[i]] + " ";
    }
    spdlog::warn("You have an error in your syntax");
    spdlog::warn("the error may happens here: {}", input);
  }
}

} // grammar