//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTIFSTATEMENT_H
#define COMPILERASSIGNMENT_ASTIFSTATEMENT_H


#include "../ASTStatementNode.h"
#include "../Expressions/ASTExpression.h"
#include "ASTBlockStatement.h"

class ASTIfStatement : public ASTStatementNode{
public:
    ASTExpression *expression;
    ASTBlockStatement *ifBlock;
    ASTBlockStatement *elseBlock;
    ASTIfStatement(ASTExpression *expression, ASTBlockStatement *ifBlock, ASTBlockStatement *elseBlock);
    ~ASTIfStatement();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTIFSTATEMENT_H
