// Including libraries
#include <stdio.h>
#include <stdlib.h>
#include "opTree.h"
#include "mathExp.h"

int main(int argc, char const *argv[]) {
	struct Node* opTree = NULL;
	char mExp[] = "1 + 2";
	removeSpaces(mExp);

	setOpTreFromExpression(&opTree, mExp);
	if(opTree == NULL) {
		printf("Error\n");
	} else {
		printOpTree(opTree);
	}
	printf("\n");

	return 0;
}
