//
// Created by Jamie on 5/5/2019.
//

#include "Lexer/Lexer.h"
#include "Parser/Parser.h"

using namespace std;

int main(){
    Lexer *lex = new Lexer("C:\\Users\\Jamie\\Desktop\\Uni\\CPS2000-Compiler Theory and Practice\\CompilerAssignment\\testprog.txt");
    Parser *parser = new Parser(lex);
    vector<ASTNode*> *AST = parser->buildAST();


    /*Token tok = lex->getNextToken();
    cout << "Type: " << tok.getType() << endl;
    cout << "Value: " << tok.getValue() << endl;

    while(tok.getType() != TOK_EOF){
        tok = lex->getNextToken();
        cout << "Type: " << tok.getType() << endl;
        cout << "Value: " << tok.getValue() << endl;
    }*/
    return 0;
}