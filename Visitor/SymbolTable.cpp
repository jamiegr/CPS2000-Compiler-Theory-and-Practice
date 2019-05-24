//
// Created by Jamie on 5/23/2019.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    table = new vector<map<string, Value*>*>;
    openscope();
}

SymbolTable::~SymbolTable() {
    table->clear();
}

void SymbolTable::openscope() {
    table->push_back(new map<string, Value*>);
}

void SymbolTable::closescope() {
    table->pop_back();
}

int SymbolTable::lookup(string identifier) {
    for(int i = 0; i < table->size(); i++){
        if(table->at(i)->find(identifier) != table->at(i)->end()) return i; //returns the index at which the key is found.
    }
    return -1;//if the identifier is not already mapped in the symbol table -1 is returned to indicate this
}


int SymbolTable::insertvar(string identifier, Value *value) {
    if(lookup(identifier) != -1) return -1;//returns -1 if the given identifier already exists in the table
    table->back()->insert(make_pair(identifier, value));
    return 1;//returns 1 if the identifer did not previously exist and was thus successfully added to the table
}

int SymbolTable::assignvar(string identifier, Value *value) {
    Value *var = getValue(identifier);
    if(var == nullptr) return -1;//returns -1 if the identifier to be assigned a value hasn't been declared
    else{
        if(var->identifierType == value->identifierType){
            if(var->identifierType == INT) var->intval = value->intval;
            else if(var->identifierType == FLOAT) var->floatval = value->floatval;
            else var->boolval = value->boolval;
        }else return -1;//returns -1 if the value being assigned does not match the type of the declared variable
    }
    return 1;
}

bool SymbolTable::checkValidFunctionCall(string identifier, vector<Value*> *parameters) {
    Value *originalFunc = getValue(identifier);
    if(originalFunc != nullptr){
        if(originalFunc->funcparams == nullptr){
            cout << "Function call failure: the identifier used refers to a variable, not a function" << endl;
            return false;
        }
        if(originalFunc->funcparams->size() != parameters->size()){
            cout << "Function call failure: parameter quantity mismatch between function call and declaration" << endl;
            return false;
        }
        for(int i = 0; i < parameters->size(); i++){
            if(parameters->at(i)->identifierType != originalFunc->funcparams->at(i)->identifierType){
                cout << "Function call failure: parameter type mismatch between one or more parameters in function call and function declaration" << endl;
                return false;
            }
        }
        return true;//returns true if no mismatches are found
    }else{
        cout << "Function call failure: function not declared" << endl;
        return false;
    }
}


Value *SymbolTable::getValue(string identifier) {
    int loc = lookup(identifier);
    if(loc == -1) return nullptr;
    else{
        return table->at(loc)->at(identifier);
    }
}