#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"


int main(void) {
	int list[MAX] = { 10,20,30,40,50,60,70 };
	int i, target, size,insert;
	printf("\n���� �� ���� ����Ʈ");
	size = sizeof(list) / sizeof(int);
	for (i = 0; i < size; i++) {
		printf("%3d", list[i]);
	}
	scanf("%d", &target);
	DeleteElement(list, target);
	scanf("%d", &insert);
	InsertElement(list, insert);
	for (i = 0; i < size; i++) {
		printf("%3d", list[i]);
	}
}