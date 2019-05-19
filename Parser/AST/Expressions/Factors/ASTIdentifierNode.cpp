//
// Created by Jamie on 5/16/2019.
//

#include "ASTIdentifierNode.h"
#include "../../../../Visitor/Visitor.h"

ASTIdentifierNode::ASTIdentifierNode(std::string value) {
    this->value = value;
}

void ASTIdentifierNode::Accept(Visitor *visitor) {
    visitor->visit(this);
}
