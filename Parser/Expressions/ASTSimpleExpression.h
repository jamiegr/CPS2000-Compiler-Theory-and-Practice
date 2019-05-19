//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "ASTTerm.h"
#include "ASTAddOp.h"

class ASTSimpleExpression : ASTExpressionNode{
public:
    ASTTerm *term1;
    ASTAddOp *addOp;
    ASTTerm *term2;
    ASTSimpleExpression(ASTTerm *term1, ASTAddOp *addOp, ASTTerm *term2);
    ~ASTSimpleExpression();
    void Accept(Visitor *visitor) override;
};

