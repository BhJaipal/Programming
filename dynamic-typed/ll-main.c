#include "singly-linked-list.h"
#include "types.h"

int main() {
	SingleLinkedList *ll = linked_list_new(int_to_object(5));
	linked_list_insert_at_index(ll, int_to_object(7), 4);
	linked_list_print(ll);
	linked_list_free(ll);
}
