//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFORMALPARAMS_H
#define COMPILERASSIGNMENT_ASTFORMALPARAMS_H

#include <vector>
#include "ASTFormalParam.h"

class ASTFormalParams : public ASTNode {
public:
    std::vector<ASTFormalParam *> *formalParams;

    explicit ASTFormalParams(std::vector<ASTFormalParam *> *formalParams);

    ~ASTFormalParams();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFORMALPARAMS_H
