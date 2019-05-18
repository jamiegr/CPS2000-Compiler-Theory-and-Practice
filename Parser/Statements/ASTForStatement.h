//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTStatementNode.h"

class ASTForStatement : public ASTStatementNode {
public:
    ASTVariableDeclStatement *variableDeclStatement;
    ASTExpressionNode *expression;
    ASTAssignmentStatement *assignmentStatement;

    ASTForStatement(ASTVariableDeclStatement *variableDeclStatement, ASTExpressionNode *expression,
                    ASTAssignmentStatement *assignmentStatement);

    ~ASTForStatement();

    void Accept(Visitor *visitor) override;
};

