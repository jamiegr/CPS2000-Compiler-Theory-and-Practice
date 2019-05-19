//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFACTORNODE_H
#define COMPILERASSIGNMENT_ASTFACTORNODE_H


#include "../ASTNode.h"

class ASTFactorNode : public ASTNode {
public:
    void Accept(Visitor *visitor) override = 0;
};


#endif //COMPILERASSIGNMENT_ASTFACTORNODE_H
