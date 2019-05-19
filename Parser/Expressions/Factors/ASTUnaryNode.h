//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTExpression.h"
#include "../ASTFactorNode.h"

class ASTUnaryNode : public ASTFactorNode {
public:
    ASTUnaryOp *unaryOp;
    ASTExpression *expression;
    ASTUnaryNode(ASTUnaryOp *unaryOp, ASTExpression *expression);
    ~ASTUnaryNode();
    void Accept(Visitor *visitor) override;
};

