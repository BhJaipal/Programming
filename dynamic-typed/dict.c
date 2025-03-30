#include "dict.h"
#include "array.h"
#include "types.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

Dict *dict_new() {
	Dict *d = malloc(sizeof(Dict));
	d->len = 0;
	d->arr = malloc(0);
	return d;
}

void dict_add_element(Dict *dict, Object key, Object value) {
	if (!(key.type == INT || key.type == STRING)) {
		warn("Key should be either Integer or String\nPair not added\n");
		return;
	}
	DictElement pair = {key, value};
	dict->len++;
	dict->arr = realloc(dict->arr, sizeof(DictElement[dict->len]));
	dict->arr[dict->len - 1] = pair;
}

Object dict_pop_pair_else_default(Dict *dict, Object key, Object defaultValue) {
	unsigned foundI = -1;
	for (unsigned i = 0; i < dict->len; i++) {
		Object el = dict->arr[i].key;
		if (key.type != el.type)
			continue;
		if (key.type == STRING) {
			if (!strcmp(String.get_value(key), String.get_value(el))) {
				defaultValue = dict->arr[i].value;
				foundI = i;
				break;
			}
		} else if (Int.get_value(dict->arr[i].key) == Int.get_value(dict->arr[i].key)) {
			defaultValue = dict->arr[i].value;
			foundI = i;
			break;
		}
	}
	if (foundI != (unsigned)(-1)) {
		for (unsigned i = foundI; i < dict->len - 2; i++) {
			dict[i] = dict[i + 1];
		}
		dict->arr = realloc(dict->arr, sizeof(DictElement[--dict->len]));
	}
	return defaultValue;
}

Object dict_pop_pair(Dict *dict, Object key) {
	Object defaultValue = NullObject;
	unsigned foundI = -1;
	for (unsigned i = 0; i < dict->len; i++) {
		Object el = dict->arr[i].key;
		if (key.type != el.type)
			continue;
		if (key.type == STRING) {
			if (!strcmp(String.get_value(key), String.get_value(el))) {
				defaultValue = dict->arr[i].value;
				foundI = i;
				break;
			}
		} else if (Int.get_value(dict->arr[i].key) == Int.get_value(dict->arr[i].key)) {
			defaultValue = dict->arr[i].value;
			foundI = i;
			break;
		}
	}
	if (defaultValue.data != NULL) {
		for (unsigned i = foundI; i < dict->len - 2; i++) {
			dict[i] = dict[i + 1];
		}
		dict->arr = realloc(dict->arr, sizeof(DictElement[--dict->len]));
	}
	return defaultValue;
}

Object dict_get_value_else_default(Dict *dict, Object key, Object defaultValue) {
	for (unsigned i = 0; i < dict->len; i++) {
		Object el = dict->arr[i].key;
		if (key.type != el.type)
			continue;
		if (key.type == STRING) {
			if (!strcmp(String.get_value(key), String.get_value(el))) {
				defaultValue = dict->arr[i].value;
				break;
			}
		} else if (Int.get_value(dict->arr[i].key) == Int.get_value(dict->arr[i].key)) {
			defaultValue = dict->arr[i].value;
			break;
		}
	}
	return defaultValue;
}

Object dict_get_value(Dict *dict, Object key) {
	Object defaultValue = NullObject;
	for (unsigned i = 0; i < dict->len; i++) {
		Object el = dict->arr[i].key;
		if (key.type != el.type)
			continue;
		if (key.type == STRING) {
			if (!strcmp(String.get_value(key), String.get_value(el))) {
				defaultValue = dict->arr[i].value;
				break;
			}
		} else if (Int.get_value(dict->arr[i].key) == Int.get_value(dict->arr[i].key)) {
			defaultValue = dict->arr[i].value;
			break;
		}
	}
	return defaultValue;
}

void dict_print(Dict *dict) {
	printf("{ ");
	for (unsigned i = 0; i < dict->len; i++) {
		switch (dict->arr[i].key.type) {
			case STRING:
				String.print(dict->arr[i].key);
				break;
			default:
				Int.print(dict->arr[i].key);
				break;
		}
		printf(" => ");
		SWITCH_ON_OBJ(dict->arr[i].value, String.print, Float.print, dict_print, array_print, Int.print);
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
				String.print(dict->arr[i].key);
				break;
			default:
				Int.print(dict->arr[i].key);
				break;
		}
		printf(" => ");
		SWITCH_ON_OBJ(dict->arr[i].value, String.print, Float.print, dict_print, array_print, Int.print);
		if (i != dict->len - 1)
			printf(",");
	}
	printf("\n}\nLength: %u\n", dict->len);
}

Object dict_to_object(Dict *dict) {
	Object obj = {dict, DICT, 0};
	return obj;
}

void dict_free(Dict *dict) {
	for (unsigned int i = 0; i < dict->len; i++) {
		// Key is either String or Int/FLoat
		switch (dict->arr[i].key.type) {
			case STRING:
				String.unref(dict->arr[i].key);
				break;
			default:
				free(dict->arr[i].key.data);
				break;
		}

		SWITCH_ON_OBJ(dict->arr[i].value, String.unref, Float.unref, dict_free, array_free, Int.unref);
	}
	free(dict->arr);
	free(dict);
}
