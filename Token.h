//
// Created by Jamie on 4/27/2019.
//

#ifndef COMPILERASSIGNMENT_TOKEN_H
#define COMPILERASSIGNMENT_TOKEN_H

#include <string>
using namespace std;

enum TOK_TYPE{TOK_TYPE, TOK_BOOL_LIT, TOK_INT_LIT, TOK_FLOAT_LIT, TOK_IDENTIFIER, TOK_MULT_OP, TOK_DIV_OP, TOK_ADD_OP, TOK_REL_OP,
                        TOK_UNARY_OP, TOK_ASSIGNMENT_OP, TOK_VAR_DECL, TOK_PRINT, TOK_RETURN, TOK_IF, TOK_FOR, TOK_FUNC_DECL,
                        TOK_OPEN_SCOPE, TOK_CLOSE_SCOPE, TOK_OPEN_PARENTHESES, TOK_CLOSE_PARENTHESES, TOK_COLON, TOK_SEMICOLON,
                        TOK_COMMA, TOK_EOF, TOK_LINE_COMMENT, TOK_BLOCK_COMMENT, TOK_SYNTAX_ERR}; //defining possible token type states

class Token{
private:

    TOK_TYPE type;//token type
    string value;//token value

public:

    Token(TOK_TYPE tokentype, string tokenvalue);//default constructor

    TOK_TYPE getType();

    string getValue();
};


#endif //COMPILERASSIGNMENT_TOKEN_H
