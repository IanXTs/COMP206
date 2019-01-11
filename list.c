#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NODE {
	int data;
	struct  NODE *next;
};

struct NODE *head;

void newList(){

	head = NULL;
}

int addNode(int value){
	struct NODE *makeNode = malloc(sizeof(struct NODE));
	if (makeNode == NULL) return false;

	makeNode->data = value;
    makeNode->next = head;
	head = makeNode;
	return true;
}

void prettyPrint(){
	struct NODE *workingNode = head;

	while (workingNode != NULL){
		printf("%d\n", workingNode->data);
		workingNode = workingNode->next;
	}
	
	
}

