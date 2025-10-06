// Including libraries
#include <iostream>
#include "parser.h"

using namespace std;

// Functions prototype
void printTk(string* vect, Token* t);
string* allocVect();
void freeVect(string* vect);

int main() {
    // Declaring variables
    string* vect = allocVect();
    string input;               // variable to store the math expression
    getline(cin, input);

    // Scanner test
    Scanner* scan = new Scanner(input);

    Token* t;
    do {
        t = scan->nextToken();
        printTk(vect, t);
    } while(t->name != END_OF_FILE);

    cout << "\n";
    freeVect(vect);

    // Parser test
    Parser* parser = new Parser(input);
    parser->run();

    return EXIT_SUCCESS;
}

string* allocVect() {
    string* vect = new string[16];
    vect[0] = "UNDEF";
    vect[1] = "NUMBER";
    vect[2] = "DOUBLE_LITERAL";
    vect[3] = "INTEGER_LITERAL";
    vect[4] = "ARITHMETIC_OPERATOR";
    vect[5] = "PLUS";
    vect[6] = "MINUS";
    vect[7] = "MULT";
    vect[8] = "DIV";
    vect[9]= "SEPARATOR";
    vect[10] = "L_PARENTHESE";
    vect[11] = "R_PARENTHESE";
    vect[12] = "L_BRACKET";
    vect[13] = "R_BRACKET";
    vect[14] = "END_OF_FILE";

    return vect;
}

void freeVect(string* vect) {
    delete[] vect;
}

void printTk(string* vect, Token* t) {
    cout << vect[t->name];

    if(t->name == NUMBER) {
        cout << "(" << t->lexeme << ")";
    } else {
        cout << "(" << vect[t->attribute] << ")";
    }
    
    cout << " ";
}