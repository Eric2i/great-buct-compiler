# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\DBZQ\Desktop\great-buct-compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\DBZQ\Desktop\great-buct-compiler\build

# Include any dependencies generated for this target.
include CMakeFiles/great_buct_compiler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/great_buct_compiler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/great_buct_compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/great_buct_compiler.dir/flags.make

CMakeFiles/great_buct_compiler.dir/main.cpp.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/main.cpp.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/main.cpp
CMakeFiles/great_buct_compiler.dir/main.cpp.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/great_buct_compiler.dir/main.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/main.cpp.obj -MF CMakeFiles\great_buct_compiler.dir\main.cpp.obj.d -o CMakeFiles\great_buct_compiler.dir\main.cpp.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\main.cpp

CMakeFiles/great_buct_compiler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/main.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\main.cpp > CMakeFiles\great_buct_compiler.dir\main.cpp.i

CMakeFiles/great_buct_compiler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/main.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\main.cpp -o CMakeFiles\great_buct_compiler.dir\main.cpp.s

CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/lex/token.cc
CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\lex\token.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\lex\token.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\token.cc

CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\token.cc > CMakeFiles\great_buct_compiler.dir\src\lex\token.cc.i

CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\token.cc -o CMakeFiles\great_buct_compiler.dir\src\lex\token.cc.s

CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/lex/rules.cc
CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\lex\rules.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\lex\rules.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\rules.cc

CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\rules.cc > CMakeFiles\great_buct_compiler.dir\src\lex\rules.cc.i

CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\rules.cc -o CMakeFiles\great_buct_compiler.dir\src\lex\rules.cc.s

CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/grammar/grammar_analyzer.cc
CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_analyzer.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_analyzer.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\grammar_analyzer.cc

CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\grammar_analyzer.cc > CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_analyzer.cc.i

CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\grammar_analyzer.cc -o CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_analyzer.cc.s

CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/grammar/grammar_parser.cc
CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_parser.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_parser.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\grammar_parser.cc

CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\grammar_parser.cc > CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_parser.cc.i

CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\grammar_parser.cc -o CMakeFiles\great_buct_compiler.dir\src\grammar\grammar_parser.cc.s

CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/grammar/ll_1_parser.cc
CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\grammar\ll_1_parser.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\grammar\ll_1_parser.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\ll_1_parser.cc

CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\ll_1_parser.cc > CMakeFiles\great_buct_compiler.dir\src\grammar\ll_1_parser.cc.i

CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\grammar\ll_1_parser.cc -o CMakeFiles\great_buct_compiler.dir\src\grammar\ll_1_parser.cc.s

CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/lex/alphabet.cpp
CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj -MF CMakeFiles\great_buct_compiler.dir\src\lex\alphabet.cpp.obj.d -o CMakeFiles\great_buct_compiler.dir\src\lex\alphabet.cpp.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\alphabet.cpp

CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\alphabet.cpp > CMakeFiles\great_buct_compiler.dir\src\lex\alphabet.cpp.i

CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\alphabet.cpp -o CMakeFiles\great_buct_compiler.dir\src\lex\alphabet.cpp.s

CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/lex/nfa.cc
CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\lex\nfa.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\lex\nfa.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\nfa.cc

CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\nfa.cc > CMakeFiles\great_buct_compiler.dir\src\lex\nfa.cc.i

CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\nfa.cc -o CMakeFiles\great_buct_compiler.dir\src\lex\nfa.cc.s

CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/lex/dfa.cc
CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\lex\dfa.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\lex\dfa.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\dfa.cc

CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\dfa.cc > CMakeFiles\great_buct_compiler.dir\src\lex\dfa.cc.i

CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\dfa.cc -o CMakeFiles\great_buct_compiler.dir\src\lex\dfa.cc.s

CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj: CMakeFiles/great_buct_compiler.dir/flags.make
CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj: C:/Users/DBZQ/Desktop/great-buct-compiler/src/lex/lexical_analyzer.cc
CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj: CMakeFiles/great_buct_compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj -MF CMakeFiles\great_buct_compiler.dir\src\lex\lexical_analyzer.cc.obj.d -o CMakeFiles\great_buct_compiler.dir\src\lex\lexical_analyzer.cc.obj -c C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\lexical_analyzer.cc

CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\lexical_analyzer.cc > CMakeFiles\great_buct_compiler.dir\src\lex\lexical_analyzer.cc.i

CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\DBZQ\Desktop\great-buct-compiler\src\lex\lexical_analyzer.cc -o CMakeFiles\great_buct_compiler.dir\src\lex\lexical_analyzer.cc.s

# Object files for target great_buct_compiler
great_buct_compiler_OBJECTS = \
"CMakeFiles/great_buct_compiler.dir/main.cpp.obj" \
"CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj" \
"CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj" \
"CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj"

# External object files for target great_buct_compiler
great_buct_compiler_EXTERNAL_OBJECTS =

great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/main.cpp.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/lex/token.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/lex/rules.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_analyzer.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/grammar/grammar_parser.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/grammar/ll_1_parser.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/lex/alphabet.cpp.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/lex/nfa.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/lex/dfa.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/src/lex/lexical_analyzer.cc.obj
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/build.make
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/linkLibs.rsp
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/objects1.rsp
great_buct_compiler.exe: CMakeFiles/great_buct_compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable great_buct_compiler.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\great_buct_compiler.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/great_buct_compiler.dir/build: great_buct_compiler.exe
.PHONY : CMakeFiles/great_buct_compiler.dir/build

CMakeFiles/great_buct_compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\great_buct_compiler.dir\cmake_clean.cmake
.PHONY : CMakeFiles/great_buct_compiler.dir/clean

CMakeFiles/great_buct_compiler.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\DBZQ\Desktop\great-buct-compiler C:\Users\DBZQ\Desktop\great-buct-compiler C:\Users\DBZQ\Desktop\great-buct-compiler\build C:\Users\DBZQ\Desktop\great-buct-compiler\build C:\Users\DBZQ\Desktop\great-buct-compiler\build\CMakeFiles\great_buct_compiler.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/great_buct_compiler.dir/depend

