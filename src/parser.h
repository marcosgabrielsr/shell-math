// Including libraries
#include "scanner.h"

class Parser
{
    private:
        Scanner* scanner;
        Token* lToken;

        void advance();
        void match(int);

        void goal();
        void expr();
        void _expr();
        void term();
        void _term();
        void factor();

        void error(string);

    public:
        // Constructor method
        Parser(string);
        
        // Method that execute the Syntatical Analysis
        void run();
};