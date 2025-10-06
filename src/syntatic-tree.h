// Including libraries
#include "token.h"

enum Values {
    UNDEF_VALUE,        //0
    E,                  //1
    _E,                 //2
    T,                  //3
    _T,                 //4
    F                   //5
};

class Node {
    public:
        int value;
        Token* tok;
        Node* first;
        Node* second;
        Node(int);
        Node(Token*);
        Node(int, Token*);
        void printNode();
};

class SyntaticTree {
    private:
        Node* root;
    
    public:
        SyntaticTree();
        void startTree(Node*);
        void printInOrder();
        void printInOrder(Node* n);
        void printHierarchical();
        void printHierarchical(Node* n, int level);

};