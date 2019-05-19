//
// Created by Jamie on 5/16/2019.
//

#include "ASTSubExpression.h"
#include "../../../../Visitor/Visitor.h"

ASTSubExpression::ASTSubExpression(ASTExpression *expression) {
    this->expression = expression;
}

ASTSubExpression::~ASTSubExpression() {
    delete expression;
}

void ASTSubExpression::Accept(Visitor *visitor) {
    visitor->visit(this);
}
