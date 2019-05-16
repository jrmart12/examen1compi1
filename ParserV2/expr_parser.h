#ifndef _PARSER_H
#define _PARSER_H
#include "expr_lexer.h"

class Parser {
    public:
        Parser(Lexer &lex,std::ostringstream &out):lexer(lex) , outs(outs){
            token=lexer.getNextToken();
        }
        void parse();
        Lexer lexer;
        std::string outs;
        Symbol token;
};
    
#endif
