#include <iostream>

void print_help_info() {
    std::cerr << "Usage: gbc [options] file...\n"
                 "Options:\n"
                 "  -h help\t print this help info\n"
                 "  -v version\t print version info\n"
                 "  -l lexical\t output lexical analysis result\n"
                 "  -g grammar\t output syntax analysis result\n"
                 "  -s semantics\t output semantics analysis result\n"
                 "  -o output\t specify output file\n"
                 ;
}

void print_version_info() {
    std::cerr << "GBC version 0.0.1\n";
}

int main(int argc, char **argv) {
    // print help info if no argument is given
    if (argc == 1 || (argc == 2 && std::string(argv[1]) == "-h")) {
        print_help_info();
    }
    // print version info
    else if (argc == 2 && std::string(argv[1]) == "-v") {
        print_version_info();
    }
    else if (argc == 2 || argc == 3 || argc == 4) {
        std::cerr << "Wrong number of arguments\n\n";
        print_help_info();
    }
    else if (argc == 5) {
        // gbc -o output_file {-l || -g || -s} input_file
        // TODO: run specified modules
    }
}