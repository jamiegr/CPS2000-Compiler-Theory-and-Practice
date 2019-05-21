//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTTYPE_H
#define COMPILERASSIGNMENT_ASTTYPE_H


#include "../ASTExpressionNode.h"

enum TYPE {
    FLOAT = 1, INT = 2, BOOL = 3
};

class ASTType : public ASTNode {
public:
    TYPE value;

    ASTType(TYPE value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTTYPE_H
