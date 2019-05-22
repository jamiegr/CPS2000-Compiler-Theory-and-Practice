//
// Created by Jamie on 5/22/2019.
//

#ifndef COMPILERASSIGNMENT_ASTOP_H
#define COMPILERASSIGNMENT_ASTOP_H

#include "ASTNode.h"

class ASTOp : public ASTNode {
public:
    virtual ~ASTOp() = default;//default destructor for abstract class
    void Accept(Visitor *visitor) override = 0;
};

#endif //COMPILERASSIGNMENT_ASTOP_H
