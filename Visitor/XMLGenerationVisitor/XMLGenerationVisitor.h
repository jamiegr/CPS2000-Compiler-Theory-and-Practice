//
// Created by Jamie on 5/22/2019.
//

#ifndef COMPILERASSIGNMENT_XMLGENERATIONVISITOR_H
#define COMPILERASSIGNMENT_XMLGENERATIONVISITOR_H


#include "../Visitor.h"

class XMLGenerationVisitor : public Visitor {
private:
    std::string indent;
public:

    XMLGenerationVisitor();

    void visit(ASTBool *node) override;

    void visit(ASTFloat *node) override;

    void visit(ASTIdentifierNode *node) override;

    void visit(ASTFunctionCall *node) override;

    void visit(ASTInt *node) override;

    void visit(ASTSubExpression *node) override;

    void visit(ASTUnaryNode *node) override;

    void visit(ASTActualParams *node) override;

    void visit(ASTAddOp *node) override;

    void visit(ASTExpression *node) override;

    void visit(ASTFormalParam *node) override;

    void visit(ASTFormalParams *node) override;

    void visit(ASTMultOp *node) override;

    void visit(ASTRelOp *node) override;

    void visit(ASTType *node) override;

    void visit(ASTUnaryOp *node) override;

    void visit(ASTAssignmentStatement *node) override;

    void visit(ASTBlockStatement *node) override;

    void visit(ASTForStatement *node) override;

    void visit(ASTFunctionDeclStatement *node) override;

    void visit(ASTIfStatement *node) override;

    void visit(ASTPrintStatement *node) override;

    void visit(ASTReturnStatement *node) override;

    void visit(ASTVariableDeclStatement *node) override;
};


#endif //COMPILERASSIGNMENT_XMLGENERATIONVISITOR_H
