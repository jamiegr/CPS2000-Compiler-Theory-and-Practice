//
// Created by Jamie on 5/16/2019.
//

#include "ASTUnaryNode.h"

ASTUnaryNode::ASTUnaryNode(ASTUnaryOp *unaryOp, ASTExpression *expression) {
    this->unaryOp = unaryOp;
    this->expression = expression;
}

ASTUnaryNode::~ASTUnaryNode() {
    delete unaryOp;
    delete expression;
}

void ASTUnaryNode::Accept(Visitor *visitor) {
    visitor->visit(this);
}
