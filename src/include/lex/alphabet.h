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
        Alphabet() = default;

        ~Alphabet() = default;

        void initiate();

        bool has(const char &c);

        bool insert(const char &c);

        std::set<char>::iterator begin();

        std::set<char>::iterator end();

    private:
        std::set<char> _alphabet;

    };

} // gbc::lex namespace

#endif //GREAT_BUCT_COMPILER_ALPHABET_H
