//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTFactorNode.h"

class ASTFunctionCall : public ASTFactorNode {
public:
    ASTIdentifierNode *identifierNode;
    ASTActualParams *actualParams;

    ASTFunctionCall(ASTIdentifierNode *identifierNode, ASTActualParams *actualParams);

    ~ASTFunctionCall();

    void Accept(Visitor *visitor) override;
};

