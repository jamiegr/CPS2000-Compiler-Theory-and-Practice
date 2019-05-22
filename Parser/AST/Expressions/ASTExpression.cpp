//
// Created by Jamie on 5/18/2019.
//

#include "ASTExpression.h"
#include "../../../Visitor/Visitor.h"

ASTExpression::ASTExpression(ASTFactorNode *factor1, std::vector<ASTOp*> *relOps, std::vector<ASTFactorNode*> *factors) {
    this->factor1 = factor1;
    this->ops = ops;
    this->factors = factors;
}


ASTExpression::~ASTExpression() {
    delete factor1;
    ops->clear();
    factors->clear();
}

void ASTExpression::Accept(Visitor *visitor) {
    visitor->visit(this);
}