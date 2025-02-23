#include "array.h"
#include "types.h"
int main() {
	Array *arr = array_new();
	array_push(arr, int_el_new(5), INT);
	array_push(arr, string_el_new("Jaipal"), STRING);
	// printf("Poped: %s\n", string_el_unref(array_pop_last(arr).data));
	array_push(arr, float_el_new(5.7), FLOAT);
	array_insert_at_index(arr, int_el_new(75), INT, 6);
	array_print_all(arr);
	array_pop_at_index(arr, 10);
	array_free(arr);
	return 0;
}
