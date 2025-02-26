#ifndef DYNAMIC_TYPES_H
#define DYNAMIC_TYPES_H

#define DYNAMIC_ELEM_TYPE(EL_TYPE)		\
	EL_TYPE *EL_TYPE##_new(EL_TYPE data);		\
	EL_TYPE EL_TYPE##_get_value(Object elem);	\
	void EL_TYPE##_unref(Object elem);			\
	Object EL_TYPE##_to_object(EL_TYPE value);	\
	void EL_TYPE##_print(Object elem);

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

DYNAMIC_ELEM_TYPE(int);

char *string_new(char *data);
char *string_get_value(Object elem);
void string_unref(Object elem);
Object string_to_object(char *value);
void string_print(Object elem);

DYNAMIC_ELEM_TYPE(float);

#endif
