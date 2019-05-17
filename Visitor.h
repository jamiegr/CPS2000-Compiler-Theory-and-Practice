//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_VISITOR_H
#define COMPILERASSIGNMENT_VISITOR_H

#include "ASTAssignmentStatement.h"
#include "ASTBoolNode.h"
#include "ASTFloatNode.h"
#include "ASTForStatement.h"
#include "ASTFunctionCallNode.h"
#include "ASTFunctionDeclStatement.h"
#include "ASTIfStatement.h"
#include "ASTIntNode.h"
#include "ASTPrintStatement.h"
#include "ASTReturnStatement.h"
#include "ASTSimpleExpression.h"
#include "ASTSubExpressionNode.h"
#include "ASTUnaryNode.h"
#include "ASTVariableDeclStatement.h"
#include "ASTBlockStatement.h"

class Visitor {
public:
    virtual void visit(ASTAssignmentStatement *assignmentStatement) = 0;
    virtual void visit(ASTBlockStatement *blockStatement) = 0;
    virtual void visit(ASTBoolNode *boolNode) = 0;
    virtual void visit(ASTFloatNode *floatNode) = 0;
    virtual void visit(ASTForStatement *forStatement) = 0;
    virtual void visit(ASTFunctionCallNode *functionCallNode) = 0;
    virtual void visit(ASTFunctionDeclStatement *functionDeclStatement) = 0;
    virtual void visit(ASTIdentifierNode *identifierNode) = 0;
    virtual void visit(ASTIfStatement *ifStatement) = 0;
    virtual void visit(ASTIntNode *intNode) = 0;
    virtual void visit(ASTPrintStatement *printStatement) = 0;
    virtual void visit(ASTReturnStatement *returnStatement) = 0;
    virtual void visit(ASTSimpleExpression *simpleExpression) = 0;
    virtual void visit(ASTSubExpressionNode *subExpressionNode) = 0;
    virtual void visit(ASTUnaryNode *unaryNode) = 0;
    virtual void visit(ASTVariableDeclStatement *variableDeclStatement) = 0;
};


#endif //COMPILERASSIGNMENT_VISITOR_H
