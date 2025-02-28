#include "singly-linked-list.h"
#include "types.h"
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

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

Object linked_list_pop_last(SingleLinkedList *ll) {
	SingleNode *curr = ll->first,
		*prev = NULL;
	while (curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL) {
		linked_list_free(ll);
		error("Linked list has only one node\n");
	}
	Object value = curr->value;
	prev->next = curr->next;
	free(curr);
	return value;
}

void linked_list_free(SingleLinkedList *ll) {
	SingleNode *curr = ll->first,
		*prev = NULL;
	for (unsigned int i = 0; i < ll->len; i++) {
		SWITCH_ON_OBJ(curr->value, string_unref, float_unref, , , int_unref);
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(ll);
}

void linked_list_print(SingleLinkedList *ll) {
	SingleNode *curr = ll->first;
	SWITCH_ON_OBJ(curr->value, string_print, float_print, , , int_print);
	printf(" -> ");
	while (curr->next != NULL) {
		curr = curr->next;
		SWITCH_ON_OBJ(curr->value, string_print, float_print, , , int_print);
		printf(" -> ");
	}
	printf("\x1b[38;5;178mNULL\x1b[0m\n");
}
