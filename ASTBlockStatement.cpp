//
// Created by Jamie on 5/16/2019.
//

#include "ASTBlockStatement.h"

ASTBlockStatement::ASTBlockStatement(vector<ASTStatement*> *block){
    this->block = block;
}

ASTBlockStatement::~ASTBlockStatement(){
    block->clear();
}

void ASTBlockStatement::Accept(Visitor *visitor) {
    visitor->visit(this);
}