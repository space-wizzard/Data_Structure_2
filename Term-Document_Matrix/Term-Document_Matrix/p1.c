#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <stdio.h>
//#include <stdlib.h>
//#define _CRT_SECURE_NO_WARNINGS
//typedef struct tdm {
//	int row;
//	int col;
//}tdm;
//
//int main() {
//	int row, col;
//	printf("Input count of row and column:");
//	scanf("%d%d", &row, &col);
//	int (*double_matrix)[col] = malloc(sizeof(int) * row * col);
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			scanf("%d", &*double_matrix[i][j]);
//		}
//	}
//	
//	tdm t[10];
//	printf("Input count of row and column:");
//	scanf("%d", &t[0].row);
//	scanf("%d", &t[0].col);
//
//
//}


typedef struct {
    int row;
    int col;
    int value;
} tdm;

int main() {
    printf("Input row and col");
    int row, col;
    scanf("%d%d", &row, &col);
    // Dynamically allocate memory for the matrix
    tdm**t= (tdm**)malloc(sizeof(tdm*)*row);
    int** ans = malloc(sizeof(int) * row);
    
    for (int i = 0; i < row; i++) {
        t[i] = (tdm*)malloc(sizeof(tdm) * col);
        ans[i] = malloc(sizeof(int) * col);
    }
    
    int count = 0;
    // Input values into the matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            t[i][j].row = i;
            t[i][j].col = j;
            printf("Input %dst document:",count);
            scanf("%d", &t[i][j].value);
            count++;
        }
    }
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (t[i][j]!=0)
        }
    }
    /*for (int i = 0; i <row ; i++) {
        for (int j = 0; j < col; j++) {
            if (t[i][j].value != 0) {
                printf("Document No.%d %d\n", i + j, t[i][j].value);
           }
        }
    }*/

    

    

    
}


