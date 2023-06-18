//
// Created by Eric2i Hsiung on 2023/6/16.
//

#include "../include/lex/nfa.h"
#include <iostream>
#include <stack>

namespace gbc::lex {

    int counter;
    const char EPSILON = '\0'; // treat epsilon as char '\0'

    void reset_state_counter() {
        counter = 0;
    }

    NFA char2NFA(char c) {
        NFA nfa;
        nfa.start = counter++;
        nfa.accept = counter++;

        nfa.states[nfa.start].outEdges.push_back({nfa.accept, c});

        return nfa;
    }

// N(r) = N(s | t) = N(s) \Union N(t)
    NFA Union(NFA Ns, NFA Nt) {
        NFA nfa;
        nfa.start = counter++;
        nfa.accept = counter++;
        // nfa.states.resize(counter);

        // Connect new start state to start states of Ns and Nt
        nfa.states[nfa.start].outEdges.push_back({Ns.start, EPSILON});
        nfa.states[nfa.start].outEdges.push_back({Nt.start, EPSILON});

        // Connect new accept state by accept states of Ns and Nt
        nfa.states[Ns.accept].outEdges.push_back({nfa.accept, EPSILON});
        nfa.states[Nt.accept].outEdges.push_back({nfa.accept, EPSILON});

        // Combine states
        nfa.states.insert(Ns.states.begin(), Ns.states.end());
        nfa.states.insert(Nt.states.begin(), Nt.states.end());

        return nfa;
    }

// N(r) = N(st) = N(s) Concatenate N(t)
    NFA Concat(NFA Ns, NFA Nt) {
        NFA nfa;
        nfa.start = counter++;
        nfa.accept = counter++;
        // nfa.states.resize(counter);

        nfa.states[nfa.start].outEdges.push_back({Ns.start, EPSILON});
        nfa.states[Ns.accept].outEdges.push_back({Nt.start, EPSILON});
        nfa.states[Nt.accept].outEdges.push_back({nfa.accept, EPSILON});

        // Combine states
        nfa.states.insert(Ns.states.begin(), Ns.states.end());
        nfa.states.insert(Nt.states.begin(), Nt.states.end());

        return nfa;
    }

    NFA KleenClosure(NFA N) {
        NFA nfa;
        nfa.start = counter++;
        nfa.accept = counter++;
        // nfa.states.resize(counter);

        nfa.states[nfa.start].outEdges.push_back({N.start, EPSILON});
        nfa.states[nfa.start].outEdges.push_back({nfa.accept, EPSILON});
        nfa.states[N.accept].outEdges.push_back({N.start, EPSILON});
        nfa.states[N.accept].outEdges.push_back({nfa.accept, EPSILON});

        // Combine states
        nfa.states.insert(N.states.begin(), N.states.end());
        return nfa;
    }

    NFA PositiveClosure(NFA N) {
        NFA nfa;
        nfa.start = counter++;
        nfa.accept = counter++;
        // nfa.states.resize(counter);

        nfa.states[nfa.start].outEdges.push_back({N.start, EPSILON});
        nfa.states[N.accept].outEdges.push_back({N.start, EPSILON});
        nfa.states[N.accept].outEdges.push_back({nfa.accept, EPSILON});

        // Combine states
        nfa.states.insert(N.states.begin(), N.states.end());
        return nfa;
    }

    void show_NFA(NFA &N) {
        for (int i = 0; i < counter; i++) {
//            std::vector<char> connection(counter, '_');

//            if (N.states.count(i) == 1)
//                for (auto j: N.states[i].outEdges)
//                    connection[j.dest] = j.label == '\0' ? '!' : j.label;
//
//            for (auto c: connection) { std::cerr << c << " "; }
            for (auto j: N.states[i].outEdges) {
                std::cerr << i << "-" << (j.label == '\0' ? '!' : j.label) << "->" << j.dest << std::endl;
            }
        }
        std::cerr << std::endl;
    }

    int report_counter() {
        // std::cerr << "counter Reportor: " << counter << std::endl;
        return counter;
    }

    int report_counter_then_delta(int delta) {
        counter += delta;
        return counter - delta;
    }

    NFA build_from_rules(LexicalRules &rules) {
        rules.definition_to_expression();
        rules.infix_to_postfix();

        std::stack<NFA> NFAs;
        reset_state_counter();
        for (auto &token: rules.tokens()) {
            std::stack<NFA> operands;
            if(token.name() == "IDENTIFIER") {
                // cut the corner for annoying 'identifier' case
                NFA head = char2NFA('a');
                NFA tail = char2NFA(EPSILON);
                NFA id_nfa = Concat(head, tail);
                NFAState start = head.start;
                NFAState accept = head.accept;
                std::string _letters_ = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
                std::string _digits = "0123456789";
                for(auto c: _letters_) {
                    id_nfa.states[start].outEdges.push_back({accept, c});
                }
                for(auto c: _letters_ + _digits) {
                    id_nfa.states[accept].outEdges.push_back({accept, c});
                }
                operands.push(id_nfa);
            }
            else {
                for (int i = 0; i < token.pattern().size(); ++i) {
                    char c = token.pattern()[i];
                    if (c == '\\') {
                        // case: special operand, push to stack
                        c = token.pattern()[++i];
                        operands.push(char2NFA(c));
                    } else if (!isRegexCharacter(c)) {
                        // case: operand, push to stack
                        operands.push(char2NFA(c));
                    } else {
                        // case: operator, do regular expression operations
                        NFA nfa1 = operands.top();
                        operands.pop();
                        if (c == '*') {
                            operands.push(KleenClosure(nfa1));
                        } else if (c == '+') {
                            operands.push(PositiveClosure(nfa1));
                        } else if (c == '?') {
                            operands.push(Union(nfa1, char2NFA('\0'))); // r? <=> r | epsilon
                        } else {
                            NFA nfa2 = operands.top();
                            operands.pop();
                            if (c == '#') {
                                operands.push(Concat(nfa2, nfa1));
                            } else {
                                operands.push(Union(nfa2, nfa1));
                            }
                        }
                    }
                }
            }
            NFA rule_to_nfa = operands.top();
            rule_to_nfa.tokens[rule_to_nfa.accept] = token;
            NFAs.push(rule_to_nfa);
        }

        NFA nfa;
        nfa.alphabet = rules.alphabet;
        nfa.start = counter++;
        nfa.accept = counter++;
        while(!NFAs.empty()) {
            NFA t = NFAs.top();
            NFAs.pop();
            nfa.states[nfa.start].outEdges.push_back({t.start, EPSILON});
            nfa.states[t.accept].outEdges.push_back({nfa.accept, EPSILON});
            nfa.states.insert(t.states.begin(), t.states.end());
            for(auto &state2token: t.tokens) {
                nfa.tokens[state2token.first] = state2token.second;
            }
        }
        return nfa;
    }
}
