//
// Created by Jamie on 5/16/2019.
//

#include "ASTReturnStatement.h"

ASTReturnStatement::ASTReturnStatement(ASTExpressionNode *expression) {
    this->expression = expression;
}

ASTReturnStatement::~ASTReturnStatement() {
    delete expression;
}


void ASTReturnStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}