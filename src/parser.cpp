// Including libraries
#include "parser.h"

Parser::Parser(string input)
{
    scanner = new Scanner(input);
    syncTree = new SyntaticTree();
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
    Node* r = expr();
    syncTree->startTree(r);
    cout << "Compilation done!" << '\n';
    cout << "Syntatic Tree In Order: ";
    syncTree->printHierarchical();
    cout << "\n";
}

Node* Parser::expr() {
    Node* n = new Node(E);
    n->first = term();
    n->second = _expr();
    return n;
}

Node* Parser::_expr() {
    Node* n;

    if(lToken->attribute == PLUS || lToken->attribute == MINUS) {
        n = new Node(lToken);
        advance();
        n->first = term();
        n->second = _expr();
    } else {
        n = new Node(_E);
    }

    return n;
}

Node* Parser::term() {
    Node* n = new Node(T);
    n->first = factor();
    n->second = _term();
    return n;
}

Node* Parser::_term() {
    Node* n;

    if(lToken->attribute == MULT || lToken->attribute == DIV) {
        n = new Node(lToken);
        advance();
        n->first = factor();
        n->second = _term();
    } else {
        n = new Node(_T);
    }

    return n;
}

Node* Parser::factor() {
    if(lToken->name == NUMBER) {
        return new Node(F,lToken);

    } else if(lToken->name == SEPARATOR) {
        if(lToken->attribute == L_PARENTHESE) {
            advance();
            return expr();
            match(R_PARENTHESE);
        } else if(lToken->attribute == L_BRACKET) {
            advance();
            return expr();
            match(R_BRACKET);
        } else {
            return new Node(UNDEF_VALUE);
        }
    } else {
        error("Syntatical error!");
        return new Node(UNDEF_VALUE);
    }
}

void Parser::error(string s) {
    cout << s << '\n';
}