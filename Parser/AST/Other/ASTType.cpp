//
// Created by Jamie on 5/17/2019.
//

#include "ASTType.h"
#include "../../../Visitor/Visitor.h"

ASTType::ASTType(std::string value) {
    this->value = value;
}

void ASTType::Accept(Visitor *visitor) {
    visitor->visit(this);
}
