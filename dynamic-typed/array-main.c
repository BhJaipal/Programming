#include "array.h"
#include "types.h"
#include "dict.h"

int main() {
	Array *arr = array_new();
	array_push(arr, int_to_object(5));
	array_push(arr, string_to_object("Jaipal"));
	array_push(arr, float_to_object(5.7));
	Dict *dict = dict_new();
	dict_add_element(dict, int_to_object(7), float_to_object(18));
	array_push(arr, dict_to_object(dict));
	array_insert_at_index(arr, int_to_object(75), 6);
	array_print_all(arr);
	array_pop_at_index(arr, 10);
	array_free(arr);
	return 0;
}
