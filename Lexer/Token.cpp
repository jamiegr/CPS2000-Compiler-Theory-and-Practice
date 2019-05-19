//
// Created by Jamie on 4/27/2019.
//

#include "Token.h"

Token::Token(TOK_TYPE tokentype, string tokenvalue){
    this->type = tokentype;
    this->value = tokenvalue;
}//default constructor

TOK_TYPE Token::getType() {//type getter
    return type;
}

string Token::getValue() {
    return value;
}