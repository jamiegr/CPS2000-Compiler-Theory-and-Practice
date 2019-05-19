//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTNode.h"

class ASTFactorNode : public ASTNode {
public:
    void Accept(Visitor *visitor) override = 0;
};

