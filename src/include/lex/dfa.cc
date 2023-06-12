
#include "../include/lex/dfa.h"
#include <fstream>
#include <iostream>

namespace gbc::lex {

    std::vector<std::vector<Token>> DFA::get_tokens() {

        this->_tokens.reserve(6);

        this->_tokens[0].push_back({1, "reversed", "int"});
        this->_tokens[0].push_back({2, "reversed", "main"});this->_tokens[0].push_back({3, "LEFT_BRACKET", "("});
        this->_tokens[0].push_back({4, "RIGHT_BRACKET", ")"});this->_tokens[0].push_back({5, "LEFT_CURLYBRACE", "{"});
        
        this->_tokens[1].push_back({6, "reserved", "float"});this->_tokens[1].push_back({7, "identifier", "PI"});
        this->_tokens[1].push_back({8, "ASSIGN", "="});this->_tokens[1].push_back({9, "number", "3.14"});
        this->_tokens[1].push_back({10, "SEMICOLON", ";"});

        this->_tokens[2].push_back({11, "reserved", "float"});this->_tokens[2].push_back({12, "identifier", "radius"});
        this->_tokens[2].push_back({13, "ASSIGN", "="});this->_tokens[2].push_back({14, "number", "2"});
        this->_tokens[2].push_back({15, "SEMICOLON", ";"});

        this->_tokens[3].push_back({16, "reserved", "double"});this->_tokens[3].push_back({17, "identifier", "area"});
        this->_tokens[3].push_back({18, "ASSIGN", "="});this->_tokens[3].push_back({19, "identifier", "PI"});
        this->_tokens[3].push_back({20, "MULTIPLY", "*"});this->_tokens[3].push_back({21, "identifier", "radius"});
        this->_tokens[3].push_back({22, "MULTIPLY", "*"});this->_tokens[3].push_back({23, "identifier", "radius"});
        this->_tokens[3].push_back({24, "SEMICOLON", ";"});
        
        this->_tokens[4].push_back({25, "reserved", "return"});this->_tokens[4].push_back({26, "digit", "0"});
        this->_tokens[4].push_back({27, "SEMICOLON", ";"});

        this->_tokens[5].push_back({28, "RIGHT_CURLYBRACE", "}"});

        return this->_tokens;
    }

} // gbc namespace
