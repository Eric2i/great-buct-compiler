//
// Created by Eric2i Hsiung on 2023/6/17.
//

#include "../include/lex/dfa.h"
#include <stack>
#include <iostream>
#include <fstream>

namespace gbc::lex {
    const char EPSILON = '\0';

    void DFA::NFA2DFA(NFA &N) {
        this->start = epsilon_closure(DFAState({N.start}), N);
        this->Dstates.insert(this->start);
        this->alphabet = N.alphabet;
        std::map<std::set<int>, bool> isMarked;
        while (isMarked.size() < this->Dstates.size()) {
            // there exists one unmarked state
            for (const auto &T: this->Dstates) {
                if (isMarked.find(T) == isMarked.end()) {
                    // found unmarked state T
                    isMarked[T] = true;
                    for (auto a: this->alphabet) {
                        std::set<int> U = epsilon_closure(move(T, a, N), N);
                        if (U.empty()) continue; // !exsist U=move(T,a), then nothing to do
                        if (this->Dstates.find(U) == this->Dstates.end()) {
                            this->Dstates.insert(U);
                            if (U.find(N.accept) != U.end()) this->accept.insert(U);
                        }
                        this->Dtrans[{T, a}] = U;
                    }
                }
            }
        }

        // transfer tokens
        for (DFAState dfastate: this->Dstates) {
            for (const auto &entry: N.tokens) {
                NFAState nfastate = entry.first;
                Token token = entry.second;
                if (dfastate.find(nfastate) != dfastate.end()) {
                    if (this->tokens.find(dfastate) == this->tokens.end()) this->tokens[dfastate] = token;
                        // Conflict Resolution
                    else if (token < this->tokens[dfastate]) {
                        this->tokens[dfastate] = token;
                    }
                }
            }
        }
    }

    DFAState epsilon_closure(DFAState T, NFA &N) {
        std::stack<int> stk;
        for (auto i: T) stk.push(i);
        std::set<int> closure;
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            closure.insert(t);
            for (auto outEdges_t: N.states[t].outEdges) {
                if (outEdges_t.label == EPSILON && closure.find(outEdges_t.dest) == closure.end()) {
                    closure.insert(outEdges_t.dest);
                    stk.push(outEdges_t.dest);
                }
            }
        }

        // std::cerr << "Message from epsilon-closure: " << std::endl;
        // print_Set(closure);
        return closure;
    }

    DFAState move(DFAState T, char a, NFA &N) {
        std::set<int> afterMove;

        for (auto t: T) {
            for (auto outEdges_t: N.states[t].outEdges) {
                if (outEdges_t.label == a) {
                    afterMove.insert(outEdges_t.dest);
                }
            }
        }
        return afterMove;
    }

    DFAState DFA::trans(DFAState &s, char &c) {

        if (this->Dtrans.find({s, c}) != this->Dtrans.end()) {
            return this->Dtrans[{s, c}];
        }
        return DFAState();
    }

    std::map<DFAState, int> PartitionID;
    std::map<int, std::set<DFAState>> Partition;
    std::map<int, DFAState> Repr;

    DFA DFAMinimize(DFA &D) {
        DFA dfa;
        dfa.alphabet = D.alphabet;
        int counter = 0;

        /* Initialization */
        // Special Case, to fill the blankets in transition table
        PartitionID[DFAState({})] = -1;
        // set_partition for final states accepting same token
        std::map<Token, std::set<DFAState>> token2states;
        for (const auto &s: D.tokens) {
            DFAState state = s.first;
            Token token = s.second;
            token2states[token].insert(state);
        }

        for (auto s: token2states) {
            set_partition(s.second, counter++);
        }
        // set_partiton for all non-final states
        for (auto s: D.Dstates) if (D.accept.find(s) == D.accept.end()) set_partition(s, counter);
        ++counter;

        /* spliting */
        bool splited;
        do {
            splited = false;
            for (auto P: Partition) {
                int ID = P.first;
                std::set<DFAState> G = P.second;
                auto subgroups = subgroup(G, D);
                // subgrouping_report(G, subgroups);
                if (subgroups.size() > 1) {
                    // Update
                    splited = true;
                    remove_partition_byID(ID);
                    for (auto s: subgroups) {
                        set_partition(s, counter++);
                    }
                    // show_partition_table();
                    break;
                }
            }
        } while (splited);

        /* choose representative */
        for (auto s: Partition) {
            int id = s.first;
            // always choose the first DFAState in one Group as representative
            Repr[id] = *s.second.begin();
            // minimized nfa only includes representatives from each group
            dfa.Dstates.insert(Repr[id]);
        }

        /* complete the minimized dfa */
        // define start states
        dfa.start = Repr[PartitionID[D.start]];
        // define final states
        for (DFAState s: D.accept) {
            dfa.accept.insert(Repr[PartitionID[s]]);
        }
        // define transition table
        for (auto s: dfa.Dstates) {
            for (auto c: D.alphabet) {
                DFAState t = D.trans(s, c);
                if (t.size() > 0) dfa.Dtrans[{Repr[PartitionID[s]], c}] = Repr[PartitionID[t]];
            }
        }

        // define token that each final state accept
        for (auto entry: D.tokens) {
            DFAState dfastate = entry.first;
            Token token = entry.second;
            dfa.tokens[Repr[PartitionID[dfastate]]] = token;
        }

        // return the minimized dfa
        return dfa;
    }

    void set_partition(DFAState s, int id) {
        Partition[PartitionID[s]].erase(s);
        if (Partition[PartitionID[s]].size() == 0) Partition.erase(PartitionID[s]);
        PartitionID[s] = id;
        Partition[id].insert(s);
    }

    void set_partition(std::set<DFAState> states, int id) {
        for (auto s: states) {
            set_partition(s, id);
        }
    }

    void remove_partition_byID(int id) {
        Partition.erase(id);
    }

    std::set<std::set<DFAState>> subgroup(std::set<DFAState> G, DFA &D) {
        std::map<std::vector<int>, std::set<DFAState>> subsets;
        for (auto g: G) {
            std::vector<int> v;
            for (auto c: D.alphabet) v.push_back(PartitionID[D.trans(g, c)]);
            subsets[v].insert(g);
        }
        // show_vectorization(subsets);
        std::set<std::set<DFAState>> subgroups;
        for (auto s: subsets) {
            subgroups.insert(s.second);
        }
        return subgroups;
    }

// DEBUG
    void show_DFA(DFA &D) {
        std::cerr << "alphabet============================" << std::endl;
        short new_line = 10;
        for (auto c: D.alphabet) {
            std::cerr << c << " ";
            if (--new_line == 0) {
                std::cerr << std::endl;
                new_line = 10;
            }
        }
        std::cerr << std::endl;
        std::cerr << "====================================" << std::endl;

        std::map<DFAState, int> notations;
        std::cerr << "Total states: " << D.Dstates.size()
                  << "=====================" << std::endl;

        for (auto s: D.Dstates) {
            notations[s] = notations.size();
            std::cerr
                    << (s == D.start ? "(start)" : (D.accept.find(s) != D.accept.end() ? "(accept)" : ""))
                    << notations[s]
                    << ": ";
            std::cerr << "{";
            for (auto i: s) { std::cerr << i << ","; }
            std::cerr << "}\n";
        }
        std::cerr << "==================================" << std::endl;

        std::cerr << "valid transitions: " << std::endl;
        for (auto t: D.Dtrans) {
            // std::cerr << "{";
            // for(auto i: t.first.first) {std::cerr << i << ",";}
            // std::cerr << "} -> " << t.first.second << " -> {";
            // for(auto i: t.second) {std::cerr << i << ",";}
            // std::cerr << "}"<<std::endl;
            std::cerr << notations[t.first.first] << " --> "
                      << notations[t.second]
                      << ": " << t.first.second
                      << std::endl;
        }
        show_tokens(D);
        make_mermaid(D);
    }

    std::vector<std::pair<Token, std::string>> DFASimulator(DFA &M, std::string &input) {
        std::vector<std::pair<Token, std::string>> tokens;

        std::stack<DFAState> states;
        std::string lexeme_buffer;
        states.push(M.start);
        for (int i = 0; i < input.size(); i++) {
            DFAState state = states.top();
            char c = input[i];
            if (!M.alphabet.has(c)) {
                std::cerr << "ERROR: \n\tUnknown character " << c <<"(" <<(int)c << ")." << std::endl;
                continue;
            }
            DFAState next_state = M.trans(state, c);
            if (next_state != DFAState()) {
                states.push(next_state);
                lexeme_buffer += c;
            } else {
                i -= 1;
                tokens.push_back({M.tokens[state], lexeme_buffer});
                while (!states.empty()) states.pop();
                lexeme_buffer = "";
                states.push(M.start);
            }
        }

        tokens.push_back({M.tokens[states.top()], lexeme_buffer});

        return tokens;
    }

// DEBUG
    void show_tokens(DFA &D) {
        std::map<DFAState, int> notations;
        for (auto s: D.Dstates) {
            notations[s] = notations.size();
        }
        std::cerr << "Tokens=============================" << std::endl;
        for (auto t: D.tokens) {
            std::cerr << notations[t.first];
            std::cerr << ": ";
            // std::cerr << "{";
            std::cerr << t.second.name();
            // std::cerr << "}";
            std::cerr << std::endl;
        }
        std::cerr << "===================================" << std::endl;
    }

// DEBUG
    void print_Set(const std::set<int> &S) {
        std::cerr << "{";
        for (auto i: S) { std::cerr << i << ","; }
        std::cerr << "}";
    }

// DEBUG
    void show_alphabet(std::set<char> alphabet) {
        for (auto i: alphabet) {
            std::cerr << i << " ";
        }
        std::cerr << std::endl;
    }

// DEBUG
    void show_partition_table() {
        // print out partition and partitionID as a table
        std::cerr << "PartitionTb=====================================================" << std::endl;
        for (auto entry: Partition) {
            int ID = entry.first;
            std::set<DFAState> G = entry.second;
            std::cerr << "Paritition " << ID << ": ";
            for (auto each: G) {
                print_Set(each);
                std::cerr << ", ";
            }
            std::cerr << "\n";
        }
        std::cerr << "================================================================" << std::endl;
    }

// DEBUG
    void subgrouping_report(std::set<DFAState> G, std::set<std::set<DFAState> > subgroups) {
        // subgrouping(G) -> subgroups
        std::cerr << "SubgroupingReport============================================" << std::endl;
        std::cerr << "{";
        for (auto g: G) {
            print_Set(g);
            std::cerr << ",";
        }
        std::cerr << "} =>";
        for (auto group: subgroups) {
            std::cerr << "{";
            for (auto g: group) {
                print_Set(g);
                std::cerr << ",";
            }
            std::cerr << "};";
        }
        std::cerr << "\n";
        std::cerr << "=============================================================" << std::endl;
    }

// DEBUG
    void show_vectorization(std::map<std::vector<int>, std::set<DFAState>> &subsets) {
        std::cerr << "vectorizationReport================================" << std::endl;
        for (auto entry: subsets) {
            auto vector = entry.first;
            auto G = entry.second;
            std::cerr << "vector: [";
            for (auto i: vector) std::cerr << i << ",";
            std::cerr << "] => ";
            std::cerr << "{";
            for (auto g: G) {
                print_Set(g);
                std::cerr << ",";
            }
            std::cerr << "}\n";
        }
        std::cerr << "===================================================" << std::endl;
    }

// DEBUG
    void make_mermaid(DFA &D) {
        std::ofstream fout("../test/lex/mermaid.txt");
        if (!fout) {
            std::cerr << "Failed to open the output file" << std::endl;
            return;
        }

        fout << "stateDiagram-v2\n";
        std::map<DFAState, int> notations;
        for (auto s: D.Dstates) {
            notations[s] = notations.size();
        }
        for (auto t: D.Dtrans) {
            fout << notations[t.first.first] << " --> "
                 << notations[t.second]
                 << ": " << t.first.second
                 << std::endl;
        }
        for (auto t: D.tokens) {
            fout << "note right of ";
            fout << notations[t.first];
            fout << ": ";
            fout << t.second.name();
            fout << std::endl;
        }
        fout.close();
    }
}