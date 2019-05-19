//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFLOATNODE_H
#define COMPILERASSIGNMENT_ASTFLOATNODE_H


#include "../ASTFactorNode.h"

class ASTFloat : public ASTFactorNode {
public:
    float floatValue;

    explicit ASTFloat(float floatValue);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFLOATNODE_H
