// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include "mathExp.h"

// Defining constants

// Defining datastructres
struct Node {
    char opSignal;
    int value;
    struct Node* left;
    struct Node* right;
};

// Prototype functions
// Return a new OpTree Node
struct Node* newNode(char opSignal, int value);

// Prints an OpTree Node
void printNode(struct Node* node);

// Prints an OpTree Node with a new line character
void printlnNode(struct Node* node);

// Prints a math expression from an opTree
void printOpTree(struct Node* opTree);

// Set an opTree from a math expression
void setOpTreFromExpression(struct Node** opTree, char exp[]);