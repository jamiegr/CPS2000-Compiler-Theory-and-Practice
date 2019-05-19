//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTIDENTIFIERNODE_H
#define COMPILERASSIGNMENT_ASTIDENTIFIERNODE_H

#include "../ASTFactorNode.h"
#include <string>

class ASTIdentifierNode : public ASTFactorNode {
public:
    std::string value;
    explicit ASTIdentifierNode(std::string value);
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTIDENTIFIERNODE_H
