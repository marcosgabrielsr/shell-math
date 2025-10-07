// Including libraries
#include "syntatic-tree.h"

// Class Node Methods
// Constructor Method
Node::Node(int v) {
    value = v;
    tok = nullptr;
    first = nullptr;
    second = nullptr;
}

Node::Node(Token* t) {
    value = UNDEF_VALUE; 
    tok = t;
    first = nullptr;
    second = nullptr;
}

Node::Node(int v, Token* t) {
    value = v; 
    tok = t;
    first = nullptr;
    second = nullptr;
}

void Node::printNode() {
    string value_name_list[] = {"UNDEF_VALUE", "E", "_E", "T", "_T", "F"};

    if(value != UNDEF_VALUE) {
        cout << value_name_list[value];
        if(tok != nullptr) {
            cout << ".Token(" << tok->name << ")";
        }
        
        cout << " ";
    }
}

SyntaticTree::SyntaticTree() {
    root = nullptr;
}

void SyntaticTree::startTree(Node* n) {
    root = n;
}

void SyntaticTree::printInOrder() {
    cout << "Printing in order:";
    if(root != nullptr) {
        printInOrder(root->first);
        root->printNode();
        printInOrder(root->second);
    }
    cout << '\n';
}

void SyntaticTree::printInOrder(Node* n) {
    if(n != nullptr) {
        printInOrder(n->first);
        n->printNode();
        printInOrder(n->second);
    }
}

// Função auxiliar recursiva
void SyntaticTree::printHierarchical(Node* n, int level) {
    if (n == nullptr) return;

    // Indentação para representar a hierarquia
    for (int i = 0; i < level; i++) cout << "│   ";

    // Prefixo visual (último nível)
    if (level > 0) cout << "├── ";

    // Imprime o nó atual
    if (n->value != UNDEF_VALUE) {
        string value_name_list[] = {"UNDEF_VALUE", "E", "_E", "T", "_T", "F"};
        cout << value_name_list[n->value] << endl;
    } else if (n->tok != nullptr) {
        cout << "Token(" << n->tok->name << ")" << endl;
    } else {
        cout << "(nó vazio)" << endl;
    }

    // Recursão nos filhos
    if (n->first != nullptr || n->second != nullptr) {
        printHierarchical(n->first, level + 1);
        printHierarchical(n->second, level + 1);
    }
}

// Função pública para começar pela raiz
void SyntaticTree::printHierarchical() {
    if (root == nullptr) {
        cout << "Void Tree." << endl;
        return;
    }

    cout << "Syntatic Tree (Hierarchcal):" << endl;
    printHierarchical(root, 0);
}