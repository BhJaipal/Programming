#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "array.h"

#define string_len 10

ArrayElemTypes input_type(char el[string_len]) {
	int isFloat = 0;
	unsigned int slen = strlen(el);
	for (size_t i = 0; i < slen; i++) {
		if (el[i] == '.' && isFloat) return String;
		else if (el[i] == '.') isFloat = 1;
		else if (el[i] < '0' || el[i] > '9') return String;
	}
	return (isFloat) ? Float : Int;
}

int main() {
	char input[string_len] = "";
	Array *arr = array_new();
	unsigned char len = 0;

	printf("Enter array length: ");
	scanf("%u", (unsigned int*)&len);

	printf("Enter array elements: \n");
	for (unsigned char i = 0; i < len; i++) {
		for (int j = 0; j < string_len; j++) {
			read(0, input + j, 1);
			if (input[j] == '\n' || input[j] == 0 || input[j] == ' ')
				break;
		}
		for (int i = 0; i < string_len; i++) {
			if (input[i] == 0) break;
			if (input[i] == '\n') {
				input[i] = 0;
				break;
			}
		}
		ArrayElemTypes elType = input_type(input);
		void *data;
		switch (elType) {
			case String:
				data = string_el_new(input);
				break;
			case Float:
				data = float_el_new(atof(input));
				break;
			default:
				data = int_el_new(atoi(input));
				break;
		}

		array_push(arr, data, elType);
		strcpy(input, "");
	}
	printf("Elements: [\n");
	for (unsigned char i = 0; i < len; i++) {
		switch (arr->elements_[i].type) {
			case String:
				printf("\t%s => ", string_el_get_value(arr->elements_[i].data));
				break;
			case Float:
				printf("\t%f => ", float_el_get_value(arr->elements_[i].data));
				break;
			default:
				printf("\t%d => ", int_el_get_value(arr->elements_[i].data));
				break;
		}
		printf("\x1b[38;5;69m");
		switch (arr->elements_[i].type) {
			case String:
				printf("String");
				break;
			case Float:
				printf("Float");
				break;
			default:
				printf("Int");
				break;
		}
		printf("\x1b[0m\n");
	}
	printf("]\n");
	array_free(arr);
	return 0;
}
