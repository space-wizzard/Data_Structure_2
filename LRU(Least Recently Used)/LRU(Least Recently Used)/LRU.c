#include "LRU.h"

Nodeh* CreateLinkedList() {
	Nodeh* head = malloc(sizeof(Node));
	head->top = NULL;
	return head;
}

Node* CreateNode(Node*prev,Node*curr) {
	Node* newnode = malloc(sizeof(Node));
	newnode->llink = prev;
	newnode->rlink = NULL;
	scanf("%d", &newnode->data);

	return newnode;
}