#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	int data;
	struct Node* next;
}ListNode;

// head pointer(not node)
typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* CreateLinkedList();
ListNode* CreateNode();
void InsertFirstNode(HeadNode* node);
void InsertLastNode(HeadNode* node);
void PrintNode(HeadNode* node);
ListNode* searchNode(HeadNode* L, int x);
void InsertMiddleNode(HeadNode* L, ListNode* pre);
void DeleteNode(HeadNode* L, ListNode* p);