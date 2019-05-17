//
// Created by Jamie on 5/16/2019.
//

#include "ASTAssignmentStatement.h"

ASTAssignmentStatement::ASTAssignmentStatement(ASTIdentifierNode *identifierNode, ASTExpression *expressionNode){//class constructor
    this->identifierNode = identifierNode;
    this->expressionNode = expressionNode;
}

ASTAssignmentStatement::~ASTAssignmentStatement(){//class destructor
    delete identifierNode;
    delete expressionNode;
}

void ASTAssignmentStatement::Accept(Visitor *visitor){
    visitor->visit(this);
}