//
// Created by Jamie on 5/18/2019.
//

#include "ASTUnaryOp.h"

ASTUnaryOp::ASTUnaryOp(UNARY_OP value) {
    this->value = value;
}

void ASTUnaryOp::Accept(Visitor *visitor) {
    visitor->visit(this);
}
