//
// Created by Jamie on 5/18/2019.
//

#pragma once


#include "ASTRelOp.h"
#include "ASTSimpleExpression.h"

class ASTExpression : public ASTExpressionNode {
public:
    ASTSimpleExpression *simpleExpression1;
    ASTRelOp *relOp;
    ASTSimpleExpression *simpleExpression2;
    ASTExpression(ASTSimpleExpression *simpleExpression1, ASTRelOp *relOp, ASTSimpleExpression *simpleExpression2);
    ~ASTExpression();
    void Accept(Visitor *visitor) override;
};

