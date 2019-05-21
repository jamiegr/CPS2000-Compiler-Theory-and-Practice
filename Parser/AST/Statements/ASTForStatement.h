//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFORSTATEMENT_H
#define COMPILERASSIGNMENT_ASTFORSTATEMENT_H


#include "../ASTStatementNode.h"
#include "../Expressions/ASTExpression.h"
#include "ASTVariableDeclStatement.h"
#include "ASTAssignmentStatement.h"
#include "ASTBlockStatement.h"

class ASTForStatement : public ASTStatementNode {
public:
    ASTVariableDeclStatement *variableDeclStatement;
    ASTExpressionNode *expression;
    ASTAssignmentStatement *assignmentStatement;
    ASTBlockStatement *forBlock;
    ASTForStatement(ASTVariableDeclStatement *variableDeclStatement, ASTExpressionNode *expression,
                    ASTAssignmentStatement *assignmentStatement, ASTBlockStatement *forBlock);

    ~ASTForStatement();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFORSTATEMENT_H
