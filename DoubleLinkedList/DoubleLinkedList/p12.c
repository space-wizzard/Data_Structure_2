#include "DoubleLinkedList1.h"

int main() {
	HeadNode* L = CreateLinkedList();
	//ListNode* node = L->head;
	InsertNode(L);
	InsertNode(L);
	InsertNode(L);
	PrintList(L);
	InsertNode(L);
	InsertNode(L);
	PrintList(L);
	InsertNode(L);
	InsertNode(L);
	PrintList(L);
	InsertNode(L);
	printf("%d",CountNode(L));
	int n;
	scanf("%d", &n);
	ListNode*node=SearchNthNode(L, n);
	printf("%s", node->data);
}