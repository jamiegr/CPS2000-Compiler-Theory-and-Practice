//
// Created by Jamie on 5/18/2019.
//

#include "ASTAddOp.h"
#include "../../../Visitor/Visitor.h"

ASTAddOp::ASTAddOp(std::string value) {
    this->value = value;
}

void ASTAddOp::Accept(Visitor *visitor) {
    visitor->visit(this);
}
