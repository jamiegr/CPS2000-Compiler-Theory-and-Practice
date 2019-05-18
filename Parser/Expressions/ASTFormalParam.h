//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFORMALPARAMNODE_H
#define COMPILERASSIGNMENT_ASTFORMALPARAMNODE_H


#include "../ASTExpressionNode.h"
#include "ASTType.h"

class ASTFormalParam : ASTExpressionNode {
public:
    ASTIdentifierNode *identifierNode;
    ASTType *type;

    ASTFormalParam(ASTIdentifierNode *identifierNode, ASTType *type);

    ~ASTFormalParam();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFORMALPARAMNODE_H
