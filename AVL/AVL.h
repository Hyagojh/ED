#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

typedef struct avl {
	int value;
	struct AvlNode* left;
	struct AvlNode* right;
	int height;
} AvlNode;

void AvlNode* insertInTree (AvlNode* node ,int value);

#endif