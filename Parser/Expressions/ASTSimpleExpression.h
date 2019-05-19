//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTSIMPLEEXPRESSION_H
#define COMPILERASSIGNMENT_ASTSIMPLEEXPRESSION_H


#include "ASTTerm.h"
#include "ASTAddOp.h"

class ASTSimpleExpression : ASTExpressionNode{
public:
    ASTTerm *term1;
    ASTAddOp *addOp;
    ASTTerm *term2;
    ASTSimpleExpression(ASTTerm *term1, ASTAddOp *addOp, ASTTerm *term2);
    ~ASTSimpleExpression();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTSIMPLEEXPRESSION_H
