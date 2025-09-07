// Including libraries
#include <iostream>
#include "lexer.h"

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

    Lexer* lexer = new Lexer(input);

    Token* t;
    do {
        t = lexer->nextToken();
        printTk(vect, t);
    } while(t->name != END_OF_FILE);

    cout << "\n";
    freeVect(vect);
    return EXIT_SUCCESS;
}

string* allocVect() {
    string* vect = new string[14];
    vect[0] = "UNDEF";
    vect[1] = "NUMBER";
    vect[2] = "DOUBLE_LITERAL";
    vect[3] = "FLOAT_LITERAL";
    vect[4] = "INTEGER_LITERAL";
    vect[5] = "PLUS";
    vect[6] = "MINUS";
    vect[7] = "MULT";
    vect[8] = "DIV";
    vect[9] = "L_PARENTHESE";
    vect[10] = "R_PARENTHESE";
    vect[11] = "L_BRACKET";
    vect[12] = "R_BRACKET";
    vect[13] = "END_OF_FILE";

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