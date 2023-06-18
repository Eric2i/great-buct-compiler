//
// Created by Dysprosium on 2023/6/18.
//

#include "../include/grammar/ast.h"

namespace gbc::grammar {

ASTNode *ASTNode::BuildSubTreeFromProduction(Tokens children) {
  for (const auto &item : children) {
    ASTNode* node = new ASTNode(item.id());
    this->AddChild(node);
  }
  return nullptr;
}

void ASTNode::AddChild(ASTNode* &child) {
  this->children.push_back(child);
}

void ASTNode::Print() {
  std::deque<ASTNode *> q;
  q.push_back(this);
  while (!q.empty()) {
    auto f = q.front();
    q.pop_front();
    for (const auto &child : f->children) {
      q.push_back(child);
      std::cout << f->id << " -> " << child->id << std::endl;
    }
  }
}

const std::vector<ASTNode *> &ASTNode::GetChildren() const {
  return children;
}

} // gbc
