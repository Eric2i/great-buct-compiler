//
// Created by Eric2i Hsiung on 2023/6/4.
//

/*
 * 我们希望将有关图的一般性数据结构和功能函数抽象为两个类,
 * 此后有关某类具体图数据结构的构建将通过引用本文件实现其高层功能
 */

#ifndef GREAT_BUCT_COMPILER_GRAPH_H
#define GREAT_BUCT_COMPILER_GRAPH_H


#include <vector>


enum Result {OK, FAILED}; // return status


typedef long long state_id;
typedef long long edge_id;
typedef char label_t;


template<class state_t>
class genericEdge {
private:
    edge_id _id;
    label_t _label;
    state_t _destination;
public:
    edge_id id(); // get edge id
    state_t dest(); // get the destination of this edge
    label_t label(); // get the label of this edge
};


template<class edge_t>
class genericState {
private:
    state_id _id;
    std::vector<edge_t> _edges;
public:
    state_id id(); // get state id
    edge_t outEdges(); // get out edges
    Result addEdges(); // add new out edge
};

#endif //GREAT_BUCT_COMPILER_GRAPH_H
