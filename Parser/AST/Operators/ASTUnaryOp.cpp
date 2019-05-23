//
// Created by Jamie on 5/18/2019.
//

#include "ASTUnaryOp.h"
#include "../../../Visitor/Visitor.h"

ASTUnaryOp::ASTUnaryOp(std::string value) {
    this->value = value;
}

void ASTUnaryOp::Accept(Visitor *visitor) {
    visitor->visit(this);
}
