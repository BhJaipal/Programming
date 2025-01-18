#include <stdlib.h>
#ifndef TI_MACROS_H
#define TI_MACROS_H 1

#define DECL_ARRAY(NAME, TYPE)                                                 \
	typedef struct _##NAME {                                                   \
		TYPE *arr;                                                             \
		int len;                                                               \
	} NAME;

#define FREE_ARRAY(NAME)                                                       \
	{ free(NAME->arr); }

#define APPEND_ARRAY(ARR, EL)                                                  \
	{                                                                          \
		ARR->arr = realloc(ARR->arr, sizeof(ARR->arr[0]) * (++ARR->len));      \
		ARR->arr[ARR->len - 1] = EL;                                           \
	}

#define ARRAY_NEW(NAME, TYPE)                                                  \
	{                                                                          \
		NAME arr;                                                              \
		arr.arr = malloc(sizeof(TYPE));                                        \
		arr.len = 0;                                                           \
		return arr;                                                            \
	}

#endif // !TI_MACROS_H
