//
// Created by Jamie on 5/23/2019.
//

#include "Value.h"

Value::Value(int intval) {
    identifierType = INT;
    this->intval = new int(intval);
    boolval = nullptr;
    floatval = nullptr;
    funcparams = nullptr;
}

Value::Value(bool boolval) {
    identifierType = BOOL;
    this->boolval = new bool(boolval);
    intval = nullptr;
    floatval = nullptr;
    funcparams = nullptr;
}

Value::Value(float floatval) {
    identifierType = FLOAT;
    this->floatval = new float(floatval);
    boolval = nullptr;
    intval = nullptr;
    funcparams = nullptr;
}

Value::Value(string type) {
    if(type == "int") identifierType = INT;
    else if(type == "float") identifierType = FLOAT;
    else identifierType = BOOL;
    intval = nullptr;
    boolval = nullptr;
    floatval = nullptr;
    funcparams = nullptr;
}

Value::Value(TYPE identifierType) {
    this->identifierType = identifierType;
    floatval = nullptr;
    boolval = nullptr;
    intval = nullptr;
    funcparams = nullptr;
}

Value::Value(string type, vector<Value *> *funcparams) {
    if(type == "int") identifierType = INT;
    else if(type == "float") identifierType = FLOAT;
    else identifierType = BOOL;
    this->funcparams = funcparams;
    intval = nullptr;
    boolval = nullptr;
    floatval = nullptr;
}



Value::~Value() {
    delete intval;
    delete boolval;
    delete floatval;
    funcparams->clear();
}
