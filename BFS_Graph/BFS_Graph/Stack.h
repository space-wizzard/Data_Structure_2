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
	int vertex;							// 정점 이름
	struct graphNode* link;				// 다음 정점 연결하는 link field
}graphNode;

typedef struct graphType {
	int n;								// 그래프 정점 개수
	graphNode* adjList_H[MAX_VERTEX];	// 그래프 정점에 대한 헤드 포인터 배열(정점마다 헤드 포인터 생성)
	int visited[MAX_VERTEX];
}graphType;

void createGraph(graphType* g);
void insertVertex(graphType* g, int v);
void insertEdge(graphType* g, int u, int v);
void print_adjList(graphType* g);
void DFS_adjList(graphType* g, int v);