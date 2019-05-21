//
// Created by Jamie on 5/17/2019.
//

#ifndef COMPILERASSIGNMENT_ASTNODE_H
#define COMPILERASSIGNMENT_ASTNODE_H

class Visitor;//forward declaration of visitor class to be imported in subclasses with an accept visitor implementation

class ASTNode {
public:
    virtual ~ASTNode() = default;// virtual destructor for abstract class
    virtual void Accept(Visitor *visitor) = 0;
};

#endif //COMPILERASSIGNMENT_ASTNODE_H