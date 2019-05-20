//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTACTUALPARAMS_H
#define COMPILERASSIGNMENT_ASTACTUALPARAMS_H

#include <vector>
#include "ASTExpression.h"

class ASTActualParams : public ASTExpressionNode {
public:
    std::vector<ASTExpression *> *parameters;

    explicit ASTActualParams(std::vector<ASTExpression *> *parameters);

    ~ASTActualParams();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTACTUALPARAMS_H
