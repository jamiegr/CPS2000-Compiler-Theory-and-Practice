//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTSUBEXPRESSIONNODE_H
#define COMPILERASSIGNMENT_ASTSUBEXPRESSIONNODE_H


#include "../ASTExpression.h"
#include "../ASTFactorNode.h"

class ASTSubExpression : public ASTFactorNode{
public:
    ASTExpression *expression;
    ASTSubExpression(ASTExpression *expression);
    ~ASTSubExpression();
    void Accept(Visitor *visitor) override ;
};


#endif //COMPILERASSIGNMENT_ASTSUBEXPRESSIONNODE_H
