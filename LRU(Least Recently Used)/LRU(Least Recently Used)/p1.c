#include "LRU.h"

int main() {
	int n;
	Nodeh* head;
	printf("Input node count ");
	scanf("%d", &n);
	head=CreateDoubleLinkedList(n);
	for(int i=0;i<10;i++) {
		printf("Search Page\n");
		InsertNode(head);
	}
	
}