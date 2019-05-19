//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTExpression.h"
#include "../ASTFactorNode.h"

class ASTSubExpression : ASTFactorNode{
public:
    ASTExpression *expression;
    ASTSubExpression(ASTExpression *expression);
    ~ASTSubExpression();
    void Accept(Visitor *visitor) override ;
};

