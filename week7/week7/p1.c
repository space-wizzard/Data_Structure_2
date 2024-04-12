#define _CRT_SECURE_NO_WARNINGS

#include "InsertLinkedList.h"

int main() {
	HeadNode* l = CreateLinkedList();
	printf("%p\n", l);
	InsertFirstNode(l);
	InsertFirstNode(l);
	
	InsertFirstNode(l);
	InsertLastNode(l);
	InsertMiddleNode(l,NULL);
	InsertMiddleNode(l, l->head->next);
	InsertLastNode(l);
	printf("Delete second node ");
	DeleteNode(l, l->head->next->next);
	InsertLastNode(l);
	PrintNode(l);
}