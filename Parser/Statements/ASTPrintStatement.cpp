//
// Created by Jamie on 5/16/2019.
//

#include "ASTPrintStatement.h"

ASTPrintStatement::ASTPrintStatement(ASTExpressionNode *expression) {
    this->expression = expression;
}

ASTPrintStatement::~ASTPrintStatement() {
    delete expression;
}


void ASTPrintStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}