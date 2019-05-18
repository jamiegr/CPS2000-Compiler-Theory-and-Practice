//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include <string>
#include "../ASTStatementNode.h"
#include "../ASTExpressionNode.h"
#include "../Expressions/Factors/ASTIdentifierNode.h"

class ASTAssignmentStatement : ASTStatementNode {
public:
    ASTIdentifierNode *identifierNode;//the identifier which is being assigned a value
    ASTExpressionNode *expressionNode;//the expression whose result is to be assigned to the identifier
    ASTAssignmentStatement(ASTIdentifierNode *identifierNode, ASTExpressionNode *expressionNode);

    ~ASTAssignmentStatement();

    void Accept(Visitor *visitor) override;
};
