//
// Created by Jamie on 5/17/2019.
//

#include "ASTIntNode.h"

ASTIntNode::ASTIntNode(int value) {
    this->value = value;
}

void ASTIntNode::Accept(Visitor *visitor) {
    visitor->visit(this);
}
