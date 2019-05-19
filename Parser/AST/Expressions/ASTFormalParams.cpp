//
// Created by Jamie on 5/17/2019.
//

#include "ASTFormalParams.h"

ASTFormalParams::ASTFormalParams(vector<ASTFormalParam *> *formalParams) {
    this->formalParams = formalParams;
}

ASTFormalParams::~ASTFormalParams() {
    formalParams->clear();
}

void ASTFormalParams::Accept(Visitor *visitor) {
    visitor->visit(this);
}
