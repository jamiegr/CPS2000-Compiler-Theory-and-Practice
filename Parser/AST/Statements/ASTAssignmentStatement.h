//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTASSIGNMENTSTATEMENT_H
#define COMPILERASSIGNMENT_ASTASSIGNMENTSTATEMENT_H

#include <string>
#include "../ASTStatementNode.h"
#include "../Expressions/ASTExpression.h"
#include "../Expressions/Factors/ASTIdentifierNode.h"

class ASTAssignmentStatement : public ASTStatementNode {
public:
    ASTIdentifierNode *identifierNode;//the identifier which is being assigned a value
    ASTExpressionNode *expression;//the expression whose result is to be assigned to the identifier
    ASTAssignmentStatement(ASTIdentifierNode *identifierNode, ASTExpressionNode *expressionNode);

    ~ASTAssignmentStatement();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTASSIGNMENTSTATEMENT_H
