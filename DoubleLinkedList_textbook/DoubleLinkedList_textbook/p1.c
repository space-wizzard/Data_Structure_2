#include "DoubleLinkedList.h"

int main() {
	linkedList_h* DL;
	listNode* p;
	DL = createLinkedList_h();
	PrintList(DL);
	printf("\n");
	InsertNode(DL, NULL, "��");
	PrintList(DL);
	printf("\n");
	p = SearchNode(DL, "��");
	InsertNode(DL, p, "��");
	PrintList(DL);
	printf("\n");
	p = SearchNode(DL, "��");
	InsertNode(DL, p, "��");
	PrintList(DL);
	printf("\n");
	p = SearchNode(DL, "��");
	DeleteNode(DL, p);
	PrintList(DL);
}