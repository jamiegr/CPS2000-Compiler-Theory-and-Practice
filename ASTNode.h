//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTNODE_H
#define COMPILERASSIGNMENT_ASTNODE_H

#include "Visitor.h"

class ASTNode{
public:
    virtual void Accept(Visitor *visitor) = 0;
};

#endif //COMPILERASSIGNMENT_ASTNODE_H
