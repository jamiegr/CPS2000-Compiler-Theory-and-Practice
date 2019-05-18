//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTUNARYOP_H
#define COMPILERASSIGNMENT_ASTUNARYOP_H

#include "../ASTExpressionNode.h"

enum UNARY_OP {
    MINUS = 1, NOT = 2
};

class ASTUnaryOp : public ASTExpressionNode {
public:
    UNARY_OP value;

    ASTUnaryOp(UNARY_OP value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTUNARYOP_H
