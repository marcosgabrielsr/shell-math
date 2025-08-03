// Importing libraries
#include "mathExp.h"

// Removes the spaces from an math expression
void removeSpaces(char exp[]) {
    int n = strlen(exp);

    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == ' ') {
            do {
                memmove(&exp[i], &exp[i+1], n - i);
            } while(exp[i] == ' ');
        }
    }
}