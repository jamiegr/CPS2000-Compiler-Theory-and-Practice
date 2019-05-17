//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTACTUALPARAMS_H
#define COMPILERASSIGNMENT_ASTACTUALPARAMS_H

#include <vector>
#include "ASTExpressionNode.h"

class ASTActualParams : public ASTExpressionNode {
public:
    vector<ASTExpressionNode*> *parameters;
    explicit ASTActualParams(vector<ASTExpressionNode*> *parameters);
    ~ASTActualParams();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTACTUALPARAMS_H
