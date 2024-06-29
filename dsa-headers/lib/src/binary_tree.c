#include "../include/binary_tree.h"

extern enum whereNow addingNode = ROOT;
extern int curr_depth = 0;
Tree createTree(int rootData) {
	Node root = {(Node *)0, (Node *)0, (Node *)0, rootData};
	Tree t = {root, 0, 0, 0, 0, 1};
	return t;
}
void addNode(int data, Tree *tree) {
	if (data > tree->root.data) {
		if (tree->root.right) {
			addNodeHelper(data, tree->root.right, tree);
			addingNode = RIGHT;
		} else {
			Node n = {&tree->root, (Node *)0, (Node *)0, data};
			tree->root.right = &n;
			tree->rightDepth = 1;
			tree->rightNodeCount = 1;
		}
	} else if (data < tree->root.data) {
		if (tree->root.left) {
			addNodeHelper(data, tree->root.left, tree);
			addingNode = LEFT;
		} else {
			Node n = {&tree->root, (Node *)0, (Node *)0, data};
			tree->root.left = &n;
			tree->leftDepth = 1;
			tree->leftNodeCount = 1;
		}
	}
}
void addNodeHelper(int data, Node *n, Tree *t) {
	curr_depth++;
	if (data > n->data) {
		if (n->right) addNodeHelper(data, n->right, t);
		else {
			curr_depth++;
			Node child = {n, (Node *)0, (Node *)0, data};
			n->right = &child;
			if (addingNode == RIGHT) {
				t->rightNodeCount++;
				if (curr_depth > t->rightDepth) t->rightDepth = curr_depth;
			} else {
				t->leftNodeCount++;
				if (curr_depth > t->leftDepth) t->leftDepth = curr_depth;
			}
			addingNode = ROOT;
			curr_depth = 0;
		}
	} else if (data < n->data) {
		if (n->left) addNodeHelper(data, n->left, t);
		else {
			curr_depth++;
			Node child = {n, (Node *)0, (Node *)0, data};
			n->left = &child;
			if (addingNode == RIGHT) {
				t->rightNodeCount++;
				if (curr_depth > t->rightDepth) t->rightDepth = curr_depth;
			} else {
				t->leftNodeCount++;
				if (curr_depth > t->leftDepth) t->leftDepth = curr_depth;
			}
			addingNode = ROOT;
			curr_depth = 0;
		}
	}
}
