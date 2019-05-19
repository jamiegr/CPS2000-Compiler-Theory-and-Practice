//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTTERM_H
#define COMPILERASSIGNMENT_ASTTERM_H


#include "../ASTNode.h"
#include "ASTFactorNode.h"
#include "ASTMultOp.h"

class ASTTerm : public ASTNode {
public:
    ASTFactorNode *factor1;
    ASTMultOp *multOp;
    ASTFactorNode *factor2;

    ASTTerm(ASTFactorNode *factor1, ASTMultOp *multOp, ASTFactorNode *factor2);

    ~ASTTerm();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTTERM_H
