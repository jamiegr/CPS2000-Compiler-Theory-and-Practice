//
// Created by Jamie on 5/16/2019.
//

#include "ASTFunctionDeclStatement.h"
#include "../../../Visitor/Visitor.h"

ASTFunctionDeclStatement::ASTFunctionDeclStatement(ASTIdentifierNode *identifierNode, ASTFormalParams *formalParams,
                                                   ASTType *type, ASTBlockStatement *blockStatement) {
    this->identifierNode = identifierNode;
    this->formalParams = formalParams;
    this->type = type;
    this->blockStatement = blockStatement;
}

ASTFunctionDeclStatement::~ASTFunctionDeclStatement() {
    delete identifierNode;
    delete formalParams;
    delete type;
    delete blockStatement;
}

void ASTFunctionDeclStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}
