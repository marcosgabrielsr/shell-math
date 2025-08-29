// Including libraries
#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

enum Names {
    UNDEF, //0
    NUMBER, //1
    DOUBLE_LITERAL, //2
    FLOAT_LITERAL, //3
    INTEGER_LITERAL, //4
    OPSIGNAL, //5
    SM, //6
    SB, //7
    MU, //8
    DI, //9
    GRSYMBOLS, //10
    PAR_RIGHT, //11
    PAR_LEFT, //12
    BRACK_RIGHT, //13
    BRACK_LEFT, //14
    END_OF_FILE //15
};

class Token {
    public:
        int name;
        int attribute;
        string lexeme;

        Token(int name) {
            this->name = name;
            attribute = UNDEF;
        }

        Token(int name, int attr) {
            this->name = name;
            this->attribute = attr;
        }
};