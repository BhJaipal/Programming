#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <malloc.h>
#include <strings.h>

#define ARRAY_ELEM_TYPE(EL_NAME, el_name, EL_TYPE)		\
	typedef struct {									\
		EL_TYPE value;									\
	} EL_NAME##El;										\
														\
	EL_NAME##El *el_name##_el_new(EL_TYPE data);		\
	EL_TYPE el_name##_el_get_value (void *elem);		\
	EL_TYPE el_name##_el_unref (void *elem);			\

/** This will generate
	typedef struct {
		int value;
	} IntEl;

	IntEl *int_el_new(EL_TYPE data);
	int int_el_get_value(void *elem);
	int int_el_unref(void *elem);
 */
ARRAY_ELEM_TYPE(Int, int, int);

/** This will generate
	typedef struct {
		char * value;
	} StringEl;

	StringEl *string_el_new(char * data);
	char * int_el_get_value(void *elem);
	char * int_el_unref(void *elem);
 */
ARRAY_ELEM_TYPE(String, string, char *);

/** This will generate
	typedef struct {
		float value;
	} FLoatEl;

	FLoatEl *int_el_new(FloatEl data);
	float int_el_get_value(void *elem);
	float int_el_unref(void *elem);
 */
ARRAY_ELEM_TYPE(Float, float, float);

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

// using __THROW means it won't cause any exception and I am sure about it

Array *array_new() __THROW;

void array_free(Array *arr) __THROW;

void array_insert_at_index(Array *arr, void *data, ArrayElemTypes type, unsigned index);

void array_push(Array *arr, void *data, ArrayElemTypes type) __THROW;

ArrayElement array_pop_at_index(Array *arr, unsigned index);

ArrayElement array_pop_last(Array *arr);

void arrar_print(Array *arr) __THROW;

#endif // DYNAMIC_ARRAY_H
