#include "LRU.h"

Nodeh* CreateDoubleLinkedList(int n) {
	Nodeh* h = malloc(sizeof(Node));
	h->top = CreateNode();
	Node* prev = h->top;
	Node* current = NULL;
	for (int i = 0; i < n - 1; i++) {
		//printf("%p\n", prev->rlink);
		current = CreateNode();
		current->llink = prev;
		prev->rlink = current;
		prev = current;
	}
	PrintNode(h);
	return h;
}
void DeleteNode(Nodeh* L) {
	Node* head = L->top;
	Node* current=head;
	//Node* prevnode = NULL;
	Node* delnode=NULL;
	while (current->rlink != NULL) {
		//prevnode = current;
		current = current->rlink;
	}
	delnode = current;
	delnode->llink->rlink = NULL;
	free(delnode);
}

void MoveNode(Nodeh* head, Node* target) {
	// target node가 첫번째 노드인 경우
	if (head->top == target) 
		return;
	
	
	// target node가 마지막 노드인 경우 제외
	if (target->rlink != NULL) {
		target->llink->rlink = target->rlink;
		target->rlink->llink = target->llink;

	}
	// 마지막 노드인 경우
	else 
		target->llink->rlink = NULL;
	
	// target node를 head node로 변경하는 과정
	target->rlink = head->top;
	target->llink = NULL;
	head->top->llink = target;
	head->top = target;
}

void InsertNode(Nodeh*head) {
	Node* newnode = CreateNode();
	scanf("%d", &newnode->data);
	Node* target = SearchNode(head, newnode->data); 
	if (target!=NULL) {
		printf("Hit!!\n");
		free(newnode);
		MoveNode(head,target);
	}
	else {
		printf("Miss!!\n");
		if (CountNode(head) >= 5) {
			DeleteNode(head);
		}
		newnode->rlink = head->top;
		// 기존의 headnode의 llink 필드에 newnode를 삽입한다.
		head->top->llink = newnode;
		// headnode를 newnode로 변경한다.
		head->top = newnode;
	}
	
	PrintNode(head);
}

Node* SearchNode(Nodeh* L, int data) {
	Node* curr = L->top;
	while (curr != NULL) {
		if (curr->data == data) {
			return curr;
		}
		curr = curr->rlink;
	}
	return NULL;
}

int CountNode(Nodeh* L) {
	Node* current = L->top;
	int count=0;
	while (current != NULL) {
		count += 1;
		current = current->rlink;
	}
	return count;
}
void PrintNode(Nodeh* L) {
	Node* current = L->top;
	while (current != NULL){
		printf("%d ", current->data);
		current = current->rlink;
	}
}

Node* CreateNode() {
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL) {
		return NULL;
	}
	newnode->llink = NULL;
	newnode->rlink = NULL;
	newnode->data = 0;
	return newnode;
}