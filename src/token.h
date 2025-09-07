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
    FLOAT_LITERAL,              //3
    INTEGER_LITERAL,            //4
    ARITHMETIC_OPERATORS,       //5
    PLUS,                       //6
    MINUS,                      //7
    MULT,                       //8
    DIV,                        //9
    SEPARATORS,                 //10     
    L_PARENTHESE,               //11
    R_PARENTHESE,               //12
    L_BRACKET,                  //13
    R_BRACKET,                  //14
    END_OF_FILE                 //15
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