//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_ASTSTATEMENT_H
#define COMPILERASSIGNMENT_ASTSTATEMENT_H


#include "Visitor.h"

class ASTStatement {

public:

    ASTStatement();

    virtual ~ASTStatement();

    virtual void Accept(Visitor *visitor) = 0;

};


#endif //COMPILERASSIGNMENT_ASTSTATEMENT_H
