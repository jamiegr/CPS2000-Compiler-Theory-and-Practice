//
// Created by Jamie on 5/16/2019.
//

#ifndef COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H
#define COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H

#include <vector>
#include "../ASTStatementNode.h"

class ASTBlockStatement : public ASTStatementNode {
public:
    std::vector<ASTStatementNode*> *block;//a vector to store all the statements in the block
    explicit ASTBlockStatement(std::vector<ASTStatementNode*> *block);
    ~ASTBlockStatement();
    void Accept(Visitor *visitor) override;
};


#endif //COMPILERASSIGNMENT_ASTBLOCKSTATEMENT_H
