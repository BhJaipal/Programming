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

/**
 * key has to be either int or string
 * if not, pair won't be added to dictionary and gives warning about key not being int/string
 */
void dict_add_element(Dict *dict, Object key, Object value);

/**
 * @returns either pops the value or default value
 */
Object dict_pop_pair_else_default(Dict *dict, Object key, Object defaultValue);

/**
 * @returns either pops the value or gives you a default value {.data = NULL, .type = INT}
 */
Object dict_pop_pair(Dict *dict, Object key);

/**
 * @returns either getss the value or default value
 */
Object dict_get_value_else_default(Dict *dict, Object key, Object defaultValue);

/**
 * @returns either gets a value or default value {.data = NULL, .type = INT}
 */
Object dict_get_value(Dict *dict, Object key);

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
