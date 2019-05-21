//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTADDOP_H
#define COMPILERASSIGNMENT_ASTADDOP_H

#include "../ASTExpressionNode.h"

enum ADD_OP {
    PLUS = 1, MINUS = 2, OR = 3
};

class ASTAddOp : public ASTNode {
public:
    ADD_OP value;

    ASTAddOp(ADD_OP value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTADDOP_H
