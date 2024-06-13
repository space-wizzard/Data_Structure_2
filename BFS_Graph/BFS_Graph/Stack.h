#pragma once
#define STACK_SIZE 30
#define MAX_VERTEX 30
#define FALSE 0
#define TRUE 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
element stack[STACK_SIZE];
int isStackEmpty(void);
int isStackFull(void);
void push(element item);
element pop(void);
element peek(void);
void printStack(void);

typedef struct graphNode {
	int vertex;							// ���� �̸�
	struct graphNode* link;				// ���� ���� �����ϴ� link field
}graphNode;

typedef struct graphType {
	int n;								// �׷��� ���� ����
	graphNode* adjList_H[MAX_VERTEX];	// �׷��� ������ ���� ��� ������ �迭(�������� ��� ������ ����)
	int visited[MAX_VERTEX];
}graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);
void DFS_adjList(graphType* g, int v);