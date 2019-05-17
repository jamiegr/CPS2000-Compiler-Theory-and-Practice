//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTBOOLNODE_H
#define COMPILERASSIGNMENT_ASTBOOLNODE_H


#include "ASTFactorNode.h"

class ASTBoolNode : public ASTFactorNode{
public:
    bool boolValue;
    explicit ASTBoolNode(bool boolValue);
    void Accept(Visitor *visitor);
};


#endif //COMPILERASSIGNMENT_ASTBOOLNODE_H
