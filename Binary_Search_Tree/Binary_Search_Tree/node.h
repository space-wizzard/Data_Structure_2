#pragma once
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode* left;
	struct treeNode* right;
	struct treeNode* prev;
}treeNode;

//void displayInorder(treeNode* root);
treeNode* searchBST(treeNode* root, element x);
treeNode* searchBST2(treeNode* node, element x);
treeNode* insertBSTNode(treeNode*parentNode,treeNode* p, element x);