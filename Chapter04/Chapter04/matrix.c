#include <stdio.h>
#include "matrix.h"

int** Add_Matrix(int a[3][2], int b[3][2]) {
	int** c = (int**)malloc(sizeof(int) * ROW);
	for (int i = 0; i < ROW; i++) {
		c[i] = (int*)malloc(sizeof(int) * COL);
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return c;
}

