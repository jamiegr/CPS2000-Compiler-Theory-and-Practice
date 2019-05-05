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
    if(line_cursor > total_lines || char_cursor >= program.length()) return Token(TOK_EOF, "");//if last line is exceeded, return end of file token

    if(isspace(program.at(char_cursor))){
        while(isspace(program.at(char_cursor))){//skipping over whitespace between tokens
            nextChar();
        }
    }

    current_state = 0;
    current_lexeme = "";
    clearStack();
    visited_final_states.push(BAD);

    while(current_state != ERROR && char_cursor < program.length()){
        string next = nextChar();//load next character in the form of a string so it can be appended
        current_lexeme.append(next);//using string(1, c) constructor to convert current character to a string and append it to the current lexeme

        if(final_states.find(current_state) != final_states.end()) clearStack();//if current state is a final state clear stack
        visited_final_states.push(current_state);//push current state to stack
        current_state = getNextState(next.at(0));//get next state
    }

    while(final_states.find(current_state) == final_states.end() && current_state != BAD){
        current_state = visited_final_states.top();//getting top state from stack
        visited_final_states.pop();//popping top state from stack
        if(!current_lexeme.empty()){
            current_lexeme.pop_back();//truncating lexeme
            char_cursor--;//moving char pointer back to before truncated character
        }

    }

    unordered_map<int, TOK_TYPE>::const_iterator token = final_states.find(current_state);//searching for state in list of final states and returning resulting iterator

    if(token != final_states.end()){//if state is final state
        TOK_TYPE returntype = token->second;
        if(returntype == TOK_LINE_COMMENT || returntype == TOK_BLOCK_COMMENT) return getNextToken();//ignoring comments
        else if(returntype == TOK_IDENTIFIER) returntype = classifyIdentifier(current_lexeme);
        return Token(returntype, current_lexeme);// return token type + value pair
    }
    return Token(TOK_SYNTAX_ERR, "ERROR");//if no valid token found return syntax error
}

string Lexer::nextChar() {
    string character = string(1, program.at(char_cursor));
    if(program.at(char_cursor) == '\n') line_cursor++;
    char_cursor++;
    return character;
}

void Lexer::clearStack() {
    while(!visited_final_states.empty()){
        visited_final_states.pop();
    }
}

int Lexer::getNextState(char next) {
    for(int i = 0; i < ALPHABET; i++){
        if(classification_table[i](next)){
            return transition_table[current_state][i];
        }
    }
}

TOK_TYPE Lexer::classifyIdentifier(string identifier) {//checks if an identifier matches one of the token specific keywords and returns the TOK_TYPE accordingly
    if(identifier == "float" || identifier == "int" || identifier == "bool") return TOK_TYPE_DECL;
    if(identifier == "true" || identifier == "false") return TOK_BOOL_LIT;
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