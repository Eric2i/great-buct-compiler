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

    std::string clear_comments(std::string line) {
        // clear comments after the //
        auto pos = line.find("//");
        if (pos != std::string::npos) {
            line = line.substr(0, pos);
        }

        // clear comments between the /* and */
        pos = line.find("/*");
        if (pos != std::string::npos) {
            auto pos2 = line.find("*/");
            if (pos2 != std::string::npos) {
                line = line.substr(0, pos) + line.substr(pos2 + 2);
            } else {
                line = line.substr(0, pos);
            }
        }
      return line;
    }

    std::vector<std::vector<Token>> LexicalAnalyzer::parse(path &src, path &OUT_FILE) {
        std::vector<std::vector<Token>> parsing_result;

        std::ifstream fin(src);
        std::ofstream fout(OUT_FILE);
        std::string line;
        // get each line of the src code
        while (std::getline(fin, line)) {
            // clear comments
            line = clear_comments(line);

            auto TokenLexemePairs = DFASimulator(this->dfa, line);
            std::vector<Token> line_tokens;
            for(const auto& pair: TokenLexemePairs) {
                Token token = pair.first;
                if(token.name() == "space" || token.name() == "ws") continue;
                std::string lexeme = pair.second;
//                std::cerr << "<";
//                std::cerr << token.name() << ": " << lexeme;
//                std::cerr << ">";
                token.set_unknown_attribute(lexeme);
                line_tokens.push_back(token);
            }
            if(!line_tokens.empty()) {
              parsing_result.push_back(line_tokens);
              for(auto i: line_tokens) {
                fout << "<" << i.name() << ": " << i.unknown() << ">";
              }
                fout << std::endl;
            }
        }
        return parsing_result;
    }

} // gbc::lex namespace
