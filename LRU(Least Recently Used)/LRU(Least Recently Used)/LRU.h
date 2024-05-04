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

void CreateDoubleLinkedList(int n);
Node* CreateNode();
void PrintNode(Node* current);