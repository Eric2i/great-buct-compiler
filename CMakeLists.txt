cmake_minimum_required(VERSION 3.25)
project(great_buct_compiler)

set(CMAKE_CXX_STANDARD 17)

set(GBC_SRC
        main.cpp
        src/include/lex/token.h
        src/include/lex/error_message.h
        src/include/lex/dfa.h
        src/include/lex/fa.h
        src/include/lex/graph.h
        src/include/lex/lexical_analyzer.h
        src/include/lex/nfa.h
        src/include/lex/regex.h
        src/include/grammar/grammar_analyzer.h
        src/include/grammar/grammar_parser.h
        src/include/grammar/ll_1_parser.h
        src/grammar/grammar_analyzer.cc
        src/grammar/grammar_parser.cc
        src/grammar/ll_1_parser.cc
        test/grammar/read_from_file.cc test/grammar/read_from_file.cc)

add_executable(${PROJECT_NAME} ${GBC_SRC})

find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(doctest REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)


