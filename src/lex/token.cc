//
// Created by Eric2i Hsiung on 2023/6/4.
//
#include <utility>
#include <iostream>
#include <stack>
#include "../include/lex/token.h"
#include "../include/lex/graph.h"

namespace gbc::lex {
    Token::Token(token_id id, token_name name, token_pattern pattern) {
        this->_id = id;
        this->_name = std::move(name);
        this->_pattern = std::move(pattern);
    }

    token_id Token::id() const {
        return this->_id;
    }

    token_name Token::name() {
        return this->_name;
    }

    token_pattern Token::pattern() {
        return this->_pattern;
    }

    bool Token::operator<(const Token &X) const {
        return this->_id < X._id;
    }

    bool isRegexCharacter(char c) {
        if(isalnum(c)) return false;
        switch(c) {
            case '_':
                return false;
            case '<':
                return false;
            case '=':
                return false;
            case '!':
                return false;
            case '>':
                return false;
            case '-':
                return false;
            case ' ':
                return false;
            case ';':
                return false;
        }
        return true;
    }

    bool allowConcatFollow(char c) {
        if(!isRegexCharacter(c)) return true;
        switch(c) {
            case '*':
                return true;
            case ')':
                return true;
            case '?':
                return true;
            case '\\':
                return true;
        }
        return false;
    }

    bool PartialOrd(const char a, const char b) {
        const std::string ordered_operator_lists = "(|#*?";
        return ordered_operator_lists.find(a) >= ordered_operator_lists.find(b);
    }

    bool Token::infix_to_postfix() {
        token_pattern postfix;

        std::stack<label_t> operator_stk;
        char lastToken = '\0';

        for (int i = 0; i < this->_pattern.size(); i++)
        {
            char character = this->_pattern[i];
            // we treat the character after the backslash as a normal single character
            if(character == '\\') {
                if(allowConcatFollow(lastToken)) {
                    char Concatenation = '#';
                    while(!operator_stk.empty() && PartialOrd(operator_stk.top(), Concatenation)) {
                        postfix += operator_stk.top();
                        operator_stk.pop();
                    }
                    operator_stk.push(Concatenation);
                }
                char nextChar = this->_pattern[i+1];
                this->alphabet.append(nextChar);
//                postfix += character; // keep the backslash
                postfix += nextChar;
                lastToken = character;
                i += 1; // skip the next character
            }
            else if(!isRegexCharacter(character)) {
                if(allowConcatFollow(lastToken)) {
                    char Concatenation = '#';
                    while(!operator_stk.empty() && PartialOrd(operator_stk.top(), Concatenation)) {
                        postfix += operator_stk.top();
                        operator_stk.pop();
                    }
                    operator_stk.push(Concatenation);
                }
                this->alphabet.append(character);
                postfix += character;
                lastToken = character;
            }
            else if (character == '(')
            {
                if(allowConcatFollow(lastToken)) {
                    char Concatenation = '#';
                    while(!operator_stk.empty() && PartialOrd(operator_stk.top(), Concatenation)) {
                        postfix += operator_stk.top();
                        operator_stk.pop();
                    }
                    operator_stk.push(Concatenation);
                }
                operator_stk.push('(');
                lastToken = character;
            }
            else if (character == ')')
            {
                while(!operator_stk.empty() && operator_stk.top() != '(')
                {
                    postfix += operator_stk.top();operator_stk.pop();
                }
                operator_stk.pop();
                lastToken = ')';
            }
            else { // regular expression operators
                while(!operator_stk.empty() && PartialOrd(operator_stk.top(), character)) {
                    postfix += operator_stk.top();
                    operator_stk.pop();
                }
                operator_stk.push(character);
                lastToken = character;
            }
        }
        while(!operator_stk.empty()) {
            postfix += operator_stk.top();
            operator_stk.pop();
        }

        this->_pattern = postfix;
        return true;
    }

    void token_class_tester() {
        gbc::lex::token_id id = 0;
        gbc::lex::token_name name = "digit";
        gbc::lex::token_pattern pattern = "0|1|2|3|4|5|6|7|8|9";

        gbc::lex::Token t(id, name, pattern);

        assert(t.id() == 0);
        assert(t.name() == "digit");
        assert(t.pattern() == "0|1|2|3|4|5|6|7|8|9");

        std::cout << "Success!" << std::endl;
    }

    bool Token::update_pattern(token_pattern new_pattern) {
        this->_pattern = std::move(new_pattern);
        return true;
    }
} // gbc::lex namespace

