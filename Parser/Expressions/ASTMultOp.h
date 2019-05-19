//
// Created by Jamie on 5/18/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

enum MULT_OP{MULTIPLICATION = 1, DIVISION = 2, AND = 3};

class ASTMultOp : public ASTExpressionNode{
public:
    MULT_OP value;
    ASTMultOp(MULT_OP value);
    void Accept(Visitor *visitor) override;
};

