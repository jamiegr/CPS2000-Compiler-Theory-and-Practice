//
// Created by Jamie on 5/17/2019.
//

#include "ASTFloat.h"

ASTFloatNode::ASTFloatNode(float floatValue) {
    this->floatValue = floatValue;
}

void ASTFloatNode::Accept(Visitor *visitor) {
    visitor->visit(this);
}