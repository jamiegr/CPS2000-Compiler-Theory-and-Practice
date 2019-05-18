//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include <string>
#include "../ASTFactorNode.h"

class ASTIdentifierNode : public ASTFactorNode {
public:
    string value;

    explicit ASTIdentifierNode(string value);

    void Accept(Visitor *visitor) override;
};

