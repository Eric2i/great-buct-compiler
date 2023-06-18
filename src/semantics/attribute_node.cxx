//
// Created by Eric2i Hsiung on 2023/6/18.
//

#include "../../src/include/semantics/attribute_node.h"

namespace gbc::semantics {
    bool AttributeNode::operator<(const gbc::semantics::AttributeNode &X) const {
      return this->in_degree;
    }
}