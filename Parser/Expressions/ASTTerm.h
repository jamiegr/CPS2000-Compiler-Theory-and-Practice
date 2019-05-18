//
// Created by Jamie on 5/18/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

class ASTTerm : ASTExpressionNode {
public:
    ASTFactorNode *factor1;
    ASTMultOp *multOp;
    ASTFactorNode *factor2;

    ASTTerm(ASTFactorNode *factor1, ASTMultOp *multOp, ASTFactorNode *factor2);

    ~ASTTerm();

    void Accept(Visitor *visitor) override;
};

