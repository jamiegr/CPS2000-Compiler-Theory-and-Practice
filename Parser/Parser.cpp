//
// Created by Jamie on 5/12/2019.
//

#include "Parser.h"

Parser::Parser(Lexer lexer) {
    this->lexer = lexer;
}

std::vector<ASTNode *> *Parser::buildAST() {
    std::vector<ASTNode*> *AST = new vector<ASTNode*>;
    currentToken = lexer.getNextToken();
    while(currentToken.getType() != TOK_EOF){
        AST->push_back(parse());
    }
}

ASTNode *Parser::parse() {

}

ASTBool *Parser::parseBool() {
    return nullptr;
}

ASTFloat *Parser::parseFloat() {
    return nullptr;
}

ASTFunctionCall *Parser::parseFunctionCall() {
    return nullptr;
}

ASTIdentifierNode *Parser::parseIdentifierNode() {
    return nullptr;
}

ASTInt *Parser::parseInt() {
    return nullptr;
}

ASTSubExpression *Parser::parseSubExpression() {
    return nullptr;
}

ASTUnaryNode *Parser::parseUnaryNode() {
    return nullptr;
}

ASTActualParams *Parser::parseActualParams() {
    return nullptr;
}

ASTAddOp *Parser::parseAddOp() {
    return nullptr;
}

ASTExpression *Parser::parseExpression() {
    return nullptr;
}

ASTFormalParam *Parser::parseFormalParam() {
    return nullptr;
}

ASTFormalParams *Parser::parseFormalParams() {
    return nullptr;
}

ASTMultOp *Parser::parseMultOp() {
    return nullptr;
}

ASTRelOp *Parser::parseRelOp() {
    return nullptr;
}

ASTSimpleExpression *Parser::parseSimpleExpression() {
    return nullptr;
}

ASTTerm *Parser::parseTerm() {
    return nullptr;
}

ASTType *Parser::parseType() {
    return nullptr;
}

ASTUnaryOp *Parser::parseUnaryOp() {
    return nullptr;
}

ASTAssignmentStatement *Parser::parseAssignmentStatement() {
    return nullptr;
}

ASTBlockStatement *Parser::parseBlockStatement() {
    return nullptr;
}

ASTForStatement *Parser::parseForStatement() {
    return nullptr;
}

ASTFunctionDeclStatement *Parser::parseFunctionDeclStatement() {
    return nullptr;
}

ASTIfStatement *Parser::parseIfStatement() {
    return nullptr;
}

ASTPrintStatement *Parser::parsePrintStatement() {
    return nullptr;
}

ASTReturnStatement *Parser::parseReturnStatement() {
    return nullptr;
}

ASTVariableDeclStatement *Parser::parseVariableDeclStatement() {
    return nullptr;
}


