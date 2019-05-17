//
// Created by Jamie on 5/5/2019.
//

#include "Lexer/Lexer.h"
using namespace std;

int main(){
    Lexer *lex = new Lexer("testprog.txt");

    Token tok = lex->getNextToken();
    cout << "Type: " << tok.getType() << endl;
    cout << "Value: " << tok.getValue() << endl;

    while(tok.getType() != TOK_EOF){
        tok = lex->getNextToken();
        cout << "Type: " << tok.getType() << endl;
        cout << "Value: " << tok.getValue() << endl;
    }
}