//
// Created by Jamie on 5/23/2019.
//

#ifndef COMPILERASSIGNMENT_VALUE_H
#define COMPILERASSIGNMENT_VALUE_H

#include <string>
#include <vector>

using namespace std;

enum TYPE{INT = 1, FLOAT = 2, BOOL = 3, FUNCCALL = 4};

class Value{
public:
    TYPE identifierType;
    int *intval;
    float *floatval;
    bool *boolval;
    vector<Value*> *funcparams;
    Value(int intval);
    Value(float floatval);
    Value(bool boolval);
    Value(TYPE identifierType);
    Value(string type);
    Value(string type, vector<Value*> *funcparams);
    ~Value();

};

#endif //COMPILERASSIGNMENT_VALUE_H
