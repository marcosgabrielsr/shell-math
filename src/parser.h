// Including libraries
#include "scanner.h"
#include "syntatic-tree.h"

class Parser
{
    private:
        Scanner* scanner;
        Token* lToken;
        SyntaticTree* syncTree;

        void advance();
        void match(int);

        void goal();
        Node* expr();
        Node* _expr();
        Node* term();
        Node* _term();
        Node* factor();

        void error(string);

    public:
        // Constructor method
        Parser(string);
        
        // Method that execute the Syntatical Analysis
        void run();
};