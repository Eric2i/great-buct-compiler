//
// Created by Eric2i Hsiung on 2023/6/16.
//

#include "../include/lex/nfa.h"
#include <iostream>

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
            for(auto j: N.states[i].outEdges) {
                std::cerr << i << "-" << (j.label == '\0' ? '!' : j.label)  << "->" << j.dest << std::endl;
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

}
