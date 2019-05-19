//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTVARIABLEDECLSTATEMENT_H
#define COMPILERASSIGNMENT_ASTVARIABLEDECLSTATEMENT_H


#include "../Expressions/ASTType.h"
#include "../Expressions/ASTExpression.h"
#include "../ASTStatementNode.h"
#include "../Expressions/Factors/ASTIdentifierNode.h"

class ASTVariableDeclStatement : public ASTStatementNode {
public:
    ASTIdentifierNode *identifierNode;
    ASTType *type;
    ASTExpression *expression;

    ASTVariableDeclStatement(ASTIdentifierNode *identifierNode, ASTType *type, ASTExpression *expression);

    ~ASTVariableDeclStatement();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTVARIABLEDECLSTATEMENT_H
