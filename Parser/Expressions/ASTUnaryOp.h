//
// Created by Jamie on 5/18/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

enum UNARY_OP{MINUS = 1, NOT = 2};

class ASTUnaryOp : public ASTExpressionNode {
public:
    UNARY_OP value;
    ASTUnaryOp(UNARY_OP value);
    void Accept(Visitor *visitor) override;
};
