#include "DoubleLinkedList.h"

int main() {
	linkedList_h* DL;
	listNode* p;
	DL = createLinkedList_h();
	PrintList(DL);
	printf("\n");
	InsertNode(DL, NULL, "월");
	PrintList(DL);
	printf("\n");
	p = SearchNode(DL, "월");
	InsertNode(DL, p, "수");
	PrintList(DL);
	printf("\n");
	p = SearchNode(DL, "수");
	InsertNode(DL, p, "금");
	PrintList(DL);
	printf("\n");
	p = SearchNode(DL, "월");
	DeleteNode(DL, p);
	PrintList(DL);
}