//
// Created by Jamie on 5/16/2019.
//

#include "ASTSimpleExpression.h"
#include "../../../Visitor/Visitor.h"

ASTSimpleExpression::ASTSimpleExpression(ASTExpressionNode *term1, ASTAddOp *addOp, ASTExpressionNode *term2) {
    this->term1 = term1;
    this->addOp = addOp;
    this->term2 = term2;
}

ASTSimpleExpression::~ASTSimpleExpression() {
    delete term1;
    delete addOp;
    delete term2;
}


void ASTSimpleExpression::Accept(Visitor *visitor) {
    visitor->visit(this);
}