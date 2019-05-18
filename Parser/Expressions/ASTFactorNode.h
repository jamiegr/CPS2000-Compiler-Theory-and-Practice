//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

class ASTFactorNode : public ASTExpressionNode {
public:
    void Accept(Visitor *visitor) override = 0;
};

