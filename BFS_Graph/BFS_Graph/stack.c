#include "Stack.h"

int top = -1;

int isStackEmpty(void) {
	if (top == -1)
		return 1;
	else
		return 0;
}

int isStackFull(void) {
	if (top == STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

void push(element item) {
	if (isStackFull()) {
		printf("\n\n Stack is Full!\n");
		return;
	}
	else
		stack[++top] = item;

}

element pop(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty\n");
		return 0;
	}
	else
		return stack[top--];
}

element peek(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty\n");
		return 0;
	}
	else
		return stack[top];
}

void printStack(void) {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++) {
		printf("%d ", stack[i]);
	}
	printf("]");
}

void createGraph(graphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;
		g->visited[v] = 0;
	}
}
void insertVertex(graphType* g, int v) {

	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n �׷��� ������ ������ �ʰ��߽��ϴ�.");
		return;
	}
	
	g->n += 1;

}
void insertEdge(graphType* g, int u, int v) {
	//u -> ���� ����, v->������ ����
	graphNode* node;

	if (u >= g->n || v >= g->n) {
		printf("�׷����� ���� �����Դϴ�.");
		return;
	}
	node = malloc(sizeof(graphNode));
	node->vertex = v;
	// �� ���� ����(node)�� ���� ����Ʈ�� ù��° ���� ������Ʈ(�Ʒ� 2�� �ڵ�)
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
	graphNode* p;
	for (int i = 0; i < g->n; i++) {
		printf("\n\t����%c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("->%c", p->vertex + 65);
			p = p->link;
		}
	}
}

void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf(" %c", v + 65);

	while (!isStackEmpty()) {
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf("%c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else
				w = w->link;
		}
		v = pop();
	}
	
}