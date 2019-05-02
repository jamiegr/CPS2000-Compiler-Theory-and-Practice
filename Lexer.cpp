//
// Created by Jamie on 5/1/2019.
//

#include "Lexer.h"

Lexer::Lexer(string file_address) {//lexer constructor, checks if given file address is valid and loads the file
    program = "";
    string current_line;
    char_cursor = 0;//starts at 0 since this will be used to get character from the 'program' string by index
    line_cursor = 1;//starts at 1 since this will be used to keep track of the line currently being processed, to return EOF token when final line is passed
    total_lines = 0;//starts at 0 and will be incremented for every line read in the program
    ifstream filestream;
    filestream.open(file_address);
    if(filestream.is_open()){//only executes if valid readable file address is given
        while(getline(filestream, current_line)){//adding program from file to program string line by line
            program.append(current_line + "\n");
            total_lines++;
        }
    }else{
        cout << "Invalid file address" << endl;
    }
    filestream.close();
}