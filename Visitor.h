//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_VISITOR_H
#define COMPILERASSIGNMENT_VISITOR_H

#include "Parser/ASTAssignmentStatement.h"
#include "Parser/ASTBool.h"
#include "Parser/ASTFloat.h"
#include "Parser/ASTForStatement.h"
#include "Parser/ASTFunctionCall.h"
#include "Parser/ASTFunctionDeclStatement.h"
#include "Parser/ASTIfStatement.h"
#include "Parser/ASTIntNode.h"
#include "Parser/ASTPrintStatement.h"
#include "Parser/ASTReturnStatement.h"
#include "Parser/ASTSimpleExpression.h"
#include "Parser/ASTSubExpression.h"
#include "Parser/ASTUnaryNode.h"
#include "Parser/ASTVariableDeclStatement.h"
#include "Parser/ASTBlockStatement.h"
#include "Parser/ASTActualParams.h"
#include "Parser/ASTFormalParam.h"
#include "Parser/ASTFormalParams.h"

class Visitor {
public:
    virtual void visit(ASTActualParams *actualParams) = 0;
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
    virtual void visit(ASTPrintStatement *printStatement) = 0;
    virtual void visit(ASTReturnStatement *returnStatement) = 0;
    virtual void visit(ASTSimpleExpression *simpleExpression) = 0;
    virtual void visit(ASTSubExpression *subExpressionNode) = 0;
    virtual void visit(ASTUnaryNode *unaryNode) = 0;
    virtual void visit(ASTVariableDeclStatement *variableDeclStatement) = 0;
};


#endif //COMPILERASSIGNMENT_VISITOR_H
