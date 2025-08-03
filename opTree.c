// Including Libraries
#include "opTree.h"

// Return a new OpTree Node
struct Node* newNode(char opSignal, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    if(newNode) {
        if(opSignal == 0) {
            newNode->opSignal = opSignal;
        } else {
            newNode->opSignal = 0;
            newNode->value = value;
        }
        newNode->left = NULL;
        newNode->right = NULL;
    }

    return newNode;
}

// Print an OpTree Node
void printNode(struct Node* node) {
    if(node->opSignal == 0) {
        printf("%d ", node->value);
    } else {
        printf("%s ", node->opSignal);
    }
}

// Print an OpTree Node with a new line character
void printlnNode(struct Node* node) {
    printNode(node);
    printf("\n");
}

// Prints a math expression from an opTree
void printOpTree(struct Node* opTree) {
    if(opTree->left != NULL) {
        printOpTree(opTree->left);
    }
    printNode(opTree->left);

    if(opTree->right != NULL) {
        printNode(opTree->right);
    }
}

// Set an opTree from a math expression
void setOpTreFromExpression(struct Node** opTree, char exp[]) {
    // Signals available currently
    char signals[] = {'+', '-'};
    int n = strlen(signals);

    for(int i = 0; i < strlen(signals); i++) {
        for(int j = 0; exp[j] != '\0'; j++) {
            if(signals[i] == exp[j]) {
                *opTree = newNode(signals[i], 0);
                (*opTree)->left = newNode(0, atoi(&exp[j - 1]));
                (*opTree)->right = newNode(0, atoi(&exp[j + 1]));
            }
        }
    }
}