// Including libraries
#include <iostream>

using namespace std;

// Functions prototype
void allocVector(string* vet);

int main() {
    string* vet;
    allocVector(vet);
    
    return EXIT_SUCCESS;
}

void allocVector(string* vet) {
    vet = new string[17];
}