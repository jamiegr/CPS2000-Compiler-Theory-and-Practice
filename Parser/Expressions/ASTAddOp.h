//
// Created by Jamie on 5/18/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

enum ADD_OP {
    PLUS = 1, MINUS = 2, OR = 3
};

class ASTAddOp : public ASTExpressionNode {
public:
    ADD_OP value;

    ASTAddOp(ADD_OP value);

    void Accept(Visitor *visitor) override;
};

