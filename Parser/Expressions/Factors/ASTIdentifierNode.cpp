//
// Created by Jamie on 5/16/2019.
//

#include "ASTIdentifierNode.h"

ASTIdentifierNode::ASTIdentifierNode(string value) {
    this->value = value;
}

void ASTIdentifierNode::Accept(Visitor *visitor) {
    ASTFactorNode::Accept(visitor);
}
