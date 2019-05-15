#include "expr_parser.h"

int Parser::parse() {
    cant = 0;
    token = lexer.getNextToken();
    input();
    if(token == Symbol::Eof){
        cant++;
    }
    return cant;
    
}

void Parser::input(){
    stmlist();
    if(token == Symbol::SEMICOLON){
        token = lexer.getNextToken();
        cant++;
    }
}

void Parser::stmlist(){
    expr();
    stmlistp();
}

void Parser::stmlistp(){
    if(token == Symbol::SEMICOLON){
        token = lexer.getNextToken();
        cant++;
        expr();
        stmlistp();
    } else{
        return ;
    }
}


void Parser::expr(){
    term();
    exprp();
}

void Parser::exprp(){
    if(token == Symbol::PLUS || token == Symbol::MINUS || token == Symbol::ASTERISK || token  == Symbol::FORWARD_SLASH){
        token = lexer.getNextToken();
        term();
        exprp();
    } else {
        return ;
    }
}

void Parser::term(){
    factor();
    termp();
}

void Parser::termp(){
    if(token == Symbol::ASTERISK){
        token = lexer.getNextToken();
        factor();
        termp();
    } else {
        return ;
    }
}

void Parser::factor(){
    if(token == Symbol::Ident){
    } else if(token == Symbol::Number){
        token = lexer.getNextToken();
    } else if(token == Symbol::OPEN_PARENTHESIS){
        token = lexer.getNextToken();
        expr();
        if(token != Symbol::CLOSE_PARENTHESIS){
        } 
        token = lexer.getNextToken();
    } else{
    }
}