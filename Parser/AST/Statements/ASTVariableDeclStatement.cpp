//
// Created by Jamie on 5/16/2019.
//

#include "ASTVariableDeclStatement.h"
#include "../../../Visitor/Visitor.h"

ASTVariableDeclStatement::ASTVariableDeclStatement(ASTIdentifierNode *identifierNode, ASTType *type,
                                                   ASTExpression *expression) {
    this->identifierNode = identifierNode;
    this->type = type;
    this->expression = expression;
}

ASTVariableDeclStatement::~ASTVariableDeclStatement() {
    delete identifierNode;
    delete type;
    delete expression;
}

void ASTVariableDeclStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}

