#define _CRT_SECURE_NO_WARNINGS
#include "InsertLinkedList.h"

HeadNode* CreateLinkedList() {
	HeadNode* newnode;
	newnode = (HeadNode*)malloc(sizeof(HeadNode));
	if (newnode == NULL)
		return NULL;
	else {
		newnode->head = NULL;
		return newnode;
	}

}

ListNode* CreateNode() {
	ListNode* newnode;
	newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
		return NULL;

	else {
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		return newnode;
	}
}
//Insert before headnode
void InsertFirstNode(HeadNode* node) {
	printf("Insert node first\n");
	ListNode* newnode = CreateNode();


	// insert address of previous headnode in newnode->next
	newnode->next = node->head;
	// Update headnode to 'newnode'
	node->head = newnode;
}

void InsertLastNode(HeadNode* node) {
	printf("Insert node last\n");
	ListNode* newnode = CreateNode();

	ListNode* temp = node->head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
}

void InsertMiddleNode(HeadNode* L, ListNode* pre) {
	printf("Insert node middle\n");
	ListNode* newNode;
	newNode = CreateNode();
	// ��� �����Ͱ� ����ִ� ���
	if (L->head == NULL) {
		newNode->next = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {		// ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
		newNode->next = L->head;
		L->head = newNode;
	}
	else {
		newNode->next = pre->next;	// ������ pre ��� ���� �� ��� ����
		pre->next = newNode;
	}
}

void PrintNode(HeadNode* node) {
	//ListNode* l;
	ListNode* temp = node->head;
	/*for (l = node->head; l != NULL; l = l->next) {
		printf("%p\n", l);
		printf("%d\n", l->data);
	}*/
	while (temp != NULL) {

		printf("%p\n", temp);
		printf("%d\n", temp->data);
		temp = temp->next;
	}

}

ListNode* searchNode(HeadNode* L, int x) {
	ListNode* temp;
	temp = L->head;
	while (temp != NULL) {
		if (temp->data == x)
			return temp;
		else
			temp = temp->next;
	}
}

void DeleteNode(HeadNode* L, ListNode* p) {
	ListNode* pre;
	if (L->head == NULL)
		return;
	if (L->head->next == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL)
		return;
	else {			// ������ ��� p�� ������ ���� ���� ��带 ����
		pre = L->head;
		while (pre->next != p)
			pre = pre->next;
	}
	pre->next = p->next;
	free(p);
}