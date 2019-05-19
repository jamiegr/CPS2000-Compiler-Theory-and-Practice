//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include "../ASTExpressionNode.h"
#include "ASTType.h"

class ASTFormalParam : ASTExpressionNode{
public:
    ASTIdentifierNode *identifierNode;
    ASTType *type;
    ASTFormalParam(ASTIdentifierNode *identifierNode, ASTType *type);
    ~ASTFormalParam();
    void Accept(Visitor *visitor) override;
};

