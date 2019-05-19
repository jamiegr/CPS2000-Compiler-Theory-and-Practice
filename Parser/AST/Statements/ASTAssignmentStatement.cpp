//
// Created by Jamie on 5/16/2019.
//

#include "ASTAssignmentStatement.h"
#include "../../../Visitor/Visitor.h"

ASTAssignmentStatement::ASTAssignmentStatement(ASTIdentifierNode *identifierNode,
                                               ASTExpression *expressionNode) {//class constructor
    this->identifierNode = identifierNode;
    this->expression = expressionNode;
}

ASTAssignmentStatement::~ASTAssignmentStatement() {//class destructor
    delete identifierNode;
    delete expression;
}

void ASTAssignmentStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}