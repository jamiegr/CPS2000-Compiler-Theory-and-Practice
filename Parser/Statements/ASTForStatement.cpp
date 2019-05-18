//
// Created by Jamie on 5/16/2019.
//

#include "ASTForStatement.h"

ASTForStatement::ASTForStatement(ASTVariableDeclStatement *variableDeclStatement, ASTExpressionNode *expression,
                                 ASTAssignmentStatement *assignmentStatement) {
    this->variableDeclStatement = variableDeclStatement;
    this->expression = expression;
    this->assignmentStatement = assignmentStatement;
}

ASTForStatement::~ASTForStatement() {
    delete variableDeclStatement;
    delete expression;
    delete assignmentStatement;
}

void ASTForStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}