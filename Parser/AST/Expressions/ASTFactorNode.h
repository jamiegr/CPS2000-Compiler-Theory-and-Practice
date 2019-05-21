//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFACTORNODE_H
#define COMPILERASSIGNMENT_ASTFACTORNODE_H


#include "../ASTExpressionNode.h"

class ASTFactorNode : public ASTExpressionNode {
public:
    virtual ~ASTFactorNode() = default;//virtual destructor for abstract class
    void Accept(Visitor *visitor) override = 0;
};


#endif //COMPILERASSIGNMENT_ASTFACTORNODE_H
