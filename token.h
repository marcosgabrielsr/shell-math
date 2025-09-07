// Including libraries
#include <iostream>
#include <ctype.h>
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
    private:
        static string* vet;

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

        // Static methods to print the tokens names
        static void allocVet() {
            vet = new string[14];

            vet[0] = "UNDEF";           //0
            vet[1] = "NUMBER";          //1
            vet[2] = "DOUBLE_LITERAL";  //2
            vet[3] = "FLOAT_LITERAL";   //3
            vet[4] = "INTEGER_LITERAL"; //4
            vet[5] = "PLUS";            //5
            vet[6] = "MINUS";           //6
            vet[7] = "MULT";            //7
            vet[8] = "DIV";             //8
            vet[9] = "L_PARENTHESE";    //9
            vet[10]= "R_PARENTHESE";    //10
            vet[11]= "L_BRACKET";       //11
            vet[12]= "R_BRACKET";       //12
            vet[13] = "END_OF_FILE";    //13
        }

        static void freetVet() {
            delete[] vet;
        }

        static void printTk(Token* t) {
            cout << vet[t->name];

            if(t->name == NUMBER) {
                cout << "(" << t->lexeme << ")";
            } else {
                cout << "(" << t->attribute << ")";
            }
            
            cout << " ";
        }
};
