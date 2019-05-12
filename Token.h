//
// Created by Jamie on 4/27/2019.
//

#ifndef COMPILERASSIGNMENT_TOKEN_H
#define COMPILERASSIGNMENT_TOKEN_H

#include <string>
using namespace std;

enum TOK_TYPE{TOK_TYPE_DECL = 1, TOK_BOOL_LIT = 2, TOK_INT_LIT = 3, TOK_FLOAT_LIT = 4, TOK_IDENTIFIER = 5, TOK_MULT_OP = 6, TOK_DIV_OP = 7, TOK_ADD_OP = 8, TOK_REL_OP = 9,
                        TOK_UNARY_OP = 10, TOK_ASSIGNMENT_OP = 11, TOK_VAR_DECL = 12, TOK_PRINT = 13, TOK_RETURN = 14, TOK_IF = 15, TOK_FOR = 16, TOK_FUNC_DECL = 17,
                        TOK_OPEN_SCOPE = 18, TOK_CLOSE_SCOPE = 19, TOK_OPEN_PARENTHESES = 20, TOK_CLOSE_PARENTHESES = 21, TOK_COLON = 22, TOK_SEMICOLON = 23,
                        TOK_COMMA = 24, TOK_ELSE = 25, TOK_LINE_COMMENT = 26, TOK_BLOCK_COMMENT = 27, TOK_EOF = 28, TOK_SYNTAX_ERR = -1}; //defining possible token type states

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
