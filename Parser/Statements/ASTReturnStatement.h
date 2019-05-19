//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTStatementNode.h"

class ASTReturnStatement : public ASTStatementNode{
public:
    ASTExpressionNode *expression;
    ASTReturnStatement(ASTExpressionNode *expression);
    ~ASTReturnStatement();
    void Accept(Visitor *visitor) override;
};
