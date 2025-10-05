// Importing libraries
#include "token.h"

class Scanner {
    private:
        // Declaring atributes
        string input;                       // Store the input text
        int pos;                            // Store the position in the input text
    
    public:
        // Builder
        Scanner(string);

        // Method that returns the next token identified
        Token* nextToken();

        // Lexical Error identified
        void lexicalError();
};