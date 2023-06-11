//
// Created by Eric2i Hsiung on 2023/6/4.
//
#include "../include/lex/regex.h"
#include <fstream>
#include <iostream>

namespace gbc {
    namespace lex {
        bool Regex::read_from_file(path p) {
            token_name name;
            token_pattern pattern;
            token_id seq = 0;

            std::ifstream fin(p);
            while(std::getline(fin, name, ' ')) {
                std::getline(fin, pattern);
                this->_tokens.push_back(Token(seq++,
                                              name.substr(0, name.size()-1),
                                              pattern));
                name2pattern[name.substr(0, name.size()-1)] = pattern;
            }
            return true;
        }

        token_pattern Regex::expand(token_pattern pattern) {
            // match all string between { } and replace { } with ( ) and its content with this->name2pattern[]
            std::string::size_type pos = 0;
            while((pos = pattern.find('{', pos)) != std::string::npos) {
                std::string::size_type end = pattern.find('}', pos);
                if(end == std::string::npos) break;
                std::string name = pattern.substr(pos+1, end-pos-1);
                pattern.replace(pos, end-pos+1, "(" + this->name2pattern[name] + ")");
                pos += this->name2pattern[name].size() + 2;
            }
            return pattern;
        }

        bool Regex::definition_to_expression() {
            for(Token &t: this->_tokens) {
                t.update_pattern(expand(t.pattern()));
                // this->name2pattern must be synchronized with all tokens
                this->name2pattern[t.name()] = t.pattern();
            }
        }

        bool Regex::infix_to_postfix() {
            // transform infix regex to postfix regex
            for(Token &t: this->_tokens) {
                t.infix_to_postfix();
            }
            return true;
        }

        std::vector<Token> Regex::tokens() {
            return this->_tokens;
        }

        void Regex::debug() {
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

        void regex_class_tester() {
            Regex regex;
            regex.read_from_file("tokens.txt");
            regex.definition_to_expression();
            regex.infix_to_postfix();
            for(Token &t: regex.tokens()) {
                std::cerr << t.name() << ": " << t.pattern() << std::endl;
            }
//            regex.debug();
        }

    } // lex namespace
} // gbc namespace
