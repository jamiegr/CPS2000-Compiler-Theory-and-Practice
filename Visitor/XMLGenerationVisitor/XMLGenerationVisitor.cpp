//
// Created by Jamie on 5/22/2019.
//

#include <iostream>
#include "XMLGenerationVisitor.h"

using namespace std;


XMLGenerationVisitor::XMLGenerationVisitor() {
    indent = "";//initializing indent string as empty
}

void XMLGenerationVisitor::visit(ASTBool *node) {
    cout << indent << "<Bool>" << node->boolValue << "</Bool>" << endl;
}

void XMLGenerationVisitor::visit(ASTFloat *node) {
    cout << indent << "<Float>" << node->floatValue << "</Float>" << endl;
}

void XMLGenerationVisitor::visit(ASTIdentifierNode *node) {
    cout << indent << "<IdentifierNode>" << node->value << "</IdentifierNode>" << endl;
}

void XMLGenerationVisitor::visit(ASTFunctionCall *node) {
    cout << indent << "<FunctionCall>" << endl;
    indent += "\t";
    node->identifierNode->Accept(this);
    node->actualParams->Accept(this);
    indent.pop_back();
    cout << indent << "</FunctionCall>" << endl;
}

void XMLGenerationVisitor::visit(ASTInt *node) {
    cout << indent << "<Int>" << node->value << "</Int>" << endl;
}

void XMLGenerationVisitor::visit(ASTSubExpression *node) {
    cout << indent << "<SubExpression>" << endl;
    indent += "\t";
    node->expression->Accept(this);
    indent.pop_back();
    cout << indent << "</SubExpression>" << endl;
}

void XMLGenerationVisitor::visit(ASTUnaryNode *node) {
    cout << indent << "<UnaryNode>" << endl;
    indent += "\t";
    node->unaryOp->Accept(this);
    node->expression->Accept(this);
    indent.pop_back();
    cout << indent << "</UnaryNode>" << endl;
}

void XMLGenerationVisitor::visit(ASTActualParams *node) {
    cout << indent << "<ActualParams>" << endl;
    indent += "\t";
    for(ASTExpressionNode *param : *node->parameters){
        param->Accept(this);
    }
    indent.pop_back();
    cout << indent << "</ActualParams>" << endl;
}

void XMLGenerationVisitor::visit(ASTAddOp *node) {
    cout << indent << "<AddOp>" << node->value << "</AddOp>" << endl;
}

void XMLGenerationVisitor::visit(ASTExpression *node) {
}

void XMLGenerationVisitor::visit(ASTFormalParam *node) {

}

void XMLGenerationVisitor::visit(ASTFormalParams *node) {

}

void XMLGenerationVisitor::visit(ASTMultOp *node) {

}

void XMLGenerationVisitor::visit(ASTRelOp *node) {

}

void XMLGenerationVisitor::visit(ASTType *node) {

}

void XMLGenerationVisitor::visit(ASTUnaryOp *node) {

}

void XMLGenerationVisitor::visit(ASTAssignmentStatement *node) {

}

void XMLGenerationVisitor::visit(ASTBlockStatement *node) {

}

void XMLGenerationVisitor::visit(ASTForStatement *node) {

}

void XMLGenerationVisitor::visit(ASTFunctionDeclStatement *node) {

}

void XMLGenerationVisitor::visit(ASTIfStatement *node) {

}

void XMLGenerationVisitor::visit(ASTPrintStatement *node) {

}

void XMLGenerationVisitor::visit(ASTReturnStatement *node) {

}

void XMLGenerationVisitor::visit(ASTVariableDeclStatement *node) {

}
