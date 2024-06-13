#include "node.h"

treeNode* searchBST(treeNode* root, element x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key)
			p = p->left;
		else if (x == p->key)
			return p;
		else
			p=p->right;
	}
	return p;

}

treeNode* searchBST2(treeNode* node, element x) {
	if (x > node->key)
		searchBST2(node->right, x);
	else if (x < node->key)
		searchBST2(node->left, x);
	else if (node == NULL) 
		searchBST2(node->prev,x);
	
		
	else if (node->key == x) {
		printf("%d", node->key);
	}
	
	return NULL;
}

treeNode* insertBSTNode(treeNode*parentNode,treeNode* p, element x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		if(parentNode!=NULL)
			newNode->prev = parentNode;
		return newNode;
	}
	else if (p->key > x) {
		parentNode = p;
		p->left = insertBSTNode(parentNode,p->left, x);
	}
	else if (p->key < x) {
		parentNode = p;
		p->right = insertBSTNode(parentNode,p->right, x);
	}
		
	return p;
		
}