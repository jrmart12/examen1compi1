#include "expr_parser.h"


static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 9) return index;
    else return (index - 9);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 9;
}

struct Rule {
    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

Rule none;
std::vector<std::vector<Rule>> ll1_table = {
    /* input */ { none, none, {Symbol::input, {Symbol::stmt_list, Symbol::Eol, }}, {Symbol::input, {Symbol::stmt_list, Symbol::Eol, }}, none, none, none, none, none, none, none, none, },
    /* stmt_list */ { none, none, {Symbol::stmt_list, {Symbol::stmt, Symbol::stmt_listp, }}, {Symbol::stmt_list, {Symbol::stmt, Symbol::stmt_listp, }}, none, none, none, none, none, none, none, none, },
    /* stmt */ { none, none, {Symbol::stmt, {Symbol::Print, Symbol::expr, }}, {Symbol::stmt, {Symbol::Ident, Symbol::OpAssign, Symbol::expr, }}, none, none, none, none, none, none, none, none, },
    /* stmt_listp */ { none, {Symbol::stmt_listp, {Symbol::Eol, Symbol::stmt, Symbol::stmt_listp, }}, none, none, none, none, none, none, none, none, none, none, },
    /* expr */ { none, none, none, {Symbol::expr, {Symbol::term, Symbol::exprp, }}, none, none, none, none, none, {Symbol::expr, {Symbol::term, Symbol::exprp, }}, {Symbol::expr, {Symbol::term, Symbol::exprp, }}, none, },
    /* term */ { none, none, none, {Symbol::term, {Symbol::factor, Symbol::termp, }}, none, none, none, none, none, {Symbol::term, {Symbol::factor, Symbol::termp, }}, {Symbol::term, {Symbol::factor, Symbol::termp, }}, none, },
    /* exprp */ { none, none, none, none, none, {Symbol::exprp, {Symbol::OpAdd, Symbol::term, Symbol::exprp, }}, {Symbol::exprp, {Symbol::OpSub, Symbol::term, Symbol::exprp, }}, {Symbol::exprp, {Symbol::OpMul, Symbol::term, Symbol::exprp, }}, {Symbol::exprp, {Symbol::OpDiv, Symbol::term, Symbol::exprp, }}, none, none, none, },
    /* factor */ { none, none, none, {Symbol::factor, {Symbol::Ident, }}, none, none, none, none, none, {Symbol::factor, {Symbol::Number, }}, {Symbol::factor, {Symbol::OpenPar, Symbol::expr, Symbol::ClosePar, }}, none, },
    /* termp */ { none, none, none, none, none, none, none, {Symbol::termp, {Symbol::OpMul, Symbol::factor, Symbol::termp, }}, none, none, none, none, },
};

void Parser::parse(){
    indexOf(token);
    
}