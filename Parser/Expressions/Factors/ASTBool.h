//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include "../ASTFactorNode.h"

class ASTBool : public ASTFactorNode{
public:
    bool boolValue;
    explicit ASTBool(bool boolValue);
    void Accept(Visitor *visitor) override;
};