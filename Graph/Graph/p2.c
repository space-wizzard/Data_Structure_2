#include "adjMatrix.h"

int main() {
	graphType* G1 = malloc(sizeof(graphType));
	graphType* G2 = malloc(sizeof(graphType));
	graphType* G3 = malloc(sizeof(graphType));

	createGraph(G1);
	createGraph(G2);
	createGraph(G3);

	for (int i = 0; i < 29; i++) {
		insertVertex(G1, i);
	}
	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 1);
	print_adjMatrix(G1);
}