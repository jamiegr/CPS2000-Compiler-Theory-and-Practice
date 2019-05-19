//
// Created by Jamie on 5/16/2019.
//

#include "ASTFunctionCall.h"

ASTFunctionCall::ASTFunctionCall(ASTIdentifierNode *identifierNode, ASTActualParams *actualParams){
    this->identifierNode = identifierNode;
    this->actualParams = actualParams;
}

ASTFunctionCall::~ASTFunctionCall(){
    delete identifierNode;
    delete actualParams;
}

void ASTFunctionCall::Accept(Visitor *visitor){
    visitor->visit(this);
}