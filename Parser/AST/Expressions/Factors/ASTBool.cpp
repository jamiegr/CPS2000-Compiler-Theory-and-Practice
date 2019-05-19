//
// Created by Jamie on 5/17/2019.
//

#include "ASTBool.h"
#include "../../../../Visitor/Visitor.h"

ASTBool::ASTBool(bool boolValue) {
    this->boolValue = boolValue;
}

void ASTBool::Accept(Visitor *visitor) {
    visitor->visit(this);
}