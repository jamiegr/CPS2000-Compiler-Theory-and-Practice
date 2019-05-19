//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H
#define COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H

#include <Vector>
#include "../ASTStatementNode.h"

using namespace std;

class ASTBlockStatement : public ASTStatementNode {
public:
    vector<ASTStatementNode*> *block;//a vector to store all the statements in the block
    explicit ASTBlockStatement(vector<ASTStatementNode*> *block);
    ~ASTBlockStatement();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H
