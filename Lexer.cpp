//
// Created by Jamie on 5/1/2019.
//

#include "Lexer.h"

Lexer::Lexer(string file_address) {//lexer constructor, checks if given file address is valid and loads the file
    program = "";
    current_lexeme = "";
    string currentLine;
    char_cursor = 0;//starts at 0 since this will be used to get character from the 'program' string by index
    line_cursor = 1;//starts at 1 since this will be used to keep track of the line currently being processed, to return EOF token when final line is passed
    total_lines = 0;//starts at 0 and will be incremented for every line read in the program
    current_state = 0;
    ifstream filestream;
    filestream.open(file_address);
    if(filestream.is_open()){//only executes if valid readable file address is given
        while(getline(filestream, currentLine)){//adding program from file to program string line by line
            program.append(currentLine + "\n");
            total_lines++;
        }
    }else{
        cout << "Invalid file address" << endl;
    }
    filestream.close();
}

Token Lexer::getNextToken() {
    if(line_cursor > total_lines) return Token(TOK_EOF, "");//if last line is exceeded, return end of file token

    if(current_lexeme.empty() && current_state == 0){
        while(isspace(program.at(char_cursor))){//skipping over whitespace between tokens
            if(program.at(char_cursor) == '\n') line_cursor++;
            char_cursor++;
        }
    }

    while(current_state != ERROR){
        current_lexeme.append(string(1, program.at(char_cursor)));//using string(1, c) constructor to convert current character to a string and append it to the current lexeme
        current_state = getNextState();
    }


}

int Lexer::getNextState() {
    for(int i = 0; i < ALPHABET; i++){
        if(transition_function[i](program.at(char_cursor))){
            return transition_table[current_state][i];
        }
    }
}

TOK_TYPE Lexer::classifyIdentifier(string identifier) {//checks if an identifier matches one of the token specific keywords and returns the TOK_TYPE accordingly
    if(identifier == "float" || identifier == "int" || identifier == "bool") return TOK_TYPE_DECL;
    if(identifier == "and") return TOK_MULT_OP;
    if(identifier == "or") return TOK_ADD_OP;
    if(identifier == "not") return TOK_UNARY_OP;
    if(identifier == "var") return TOK_VAR_DECL;
    if(identifier == "print") return TOK_PRINT;
    if(identifier == "return") return TOK_RETURN;
    if(identifier == "if") return TOK_IF;
    if(identifier == "else") return TOK_ELSE;
    if(identifier == "for") return TOK_FOR;
    if(identifier == "fn") return TOK_FUNC_DECL;
    return TOK_IDENTIFIER;
}