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
	printf("타겟 노드가 연결리스트의 마지막 노드인 경우\n");
}

void InsertNodeMiddle(ListNode* newnode, ListNode* left) {
	newnode->rlink = left->rlink;
	left->rlink = newnode;
	newnode->llink = left;
	left->rlink->llink = newnode;
	printf("타겟 노드가 연결리스트 처음이나 중간에 있는 경우\n");
}

void InsertNodeFirst(HeadNode* L) {
	ListNode* left = NULL;
	ListNode* newnode = NULL;
	newnode = CreateNode();
	char x[10];

	printf("Target Node?");
	printf("Target ");
	scanf("%s", x);
	if (L->head == NULL) {					// 헤드 노드에 아무것도 없는 경우(연결리스트에 아무것도 없을 때)
		L->head = newnode;					// 새 노드를 헤드 포인터로 지정
		printf("헤드 노드에 아무것도 없는 경우\n");
	}
	else if (SearchNode(L, x) == NULL) {	// data x가 연결리스트에 없는 경우 ... 연결리스트 처음에 삽입
		newnode->rlink = L->head;
		//newnode->rlink->llink = newnode;
		L->head = newnode;
		printf("data x가 연결리스트에 없는 경우\n");
	}

	else {									// data x가 있는 노드 뒤에 삽입하는 경우
		left = SearchNode(L, x);
		if (left->rlink == NULL) 			// 타겟 노드가 연결리스트의 마지막 노드인 경우 ... 연결리스트 마지막에 삽입
			InsertNodeLast(newnode, left);
		else 								// 타겟 노드가 연결리스트 중간에 있는 경우 ... 타겟 노드 다음에 삽입
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