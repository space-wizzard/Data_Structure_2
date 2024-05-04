#include "LRU.h"

int main() {
	Nodeh* h = CreateLinkedList();
	int n;
	scanf("%d", &n);
	Node* prevnode = h->top;
	Node* currnode = NULL;
	currnode = CreateNode(prevnode,currnode);
	for (int i = 0; i < n; i++) {
		currnode->rlink = CreateNode(prevnode,currnode);
		prevnode = prevnode->rlink;
		currnode = currnode->rlink;
	}
	currnode = h->top;
	
	while (currnode->rlink != NULL) {
		printf("%d\n", currnode->data);
	}
	
}