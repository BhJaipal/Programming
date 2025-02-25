#ifndef DYNAMIC_DICT_H
#define DYNAMIC_DICT_H
#include "types.h"

typedef struct {
	Object key;
	Object value;
} DictElement;

typedef struct {
	DictElement *arr;
	unsigned len;
} Dict;

Dict *dict_new();

void dict_add_element(Dict *dict, Object key, Object value);

Object dict_pop_pair(Dict *dict, Object key, Object defaultValue);

/**
 * Prints in:
 * { key => value, ... }
 */
void dict_print(Dict *dict);

/**
 * Prints in:
 * {
 *		key => value
 *		...
 * }
 * Length: x
 */
void dict_print_all(Dict *dict);

Object dict_to_object(Dict *dict);

void dict_free(Dict *dict);

#endif // DYNAMIC_DICT_H
