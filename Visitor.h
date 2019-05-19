//
// Created by Jamie on 5/12/2019.
//

#pragma once

#include "Parser/Statements/ASTAssignmentStatement.h"
#include "Parser/Expressions/Factors/ASTBool.h"
#include "Parser/Expressions/Factors/ASTFloat.h"
#include "Parser/Statements/ASTForStatement.h"
#include "Parser/Expressions/Factors/ASTFunctionCall.h"
#include "Parser/Statements/ASTFunctionDeclStatement.h"
#include "Parser/Statements/ASTIfStatement.h"
#include "Parser/Expressions/Factors/ASTIntNode.h"
#include "Parser/Statements/ASTPrintStatement.h"
#include "Parser/Statements/ASTReturnStatement.h"
#include "Parser/Expressions/ASTSimpleExpression.h"
#include "Parser/Expressions/Factors/ASTSubExpression.h"
#include "Parser/Expressions/Factors/ASTUnaryNode.h"
#include "Parser/Statements/ASTVariableDeclStatement.h"
#include "Parser/Statements/ASTBlockStatement.h"
#include "Parser/Expressions/ASTActualParams.h"
#include "Parser/Expressions/ASTFormalParam.h"
#include "Parser/Expressions/ASTFormalParams.h"
#include "Parser/Expressions/ASTAddOp.h"
#include "Parser/Expressions/ASTMultOp.h"
#include "Parser/Expressions/ASTRelOp.h"
#include "Parser/Expressions/ASTUnaryOp.h"

class Visitor {
public:
    virtual void visit(ASTActualParams *actualParams) = 0;
    virtual void visit(ASTAddOp *addOp) = 0;
    virtual void visit(ASTAssignmentStatement *assignmentStatement) = 0;
    virtual void visit(ASTBlockStatement *blockStatement) = 0;
    virtual void visit(ASTBool *boolNode) = 0;
    virtual void visit(ASTFloatNode *floatNode) = 0;
    virtual void visit(ASTFormalParam *formalParamNode) = 0;
    virtual void visit(ASTFormalParams *formalParams) = 0;
    virtual void visit(ASTForStatement *forStatement) = 0;
    virtual void visit(ASTFunctionCall *functionCallNode) = 0;
    virtual void visit(ASTFunctionDeclStatement *functionDeclStatement) = 0;
    virtual void visit(ASTIdentifierNode *identifierNode) = 0;
    virtual void visit(ASTIfStatement *ifStatement) = 0;
    virtual void visit(ASTIntNode *intNode) = 0;
    virtual void visit(ASTMultOp *multOp) = 0;
    virtual void visit(ASTPrintStatement *printStatement) = 0;
    virtual void visit(ASTRelOp *relOp) = 0;
    virtual void visit(ASTReturnStatement *returnStatement) = 0;
    virtual void visit(ASTSimpleExpression *simpleExpression) = 0;
    virtual void visit(ASTTerm *term) = 0;
    virtual void visit(ASTType *type) = 0;
    virtual void visit(ASTSubExpression *subExpressionNode) = 0;
    virtual void visit(ASTUnaryNode *unaryNode) = 0;
    virtual void visit(ASTUnaryOp *unaryOp) = 0;
    virtual void visit(ASTVariableDeclStatement *variableDeclStatement) = 0;
};
