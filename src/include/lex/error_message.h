//
// Created by Eric2i Hsiung on 2023/6/3.
//

#ifndef GREAT_BUCT_COMPILER_ERRORMSG_H
#define GREAT_BUCT_COMPILER_ERRORMSG_H

#include<string>

namespace gbc {
namespace lex {

class ErrorMessage {
public:
    static void ReportError(const std::string& message);
    static void ReportWarning(const std::string& message);
};

} // lex
} // gbc


#endif //GREAT_BUCT_COMPILER_ERRORMSG_H