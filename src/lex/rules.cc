//
// Created by Eric2i Hsiung on 2023/6/4.
//
#include "../include/lex/rules.h"
#include <fstream>
#include <iostream>

namespace gbc::lex {
    LexicalRules::LexicalRules() {
        this->alphabet.initiate();
    }

    bool LexicalRules::read_from_file(path p) {
        token_name name;
        token_pattern pattern;
        token_id seq = 0;

        std::ifstream fin(p);
        while(std::getline(fin, name, ' ')) {
            std::getline(fin, pattern);
            this->_tokens.emplace_back(seq++, name.substr(0, name.size()-1), pattern);
            name2pattern[name.substr(0, name.size()-1)] = pattern;
        }

        return true;
    }

    bool LexicalRules::definition_to_expression() {
        for(Token &t: this->_tokens) {
            std::string::size_type pos = 0;
            std::string pattern = t.pattern();
            while((pos = pattern.find('{', pos)) != std::string::npos) {
                std::string::size_type end = pattern.find('}', pos);
                if(end == std::string::npos) break;
                std::string name = pattern.substr(pos+1, end-pos-1);
                pattern.replace(pos, end-pos+1, "(" + this->name2pattern[name] + ")");
                pos += this->name2pattern[name].size() + 2;
            }
            t.update_pattern(pattern);
            this->name2pattern[t.name()] = t.pattern();
        }
        return true;
    }

    bool LexicalRules::infix_to_postfix() {
        // transform infix regex to postfix regex
        for(Token &t: this->_tokens) {
            t.infix_to_postfix();
        }
        return true;
    }

    std::vector<Token> LexicalRules::tokens() {
        return this->_tokens;
    }

    void LexicalRules::debug() {
        std::cerr << "[Tokens]:\n";
        std::cerr << "\t"
                  << "id\t"
                  << "name\t"
                  << "pattern\n";
        for(Token t: this->_tokens) {
            std::cerr << "\t"
                      << t.id() << ".\t"
                      << t.name() << "\t"
                      << t.pattern() << "\n";
        }
    }
} // gbc namespace
