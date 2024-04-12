#include <stdio.h>
#include "smTranspose.h"
int main() {
	term a[] = { {8,7,9},{0,2,2},{1,4,7},{2,0,23},{3,3,31},{4,1,14},{4,5,25},{5,6,6},{6,0,52},{7,4,11} };
	term b[sizeof(a) / sizeof(a[0])];
	printf("<<锐家青纺 a>>\n");
	PrintMatrix(a);
	/*for (int i = 0; i < a[0].value; i++) {
		printf("\n[%3d,%3d,%3d]", a[i].row, a[i].col, a[i].value);
	}*/
	smTranspose(a, b);
	printf("\n<<锐家青纺 b>>\n");
	//PrintMatrix(b);
	/*for (int i = 0; i < b[0].value; i++) {
		printf("\n[%3d,%3d,%3d]", b[i].row, b[i].col, b[i].value);
	}*/
}