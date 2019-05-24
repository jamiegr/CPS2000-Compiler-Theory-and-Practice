//
// Created by Jamie on 5/5/2019.
//

#include "Lexer/Lexer.h"
#include "Parser/Parser.h"
#include "Visitor/XMLGenerationVisitor/XMLGenerationVisitor.h"
#include "Visitor/SemanticAnalysisVisitor/SemanticAnalysisVisitor.h"

using namespace std;

int main(){
    Lexer *lex = new Lexer("C:\\Users\\Jamie\\Desktop\\Uni\\CPS2000-Compiler Theory and Practice\\CompilerAssignment\\testprog.txt");
    Parser *parser = new Parser(lex);
    vector<ASTNode*> *AST = parser->buildAST();
    XMLGenerationVisitor *XMLvisitor = new XMLGenerationVisitor;
    SemanticAnalysisVisitor *SemanticAnalysisvisitor = new SemanticAnalysisVisitor;
    if(AST != nullptr){
        for(ASTNode *node : *AST){
            node->Accept(SemanticAnalysisvisitor);
            node->Accept(XMLvisitor);
        }
    }

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