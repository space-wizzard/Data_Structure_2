#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "list.h"


int main(void) {
	int list[MAX] = { 10,20,30,40,50,60,70 };
	int i, target, size,insert;
	printf("\n삽입 전 선형 리스트");
	size = sizeof(list) / sizeof(int);
	for (i = 0; i < size; i++) {
		printf("%3d", list[i]);
	}
	scanf("%d", &target);
	size = sizeof(list) / sizeof(int);
	DeleteElement(list, target,size);
	scanf("%d", &insert);
	InsertElement(list, insert,size);
	for (i = 0; i < size; i++) {
		printf("%3d", list[i]);
	}
}