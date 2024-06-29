#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct _Node {
	struct _Node *parent;
	struct _Node *right;
	struct _Node *left;
	int data;
} Node;

typedef struct Tree {
	Node root;
	int leftDepth;
	int rightDepth;
	int len;
} Tree;

enum whereNow { ROOT, LEFT, RIGHT };

Tree createTree(int rootData);
void addNode(int data, Tree *tree);
void addNodeHelper(int data, Node *n);
#endif