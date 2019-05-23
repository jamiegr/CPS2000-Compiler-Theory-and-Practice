//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTUNARYOP_H
#define COMPILERASSIGNMENT_ASTUNARYOP_H

#include "../ASTExpressionNode.h"
#include "../ASTOp.h"

class ASTUnaryOp : public ASTOp {
public:
    std::string value;

    ASTUnaryOp(std::string value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTUNARYOP_H
