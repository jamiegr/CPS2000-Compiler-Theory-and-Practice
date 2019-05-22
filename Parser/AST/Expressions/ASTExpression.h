//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTEXPRESSION_H
#define COMPILERASSIGNMENT_ASTEXPRESSION_H

#include <vector>
#include "ASTFactorNode.h"
#include "../ASTOp.h"

class ASTExpression : public ASTExpressionNode {
public:
    ASTFactorNode *factor1;
    std::vector<ASTOp*> *ops;
    std::vector<ASTFactorNode*> *factors;

    ASTExpression(ASTFactorNode *factor1, std::vector<ASTOp*> *relOps, std::vector<ASTFactorNode*> *factors);

    ~ASTExpression();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTEXPRESSION_H
