#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

AvlNode* newNode (int value){
	AvlNode* node = (AvlNode*) malloc(sizeof(AvlNode));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node); 
}

int height (AvlNode* node){
	if (node = NULL){
		return 0;
	} else {
		return node->height;
	}
}

int max(int a, int b){
	if (a > b){
		return a;
	} else{
		return b;
	}
}

int getBalance (AvlNode* node){
	if (node == NULL){
		return 0;
	}
	return height (node->left) - height (node->right);
}

AvlNode* rotateToRight (AvlNode* node){
	AvlNode* nodeLeftSon = node->left;
	AvlNode* nodeLeftRightSon = nodeLeftSon -> right;

	nodeLeftSon->right = node;
	node->left = nodeLeftRightSon;

	node->height = 1 + max (height(node->left), height(node->right));
	nodeLeftSon->height = 1 + max (height(node->left), height(node->right));

	return nodeLeftSon;
}

AvlNode* insertInTree (AvlNode* node, int value){
	if (node == NULL){
		return (newNode(value));
	}

	if (value < node->value){
		node->left = insertInTree(node->left, value);
	} else if (value > node->value){
		node->right = insertInTree(node->right, value);
	} else {
		return node;
	}

	node->height = 1 + max(height(node->left), height(node->right));
	int balanceFactor = getBalance (node);

	if (balanceFactor > 1 && value > node->left->value){	
		return rotateToRight (node);
	}
}