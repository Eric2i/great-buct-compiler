cmake_minimum_required(VERSION 3.25)
project(great_buct_compiler)

set(CMAKE_CXX_STANDARD 17)

add_library(GBC_SRC STATIC
        src/include/lex/token.h
        src/include/lex/error_message.h
        src/include/lex/dfa.h
        src/include/lex/fa.h
        src/include/lex/graph.h
        src/include/lex/lexical_analyzer.h
        src/include/lex/nfa.h
        src/include/lex/regex.h
        src/grammar/grammar_analyzer.cc src/include/grammar/grammar_analyzer.h src/grammar/grammar_parser.cc src/include/grammar/grammar_parser.h src/grammar/ll_1_parser.cc src/include/grammar/ll_1_parser.h)

include_directories(third_party/doctest/doctest/doctest.h)

add_executable(${PROJECT_NAME} main.cpp)