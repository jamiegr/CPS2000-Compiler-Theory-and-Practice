//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_ASTNODE_H
#define COMPILERASSIGNMENT_ASTNODE_H

#include <string>
#include "Visitor.h"

class ASTNode {

    ASTNode();

    virtual ~ASTNode();

    virtual void Accept(Visitor *visitor) = 0;

};


#endif //COMPILERASSIGNMENT_ASTNODE_H
