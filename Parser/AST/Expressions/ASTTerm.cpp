//
// Created by Jamie on 5/18/2019.
//

#include "ASTTerm.h"
#include "../../../Visitor/Visitor.h"

ASTTerm::ASTTerm(ASTExpressionNode *factor1, ASTMultOp *multOp, ASTExpressionNode *factor2) {
    this->factor1 = factor1;
    this->multOp = multOp;
    this->factor2 = factor2;
}

ASTTerm::~ASTTerm() {
    delete factor1;
    delete multOp;
    delete factor2;
}

void ASTTerm::Accept(Visitor *visitor) {
    visitor->visit(this);
}