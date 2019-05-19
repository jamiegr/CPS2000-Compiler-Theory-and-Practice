//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTRETURNSTATEMENT_H
#define COMPILERASSIGNMENT_ASTRETURNSTATEMENT_H


#include "../ASTStatementNode.h"
#include "../Expressions/ASTExpression.h"

class ASTReturnStatement : public ASTStatementNode{
public:
    ASTExpression *expression;
    ASTReturnStatement(ASTExpression *expression);
    ~ASTReturnStatement();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTRETURNSTATEMENT_H
