#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	int arr[3][2] = { {1,2},{3,4},{5,6} };
	int target[3][2] = { {1,1},{1,1},{1,1} };
	int** ans = (int**)malloc(sizeof(int) * ROW);
	for (int i = 0; i < ROW; i++) {
		ans[i] = (int*)malloc(sizeof(int) * COL);
	}
	ans=Add_Matrix(arr,target);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("%d ", ans[i][j]);
		}
	}
	free(ans);
}