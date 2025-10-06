// Including libraries
#include "parser.h"

Parser::Parser(string input)
{
    scanner = new Scanner(input);
    advance();
}

void Parser::run() {
    goal();
}

void Parser::advance() {
    lToken = scanner->nextToken();
}

void Parser::match(int t) {
    if (lToken->name == t || lToken->attribute == t) {
        advance();
    } else {
        error("Unexpected token");
    }
}

void Parser::goal() {
    expr();
    cout << "Compilation done!" << '\n';
}

void Parser::expr() {
    term();
    _expr();
}

void Parser::_expr() {
    if(lToken->attribute == PLUS || lToken->attribute == MINUS) {
        advance();
        term();
        _expr();
    }
}

void Parser::term() {
    factor();
    _term();
}

void Parser::_term() {
    if(lToken->attribute == MULT || lToken->attribute == DIV) {
        factor();
        _term();
    }
}

void Parser::factor() {
    if(lToken->name == NUMBER) {

    } else if(lToken->name == SEPARATOR) {
        if(lToken->attribute == L_PARENTHESE) {
            advance();
            expr();
            match(R_PARENTHESE);
        } else if(lToken->attribute == L_BRACKET) {
            advance();
            expr();
            match(R_BRACKET);
        }
    } else {
        error("Sintatical error!");
    }
}

void Parser::error(string s) {
    cout << s << '\n';
}