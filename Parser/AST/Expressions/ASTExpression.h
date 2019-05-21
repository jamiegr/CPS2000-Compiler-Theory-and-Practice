//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTEXPRESSION_H
#define COMPILERASSIGNMENT_ASTEXPRESSION_H


#include "../Other/ASTRelOp.h"
#include "ASTSimpleExpression.h"

class ASTExpression : public ASTExpressionNode {
public:
    ASTExpressionNode *simpleExpression1;
    ASTRelOp *relOp;
    ASTExpressionNode *simpleExpression2;

    ASTExpression(ASTExpressionNode *simpleExpression1, ASTRelOp *relOp, ASTExpressionNode *simpleExpression2);

    ~ASTExpression();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTEXPRESSION_H
