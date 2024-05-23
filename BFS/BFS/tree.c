#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int idx = 0;
int tree_level = 0;
typedef struct ListNode {
	int data;
	struct ListNode* left;
	struct ListNode* right;
}Node;

typedef struct {
	Node* head;
}Nodeh;

Nodeh* CreateLinkedList() {
	Nodeh* headnode = malloc(sizeof(Node));
	headnode->head = NULL;
	return headnode;
}

Node* CreateNode() {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = idx;
	newnode->left = NULL;
	newnode->right = NULL;
	idx += 1;
	return newnode;
}

void InsertLeftTree(Node* parent) {
	tree_level += 1;
	Node* son = CreateNode();
	parent->left = son;
}
void InsertRightTree(Node* parent) {
	tree_level += 1;
	Node* son = CreateNode();
	parent->right = son;
}

void InsertTree(Node*root) {
	int level=0;
	Node* curr = root;
	while (curr->left != NULL || curr->right != NULL) {
		// 오른쪽 자식 노드가 있는 경우
		if (curr->left == NULL && curr->right!=NULL) {
			printf("오른쪽:%d ", curr->data);
			curr = curr->right;
		}
		// 왼쪽 자식 노드가 있는 경우
		else if (curr->right == NULL&& curr->left!=NULL) {
			printf("왼쪽:%d ", curr->data);
			curr = curr->left;
		}
		// 양쪽 자식 노드가 있는 경우
		else {
			printf("양쪽:%d ", curr->data);
			curr = curr->right;
		}
		level += 1;
	}
	InsertLeftTree(curr);
	InsertRightTree(curr);
}
int sum = 0;
// Preorder Traversal
void TraverseTree(const Node* root){
	sum += root->data;
	if (root->left != NULL && root->right==NULL) {
		TraverseTree(root->left);
	}
	else if (root->right != NULL && root->left==NULL) {
		TraverseTree(root->right);
	}
	else if(root->right != NULL&& root->left != NULL) {
		TraverseTree(root->left);
		TraverseTree(root->right);
	}
	else {
		return;
	}


}

int main() {
	Nodeh* h = CreateLinkedList();
	h->head=CreateNode();
	int num=0;
	InsertTree(h->head);
	InsertTree(h->head);
	InsertTree(h->head);
	InsertTree(h->head);
	InsertTree(h->head);
	TraverseTree(h->head);
	printf("%d\n", sum);
	//while (num < 4) {
	//	scanf("%d", &num);
	//	switch (num) {
	//	case 1:
	//		InsertTree(h->head);
	//	case 2:
	//		//InsertRightTree(h->head);
	//	}
	//}

}