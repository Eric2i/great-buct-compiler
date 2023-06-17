//
// Created by Eric2i Hsiung on 2023/6/7.
//

#include "../include/lex/alphabet.h"

namespace gbc::lex {

    void Alphabet::initiate() {
        std::string initial_alphabet_table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*/%<>~&|^!=()[]{}_',.\" ;";
        for(auto &c : initial_alphabet_table) {
            this->_alphabet.insert(c);
        }
    }

    bool Alphabet::isInAlphabet(char &c) {
        return this->_alphabet.find(c) != this->_alphabet.end();
    }

    bool Alphabet::append(char &c) {
        if(this->isInAlphabet(c)) return false;
        this->_alphabet.insert(c);
        return true;
    }

} // gbc::lex namespace