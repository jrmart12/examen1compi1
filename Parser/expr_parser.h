#ifndef _PARSER_H
#define _PARSER_H

#include "expr_lexer.h"
#include "gramatica.cpp"
class Parser {
public:
    Parser(Lexer& lexer): lexer(lexer) {}
    int parse();
    void input();
    void stmlist();
    void stmlistp();
    void expr();
    void exprp();
    void term();
    void termp();
    void factor();

private:
    Lexer& lexer;
    Symbol token;
    int cant;
};

#endif
