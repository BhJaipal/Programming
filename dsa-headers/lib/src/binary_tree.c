#include "../include/binary_tree.h"

Tree createTree(int rootData) {
	Node root = {(Node *)0, (Node *)0, (Node *)0, rootData};
	Tree t = {root, 0, 0, 1};
	return t;
}
void addNode(int data, Tree *tree) {
	if (data > tree->root.data) {
		if (tree->root.right) addNodeHelper(data, tree->root.right);
		else {
			Node n = {&tree->root, (Node *)0, (Node *)0, data};
			tree->root.right = &n;
		}
	} else if (data < tree->root.data) {
		if (tree->root.left) addNodeHelper(data, tree->root.left);
		else {
			Node n = {&tree->root, (Node *)0, (Node *)0, data};
			tree->root.left = &n;
		}
	}
}
void addNodeHelper(int data, Node *n) {
	if (data > n->data) {
		if (n->right) addNodeHelper(data, n->right);
		else {
			Node child = {n, (Node *)0, (Node *)0, data};
			n->right = &child;
		}
	} else if (data < n->data) {
		if (n->left) addNodeHelper(data, n->left);
		else {
			Node child = {n, (Node *)0, (Node *)0, data};
			n->left = &child;
		}
	}
}
