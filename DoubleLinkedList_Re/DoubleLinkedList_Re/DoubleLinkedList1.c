#include "DoubleLinkedList.h"

HeadNode* CreateLinkedList() {
	HeadNode* newnode = NULL;
	newnode = (HeadNode*)malloc(sizeof(HeadNode));
	if (newnode == NULL) exit(1);
	newnode->head = NULL;
	return newnode;
}

ListNode* CreateNode() {
	ListNode* newnode = NULL;
	newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		printf("NULL");
		return NULL;
	}

	newnode->rlink = NULL;
	newnode->llink = NULL;
	printf("Newnode data?");
	scanf("%s", newnode->data);
	return newnode;

}

ListNode* SearchNode(HeadNode* L, char* x) {
	ListNode* curr = L->head;
	while (curr != NULL) {
		if (strcmp(curr->data, x) == 0)
			return curr;
		else
			curr = curr->rlink;
	}
	return NULL;
}

void InsertNodeLast(ListNode* newnode, ListNode* left) {
	newnode->llink = left->rlink;
	left->rlink = newnode;
	printf("Ÿ�� ��尡 ���Ḯ��Ʈ�� ������ ����� ���\n");
}

void InsertNodeMiddle(ListNode* newnode, ListNode* left) {
	newnode->rlink = left->rlink;
	left->rlink = newnode;
	newnode->llink = left;
	left->rlink->llink = newnode;
	printf("Ÿ�� ��尡 ���Ḯ��Ʈ ó���̳� �߰��� �ִ� ���\n");
}

void InsertNodeFirst(HeadNode* L) {
	ListNode* left = NULL;
	ListNode* newnode = NULL;
	newnode = CreateNode();
	char x[10];

	printf("Target Node?");
	printf("Target ");
	scanf("%s", x);
	if (L->head == NULL) {					// ��� ��忡 �ƹ��͵� ���� ���(���Ḯ��Ʈ�� �ƹ��͵� ���� ��)
		L->head = newnode;					// �� ��带 ��� �����ͷ� ����
		printf("��� ��忡 �ƹ��͵� ���� ���\n");
	}
	else if (SearchNode(L, x) == NULL) {	// data x�� ���Ḯ��Ʈ�� ���� ��� ... ���Ḯ��Ʈ ó���� ����
		newnode->rlink = L->head;
		//newnode->rlink->llink = newnode;
		L->head = newnode;
		printf("data x�� ���Ḯ��Ʈ�� ���� ���\n");
	}

	else {									// data x�� �ִ� ��� �ڿ� �����ϴ� ���
		left = SearchNode(L, x);
		if (left->rlink == NULL) 			// Ÿ�� ��尡 ���Ḯ��Ʈ�� ������ ����� ��� ... ���Ḯ��Ʈ �������� ����
			InsertNodeLast(newnode, left);
		else 								// Ÿ�� ��尡 ���Ḯ��Ʈ �߰��� �ִ� ��� ... Ÿ�� ��� ������ ����
			InsertNodeMiddle(newnode, left);
		
	}

}


void PrintList(HeadNode* L) {
	ListNode* curr = L->head;
	while (curr != NULL) {
		printf("%s\n", curr->data);
		curr = curr->rlink;
	}


}

int CountNode(HeadNode* L) {
	int count = 1;
	ListNode* temp = L->head;
	while (temp->rlink != NULL) {
		temp = temp->rlink;
		count++;
	}
	return count;
}

ListNode* SearchNthNode(HeadNode* L, int n) {
	ListNode* target = L->head;
	int count = 1;
	while (target!=NULL) {
		target = target->rlink;
		count++;
		if (count == n)
			return target;
	}
	return NULL;
}

int SearchDay(HeadNode* L,char* x) {
	ListNode* target = L->head;
	int count = 1;
	while (target != NULL) {
		if (strcmp(target->data, x) == 0)
			return count;
		target = target->rlink;
		count++;
	}
	return 2;
}

void FreeNode(HeadNode* L) {
	ListNode* curr = L->head;
	ListNode* temp;
	while (curr->rlink != NULL) {
		curr = curr->rlink;
		temp = curr;
		free(temp);
	}
}