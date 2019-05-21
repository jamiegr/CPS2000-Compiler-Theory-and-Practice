//
// Created by Jamie on 5/16/2019.
//

#include "ASTForStatement.h"
#include "../../../Visitor/Visitor.h"

ASTForStatement::ASTForStatement(ASTVariableDeclStatement *variableDeclStatement, ASTExpressionNode *expression,
                                 ASTAssignmentStatement *assignmentStatement, ASTBlockStatement *forBlock) {
    this->variableDeclStatement = variableDeclStatement;
    this->expression = expression;
    this->assignmentStatement = assignmentStatement;
    this->forBlock = forBlock;
}

ASTForStatement::~ASTForStatement() {
    delete variableDeclStatement;
    delete expression;
    delete assignmentStatement;
    delete forBlock;
}

void ASTForStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}