//
// Created by Jamie on 5/16/2019.
//

#include "ASTReturnStatement.h"
#include "../../../Visitor/Visitor.h"

ASTReturnStatement::ASTReturnStatement(ASTExpression *expression) {
    this->expression = expression;
}

ASTReturnStatement::~ASTReturnStatement() {
    delete expression;
}


void ASTReturnStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}