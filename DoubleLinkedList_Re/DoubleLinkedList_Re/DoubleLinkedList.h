#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode {
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
}ListNode;

typedef struct {
	ListNode* head;
}HeadNode;

HeadNode* CreateLinkedList();
void PrintList(HeadNode* L);
ListNode* CreateNode();
void InsertNodeFirst(HeadNode* L);
ListNode* SearchNode(HeadNode* L, char* x);
int CountNode(HeadNode* L);
ListNode* SearchNthNode(HeadNode* L, int n);
int SearchDay(HeadNode* L, char* x);
void InsertNodeMiddle(ListNode* newnode, ListNode* left);
void InsertNodeLast(ListNode* newnode, ListNode* left);