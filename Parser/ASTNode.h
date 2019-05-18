//
// Created by Jamie on 5/17/2019.
//

#pragma once

#include "../Visitor.h"

class ASTNode {
public:
    virtual void Accept(Visitor *visitor) = 0;
};