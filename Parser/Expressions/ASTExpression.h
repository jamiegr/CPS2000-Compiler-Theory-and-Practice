//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTEXPRESSION_H
#define COMPILERASSIGNMENT_ASTEXPRESSION_H

#include "ASTRelOp.h"
#include "ASTSimpleExpression.h"

class ASTExpression : public ASTExpressionNode {
public:
    ASTSimpleExpression *simpleExpression1;
    ASTRelOp *relOp;
    ASTSimpleExpression *simpleExpression2;

    ASTExpression(ASTSimpleExpression *simpleExpression1, ASTRelOp *relOp, ASTSimpleExpression *simpleExpression2);

    ~ASTExpression();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTEXPRESSION_H
