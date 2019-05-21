//
// Created by Jamie on 5/18/2019.
//

#include "ASTRelOp.h"
#include "../../../Visitor/Visitor.h"

ASTRelOp::ASTRelOp(REL_OP value) {
    this->value = value;
}

void ASTRelOp::Accept(Visitor *visitor) {
    visitor->visit(this);
}
