//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTFUNCTIONCALLNODE_H
#define COMPILERASSIGNMENT_ASTFUNCTIONCALLNODE_H


#include "../ASTFactorNode.h"
#include "ASTIdentifierNode.h"
#include "../../Other/ASTActualParams.h"

class ASTFunctionCall : public ASTFactorNode {
public:
    ASTIdentifierNode *identifierNode;
    ASTActualParams *actualParams;

    ASTFunctionCall(ASTIdentifierNode *identifierNode, ASTActualParams *actualParams);

    ~ASTFunctionCall();

    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTFUNCTIONCALLNODE_H
