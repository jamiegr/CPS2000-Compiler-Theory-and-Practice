//
// Created by Jamie on 5/18/2019.
//

#include "ASTAddOp.h"

ASTAddOp::ASTAddOp(ADD_OP value) {
    this->value = value;
}

void ASTAddOp::Accept(Visitor *visitor) {
    visitor->visit(this);
}
