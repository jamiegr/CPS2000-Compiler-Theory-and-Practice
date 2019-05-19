//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFORMALPARAMS_H
#define COMPILERASSIGNMENT_ASTFORMALPARAMS_H

#include <vector>
#include "../ASTExpressionNode.h"

class ASTFormalParams : public ASTExpressionNode {
public:
    vector<ASTFormalParam*> *formalParams;
    ASTFormalParams(vector<ASTFormalParam*> *formalParams);
    ~ASTFormalParams();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFORMALPARAMS_H
