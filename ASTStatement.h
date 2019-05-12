//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_ASTSTATEMENT_H
#define COMPILERASSIGNMENT_ASTSTATEMENT_H


#include "Visitor.h"
#include "ASTNode.h"

class ASTStatement : public ASTNode {

public:

    ASTStatement();

    virtual ~ASTStatement();

    virtual void Accept(Visitor *visitor) = 0;

};


#endif //COMPILERASSIGNMENT_ASTSTATEMENT_H
