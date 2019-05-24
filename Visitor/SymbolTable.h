//
// Created by Jamie on 5/23/2019.
//

#ifndef COMPILERASSIGNMENT_SYMBOLTABLE_H
#define COMPILERASSIGNMENT_SYMBOLTABLE_H

#include <iostream>
#include <map>
#include "Value.h"

class SymbolTable {
public:
    SymbolTable();

    ~SymbolTable();

    void openscope();

    void closescope();

    int lookup(string identifier);

    int insertvar(string identifier, Value *value);

    int assignvar(string identifier, Value *value);

    bool checkValidFunctionCall(string identifier, vector<Value*> *parameters);

    Value *getValue(string identifier);

private:
    vector<map<string, Value*>*> *table;
};


#endif //COMPILERASSIGNMENT_SYMBOLTABLE_H
