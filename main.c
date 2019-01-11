#include <stdio.h>
#include "list.h"
#include <stdlib.h>

int main(void){
	newList();
	int count;

	while (scanf("%d", &count) == 1) { 
		if (count > 0) {
			if (!addNode(count)) {
				printf("No memory left!\n");
				exit(EXIT_FAILURE);
			}
		}
		else {
			prettyPrint();
			exit(EXIT_SUCCESS);
		}
	}
	printf("Invalid Input!\n");
	exit(EXIT_FAILURE);
}
