//
// Created by Jamie on 5/18/2019.
//

#include "ASTMultOp.h"

ASTMultOp::ASTMultOp(MULT_OP value) {
    this->value = value;
}

void ASTMultOp::Accept(Visitor *visitor) {
    visitor->visit(this);
}
