#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

Nodeh* createLinkedList() {
	Nodeh* L = (Nodeh*)malloc(sizeof(Nodeh));
	L->head = NULL;
	return L;
}
Node* createNode(char*x) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->data, x);
	newnode->link = NULL;
	return newnode;
}

void InsertFirstNode(Nodeh* L, char* x) {
	if (L == NULL)
		return;
	Node*newnode = createNode(x);

	newnode->link = NULL;
	newnode->link = L->head;
	L->head = newnode;
}

void FreeNode(Nodeh*L) {
	Node* curr;
	while (L->head!= NULL) {
		curr = L->head;
		L->head = L->head->link;
		free(curr);
		curr = NULL;

	}
}
void InsertMiddleNode(Nodeh* L, char* x,char*newdata) {
	Node* newnode = createNode(newdata);
	Node* currnode = L->head;
	Node* temp = NULL;
	if (L == NULL)  // 헤드 노드가 없는 경우
		InsertFirstNode(L, x);
	
	//중간에 노드 삽입
	else {
		while (strcmp(x, currnode->data) != 0) {
			//printf("%s\n", currnode->data);
			currnode = currnode->link;
		}
		
		temp = currnode->link;
		currnode->link = newnode;
		newnode->link = temp;

	}
		
	
	
}

void InsertLastNode(Nodeh* L, char* x) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->data, x);
	Node* curr = NULL;
	if (L == NULL) {
		L->head = newnode;
		return;
	}
	curr = L->head;
	while (curr->link != NULL) {
		curr = curr->link;
	}
	curr->link = newnode;

}

void printList(Nodeh* L) {
	/*Node* currnode;
	currnode = L->head;
	while (currnode != NULL) {
		printf("%s\n", currnode->data);
		currnode = currnode->link;
	}*/
	Node* p = NULL;
	//헤드 노드(Nodeh) 안에 head 변수의 자료형은(Node)
	for (p = L->head; p != NULL; p = p->link) {
		printf("%s\n", p->data);
	}
}