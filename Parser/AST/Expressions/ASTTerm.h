//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTTERM_H
#define COMPILERASSIGNMENT_ASTTERM_H


#include "ASTFactorNode.h"
#include "../Operators/ASTMultOp.h"
#include "../ASTExpressionNode.h"

class ASTTerm : public ASTExpressionNode {
public:
    ASTExpressionNode *factor1;
    ASTMultOp *multOp;
    ASTExpressionNode *factor2;

    ASTTerm(ASTExpressionNode *factor1, ASTMultOp *multOp, ASTExpressionNode *factor2);

    ~ASTTerm();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTTERM_H