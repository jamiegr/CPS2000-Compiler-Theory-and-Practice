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
    cout << indent << "<Bool>" << boolalpha << node->boolValue << "</Bool>" << endl;
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
    for (ASTExpressionNode *param : *node->parameters) {
        param->Accept(this);
    }
    indent.pop_back();
    cout << indent << "</ActualParams>" << endl;
}

void XMLGenerationVisitor::visit(ASTAddOp *node) {
    cout << indent << "<AddOp>" << node->value << "</AddOp>" << endl;
}

void XMLGenerationVisitor::visit(ASTExpression *node) {
    cout << indent << "<Expression>" << endl;
    indent += "\t";
    node->simpleExpression1->Accept(this);
    node->relOp->Accept(this);
    node->simpleExpression1->Accept(this);
    indent.pop_back();
    cout << indent << "</Expression>" << endl;
}

void XMLGenerationVisitor::visit(ASTSimpleExpression *node) {
    cout << indent << "<SimpleExpression>" << endl;
    indent += "\t";
    node->term1->Accept(this);
    node->addOp->Accept(this);
    node->term2->Accept(this);
    indent.pop_back();
    cout << indent << "</SimpleExpression>" << endl;
}

void XMLGenerationVisitor::visit(ASTTerm *node) {
    cout << indent << "<Term>" << endl;
    indent += "\t";
    node->factor1->Accept(this);
    node->multOp->Accept(this);
    node->factor2->Accept(this);
    indent.pop_back();
    cout << indent << "</Term>" << endl;
}

void XMLGenerationVisitor::visit(ASTFormalParam *node) {
    cout << indent << "<FormalParam>" << endl;
    indent += "\t";
    node->identifierNode->Accept(this);
    node->type->Accept(this);
    indent.pop_back();
    cout << indent << "</FormalParam>" << endl;

}

void XMLGenerationVisitor::visit(ASTFormalParams *node) {
    cout << indent << "<FormalParams>" << endl;
    indent += "\t";
    for (ASTFormalParam *param : *node->formalParams) {
        param->Accept(this);
    }
    indent.pop_back();
    cout << indent << "</FormalParams>" << endl;
}

void XMLGenerationVisitor::visit(ASTMultOp *node) {
    cout << indent << "<MultOp>" << node->value << "</MultOp>" << endl;

}

void XMLGenerationVisitor::visit(ASTRelOp *node) {
    cout << indent << "<RelOp>" << node->value << "</RelOp>" << endl;
}

void XMLGenerationVisitor::visit(ASTType *node) {
    cout << indent << "<Type>" << node->value << "</Type>" << endl;
}

void XMLGenerationVisitor::visit(ASTUnaryOp *node) {
    cout << indent << "<UnaryOp>" << node->value << "</UnaryOp>" << endl;
}

void XMLGenerationVisitor::visit(ASTAssignmentStatement *node) {
    cout << indent << "<AssignmentStatement>" << endl;
    indent += "\t";
    node->identifierNode->Accept(this);
    node->expression->Accept(this);
    indent.pop_back();
    cout << indent << "</AssignmentStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTBlockStatement *node) {
    cout << indent << "<BlockStatement>" << endl;
    indent += "\t";
    for (ASTStatementNode *param : *node->block) {
        param->Accept(this);
    }
    indent.pop_back();
    cout << indent << "</BlockStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTForStatement *node) {
    cout << indent << "<ForStatement>" << endl;
    indent += "\t";
    if (node->variableDeclStatement->type->value != "") node->variableDeclStatement->Accept(this);
    node->expression->Accept(this);
    if (node->assignmentStatement->identifierNode->value != "") node->assignmentStatement->Accept(this);
    node->forBlock->Accept(this);
    cout << indent << "</ForStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTFunctionDeclStatement *node) {
    cout << indent << "<FunctionDeclStatement>" << endl;
    indent += "\t";
    node->identifierNode->Accept(this);
    if (!node->formalParams->formalParams->empty()) node->formalParams->Accept(this);
    node->type->Accept(this);
    node->blockStatement->Accept(this);
    indent.pop_back();
    cout << indent << "</FunctionDeclStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTIfStatement *node) {
    cout << indent << "<IfStatement>" << endl;
    indent += "\t";
    node->expression->Accept(this);
    node->ifBlock->Accept(this);
    if (!node->elseBlock->block->empty()) node->elseBlock->Accept(this);
    indent.pop_back();
    cout << indent << "</IfStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTPrintStatement *node) {
    cout << indent << "<PrintStatement>" << endl;
    indent += "\t";
    node->expression->Accept(this);
    indent.pop_back();
    cout << indent << "</PrintStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTReturnStatement *node) {
    cout << indent << "<ReturnStatement>" << endl;
    indent += "\t";
    node->expression->Accept(this);
    indent.pop_back();
    cout << indent << "</ReturnStatement>" << endl;
}

void XMLGenerationVisitor::visit(ASTVariableDeclStatement *node) {
    cout << indent << "<VariableDeclStatement>" << endl;
    indent += "\t";
    node->identifierNode->Accept(this);
    node->type->Accept(this);
    node->expression->Accept(this);
    indent.pop_back();
    cout << indent << "</VariableDeclStatement>" << endl;
}
