#ifndef DYNAMIC_TYPES_H
#define DYNAMIC_TYPES_H

#define DYNAMIC_ELEM_TYPE(el_name, EL_TYPE)	\
	EL_TYPE *el_name##_new(EL_TYPE data);			\
	EL_TYPE el_name##_get_value(Object elem);		\
	void el_name##_unref(Object elem);				\
	Object el_name##_to_object(EL_TYPE value);			\
	void el_name##_print(Object elem);

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

DYNAMIC_ELEM_TYPE(int, int);

char *string_new(char *data);

char *string_get_value(Object elem);
void string_unref(Object elem);
Object string_to_object(char *value);
void string_print(Object elem);

DYNAMIC_ELEM_TYPE(float, float);

#endif
