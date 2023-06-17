//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_LEXICALANALYZER_H
#define GREAT_BUCT_COMPILER_LEXICALANALYZER_H

#include "dfa.h"
#include "rules.h"
namespace gbc::lex {

    using path = std::string;
    using lexeme = std::string;

    class LexicalAnalyzer {
    private:
        DFA dfa;
    public:
        LexicalAnalyzer(DFA &);
        std::vector<std::vector<Token>> parse(path &);
    };

} // gbc::lex namespace


#endif //GREAT_BUCT_COMPILER_LEXICALANALYZER_H
