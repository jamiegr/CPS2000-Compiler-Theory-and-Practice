//
// Created by Jamie on 5/18/2019.
//

#ifndef COMPILERASSIGNMENT_ASTRELOP_H
#define COMPILERASSIGNMENT_ASTRELOP_H

#include "../ASTExpressionNode.h"
#include "../ASTOp.h"

class ASTRelOp : public ASTOp {
public:
    std::string value;

    ASTRelOp(std::string value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTRELOP_H
