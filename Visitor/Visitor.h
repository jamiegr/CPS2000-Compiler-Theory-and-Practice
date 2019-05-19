//
// Created by Jamie on 5/19/2019.
//

#ifndef COMPILERASSIGNMENT_VISITOR_H
#define COMPILERASSIGNMENT_VISITOR_H


#include "../Parser/AST/Expressions/Factors/ASTBool.h"
#include "../Parser/AST/Expressions/Factors/ASTFloat.h"
#include "../Parser/AST/Expressions/Factors/ASTInt.h"
#include "../Parser/AST/Expressions/Factors/ASTSubExpression.h"
#include "../Parser/AST/Expressions/Factors/ASTUnaryNode.h"
#include "../Parser/AST/Expressions/ASTActualParams.h"
#include "../Parser/AST/Expressions/ASTFormalParam.h"
#include "../Parser/AST/Expressions/ASTFormalParams.h"
#include "../Parser/AST/Expressions/ASTUnaryOp.h"
#include "../Parser/AST/Statements/ASTAssignmentStatement.h"
#include "../Parser/AST/Statements/ASTBlockStatement.h"
#include "../Parser/AST/Statements/ASTForStatement.h"
#include "../Parser/AST/Statements/ASTIfStatement.h"
#include "../Parser/AST/Statements/ASTPrintStatement.h"
#include "../Parser/AST/Statements/ASTReturnStatement.h"
#include "../Parser/AST/Expressions/Factors/ASTFunctionCall.h"
#include "../Parser/AST/Statements/ASTFunctionDeclStatement.h"

class Visitor {
public:
    virtual void visit(ASTBool *node) = 0;
    virtual void visit(ASTFloat *node) = 0;
    virtual void visit(ASTIdentifierNode *node) = 0;
    virtual void visit(ASTFunctionCall *node) = 0;
    virtual void visit(ASTInt *node) = 0;
    virtual void visit(ASTSubExpression *node) = 0;
    virtual void visit(ASTUnaryNode *node) = 0;
    virtual void visit(ASTActualParams *node) = 0;
    virtual void visit(ASTAddOp *node) = 0;
    virtual void visit(ASTExpression *node) = 0;
    virtual void visit(ASTFormalParam *node) = 0;
    virtual void visit(ASTFormalParams *node) = 0;
    virtual void visit(ASTMultOp *node) = 0;
    virtual void visit(ASTRelOp *node) = 0;
    virtual void visit(ASTSimpleExpression *node) = 0;
    virtual void visit(ASTTerm *node) = 0;
    virtual void visit(ASTType *node) = 0;
    virtual void visit(ASTUnaryOp *node) = 0;
    virtual void visit(ASTAssignmentStatement *node) = 0;
    virtual void visit(ASTBlockStatement *node) = 0;
    virtual void visit(ASTForStatement *node) = 0;
    virtual void visit(ASTFunctionDeclStatement *node) = 0;
    virtual void visit(ASTIfStatement *node) = 0;
    virtual void visit(ASTPrintStatement *node) = 0;
    virtual void visit(ASTReturnStatement *node) = 0;
    virtual void visit(ASTVariableDeclStatement *node) = 0;
};


#endif //COMPILERASSIGNMENT_VISITOR_H
