#include "adjMatrix.h"

void createGraph(graphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = 0; j < MAX_VERTEX; j++) {
			g->adjMatrix[i][j] = 0;
		}
	}
}

void insertVertex(graphType* g, int v) {
	
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과했습니다.");
		return;
	}
	if (v < (g->n))
		return;
	g->n += 1;

}

void insertEdge(graphType* g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		printf("\n 그래프가 없는 정점입니다.");
		return;
	}
	g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(graphType* g) {
	for (int i = 0; i < g->n; i++) {
		printf("\n\t\t");
		for (int j = 0; j < g->n; j++) {
			printf("%2d", g->adjMatrix[i][j]);
		}
	}
	
}
