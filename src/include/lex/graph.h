//
// Created by Eric2i Hsiung on 2023/6/4.
//

#ifndef GREAT_BUCT_COMPILER_GRAPH_H
#define GREAT_BUCT_COMPILER_GRAPH_H

#include <vector>
namespace gbc {
    namespace lex {

        typedef long long state_id;
        typedef long long edge_id;
        typedef char label_t;

        static long long edge_next_id = 0;
        static long long state_next_id = 0;

        template<class state_t>
        class GenericEdge {
        private:
            edge_id _id;
            label_t _label;
            state_t _destination;
        public:
            GenericEdge(label_t label, state_t destination)
                : _label(label), _destination(destination) {
                _id = edge_next_id++;
            }

            edge_id id() { // get edge id
                return this->_id;
            }

            state_t dest() { // get the destination of this edge
                return this->_destination;
            }

            label_t label() { // get the label of this edge
                return this->_label;
            }
        };

        template<class edge_t>
        class GenericState {
        private:
            state_id _id;
            std::vector<edge_t> _edges;
        public:
            GenericState() {
                _id = state_next_id++;
            }

            state_id id() { // get state id
                return this->_id;
            }

            std::vector<edge_t> outEdges() { // get out edges
                return this->_edges;
            }

            bool addEdges(edge_t edge) { // add new edge
                this->_edges.push_back(edge);
                return true;
            }
        };

    } // lex
} // gbc



#endif //GREAT_BUCT_COMPILER_GRAPH_H