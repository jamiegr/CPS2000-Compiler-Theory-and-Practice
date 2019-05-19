//
// Created by Jamie on 5/17/2019.
//

#include "ASTInt.h"

ASTInt::ASTInt(int value) {
    this->value = value;
}

void ASTInt::Accept(Visitor *visitor) {
    visitor->visit(this);
}
