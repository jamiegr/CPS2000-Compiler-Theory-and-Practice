//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include "../ASTFactorNode.h"

class ASTIntNode : public ASTFactorNode {
public:
    int value;

    explicit ASTIntNode(int value);

    void Accept(Visitor *visitor) override;
};

