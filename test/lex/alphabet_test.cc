//
// Created by Eric2i Hsiung on 2023/6/18.
//

#include "../../src/include/lex/alphabet.h"
#include <iostream>
#include <set>

namespace gbc::lex {
    bool alphabet_tester() {
        Alphabet alphabet;
        // insert several chars and test isInAlphabet

        // test append
        alphabet.insert('a');
        alphabet.insert('b');
        alphabet.insert('c');


        // test isInAlphabet
        assert(alphabet.has('a'));
        assert(alphabet.has('b'));
        assert(alphabet.has('c'));


        // test begin() and end()
        auto iter = alphabet.begin();
        assert(*iter == 'a');
        iter++;
        assert(*iter == 'b');
        iter++;
        assert(*iter == 'c');
        iter++;
        assert(iter == alphabet.end());

        // test initiate()
        alphabet.initiate();
        for (auto i: alphabet) std::cerr << i << " ";

        return true;
    }
}