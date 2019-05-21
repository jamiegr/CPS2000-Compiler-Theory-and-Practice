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
#include "AST/Expressions/ASTFormalParam.h"
#include "AST/Expressions/ASTFormalParams.h"
#include "AST/Statements/ASTAssignmentStatement.h"
#include "AST/Statements/ASTBlockStatement.h"
#include "AST/Statements/ASTForStatement.h"
#include "AST/Statements/ASTFunctionDeclStatement.h"
#include "AST/Statements/ASTIfStatement.h"
#include "AST/Statements/ASTReturnStatement.h"
#include "AST/Statements/ASTPrintStatement.h"

class Parser {
public:
    explicit Parser(Lexer lexer);

    vector<ASTNode *> *buildAST();

private:
    Lexer lexer;
    Token currentToken, nextToken;

    void moveToNext();

    ASTNode *parse();

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

    ASTFormalParam *parseFormalParam();

    ASTFormalParams *parseFormalParams();

    ASTMultOp *parseMultOp();

    ASTRelOp *parseRelOp();

    ASTSimpleExpression *parseSimpleExpression();

    ASTTerm *parseTerm();

    ASTType *parseType();

    ASTUnaryOp *parseUnaryOp();

    ASTAssignmentStatement *parseAssignmentStatement();

    ASTBlockStatement *parseBlockStatement();

    ASTForStatement *parseForStatement();

    ASTFunctionDeclStatement *parseFunctionDeclStatement();

    ASTIfStatement *parseIfStatement();

    ASTPrintStatement *parsePrintStatement();

    ASTReturnStatement *parseReturnStatement();

    ASTVariableDeclStatement *parseVariableDeclStatement();
};


#endif //COMPILERASSIGNMENT_PARSER_H
