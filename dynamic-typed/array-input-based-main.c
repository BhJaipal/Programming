#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "array.h"
#include "types.h"

#define string_len 10

ObjectType input_type(char el[string_len]) {
	int isFLOAT = 0;
	unsigned int slen = strlen(el);
	for (size_t i = 0; i < slen; i++) {
		if (el[i] == '.' && isFLOAT) return STRING;
		else if (el[i] == '.') isFLOAT = 1;
		else if (el[i] < '0' || el[i] > '9') return STRING;
	}
	return (isFLOAT) ? FLOAT : INT;
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
		ObjectType elType = input_type(input);
		Object data;
		switch (elType) {
			case STRING:
				data = string_to_object(input);
				break;
			case FLOAT:
				data = float_to_object(atof(input));
				break;
			default:
				data = int_to_object(atoi(input));
				break;
		}

		array_push(arr, data);
		strcpy(input, "");
	}
	printf("Elements: [\n");
	for (unsigned char i = 0; i < len; i++) {
		printf("\t");
		switch (arr->elements_[i].type) {
			case STRING:
				string_print(arr->elements_[i]);
				break;
			case FLOAT:
				float_print(arr->elements_[i]);
				break;
			default:
				int_print(arr->elements_[i]);
				break;
		}
		printf(" => \x1b[38;5;69m");
		switch (arr->elements_[i].type) {
			case STRING:
				printf("STRING");
				break;
			case FLOAT:
				printf("FLOAT");
				break;
			default:
				printf("INT");
				break;
		}
		printf("\x1b[0m\n");
	}
	printf("]\n");
	array_free(arr);
	return 0;
}
