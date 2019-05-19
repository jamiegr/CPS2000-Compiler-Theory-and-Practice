//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTMULTOP_H
#define COMPILERASSIGNMENT_ASTMULTOP_H

#include "../ASTNode.h"

enum MULT_OP {
    MULTIPLICATION = 1, DIVISION = 2, AND = 3
};

class ASTMultOp : public ASTNode {
public:
    MULT_OP value;

    ASTMultOp(MULT_OP value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTMULTOP_H
