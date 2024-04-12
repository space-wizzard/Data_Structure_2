#include "list.h"
void DeleteElement(int l[],int target) {
	int size = sizeof(*l) / sizeof(l[0]);
	int idx = 0;
	while (1) {
		if (l[idx] == target) {
			break;
		}
		idx++;
	}
	for (int i = 0; i < size-1; i++) {
		if (idx <= i) 
			l[i] = l[i + 1];
	}
}

void InsertElement(int l[], int insert) {
	int size = sizeof(*l) / sizeof(l[0]);
	int idx = 0;
	for (int i = 0; i < size-1; i++) {
		if (l[i] > insert && l[i + 1] < insert) {
			l[i + 1] = insert;
			idx = i + 1;
			break;
		}
	}
}