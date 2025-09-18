#include "../c-impl.h"

typedef struct Node Node;
struct Node {
	Node *next;
	size_t value;
};

typedef struct {
	size_t node_size;
	Node *head;
} LinkedList;

LinkedList* ll_new(size_t node_size);
void ll_add_node(LinkedList *ll, size_t val);
void ll_delete_node(LinkedList *ll, size_t val);
void ll_destroy(LinkedList *ll);

int main() {
	LinkedList* ll = ll_new(sizeof(Node));
	ll_add_node(ll, 5);
	ll_add_node(ll, 7);
	ll_add_node(ll, 3);
	ll_delete_node(ll, 7);
	Node *head = ll->head;

	while (head) {
		write_uint(head->value);
		print(" -> ");
		head = head->next;
	}
	println("NULL");
	ll_destroy(ll);
}

LinkedList* ll_new(size_t node_size) {
	LinkedList* ll = mmap(null, sizeof(LinkedList), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	ll->head = null;
	ll->node_size = node_size;
	return ll;
}
void ll_add_node(LinkedList *ll, size_t val) {
	if (!ll->head) {
		ll->head = mmap(null, sizeof(ll->node_size), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		ll->head->value = val;
		ll->head->next = null;
		return;
	}
	Node *head = ll->head;
	while (head->next) {
		head = head->next;
	}
	head->next = mmap(null, sizeof(ll->node_size), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	head->next->value = val;
	head->next->next = null;
}
void ll_delete_node(LinkedList *ll, size_t val) {
	Node *head = ll->head;
	if (!head) return;
	Node *prev = null;

	while (head && head->value != val) {
		prev = head;
		head = head->next;
	}
	prev->next = head->next;
	munmap(head, ll->node_size);
}
void ll_destroy(LinkedList *ll) {
	Node *head = ll->head;
	Node *prev = null;

	while (head) {
		prev = head;
		head = head->next;
		munmap(prev, ll->node_size);
	}
}
