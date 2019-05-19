//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include <vector>
#include "../ASTExpressionNode.h"

class ASTFormalParams : ASTExpressionNode {
public:
    vector<ASTFormalParam*> *formalParams;
    ASTFormalParams(vector<ASTFormalParam*> *formalParams);
    ~ASTFormalParams();
    void Accept(Visitor *visitor) override;
};

