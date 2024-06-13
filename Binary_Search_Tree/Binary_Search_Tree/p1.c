#include "node.h"

int main() {
	treeNode* root = NULL;
	root = insertBSTNode(NULL,root,1);
	insertBSTNode(NULL, root, 1);
	insertBSTNode(NULL, root, 2);
	insertBSTNode(NULL, root, 3);
	insertBSTNode(NULL, root, -1);

	insertBSTNode(NULL, root, -2);
	insertBSTNode(NULL, root, 6);
	insertBSTNode(NULL, root, 8);
	insertBSTNode(NULL, root, 7);
	//printf("%d", root->key);
	searchBST2(root, -2);
}