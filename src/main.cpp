// Including libraries
#include <iostream>
#include "parser.h"

using namespace std;

int main() {
    // Declaring variables
    string input;               // variable to store the math expression
    getline(cin, input);

    // Parser test
    Parser* parser = new Parser(input);
    parser->run();

    return EXIT_SUCCESS;
}