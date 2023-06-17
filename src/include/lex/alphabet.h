//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_ALPHABET_H
#define GREAT_BUCT_COMPILER_ALPHABET_H

#include <set>
#include <string>

namespace gbc::lex {

    class Alphabet {
    public:
        std::set<char> _alphabet;
        void initiate();
        bool isInAlphabet(char &c); // check if c is in alphabet
        bool append(char &c); // add new character to alphabet
        // iterator for Alphabet

    };

} // gbc::lex namespace

#endif //GREAT_BUCT_COMPILER_ALPHABET_H
