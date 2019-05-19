//
// Created by Jamie on 5/17/2019.
//

#include "ASTActualParams.h"
#include "../../../Visitor/Visitor.h"

ASTActualParams::ASTActualParams(std::vector<ASTExpression*> *parameters){
    this->parameters = parameters;
}

ASTActualParams::~ASTActualParams (){
    parameters->clear();
}

void ASTActualParams::Accept(Visitor *visitor) {
    visitor->visit(this);
}