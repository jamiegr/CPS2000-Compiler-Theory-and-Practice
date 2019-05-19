//
// Created by Jamie on 5/17/2019.
//

#include "ASTFloat.h"
#include "../../../../Visitor/Visitor.h"

ASTFloat::ASTFloat(float floatValue) {
    this->floatValue = floatValue;
}

void ASTFloat::Accept(Visitor *visitor) {
    visitor->visit(this);
}