#include "DoubleLinkedList.h"

int main() {
	HeadNode* L = CreateLinkedList();
	ListNode* node = NULL;
	int n;
	//ListNode* node = L->head;
	/*InsertNodeFirst(L);
	InsertNodeFirst(L);
	InsertNodeFirst(L);
	PrintList(L);
	InsertNodeFirst(L);
	InsertNodeFirst(L);*/
	int num=0;
	while (num != 4) {
		scanf("%d", &num);
		switch (num) {
		case 1:
			InsertNodeFirst(L);
			break;
		case 2:
			PrintList(L);
			break;
		case 3:
			scanf("%d", &n);
			node = SearchNthNode(L, n);
			printf("%s", node->data);
			break;
		case 4:
			printf("Finish");
			FreeNode(L);
			break;
		case 5:
			DeleteNode(L, L->head);
		}
	}
	
	/*PrintList(L);
	InsertNodeFirst(L);
	InsertNodeFirst(L);
	PrintList(L);
	printf("%d", CountNode(L));
	int n;
	scanf("%d", &n);
	ListNode* node = SearchNthNode(L, n);
	printf("%s", node->data);*/
	char x[10];
	scanf("%s", x);
	printf("%d",SearchDay(L, x));
}