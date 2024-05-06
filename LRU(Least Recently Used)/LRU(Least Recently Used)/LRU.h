#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* llink;
	struct ListNode* rlink;
}Node;

typedef struct {
	Node* top;
}Nodeh;

Nodeh* CreateDoubleLinkedList(int n);
Node* CreateNode();
void PrintNode(Nodeh* L);
void InsertNode(Nodeh* head);
int CountNode(Nodeh* L);
void DeleteNode(Nodeh* L);
Node* SearchNode(Nodeh* L, int data);
void MoveNode(Nodeh* head, Node* target);