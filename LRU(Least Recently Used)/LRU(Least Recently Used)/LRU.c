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
	// target node�� ù��° ����� ���
	if (head->top == target) 
		return;
	
	
	// target node�� ������ ����� ��� ����
	if (target->rlink != NULL) {
		target->llink->rlink = target->rlink;
		target->rlink->llink = target->llink;

	}
	// ������ ����� ���
	else 
		target->llink->rlink = NULL;
	
	// target node�� head node�� �����ϴ� ����
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
		// ������ headnode�� llink �ʵ忡 newnode�� �����Ѵ�.
		head->top->llink = newnode;
		// headnode�� newnode�� �����Ѵ�.
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