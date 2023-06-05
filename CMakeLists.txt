cmake_minimum_required(VERSION 3.25)
project(great_buct_compiler)

set(CMAKE_CXX_STANDARD 17)

add_library(GBC_SRC STATIC
        src/lex/DFA.cpp
        src/include/lex/Token.h
        src/include/lex/ErrorMsg.h
        src/include/lex/DFA.h
        src/include/lex/FA.h
        src/include/lex/Graph.h
        src/include/lex/LexicalAnalyzer.h
        src/include/lex/NFA.h
        src/include/lex/Regex.h
        )

include_directories(third_party/doctest/doctest/doctest.h)

add_executable(${PROJECT_NAME} main.cpp)