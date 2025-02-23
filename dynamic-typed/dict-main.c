#include "array.h"
#include "dict.h"
#include "types.h"
#include <stdio.h>

int main() {
	Dict *dict = dict_new();
	Array *arr = array_new();
	array_push_object(arr, int_to_object(75));
	dict_add_element(dict, int_to_object(5), float_to_object(3.4));
	dict_add_element(dict, string_to_object("info"), array_to_object(arr));
	dict_add_element(dict, float_to_object(5.7), float_to_object(2.5));
	dict_add_element(dict, int_to_object(10), float_to_object(2.5));
	printf("\nBy dict_print: ");
	dict_print(dict);
	printf("\nBy dict_print_all:\n");
	dict_print_all(dict);
	return 0;
}
