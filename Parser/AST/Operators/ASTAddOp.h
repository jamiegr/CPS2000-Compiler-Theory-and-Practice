//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTADDOP_H
#define COMPILERASSIGNMENT_ASTADDOP_H

#include "../ASTExpressionNode.h"
#include "../ASTOp.h"

class ASTAddOp : public ASTOp {
public:
    std::string value;

    ASTAddOp(std::string value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTADDOP_H
