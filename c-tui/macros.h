#ifndef TI_MACROS_H
#define TI_MACROS_H 1

#define BEGIN_DECL extern "C" {
#define END_DECL }

#define DECL_ARRAY(NAME, TYPE, snake_case)                                      \
	typedef struct _##NAME {                                                    \
		TYPE *arr;                                                              \
		uint32_t len;                                                           \
		void (*free)(struct _##NAME *arr);                                      \
		TYPE (*pop)(struct _##NAME *arr);                                       \
		void (*append)(struct _##NAME *arr, TYPE opt);                          \
	} NAME;                                                                     \
	NAME snake_case##_opt_list_new();

#define TI_ARRAY_FREE(NAME) { free(NAME->arr); }

#define TI_ARRAY_APPEND(ARR, EL) {                                          \
	ARR->arr = realloc(ARR->arr, sizeof(ARR->arr[0]) * (++ARR->len));       \
	ARR->arr[ARR->len - 1] = EL;                                            \
}

#define TI_DECL_ARRAY_FUNCS(snake_case, ARR_T, EL_T)                             \
	void __##snake_case##_append(ARR_T *a, EL_T e);                              \
	EL_T __##snake_case##_pop(ARR_T *a);                                         \
	void __##snake_case##_free(ARR_T *a);                                        \
	
#endif // !TI_MACROS_H
