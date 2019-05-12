cmake_minimum_required(VERSION 3.8)
project(CompilerAssignment)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Token.h Token.cpp Lexer.h Lexer.cpp main.cpp Parser.cpp Parser.h ASTNode.cpp ASTNode.h Visitor.cpp Visitor.h)
add_executable(CompilerAssignment ${SOURCE_FILES})