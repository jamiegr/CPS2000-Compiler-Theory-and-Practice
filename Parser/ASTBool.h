//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTBOOLNODE_H
#define COMPILERASSIGNMENT_ASTBOOLNODE_H


#include "ASTFactorNode.h"

class ASTBool : public ASTFactorNode{
public:
    bool boolValue;
    explicit ASTBool(bool boolValue);
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTBOOLNODE_H
