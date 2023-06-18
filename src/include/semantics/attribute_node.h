//
// Created by Eric2i Hsiung on 2023/6/18.
//

#ifndef GREAT_BUCT_COMPILER_ATTRIBUTE_NODE_H
#define GREAT_BUCT_COMPILER_ATTRIBUTE_NODE_H

namespace gbc::semantics {
    using degree_t = long long;

  class AttributeNode {
    public:
      AttributeNode() = default;

      ~AttributeNode() = default;

      bool operator<(const AttributeNode &X) const;

    private:
      degree_t in_degree;
    };
}
#endif //GREAT_BUCT_COMPILER_ATTRIBUTE_NODE_H
