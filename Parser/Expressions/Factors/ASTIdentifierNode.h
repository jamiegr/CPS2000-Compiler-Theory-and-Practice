//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTIDENTIFIERNODE_H
#define COMPILERASSIGNMENT_ASTIDENTIFIERNODE_H

#include <string>
#include "../ASTFactorNode.h"

class ASTIdentifierNode : public ASTFactorNode {
public:
    string value;

    explicit ASTIdentifierNode(string value);

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTIDENTIFIERNODE_H
