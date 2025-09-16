#include "c-impl.h"

void _start() {
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
	exit(0);
}
