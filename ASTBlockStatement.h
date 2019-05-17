//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H
#define COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H

#include <Vector>
#include "ASTStatement.h"

using namespace std;

class ASTBlockStatement : public ASTStatement {
public:
    vector<ASTStatement*> *block;//a vector to store all the statements in the block
    explicit ASTBlockStatement(vector<ASTStatement*> *block);
    ~ASTBlockStatement();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H
