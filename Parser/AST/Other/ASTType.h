//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTTYPE_H
#define COMPILERASSIGNMENT_ASTTYPE_H

#include <string>
#include "../ASTExpressionNode.h"

class ASTType : public ASTNode {
public:
    std::string value;

    ASTType(std::string value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTTYPE_H
