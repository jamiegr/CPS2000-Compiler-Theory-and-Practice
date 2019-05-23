//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTMULTOP_H
#define COMPILERASSIGNMENT_ASTMULTOP_H

#include "../ASTExpressionNode.h"
#include "../ASTOp.h"

class ASTMultOp : public ASTOp {
public:
    std::string value;

    ASTMultOp(std::string value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTMULTOP_H
