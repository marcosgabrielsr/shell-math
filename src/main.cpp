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
    string* vect = new string[16];
    vect[0] = "UNDEF";
    vect[1] = "NUMBER";
    vect[2] = "DOUBLE_LITERAL";
    vect[3] = "FLOAT_LITERAL";
    vect[4] = "INTEGER_LITERAL";
    vect[5] = "ARITHMETIC_OPERATORS";
    vect[6] = "PLUS";
    vect[7] = "MINUS";
    vect[8] = "MULT";
    vect[9] = "DIV";
    vect[10]= "SEPARATORS";
    vect[11] = "L_PARENTHESE";
    vect[12] = "R_PARENTHESE";
    vect[13] = "L_BRACKET";
    vect[14] = "R_BRACKET";
    vect[15] = "END_OF_FILE";

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