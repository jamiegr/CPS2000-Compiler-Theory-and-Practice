//
// Created by Jamie on 4/28/2019.
//

#ifndef COMPILERASSIGNMENT_LEXER_H
#define COMPILERASSIGNMENT_LEXER_H

#ifndef ERROR
#define ERROR (-1) //error states point to -1, out of index range of transition table
#endif

#ifndef BAD
#define BAD (-99) //for invalid tokens
#endif

#ifndef ALPHABET
#define ALPHABET 22 //18 unique valid characters + letters + digits + printable characters + whitespace characters
#endif

#ifndef TERMINAL_STATE //A state which leads to no other state for any input from the whole alphabet, thus having 22 error transitions
#define TERMINAL_STATE {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}
#endif

#ifndef DFA_STATES
#define DFA_STATES 24 //S0-S24, DFA to be attached in documentation
#endif


#include "Token.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <unordered_map>
#include <stack>

using namespace std;

class Lexer {

public:
    Lexer(string file_address);//lexer constructor with address of file to read instructions from

    Token getNextToken();//get next token function to return next token in program for parser as specified in assignment description

private:
    function<bool(
            char)> classification_table[ALPHABET] = {//array of functions to classify which character of the alphabet the next character falls under
            [](char c) { return isalpha(c); },//1
            [](char c) { return c == '_'; },//2
            [](char c) { return isdigit(c); },//3
            [](char c) { return c == '.'; },//4
            [](char c) { return c == '/'; },//5
            [](char c) { return c == '*'; },//6
            [](char c) { return c == '+'; },//7
            [](char c) { return c == '-'; },//8
            [](char c) { return c == '='; },//9
            [](char c) { return c == '<'; },//10
            [](char c) { return c == '>'; },//11
            [](char c) { return c == '!'; },//12
            [](char c) { return c == '{'; },//13
            [](char c) { return c == '}'; },//14
            [](char c) { return c == '('; },//15
            [](char c) { return c == ')'; },//16
            [](char c) { return c == ':'; },//17
            [](char c) { return c == ';'; },//18
            [](char c) { return c == ','; },//19
            [](char c) { return c == '\n'; },//20
            [](char c) { return isprint(c); },//21
            [](char c) { return isspace(c); },//22
    };

    int transition_table[DFA_STATES][ALPHABET] = {
            {1, 1, 2, ERROR, 4, 5, 6, 6, 7, 8, 8, 10, 11, 12, 13, 14, 15, 16, 17}, //S0 - Initial State
            {1, 1, 1, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR}, //S1 - Final State - Identifier Token
            {ERROR, ERROR, 2, 3, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, //S2 - Final State - Integer Token
            {ERROR, ERROR, 23, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, //S3 - Non-Final State - Partial Float Token
            {ERROR, ERROR, ERROR, ERROR, 18, 19, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, //S4 - Final State - Division Token
            TERMINAL_STATE, //S5 - Final State - Multiplication Token
            TERMINAL_STATE, //S6 - Final State - AdditiveOp Token
            {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 9, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, //S7 - Final State - AssignmentOp Token
            {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 9, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, //S8 - Final State - RelOp Token
            TERMINAL_STATE, //S9 - Final State - RelOp Token
            {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, 9, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR}, //S10 - Non-Final State - unfinished inequality op
            TERMINAL_STATE, //S11 - Final State - OpenScope Token
            TERMINAL_STATE, //S12 - Final State - CloseScope Token
            TERMINAL_STATE, //S13 - Final State - OpenParentheses Token
            TERMINAL_STATE, //S14 - Final State - CloseParentheses Token
            TERMINAL_STATE, //S15 - Final State - Colon Token
            TERMINAL_STATE, //S16 - Final State - Semicolon Token
            TERMINAL_STATE, //S17 - Final State - Comma Token
            {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 20, 18,
             18}, //S18 - Non-Final State - SingleLineComment
            {19, 19, 19, 19, 19, 21, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
             19}, //S19 - Non-Final State - BlockComment
            TERMINAL_STATE, //S20 - Final State, SingleLineComment Token
            {19, 19, 19, 19, 22, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
             19}, //S21 - Non-Final State - BlockComment
            TERMINAL_STATE, //S22 - Final State, BlockComment Token
            {ERROR, ERROR, 23, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR,
             ERROR, ERROR, ERROR, ERROR, ERROR, ERROR, ERROR} //S23 - Final State, Float Token
    };

    unordered_map<int, TOK_TYPE> final_states = {//mapping each final state to its corresponding token type
            {1,  TOK_IDENTIFIER},
            {2,  TOK_INT_LIT},
            {4,  TOK_MULT_OP},
            {5,  TOK_MULT_OP},
            {6,  TOK_ADD_OP},
            {7,  TOK_ASSIGNMENT_OP},
            {8,  TOK_REL_OP},
            {9,  TOK_REL_OP},
            {11, TOK_OPEN_SCOPE},
            {12, TOK_CLOSE_SCOPE},
            {13, TOK_OPEN_PARENTHESES},
            {14, TOK_CLOSE_PARENTHESES},
            {15, TOK_COLON},
            {16, TOK_SEMICOLON},
            {17, TOK_COMMA},
            {20, TOK_LINE_COMMENT},
            {22, TOK_BLOCK_COMMENT},
            {23, TOK_FLOAT_LIT}
    };

    void clearStack();

    string nextChar();

    TOK_TYPE classifyIdentifier(
            string identifier);//takes a string classified as an identifier and checks if it matches any keywords such as for, if, print, return, var etc... and returns the corresponding token type

    int getNextState(
            char next);//uses the char_cursor and current_state to get the next state using the transition function and transition table

    string program, current_lexeme;//the string which will store the code to be compiled and the characters processed so far from the current lexeme being evaluated
    unsigned int char_cursor, line_cursor, total_lines;//two integers to point to the current character and the current line the lexer is processing, one integer to store the total number of lines in the program
    int current_state;//one more integer to keep track of the current state, not unsigned since it can be an ERROR state which corresponds to a value of -1
    stack<int> visited_final_states;
};

#endif //COMPILERASSIGNMENT_LEXER_H
