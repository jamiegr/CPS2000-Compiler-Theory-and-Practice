//
// Created by Jamie on 5/12/2019.
//

#include "Parser.h"

using namespace std;

Parser::Parser(Lexer lexer) {
    this->lexer = lexer;
}

vector<ASTNode *> *Parser::buildAST() {
    vector<ASTNode*> *AST = new vector<ASTNode*>;
    nextToken = lexer.getNextToken();
    moveToNext();
    ASTNode *currentNode;
    while(currentToken.getType() != TOK_EOF){
        currentNode = parse();
        if(currentNode != nullptr){
            AST->push_back(currentNode);
        }else{
            cout << "Parsing error occured, parser terminating." << endl;
            return nullptr;
        }
    }
    return AST;
}

ASTNode *Parser::parse() {
    switch(currentToken.getType()){
        case TOK_VAR_DECL: return parseVariableDeclStatement();
        case TOK_PRINT: return parsePrintStatement();
        case TOK_RETURN: return parseReturnStatement();
        case TOK_IF: return parseIfStatement();
        case TOK_FOR: return parseForStatement();
        case TOK_IDENTIFIER: return parseAssignmentStatement();
        case TOK_FUNC_DECL: return parseFunctionDeclStatement();
        case TOK_OPEN_SCOPE: return parseBlockStatement();
        default: return nullptr;
    }
}

ASTFactorNode *Parser::parseFactor() {
    switch(currentToken.getType()){
        case TOK_BOOL_LIT: return parseBool();
        case TOK_INT_LIT: return parseInt();
        case TOK_FLOAT_LIT: return parseFloat();
        case TOK_IDENTIFIER:
            if(nextToken.getType() == TOK_OPEN_PARENTHESES) return parseFunctionCall();
            else return parseIdentifierNode();
        case TOK_OPEN_PARENTHESES: return parseSubExpression();
        case TOK_UNARY_OP: return parseUnaryNode();
        default:
            if(currentToken.getType() == TOK_ADD_OP && currentToken.getValue() == "-") return parseUnaryNode();
            else return nullptr;
    }
}

ASTBool *Parser::parseBool() {
    if(currentToken.getType() == TOK_BOOL_LIT){
        if(currentToken.getValue() == "true"){
            moveToNext();
            return new ASTBool(true);
        }else if(currentToken.getValue() == "false"){
            moveToNext();
            return new ASTBool(false);
        }else{
            cout << "Parsing error occurred when parsing boolean literal." << endl;
            return nullptr;
        }
    }else{
        cout << "Token doesn't match expected type: boolean literal." << endl;
        return nullptr;
    }
}

ASTFloat *Parser::parseFloat() {
    if(currentToken.getType() == TOK_FLOAT_LIT){
        try{
            float value = stof(currentToken.getValue());
            moveToNext();
            return new ASTFloat(value);
        }catch(invalid_argument){
            cout << "Parsing error occurred when parsing float literal." << endl;
            return nullptr;
        }catch(out_of_range){
            cout << "Given float literal is out of float type memory range, underflow or overflow occurred" << endl;
            return nullptr;
        }
    }else{
        cout << "Token doesn't match expected type: float literal." << endl;
        return nullptr;
    }
}

ASTFunctionCall *Parser::parseFunctionCall() {
    ASTIdentifierNode *identifierNode = parseIdentifierNode();
    moveToNext();
    if(currentToken.getType() == TOK_OPEN_PARENTHESES){
        moveToNext();
        ASTActualParams *actualParams = parseActualParams();
        if(nextToken.getType() == TOK_CLOSE_PARENTHESES){
            if(identifierNode != nullptr && actualParams != nullptr){
                moveToNext();
                return new ASTFunctionCall(identifierNode, actualParams);
            }else{
                cout << "Error parsing function call node" << endl;
                return nullptr;
            }
        }else{
            cout << "')' expected after parameters in function call" << endl;
            return nullptr;
        }
    }else{
        cout << "'(' expected after identifier in function call" << endl;
        return nullptr;
    }
}

ASTIdentifierNode *Parser::parseIdentifierNode() {
    if(currentToken.getType() == TOK_IDENTIFIER){
        string value = currentToken.getValue();
        moveToNext();
        return new ASTIdentifierNode(value);
    }else{
        cout << "Token doesn't match expected type: identifier" << endl;
        return nullptr;
    }
}

ASTInt *Parser::parseInt() {
    if(currentToken.getType() == TOK_INT_LIT){
        try{
            float value = stoi(currentToken.getValue());
            moveToNext();
            return new ASTInt(value);
        }catch(invalid_argument){
            cout << "Parsing error occurred when parsing int literal." << endl;
            return nullptr;
        }catch(out_of_range){
            cout << "Given float literal is out of int type memory range, underflow or overflow occurred" << endl;
            return nullptr;
        }
    }else{
        cout << "Token doesn't match expected type: int literal." << endl;
        return nullptr;
    }
}

ASTSubExpression *Parser::parseSubExpression() {
    if(currentToken.getType() == TOK_OPEN_PARENTHESES){
        moveToNext();
        ASTExpressionNode *expression = parseExpression();
        if(expression == nullptr){
            cout << "Parsing error occurred when parsing sub expression." << endl;
            return nullptr;
        }else if(currentToken.getType() != TOK_CLOSE_PARENTHESES){
            cout << "')' expected after expression in sub expression" << endl;
            return nullptr;
        }else{
            moveToNext();
            return new ASTSubExpression(expression);
        }
    }
}

ASTUnaryNode *Parser::parseUnaryNode() {
    ASTUnaryOp *unaryOp = parseUnaryOp();
    ASTExpressionNode *expression = parseExpression();
    if(unaryOp != nullptr && expression != nullptr) return new ASTUnaryNode(unaryOp, expression);
    else{
        cout << "Error occurred when parsing unary node" << endl;
        return nullptr;
    }
}

ASTActualParams *Parser::parseActualParams() {
    vector<ASTExpressionNode*> *actualParams = new vector<ASTExpressionNode*>;
    ASTExpressionNode *expression = parseExpression();
    if(expression != nullptr) actualParams->push_back(expression);
    else{
        cout << "Parsing error occurred when parsing actual parameters node" << endl;
        return nullptr;
    }
    if(currentToken.getType() == TOK_COMMA){
        if(nextToken.getType() == TOK_CLOSE_PARENTHESES){
            cout << "Parsing error occurred when parsing actual parameters node: expression expected after comma, got ')' instead" << endl;
            return nullptr;
        }else{
            moveToNext();
            return parseActualParams(actualParams);
        }
    }else if(currentToken.getType() == TOK_CLOSE_PARENTHESES){
        moveToNext();
        return new ASTActualParams(actualParams);
    }else{
        cout << "Parsing error occurred when parsing actual parameters node" << endl;
        return nullptr;
    }
}

ASTActualParams *Parser::parseActualParams(vector<ASTExpressionNode *> *actualParams) {
    ASTExpressionNode *expression = parseExpression();
    if(expression != nullptr) actualParams->push_back(expression);
    else{
        cout << "Parsing error occurred when parsing actual parameters node" << endl;
        return nullptr;
    }
    if(currentToken.getType() == TOK_COMMA){
        if(nextToken.getType() == TOK_CLOSE_PARENTHESES){
            cout << "Parsing error occurred when parsing actual parameters node: expression expected after comma, got ')' instead" << endl;
            return nullptr;
        }else{
            moveToNext();
            return parseActualParams(actualParams);
        }
    }else if(currentToken.getType() == TOK_CLOSE_PARENTHESES){
        moveToNext();
        return new ASTActualParams(actualParams);
    }else{
        cout << "Parsing error occurred when parsing actual parameters node" << endl;
        return nullptr;
    }
}

ASTAddOp *Parser::parseAddOp() {
    if(currentToken.getType() == TOK_ADD_OP){
        if(currentToken.getValue() == "+") return new ASTAddOp(PLUS);
        else if(currentToken.getValue() == "-") return new ASTAddOp(MINUS);
        else if(currentToken.getValue() == "or") return new ASTAddOp(OR);
        else{
            cout << "Parsing error occurred when parsing add op token" << endl;
            return nullptr;
        }
    }else{
        cout << "Parsing error occurred when parsing add op token" << endl;
        return nullptr;
    }
}

ASTExpressionNode *Parser::parseExpression() {

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

void Parser::moveToNext() {
    currentToken = nextToken;
    nextToken = lexer.getNextToken();
}