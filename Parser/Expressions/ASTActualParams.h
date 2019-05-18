//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include <vector>
#include "../ASTExpressionNode.h"

class ASTActualParams : public ASTExpressionNode {
public:
    vector<ASTExpressionNode *> *parameters;

    explicit ASTActualParams(vector<ASTExpressionNode *> *parameters);

    ~ASTActualParams();

    void Accept(Visitor *visitor) override;
};

