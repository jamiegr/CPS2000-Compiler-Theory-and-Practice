//
// Created by Jamie on 5/18/2019.
//

#include "ASTExpression.h"

ASTExpression::ASTExpression(ASTSimpleExpression *simpleExpression1, ASTRelOp *relOp,
                             ASTSimpleExpression *simpleExpression2) {
    this->simpleExpression1 = simpleExpression1;
    this->relOp = relOp;
    this->simpleExpression2 = simpleExpression2;
}


ASTExpression::~ASTExpression() {
    delete simpleExpression1;
    delete relOp;
    delete simpleExpression2;
}

void ASTExpression::Accept(Visitor *visitor) {
    visitor->visit(this);
}