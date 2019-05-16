#ifndef _LEXER_H
#define _LEXER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
enum class Symbol: unsigned {
    input = 0,
    stmt_list = 1,
    stmt = 2,
    stmt_listp = 3,
    expr = 4,
    term = 5,
    exprp = 6,
    factor = 7,
    termp = 8,
    Eof = 9,
    Eol = 10,
    Print = 11,
    Ident = 12,
    OpAssign = 13,
    OpAdd = 14,
    OpSub = 15,
    OpMul = 16,
    OpDiv = 17,
    Number = 18,
    OpenPar = 19,
    ClosePar = 20,
    Epsilon = 21
};
using SymbolInfo = std::pair<Symbol, std::string>;

class Lexer {
public:
    Lexer(const std::vector<SymbolInfo>& tklst): tklist(tklst) {
        it = tklist.begin();
    }

    Symbol getNextToken() {
        if (it == tklist.end()) {
            return Symbol::Eof;
        }
        Symbol tk = it->first;
        text = it->second;
        it++;
        
        return tk;
    }
    
    bool hasTokens() { return it != tklist.end(); }
    std::string getText() { return text; }

private:
    std::string text;
    std::vector<SymbolInfo> tklist;
    std::vector<SymbolInfo>::iterator it;
};
#endif
