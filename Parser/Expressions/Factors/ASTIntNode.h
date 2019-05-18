//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTINTNODE_H
#define COMPILERASSIGNMENT_ASTINTNODE_H


#include "../ASTFactorNode.h"

class ASTIntNode : public ASTFactorNode{
public:
    int value;
    explicit ASTIntNode(int value);
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTINTNODE_H
