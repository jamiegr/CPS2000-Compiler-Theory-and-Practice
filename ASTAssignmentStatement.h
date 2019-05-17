//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTASSIGNMENTSTATEMENT_H
#define COMPILERASSIGNMENT_ASTASSIGNMENTSTATEMENT_H

#include <string>
#include "ASTIdentifierNode.h"
#include "ASTStatement.h"
#include "ASTExpression.h"

class ASTAssignmentStatement : ASTStatement {
public:
    ASTIdentifierNode *identifierNode;//the identifier which is being assigned a value
    ASTExpression *expressionNode;//the expression whose result is to be assigned to the identifier
    ASTAssignmentStatement(ASTIdentifierNode *identifierNode, ASTExpression *expressionNode);
    ~ASTAssignmentStatement();
    void Accept(Visitor *visitor);
};


#endif //COMPILERASSIGNMENT_ASTASSIGNMENTSTATEMENT_H
