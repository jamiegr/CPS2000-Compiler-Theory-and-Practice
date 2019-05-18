//
// Created by Jamie on 5/16/2019.
//

#pragma once

#include "../ASTStatementNode.h"

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