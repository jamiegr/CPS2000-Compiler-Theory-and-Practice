//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include "../ASTExpressionNode.h"

enum TYPE{FLOAT = 1, INT = 2, BOOL = 3};

class ASTType : public ASTExpressionNode{
public:
    TYPE value;
    ASTType(TYPE value);
    void Accept(Visitor *visitor) override;
};

