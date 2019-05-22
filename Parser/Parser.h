//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_PARSER_H
#define COMPILERASSIGNMENT_PARSER_H


#include "../Lexer/Lexer.h"
#include "AST/ASTNode.h"
#include "AST/Expressions/Factors/ASTBool.h"
#include "AST/Expressions/Factors/ASTFloat.h"
#include "AST/Expressions/Factors/ASTFunctionCall.h"
#include "AST/Expressions/Factors/ASTInt.h"
#include "AST/Expressions/Factors/ASTSubExpression.h"
#include "AST/Expressions/Factors/ASTUnaryNode.h"
#include "AST/Other/ASTFormalParam.h"
#include "AST/Other/ASTFormalParams.h"
#include "AST/Statements/ASTAssignmentStatement.h"
#include "AST/Statements/ASTBlockStatement.h"
#include "AST/Statements/ASTForStatement.h"
#include "AST/Statements/ASTFunctionDeclStatement.h"
#include "AST/Statements/ASTIfStatement.h"
#include "AST/Statements/ASTReturnStatement.h"
#include "AST/Statements/ASTPrintStatement.h"
#include "AST/Operators/ASTAddOp.h"
#include "AST/Operators/ASTMultOp.h"
#include "AST/Operators/ASTRelOp.h"

using namespace std;

class Parser {
public:
    explicit Parser(Lexer *lexer);

    vector<ASTNode *> *buildAST();

private:
    Lexer *lexer;
    Token currentToken, nextToken;

    void moveToNext();

    ASTStatementNode *parse();

    ASTBool *parseBool();

    ASTFloat *parseFloat();

    ASTFactorNode *parseFactor();

    ASTFunctionCall *parseFunctionCall();

    ASTIdentifierNode *parseIdentifierNode();

    ASTInt *parseInt();

    ASTSubExpression *parseSubExpression();

    ASTUnaryNode *parseUnaryNode();

    ASTActualParams *parseActualParams();

    ASTActualParams *parseActualParams(vector<ASTExpressionNode*> *actualParams);

    ASTAddOp *parseAddOp();

    ASTExpressionNode *parseExpression();

    ASTExpressionNode *parseExpression(ASTFactorNode *factor1, std::vector<ASTOp*> *relOps, std::vector<ASTFactorNode*> *factors);

    ASTFormalParam *parseFormalParam();

    ASTFormalParams *parseFormalParams();

    ASTFormalParams *parseFormalParams(vector<ASTFormalParam*> *formalParams);

    ASTMultOp *parseMultOp();

    ASTRelOp *parseRelOp();

    ASTType *parseType();

    ASTUnaryOp *parseUnaryOp();

    ASTAssignmentStatement *parseAssignmentStatement();

    ASTBlockStatement *parseBlockStatement();

    ASTBlockStatement *parseBlockStatement(vector<ASTStatementNode*>*statements);

    ASTForStatement *parseForStatement();

    ASTFunctionDeclStatement *parseFunctionDeclStatement();

    ASTIfStatement *parseIfStatement();

    ASTPrintStatement *parsePrintStatement();

    ASTReturnStatement *parseReturnStatement();

    ASTVariableDeclStatement *parseVariableDeclStatement();
};


#endif //COMPILERASSIGNMENT_PARSER_H
