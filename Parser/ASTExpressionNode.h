//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_ASTEXPRESSION_H
#define COMPILERASSIGNMENT_ASTEXPRESSION_H

#include "ASTNode.h"

class ASTExpressionNode : public ASTNode {
public:
    void Accept(Visitor *visitor) override = 0;
};


#endif //COMPILERASSIGNMENT_ASTEXPRESSION_H