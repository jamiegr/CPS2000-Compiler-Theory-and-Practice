//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_ASTEXPRESSION_H
#define COMPILERASSIGNMENT_ASTEXPRESSION_H


#include "ASTNode.h"

class ASTExpression : public ASTNode {

public:

    ASTExpression();

    virtual ~ASTExpression();

    virtual void Accept(Visitor *visitor) = 0;

};


#endif //COMPILERASSIGNMENT_ASTEXPRESSION_H
