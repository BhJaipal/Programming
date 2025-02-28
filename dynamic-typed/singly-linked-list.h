#ifndef DYNAMIC_LINKED_LIST_H
#define DYNAMIC_LINKED_LIST_H
#include "types.h"

typedef struct _SingleNode {
	Object value;
	struct _SingleNode *next;
} SingleNode;

typedef struct {
	SingleNode *first;
	unsigned len;
} SingleLinkedList;

SingleLinkedList *linked_list_new(Object first);

void linked_list_push(SingleLinkedList *ll, Object value);

void linked_list_insert_at_index(SingleLinkedList *ll, Object value, int index);

Object linked_list_pop_last(SingleLinkedList *ll);

void linked_list_free(SingleLinkedList *ll);

void linked_list_print(SingleLinkedList *ll);

#endif // DYNAMIC_LINKED_LIST_H
