//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFORSTATEMENT_H
#define COMPILERASSIGNMENT_ASTFORSTATEMENT_H


#include "ASTVariableDeclStatement.h"
#include "ASTExpression.h"

class ASTForStatement {
public:
    ASTVariableDeclStatement *variableDeclStatement;
    ASTExpression *expression;
    ASTAssignmentStatement *assignmentStatement;
};


#endif //COMPILERASSIGNMENT_ASTFORSTATEMENT_H
