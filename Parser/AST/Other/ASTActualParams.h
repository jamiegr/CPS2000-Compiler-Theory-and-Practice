//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTACTUALPARAMS_H
#define COMPILERASSIGNMENT_ASTACTUALPARAMS_H

#include <vector>
#include "../Expressions/ASTExpression.h"

class ASTActualParams : public ASTNode {
public:
    std::vector<ASTExpressionNode *> *parameters;

    explicit ASTActualParams(std::vector<ASTExpressionNode *> *parameters);

    ~ASTActualParams();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTACTUALPARAMS_H
