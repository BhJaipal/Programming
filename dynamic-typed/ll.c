/**
 * @author Jaipal
 * @brief linked list with dynamic datatypes
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef enum {
	Int,
	String
} Types;

typedef struct {
	int value;
} NodeInt;

typedef struct {
	char *string;
} NodeString;

typedef struct {
	/** Available linked list values datatype */
	Types type;
	/** Either a NodeInt or NodeString */
	void *data;
} NodeData;

void *node_int_new(int value) {
	NodeInt *data = malloc(sizeof(NodeInt));
	data->value = value;
	return data;
}
int node_int_get_value(void *node_value) {
	return ((NodeInt *)node_value)->value;
}
int node_int_unref(void *node_value) {
	int val = ((NodeInt *)node_value)->value;
	free(node_value);
	return val;
}

void *node_string_new(char *value) {
	NodeString *data = malloc(sizeof(NodeString));
	data->string = malloc(sizeof(char[strlen(value)]));
	strcpy(data->string, value);
	return data;
}
/** When we only want value */
char *node_string_get_value(void *node_value) {
	return ((NodeString *)node_value)->string;
}
/** when we want to access value and remove free NodeString obj */
char *node_string_unref(void *node_value) {
	char *val = ((NodeString *)node_value)->string;
	free(node_value);
	return val;
}

/**
 * Node: Linked list node
 * @value_: value of node
 * @next_: next node pointer
*/
typedef struct _Node {
	NodeData value_;
	struct _Node *next_;
} Node;

typedef struct {
	Node* first_;
	unsigned int len_;
} LinkedList;

LinkedList *linked_list_new(void *first, Types datatype) {
	LinkedList *ll = malloc(sizeof(LinkedList));
	ll->first_ = malloc(sizeof(Node));
	ll->len_ = 1;
	NodeData data = {datatype, first};
	ll->first_->value_ = data;
	ll->first_->next_ = (Node *)NULL;
	return ll;
}

void linked_list_add_node(LinkedList *linked_list, void *value, Types datatype) {
	Node *curr = linked_list->first_;
	while (curr->next_ != NULL) {
		curr = curr->next_;
	}
	curr->next_ = malloc(sizeof(Node));
	curr->next_->next_ = NULL;
	NodeData data = {datatype, value};
	curr->next_->value_ = data;
	linked_list->len_++;
}

NodeData linked_list_pop_last(LinkedList *linkedList) {
	if (linkedList->len_ == 0) {
		NodeData d = {Int, (void *)-1};
		return d;
	}
	Node *curr = linkedList->first_;
	Node *last = NULL;
	while (curr->next_ != NULL) {
		last = curr;
		curr = curr->next_;
	}
	NodeData value = curr->value_;
	if (last != NULL) {
		last->next_ = NULL;
	}
	linkedList->len_--;
	return value;
}
void linked_list_free(LinkedList *linked_list) {
	for (size_t i = 0; i < linked_list->len_; i++) {
		NodeData data = linked_list_pop_last(linked_list);
		if (data.type == String) {
			free(((NodeString *)data.data)->string);
		}
		free(data.data);
	}
	linked_list->first_ = NULL;
	linked_list->len_ = 0;
	free(linked_list);
}

void linked_list_print(LinkedList *linked_list) {
	Node *curr = linked_list->first_;
	while (1) {
		if (curr->value_.type == String)
			printf("%s -> ", node_string_get_value(curr->value_.data));
		else printf("%d -> ", node_int_get_value(curr->value_.data));
		if (curr->next_ == NULL) break;
		curr = curr->next_;
	}
	printf("NULL\nLenght: %u\n", linked_list->len_);
}

int main() {
	LinkedList *ll = linked_list_new(node_int_new(5), Int);
	linked_list_add_node(ll, node_string_new("Int"), String);
	linked_list_add_node(ll, node_int_new(7), Int);
	printf("Poped: %d\n", node_int_unref(linked_list_pop_last(ll).data));
	linked_list_print(ll);
	linked_list_free(ll);
	return 0;
}
