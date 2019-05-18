//
// Created by Jamie on 5/18/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

enum REL_OP {
    LESS_THAN = 1,
    GREATER_THAN = 2,
    EQUAL_TO = 3,
    NOT_EQUAL_TO = 4,
    LESS_THAN_OR_EQUAL_TO = 5,
    GREATER_THAN_OR_EQUAL_TO = 6
};

class ASTRelOp : public ASTExpressionNode {
public:
    REL_OP value;

    ASTRelOp(REL_OP value);

    void Accept(Visitor *visitor) override;
};

