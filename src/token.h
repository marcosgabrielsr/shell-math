// Including libraries
#include <iostream>
#include <ctype.h>
#include <array>
#include <string>

using namespace std;

enum Names {
    UNDEF,                      //0
    NUMBER,                     //1
    DOUBLE_LITERAL,             //2
    INTEGER_LITERAL,            //3
    ARITHMETIC_OPERATOR,        //4
    PLUS,                       //5
    MINUS,                      //6
    MULT,                       //7
    DIV,                        //8
    SEPARATOR,                  //9     
    L_PARENTHESE,               //10
    R_PARENTHESE,               //11
    L_BRACKET,                  //12
    R_BRACKET,                  //13
    END_OF_FILE                 //14
};

class Token {
    public:
        int name;                       // Name of the lexeme
        int attribute;                  // Attribute to specify the lexeme
        string lexeme;                  // Lexeme identified

        // Constructor methods
        Token(int name) {
            this->name = name;
            attribute = UNDEF;
        }

        Token(int name, int attr) {
            this->name = name;
            this->attribute = attr;
        }
};