//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTStatementNode.h"

class ASTPrintStatement : public ASTStatementNode {
public:
    ASTExpressionNode *expression;

    ASTPrintStatement(ASTExpressionNode *expression);

    ~ASTPrintStatement();

    void Accept(Visitor *visitor) override;
};
