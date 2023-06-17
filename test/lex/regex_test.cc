//
// Created by Eric2i Hsiung on 2023/6/15.
//

#include "../../src/include/lex/rules.h"
#include <iostream>

bool LexicalRulesTester() {
    gbc::lex::LexicalRules regex;
    regex.read_from_file("tokens.txt");
    regex.definition_to_expression();
    regex.infix_to_postfix();
    for(gbc::lex::Token &t: regex.tokens()) {
        std::cerr << t.name() << ": " << t.pattern() << std::endl;
    }
    return true;
}