#include "smTranspose.h"
#include <stdio.h>
void PrintMatrix(term target[]) {
	int row, col,not_zero;
	row = target[0].row;
	col = target[0].col;
	not_zero = target[0].value;
	int z = 0;
	int r = 0;
	int c = 0;
	int idx = 1;
	while (not_zero != 0) {
		if (target[idx].row == r && target[idx].col == c) {
			printf("%2d ", target[idx].value);
			not_zero = not_zero - 1;
			idx++;
		}
		else
			printf("%2d ", z);
		c++;

		if (c == col) {
			r++;
			c = 0;
			printf("%d«‡ ¡æ∑·\n", target[0].value - not_zero);
		}
			
	}
	/*for (int i = 0; i < col; i++) {
		for (int j = 1; j < row; j++) {
			if (target[j].row != 0)
				printf("%2d ", target[j].value);
			else
				printf("%2d ", z);
		}
		printf("\n");
	}*/
}

void smTranspose(term a[], term b[]) {
	int row, col, value;
	col = a[0].col;
	row = a[0].row;
	value = a[0].value;

	b[0].col = row;
	b[0].row = col;
	b[0].value = value;
	if (value > 0) {
		int p = 1;
		for (int i = 0; i < col; i++) {
			for (int j = 1; j <= row; j++) {
				if (a[j].col == i) {
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}
}