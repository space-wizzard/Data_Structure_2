#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode {
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
}listNode;

typedef struct {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h();
void PrintList(linkedList_h* DL);
void InsertNode(linkedList_h* DL, listNode* pre, char* x);
void DeleteNode(linkedList_h* DL, listNode* old);
listNode* SearchNode(linkedList_h* DL, char* x);