#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#define ROW 5
#define COL 3

//int main() {
//	int A_matrix[ROW][COL] = { 0, };	//5�� 3��
//	int B_matrix[COL][ROW] = { 0, };	//3�� 5��
//	int ans_matrix[ROW][COL] = { 0, };	//3�� 5��
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++) {
//			scanf("%d", &A_matrix[i][j]);
//
//		}
//		printf("%d�� ����\n", i + 1);
//	}
//	printf("A �Է� ����");
//
//	for (int i = 0; i < COL; i++) {
//		for (int j = 0; j < ROW; j++) {
//			scanf("%d", &B_matrix[i][j]);
//		}
//		printf("%d�� ����\n", i + 1);
//	}
//	printf("B �Է� ����");
//
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < ROW; j++) {
//			for (int k = 0; k < COL; k++) {
//				ans_matrix[i][j] += A_matrix[i][k] * B_matrix[k][j];
//			}
//		}
//	}
//
//	for (int i = 0; i < COL; i++) {
//		for (int j = 0; j < ROW; j++) {
//			printf("%d ", ans_matrix[i][j]);
//		}
//		printf("\n");
//	}
//
//}

//���Ḯ��Ʈ



int main() {
	Nodeh* L;
	Node* mid=NULL;
	L = createLinkedList();
	printf("Create NULL list\n");

	InsertFirstNode(L,"Mon");
	InsertLastNode(L, "Sun");
	InsertFirstNode(L, "tue");
	InsertFirstNode(L, "Wed");
	InsertMiddleNode(L, "tue","new");
	printList(L);

	FreeNode(L);
	// �޸� ���� �Ŀ��� ��� �� ��
	//printList(L);

//	InsertMiddleNode(mid, "Tue");
	
}