//
// Created by Jamie on 5/16/2019.
//

#include "ASTIfStatement.h"

ASTIfStatement::ASTIfStatement(ASTExpressionNode *expression, ASTBlockStatement *ifBlock, ASTBlockStatement *elseBlock) {
    this->expression = expression;
    this->ifBlock = ifBlock;
    this->elseBlock = elseBlock;
}

ASTIfStatement::~ASTIfStatement() {
    delete expression;
    delete ifBlock;
    delete elseBlock;
}

void ASTIfStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}
