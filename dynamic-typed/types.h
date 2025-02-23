#ifndef DYNAMIC_TYPES_H
#define DYNAMIC_TYPES_H

#define DYNAMIC_ELEM_TYPE(EL_NAME, el_name, EL_TYPE)	\
	typedef struct {									\
		EL_TYPE value;									\
	} EL_NAME##El;										\
														\
	EL_NAME##El *el_name##_el_new(EL_TYPE data);		\
	EL_TYPE el_name##_el_get_value (void *elem);		\
	EL_TYPE el_name##_el_unref (void *elem);			\
	void el_name##_print(void *elem);					\
	Object el_name##_to_object(EL_TYPE value);

typedef enum {
	STRING,
	INT,
	FLOAT,
	ARRAY,
	DICT
} ObjectType;

typedef struct {
	void *data;
	ObjectType type;
} Object;

/** This will generate
	typedef struct {
		int value;
	} IntEl;

	IntEl *int_el_new(EL_TYPE data);
	int int_el_get_value(void *elem);
	int int_el_unref(void *elem);
 */
DYNAMIC_ELEM_TYPE(Int, int, int);

/** This will generate
	typedef struct {
		char * value;
	} StringEl;

	StringEl *string_el_new(char * data);
	char * int_el_get_value(void *elem);
	char * int_el_unref(void *elem);
 */
DYNAMIC_ELEM_TYPE(String, string, char *);

/** This will generate
	typedef struct {
		float value;
	} FLoatEl;

	FLoatEl *int_el_new(FloatEl data);
	float int_el_get_value(void *elem);
	float int_el_unref(void *elem);
 */
DYNAMIC_ELEM_TYPE(Float, float, float);

#endif
