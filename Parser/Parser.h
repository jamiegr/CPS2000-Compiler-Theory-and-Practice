//
// Created by Jamie on 5/12/2019.
//

#ifndef COMPILERASSIGNMENT_PARSER_H
#define COMPILERASSIGNMENT_PARSER_H


#include "../Lexer/Lexer.h"
#include "AST/ASTNode.h"

class Parser {
public:
    Parser(Lexer lexer);
    ~Parser();
    ASTNode *parseNode();
private:
    Lexer lexer;
    Token currentToken, nextToken;
};


#endif //COMPILERASSIGNMENT_PARSER_H
