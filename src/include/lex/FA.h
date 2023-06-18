//
// Created by Eric2i Hsiung on 2023/6/17.
//

#ifndef GREAT_BUCT_COMPILER_FA_H
#define GREAT_BUCT_COMPILER_FA_H

#include <set>

namespace gbc::lex {
    struct Edge {
        int dest;   // destination of the edge
        char label; // label of the edge
    };

    struct State {
        std::vector<Edge> outEdges;
    };
}
#endif //GREAT_BUCT_COMPILER_FA_H
