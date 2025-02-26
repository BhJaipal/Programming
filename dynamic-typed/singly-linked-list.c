#include "singly-linked-list.h"
#include "types.h"
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include <strings.h>

SingleLinkedList *linked_list_new(Object first) {
	SingleLinkedList *ll = malloc(sizeof(SingleLinkedList));
	ll->first = malloc(sizeof(SingleNode));
	ll->first->value = first;
	ll->first->next = NULL;
	ll->len = 1;
	return ll;
}

void linked_list_push(SingleLinkedList *ll, Object value) {
	SingleNode *curr = ll->first;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	ll->len++;
	SingleNode *new =  malloc(sizeof(SingleNode));
	new->next = NULL;
	new->value = value;
	curr->next = new;
}

void linked_list_insert_at_index(SingleLinkedList *ll, Object value, int index) {
	if (index >= ll->len) {
		warn("index is more than length so push node to end\n");
		linked_list_push(ll, value);
		return;
	} else if (index == ll->len - 1) {
		linked_list_push(ll, value);
		return;
	}
	SingleNode *curr = ll->first;
	unsigned int i = 0;
	while (i != index - 1) {
		curr = curr->next;
		i++;
	}
	SingleNode *next = curr->next;
	curr->next = malloc(sizeof(SingleNode));
	curr->next->value = value;
	curr->next = next;
	ll->len++;
}

void linked_list_free(SingleLinkedList *ll) {
	SingleNode *curr = ll->first,
		*prev = NULL;
	for (unsigned int i = 0; i < ll->len; i++) {
		switch (curr->value.type) {
			case STRING:
				string_unref(curr->value);
				break;
			case FLOAT:
				float_unref(curr->value);
				break;
			default:
				int_unref(curr->value);
				break;
		}
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(ll);
}

void linked_list_print(SingleLinkedList *ll) {
	SingleNode *curr = ll->first;
	switch (curr->value.type) {
		case STRING:
			string_print(curr->value);
			break;
		case FLOAT:
			float_print(curr->value);
			break;
		default:
			int_print(curr->value);
			break;
	}
	printf(" -> ");
	while (curr->next != NULL) {
		curr = curr->next;
		switch (curr->value.type) {
			case STRING:
				string_print(curr->value);
				break;
			case FLOAT:
				float_print(curr->value);
				break;
			default:
				int_print(curr->value);
				break;
		}
		printf(" -> ");
	}
	printf("\x1b[38;5;178mNULL\x1b[0m\n");
}
