cmake_minimum_required(VERSION 3.8)
project(CompilerAssignment)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Token.h Token.cpp Lexer.h Lexer.cpp main.cpp Parser.cpp Parser.h ASTNode.h Visitor.cpp Visitor.h ASTStatement.h ASTExpression.h ASTFactorNode.h ASTVariableDeclStatement.cpp ASTVariableDeclStatement.h ASTAssignmentStatement.cpp ASTAssignmentStatement.h ASTPrintStatement.cpp ASTPrintStatement.h ASTIfStatement.cpp ASTIfStatement.h ASTForStatement.cpp ASTForStatement.h ASTReturnStatement.cpp ASTReturnStatement.h ASTFunctionDeclStatement.cpp ASTFunctionDeclStatement.h ASTBlockStatement.cpp ASTBlockStatement.h ASTSimpleExpression.cpp ASTSimpleExpression.h ASTIdentifierNode.cpp ASTIdentifierNode.h ASTFunctionCallNode.cpp ASTFunctionCallNode.h ASTSubExpressionNode.cpp ASTSubExpressionNode.h ASTUnaryNode.cpp ASTUnaryNode.h ASTBoolNode.cpp ASTBoolNode.h ASTIntNode.cpp ASTIntNode.h ASTFloatNode.cpp ASTFloatNode.h)
add_executable(CompilerAssignment ${SOURCE_FILES})