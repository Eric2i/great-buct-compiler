//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_DFA_H
#define GREAT_BUCT_COMPILER_DFA_H

#include <set>
#include <map>
#include <utility>
#include <vector>
#include "rules.h"
#include "alphabet.h"
#include "nfa.h"


namespace gbc::lex {
    using DFAState = std::set<int>;

    struct DFA {
        Alphabet alphabet;

        DFAState start;
        std::set<DFAState> accept;

        std::set<DFAState> Dstates;
        std::map<std::pair<DFAState, char>, DFAState> Dtrans;

        std::map<DFAState, Token> tokens;

        void NFA2DFA(NFA &);

        void MoveTokens(std::map<NFAState, Token> &);

        DFAState trans(DFAState &, char &);
    };

    DFA DFAMinimize(DFA &);

    DFAState epsilon_closure(DFAState, NFA &N);

    DFAState move(DFAState T, char a, NFA &N);

    void set_partition(std::set<DFAState> states, int id);

    void set_partition(DFAState s, int id);

    void remove_partition_byID(int id);

    std::set<std::set<DFAState>> subgroup(std::set<DFAState> G, DFA &D);

    std::vector<std::pair<Token, std::string>> DFASimulator(DFA &, std::string &);

    // DEBUG
    void show_DFA(DFA &);

    void show_tokens(DFA &);

    void print_Set(const std::set<int> &);

    void show_alphabet(std::set<char>);

    void show_partition_table();

    void subgrouping_report(std::set<DFAState>, std::set<std::set<DFAState> >);

    void show_vectorization(std::map<std::vector<int>, std::set<DFAState>> &);

    void make_mermaid(DFA &);
}
#endif //GREAT_BUCT_COMPILER_DFA_H
