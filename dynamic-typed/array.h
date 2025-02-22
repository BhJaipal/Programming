#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define ARRAY_ELEM_TYPE(EL_NAME, el_name, EL_TYPE, ASSIGNED) \
	typedef struct {									\
		EL_TYPE value;									\
	} EL_NAME##El;										\
														\
	EL_NAME##El *el_name##_el_new(EL_TYPE data) {		\
		EL_NAME##El *el = malloc(sizeof(EL_NAME##El));  \
		el->value = data;								\
		ASSIGNED;										\
		return el;										\
	}													\
	EL_TYPE el_name##_el_get_value(void *elem) {		\
		return ((EL_NAME##El *)elem)->value;			\
	}													\
	EL_TYPE el_name##_el_unref(void *elem) {			\
		EL_TYPE value = ((EL_NAME##El *)elem)->value;   \
		free (elem);									\
		return value;									\
	}

ARRAY_ELEM_TYPE(Int, int, int,;);
ARRAY_ELEM_TYPE(String, string, char *,
		el->value = malloc(sizeof(char[strlen(data)]));
		strcpy(el->value, data);
);
ARRAY_ELEM_TYPE(Float, float, float, );

typedef enum {
	String,
	Int,
	Float
} ArrayElemTypes;

typedef struct {
	void *data;
	ArrayElemTypes type;
} ArrayElement;

typedef struct {
	ArrayElement *elements_;
	unsigned int len_;
} Array;

Array *array_new() {
	Array *a = malloc(sizeof(Array));
	a->len_ = 0;
	a->elements_ = malloc(0);
	return a;
}
void array_free(Array *arr) {
	for (int i = 0; i < arr->len_; i++) {
		if (arr->elements_[i].type == String) {
			free(((StringEl *)arr->elements_[i].data)->value);
		}
		free(arr->elements_[i].data);
	}
	arr->len_ = 0;
	free(arr);
}

void array_push(Array *arr, void *data, ArrayElemTypes type) {
	arr->elements_ = realloc(arr->elements_, sizeof(ArrayElement[arr->len_ + 1]));
	ArrayElement el = {data, type};
	arr->elements_[arr->len_] = el;
	arr->len_++;
}

ArrayElement array_pop(Array *arr) {
	arr->len_--;
	ArrayElement last = arr->elements_[arr->len_];
	arr->elements_ = realloc(arr->elements_, sizeof(ArrayElement[arr->len_]));
	return last;
}

void arrar_print(Array *arr) {
	printf("[ ");
	for (unsigned i = 0; i < arr->len_; i++) {
		if (arr->elements_[i].type == String)
			printf("%s", string_el_get_value(arr->elements_[i].data));
		else if (arr->elements_[i].type == Float)
			printf("%f", float_el_get_value(arr->elements_[i].data));
		else
			printf("%d", int_el_get_value(arr->elements_[i].data));
		if (i != arr->len_ - 1) printf(", ");
	}
	printf(" ]\n");
}
