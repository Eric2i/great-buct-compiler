//
// Created by Eric2i Hsiung on 2023/6/15.
//

#include "../include/lex/lexical_analyzer.h"
#include <fstream>
#include <iostream>

namespace gbc::lex {
    LexicalAnalyzer::LexicalAnalyzer(DFA &dfa) {
        this->dfa = dfa;
    }

    std::vector<std::vector<Token>> LexicalAnalyzer::parse(path &src) {
        std::vector<std::vector<Token>> parsing_result;

        std::ifstream fin(src);
        std::string line;
        // get each line of the src code
        while (std::getline(fin, line)) {
            auto TokenLexemePairs = DFASimulator(this->dfa, line);

            std::vector<Token> line_tokens;
            for(const auto& pair: TokenLexemePairs) {
                Token token = pair.first;
                if(token.name() == "space" || token.name() == "ws") continue;
                std::string lexeme = pair.second;
                std::cerr << "<";
                std::cerr << token.name() << ": " << lexeme;
                std::cerr << ">";
                line_tokens.push_back(token);
            }
            parsing_result.push_back(line_tokens);
            std::cerr << std::endl;
        }
        return parsing_result;
    }

} // gbc::lex namespace
