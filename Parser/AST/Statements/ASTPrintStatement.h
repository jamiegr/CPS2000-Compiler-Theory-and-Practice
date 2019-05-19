//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTPRINTSTATEMENT_H
#define COMPILERASSIGNMENT_ASTPRINTSTATEMENT_H


#include "../ASTStatementNode.h"
#include "../Expressions/ASTExpression.h"

class ASTPrintStatement : public ASTStatementNode{
public:
    ASTExpression *expression;
    ASTPrintStatement(ASTExpression *expression);
    ~ASTPrintStatement();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTPRINTSTATEMENT_H
