//
// Created by Eric2i Hsiung on 2023/6/4.
//

/*
 * 鎴戜滑甯屾湜灏嗘湁鍏冲浘鐨勪竴鑸€ф暟鎹粨鏋勫拰鍔熻兘鍑芥暟鎶借薄涓轰袱涓被,
 * 姝ゅ悗鏈夊叧鏌愮被鍏蜂綋鍥炬暟鎹粨鏋勭殑鏋勫缓灏嗛€氳繃寮曠敤鏈枃浠跺疄鐜板叾楂樺眰鍔熻兘
 */

#ifndef GREAT_BUCT_COMPILER_GRAPH_H
#define GREAT_BUCT_COMPILER_GRAPH_H

#include <vector>
namespace gbc {
namespace lex {

enum Result { OK, FAILED }; // return status


typedef long long state_id;
typedef long long edge_id;
typedef char label_t;

template<class state_t>
class GenericEdge {

public:

  GenericEdge() = default;

  edge_id _id;
  label_t _label;
  state_t _destination;

  edge_id id(); // get edge id
  state_t dest(edge_id x); // get the destination of this edge
  label_t label(edge_id x); // get the label of this edge
};

template<class edge_t>
class GenericState {

public:

  GenericState() = default;

  state_id _id;
  std::vector<edge_t> _edges;

  state_id id(); // get state id
  edge_t outEdges(state_id x); // get out edges
  Result addEdges(state_id x, state_id y); // add new out edge
};

} // lex
} // gbc

#endif //GREAT_BUCT_COMPILER_GRAPH_H