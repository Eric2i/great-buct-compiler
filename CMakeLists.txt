cmake_minimum_required(VERSION 3.25)
project(great_buct_compiler)

set(CMAKE_CXX_STANDARD 17)

set(GBC_SRC
        src/lex/token.cc src/include/lex/token.h
        src/include/lex/error_message.h
        src/include/lex/dfa.h
        src/include/lex/lexical_analyzer.h
        src/include/lex/nfa.h
        src/lex/rules.cc
        src/include/lex/rules.h
        src/grammar/grammar_analyzer.cc src/include/grammar/grammar_analyzer.h
        src/grammar/grammar_parser.cc src/include/grammar/grammar_parser.h
        src/grammar/ll_1_parser.cc src/include/grammar/ll_1_parser.h
        src/lex/alphabet.cc src/include/lex/alphabet.h
        src/lex/nfa.cc src/lex/dfa.cc src/lex/lexical_analyzer.cc test/grammar/grammar_analyzer_tester.cc src/grammar/ast.cc src/include/grammar/ast.h src/grammar/ast.cc src/include/grammar/ast.h src/semantics/number_ast.cc src/include/semantics/number_ast.h src/semantics/binary_ast.cc src/include/semantics/binary_ast.h src/include/semantics/llvm_config.h src/include/semantics/llvm_config.h
        main.cpp
        src/llvm.cc src/llvm.cc)

add_executable(${PROJECT_NAME} ${GBC_SRC})

find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
#find_package(doctest CONFIG REQUIRED)
set(LLVM_DIR /opt/homebrew/Cellar/llvm/16.0.6/lib/cmake/llvm) # change to your llvm dir

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(LLVM_LIBRARIES ${LLVM_TARGETS_TO_BUILD})


target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
#target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LLVM_LIBRARIES})