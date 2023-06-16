cmake_minimum_required(VERSION 3.25)
project(great_buct_compiler)

set(CMAKE_CXX_STANDARD 17)

set(GBC_SRC
        main.cpp
        src/lex/token.cc src/include/lex/token.h
        src/include/lex/error_message.h
        src/include/lex/dfa.h
        src/include/lex/fa.h
        src/include/lex/graph.h
        src/include/lex/lexical_analyzer.h
        src/include/lex/nfa.h
        src/lex/rules.cc src/include/lex/rules.h
        src/grammar/grammar_analyzer.cc src/include/grammar/grammar_analyzer.h src/grammar/grammar_parser.cc src/include/grammar/grammar_parser.h src/grammar/ll_1_parser.cc src/include/grammar/ll_1_parser.h
        src/lex/alphabet.cpp src/include/lex/alphabet.h)

add_executable(${PROJECT_NAME} ${GBC_SRC})

find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
#find_package(doctest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
#target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)