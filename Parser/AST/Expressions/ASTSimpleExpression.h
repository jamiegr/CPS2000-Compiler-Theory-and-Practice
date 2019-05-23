//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTSIMPLEEXPRESSION_H
#define COMPILERASSIGNMENT_ASTSIMPLEEXPRESSION_H


#include "ASTTerm.h"
#include "../Operators/ASTAddOp.h"

class ASTSimpleExpression : public ASTExpressionNode {
public:
    ASTExpressionNode *term1;
    ASTAddOp *addOp;
    ASTExpressionNode *term2;

    ASTSimpleExpression(ASTExpressionNode *term1, ASTAddOp *addOp, ASTExpressionNode *term2);

    ~ASTSimpleExpression();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTSIMPLEEXPRESSION_H