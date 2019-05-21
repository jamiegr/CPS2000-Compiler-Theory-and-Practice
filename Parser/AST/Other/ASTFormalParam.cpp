//
// Created by Jamie on 5/17/2019.
//

#include "ASTFormalParam.h"
#include "../../../Visitor/Visitor.h"

ASTFormalParam::ASTFormalParam(ASTIdentifierNode *identifierNode, ASTType *type) {
    this->identifierNode = identifierNode;
    this->type = type;
}

ASTFormalParam::~ASTFormalParam() {
    delete identifierNode;
    delete type;
}

void ASTFormalParam::Accept(Visitor *visitor) {
    visitor->visit(this);
}