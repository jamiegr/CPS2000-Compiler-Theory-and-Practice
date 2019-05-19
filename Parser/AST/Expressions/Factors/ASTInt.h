//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTINT_H
#define COMPILERASSIGNMENT_ASTINT_H


#include "../ASTFactorNode.h"

class ASTInt : public ASTFactorNode {
public:
    int value;

    explicit ASTInt(int value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTINT_H
