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
    Token::printToken(lToken);
}

void Parser::match(int t) {
    if (lToken->name == t || lToken->attribute == t) {
        advance();
    } else {
        error("Unexpected token");
    }
}

SyntaticTree* Parser::getSyntaticTree() {
    return syncTree;
}

void Parser::goal() {
    Node* r = expr();
    syncTree->startTree(r);
    cout << "Compilation done!" << '\n';
    syncTree->printInOrder();
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
        n = new Node(_E, lToken);
        advance();
        cout << "a\n";
        n->first = term();
        n->second = _expr();
    } else {
        n = new Node(_E);
    }
    cout << "_E\n";

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
        n = new Node(_T, lToken);
        advance();
        n->first = factor();
        n->second = _term();
    } else {
        n = new Node(_T);
    }

    return n;
}

Node* Parser::factor() {
    Node* n;

    if(lToken->name == NUMBER) {
        n = new Node(F,lToken);
        advance();
        return n;

    } else if(lToken->name == SEPARATOR) {
        if(lToken->attribute == L_PARENTHESE) {
            advance();
            n = expr();
            match(R_PARENTHESE);
            return n;
        } else if(lToken->attribute == L_BRACKET) {
            advance();
            n = expr();
            match(R_BRACKET);
            return n;
        } else {
            n = new Node(UNDEF_VALUE);
            return n;
        }
    } else {
        error("Syntatical error!");
        return new Node(UNDEF_VALUE);
    }
}

void Parser::error(string s) {
    cout << s << '\n';
}