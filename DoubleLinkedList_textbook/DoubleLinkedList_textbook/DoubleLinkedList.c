#include "DoubleLinkedList.h"

linkedList_h* createLinkedList_h() {
	linkedList_h* DL;
	DL = (linkedList_h*)malloc(sizeof(linkedList_h));
	DL->head = NULL;
	return DL;
}

void PrintList(linkedList_h* DL) {
	listNode* p;
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL)
			printf(", ");
	}
}

void InsertNode(linkedList_h* DL, listNode* pre, char* x) {
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy(newnode->data, x);
	if (DL->head == NULL) {
		newnode->rlink = NULL;
		newnode->llink = NULL;
		DL->head = newnode;
	}
	else {
		newnode->rlink = pre->rlink;   
		pre->rlink = newnode;
		newnode->llink = pre;	// newnode->llink 와 pre는 다른 곳에서 이용하지 않기 때문에 순서 영향x
		if (newnode->rlink != NULL)	// 마지막 노드가 아닌 경우
			newnode->rlink->llink = newnode;
	}
}

void DeleteNode(linkedList_h* DL, listNode* old) {
	if (DL == NULL)
		return;
	if (DL->head == NULL)
		return;
	else if (old == NULL)
		return;
	if (strcmp(old->data, DL->head->data) == 0) {
		if (old->llink != NULL)
			old->rlink->llink = old->llink;
		DL->head = old->rlink;
		free(old);
	}
	else {
		old->llink->rlink = old->rlink;
		if(old->rlink!=NULL)
			old->rlink->llink = old->llink;
		free(old);
		
	}
}

listNode* SearchNode(linkedList_h* DL, char* x) {
	listNode* temp;
	temp = DL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0)
			return temp;
		else
			temp = temp->rlink;
	}
	return temp;
}