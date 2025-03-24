#include "../array.h"
#include "../dict.h"
#include <stdio.h>

int main() {
	Dict *dict = dict_new();
	Array *arr = array_new();
	array_push(arr, Int.to_object(75));
	dict_add_element(dict, Int.to_object(5), Float.to_object(3.4));
	dict_add_element(dict, String.to_object("info"), array_to_object(arr));
	dict_add_element(dict, Float.to_object(5.7), Float.to_object(2.5));
	dict_add_element(dict, Int.to_object(10), Float.to_object(2.5));
	printf("\nBy dict_print: ");
	dict_print(dict);
	printf("\nBy dict_print_all:\n");
	dict_print_all(dict);
	return 0;
}
