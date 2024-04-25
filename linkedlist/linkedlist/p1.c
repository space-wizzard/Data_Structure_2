#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// general node

typedef struct Node {
	int data;
	struct Node* next;
}ListNode;

// head pointer(not node)
typedef struct {
	ListNode* head;
}HeadNode;


//void InsertFirst(int data) {
//
//}
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

	printf("node->head:%p", node->head);
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

void InsertMiddleNode(HeadNode* L) {
	ListNode* currnode = L->head;
	printf("Insert node middle\n");
	int target;
	ListNode* targetNode;
	printf("Input target data\n");
	scanf("%d", &target);
	while (1) {
		
		if (target == currnode->data) {
			targetNode = currnode;
			break;
		}
		currnode = currnode->next;
		if (currnode == NULL) {
			printf("No data\n");
			scanf("%d", &target);
			currnode = L->head;
		}
	}

	ListNode* newnode = CreateNode();
	newnode->next = targetNode->next;
	targetNode->next = newnode;


}

void PrintNode(HeadNode* node) {
	//ListNode* l;
	ListNode* temp = node->head;
	/*for (l = node->head; l != NULL; l = l->next) {
		printf("%p\n", l);
		printf("%d\n", l->data);
	}*/
	int count = 0;
	while (count==20) {

		printf("%p\n", temp);
		printf("%d\n", temp->data);
		temp = temp->next;
		count++;
	}

}

void FreeNode(HeadNode* node) {
	ListNode* curr = node->head;
	ListNode* temp;
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		printf("%d\n", temp->data);
		free(temp);
	}
}

void DeleteNode(HeadNode*node) {
	int target;
	ListNode* targetNode = NULL;
	ListNode* currnode = node->head;
	ListNode* prevnode=NULL;
	printf("Delete node");
	scanf("%d", &target);
	while (1) {
		if (target == currnode->data) {
			targetNode = currnode;
			break;
		}
		
		prevnode = currnode;
		currnode = currnode->next;
		if (currnode == NULL) {
			printf("No data\n");
			scanf("%d", &target);
			currnode = node->head;
		}
	}
	prevnode->next = NULL;
	prevnode->next = targetNode->next;
	free(targetNode);
	
}

void CreateCircleLinkedList(HeadNode* node) {
	ListNode* lastnode = NULL;
	ListNode* currnode = node->head;
	while (currnode->next != NULL) {
		currnode = currnode->next;
	}
	lastnode = currnode;
	lastnode->next = node->head;
}

int main() {
	HeadNode* l = CreateLinkedList();
	printf("%p\n", l);
	printf("%p\n", l->head);
	InsertFirstNode(l);
	printf("%p\n", l->head);
	InsertFirstNode(l);
	printf("%p\n", l->head);

	InsertFirstNode(l);
	printf("%p\n", l->head);
	InsertLastNode(l);
	printf("%p\n", l->head);
	InsertMiddleNode(l);
	InsertLastNode(l);
	DeleteNode(l);
	InsertLastNode(l);
	//CreateCircleLinkedList(l);
	PrintNode(l);
	FreeNode(l);
}