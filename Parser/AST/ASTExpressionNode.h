//
// Created by Jamie on 5/20/2019.
//

#ifndef COMPILERASSIGNMENT_ASTEXPRESSIONNODE_H
#define COMPILERASSIGNMENT_ASTEXPRESSIONNODE_H

#include "ASTNode.h"

class ASTExpressionNode : public ASTNode {
public:
    virtual ~ASTExpressionNode() = default;//virtual destructor for abstract class
    void Accept(Visitor *visitor) override = 0;
};

#endif //COMPILERASSIGNMENT_ASTEXPRESSIONNODE_H
