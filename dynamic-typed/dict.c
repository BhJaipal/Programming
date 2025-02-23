#include "dict.h"
#include "array.h"
#include "types.h"
#include <malloc.h>
#include <stdio.h>

Dict *dict_new() {
	Dict *d = malloc(sizeof(Dict));
	d->len = 0;
	d->arr = malloc(0);
	return d;
}

void dict_add_element(Dict *dict, Object key, Object value) {
	if (!(key.type == INT || key.type == STRING)) {
		printf("\x1b[33mWarning: \x1b[0mKey should be either Integer or String\nPair not added\n");
		return;
	}
	DictElement pair = {key, value};
	dict->len++;
	dict->arr = realloc(dict->arr, sizeof(DictElement[dict->len]));
	dict->arr[dict->len - 1] = pair;
}

void dict_print(Dict *dict) {
	printf("{ ");
	for (unsigned i = 0; i < dict->len; i++) {
		switch (dict->arr[i].key.type) {
			case STRING:
				string_print(dict->arr[i].key.data);
				break;
			default:
				int_print(dict->arr[i].key.data);
				break;
		}
		printf(" => ");
		switch (dict->arr[i].value.type) {
			case STRING:
				string_print(dict->arr[i].value.data);
				break;
			case FLOAT:
				float_print(dict->arr[i].value.data);
				break;
			case DICT:
				dict_print(dict->arr[i].value.data);
				break;
			case ARRAY:
				array_print((Array *)dict->arr[i].value.data);
				break;
			default:
				int_print(dict->arr[i].value.data);
				break;
		}
		if (i != dict->len - 1)
			printf(", ");
	}
	printf(" }");
}

void dict_print_all(Dict *dict) {
	printf("{");
	for (unsigned i = 0; i < dict->len; i++) {
		printf("\n\t");
		switch (dict->arr[i].key.type) {
			case STRING:
				string_print(dict->arr[i].key.data);
				break;
			default:
				int_print(dict->arr[i].key.data);
				break;
		}
		printf(" => ");
		switch (dict->arr[i].value.type) {
			case STRING:
				string_print(dict->arr[i].value.data);
				break;
			case FLOAT:
				float_print(dict->arr[i].value.data);
				break;
			case DICT:
				dict_print(dict->arr[i].value.data);
				break;
			case ARRAY:
				array_print((Array *)dict->arr[i].value.data);
				break;
			default:
				int_print(dict->arr[i].value.data);
				break;
		}
		if (i != dict->len - 1)
			printf(",");
	}
	printf("\n}\nLength: %u\n", dict->len);
}

void dict_free(Dict *dict) {
	for (int i = 0; i < dict->len; i++) {
		// Key is either String or Int/FLoat
		switch (dict->arr[i].key.type) {
			case STRING:
				{
					char *out = string_el_unref(dict->arr[i].key.data);
					free(out);
				}
				break;
			default:
				free(dict->arr[i].key.data);
				break;
		}

		switch (dict->arr[i].value.type) {
			case STRING:
				{
					char *out = string_el_unref(dict->arr[i].value.data);
					free(out);
				}
				break;
			case ARRAY:
				array_free(dict->arr[i].value.data);
				break;
			case DICT:
				dict_free(dict->arr[i].value.data);
				break;
			default:
				free(dict->arr[i].value.data);
		break;
		}
	}
	free(dict->arr);
	free(dict);
}
