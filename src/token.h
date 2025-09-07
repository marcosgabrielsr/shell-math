// Including libraries
#include <iostream>
#include <ctype.h>
#include <array>
#include <string>

using namespace std;

enum Names {
    UNDEF,            //0
    NUMBER,           //1
    DOUBLE_LITERAL,   //2
    FLOAT_LITERAL,    //3
    INTEGER_LITERAL,  //4
    PLUS,             //5
    MINUS,            //6
    MULT,             //7
    DIV,              //8
    L_PARENTHESE,     //9
    R_PARENTHESE,     //10
    L_BRACKET,        //11
    R_BRACKET,        //12
    END_OF_FILE       //13
};

class Token {
    public:
        int name;
        int attribute;
        string lexeme;

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