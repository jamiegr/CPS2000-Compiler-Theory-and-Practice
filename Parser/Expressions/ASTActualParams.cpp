//
// Created by Jamie on 5/17/2019.
//

#include "ASTActualParams.h"

ASTActualParams::ASTActualParams(vector<ASTExpressionNode *> *parameters) {
    this->parameters = parameters;
}

ASTActualParams::~ASTActualParams() {
    parameters->clear();
}

void ASTActualParams::Accept(Visitor *visitor) {
    visitor->visit(this);
}