//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_ASTSTATEMENT_H
#define COMPILERASSIGNMENT_ASTSTATEMENT_H

#include "ASTNode.h"

class ASTStatementNode : public ASTNode {
public:
    void Accept(Visitor *visitor) override = 0;
};


#endif //COMPILERASSIGNMENT_ASTSTATEMENT_H
