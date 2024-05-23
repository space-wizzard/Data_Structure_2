#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GiftIndex(char friends[4][10], char gifts[10][15]) {
	int idx[4] = { 0, };
	char a[4][10] = { 0, };
	char* friend = malloc(sizeof(char)*10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			if (strcmp(gifts[i][j]," ")==0) {
				strcpy(a[i], friend);
				printf("%s\n", a[i]);
				friend = NULL;
			}
			else {
				strcat((char*)gifts[i][j],friend);
				printf("%s\n", friend);
			}
		}
	}
}


int main() {
	char friends[4][10] = {"muzi", "ryan", "frodo", "neo"};
	printf("%s", friends[0]);
	char gifts[10][15] = { "muzi frodo", "muzi frodo", "ryan muzi", 
		"ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" };
	// 선물 지수 만들기
	GiftIndex(friends,gifts);

	
}
