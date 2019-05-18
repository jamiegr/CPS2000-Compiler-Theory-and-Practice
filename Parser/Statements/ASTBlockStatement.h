//
// Created by Jamie on 5/16/2019.
//
#pragma once

#include <Vector>
#include "../ASTStatementNode.h"

using namespace std;

class ASTBlockStatement : public ASTStatementNode {
public:
    vector<ASTStatementNode *> *block;//a vector to store all the statements in the block
    explicit ASTBlockStatement(vector<ASTStatementNode *> *block);

    ~ASTBlockStatement();

    void Accept(Visitor *visitor) override;
};
