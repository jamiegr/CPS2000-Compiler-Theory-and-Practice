//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFUNCTIONDECLSTATEMENT_H
#define COMPILERASSIGNMENT_ASTFUNCTIONDECLSTATEMENT_H


#include "../ASTStatementNode.h"
#include "../Expressions/Factors/ASTIdentifierNode.h"
#include "../Other/ASTFormalParams.h"
#include "ASTBlockStatement.h"

class ASTFunctionDeclStatement : public ASTStatementNode {
public:
    ASTIdentifierNode *identifierNode;
    ASTFormalParams *formalParams;
    ASTType *type;
    ASTBlockStatement *blockStatement;

    ASTFunctionDeclStatement(ASTIdentifierNode *identifierNode, ASTFormalParams *formalParams, ASTType *type,
                             ASTBlockStatement *blockStatement);

    ~ASTFunctionDeclStatement();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFUNCTIONDECLSTATEMENT_H
