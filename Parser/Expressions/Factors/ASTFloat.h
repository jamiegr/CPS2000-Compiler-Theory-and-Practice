//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include "../ASTFactorNode.h"

class ASTFloatNode : public ASTFactorNode {
public:
    float floatValue;

    explicit ASTFloatNode(float floatValue);

    void Accept(Visitor *visitor) override;
};

