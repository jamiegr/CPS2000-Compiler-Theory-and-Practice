//
// Created by Jamie on 5/12/2019.
//
#pragma once

#include "ASTNode.h"

class ASTStatementNode : public ASTNode {
public:
    void Accept(Visitor *visitor) override = 0;
};