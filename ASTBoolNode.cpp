//
// Created by Jamie on 5/17/2019.
//

#include "ASTBoolNode.h"

ASTBoolNode::ASTBoolNode(bool boolValue){
    this->boolValue = boolValue;
}

void ASTBoolNode::Accept(Visitor *visitor) {
    visitor->visit(this);
}