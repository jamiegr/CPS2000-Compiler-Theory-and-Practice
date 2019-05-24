//
// Created by Jamie on 5/23/2019.
//

#include "SemanticAnalysisVisitor.h"

SemanticAnalysisVisitor::SemanticAnalysisVisitor() {
    symbolTable = new SymbolTable();
    returnFlag = false;
}

SemanticAnalysisVisitor::~SemanticAnalysisVisitor() {
    delete symbolTable;
}

void SemanticAnalysisVisitor::visit(ASTBool *node) {
    currentType = BOOL;
}

void SemanticAnalysisVisitor::visit(ASTFloat *node) {
    currentType = FLOAT;
}

void SemanticAnalysisVisitor::visit(ASTIdentifierNode *node) {
    if(symbolTable->getValue(node->value) == nullptr){
        cout << "Identifier  " << node->value << " not declared" << endl;
        exit(EXIT_FAILURE);
    }else currentType = symbolTable->getValue(node->value)->identifierType;
}

void SemanticAnalysisVisitor::visit(ASTFunctionCall *node) {
    vector<Value*> *parametertypes = new vector<Value*>;
    for(ASTExpressionNode* expressionNode : *node->actualParams->parameters){
        expressionNode->Accept(this);
        parametertypes->push_back(new Value(currentType));
    }

    if(symbolTable->checkValidFunctionCall(node->identifierNode->value, parametertypes))
        currentType = symbolTable->getValue(node->identifierNode->value)->identifierType;
    else{
        cout << "Invalid function call" << endl;
        exit(EXIT_FAILURE);
    }
}

void SemanticAnalysisVisitor::visit(ASTInt *node) {
    currentType = INT;
}

void SemanticAnalysisVisitor::visit(ASTSubExpression *node) {
    node->expression->Accept(this);
}

void SemanticAnalysisVisitor::visit(ASTUnaryNode *node) {
    node->expression->Accept(this);
    if(node->unaryOp->value == "not"){
        if(currentType != BOOL){
            cout << "Error: unary operator 'not' can only be applied to bools" << endl;
            exit(EXIT_FAILURE);
        }
    }else{
        if(currentType == BOOL){
            cout << "Error: unary operator '-' can only be applied to ints and floats" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void SemanticAnalysisVisitor::visit(ASTActualParams *node) {
    //do nothing, this is handled in Function Call visit method
}

void SemanticAnalysisVisitor::visit(ASTAddOp *node) {
    //do nothing - handled in simpleexpression
}

void SemanticAnalysisVisitor::visit(ASTExpression *node) {
    node->simpleExpression1->Accept(this);
    TYPE type1 = currentType;
    node->simpleExpression2->Accept(this);
    TYPE type2 = currentType;

    if(type1 != type2){
        cout << "Error: variables in an expression must be of the same type" << endl;
        exit(EXIT_FAILURE);
    }

    string exprOp = node->relOp->value;
    if(exprOp == "<" || exprOp == ">"){
        if(type1 == BOOL){
            cout << "Invalid expression: " << exprOp << " can only be applied to ints and floats" << endl;
            exit(EXIT_FAILURE);
        }
        currentType = BOOL;
    }else currentType = BOOL;
}

void SemanticAnalysisVisitor::visit(ASTSimpleExpression *node) {
    node->term1->Accept(this);
    TYPE type1 = currentType;
    node->term2->Accept(this);
    TYPE type2 = currentType;

    if(type1 != type2){
        cout << "Error: variables in a simple expression must be of the same type" << endl;
        exit(EXIT_FAILURE);
    }

    string exprOp = node->addOp->value;
    if(exprOp == "+" || exprOp == "-"){
        if(type1 == BOOL){
            cout << "Invalid expression: " << exprOp << " can only be applied to ints and floats" << endl;
            exit(EXIT_FAILURE);
        }
        currentType = type1;
    }else{
        if(type1 != BOOL){
            cout << "Invalid expression: " << exprOp << " can only be applied to bools" << endl;
            exit(EXIT_FAILURE);
        }
        currentType = BOOL;
    }
}

void SemanticAnalysisVisitor::visit(ASTTerm *node) {
    node->factor1->Accept(this);
    TYPE type1 = currentType;
    node->factor2->Accept(this);
    TYPE type2 = currentType;

    if(type1 != type2){
        cout << "Error: variables in a term must be of the same type" << endl;
        exit(EXIT_FAILURE);
    }

    string exprOp = node->multOp->value;
    if(exprOp == "*"){
        if(type1 == INT) currentType = INT;//multiplication between two ints = int
        else if(type1 == FLOAT) currentType = FLOAT;//multiplication between two floats = float
        else{
            cout << "Invalid expression: " << exprOp << " can only be applied to ints and floats" << endl;
            exit(EXIT_FAILURE);
        }
    }else if(exprOp == "/"){
        if(type1 == BOOL){
            cout << "Invalid expression: " << exprOp << " can only be applied to ints and floats" << endl;
            exit(EXIT_FAILURE);
        }
        currentType = FLOAT;//result of division always returns float variable
    }else{
        if(type1 != BOOL){
            cout << "Invalid expression: " << exprOp << " can only be applied to bools" << endl;
            exit(EXIT_FAILURE);
        }
        currentType = BOOL;
    }
}

void SemanticAnalysisVisitor::visit(ASTFormalParam *node) {
    //do nothing, handled in func decl visit method
}

void SemanticAnalysisVisitor::visit(ASTFormalParams *node) {
    //do nothing, handled in func decl visit method
}

void SemanticAnalysisVisitor::visit(ASTMultOp *node) {
    //do nothing - handled in term
}

void SemanticAnalysisVisitor::visit(ASTRelOp *node) {
    //do nothing - handled in expression
}

void SemanticAnalysisVisitor::visit(ASTType *node) {
    //do nothing
}

void SemanticAnalysisVisitor::visit(ASTUnaryOp *node) {
    //do nothing - handled in unaryexpr
}

void SemanticAnalysisVisitor::visit(ASTAssignmentStatement *node) {
    TYPE vartype, valtype;
    node->identifierNode->Accept(this);
    vartype = currentType;
    node->expression->Accept(this);
    valtype = currentType;
    if(vartype != valtype){//error occurs if the variable and the value it is assigned have different types
        cout << "Assignment statement error: Variable type does not match expression type" << endl;
        exit(EXIT_FAILURE);
    }
}

void SemanticAnalysisVisitor::visit(ASTBlockStatement *node) {
    symbolTable->openscope();
    int check;//to check if parameters were successfully added to the new layer of the symbol table
    if(!parameters.empty()){
        map<string, Value*>::iterator it = parameters.begin();
        while(it != parameters.end()){
            check = symbolTable->insertvar(it->first, it->second);
            if(check == -1){
                cout << "Error when inserting parameter into symbol table, identifier " << it->first << " is not unique" << endl;
            }
            it++;
        }
    }
    parameters.clear();

    for(ASTStatementNode *statementNode : *node->block){
        statementNode->Accept(this);
        if(typeid(*statementNode) == typeid(ASTReturnStatement)){
            returnFlag = true;
            if(currentType != returnType){
                cout << "Return type does not match return type specified in function declaration" << endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    symbolTable->closescope();
}

void SemanticAnalysisVisitor::visit(ASTForStatement *node) {
    TYPE expressiontype;
    if(node->variableDeclStatement->identifierNode->value != "") node->variableDeclStatement->Accept(this);//checking that var dec statement is valid if present
    node->expression->Accept(this);
    expressiontype = currentType;
    if(node->assignmentStatement->identifierNode->value != "") node->assignmentStatement->Accept(this);//checking that assignment statement is valid if present
    if(expressiontype != BOOL){
        cout << "Expression in for statement arguments must be of type bool" << endl;
        exit(EXIT_FAILURE);
    }
    //since the variable declaration and assignment in for statements are optional no further checks are done
}

void SemanticAnalysisVisitor::visit(ASTFunctionDeclStatement *node) {
    string fname = node->identifierNode->value;
    string ftype = node->type->value;
    if(node->type->value == "int") returnType = INT;
    else if(node->type->value == "float") returnType = FLOAT;
    else returnType = BOOL;
    vector<Value*> *paramtypes = new vector<Value*>;
    for (int i = 0; i < node->formalParams->formalParams->size(); i++) {
        parameters.insert(make_pair(node->formalParams->formalParams->at(i)->identifierNode->value, new Value(node->formalParams->formalParams->at(i)->type->value)));
        paramtypes->push_back(new Value(node->formalParams->formalParams->at(i)->type->value));
    }
    Value *methodSignature = new Value(ftype, paramtypes);
    symbolTable->insertvar(fname, methodSignature);
    node->blockStatement->Accept(this);
    if(!returnFlag){
        cout << "Function has no return statement" << endl;
        exit(EXIT_FAILURE);
    }
    returnFlag = false;//setting back to false so it can be reused for the next function declaration if any
}

void SemanticAnalysisVisitor::visit(ASTIfStatement *node) {
    node->expression->Accept(this);
    if(currentType != BOOL){
        cout << "Conditional expression for if statement must be a bool" << endl;
        exit(EXIT_FAILURE);
    }
    node->ifBlock->Accept(this);
    node->elseBlock->Accept(this);
}

void SemanticAnalysisVisitor::visit(ASTPrintStatement *node) {
    node->expression->Accept(this);
}

void SemanticAnalysisVisitor::visit(ASTReturnStatement *node) {
    node->expression->Accept(this);//only the variable being returned needs to be checked since the return type is checked against the return type of the function in the block visitor.
}

void SemanticAnalysisVisitor::visit(ASTVariableDeclStatement *node) {
    TYPE vartype;
    if(node->type->value == "int") vartype = INT;
    else if(node->type->value == "float") vartype = FLOAT;
    else vartype = BOOL;
    node->expression->Accept(this);
    if(currentType != vartype){
        cout << "Expression type does not match declared identifier type" << endl;
        exit(EXIT_FAILURE);
    }
    if(symbolTable->insertvar(node->identifierNode->value, new Value(currentType)) == -1){
        cout << "Duplicate declaration of variable " << node->identifierNode->value << endl;
        exit(EXIT_FAILURE);
    }
}
