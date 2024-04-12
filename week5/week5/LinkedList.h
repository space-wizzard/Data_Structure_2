#pragma once
typedef struct node {
	char data[4];
	struct node* link;
}Node;

typedef struct {
	Node* head;
}Nodeh;

Nodeh* createLinkedList(void);
void printList(Nodeh* L);
void InsertFirstNode(Nodeh* L, char* x);
void FreeNode(Nodeh* L);
void InsertLastNode(Nodeh* L, char* x);
void InsertMiddleNode(Nodeh* L, char* x,char* newdata);