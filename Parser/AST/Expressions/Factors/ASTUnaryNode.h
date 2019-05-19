//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTUNARYNODE_H
#define COMPILERASSIGNMENT_ASTUNARYNODE_H


#include "../ASTExpression.h"
#include "../ASTFactorNode.h"
#include "../ASTUnaryOp.h"

class ASTUnaryNode : public ASTFactorNode {
public:
    ASTUnaryOp *unaryOp;
    ASTExpression *expression;

    ASTUnaryNode(ASTUnaryOp *unaryOp, ASTExpression *expression);

    ~ASTUnaryNode();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTUNARYNODE_H
