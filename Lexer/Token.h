//
// Created by Jamie on 4/27/2019.
//

#ifndef COMPILERASSIGNMENT_TOKEN_H
#define COMPILERASSIGNMENT_TOKEN_H

#include <string>
using namespace std;

enum TOK_TYPE{TOK_TYPE_DECL = 1, TOK_BOOL_LIT = 2, TOK_INT_LIT = 3, TOK_FLOAT_LIT = 4, TOK_IDENTIFIER = 5, TOK_MULT_OP = 6, TOK_ADD_OP = 7, TOK_REL_OP = 8,
                        TOK_UNARY_OP = 9, TOK_ASSIGNMENT_OP = 10, TOK_VAR_DECL = 11, TOK_PRINT = 12, TOK_RETURN = 13, TOK_IF = 14, TOK_FOR = 15, TOK_FUNC_DECL = 16,
                        TOK_OPEN_SCOPE = 17, TOK_CLOSE_SCOPE = 18, TOK_OPEN_PARENTHESES = 19, TOK_CLOSE_PARENTHESES = 20, TOK_COLON = 21, TOK_SEMICOLON = 22,
                        TOK_COMMA = 23, TOK_ELSE = 24, TOK_LINE_COMMENT = 25, TOK_BLOCK_COMMENT = 26, TOK_EOF = 27, TOK_SYNTAX_ERR = -1}; //defining possible token type states

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
