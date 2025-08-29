// Including librarires
#include "lexer.h"

// Builder
Lexer::Lexer(string input) {
    this->input = input;
    cout << "The input text is: " << input << "\n" << "Tamanho: " << input.length() << "\n";
    
    pos = 0;
}

// Method that returns the next token identified
Token* Lexer::nextToken() {
    Token* tok;
    int state = 0;  // initial state
    string lexeme;

    while(true) {
        switch (state) {
            case 0:         // When the state is 0 or 10
                if(input[pos] == '\0') {
                    tok = new Token(END_OF_FILE);
                    return tok;

                } else if(isdigit(input[pos])) {
                    lexeme.push_back(input[pos]);
                    state = 1;
                } else if(input[pos] == '+') {
                    state = 11;
                } else if(input[pos] == '-') {
                    state = 12;
                } else if(input[pos] == '*') {
                    state = 13;
                } else if(input[pos] == '/') {
                    state = 14;
                }

                pos++;
                break;

            case 1:         // Case a number is identified
                if(!isdigit(input[pos])) {
                    if(input[pos] == '.') {
                        state = 3;
                    } else if(input[pos] == 'E') {
                        state = 6;
                    } else {
                        state = 2;
                    }
                }
                lexeme.push_back(input[pos]);
                pos++;
                break;
            
            case 2:
                pos--;
                lexeme.pop_back();
                tok = new Token(NUMBER, INTEGER_LITERAL);
                tok->lexeme = lexeme;
                return tok;
                
            case 3:
                if(isdigit(input[pos])) {
                    state = 4;
                } else {
                    lexicalError();
                }
                lexeme.push_back(input[pos]);
                pos++;
                break;
            
            case 4:         // Case is a float number
                if(!isdigit(input[pos])) {
                    if(input[pos] == 'E') {
                        state = 6;
                    } else {
                        state = 5;
                    }
                }
                lexeme.push_back(input[pos]);
                pos++;
                break;

            case 5:
                pos--;
                lexeme.pop_back();
                tok = new Token(NUMBER, FLOAT_LITERAL);
                tok->lexeme = lexeme;
                return tok;

            case 6:        // Case is a double number
                if(isdigit(input[pos])) {
                    state = 8;
                } else {
                    if(input[pos] == '+' || input[pos] == '-') {
                        state = 7;
                    } else {
                        lexicalError();
                    }
                }
                lexeme.push_back(input[pos]);
                pos++;
                break;
            
            case 7:
                if(isdigit(input[pos])) {
                    state = 8;
                } else {
                    lexicalError();
                }
                lexeme.push_back(input[pos]);
                pos++;
                break;

            case 8:
                if(!isdigit(input[pos])) {
                    state = 9;
                }
                lexeme.push_back(input[pos]);
                pos++;
                break;
            
            case 9:
                pos--;
                lexeme.pop_back();
                tok = new Token(NUMBER, DOUBLE_LITERAL);
                tok->lexeme = lexeme;
                return tok;
            
            case 11:
                tok = new Token(OPSIGNAL, SM);
                return tok;
            
            case 12:
                tok = new Token(OPSIGNAL, SB);
                return tok;

            case 13:
                tok = new Token(OPSIGNAL, MU);
                return tok;
            
            case 14:
                tok = new Token(OPSIGNAL, DI);
                return tok;

        default:
            break;
        }
    }
}

// Lexical Error identified
void Lexer::lexicalError() {
    cout << "Token bad informed" << "\n";
    exit(EXIT_FAILURE);
}