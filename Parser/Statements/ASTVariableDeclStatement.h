//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../Expressions/ASTType.h"
#include "../Expressions/ASTExpression.h"

class ASTVariableDeclStatement : public ASTStatementNode {
public:
    ASTIdentifierNode *identifierNode;
    ASTType *type;
    ASTExpression *expression;

    ASTVariableDeclStatement(ASTIdentifierNode *identifierNode, ASTType *type, ASTExpression *expression);

    ~ASTVariableDeclStatement();

    void Accept(Visitor *visitor) override;
};