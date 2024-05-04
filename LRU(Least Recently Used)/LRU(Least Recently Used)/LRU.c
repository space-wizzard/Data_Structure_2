#include "LRU.h"

void CreateDoubleLinkedList(int n) {
	Nodeh* h = malloc(sizeof(Node));
	h->top = CreateNode();
	Node* prev = h->top;
	Node* current = NULL;
	for (int i = 0; i < n; i++) {
		//printf("%p\n", prev->rlink);
		current = CreateNode();
		current->llink = prev;
		prev->rlink = current;
		prev = current;
	}
	PrintNode(h->top);
}

void PrintNode(Node* current) {
	while (current != NULL){
		printf("%d ", current->data);
		current = current->rlink;
	}
}

Node* CreateNode() {
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) {
		return NULL;
	}
	newnode->llink = NULL;
	newnode->rlink = NULL;
	newnode->data = 0;
	return newnode;
}